#include "graphics/GL/gfxgltextureimpl.h"

#include "logging.h"
#include "graphics/GL/gfxglframebuffer.h"

static GLenum internalFormats[] = {GL_R8,
                                   GL_R8_SNORM,
                                   GL_R16,
                                   GL_R16_SNORM,
                                   GL_R32F,
                                   GL_R16F,

                                   GL_R8,
                                   GL_R8_SNORM,
                                   GL_R16,
                                   GL_R16_SNORM,
                                   GL_R32F,
                                   GL_R16F,

                                   GL_RG8,
                                   GL_RG8_SNORM,
                                   GL_RG16,
                                   GL_RG16_SNORM,
                                   GL_RG32F,
                                   GL_RG16F,

                                   GL_RGB8,
                                   GL_RGB8_SNORM,
                                   GL_RGB16,
                                   GL_RGB16_SNORM,
                                   GL_RGB32F,
                                   GL_RGB16F,

                                   GL_RGBA8,
                                   GL_RGBA8_SNORM,
                                   GL_RGBA16,
                                   GL_RGBA16_SNORM,
                                   GL_RGBA32F,
                                   GL_RGBA16F,

                                   GL_R8I,
                                   GL_R8UI,
                                   GL_R16I,
                                   GL_R16UI,
                                   GL_R32I,
                                   GL_R32UI,

                                   GL_RG8I,
                                   GL_RG8UI,
                                   GL_RG16I,
                                   GL_RG16UI,
                                   GL_RG32I,
                                   GL_RG32UI,

                                   GL_RGB8I,
                                   GL_RGB8UI,
                                   GL_RGB16I,
                                   GL_RGB16UI,
                                   GL_RGB32I,
                                   GL_RGB32UI,

                                   GL_RGBA8I,
                                   GL_RGBA8UI,
                                   GL_RGBA16I,
                                   GL_RGBA16UI,
                                   GL_RGBA32I,
                                   GL_RGBA32UI,

                                   GL_SRGB8,
                                   GL_SRGB8_ALPHA8,

                                   GL_DEPTH_COMPONENT16,
                                   GL_DEPTH_COMPONENT24,
                                   GL_DEPTH_COMPONENT32,

                                   GL_RG8,
                                   GL_RG8_SNORM,
                                   GL_RG16,
                                   GL_RG16_SNORM,
                                   GL_RG32F,
                                   GL_RG16F,

                                   GL_R8,
                                   GL_R8_SNORM,
                                   GL_R16,
                                   GL_R16_SNORM,
                                   GL_R32F,
                                   GL_R16F};

static GLenum formats[] = {GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,

                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,

                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,

                           GL_RGB,
                           GL_RGB,
                           GL_RGB,
                           GL_RGB,
                           GL_RGB,
                           GL_RGB,

                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,

                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,

                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,

                           GL_RGB,
                           GL_RGB,
                           GL_RGB,
                           GL_RGB,
                           GL_RGB,
                           GL_RGB,

                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,
                           GL_RGBA,

                           GL_RGB,
                           GL_RGBA,

                           GL_DEPTH_COMPONENT,
                           GL_DEPTH_COMPONENT,
                           GL_DEPTH_COMPONENT,

                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,
                           GL_RG,

                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED,
                           GL_RED};

static GLenum types[] = {GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_UNSIGNED_INT,
                         GL_INT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_UNSIGNED_INT,
                         GL_INT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_UNSIGNED_INT,
                         GL_INT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_UNSIGNED_INT,
                         GL_INT,

                         GL_UNSIGNED_BYTE,
                         GL_UNSIGNED_BYTE,

                         GL_FLOAT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT,

                         GL_UNSIGNED_BYTE,
                         GL_BYTE,
                         GL_UNSIGNED_SHORT,
                         GL_SHORT,
                         GL_FLOAT,
                         GL_FLOAT};

#define R GL_RED
#define G GL_GREEN
#define B GL_BLUE
#define A GL_ALPHA
#define O GL_ONE
#define Z GL_ZERO

static GLint swizzles[][4] = {{O, O, O, R},
                              {O, O, O, R},
                              {O, O, O, R},
                              {O, O, O, R},
                              {O, O, O, R},
                              {O, O, O, R},

                              {R, R, R, O},
                              {R, R, R, O},
                              {R, R, R, O},
                              {R, R, R, O},
                              {R, R, R, O},
                              {R, R, R, O},

                              {R, R, R, G},
                              {R, R, R, G},
                              {R, R, R, G},
                              {R, R, R, G},
                              {R, R, R, G},
                              {R, R, R, G},

                              {R, G, B, O},
                              {R, G, B, O},
                              {R, G, B, O},
                              {R, G, B, O},
                              {R, G, B, O},
                              {R, G, B, O},

                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},

                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},

                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},

                              {R, G, B, Z},
                              {R, G, B, Z},
                              {R, G, B, Z},
                              {R, G, B, Z},
                              {R, G, B, Z},
                              {R, G, B, Z},

                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},
                              {R, G, B, A},

                              {R, G, B, Z},
                              {R, G, B, A},

                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},

                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},
                              {R, G, Z, Z},

                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z},
                              {R, Z, Z, Z}};

#undef R
#undef G
#undef B
#undef A
#undef O
#undef Z

GLenum textureTargets[] = {GL_TEXTURE_2D, GL_TEXTURE_CUBE_MAP, GL_TEXTURE_3D, GL_TEXTURE_2D_ARRAY};
GLenum textureBindingGets[] = {GL_TEXTURE_BINDING_2D, GL_TEXTURE_BINDING_CUBE_MAP, GL_TEXTURE_BINDING_3D, GL_TEXTURE_BINDING_2D_ARRAY};

#define BEGIN_TEXTURE_BINDING GLint lastTexture;\
GLenum target = textureTargets[(int)textureType];\
glGetIntegerv(textureBindingGets[(int)textureType], &lastTexture);\
glBindTexture(target, texture);

#define END_TEXTURE_BINDING glBindTexture(target, lastTexture);

#define SET_DEFAULT_GL glTexImage2D(target, 0, GL_RGB, 0, 0, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);\
glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

#define SET_TEXTURE_DATA \
glPixelStorei(GL_UNPACK_ALIGNMENT, pixelAlignment);\
unsigned int width = TEX_COMPUTE_MIPMAP_SIZE(baseWidth, level);\
unsigned int height = TEX_COMPUTE_MIPMAP_SIZE(baseHeight, level);\
if (textureType == GfxTextureType::Texture2D or textureType == GfxTextureType::CubeMap)\
{\
    glTexImage2D(target,\
                 level,\
                 internalFormats[(int)format],\
                 width,\
                 height,\
                 0,\
                 formats[(int)format],\
                 types[(int)format],\
                 data);\
} else if (textureType == GfxTextureType::Texture2DArray)\
{\
    unsigned int depth = TEX_COMPUTE_MIPMAP_SIZE(baseDepth, level);\
    glTexImage3D(target,\
                 level,\
                 internalFormats[(int)format],\
                 width,\
                 height,\
                 depth,\
                 0,\
                 formats[(int)format],\
                 types[(int)format],\
                 data);\
} else\
{\
    unsigned int depth = TEX_COMPUTE_MIPMAP_SIZE(baseDepth, level);\
    glTexImage3D(target,\
                 level,\
                 internalFormats[(int)format],\
                 width,\
                 height,\
                 depth,\
                 0,\
                 formats[(int)format],\
                 types[(int)format],\
                 data);\
}

//TODO: The framebuffer list will not be copied from the old texture impl when removeContent() is called.
GfxGLTextureImpl::GfxGLTextureImpl()
{
    textureType = GfxTextureType::Texture2D;

    glGenTextures(1, &texture);

    BEGIN_TEXTURE_BINDING
    SET_DEFAULT_GL
    END_TEXTURE_BINDING

    baseWidth = 0;
    baseHeight = 0;
    baseDepth = 0;
}

GfxGLTextureImpl::~GfxGLTextureImpl()
{
    glDeleteTextures(1, &texture);
}

void GfxGLTextureImpl::startCreation(GfxTextureType type_,
                                     unsigned int baseWidth_,
                                     unsigned int baseHeight_,
                                     unsigned int baseDepth_,
                                     GfxTexFormat format_)
{
    glDeleteTextures(1, &texture);
    glGenTextures(1, &texture);

    textureType = type_;
    baseWidth = baseWidth_;
    baseHeight = baseHeight_;
    baseDepth = baseDepth_;
    format = format_;

    BEGIN_TEXTURE_BINDING

    glTexParameteriv(target, GL_TEXTURE_SWIZZLE_RGBA, swizzles[(int)format_]);

    END_TEXTURE_BINDING

    for (auto fb : framebuffers)
    {
        fb->setDirty();
    }
}

void GfxGLTextureImpl::allocMipmapFace(unsigned int level,
                                       unsigned int pixelAlignment,
                                       GfxFace face,
                                       const void *data)
{
    if (textureType != GfxTextureType::CubeMap)
    {
        return;
    }

    GLint lastTexture;

    GLenum target = GL_TEXTURE_CUBE_MAP_POSITIVE_X + (int)face;

    glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &lastTexture);

    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

    SET_TEXTURE_DATA

    glBindTexture(GL_TEXTURE_CUBE_MAP, lastTexture);
}

void GfxGLTextureImpl::allocMipmap(unsigned int level,
                                   unsigned int pixelAlignment,
                                   const void *data)
{
    if (textureType == GfxTextureType::CubeMap)
    {
        return;
    }

    BEGIN_TEXTURE_BINDING
    SET_TEXTURE_DATA;
    END_TEXTURE_BINDING
}

void GfxGLTextureImpl::getMipmapFace(unsigned int level,
                                     unsigned int pixelAlignment,
                                     GfxFace face,
                                     void *data)
{
    if (textureType != GfxTextureType::CubeMap)
    {
        return;
    }

    GLint lastTexture;

    GLenum target = GL_TEXTURE_CUBE_MAP_POSITIVE_X + (int)face;

    glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &lastTexture);

    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

    glGetTexImage(target,
                  level,
                  formats[static_cast<int>(format)],
                  types[static_cast<int>(format)],
                  data);

    glBindTexture(GL_TEXTURE_CUBE_MAP, lastTexture);
}

void GfxGLTextureImpl::getMipmap(unsigned int level,
                                 unsigned int pixelAlignment,
                                 void *data)
{
    if (textureType != GfxTextureType::CubeMap)
    {
        return;
    }

    GLint lastTexture;

    glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTexture);

    glBindTexture(GL_TEXTURE_2D, texture);

    glGetTexImage(GL_TEXTURE_2D,
                  level,
                  formats[static_cast<int>(format)],
                  types[static_cast<int>(format)],
                  data);

    glBindTexture(GL_TEXTURE_2D, lastTexture);
}

void GfxGLTextureImpl::generateMipmaps()
{
    BEGIN_TEXTURE_BINDING

    glGenerateMipmap(target);

    END_TEXTURE_BINDING
}

GLenum GfxGLTextureImpl::getGLTarget() const
{
    return textureTargets[(int)textureType];
}

GLenum GfxGLTextureImpl::getGLBindingGet() const
{
    return textureBindingGets[(int)textureType];
}

GLenum GfxGLTextureImpl::getGLInternalFormat() const
{
    return formats[(int)format];
}
