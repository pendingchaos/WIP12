#include "graphics/gfxdebugdrawer.h"

#include "graphics/gfxbuffer.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "globals.h"

GfxDebugDrawer::GfxDebugDrawer(GfxApi *gfxApi) : mesh(nullptr)
{
    vertex = resMgr->load<GfxShader>(
    "resources/shaders/debugDraw.vs.bin");

    fragment = resMgr->load<GfxShader>(
    "resources/shaders/debugDraw.fs.bin");

    compiledVertex = vertex->getCompiled();
    compiledFragment = fragment->getCompiled();

    mesh = NEW(GfxMesh);
    mesh->primitive = GfxLines;
}

GfxDebugDrawer::~GfxDebugDrawer()
{
    mesh->release();

    fragment->release();
    vertex->release();
}

void GfxDebugDrawer::addBox(const AABB& aabb, const Float4& color)
{
    addLine(aabb.min, Position3D(aabb.min.x, aabb.min.y, aabb.max.z), color, color);
    addLine(aabb.min, Position3D(aabb.max.x, aabb.min.y, aabb.min.z), color, color);
    addLine(Position3D(aabb.min.x, aabb.min.y, aabb.max.z), Position3D(aabb.max.x, aabb.min.y, aabb.max.z), color, color);
    addLine(Position3D(aabb.max.x, aabb.min.y, aabb.min.z), Position3D(aabb.max.x, aabb.min.y, aabb.max.z), color, color);

    addLine(Position3D(aabb.min.x, aabb.max.y, aabb.min.z), Position3D(aabb.min.x, aabb.max.y, aabb.max.z), color, color);
    addLine(Position3D(aabb.min.x, aabb.max.y, aabb.min.z), Position3D(aabb.max.x, aabb.max.y, aabb.min.z), color, color);
    addLine(Position3D(aabb.min.x, aabb.max.y, aabb.max.z), Position3D(aabb.max.x, aabb.max.y, aabb.max.z), color, color);
    addLine(Position3D(aabb.max.x, aabb.max.y, aabb.min.z), Position3D(aabb.max.x, aabb.max.y, aabb.max.z), color, color);

    addLine(aabb.min, Position3D(aabb.min.x, aabb.max.y, aabb.min.z), color, color);
    addLine(Position3D(aabb.max.x, aabb.min.y, aabb.min.z), Position3D(aabb.max.x, aabb.max.y, aabb.min.z), color, color);
    addLine(Position3D(aabb.min.x, aabb.min.y, aabb.max.z), Position3D(aabb.min.x, aabb.max.y, aabb.max.z), color, color);
    addLine(Position3D(aabb.max.x, aabb.min.y, aabb.max.z), Position3D(aabb.max.x, aabb.max.y, aabb.max.z), color, color);
}

void GfxDebugDrawer::render(const Camera& camera)
{
    ResizableData positionData(lines.getCount()*2*12);
    ResizableData colorData(lines.getCount()*2*4);

    for (size_t i = 0; i < lines.getCount(); ++i)
    {
        const Line& line = lines[i];

        float *pos = (float *)positionData.getData() + i * 2 * 3;

        pos[0] = line.startPos.x;
        pos[1] = line.startPos.y;
        pos[2] = line.startPos.z;
        pos[3] = line.endPos.x;
        pos[4] = line.endPos.y;
        pos[5] = line.endPos.z;

        uint8_t *color = (uint8_t *)colorData.getData() + i * 2 * 4;

        color[0] = line.startColor.x * 255.0f;
        color[1] = line.startColor.y * 255.0f;
        color[2] = line.startColor.z * 255.0f;
        color[3] = line.startColor.w * 255.0f;
        color[4] = line.endColor.x * 255.0f;
        color[5] = line.endColor.y * 255.0f;
        color[6] = line.endColor.z * 255.0f;
        color[7] = line.endColor.w * 255.0f;
    }

    GfxMeshAttrib attrib;
    attrib.type = GfxMeshAttribType::Position;
    attrib.dataType = GfxMeshAttribDataType::F32_3;
    attrib.data = positionData;
    mesh->setAttribute(attrib);

    attrib.type = GfxMeshAttribType::Color;
    attrib.dataType = GfxMeshAttribDataType::U8_4Norm;
    attrib.data = colorData;
    mesh->setAttribute(attrib);

    mesh->numVertices = lines.getCount() * 2;

    gfxApi->begin(compiledVertex, nullptr, nullptr, nullptr, compiledFragment, mesh);

    gfxApi->uniform(compiledVertex, "projectionMatrix", camera.getProjectionMatrix());
    gfxApi->uniform(compiledVertex, "viewMatrix", camera.getViewMatrix());

    gfxApi->draw();
    gfxApi->end();

    lines.clear();
}
