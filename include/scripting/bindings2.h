//Generated from script_binding_generator2.py. Do not edit. Edit script_binding_generator2.py instead.
#ifndef BINDINGS2_H
#define BINDINGS2_H

#include "platform.h"
#include "filesystem.h"
#include "misc_macros.h"
#include "error.h"
#include "globals.h"
#include "memory.h"
#include "imgui.h"
#include "application.h"
#include "endian_utils.h"
#include "logging.h"
#include "backtrace.h"
#include "file.h"
#include "graphics/gfxdefs.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/light.h"
#include "graphics/gfxterrain.h"
#include "graphics/gputimer.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gfxframebuffer.h"
#include "graphics/gfxapi.h"
#include "graphics/font.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxrenderer.h"
#include "graphics/gfxshader.h"
#include "graphics/camera.h"
#include "graphics/gfxmodel.h"
#include "graphics/GL/gfxglframebuffer.h"
#include "graphics/GL/glfl.h"
#include "graphics/GL/glgputimer.h"
#include "graphics/GL/gfxglbuffer.h"
#include "graphics/GL/gfxglapi.h"
#include "graphics/GL/gfxgltextureimpl.h"
#include "audio/audioworld.h"
#include "audio/audio.h"
#include "audio/audiodevice.h"
#include "resource/resourcemanager.h"
#include "resource/resource.h"
#include "physics/ghostobject.h"
#include "physics/physicsshape.h"
#include "physics/rigidbody.h"
#include "physics/physicsworld.h"
#include "physics/physicsdebugdrawer.h"
#include "math/quaternion.h"
#include "math/aabb.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix4x4.h"
#include "math/matrix3x3.h"
#include "scene/entity.h"
#include "scene/scene.h"
#include "scene/transform.h"
#include "containers/resizabledata.h"
#include "containers/hashmap.h"
#include "containers/list.h"
#include "containers/string.h"
#include "scripting/script_old.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"
#include "scripting/bindings.h"
#include "scripting/disasm.h"
#include "scripting/script.h"
#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include "scripting/parser/ast.h"
#include "scripting/parser/tokenizer.h"

namespace scripting
{
    Value *create(Context *ctx, const HashMap<String,String>& value);
    Value *create(Context *ctx, const GfxCompiledShader& value);
    Value *create(Context *ctx, const ScrollBar& value);
    Value *create(Context *ctx, const List<GhostObject*>& value);
    Value *create(Context *ctx, const T2<uint32_t>& value);
    Value *create(Context *ctx, const List<Light*>& value);
    Value *create(Context *ctx, const RenderStats& value);
    Value *create(Context *ctx, const Filesystem& value);
    Value *create(Context *ctx, const GfxRenderer& value);
    Value *create(Context *ctx, const T2<float>& value);
    Value *create(Context *ctx, const Event& value);
    Value *create(Context *ctx, const Stats& value);
    Value *create(Context *ctx, const AudioSource& value);
    Value *create(Context *ctx, const List<RayCastResult>& value);
    Value *create(Context *ctx, const Camera& value);
    Value *create(Context *ctx, const TextureSampler& value);
    Value *create(Context *ctx, const T3<int32_t>& value);
    Value *create(Context *ctx, const ResizableData& value);
    Value *create(Context *ctx, const T4<int32_t>& value);
    Value *create(Context *ctx, const T3<float>& value);
    Value *create(Context *ctx, const Transform& value);
    Value *create(Context *ctx, const List<AudioSource*>& value);
    Value *create(Context *ctx, const Quaternion& value);
    Value *create(Context *ctx, const GfxMeshAttrib& value);
    Value *create(Context *ctx, const T2<int32_t>& value);
    Value *create(Context *ctx, const AudioWorld& value);
    Value *create(Context *ctx, const GuiPlacer& value);
    Value *create(Context *ctx, const ImGui& value);
    Value *create(Context *ctx, const List<String>& value);
    Value *create(Context *ctx, const LightPointData& value);
    Value *create(Context *ctx, const T4<float>& value);
    Value *create(Context *ctx, const List<float>& value);
    Value *create(Context *ctx, const Container& value);
    Value *create(Context *ctx, const LightDirectionalData& value);
    Value *create(Context *ctx, const Matrix4x4& value);
    Value *create(Context *ctx, const HashMap<scripting::Value*,scripting::Value*>& value);
    Value *create(Context *ctx, const List<ScriptInstance*>& value);
    Value *create(Context *ctx, const T3<uint32_t>& value);
    Value *create(Context *ctx, const LightSpotData& value);
    Value *create(Context *ctx, const AudioDevice& value);
    Value *create(Context *ctx, const List<RigidBody*>& value);
    Value *create(Context *ctx, const T4<uint32_t>& value);
    Value *create(Context *ctx, const RayCastResult& value);
    Value *create(Context *ctx, const GfxLOD& value);
    Value *create(Context *ctx, const AABB& value);
    Value *create(Context *ctx, const RigidBodyConstructionInfo& value);
    Value *create(Context *ctx, const List<scripting::Value*>& value);
    Value *create(Context *ctx, const List<GfxModel::SubModel>& value);
    Value *create(Context *ctx, const List<GfxLOD>& value);
    Value *create(Context *ctx, const List<Entity*>& value);
    Value *create(Context *ctx, const Matrix3x3& value);
    Value *create(Context *ctx, GhostObject *value);
    Value *create(Context *ctx, HashMap<String,String> *value);
    Value *create(Context *ctx, GfxApi *value);
    Value *create(Context *ctx, GfxCompiledShader *value);
    Value *create(Context *ctx, ScrollBar *value);
    Value *create(Context *ctx, List<GhostObject*> *value);
    Value *create(Context *ctx, GPUTimer *value);
    Value *create(Context *ctx, RigidBody *value);
    Value *create(Context *ctx, T2<uint32_t> *value);
    Value *create(Context *ctx, List<Light*> *value);
    Value *create(Context *ctx, RenderStats *value);
    Value *create(Context *ctx, Filesystem *value);
    Value *create(Context *ctx, ResourceManager *value);
    Value *create(Context *ctx, Entity *value);
    Value *create(Context *ctx, GfxRenderer *value);
    Value *create(Context *ctx, T2<float> *value);
    Value *create(Context *ctx, GfxFramebuffer *value);
    Value *create(Context *ctx, Font *value);
    Value *create(Context *ctx, Event *value);
    Value *create(Context *ctx, PhysicsWorld *value);
    Value *create(Context *ctx, Stats *value);
    Value *create(Context *ctx, AudioSource *value);
    Value *create(Context *ctx, Script *value);
    Value *create(Context *ctx, List<RayCastResult> *value);
    Value *create(Context *ctx, Platform *value);
    Value *create(Context *ctx, Camera *value);
    Value *create(Context *ctx, GfxMesh *value);
    Value *create(Context *ctx, Resource *value);
    Value *create(Context *ctx, GfxShader *value);
    Value *create(Context *ctx, Light *value);
    Value *create(Context *ctx, TextureSampler *value);
    Value *create(Context *ctx, Scene *value);
    Value *create(Context *ctx, T3<int32_t> *value);
    Value *create(Context *ctx, ResizableData *value);
    Value *create(Context *ctx, T4<int32_t> *value);
    Value *create(Context *ctx, T3<float> *value);
    Value *create(Context *ctx, GfxBuffer *value);
    Value *create(Context *ctx, Transform *value);
    Value *create(Context *ctx, List<AudioSource*> *value);
    Value *create(Context *ctx, GfxMaterial *value);
    Value *create(Context *ctx, Quaternion *value);
    Value *create(Context *ctx, GfxMeshAttrib *value);
    Value *create(Context *ctx, ScriptInstance *value);
    Value *create(Context *ctx, RenderComponent *value);
    Value *create(Context *ctx, T2<int32_t> *value);
    Value *create(Context *ctx, AudioWorld *value);
    Value *create(Context *ctx, GuiPlacer *value);
    Value *create(Context *ctx, ImGui *value);
    Value *create(Context *ctx, List<String> *value);
    Value *create(Context *ctx, Application *value);
    Value *create(Context *ctx, LightPointData *value);
    Value *create(Context *ctx, T4<float> *value);
    Value *create(Context *ctx, List<float> *value);
    Value *create(Context *ctx, Container *value);
    Value *create(Context *ctx, LightDirectionalData *value);
    Value *create(Context *ctx, Matrix4x4 *value);
    Value *create(Context *ctx, HashMap<scripting::Value*,scripting::Value*> *value);
    Value *create(Context *ctx, List<ScriptInstance*> *value);
    Value *create(Context *ctx, T3<uint32_t> *value);
    Value *create(Context *ctx, LightSpotData *value);
    Value *create(Context *ctx, PhysicsShape *value);
    Value *create(Context *ctx, AudioDevice *value);
    Value *create(Context *ctx, List<RigidBody*> *value);
    Value *create(Context *ctx, T4<uint32_t> *value);
    Value *create(Context *ctx, RayCastResult *value);
    Value *create(Context *ctx, GfxLOD *value);
    Value *create(Context *ctx, File *value);
    Value *create(Context *ctx, AABB *value);
    Value *create(Context *ctx, RigidBodyConstructionInfo *value);
    Value *create(Context *ctx, List<scripting::Value*> *value);
    Value *create(Context *ctx, Audio *value);
    Value *create(Context *ctx, GfxTexture *value);
    Value *create(Context *ctx, List<GfxModel::SubModel> *value);
    Value *create(Context *ctx, GfxModel *value);
    Value *create(Context *ctx, List<GfxLOD> *value);
    Value *create(Context *ctx, List<Entity*> *value);
    Value *create(Context *ctx, GfxShaderCombination *value);
    Value *create(Context *ctx, Matrix3x3 *value);
    Value *create(Context *ctx, GfxDebugDrawer *value);
    Value *create(Context *ctx, Key value);
    Value *create(Context *ctx, MouseButton value);
    Value *create(Context *ctx, EventType value);
    Value *create(Context *ctx, FileOrigin value);
    Value *create(Context *ctx, ResType value);
    Value *create(Context *ctx, GfxTextureType value);
    Value *create(Context *ctx, GfxFilter value);
    Value *create(Context *ctx, GfxMipmapMode value);
    Value *create(Context *ctx, GfxWrapMode value);
    Value *create(Context *ctx, GfxTexFormat value);
    Value *create(Context *ctx, GfxTexPurpose value);
    Value *create(Context *ctx, GfxFace value);
    Value *create(Context *ctx, GfxBufferUsage value);
    Value *create(Context *ctx, GfxShaderType value);
    Value *create(Context *ctx, GfxPrimitive value);
    Value *create(Context *ctx, GfxDepthFunction value);
    Value *create(Context *ctx, GfxBlendMode value);
    Value *create(Context *ctx, GfxBlendFactor value);
    Value *create(Context *ctx, GfxCullMode value);
    Value *create(Context *ctx, GfxWinding value);
    Value *create(Context *ctx, GfxVertexAttribPurpose value);
    Value *create(Context *ctx, GfxVertexAttribType value);
    Value *create(Context *ctx, GfxMeshIndexDataType value);
    Value *create(Context *ctx, GfxMeshAttribType value);
    Value *create(Context *ctx, GfxMeshAttribDataType value);
    Value *create(Context *ctx, XOrigin value);
    Value *create(Context *ctx, GfxShadowmapPrecision value);
    Value *create(Context *ctx, GfxLightType value);
    Value *create(Context *ctx, GfxDriver value);
    Value *create(Context *ctx, CameraType value);
    Value *create(Context *ctx, Axis value);
    Value *create(Context *ctx, RigidBodyType value);
    Value *create(Context *ctx, PhysicsObjectType value);
    Value *create(Context *ctx, RenderMode value);
};

#endif // BINDINGS2_H
