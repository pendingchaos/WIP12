#include "graphics/GL/gfxglapi.h"

#include "graphics/gfxbuffer.h"
#include "graphics/gfxtexture.h"
#include "graphics/GL/gfxgltextureimpl.h"
#include "graphics/GL/gfxglbuffer.h"
#include "graphics/GL/gfxglframebuffer.h"
#include "graphics/GL/glgputimer.h"
#include "graphics/GL/glfl.h"
#include "logging.h"
#include "memory.h"
#include "error.h"
#include "file.h"

#include <cstdio>
#include <cstring>
#include <iostream>

#define UNIFORM_START GLint location = glGetUniformLocation(shader->getGLProgram(), name);\
if (location == -1)\
{\
    return;\
}

static const GLenum toGLPrimitive[] = {GL_POINTS,
                                       GL_LINE_STRIP,
                                       GL_LINE_LOOP,
                                       GL_LINES,
                                       GL_TRIANGLE_STRIP,
                                       GL_TRIANGLE_FAN,
                                       GL_TRIANGLES,
                                       GL_PATCHES};

static const GLenum toGLBlendFactor[] = {GL_ZERO,
                                         GL_ONE,
                                         GL_SRC_COLOR,
                                         GL_ONE_MINUS_SRC_COLOR,
                                         GL_DST_COLOR,
                                         GL_ONE_MINUS_DST_COLOR,
                                         GL_SRC_ALPHA,
                                         GL_ONE_MINUS_SRC_ALPHA,
                                         GL_DST_ALPHA,
                                         GL_ONE_MINUS_DST_ALPHA,
                                         GL_CONSTANT_COLOR,
                                         GL_ONE_MINUS_CONSTANT_COLOR,
                                         GL_CONSTANT_ALPHA,
                                         GL_ONE_MINUS_CONSTANT_ALPHA};

static const GLenum toGLBlendMode[] = {GL_FUNC_ADD, GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT};

static const GLenum toGLDepthFunc[] = {GL_NEVER,
                                       GL_LESS,
                                       GL_EQUAL,
                                       GL_LEQUAL,
                                       GL_GREATER,
                                       GL_NOTEQUAL,
                                       GL_GEQUAL,
                                       GL_ALWAYS};

static void printOpenGLInfo()
{
    const char *vendor = (const char *)glGetString(GL_VENDOR);
    const char *renderer = (const char *)glGetString(GL_RENDERER);
    const char *version = (const char *)glGetString(GL_VERSION);
    const char *glslVersion = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);

    logInfo("OpenGL vendor: %s\n", vendor);
    logInfo("OpenGL renderer: %s\n", renderer);
    logInfo("OpenGL version: %s\n", version);
    logInfo("GLSL version: %s\n", glslVersion);

    GLint numExtensions;
    glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

    for (GLint i = 0; i < numExtensions; ++i)
    {
        logInfo("Extension %d: %s\n", i, (const char *)glGetStringi(GL_EXTENSIONS, i));
    }
}

static void debugCallback(GLenum source,
                          GLenum type,
                          GLuint id,
                          GLenum severity,
                          GLsizei length,
                          const char *message,
                          const void *userParam)
{
    #define HANDLE_MESSAGE(behavior) switch (type)\
    {\
    case GL_DEBUG_TYPE_ERROR:\
    {\
        behavior("OpenGL error: %s", message);\
        break;\
    }\
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:\
    {\
        behavior("OpenGL deprecated behavoir: %s", message);\
        break;\
    }\
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:\
    {\
        behavior("OpenGL undefined behavior: %s", message);\
        break;\
    }\
    case GL_DEBUG_TYPE_PORTABILITY:\
    {\
        behavior("OpenGL portibility problem: %s", message);\
        break;\
    }\
    default:\
    {\
        behavior("OpenGL message: %s", message);\
        break;\
    }\
    }

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
    {
        HANDLE_MESSAGE(LOG_ERROR);
        break;
    }
    case GL_DEBUG_SEVERITY_MEDIUM:
    {
        HANDLE_MESSAGE(LOG_WARNING);
        break;
    }
    case GL_DEBUG_SEVERITY_LOW:
    {
        HANDLE_MESSAGE(LOG_WARNING);
        break;
    }
    default:
    {
        HANDLE_MESSAGE(LOG_INFO);
        break;
    }
    }
}

GfxGLApi::GfxGLApi() : stateStackSize(0),
                       textureBindingCount(0),
                       uboBindingCount(0),
                       mesh(nullptr),
                       vertex(nullptr),
                       tessControl(nullptr),
                       tessEval(nullptr),
                       geometry(nullptr),
                       fragment(nullptr)
{
    glflInit();

    std::sscanf((const char *)glGetString(GL_VERSION), "%u.%u", &glMajor, &glMinor);

    Str vendor = (const char *)glGetString(GL_VENDOR);

    if (vendor == "NVIDIA Corporation")
    {
        driver = GfxDriver::Nvidia;
    } else if (vendor.find("nouveau") != -1)
    {
        driver = GfxDriver::Mesa;
    } else if (vendor.find("mesa") != -1)
    {
        driver = GfxDriver::Mesa;
    } else
    {
        driver = GfxDriver::Unknown;
    }

    resetState();

    printOpenGLInfo();

    if (GLFL_GL_ARB_debug_output)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(debugCallback, nullptr);
    }

    glEnable(GL_DEPTH_TEST);

    if (GLFL_GL_ARB_seamless_cube_map)
    {
        glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
    }

    if (not GLFL_GL_ARB_separate_shader_objects)
    {
        LOG_FATAL("GL_ARB_separate_shader_objects is not supported.");
    }

    if (not GLFL_GL_ARB_tessellation_shader)
    {
        LOG_FATAL("GLFL_GL_ARB_tessellation_shader is not supported.");
    }

    glGenProgramPipelines(1, &pipeline);

    for (size_t i = 0; i < 4096; ++i)
    {
        samplers[i] = 0;
    }
}

GfxGLApi::~GfxGLApi()
{
    for (size_t i = 0; i < 4096; ++i)
    {
        if (samplers[i] != 0)
        {
            glDeleteSamplers(1, &samplers[i]);
        }
    }

    glDeleteProgramPipelines(1, &pipeline);
}

GfxDriver GfxGLApi::getDriver() const
{
    return driver;
}

size_t GfxGLApi::getMaxTextureSize() const
{
    GLint size;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &size);
    return size;
}

GfxBuffer *GfxGLApi::createBuffer()
{
    return NEW(GfxGLBuffer);
}

GfxTextureImpl *GfxGLApi::createTextureImpl()
{
    return NEW(GfxGLTextureImpl);
}

GfxFramebuffer *GfxGLApi::createFramebuffer()
{
    return NEW(GfxGLFramebuffer);
}

GPUTimer *GfxGLApi::createTimer()
{
    return NEW(GLGPUTimer);
}

void GfxGLApi::setCurrentFramebuffer(GfxFramebuffer *framebuffer)
{
    if (framebuffer != nullptr)
    {
        ((GfxGLFramebuffer *)framebuffer)->bind();

        GLenum drawBuffers[framebuffer->getNumColorAttachments()];

        for (size_t i = 0; i < framebuffer->getNumColorAttachments(); ++i)
        {
            drawBuffers[i] = GL_COLOR_ATTACHMENT0+i;
        }

        glDrawBuffers(framebuffer->getNumColorAttachments(), drawBuffers);
    } else
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}

void GfxGLApi::clearDepth(float depthValue)
{
    glClearBufferfv(GL_DEPTH, 0, &depthValue);
}

void GfxGLApi::clearColor(size_t rtIndex, Float4 value)
{
    GLfloat value_[] = {value.x, value.y, value.z, value.w};

    glClearBufferfv(GL_COLOR, rtIndex, value_);
}

void GfxGLApi::clearColor(size_t rtIndex, Int4 value)
{
    GLint value_[] = {value.x, value.y, value.z, value.w};

    glClearBufferiv(GL_COLOR, rtIndex, value_);
}

void GfxGLApi::clearColor(size_t rtIndex, UInt4 value)
{
    GLuint value_[] = {value.x, value.y, value.z, value.w};

    glClearBufferuiv(GL_COLOR, rtIndex, value_);
}

#define END_DRAW for (size_t i = 0; i < textureBindingCount; ++i)\
{\
    GLuint binding = textureBindings[i];\
\
    glActiveTexture(GL_TEXTURE0+i);\
    glBindTexture(binding, 0);\
\
    glBindSampler(i, 0);\
}\
\
textureBindingCount = 0;\
uboBindingCount = 0;

void GfxGLApi::begin(GfxCompiledShader *vertex_,
                     GfxCompiledShader *tessControl_,
                     GfxCompiledShader *tessEval_,
                     GfxCompiledShader *geometry_,
                     GfxCompiledShader *fragment_)
{
    mesh = nullptr;
    tesselation = (tessControl_ != nullptr) or (tessEval_ != nullptr);

    glBindProgramPipeline(pipeline);

    if (vertex_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, vertex_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, 0);
    }
    vertex = vertex_;

    if (tessControl_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_TESS_CONTROL_SHADER_BIT, tessControl_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_TESS_CONTROL_SHADER_BIT, 0);
    }
    tessControl = tessControl_;

    if (tessEval_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_TESS_EVALUATION_SHADER_BIT, tessEval_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_TESS_EVALUATION_SHADER_BIT, 0);
    }
    tessEval = tessEval_;

    if (geometry_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_GEOMETRY_SHADER_BIT, geometry_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_GEOMETRY_SHADER_BIT, 0);
    }
    geometry = geometry_;

    if (fragment_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, fragment_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, 0);
    }
    fragment = fragment_;
}

void GfxGLApi::draw(size_t instanceCount)
{
    if (mesh == nullptr)
    {
        return;
    }

    GLenum primitive = tesselation ? GL_PATCHES : toGLPrimitive[(int)mesh->primitive];

    if (not mesh->getIndexed())
    {
        glDrawArraysInstanced(primitive, 0, mesh->numVertices, instanceCount);
    } else
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->getGLIndexBuffer());

        switch (mesh->getIndexType())
        {
        case GfxMeshIndexDataType::U8:
        {
            glDrawElementsInstanced(primitive,
                                    mesh->numIndices,
                                    GL_UNSIGNED_BYTE,
                                    (const GLvoid *)0,
                                    instanceCount);
            break;
        }
        case GfxMeshIndexDataType::U16:
        {
            glDrawElementsInstanced(primitive,
                                    mesh->numIndices,
                                    GL_UNSIGNED_SHORT,
                                    (const GLvoid *)0,
                                    instanceCount);
            break;
        }
        case GfxMeshIndexDataType::U32:
        {
            glDrawElementsInstanced(primitive,
                                    mesh->numIndices,
                                    GL_UNSIGNED_INT,
                                    (const GLvoid *)0,
                                    instanceCount);
            break;
        }
        default: {break;}
        }

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}

void GfxGLApi::end()
{
    END_DRAW

    mesh = nullptr;
}

void GfxGLApi::setMesh(GfxMesh *mesh_)
{
    mesh = mesh_;
    glBindVertexArray(mesh_->getGLVAO());

    switch (mesh->cullMode)
    {
    case GfxCullNone:
    {
        glDisable(GL_CULL_FACE);
        break;
    }
    case GfxCullFront:
    {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
    }
    case GfxCullBack:
    {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }
    }

    switch (mesh->winding)
    {
    case GfxCCW:
    {
        glFrontFace(GL_CCW);
        break;
    }
    case GfxCW:
    {
        glFrontFace(GL_CW);
        break;
    }
    }
}

GfxCompiledShader *GfxGLApi::getVertexShader()
{
    return vertex;
}

GfxCompiledShader *GfxGLApi::getTessControlShader()
{
    return tessControl;
}

GfxCompiledShader *GfxGLApi::getTessEvalShader()
{
    return tessEval;
}

GfxCompiledShader *GfxGLApi::getGeometryShader()
{
    return geometry;
}

GfxCompiledShader *GfxGLApi::getFragmentShader()
{
    return fragment;
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, float value)
{
    UNIFORM_START
    glProgramUniform1f(shader->getGLProgram(), location, value);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Float2& value)
{
    UNIFORM_START
    glProgramUniform2f(shader->getGLProgram(), location, value.x, value.y);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Float3& value)
{
    UNIFORM_START
    glProgramUniform3f(shader->getGLProgram(), location, value.x, value.y, value.z);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Float4& value)
{
    UNIFORM_START
    glProgramUniform4f(shader->getGLProgram(), location, value.x, value.y, value.z, value.w);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, int32_t value)
{
    UNIFORM_START
    glProgramUniform1i(shader->getGLProgram(), location, value);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Int2& value)
{
    UNIFORM_START
    glProgramUniform2i(shader->getGLProgram(), location, value.x, value.y);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Int3& value)
{
    UNIFORM_START
    glProgramUniform3i(shader->getGLProgram(), location, value.x, value.y, value.z);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Int4& value)
{
    UNIFORM_START
    glProgramUniform4i(shader->getGLProgram(), location, value.x, value.y, value.z, value.w);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, uint32_t value)
{
    UNIFORM_START
    glProgramUniform1ui(shader->getGLProgram(), location, value);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const UInt2& value)
{
    UNIFORM_START
    glProgramUniform2ui(shader->getGLProgram(), location, value.x, value.y);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const UInt3& value)
{
    UNIFORM_START
    glProgramUniform3ui(shader->getGLProgram(), location, value.y, value.y, value.z);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const UInt4& value)
{
    UNIFORM_START
    glProgramUniform4ui(shader->getGLProgram(), location, value.x, value.y, value.z, value.w);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const float *values)
{
    UNIFORM_START
    glProgramUniform1fv(shader->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float2 *values)
{
    UNIFORM_START
    glProgramUniform2fv(shader->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float3 *values)
{
    UNIFORM_START
    glProgramUniform3fv(shader->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float4 *values)
{
    UNIFORM_START
    glProgramUniform4fv(shader->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const int32_t *values)
{
    UNIFORM_START
    glProgramUniform1iv(shader->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int2 *values)
{
    UNIFORM_START
    glProgramUniform2iv(shader->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int3 *values)
{
    UNIFORM_START
    glProgramUniform3iv(shader->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int4 *values)
{
    UNIFORM_START
    glProgramUniform4iv(shader->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const uint32_t *values)
{
    UNIFORM_START
    glProgramUniform1uiv(shader->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt2 *values)
{
    UNIFORM_START
    glProgramUniform2uiv(shader->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt3 *values)
{
    UNIFORM_START
    glProgramUniform3uiv(shader->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt4 *values)
{
    UNIFORM_START
    glProgramUniform4uiv(shader->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::addUBOBinding(GfxCompiledShader *shader, const char *name, const GfxBuffer *buffer)
{
    GLint location;

    location = glGetUniformBlockIndex(shader->getGLProgram(), name);

    if (location == -1)
    {
        return;
    }

    glBindBufferBase(GL_UNIFORM_BUFFER, uboBindingCount, ((const GfxGLBuffer *)buffer)->getGLBuffer());
    glUniformBlockBinding(shader->getGLProgram(), location, uboBindingCount);

    ++uboBindingCount;
}

void GfxGLApi::addTextureBinding(GfxCompiledShader *shader, const char *name, GfxTexture *texture, TextureSampler sampler)
{
    UNIFORM_START

    if (textureBindingCount < sizeof(textureBindings)/sizeof(GLuint))
    {
        GLuint target = ((GfxGLTextureImpl *)texture->getImpl())->getGLTarget();
        GLuint id = ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture();

        glActiveTexture(GL_TEXTURE0+textureBindingCount);
        glBindTexture(target, id);

        glProgramUniform1i(shader->getGLProgram(), location, textureBindingCount);
        glBindSampler(textureBindingCount, getSampler(sampler));

        textureBindings[textureBindingCount++] = target;
    }
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Matrix3x3& value)
{
    UNIFORM_START
    glProgramUniformMatrix3fv(shader->getGLProgram(), location, 1, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Matrix4x4& value)
{
    UNIFORM_START
    glProgramUniformMatrix4fv(shader->getGLProgram(), location, 1, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix3x3 *value)
{
    UNIFORM_START
    glProgramUniformMatrix3fv(shader->getGLProgram(), location, count, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix4x4 *value)
{
    UNIFORM_START
    glProgramUniformMatrix4fv(shader->getGLProgram(), location, count, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::pushState()
{
    if (stateStackSize == (sizeof(stateStack)/sizeof(State)))
    {
        THROW(BoundsException);
    }

    stateStack[stateStackSize++] = currentState;
}

void GfxGLApi::popState()
{
    if (stateStackSize == 0)
    {
        THROW(BoundsException);
    }

    useState(stateStack[--stateStackSize]);
}

void GfxGLApi::resetState()
{
    State state;

    state.patchSize = 0;
    state.constantColor[0] = 0;
    state.constantColor[1] = 0;
    state.constantColor[2] = 0;
    state.constantColor[3] = 0;
    state.srcFactorRGB = GfxOne;
    state.srcFactorAlpha = GfxOne;
    state.dstFactorRGB = GfxZero;
    state.dstFactorAlpha = GfxZero;
    state.blendRGB = GfxAdd;
    state.blendAlpha = GfxAdd;
    state.writeDepth = true;
    state.depthFunc = GfxLess;
    state.blendingEnabled = false;
    state.viewportLeft = 0;
    state.viewportBottom = 0;
    state.viewportWidth = 100;
    state.viewportHeight = 100;
    state.scissorLeft = 0;
    state.scissorBottom = 0;
    state.scissorWidth = 100;
    state.scissorHeight = 100;
    state.cullMode = GfxCullNone;
    state.scissorEnabled = false;

    useState(state);
}

void GfxGLApi::setBlendingEnabled(bool enabled)
{
    if (enabled)
    {
        glEnable(GL_BLEND);
    } else
    {
        glDisable(GL_BLEND);
    }

    currentState.blendingEnabled = enabled;
}

void GfxGLApi::setBlendConstantColor(const uint8_t constantColor[4])
{
    glBlendColor(static_cast<float>(constantColor[0])/255.0f,
                 static_cast<float>(constantColor[1])/255.0f,
                 static_cast<float>(constantColor[2])/255.0f,
                 static_cast<float>(constantColor[3])/255.0f);

    currentState.constantColor[0] = constantColor[0];
    currentState.constantColor[1] = constantColor[1];
    currentState.constantColor[2] = constantColor[2];
    currentState.constantColor[3] = constantColor[3];
}

void GfxGLApi::setBlendFactors(GfxBlendFactor srcFactorRGB,
                               GfxBlendFactor srcFactorAlpha,
                               GfxBlendFactor dstFactorRGB,
                               GfxBlendFactor dstFactorAlpha)
{
    glBlendFuncSeparate(toGLBlendFactor[srcFactorRGB],
                        toGLBlendFactor[dstFactorRGB],
                        toGLBlendFactor[srcFactorAlpha],
                        toGLBlendFactor[dstFactorAlpha]);

    currentState.srcFactorRGB = srcFactorRGB;
    currentState.srcFactorAlpha = srcFactorAlpha;
    currentState.dstFactorRGB = dstFactorRGB;
    currentState.dstFactorAlpha = dstFactorAlpha;
}

void GfxGLApi::setBlendMode(GfxBlendMode blendRGB, GfxBlendMode blendAlpha)
{
    glBlendEquationSeparate(toGLBlendMode[blendRGB], toGLBlendMode[blendAlpha]);

    currentState.blendRGB = blendRGB;
    currentState.blendAlpha = blendAlpha;
}

void GfxGLApi::setWriteDepth(bool depth)
{
    glDepthMask(depth);

    currentState.writeDepth = depth;
}

void GfxGLApi::setDepthFunction(GfxDepthFunction depthFunc)
{
    glDepthFunc(toGLDepthFunc[depthFunc]);

    currentState.depthFunc = depthFunc;
}

void GfxGLApi::setCullMode(GfxCullMode mode)
{
    switch (mode)
    {
    case GfxCullNone:
    {
        glDisable(GL_CULL_FACE);
        break;
    }
    case GfxCullFront:
    {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        break;
    }
    case GfxCullBack:
    {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        break;
    }
    }

    currentState.cullMode = mode;
}

void GfxGLApi::setViewport(uint16_t left,
                           uint16_t bottom,
                           uint16_t width,
                           uint16_t height)
{
    glViewport(left, bottom, width, height);

    currentState.viewportLeft = left;
    currentState.viewportBottom = bottom;
    currentState.viewportWidth = width;
    currentState.viewportHeight = height;
}

void GfxGLApi::setScissor(uint16_t left,
                          uint16_t bottom,
                          uint16_t width,
                          uint16_t height)
{
    glScissor(left, bottom, width, height);

    currentState.scissorLeft = left;
    currentState.scissorBottom = bottom;
    currentState.scissorWidth = width;
    currentState.scissorHeight = height;
}

void GfxGLApi::useState(const State& state)
{
    setBlendConstantColor(state.constantColor);
    setBlendFactors(state.srcFactorRGB,
                    state.srcFactorAlpha,
                    state.dstFactorRGB,
                    state.dstFactorAlpha);
    setBlendMode(state.blendRGB, state.blendAlpha);
    setWriteDepth(state.writeDepth);
    setDepthFunction(state.depthFunc);
    setBlendingEnabled(state.blendingEnabled);
    setViewport(state.viewportLeft,
                state.viewportBottom,
                state.viewportWidth,
                state.viewportHeight);
    setCullMode(state.cullMode);
    setScissorEnabled(state.scissorEnabled);
    setScissor(state.scissorLeft,
               state.scissorBottom,
               state.scissorWidth,
               state.scissorHeight);
}

bool GfxGLApi::isBlendingEnabled() const
{
    return currentState.blendingEnabled;
}

const uint8_t *GfxGLApi::getBlendConstantColor() const
{
    return currentState.constantColor;
}

uint8_t *GfxGLApi::getBlendConstantColor()
{
    return currentState.constantColor;
}

GfxBlendFactor GfxGLApi::getBlendSrcFactorRGB() const
{
    return currentState.srcFactorRGB;
}

GfxBlendFactor GfxGLApi::getBlendSrcFactorAlpha() const
{
    return currentState.srcFactorAlpha;
}

GfxBlendFactor GfxGLApi::getBlendDstFactorRGB() const
{
    return currentState.dstFactorRGB;
}

GfxBlendFactor GfxGLApi::getBlendDstFactorAlpha() const
{
    return currentState.dstFactorAlpha;
}

GfxBlendMode GfxGLApi::getBlendModeRGB() const
{
    return currentState.blendRGB;
}

GfxBlendMode GfxGLApi::getBlendModeAlpha() const
{
    return currentState.blendAlpha;
}

bool GfxGLApi::getWriteDepth() const
{
    return currentState.writeDepth;
}

GfxDepthFunction GfxGLApi::getDepthFunction() const
{
    return currentState.depthFunc;
}

GfxCullMode GfxGLApi::getCullMode() const
{
    return currentState.cullMode;
}

uint16_t GfxGLApi::getViewportLeft() const
{
    return currentState.viewportLeft;
}

uint16_t GfxGLApi::getViewportBottom() const
{
    return currentState.viewportBottom;
}

uint16_t GfxGLApi::getViewportWidth() const
{
    return currentState.viewportWidth;
}

uint16_t GfxGLApi::getViewportHeight() const
{
    return currentState.viewportHeight;
}

uint16_t GfxGLApi::getScissorLeft() const
{
    return currentState.scissorLeft;
}

uint16_t GfxGLApi::getScissorBottom() const
{
    return currentState.scissorBottom;
}

uint16_t GfxGLApi::getScissorWidth() const
{
    return currentState.scissorWidth;
}

uint16_t GfxGLApi::getScissorHeight() const
{
    return currentState.scissorHeight;
}

void GfxGLApi::setScissorEnabled(bool enabled)
{
    if (enabled)
    {
        glEnable(GL_SCISSOR_TEST);
    } else
    {
        glDisable(GL_SCISSOR_TEST);
    }

    currentState.scissorEnabled = enabled;
}

bool GfxGLApi::getScissorEnabled()
{
    return currentState.scissorEnabled;
}

void GfxGLApi::setTessPatchSize(size_t size)
{
    if (GLFL_GL_ARB_tessellation_shader)
    {
        glPatchParameteri(GL_PATCH_VERTICES, size);
    }

    currentState.patchSize = size;
}

size_t GfxGLApi::getTessPatchSize()
{
    return currentState.patchSize;
}

GLuint GfxGLApi::getSampler(const TextureSampler& params)
{
    uint16_t index = (uint16_t)params.minFilter |
                     (uint16_t)params.magFilter<<1 |
                     (uint16_t)params.mipmapMode<<2 |
                     (uint16_t)params.wrapMode<<4 |
                     (uint16_t)params.shadowmap<<6 |
                     (uint16_t)params.maxAnisotropy<<7;

    if (samplers[index] == 0)
    {
        GLuint sampler;
        glGenSamplers(1, &sampler);
        if (GLFL_GL_EXT_texture_filter_anisotropic)
        {
            float maxMaxAnisotropy = 1.0f;

            glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxMaxAnisotropy);

            float result = std::max(std::min(params.maxAnisotropy, maxMaxAnisotropy), 1.0f);

            glSamplerParameterf(sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, result);
        }

        switch (params.magFilter)
        {
        case GfxFilter::Bilinear:
        {
            glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            break;
        }
        case GfxFilter::Nearest:
        {
            glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        }
        }

        switch (params.wrapMode)
        {
        case GfxWrapMode::Stretch:
        {
            glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            break;
        }
        case GfxWrapMode::Repeat:
        {
            glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, GL_REPEAT);
            break;
        }
        case GfxWrapMode::Mirror:
        {
            glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
            glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
            break;
        }
        }

        switch (params.mipmapMode)
        {
        case GfxMipmapMode::None:
        {
            switch (params.minFilter)
            {
            case GfxFilter::Bilinear:
            {
                glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                break;
            }
            case GfxFilter::Nearest:
            {
                glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                break;
            }
            }
            break;
        }
        case GfxMipmapMode::Nearest:
        {
            switch (params.minFilter)
            {
            case GfxFilter::Bilinear:
            {
                glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
                break;
            }
            case GfxFilter::Nearest:
            {
                glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
                break;
            }
            }
            break;
        }
        case GfxMipmapMode::Linear:
        {
            switch (params.minFilter)
            {
            case GfxFilter::Bilinear:
            {
                glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                break;
            }
            case GfxFilter::Nearest:
            {
                glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
                break;
            }
            }
            break;
        }
        }

        if (params.shadowmap)
        {
            glSamplerParameteri(sampler, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
            glSamplerParameteri(sampler, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
        } else
        {
            glSamplerParameteri(sampler, GL_TEXTURE_COMPARE_MODE, GL_NONE);
        }

        samplers[index] = sampler;
    }

    return samplers[index];
}
