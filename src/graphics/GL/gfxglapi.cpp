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

#define UNIFORM_START GLint location;\
String newName = String::format("_%s_uniform", name);\
location = glGetUniformLocation(shader->getGLProgram(), newName.getData());\
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
                       textureBindingCount(0),
                       uboBindingCount(0),
                       mesh(nullptr)
{
    glflInit();

    std::sscanf((const char *)glGetString(GL_VERSION), "%u.%u", &glMajor, &glMinor);

    String vendor = (const char *)glGetString(GL_VENDOR);

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
        ERROR(CATEGORY_OPENGL, "GL_ARB_separate_shader_objects is not supported.")();
    }

    glGenProgramPipelines(1, &pipeline);
}

GfxGLApi::~GfxGLApi()
{
    glDeleteProgramPipelines(1, &pipeline);
}

GfxDriver GfxGLApi::getDriver() const
{
    return driver;
}

bool GfxGLApi::tesselationSupported()
{
    return GLFL_GL_ARB_tessellation_shader;
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
        glBindFramebuffer(GL_FRAMEBUFFER,
                          ((GfxGLFramebuffer *)framebuffer)->getGLFramebuffer());

        size_t numBuffers = framebuffer->getNumColorAttachments();

        for (size_t i = 0; i < numBuffers; ++i)
        {
            GfxTexture *texture = framebuffer->getColorAttachment(i);

            if (framebuffer->getColorAttachmentLayer(i) >= 0)
            {
                glFramebufferTextureLayer(GL_FRAMEBUFFER,
                                          GL_COLOR_ATTACHMENT0+framebuffer->getColorRT(i),
                                          ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                          framebuffer->getColorAttachmentMipmapLevel(i),
                                          framebuffer->getColorAttachmentLayer(i));

            } else
            {
                glFramebufferTexture(GL_FRAMEBUFFER,
                                     GL_COLOR_ATTACHMENT0+framebuffer->getColorRT(i),
                                     ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                     framebuffer->getColorAttachmentMipmapLevel(i));
            }
        }

        if (framebuffer->hasDepthAttachment())
        {
            GfxTexture *texture = framebuffer->getDepthTexture();

            if (framebuffer->getDepthAttachmentLayer() >= 0)
            {
                glFramebufferTextureLayer(GL_FRAMEBUFFER,
                                          GL_DEPTH_ATTACHMENT,
                                          ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                          framebuffer->getDepthTextureMipmapLevel(),
                                          framebuffer->getDepthAttachmentLayer());
            } else
            {
                glFramebufferTexture(GL_FRAMEBUFFER,
                                     GL_DEPTH_ATTACHMENT,
                                     ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                     framebuffer->getDepthTextureMipmapLevel());
            }
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
    glBindTexture(binding.target, dynamic_cast<GfxGLTextureImpl *>(binding.texture->getImpl())->getGLTexture());\
\
    glProgramUniform1i(binding.program, binding.location, i);\
    glBindSampler(i, binding.sampler);\
}\
for (size_t i = 0; i < uboBindingCount; ++i)\
{\
    const UBOBinding& binding = uboBindings[i];\
\
    glBindBufferBase(GL_UNIFORM_BUFFER, i, dynamic_cast<const GfxGLBuffer *>(binding.buffer)->getGLBuffer());\
    glUniformBlockBinding(binding.program, binding.location, i);\
}\
\
switch (mesh->cullMode)\
{\
case GfxCullNone:\
{\
    glDisable(GL_CULL_FACE);\
    break;\
}\
case GfxCullFront:\
{\
    glEnable(GL_CULL_FACE);\
    glCullFace(GL_FRONT);\
}\
case GfxCullBack:\
{\
    glEnable(GL_CULL_FACE);\
    glCullFace(GL_BACK);\
}\
}\
\
switch (mesh->winding)\
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
    glBindTexture(binding.target, 0);\
    binding.texture = nullptr;\
\
    glDeleteSamplers(1, &binding.sampler);\
    glBindSampler(i, 0);\
}\
\
textureBindingCount = 0;\
uboBindingCount = 0;

void GfxGLApi::begin(GfxCompiledShader *vertex_,
                     GfxCompiledShader *tessControl_,
                     GfxCompiledShader *tessEval_,
                     GfxCompiledShader *geometry_,
                     GfxCompiledShader *fragment_,
                     GfxMesh *mesh_)
{
    mesh = mesh_;
    tesselation = tessControl_ != nullptr or tessEval_ != nullptr;

    glBindVertexArray(mesh->getGLVAO());

    glBindProgramPipeline(pipeline);

    if (vertex_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, vertex_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, 0);
    }

    if (GLFL_GL_ARB_tessellation_shader)
    {
        if (tessControl_ != nullptr)
        {
            glUseProgramStages(pipeline, GL_TESS_CONTROL_SHADER_BIT, tessControl_->getGLProgram());
        } else
        {
            glUseProgramStages(pipeline, GL_TESS_CONTROL_SHADER_BIT, 0);
        }

        if (tessEval_ != nullptr)
        {
            glUseProgramStages(pipeline, GL_TESS_EVALUATION_SHADER_BIT, tessEval_->getGLProgram());
        } else
        {
            glUseProgramStages(pipeline, GL_TESS_EVALUATION_SHADER_BIT, 0);
        }
    }

    if (geometry_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_GEOMETRY_SHADER_BIT, geometry_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_GEOMETRY_SHADER_BIT, 0);
    }

    if (fragment_ != nullptr)
    {
        glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, fragment_->getGLProgram());
    } else
    {
        glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, 0);
    }
}

void GfxGLApi::draw(size_t instanceCount)
{
    if (mesh == nullptr)
    {
        return;
    }

    BEGIN_DRAW

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

void GfxGLApi::end(size_t instanceCount)
{
    if (mesh == nullptr)
    {
        return;
    }

    if (instanceCount != 0)
    {
        draw(instanceCount);
    }

    END_DRAW

    mesh = nullptr;
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

    /*GLuint program = dynamic_cast<GfxGLCompiledShader *>(shader)->getGLProgram();

    std::cout << name << ':' << std::endl;

    GLint num = 0;
    GLenum prop[] = {GL_NUM_ACTIVE_VARIABLES};
    glGetProgramResourceiv(program, GL_UNIFORM_BLOCK, location, 1, prop, 1, NULL, &num);

    GLint indices[num];
    GLenum prop3[] = {GL_ACTIVE_VARIABLES};
    glGetProgramResourceiv(program, GL_UNIFORM_BLOCK, location, 1, prop3, num, NULL, indices);

    for (size_t i = 0; i < num; ++i)
    {
        GLint len;
        GLenum prop2[] = {GL_NAME_LENGTH};

        glGetProgramResourceiv(program, GL_UNIFORM, indices[i], 1, prop2, 1, NULL, &len);

        char name[len+1];
        name[len] = '\x00';
        glGetProgramResourceName(program, GL_UNIFORM, indices[i], len, NULL, name);

        GLint offset;
        GLenum prop4[] = {GL_OFFSET};
        glGetProgramResourceiv(program, GL_UNIFORM, indices[i], 1, prop4, 1, NULL, &offset);

        std::cout << "    " << offset << ' ' << name << std::endl;
    }*/

    if (uboBindingCount < sizeof(uboBindings)/sizeof(UBOBinding))
    {
        uboBindings[uboBindingCount++] = (UBOBinding){.buffer = buffer,
                                                      .location = location,
                                                      .program = shader->getGLProgram()};
    }
}

void GfxGLApi::addTextureBinding(GfxCompiledShader *shader, const char *name, GfxTexture *texture, TextureSampler sampler)
{
    UNIFORM_START

    GLuint glSampler;
    glGenSamplers(1, &glSampler);

    if (GLFL_GL_EXT_texture_filter_anisotropic)
    {
        float maxMaxAnisotropy = 1.0f;

        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxMaxAnisotropy);

        float result = std::max(std::min(sampler.maxAnisotropy, maxMaxAnisotropy), 1.0f);

        glSamplerParameterf(glSampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, result);
    }

    switch (sampler.magFilter)
    {
    case GfxFilter::Bilinear:
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    }
    case GfxFilter::Nearest:
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    }

    switch (sampler.wrapMode)
    {
    case GfxWrapMode::Stretch:
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glSamplerParameteri(glSampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        break;
    }
    case GfxWrapMode::Repeat:
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glSamplerParameteri(glSampler, GL_TEXTURE_WRAP_T, GL_REPEAT);
        break;
    }
    case GfxWrapMode::Mirror:
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glSamplerParameteri(glSampler, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        break;
    }
    }

    switch (sampler.mipmapMode)
    {
    case GfxMipmapMode::None:
    {
        switch (sampler.minFilter)
        {
        case GfxFilter::Bilinear:
        {
            glSamplerParameteri(glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            break;
        }
        case GfxFilter::Nearest:
        {
            glSamplerParameteri(glSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            break;
        }
        }
        break;
    }
    case GfxMipmapMode::Nearest:
    {
        switch (sampler.minFilter)
        {
        case GfxFilter::Bilinear:
        {
            glSamplerParameteri(glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            break;
        }
        case GfxFilter::Nearest:
        {
            glSamplerParameteri(glSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
            break;
        }
        }
        break;
    }
    case GfxMipmapMode::Linear:
    {
        switch (sampler.minFilter)
        {
        case GfxFilter::Bilinear:
        {
            glSamplerParameteri(glSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            break;
        }
        case GfxFilter::Nearest:
        {
            glSamplerParameteri(glSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            break;
        }
        }
        break;
    }
    }

    if (sampler.shadowmap)
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
        glSamplerParameteri(glSampler, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    } else
    {
        glSamplerParameteri(glSampler, GL_TEXTURE_COMPARE_MODE, GL_NONE);
    }

    if (textureBindingCount < sizeof(textureBindings)/sizeof(TextureBinding))
    {
        textureBindings[textureBindingCount++] = (TextureBinding){.texture = texture,
                                                                  .target = dynamic_cast<GfxGLTextureImpl *>(texture->getImpl())->getGLTarget(),
                                                                  .location = location,
                                                                  .program = shader->getGLProgram(),
                                                                  .bindingGet = dynamic_cast<GfxGLTextureImpl *>(texture->getImpl())->getGLBindingGet(),
                                                                  .sampler = glSampler};
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
