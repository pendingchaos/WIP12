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

    GfxMesh::VertexAttribute positionAttribute;
    positionAttribute.numComponents = 3;
    positionAttribute.type = GfxFloat;
    positionAttribute.stride = 28;
    positionAttribute.offset = 16;

    mesh->setVertexAttrib(GfxPosition, positionAttribute);

    GfxMesh::VertexAttribute colorAttribute;
    colorAttribute.numComponents = 4;
    colorAttribute.type = GfxFloat;
    colorAttribute.stride = 28;
    colorAttribute.offset = 0;

    mesh->setVertexAttrib(GfxColor, colorAttribute);
}

GfxDebugDrawer::~GfxDebugDrawer()
{
    mesh->release();

    fragment->release();
    vertex->release();
}

void GfxDebugDrawer::render(const Camera& camera)
{
    mesh->getBuffer()->allocData(lines.getCount()*sizeof(Line), lines.getData(), GfxBufferUsage::Static);

    mesh->numVertices = lines.getCount() * 2;

    gfxApi->begin(compiledVertex, nullptr, nullptr, nullptr, compiledFragment, mesh);

    gfxApi->uniform(compiledVertex, "projectionMatrix", camera.getProjectionMatrix());
    gfxApi->uniform(compiledVertex, "viewMatrix", camera.getViewMatrix());

    gfxApi->end(mesh->primitive, mesh->numVertices, mesh->winding);

    lines.clear();
}
