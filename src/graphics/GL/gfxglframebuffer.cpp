#include "graphics/GL/gfxglframebuffer.h"

#include "graphics/GL/gfxgltextureimpl.h"

#define BEGIN_FRAMEBUFER_BINDING GLint lastFBO;\
glGetIntegerv(GL_FRAMEBUFFER_BINDING, &lastFBO);\
glBindFramebuffer(GL_FRAMEBUFFER, fbo);

#define END_FRAMEBUFFER_BINDING glBindFramebuffer(GL_FRAMEBUFFER, lastFBO);

GfxGLFramebuffer::GfxGLFramebuffer() : hasDepth(false), dirty(true)
{
    glGenFramebuffers(1, &fbo);
}

GfxGLFramebuffer::~GfxGLFramebuffer()
{
    glDeleteFramebuffers(1, &fbo);
}

void GfxGLFramebuffer::addColorAttachment(size_t rtIndex,
                                          GfxTexture *texture,
                                          size_t mipmapLevel,
                                          int layer)
{
    Attachment attachment;

    attachment.mipmapLevel = mipmapLevel;
    attachment.rtIndex = rtIndex;
    attachment.texture = texture->copyRef<GfxTexture>();
    attachment.layer = layer;

    attachments.append(attachment);

    ((GfxGLTextureImpl *)texture->getImpl())->framebuffers.append(this);
}

void GfxGLFramebuffer::removeColorAttachment(size_t index)
{
    attachments[index].texture->release();
    attachments.remove(index);
    dirty = true;
}

size_t GfxGLFramebuffer::getNumColorAttachments()
{
    return attachments.getCount();
}

size_t GfxGLFramebuffer::getColorRT(size_t index)
{
    return attachments[index].rtIndex;
}

GfxTexture *GfxGLFramebuffer::getColorAttachment(size_t index)
{
    return attachments[index].texture;
}

size_t GfxGLFramebuffer::getColorAttachmentMipmapLevel(size_t index)
{
    return attachments[index].mipmapLevel;
}

int GfxGLFramebuffer::getColorAttachmentLayer(size_t index)
{
    return attachments[index].layer;
}

void GfxGLFramebuffer::setDepthAttachment(GfxTexture *texture,
                                          size_t mipmapLevel,
                                          int layer)
{
    hasDepth = true;
    depthAttachment.mipmapLevel = mipmapLevel;
    depthAttachment.texture = texture->copyRef<GfxTexture>();
    depthAttachment.layer = layer;

    ((GfxGLTextureImpl *)texture->getImpl())->framebuffers.append(this);
}

void GfxGLFramebuffer::removeDepthAttachment()
{
    hasDepth = false;
    depthAttachment.texture->release();
    depthAttachment.texture = nullptr;
    dirty = true;
}

bool GfxGLFramebuffer::hasDepthAttachment()
{
    return hasDepth;
}

GfxTexture *GfxGLFramebuffer::getDepthTexture()
{
    return depthAttachment.texture;
}

size_t GfxGLFramebuffer::getDepthTextureMipmapLevel()
{
    return depthAttachment.mipmapLevel;
}

int GfxGLFramebuffer::getDepthAttachmentLayer()
{
    return depthAttachment.layer;
}

void GfxGLFramebuffer::bind()
{
    if (dirty)
    {
        glDeleteFramebuffers(1, &fbo);
        glGenFramebuffers(1, &fbo);

        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        for (auto attachment : attachments)
        {
            GfxTexture *texture = attachment.texture;

            if (attachment.layer >= 0)
            {
                glFramebufferTextureLayer(GL_FRAMEBUFFER,
                                          GL_COLOR_ATTACHMENT0+attachment.rtIndex,
                                          ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                          attachment.mipmapLevel,
                                          attachment.layer);

            } else
            {
                glFramebufferTexture(GL_FRAMEBUFFER,
                                     GL_COLOR_ATTACHMENT0+attachment.rtIndex,
                                     ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                     attachment.mipmapLevel);
            }
        }

        if (hasDepth)
        {
            GfxTexture *texture = depthAttachment.texture;

            if (getDepthAttachmentLayer() >= 0)
            {
                glFramebufferTextureLayer(GL_FRAMEBUFFER,
                                          GL_DEPTH_ATTACHMENT,
                                          ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                          depthAttachment.mipmapLevel,
                                          depthAttachment.layer);
            } else
            {
                glFramebufferTexture(GL_FRAMEBUFFER,
                                     GL_DEPTH_ATTACHMENT,
                                     ((GfxGLTextureImpl *)texture->getImpl())->getGLTexture(),
                                     depthAttachment.mipmapLevel);
            }
        }

        dirty = false;
    } else
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    }
}
