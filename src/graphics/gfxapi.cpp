#include "graphics/gfxapi.h"

#include "graphics/gfxshader.h"

GfxApi::~GfxApi() {}

void GfxApi::begin(GfxShaderCombination *shaders)
{
    begin(shaders->getCompiled(GfxShaderType::Vertex),
          shaders->getCompiled(GfxShaderType::TessControl),
          shaders->getCompiled(GfxShaderType::TessEval),
          shaders->getCompiled(GfxShaderType::Geometry),
          shaders->getCompiled(GfxShaderType::Fragment));
}
