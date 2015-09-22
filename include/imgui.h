#ifndef IMGUI_H
#define IMGUI_H

class GfxMesh;
class GfxShader;
class GfxCompiledShader;
class Font;

class ImGui
{
    public:
        ImGui();
        ~ImGui();

        bool button(const char *text, float left, float right, float bottom, float top);
    private:
        GfxMesh *mesh;
        GfxShader *vertexShader;
        GfxShader *fragmentShader;
        GfxCompiledShader *compiledVertex;
        GfxCompiledShader *compiledFragment;
};

#endif // IMGUI_H
