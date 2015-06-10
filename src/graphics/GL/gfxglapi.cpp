#include "graphics/GL/gfxglapi.h"

#include "graphics/gfxbuffer.h"
#include "graphics/gfxtexture.h"
#include "graphics/GL/gfxglshaderimpl.h"
#include "graphics/GL/gfxglmeshimpl.h"
#include "graphics/GL/gfxgltextureimpl.h"
#include "graphics/GL/gfxglbuffer.h"
#include "graphics/GL/gfxglframebuffer.h"
#include "logging.h"
#include "memory.h"
#include "error.h"
#include "file.h"

#include <cstdio>
#include <cstring>

#ifdef DEBUG
#define BEGIN_END_TEST beginEndTest()
#else
#define BEGIN_END_TEST
#endif

//WARN(CATEGORY_RENDER, "Uniform does not exist. It may have been optimized out.")(name);
#define UNIFORM_START BEGIN_END_TEST;\
GLint location = glGetUniformLocation(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), name);\
if (location == -1)\
{\
    return;\
}

GLenum toGLPrimitive[] = {GL_POINTS,
                          GL_LINE_STRIP,
                          GL_LINE_LOOP,
                          GL_LINES,
                          GL_TRIANGLE_STRIP,
                          GL_TRIANGLE_FAN,
                          GL_TRIANGLES,
                          GL_PATCHES};

GLenum toGLBlendFactor[] = {GL_ZERO,
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

GLenum toGLBlendMode[] = {GL_FUNC_ADD, GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT};

GLenum toGLDepthFunc[] = {GL_NEVER,
                          GL_LESS,
                          GL_EQUAL,
                          GL_LEQUAL,
                          GL_GREATER,
                          GL_NOTEQUAL,
                          GL_GEQUAL,
                          GL_ALWAYS};

void printOpenGLInfo()
{
    const char *vendor = reinterpret_cast<const char *>(glGetString(GL_VENDOR));
    const char *renderer = reinterpret_cast<const char *>(glGetString(GL_RENDERER));
    const char *version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
    const char *glslVersion = reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));

    String extensions;

    GLint numExtensions;

    glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

    for (GLint i = 0; i < numExtensions; ++i)
    {
        extensions.append
        (reinterpret_cast<const char *>(glGetStringi(GL_EXTENSIONS, i)));

        extensions.append('\n');
    }

    INFO(CATEGORY_OPENGL, "OpenGL information.")(vendor,
                                                 renderer,
                                                 version,
                                                 glslVersion,
                                                 extensions);
}

void debugCallback(GLenum source,
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
        behavior(CATEGORY_OPENGL, "OpenGL error.")(message);\
        break;\
    }\
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:\
    {\
        behavior(CATEGORY_OPENGL, "OpenGL deprecated behavoir.")(message);\
        break;\
    }\
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:\
    {\
        behavior(CATEGORY_OPENGL, "OpenGL undefined behavior.")(message);\
        break;\
    }\
    case GL_DEBUG_TYPE_PORTABILITY:\
    {\
        behavior(CATEGORY_OPENGL, "OpenGL portibility problem.")(message);\
        break;\
    }\
    default:\
    {\
        behavior(CATEGORY_OPENGL, "OpenGL message.")(message);\
        break;\
    }\
    }

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
    {
        HANDLE_MESSAGE(FATAL);
        break;
    }
    case GL_DEBUG_SEVERITY_MEDIUM:
    {
        HANDLE_MESSAGE(ERROR);
        break;
    }
    case GL_DEBUG_SEVERITY_LOW:
    {
        HANDLE_MESSAGE(WARN);
        break;
    }
    default:
    {
        HANDLE_MESSAGE(INFO);
        break;
    }
    }
}

GfxGLApi::GfxGLApi() : stateStackSize(0),
                       inBeginEnd(false),
                       textureBindingCount(0),
                       uboBindingCount(0)
{
    glflInit();

    resetState();

    printOpenGLInfo();

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(debugCallback, nullptr);

    glEnable(GL_DEPTH_TEST);

    if (GLFL_GL_ARB_seamless_cube_map)
    {
        glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
    }

    glGenProgramPipelines(1, &pipeline);
}

GfxGLApi::~GfxGLApi()
{
    glDeleteProgramPipelines(1, &pipeline);
}

GfxShaderImpl *GfxGLApi::createShaderImpl()
{
    return NEW(GfxGLShaderImpl);
}

GfxBuffer *GfxGLApi::createBuffer()
{
    return NEW(GfxGLBuffer);
}

GfxTextureImpl *GfxGLApi::createTextureImpl()
{
    return NEW(GfxGLTextureImpl);
}

GfxMeshImpl *GfxGLApi::createMeshImpl()
{
    return NEW(GfxGLMeshImpl);
}

GfxFramebuffer *GfxGLApi::createFramebuffer()
{
    return NEW(GfxGLFramebuffer);
}

void GfxGLApi::setCurrentFramebuffer(GfxFramebuffer *framebuffer)
{
    if (framebuffer != NULL)
    {
        glBindFramebuffer(GL_FRAMEBUFFER,
                          ((GfxGLFramebuffer *)framebuffer)->getGLFramebuffer());

        size_t numBuffers = framebuffer->getNumColorAttachments();

        for (size_t i = 0; i < numBuffers; ++i)
        {
            ResPtr<GfxTexture> texture = framebuffer->getColorAttachment(i);

            glFramebufferTexture2D(GL_FRAMEBUFFER,
                                   GL_COLOR_ATTACHMENT0+framebuffer->getColorRT(i),
                                   GL_TEXTURE_2D,
                                   ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                   framebuffer->getColorAttachmentMipmapLevel(i));
        }

        if (framebuffer->hasDepthAttachment())
        {
            ResPtr<GfxTexture> texture = framebuffer->getDepthTexture();

            glFramebufferTexture2D(GL_FRAMEBUFFER,
                                   GL_DEPTH_ATTACHMENT,
                                   GL_TEXTURE_2D,
                                   ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                   framebuffer->getDepthTextureMipmapLevel());
        }

        GLenum drawBuffers[numBuffers];

        for (size_t i = 0; i < numBuffers; ++i)
        {
            drawBuffers[i] = GL_COLOR_ATTACHMENT0+i;
        }

        glDrawBuffers(numBuffers, drawBuffers);
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

#define BEGIN_DRAW for (size_t i = 0; i < textureBindingCount; ++i)\
{\
    TextureBinding& binding = textureBindings[i];\
\
    glActiveTexture(GL_TEXTURE0+i);\
\
    glGetIntegerv(binding.bindingGet, &binding.lastTexture);\
\
    glBindTexture(binding.target, dynamic_cast<GfxGLTextureImpl *>(binding.texture->getImpl())->getGLTexture());\
\
    glProgramUniform1i(binding.program, binding.location, i);\
}\
for (size_t i = 0; i < uboBindingCount; ++i)\
{\
    UBOBinding& binding = uboBindings[i];\
\
    glBindBufferBase(GL_UNIFORM_BUFFER, i, dynamic_cast<const GfxGLBuffer *>(binding.buffer)->getGLBuffer());\
    glUniformBlockBinding(binding.program, binding.location, i);\
}\
\
switch (winding)\
{\
case GfxCCW:\
{\
    glFrontFace(GL_CCW);\
    break;\
}\
case GfxCW:\
{\
    glFrontFace(GL_CW);\
    break;\
}\
}

#define END_DRAW for (size_t i = 0; i < textureBindingCount; ++i)\
{\
    TextureBinding& binding = textureBindings[i];\
\
    glActiveTexture(GL_TEXTURE0+i);\
    glBindTexture(binding.target, binding.lastTexture);\
    binding.texture = nullptr;\
}\
\
textureBindingCount = 0;\
uboBindingCount = 0;\
\
inBeginEnd = false;\
glBindVertexArray(0);

void GfxGLApi::begin(GfxCompiledShader *vertex_,
                     GfxCompiledShader *tessControl_,
                     GfxCompiledShader *tessEval_,
                     GfxCompiledShader *geometry_,
                     GfxCompiledShader *fragment_,
                     ResPtr<GfxMesh> mesh)
{
    glBindVertexArray(dynamic_cast<GfxGLMeshImpl *>(mesh->getImpl())->getGLVAO());

    glBindProgramPipeline(pipeline);

    if (vertex_ != nullptr)
    {
        GfxGLCompiledShader *glVertex = dynamic_cast<GfxGLCompiledShader *>(vertex_);

        glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, glVertex->getGLProgram());
        vertex = glVertex->getGLProgram();
    } else
    {
        glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, 0);
        vertex = 0;
    }

    if (tessControl_ != nullptr)
    {
        GfxGLCompiledShader *glTessControl = dynamic_cast<GfxGLCompiledShader *>(tessControl_);

        glUseProgramStages(pipeline, GL_TESS_CONTROL_SHADER_BIT, glTessControl->getGLProgram());
        tessControl = glTessControl->getGLProgram();
    } else
    {
        glUseProgramStages(pipeline, GL_TESS_CONTROL_SHADER_BIT, 0);
        tessControl = 0;
    }

    if (tessEval_ != nullptr)
    {
        GfxGLCompiledShader *glTessEval = dynamic_cast<GfxGLCompiledShader *>(tessEval_);

        glUseProgramStages(pipeline, GL_TESS_EVALUATION_SHADER_BIT, glTessEval->getGLProgram());
        tessEval = glTessEval->getGLProgram();
    } else
    {
        glUseProgramStages(pipeline, GL_TESS_EVALUATION_SHADER_BIT, 0);
        tessEval = 0;
    }

    if (geometry_ != nullptr)
    {
        GfxGLCompiledShader *glGeometry = dynamic_cast<GfxGLCompiledShader *>(geometry_);

        glUseProgramStages(pipeline, GL_GEOMETRY_SHADER_BIT, glGeometry->getGLProgram());
        geometry = glGeometry->getGLProgram();
    } else
    {
        glUseProgramStages(pipeline, GL_GEOMETRY_SHADER_BIT, 0);
        geometry = 0;
    }

    if (fragment_ != nullptr)
    {
        GfxGLCompiledShader *glFragment = dynamic_cast<GfxGLCompiledShader *>(fragment_);

        glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, glFragment->getGLProgram());
        fragment = glFragment->getGLProgram();
    } else
    {
        glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, 0);
        fragment = 0;
    }

    inBeginEnd = true;
}

void GfxGLApi::end(GfxPrimitive primitive, uint32_t count, GfxWinding winding)
{
    BEGIN_DRAW

    glDrawArrays(toGLPrimitive[primitive], 0, count);

    END_DRAW
}

void GfxGLApi::endIndexed(GfxPrimitive primitive,
                          GfxVertexAttribType type,
                          uint32_t count,
                          size_t offset,
                          GfxBuffer *indices,
                          GfxWinding winding)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, dynamic_cast<GfxGLBuffer *>(indices)->getGLBuffer());

    BEGIN_DRAW

    switch (type)
    {
    case GfxUnsignedByte:
    {
        glDrawElements(toGLPrimitive[primitive],
                       count,
                       GL_UNSIGNED_BYTE,
                       (const GLvoid *)offset);
        break;
    }
    case GfxUnsignedShort:
    {
        glDrawElements(toGLPrimitive[primitive],
                       count,
                       GL_UNSIGNED_SHORT,
                       (const GLvoid *)offset);
        break;
    }
    case GfxUnsignedInteger:
    {
        glDrawElements(toGLPrimitive[primitive],
                       count,
                       GL_UNSIGNED_INT,
                       (const GLvoid *)offset);
        break;
    }
    default: {break;}
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    END_DRAW
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, float value)
{
    UNIFORM_START

    glProgramUniform1f(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Float2& value)
{
    UNIFORM_START

    glProgramUniform2f(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Float3& value)
{
    UNIFORM_START

    glProgramUniform3f(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y, value.z);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Float4& value)
{
    UNIFORM_START

    glProgramUniform4f(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y, value.z, value.w);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, int32_t value)
{
    UNIFORM_START

    glProgramUniform1i(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Int2& value)
{
    UNIFORM_START

    glProgramUniform2i(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Int3& value)
{
    UNIFORM_START

    glProgramUniform3i(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y, value.z);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Int4& value)
{
    UNIFORM_START

    glProgramUniform4i(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y, value.z, value.w);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, uint32_t value)
{
    UNIFORM_START

    glProgramUniform1ui(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const UInt2& value)
{
    UNIFORM_START

    glProgramUniform2ui(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const UInt3& value)
{
    UNIFORM_START

    glProgramUniform3ui(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.y, value.y, value.z);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const UInt4& value)
{
    UNIFORM_START

    glProgramUniform4ui(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, value.x, value.y, value.z, value.w);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const float *values)
{
    UNIFORM_START

    glProgramUniform1fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float2 *values)
{
    UNIFORM_START

    glProgramUniform2fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float3 *values)
{
    UNIFORM_START

    glProgramUniform3fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float4 *values)
{
    UNIFORM_START

    glProgramUniform4fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLfloat *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const int32_t *values)
{
    UNIFORM_START

    glProgramUniform1iv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int2 *values)
{
    UNIFORM_START

    glProgramUniform2iv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int3 *values)
{
    UNIFORM_START

    glProgramUniform3iv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int4 *values)
{
    UNIFORM_START

    glProgramUniform4iv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const uint32_t *values)
{
    UNIFORM_START

    glProgramUniform1uiv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt2 *values)
{
    UNIFORM_START

    glProgramUniform2uiv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt3 *values)
{
    UNIFORM_START

    glProgramUniform3uiv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt4 *values)
{
    UNIFORM_START

    glProgramUniform4uiv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, (const GLuint *)values);
}

void GfxGLApi::addUBOBinding(GfxCompiledShader *shader, const char *name, const GfxBuffer *buffer)
{
    GLint location = glGetUniformBlockIndex(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), name);

    if (location == -1)
    {
        return;
    }

    if (uboBindingCount < sizeof(uboBindings)/sizeof(UBOBinding))
    {
        uboBindings[uboBindingCount++] = (UBOBinding){.buffer = buffer,
                                                      .location = location,
                                                      .program = dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram()};
    }
}

void GfxGLApi::addTextureBinding(GfxCompiledShader *shader, const char *name, ResPtr<GfxTexture> texture)
{
    UNIFORM_START

    if (textureBindingCount < sizeof(textureBindings)/sizeof(TextureBinding))
    {
        textureBindings[textureBindingCount++] = (TextureBinding){.texture = texture,
                                                                  .target = dynamic_cast<GfxGLTextureImpl *>(texture->getImpl())->getGLTarget(),
                                                                  .location = location,
                                                                  .program = dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(),
                                                                  .bindingGet = dynamic_cast<GfxGLTextureImpl *>(texture->getImpl())->getGLBindingGet()};
    }
}
void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Matrix3x3& value)
{
    UNIFORM_START

    glProgramUniformMatrix3fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, 1, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, const Matrix4x4& value)
{
    UNIFORM_START

    glProgramUniformMatrix4fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, 1, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix3x3 *value)
{
    UNIFORM_START

    glProgramUniformMatrix3fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix4x4 *value)
{
    UNIFORM_START

    glProgramUniformMatrix4fv(dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram(), location, count, GL_TRUE, reinterpret_cast<const float *>(&value));
}

void GfxGLApi::pushState()
{
    #ifdef DEBUG
    FATAL_IF_TRUE(CATEGORY_RENDER,
                  stateStackSize == (sizeof(stateStack)/sizeof(State)),
                  "State stack overflow")();
    #endif

    stateStack[stateStackSize++] = currentState;
}

void GfxGLApi::popState()
{
    FATAL_IF_TRUE(CATEGORY_RENDER,
                  stateStackSize == 0,
                  "State stack underflow")();

    useState(stateStack[--stateStackSize]);
}

void GfxGLApi::resetState()
{
    State state;

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
    state.cullMode = GfxCullNone;

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
}

void GfxGLApi::beginEndTest()
{
    FATAL_IF_TRUE(CATEGORY_RENDER,
                  inBeginEnd == false,
                  "Function call is not between GfxApi::begin and GfxApi::end.")();
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
