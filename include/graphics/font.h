#ifndef FONT_H
#define FONT_H

#include "containers/hashmap.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "math/t2.h"
#include "math/t3.h"
#include "resource/resource.h"
#include "error.h"
#include "scripting/bindings.h"

#include <ft2build.h>
#include FT_FREETYPE_H

class GfxFramebuffer;

class FontException : public Exception
{
    public:
        FontException(const char *file_,
                      size_t line_,
                      const char *function_,
                      Str filename_,
                      Str problem_) : Exception(file_, line_, function_),
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

        const Str& getFilename() const
        {
            return filename;
        }

        const Str& getProblem() const
        {
            return problem;
        }
    private:
        Str filename;
        Str problem;
};

class Font : public Resource
{
    NO_COPY_INHERITED(Font, Resource);

    public:
        static const ResType resource_type = ResType::FontType;

        Font();
        Font(const Str& filename);
        virtual ~Font();

        virtual void removeContent();

        size_t predictWidth(size_t size, const char *string) const;

        void render(size_t size,
                    const Float2& position,
                    const char *string,
                    GfxFramebuffer *framebuffer,
                    const Float3& color) const;

        void render(size_t size,
                    const Float2& position,
                    const char *string,
                    const Float3& color) const
        {
            render(size, position, string, nullptr, color);
        }
    private:
        struct Glyph
        {
            UInt2 size;
            Int2 bearing;
            float xAdvance;
            GfxTexture *texture;
        };

        struct Face
        {
            FT_Face face;
            HashMap<char, Glyph> glyphs;
        };

        Face *getFace(size_t size) const;

        void loadGlyph(Face& face, char character) const;

        mutable HashMap<size_t, Face> faces;

        GfxMesh *quadMesh;
        GfxShaderCombination *shaders;
    protected:
        Resource *_copy() const;
} DESTROY(obj->release()) BIND;

#endif // FONT_H
