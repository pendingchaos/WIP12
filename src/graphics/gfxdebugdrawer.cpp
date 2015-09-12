#include "graphics/gfxdebugdrawer.h"

#include "graphics/gfxbuffer.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "globals.h"

GfxDebugDrawer::GfxDebugDrawer(GfxApi *gfxApi) : mesh(nullptr)
{
    vertex = resMgr->load<GfxShader>(
    "resources/shaders/debugDrawVertex.bin");

    fragment = resMgr->load<GfxShader>(
    "resources/shaders/debugDrawFragment.bin");

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

void GfxDebugDrawer::render(const Camera& camera)
{
    ResizableData positionData(lines.getCount()*2*12);
    ResizableData colorData(lines.getCount()*2*4);

    std::cout << lines.getCount() << std::endl;

    for (size_t i = 0; i < lines.getCount(); ++i)
    {
        float *pos = (float *)positionData.getData() + i * 2 * 3;

        pos[0] = lines[i].startPos.x;
        pos[1] = lines[i].startPos.y;
        pos[2] = lines[i].startPos.z;
        pos[3] = lines[i].endPos.x;
        pos[4] = lines[i].endPos.y;
        pos[5] = lines[i].endPos.z;

        uint8_t *color = (uint8_t *)colorData.getData() + i * 2 * 4;

        color[0] = lines[i].startColor.x * 255.0f;
        color[1] = lines[i].startColor.y * 255.0f;
        color[2] = lines[i].startColor.z * 255.0f;
        color[3] = lines[i].endColor.x * 255.0f;
        color[4] = lines[i].endColor.y * 255.0f;
        color[5] = lines[i].endColor.z * 255.0f;
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

    gfxApi->end();

    lines.clear();
}
