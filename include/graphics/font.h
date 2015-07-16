#ifndef FONT_H
#define FONT_H

#include "containers/hashmap.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "math/t2.h"
#include "resource/resource.h"
#include "error.h"

#include <ft2build.h>
#include FT_FREETYPE_H

class GfxFramebuffer;

class FontException : public Exception
{
    public:
        FontException(const char *file_,
                      size_t line_,
                      const char *function_,
                      String filename_,
                      String problem_) : Exception(file_, line_, function_),
                                         filename(filename_),
                                         problem(problem_) {}

        virtual const char *getString() const
        {
            static char string[FILENAME_MAX+256];
            std::memset(string, 0, sizeof(string));

            std::snprintf(string,
                          sizeof(string),
                          "Unable to do something with a font at %s: %s",
                          filename.getData(),
                          problem.getData());

            return string;
        }

        inline const String& getFilename() const
        {
            return filename;
        }

        inline const String& getProblem() const
        {
            return problem;
        }
    private:
        String filename;
        String problem;
};

class Font : public Resource
{
    public:
        static const Resource::Type resource_type = FontType;

        Font();
        Font(const String& filename);
        ~Font();

        virtual void removeContent();

        void render(size_t size,
                    const Float2& position,
                    const char *string,
                    GfxFramebuffer *framebuffer,
                    const Float3& color);
    private:
        struct Glyph
        {
            UInt2 size;
            UInt2 bearing;
            float xAdvance;
            GfxTexture *texture;

            inline bool operator == (const Glyph& other) const
            {
                return size == other.size and
                       bearing == other.bearing and
                       xAdvance == other.xAdvance and
                       texture == other.texture;
            }
        };

        struct Face
        {
            FT_Face face;
            HashMap<char, Glyph> glyphs;

            inline bool operator == (const Face& other) const
            {
                return face == other.face and
                       glyphs == other.glyphs;
            }
        };

        void loadGlyph(Face& face, char character);

        HashMap<size_t, Face> faces;

        GfxMesh *quadMesh;
        GfxShader *quadVertex;
        GfxShader *quadGeometry;
        GfxShader *quadFragment;
        GfxCompiledShader *compiledQuadVertex;
        GfxCompiledShader *compiledQuadGeometry;
        GfxCompiledShader *compiledQuadFragment;
    protected:
        Resource *_copy() const;
};

#endif // FONT_H
