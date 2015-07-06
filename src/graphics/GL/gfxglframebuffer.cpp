#include "graphics/GL/gfxglframebuffer.h"

#include "graphics/GL/gfxgltextureimpl.h"

#define BEGIN_FRAMEBUFER_BINDING GLint lastFBO;\
glGetIntegerv(GL_FRAMEBUFFER_BINDING, &lastFBO);\
glBindFramebuffer(GL_FRAMEBUFFER, fbo);

#define END_FRAMEBUFFER_BINDING glBindFramebuffer(GL_FRAMEBUFFER, lastFBO);

GfxGLFramebuffer::GfxGLFramebuffer() : hasDepth(false)
{
    glGenFramebuffers(1, &fbo);
}

GfxGLFramebuffer::~GfxGLFramebuffer()
{
    glDeleteFramebuffers(1, &fbo);
}

void GfxGLFramebuffer::addColorAttachment(size_t rtIndex,
                                          ResPtr<GfxTexture> texture,
                                          size_t mipmapLevel,
                                          int layer)
{
    Attachment attachment;

    attachment.mipmapLevel = mipmapLevel;
    attachment.rtIndex = rtIndex;
    attachment.texture = texture;
    attachment.layer = layer;

    attachments.append(attachment);
}

void GfxGLFramebuffer::removeColorAttachment(size_t index)
{
    const Attachment& attachment = attachments[index];

    BEGIN_FRAMEBUFER_BINDING

    glFramebufferTexture(GL_FRAMEBUFFER,
                         GL_COLOR_ATTACHMENT0+attachment.rtIndex,
                         0,
                         0);

    END_FRAMEBUFFER_BINDING

    attachments.remove(index);
}

size_t GfxGLFramebuffer::getNumColorAttachments()
{
    return attachments.getCount();
}

size_t GfxGLFramebuffer::getColorRT(size_t index)
{
    return attachments[index].rtIndex;
}

ResPtr<GfxTexture> GfxGLFramebuffer::getColorAttachment(size_t index)
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

void GfxGLFramebuffer::setDepthAttachment(ResPtr<GfxTexture> texture,
                                          size_t mipmapLevel,
                                          int layer)
{
    hasDepth = true;
    depthAttachment.mipmapLevel = mipmapLevel;
    depthAttachment.texture = texture;
    depthAttachment.layer = layer;
}

void GfxGLFramebuffer::removeDepthAttachment()
{
    BEGIN_FRAMEBUFER_BINDING

    glFramebufferTexture(GL_FRAMEBUFFER,
                         GL_DEPTH_ATTACHMENT,
                         0,
                         0);

    END_FRAMEBUFFER_BINDING

    hasDepth = false;
    depthAttachment.texture = nullptr;
}

bool GfxGLFramebuffer::hasDepthAttachment()
{
    return hasDepth;
}

ResPtr<GfxTexture> GfxGLFramebuffer::getDepthTexture()
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
