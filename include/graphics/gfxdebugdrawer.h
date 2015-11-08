#ifndef GFXDEBUGDRAWER_H
#define GFXDEBUGDRAWER_H

#include "containers/list.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/aabb.h"
#include "scripting/bindings.h"

class GfxBuffer;
class Camera;

class GfxDebugDrawer
{
    public:
        GfxDebugDrawer() NO_BIND;
        ~GfxDebugDrawer();

        void addLine(const Position3D& startPos,
                     const Position3D& endPos,
                     const Float4& startColor,
                     const Float4& endColor)
        {
            lines.append((Line){startColor, startPos, endColor, endPos});
        }

        void addBox(const AABB& aabb, const Float4& color);

        void render(const Camera& camera);
    private:
        struct Line
        {
            Float4 startColor;
            Position3D startPos;
            Float4 endColor;
            Position3D endPos;
        };

        List<Line> lines;

        GfxMesh *mesh;

        GfxShader *vertex;
        GfxCompiledShader *compiledVertex;

        GfxShader *fragment;
        GfxCompiledShader *compiledFragment;

    NO_COPY(GfxDebugDrawer)
} BIND NOT_COPYABLE;

#endif // GFXDEBUGDRAWER_H
