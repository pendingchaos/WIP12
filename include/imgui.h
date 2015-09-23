#ifndef IMGUI_H
#define IMGUI_H

#include <stddef.h>

class GfxMesh;
class GfxShader;
class GfxCompiledShader;
class Font;

class ImGui
{
    public:
        ImGui();
        ~ImGui();

        bool button(const char *text, int left, int right, int bottom, int top);
    private:
        GfxMesh *mesh;
        GfxShader *vertexShader;
        GfxShader *fragmentShader;
        GfxCompiledShader *compiledVertex;
        GfxCompiledShader *compiledFragment;

        Font *font;
};

#endif // IMGUI_H
