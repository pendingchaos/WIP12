#include "graphics/font.h"

#include "graphics/gfxapi.h"
#include "globals.h"

#include <cstring>

Font::Font(const String& filename) : Resource(filename, FontType)
{
    quadMesh = NEW(GfxMesh);
    quadMesh->primitive = GfxPoints;
    quadMesh->numVertices = 1;

    quadVertex = resMgr->load<GfxShader>("resources/shaders/fontVertex.bin");
    quadGeometry = resMgr->load<GfxShader>("resources/shaders/fontGeometry.bin");
    quadFragment = resMgr->load<GfxShader>("resources/shaders/fontFragment.bin");

    compiledQuadVertex = quadVertex->getCompiled();
    compiledQuadGeometry = quadGeometry->getCompiled();
    compiledQuadFragment = quadFragment->getCompiled();
}

Font::Font() : Resource(FontType) {}

Font::~Font()
{
    quadFragment->release();
    quadGeometry->release();
    quadVertex->release();

    quadMesh->release();

    for (size_t i = 0; i < faces.getEntryCount(); ++i)
    {
        HashMap<char, Glyph> glyphs = faces.getValue(i).glyphs;

        for (size_t j = 0; j < glyphs.getEntryCount(); ++j)
        {
            glyphs.getValue(j).texture->release();
        }

        FT_Done_Face(faces.getValue(i).face);
    }
}

void Font::removeContent()
{
    for (size_t i = 0; i < faces.getEntryCount(); ++i)
    {
        HashMap<char, Glyph> glyphs = faces.getValue(i).glyphs;

        for (size_t j = 0; j < glyphs.getEntryCount(); ++j)
        {
            glyphs.getValue(j).texture->release();
        }

        FT_Done_Face(faces.getValue(i).face);
    }

    faces.clear();
}

void Font::render(size_t size,
                  const Float2& position,
                  const char *string,
                  GfxFramebuffer *framebuffer,
                  const Float3& color)
{
    if (getFilename().getLength() == 0)
    {
        return;
    }

    Float2 onePixel = Float2(1.0f) / Float2(gfxApi->getViewportWidth(), gfxApi->getViewportHeight());

    int faceIndex = faces.findEntry(size);
    Face *face;

    if (faceIndex == -1)
    {
        Face newFace;

        if (FT_New_Face(freeType, getFilename().getData(), 0, &newFace.face) != 0)
        {
            THROW(FontException, getFilename(), "Unable to load font.")
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

    struct Character
    {
        Position2D position;
        Glyph glyph;
    };

    HashMap<char, List<Character>> characters;

    for (size_t i = 0; i < length; ++i)
    {
        if (string[i] == '\n')
        {
            y -= size * onePixel.y;
            x = position.x;

            continue;
        }

        int glyphIndex = face->glyphs.findEntry(string[i]);
        Glyph glyph;

        if (glyphIndex == -1)
        {
            loadGlyph(*face, string[i]);

            glyph = face->glyphs.get(string[i]);
        } else
        {
            glyph = face->glyphs.getValue(glyphIndex);
        }

        Character character;
        character.position = Position2D(x + glyph.bearing.x * onePixel.x,
                                        y - (glyph.size.y - glyph.bearing.y) * onePixel.y);
        character.glyph = glyph;

        int index = characters.findEntry(string[i]);

        if (index == -1)
        {
            List<Character> chars;
            chars.append(character);

            characters.set(string[i], chars);
        } else
        {
            characters.getValue(index).append(character);
        }

        x += glyph.xAdvance * onePixel.x;
    }

    for (size_t i = 0; i < characters.getEntryCount(); ++i)
    {
        List<Position2D> positions;

        for (size_t j = 0; j < characters.getValue(i).getCount(); ++j)
        {
            positions.append(characters.getValue(i)[j].position);
        }

        Glyph& glyph = characters.getValue(i)[0].glyph;

        for (size_t j = 0; j < positions.getCount()/100; ++j)
        {
            gfxApi->begin(compiledQuadVertex,
                          nullptr,
                          nullptr,
                          compiledQuadGeometry,
                          compiledQuadFragment,
                          quadMesh);

            gfxApi->uniform(compiledQuadGeometry, "glyphSize", Float2(glyph.size) * onePixel);
            gfxApi->uniform(compiledQuadGeometry, "glyphPositions", 100, positions.getData()+j*100*sizeof(Position2D));
            gfxApi->uniform(compiledQuadFragment, "color", color);
            gfxApi->addTextureBinding(compiledQuadFragment, "glyphTexture", glyph.texture);

            gfxApi->end(quadMesh->primitive,
                        quadMesh->numVertices,
                        quadMesh->winding,
                        100);
        }

        if (positions.getCount() % 100 != 0)
        {
            size_t offset = positions.getCount()/100*100*sizeof(Position2D);

            gfxApi->begin(compiledQuadVertex,
                          nullptr,
                          nullptr,
                          compiledQuadGeometry,
                          compiledQuadFragment,
                          quadMesh);

            gfxApi->uniform(compiledQuadGeometry, "glyphSize", Float2(glyph.size) * onePixel);
            gfxApi->uniform(compiledQuadGeometry, "glyphPositions", positions.getCount() % 100, positions.getData()+offset);
            gfxApi->uniform(compiledQuadFragment, "color", color);
            gfxApi->addTextureBinding(compiledQuadFragment, "glyphTexture", glyph.texture);

            gfxApi->end(quadMesh->primitive,
                        quadMesh->numVertices,
                        quadMesh->winding,
                        positions.getCount() % 100);
        }
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

    glyph.texture = NEW(GfxTexture);

    glyph.texture->startCreation(GfxTexture::Texture2D,
                                 false,
                                 glyph.size.x,
                                 glyph.size.y,
                                 1,
                                 255,
                                 GfxTexture::Color,
                                 GfxTexture::LuminanceU8);

    glyph.texture->allocMipmap(0, 1, face.face->glyph->bitmap.buffer);
    glyph.texture->setWrapMode(GfxTexture::Stretch);

    face.glyphs.set(character, glyph);
}

Resource *Font::_copy() const
{
    return (Resource *)NEW(Font, getFilename());
}
