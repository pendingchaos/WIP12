#include "graphics/GL/gfxgltextureimpl.h"

#include "logging.h"

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
                                   GL_SRGB8_ALPHA8};

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
                           GL_RGBA};

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
                         GL_UNSIGNED_BYTE};

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
                               {R, G, B, A}};

#undef R
#undef G
#undef B
#undef A
#undef O
#undef Z

#define BEGIN_TEXTURE_BINDING GLint lastTexture;\
GLenum target = textureType == GfxTexture::CubeMap\
                ? GL_TEXTURE_CUBE_MAP\
                : GL_TEXTURE_2D;\
glGetIntegerv(textureType == GfxTexture::CubeMap\
              ? GL_TEXTURE_BINDING_CUBE_MAP\
              : GL_TEXTURE_BINDING_2D, &lastTexture);\
glBindTexture(target, texture);

#define END_TEXTURE_BINDING glBindTexture(target, lastTexture);

#define SET_DEFAULT textureType = Texture2D;\
    compress = false;\
    maximumAnisotropy = 1.0f;\
    minFilter = Bilinear;\
    magFilter = Bilinear;\
    mipmapMode = None;\
    wrapMode = Repeat;\
    gamma = 1.0f;\
    baseWidth = 0;\
    baseHeight = 0;\
    compressionQuality = 255;\
    purpose = Other;\
    format = RGBU8;

#define SET_DEFAULT_GL glTexImage2D(target, 0, GL_RGB, 0, 0, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);\
glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

#define SET_TEXTURE_DATA \
glPixelStorei(GL_UNPACK_ALIGNMENT, pixelAlignment);\
unsigned int width = TEX_COMPUTE_MIPMAP_SIZE(baseWidth, level);\
unsigned int height = TEX_COMPUTE_MIPMAP_SIZE(baseHeight, level);\
glTexImage2D(target,\
             level,\
             internalFormats[(int)format],\
             width,\
             height,\
             0,\
             formats[(int)format],\
             types[(int)format],\
             data);

GfxGLTextureImpl::GfxGLTextureImpl()
{
    glGenTextures(1, &texture);

    textureType = GfxTexture::Texture2D;
    minFilter = GfxTexture::Bilinear;
    mipmapMode = GfxTexture::None;

    BEGIN_TEXTURE_BINDING
    SET_DEFAULT_GL
    END_TEXTURE_BINDING
}

GfxGLTextureImpl::~GfxGLTextureImpl()
{
    glDeleteTextures(1, &texture);
}

void GfxGLTextureImpl::startCreation(GfxTexture::TextureType type_,
                                     bool compress_,
                                     unsigned int baseWidth_,
                                     unsigned int baseHeight_,
                                     uint8_t compressionQuality_,
                                     GfxTexture::Purpose purpose_,
                                     GfxTexture::Format format_)
{
    glDeleteTextures(1, &texture);
    glGenTextures(1, &texture);

    textureType = type_;
    baseWidth = baseWidth_;
    baseHeight = baseHeight_;
    format = format_;

    BEGIN_TEXTURE_BINDING

    glTexParameteriv(target, GL_TEXTURE_SWIZZLE_RGBA, swizzles[(int)format_]);

    END_TEXTURE_BINDING
}

void GfxGLTextureImpl::allocMipmapFace(unsigned int level,
                                       unsigned int pixelAlignment,
                                       GfxTexture::Face face,
                                       const void *data)
{
    WARN_IF_FALSE(CATEGORY_RENDER,
                  textureType == GfxTexture::CubeMap,
                  "Trying to allocate data for a cubemap "
                  "face for a texture that is not a cubemap.")();

    if (textureType != GfxTexture::CubeMap)
    {
        return;
    }

    GLint lastTexture;

    GLenum target = GL_TEXTURE_CUBE_MAP_POSITIVE_X + face;

    glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &lastTexture);

    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

    SET_TEXTURE_DATA

    glBindTexture(GL_TEXTURE_CUBE_MAP, lastTexture);
}

void GfxGLTextureImpl::allocMipmap(unsigned int level,
                                   unsigned int pixelAlignment,
                                   const void *data)
{
    WARN_IF_FALSE(CATEGORY_RENDER,
                  textureType == GfxTexture::Texture2D,
                  "Trying to allocate data for a 2d texture "
                  "for a texture that is not 2d.")();

    if (textureType != GfxTexture::Texture2D)
    {
        return;
    }

    BEGIN_TEXTURE_BINDING
    SET_TEXTURE_DATA;
    END_TEXTURE_BINDING
}

void GfxGLTextureImpl::getMipmapFace(unsigned int level,
                                     unsigned int pixelAlignment,
                                     GfxTexture::Face face,
                                     void *data)
{
    WARN_IF_FALSE(CATEGORY_RENDER,
                  textureType == GfxTexture::CubeMap,
                  "Trying to allocate data for a cubemap "
                  "face for a texture that is not a cubemap.")();

    if (textureType != GfxTexture::CubeMap)
    {
        return;
    }

    GLint lastTexture;

    GLenum target = GL_TEXTURE_CUBE_MAP_POSITIVE_X + face;

    glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &lastTexture);

    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

    glGetTexImage(target,
                  level,
                  formats[static_cast<int>(format)],
                  GL_UNSIGNED_BYTE,
                  data);

    glBindTexture(GL_TEXTURE_CUBE_MAP, lastTexture);
}

void GfxGLTextureImpl::getMipmap(unsigned int level,
                                 unsigned int pixelAlignment,
                                 void *data)
{
    WARN_IF_FALSE(CATEGORY_RENDER,
                  textureType == GfxTexture::Texture2D,
                  "Trying to allocate data for a 2d texture "
                  "for a texture that is not 2d.")();

    if (textureType != GfxTexture::Texture2D)
    {
        return;
    }

    GLint lastTexture;

    glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTexture);

    glBindTexture(GL_TEXTURE_2D, texture);

    glGetTexImage(GL_TEXTURE_2D,
                  level,
                  formats[static_cast<int>(format)],
                  GL_UNSIGNED_BYTE,
                  data);

    glBindTexture(GL_TEXTURE_2D, lastTexture);
}

GLenum GfxGLTextureImpl::getGLInternalFormat() const
{
    return formats[(int)format];
}

void GfxGLTextureImpl::setMaximumAnisotropy(float maxAnisotropy)
{
    if (GLFL_GL_EXT_texture_filter_anisotropic)
    {
        BEGIN_TEXTURE_BINDING;

        float maxMaxAnisotropy = 1.0f;

        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxMaxAnisotropy);

        if (maxAnisotropy > maxMaxAnisotropy)
        {
            maxAnisotropy = maxMaxAnisotropy;
        }

        if (maxAnisotropy < 1.0f)
        {
            maxAnisotropy = 1.0f;
        }

        glTexParameterf(target, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);

        END_TEXTURE_BINDING;
    }
}

void GfxGLTextureImpl::setMinFilter(GfxTexture::Filter minFilter_)
{
    minFilter = minFilter_;

    setMinFiltering();
}

void GfxGLTextureImpl::setMagFilter(GfxTexture::Filter magFilter)
{
    BEGIN_TEXTURE_BINDING

    switch (magFilter)
    {
    case GfxTexture::Bilinear:
    {
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    }
    case GfxTexture::Nearest:
    {
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;
    }
    }

    END_TEXTURE_BINDING
}

void GfxGLTextureImpl::setMipmapMode(GfxTexture::MipmapMode mode)
{
    if (mode == mipmapMode)
    {
        return;
    }

    mipmapMode = mode;

    setMinFiltering();
}

void GfxGLTextureImpl::setWrapMode(GfxTexture::WrapMode mode)
{
    BEGIN_TEXTURE_BINDING

    switch (mode)
    {
    case GfxTexture::Stretch:
    {
        glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        break;
    }
    case GfxTexture::Repeat:
    {
        glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
        break;
    }
    case GfxTexture::Mirror:
    {
        glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        break;
    }
    }

    END_TEXTURE_BINDING
}

void GfxGLTextureImpl::setMinFiltering()
{
    BEGIN_TEXTURE_BINDING

    switch (mipmapMode)
    {
    case GfxTexture::None:
    {
        switch (minFilter)
        {
        case GfxTexture::Bilinear:
        {
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            break;
        }
        case GfxTexture::Nearest:
        {
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            break;
        }
        }
        break;
    }
    case GfxTexture::NearestMipmap:
    {
        switch (minFilter)
        {
        case GfxTexture::Bilinear:
        {
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            break;
        }
        case GfxTexture::Nearest:
        {
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
            break;
        }
        }
        break;
    }
    case GfxTexture::LinearMipmap:
    {
        switch (minFilter)
        {
        case GfxTexture::Bilinear:
        {
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            break;
        }
        case GfxTexture::Nearest:
        {
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            break;
        }
        }
        break;
    }
    }

    END_TEXTURE_BINDING
}
