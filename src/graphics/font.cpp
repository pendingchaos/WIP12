#include "graphics/font.h"

#include "graphics/gfxapi.h"
#include "globals.h"

#include <cstring>

Font::Font(const char *filename_) : filename(filename_)
{
    quadMesh = NEW(GfxMesh, "");
    quadMesh->primitive = GfxPoints;
    quadMesh->numVertices = 1;

    quadVertex = resMgr->getResourceByFilename<GfxShader>("resources/shaders/fontVertex.bin");
    quadGeometry = resMgr->getResourceByFilename<GfxShader>("resources/shaders/fontGeometry.bin");
    quadFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/fontFragment.bin");

    compiledQuadVertex = quadVertex->getCompiled();
    compiledQuadGeometry = quadGeometry->getCompiled();
    compiledQuadFragment = quadFragment->getCompiled();
}

Font::~Font()
{
    for (size_t i = 0; i < faces.getEntryCount(); ++i)
    {
        FT_Done_Face(faces.getValue(i).face);
    }
}

void Font::render(size_t size,
                  const Float2& position,
                  const char *string,
                  GfxFramebuffer *framebuffer,
                  const Float3& color)
{
    Float2 onePixel = Float2(1.0f) / Float2(gfxApi->getViewportWidth(), gfxApi->getViewportHeight());

    int faceIndex = faces.findEntry(size);
    Face *face;

    if (faceIndex == -1)
    {
        Face newFace;

        if (FT_New_Face(freeType, filename.getData(), 0, &newFace.face) != 0)
        {
            THROW(FontException, filename, "Unable to load font.")
        }

        FT_Set_Pixel_Sizes(newFace.face, 0, size);

        faces.set(size, newFace);

        face = &faces.get(size);
    } else
    {
        face = &faces.getValue(faceIndex);
    }

    size_t length = std::strlen(string);

    float x = position.x;
    float y = position.y;

    gfxApi->pushState();
    gfxApi->setCurrentFramebuffer(framebuffer);
    gfxApi->setBlendingEnabled(true);
    gfxApi->setDepthFunction(GfxAlways);
    gfxApi->setWriteDepth(false);
    gfxApi->setBlendFactors(GfxSrcAlpha,
                            GfxSrcAlpha,
                            GfxOneMinusSrcAlpha,
                            GfxOneMinusSrcAlpha);
    gfxApi->setBlendMode(GfxAdd, GfxAdd);

    for (size_t i = 0; i < length; ++i)
    {
        if (string[i] == '\n')
        {
            y -= size * onePixel.y;
            x = position.x;

            continue;
        }

        int glyphIndex = face->glyphs.findEntry(string[i]);
        Glyph *glyph;

        if (glyphIndex == -1)
        {
            loadGlyph(*face, string[i]);

            glyph = &face->glyphs.get(string[i]);
        } else
        {
            glyph = &face->glyphs.getValue(glyphIndex);
        }

        gfxApi->begin(compiledQuadVertex,
                      nullptr,
                      nullptr,
                      compiledQuadGeometry,
                      compiledQuadFragment,
                      quadMesh);

        Float2 newPosition(x + glyph->bearing.x * onePixel.x,
                           y - (glyph->size.y - glyph->bearing.y) * onePixel.y);

        gfxApi->uniform(compiledQuadGeometry, "glyphSize", Float2(glyph->size) * onePixel);
        gfxApi->uniform(compiledQuadGeometry, "glyphPosition", newPosition);
        gfxApi->uniform(compiledQuadFragment, "color", color);
        gfxApi->addTextureBinding(compiledQuadFragment, "glyphTexture", glyph->texture);

        gfxApi->end(quadMesh->primitive,
                    quadMesh->numVertices,
                    quadMesh->winding);

        x += glyph->xAdvance * onePixel.x;
    }

    gfxApi->popState();
}

void Font::loadGlyph(Face& face, char character)
{
    FT_Load_Char(face.face, character, FT_LOAD_RENDER);

    Glyph glyph;

    glyph.size.x = face.face->glyph->bitmap.width;
    glyph.size.y = face.face->glyph->bitmap.rows;
    glyph.bearing.x = face.face->glyph->bitmap_left;
    glyph.bearing.y = face.face->glyph->bitmap_top;
    glyph.xAdvance = face.face->glyph->advance.x / 64.0f;

    glyph.texture = NEW(GfxTexture, "");

    glyph.texture->startCreation(GfxTexture::Texture2D,
                                 false,
                                 glyph.size.x,
                                 glyph.size.y,
                                 255,
                                 GfxTexture::Color,
                                 GfxTexture::LuminanceU8);

    glyph.texture->allocMipmap(0, 1, face.face->glyph->bitmap.buffer);
    glyph.texture->setWrapMode(GfxTexture::Stretch);

    face.glyphs.set(character, glyph);
}
