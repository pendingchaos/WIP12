#ifndef GFXDEBUGDRAWER_H
#define GFXDEBUGDRAWER_H

#include "containers/list.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "math/t3.h"
#include "math/t4.h"

class GfxApi;
class GfxBuffer;
class Camera;

class GfxDebugDrawer
{
    public:
        GfxDebugDrawer(GfxApi *gfxApi);
        ~GfxDebugDrawer();

        inline void addLine(const Position3D& startPos,
                            const Position3D& endPos,
                            const Float4& startColor,
                            const Float4& endColor)
        {
            lines.append((Line){startColor, startPos, endColor, endPos});
        }

        void render(const Camera& camera);
    private:
        struct Line
        {
            Float4 startColor;
            Position3D startPos;
            Float4 endColor;
            Position3D endPos;

            inline bool operator == (const Line& other) const
            {
                return startColor == other.startColor and
                       startPos == other.startPos and
                       endColor == other.endColor and
                       endPos == other.endPos;
            }
        };

        List<Line> lines;

        ResPtr<GfxMesh> mesh;
        GfxBuffer *buffer;

        ResPtr<GfxShader> vertex;
        GfxCompiledShader *compiledVertex;

        ResPtr<GfxShader> fragment;
        GfxCompiledShader *compiledFragment;

    NO_COPY(GfxDebugDrawer)
};

#endif // GFXDEBUGDRAWER_H
