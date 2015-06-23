#include "file.h"
#include "error.h"
#include "memory.h"
#include "globals.h"
#include "logging.h"
#include "backtrace.h"
#include "filesystem.h"
#include "application.h"
#include "misc_macros.h"
#include "endian_utils.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "scene/transform.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmodel.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gfxdefs.h"
#include "graphics/gfxrenderer.h"
#include "graphics/camera.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/font.h"
#include "graphics/gputimer.h"
#include "scripting/script.h"
#include "resource/resource.h"
#include "resource/resourcemanager.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix3x3.h"
#include "math/matrix4x4.h"
#include "math/quaternion.h"
#include "math/aabb.h"
#include "containers/list.h"
#include "containers/pair.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "containers/resizabledata.h"
#include "physics/physicsworld.h"
#include "physics/rigidbody.h"
#include "physics/physicsshape.h"
#include "physics/physicsdebugdrawer.h"
#include "platform/platform.h"
struct _functionStruct
{
    const char ** (*f0)(unsigned int & arg0);
    size_t (*f1)(const String & arg0);
    bool (*f2)(const char * arg0);
    List<String> (*f3)(const char * arg0);
    void (*f4)(Application * arg0);
    ScriptInstance * (*f5)( Script *obj, Entity * arg0);
    void (*f6)( GfxMaterial *obj, bool arg0);
    void (*f7)(const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3);
    void (*f8)(ResPtr<GfxMesh> arg0);
    void (*f9)( GfxRenderer *obj, const UInt2 & arg0);
    void (*f10)( GfxRenderer *obj);
    AABB (*f11)(const GfxRenderer *obj);
    AABB (*f12)(const GfxRenderer *obj);
    void (*f13)( GfxRenderer *obj);
    void (*f14)( GfxRenderer *obj);
    Quaternion (*f15)(const Quaternion *obj, const Quaternion & arg0);
    Matrix4x4 (*f16)(const Quaternion *obj);
    Float4 (*f17)(const Quaternion *obj);
    void (*f18)( Quaternion *obj, const Direction3D & arg0);
    void (*f19)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f20)( Quaternion *obj, const Float3 & arg0);
    Float3 (*f21)( Quaternion *obj);
    void (*f22)( Quaternion *obj);
    void (*f23)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f24)( Quaternion *obj, float arg0, float arg1, float arg2, float arg3);
    void (*f25)( Quaternion *obj, const Float3 & arg0);
    LogEntry & (*f26)( LogEntry *obj, const char * arg0, uint8_t arg1);
    LogEntry & (*f27)( LogEntry *obj, const char * arg0, int8_t arg1);
    LogEntry & (*f28)( LogEntry *obj, const char * arg0, uint16_t arg1);
    LogEntry & (*f29)( LogEntry *obj, const char * arg0, int16_t arg1);
    LogEntry & (*f30)( LogEntry *obj, const char * arg0, uint32_t arg1);
    LogEntry & (*f31)( LogEntry *obj, const char * arg0, int32_t arg1);
    LogEntry & (*f32)( LogEntry *obj, const char * arg0, uint64_t arg1);
    LogEntry & (*f33)( LogEntry *obj, const char * arg0, int64_t arg1);
    LogEntry & (*f34)( LogEntry *obj, const char * arg0, bool arg1);
    LogEntry & (*f35)( LogEntry *obj, const char * arg0, float arg1);
    LogEntry & (*f36)( LogEntry *obj, const char * arg0, double arg1);
    LogEntry & (*f37)( LogEntry *obj, const char * arg0, long double arg1);
    LogEntry & (*f38)( LogEntry *obj, const char * arg0, const char * arg1);
    LogEntry & (*f39)( LogEntry *obj, const char * arg0, const String & arg1);
    LogEntry & (*f40)( LogEntry *obj);
    LogEntry & (*f41)( LogEntry *obj, unsigned int arg0, const char ** arg1);
    int (*f42)( LogEntry *obj);
    int (*f43)( LogEntry *obj);
    void (*f44)( Light *obj, size_t arg0, Light::ShadowmapPrecision arg1);
    void (*f45)( Light *obj, GfxRenderer * arg0);
    void (*f46)( PhysicsShape *obj);
    void (*f47)( PhysicsShape *obj, float arg0);
    void (*f48)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f49)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f50)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f51)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f52)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f53)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f54)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f55)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f56)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    void (*f57)( Resource *obj);
    bool (*f58)(const Resource *obj);
    void (*f59)( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7);
    void (*f60)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3);
    void (*f61)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f62)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3);
    void (*f63)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f64)( GfxTexture *obj);
    void (*f65)( GfxTexture *obj, float arg0);
    void (*f66)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f67)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f68)( GfxTexture *obj, GfxTexture::MipmapMode arg0);
    void (*f69)( GfxTexture *obj, GfxTexture::WrapMode arg0);
    void (*f70)( GfxTexture *obj, bool arg0);
    Transform (*f71)( GhostObject *obj);
    void (*f72)(const GhostObject *obj, const Transform & arg0);
    void (*f73)( GhostObject *obj);
    void (*f74)( GhostObject *obj, float arg0);
    void (*f75)( GhostObject *obj, const Vector3D & arg0);
    void (*f76)( GhostObject *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f77)( GhostObject *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f78)( GhostObject *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f79)( GhostObject *obj, size_t arg0, const Position3D * arg1);
    void (*f80)( GhostObject *obj, size_t arg0, const Position3D * arg1);
    void (*f81)( GhostObject *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f82)( GhostObject *obj, const Vector3D & arg0, float arg1);
    void (*f83)( GhostObject *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    void (*f84)( GhostObject *obj, ResPtr<PhysicsShape> arg0);
    void (*f85)(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1);
    void (*f86)( PhysicsShapeImpl *obj);
    void (*f87)( Application *obj);
    void (*f88)( Application *obj, const char * arg0);
    void (*f89)( Application *obj);
    void (*f90)( Scene *obj);
    void (*f91)( Scene *obj);
    void (*f92)( Scene *obj, float arg0);
    Entity * (*f93)( Scene *obj, const String & arg0);
    void (*f94)( Scene *obj, size_t arg0);
    void (*f95)( Entity *obj, PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1);
    void (*f96)( File *obj, size_t arg0, void * arg1);
    void (*f97)( File *obj, size_t arg0, const void * arg1);
    void (*f98)( File *obj, long arg0, File::Origin arg1);
    long (*f99)( File *obj);
    void (*f100)( File *obj);
    bool (*f101)( File *obj);
    size_t (*f102)( File *obj);
    uint8_t (*f103)( File *obj);
    int8_t (*f104)( File *obj);
    uint16_t (*f105)( File *obj);
    int16_t (*f106)( File *obj);
    uint32_t (*f107)( File *obj);
    int32_t (*f108)( File *obj);
    uint64_t (*f109)( File *obj);
    int64_t (*f110)( File *obj);
    uint16_t (*f111)( File *obj);
    int16_t (*f112)( File *obj);
    uint32_t (*f113)( File *obj);
    int32_t (*f114)( File *obj);
    uint64_t (*f115)( File *obj);
    int64_t (*f116)( File *obj);
    float (*f117)( File *obj);
    char (*f118)( File *obj);
    void (*f119)( File *obj, uint8_t arg0);
    void (*f120)( File *obj, int8_t arg0);
    void (*f121)( File *obj, uint16_t arg0);
    void (*f122)( File *obj, int16_t arg0);
    void (*f123)( File *obj, uint32_t arg0);
    void (*f124)( File *obj, int32_t arg0);
    void (*f125)( File *obj, uint64_t arg0);
    void (*f126)( File *obj, int64_t arg0);
    void (*f127)( File *obj, uint16_t arg0);
    void (*f128)( File *obj, int16_t arg0);
    void (*f129)( File *obj, uint32_t arg0);
    void (*f130)( File *obj, int32_t arg0);
    void (*f131)( File *obj, uint64_t arg0);
    void (*f132)( File *obj, int64_t arg0);
    void (*f133)( File *obj, float arg0);
    void (*f134)( File *obj, const char * arg0, va_list arg1);
    void (*f135)( File *obj, char arg0);
    void (*f136)( File *obj, const char * arg0, const char * arg1);
    void (*f137)( File *obj);
    Matrix3x3 (*f138)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f139)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f140)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f141)(const Matrix3x3 *obj);
    Matrix3x3 (*f142)(const Matrix3x3 *obj);
    Matrix3x3 (*f143)(const Float2 & arg0);
    Matrix3x3 (*f144)(const Float3 & arg0);
    Matrix3x3 (*f145)(float arg0);
    Matrix3x3 (*f146)(float arg0);
    Matrix3x3 (*f147)(float arg0);
    Matrix3x3 (*f148)(float arg0);
    void (*f149)( Matrix3x3 *obj);
    void (*f150)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f151)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    void (*f152)( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4);
    void (*f153)( Font *obj, const char * arg0);
    void (*f154)( Font *obj);
    void (*f155)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f156)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f157)( GfxDebugDrawer *obj);
    Script *(*f158)();
    Script *(*f159)(size_t count);
    Script *(*f160)(const String & arg0);
    GfxMaterial *(*f161)();
    GfxMaterial *(*f162)(size_t count);
    GfxMaterial *(*f163)(const String & arg0);
    LookupException *(*f164)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f165)();
    Quaternion *(*f166)(size_t count);
    Quaternion *(*f167)(const Direction3D & arg0, float arg1);
    Quaternion *(*f168)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f169)(const Float3 & arg0);
    Light *(*f170)();
    Light *(*f171)(size_t count);
    PhysicsShape *(*f172)();
    PhysicsShape *(*f173)(size_t count);
    PhysicsShape *(*f174)(const String & arg0);
    ShaderCompileException *(*f175)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f176)(const char * arg0, size_t arg1, const char * arg2);
    PhysicsDebugDrawer *(*f177)();
    PhysicsDebugDrawer *(*f178)(size_t count);
    FileException *(*f179)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    AABB *(*f180)();
    AABB *(*f181)(size_t count);
    AABB *(*f182)(const Position3D & arg0, const Position3D & arg1);
    ResourceIOException *(*f183)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxTexture *(*f184)(const String & arg0);
    GfxTexture *(*f185)();
    GfxTexture *(*f186)(size_t count);
    PhysicsShapeImpl *(*f187)();
    PhysicsShapeImpl *(*f188)(size_t count);
    UserData *(*f189)(const ScriptFunction<void *> & arg0, const ScriptFunction<void, void *> & arg1);
    Application *(*f190)(const char * arg0);
    GfxModel *(*f191)();
    GfxModel *(*f192)(size_t count);
    GfxModel *(*f193)(const String & arg0);
    Scene *(*f194)();
    Scene *(*f195)(size_t count);
    Scene *(*f196)(const String & arg0);
    File *(*f197)(const char * arg0, const char * arg1);
    GfxShaderCombination *(*f198)(ResPtr<GfxShader> arg0, ResPtr<GfxShader> arg1);
    Matrix3x3 *(*f199)();
    Matrix3x3 *(*f200)(size_t count);
    Matrix3x3 *(*f201)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f202)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    Font *(*f203)(const char * arg0);
    GfxDebugDrawer *(*f204)(GfxApi * arg0);
};
const char ** f0(unsigned int & arg0) {return getBacktrace(arg0);}
size_t f1(const String & arg0) {return getHash(arg0);}
bool f2(const char * arg0) {return doesFileExist(arg0);}
List<String> f3(const char * arg0) {return listFiles(arg0);}
void f4(Application * arg0) { setApplication(arg0);}
ScriptInstance * f5( Script *obj, Entity * arg0) {return obj->createInstance(arg0);}
void f6( GfxMaterial *obj, bool arg0) { obj->setForward(arg0);}
void f7(const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3) { GfxRenderer::beginRenderMesh(arg0, arg1, arg2, arg3);}
void f8(ResPtr<GfxMesh> arg0) { GfxRenderer::endRenderMesh(arg0);}
void f9( GfxRenderer *obj, const UInt2 & arg0) { obj->resize(arg0);}
void f10( GfxRenderer *obj) { obj->render();}
AABB f11(const GfxRenderer *obj) {return obj->computeSceneAABB();}
AABB f12(const GfxRenderer *obj) {return obj->computeShadowCasterAABB();}
void f13( GfxRenderer *obj) { obj->updateStats();}
void f14( GfxRenderer *obj) { obj->~GfxRenderer();}
Quaternion f15(const Quaternion *obj, const Quaternion & arg0) {return obj->operator*(arg0);}
Matrix4x4 f16(const Quaternion *obj) {return obj->toMatrix();}
Float4 f17(const Quaternion *obj) {return obj->getAxisAndAngle();}
void f18( Quaternion *obj, const Direction3D & arg0) { obj->setAxis(arg0);}
void f19( Quaternion *obj, const Direction3D & arg0, float arg1) { obj->setAxisAndAngle(arg0, arg1);}
void f20( Quaternion *obj, const Float3 & arg0) { obj->setEulerAngles(arg0);}
Float3 f21( Quaternion *obj) {return obj->getEulerAngles();}
void f22( Quaternion *obj) {new (obj) Quaternion();}
void f23( Quaternion *obj, const Direction3D & arg0, float arg1) {new (obj) Quaternion(arg0, arg1);}
void f24( Quaternion *obj, float arg0, float arg1, float arg2, float arg3) {new (obj) Quaternion(arg0, arg1, arg2, arg3);}
void f25( Quaternion *obj, const Float3 & arg0) {new (obj) Quaternion(arg0);}
LogEntry & f26( LogEntry *obj, const char * arg0, uint8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f27( LogEntry *obj, const char * arg0, int8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f28( LogEntry *obj, const char * arg0, uint16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f29( LogEntry *obj, const char * arg0, int16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f30( LogEntry *obj, const char * arg0, uint32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f31( LogEntry *obj, const char * arg0, int32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f32( LogEntry *obj, const char * arg0, uint64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f33( LogEntry *obj, const char * arg0, int64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f34( LogEntry *obj, const char * arg0, bool arg1) {return obj->variable(arg0, arg1);}
LogEntry & f35( LogEntry *obj, const char * arg0, float arg1) {return obj->variable(arg0, arg1);}
LogEntry & f36( LogEntry *obj, const char * arg0, double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f37( LogEntry *obj, const char * arg0, long double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f38( LogEntry *obj, const char * arg0, const char * arg1) {return obj->variable(arg0, arg1);}
LogEntry & f39( LogEntry *obj, const char * arg0, const String & arg1) {return obj->variable(arg0, arg1);}
LogEntry & f40( LogEntry *obj) {return obj->printBacktrace();}
LogEntry & f41( LogEntry *obj, unsigned int arg0, const char ** arg1) {return obj->printBacktrace(arg0, arg1);}
int f42( LogEntry *obj) {return obj->end();}
int f43( LogEntry *obj) {return obj->fatalEnd();}
void f44( Light *obj, size_t arg0, Light::ShadowmapPrecision arg1) { obj->addShadowmap(arg0, arg1);}
void f45( Light *obj, GfxRenderer * arg0) { obj->updateMatrices(arg0);}
void f46( PhysicsShape *obj) { obj->setEmpty();}
void f47( PhysicsShape *obj, float arg0) { obj->setSphere(arg0);}
void f48( PhysicsShape *obj, const Vector3D & arg0) { obj->setBox(arg0);}
void f49( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2) { obj->setCylinder(arg0, arg1, arg2);}
void f50( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2) { obj->setCapsule(arg0, arg1, arg2);}
void f51( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2) { obj->setCone(arg0, arg1, arg2);}
void f52( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setConvexHull(arg0, arg1);}
void f53( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setStaticTriangleMesh(arg0, arg1);}
void f54( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2) { obj->setHeightfield(arg0, arg1, arg2);}
void f55( PhysicsShape *obj, const Vector3D & arg0, float arg1) { obj->setPlane(arg0, arg1);}
void f56( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1) { obj->setCompound(arg0, arg1);}
void f57( Resource *obj) { obj->load();}
bool f58(const Resource *obj) {return obj->shouldReload();}
void f59( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7) { obj->startCreation(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void f60( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3) { obj->allocMipmapFace(arg0, arg1, arg2, arg3);}
void f61( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2) { obj->allocMipmap(arg0, arg1, arg2);}
void f62( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3) { obj->getMipmapFace(arg0, arg1, arg2, arg3);}
void f63( GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2) { obj->getMipmap(arg0, arg1, arg2);}
void f64( GfxTexture *obj) { obj->generateMipmaps();}
void f65( GfxTexture *obj, float arg0) { obj->setMaximumAnisotropy(arg0);}
void f66( GfxTexture *obj, GfxTexture::Filter arg0) { obj->setMinFilter(arg0);}
void f67( GfxTexture *obj, GfxTexture::Filter arg0) { obj->setMagFilter(arg0);}
void f68( GfxTexture *obj, GfxTexture::MipmapMode arg0) { obj->setMipmapMode(arg0);}
void f69( GfxTexture *obj, GfxTexture::WrapMode arg0) { obj->setWrapMode(arg0);}
void f70( GfxTexture *obj, bool arg0) { obj->setShadowmap(arg0);}
Transform f71( GhostObject *obj) {return obj->getTransform();}
void f72(const GhostObject *obj, const Transform & arg0) { obj->setTransform(arg0);}
void f73( GhostObject *obj) { obj->setEmpty();}
void f74( GhostObject *obj, float arg0) { obj->setSphere(arg0);}
void f75( GhostObject *obj, const Vector3D & arg0) { obj->setBox(arg0);}
void f76( GhostObject *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2) { obj->setCylinder(arg0, arg1, arg2);}
void f77( GhostObject *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2) { obj->setCapsule(arg0, arg1, arg2);}
void f78( GhostObject *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2) { obj->setCone(arg0, arg1, arg2);}
void f79( GhostObject *obj, size_t arg0, const Position3D * arg1) { obj->setConvexHull(arg0, arg1);}
void f80( GhostObject *obj, size_t arg0, const Position3D * arg1) { obj->setStaticTriangleMesh(arg0, arg1);}
void f81( GhostObject *obj, uint32_t arg0, uint32_t arg1, const float * arg2) { obj->setHeightfield(arg0, arg1, arg2);}
void f82( GhostObject *obj, const Vector3D & arg0, float arg1) { obj->setPlane(arg0, arg1);}
void f83( GhostObject *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1) { obj->setCompound(arg0, arg1);}
void f84( GhostObject *obj, ResPtr<PhysicsShape> arg0) { obj->setShape(arg0);}
void f85(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1) { obj->getCollisions(arg0, arg1);}
void f86( PhysicsShapeImpl *obj) {new (obj) PhysicsShapeImpl();}
void f87( Application *obj) { obj->mainloop();}
void f88( Application *obj, const char * arg0) {new (obj) Application(arg0);}
void f89( Application *obj) { obj->~Application();}
void f90( Scene *obj) { obj->handleInput();}
void f91( Scene *obj) { obj->update();}
void f92( Scene *obj, float arg0) { obj->fixedUpdate(arg0);}
Entity * f93( Scene *obj, const String & arg0) {return obj->createEntity(arg0);}
void f94( Scene *obj, size_t arg0) { obj->removeEntity(arg0);}
void f95( Entity *obj, PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1) { obj->addRigidBody(arg0, arg1);}
void f96( File *obj, size_t arg0, void * arg1) { obj->read(arg0, arg1);}
void f97( File *obj, size_t arg0, const void * arg1) { obj->write(arg0, arg1);}
void f98( File *obj, long arg0, File::Origin arg1) { obj->seek(arg0, arg1);}
long f99( File *obj) {return obj->tell();}
void f100( File *obj) { obj->flush();}
bool f101( File *obj) {return obj->isAtEndOfFile();}
size_t f102( File *obj) {return obj->getSize();}
uint8_t f103( File *obj) {return obj->readUInt8();}
int8_t f104( File *obj) {return obj->readInt8();}
uint16_t f105( File *obj) {return obj->readUInt16LE();}
int16_t f106( File *obj) {return obj->readInt16LE();}
uint32_t f107( File *obj) {return obj->readUInt32LE();}
int32_t f108( File *obj) {return obj->readInt32LE();}
uint64_t f109( File *obj) {return obj->readUInt64LE();}
int64_t f110( File *obj) {return obj->readInt64LE();}
uint16_t f111( File *obj) {return obj->readUInt16BE();}
int16_t f112( File *obj) {return obj->readInt16BE();}
uint32_t f113( File *obj) {return obj->readUInt32BE();}
int32_t f114( File *obj) {return obj->readInt32BE();}
uint64_t f115( File *obj) {return obj->readUInt64BE();}
int64_t f116( File *obj) {return obj->readInt64BE();}
float f117( File *obj) {return obj->readFloat32();}
char f118( File *obj) {return obj->readChar();}
void f119( File *obj, uint8_t arg0) { obj->writeUInt8(arg0);}
void f120( File *obj, int8_t arg0) { obj->writeInt8(arg0);}
void f121( File *obj, uint16_t arg0) { obj->writeUInt16LE(arg0);}
void f122( File *obj, int16_t arg0) { obj->writeInt16LE(arg0);}
void f123( File *obj, uint32_t arg0) { obj->writeUInt32LE(arg0);}
void f124( File *obj, int32_t arg0) { obj->writeInt32LE(arg0);}
void f125( File *obj, uint64_t arg0) { obj->writeUInt64LE(arg0);}
void f126( File *obj, int64_t arg0) { obj->writeInt64LE(arg0);}
void f127( File *obj, uint16_t arg0) { obj->writeUInt16BE(arg0);}
void f128( File *obj, int16_t arg0) { obj->writeInt16BE(arg0);}
void f129( File *obj, uint32_t arg0) { obj->writeUInt32BE(arg0);}
void f130( File *obj, int32_t arg0) { obj->writeInt32BE(arg0);}
void f131( File *obj, uint64_t arg0) { obj->writeUInt64BE(arg0);}
void f132( File *obj, int64_t arg0) { obj->writeInt64BE(arg0);}
void f133( File *obj, float arg0) { obj->writeFloat32(arg0);}
void f134( File *obj, const char * arg0, va_list arg1) { obj->vprintf(arg0, arg1);}
void f135( File *obj, char arg0) { obj->writeChar(arg0);}
void f136( File *obj, const char * arg0, const char * arg1) {new (obj) File(arg0, arg1);}
void f137( File *obj) { obj->~File();}
Matrix3x3 f138(const Matrix3x3 *obj, const Matrix3x3 & arg0) {return obj->operator*(arg0);}
Float3 f139(const Matrix3x3 *obj, const Float3 & arg0) {return obj->operator*(arg0);}
Matrix3x3 f140(const Matrix3x3 *obj, float arg0) {return obj->operator/(arg0);}
Matrix3x3 f141(const Matrix3x3 *obj) {return obj->transpose();}
Matrix3x3 f142(const Matrix3x3 *obj) {return obj->inverse();}
Matrix3x3 f143(const Float2 & arg0) {return Matrix3x3::translate(arg0);}
Matrix3x3 f144(const Float3 & arg0) {return Matrix3x3::scale(arg0);}
Matrix3x3 f145(float arg0) {return Matrix3x3::rotate(arg0);}
Matrix3x3 f146(float arg0) {return Matrix3x3::rotatex(arg0);}
Matrix3x3 f147(float arg0) {return Matrix3x3::rotatey(arg0);}
Matrix3x3 f148(float arg0) {return Matrix3x3::rotatez(arg0);}
void f149( Matrix3x3 *obj) {new (obj) Matrix3x3();}
void f150( Matrix3x3 *obj, const Matrix4x4 & arg0) {new (obj) Matrix3x3(arg0);}
void f151( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {new (obj) Matrix3x3(arg0, arg1, arg2);}
void f152( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4) { obj->render(arg0, arg1, arg2, arg3, arg4);}
void f153( Font *obj, const char * arg0) {new (obj) Font(arg0);}
void f154( Font *obj) { obj->~Font();}
void f155( GfxDebugDrawer *obj, const Camera & arg0) { obj->render(arg0);}
void f156( GfxDebugDrawer *obj, GfxApi * arg0) {new (obj) GfxDebugDrawer(arg0);}
void f157( GfxDebugDrawer *obj) { obj->~GfxDebugDrawer();}
Script *f158() {return NEW(Script);}
Script *f159(size_t count) {return NEW_ARRAY(Script, count);}
Script *f160(const String & arg0) {return NEW(Script, arg0);}
GfxMaterial *f161() {return NEW(GfxMaterial);}
GfxMaterial *f162(size_t count) {return NEW_ARRAY(GfxMaterial, count);}
GfxMaterial *f163(const String & arg0) {return NEW(GfxMaterial, arg0);}
LookupException *f164(const char * arg0, size_t arg1, const char * arg2) {return NEW(LookupException, arg0, arg1, arg2);}
Quaternion *f165() {return NEW(Quaternion);}
Quaternion *f166(size_t count) {return NEW_ARRAY(Quaternion, count);}
Quaternion *f167(const Direction3D & arg0, float arg1) {return NEW(Quaternion, arg0, arg1);}
Quaternion *f168(float arg0, float arg1, float arg2, float arg3) {return NEW(Quaternion, arg0, arg1, arg2, arg3);}
Quaternion *f169(const Float3 & arg0) {return NEW(Quaternion, arg0);}
Light *f170() {return NEW(Light);}
Light *f171(size_t count) {return NEW_ARRAY(Light, count);}
PhysicsShape *f172() {return NEW(PhysicsShape);}
PhysicsShape *f173(size_t count) {return NEW_ARRAY(PhysicsShape, count);}
PhysicsShape *f174(const String & arg0) {return NEW(PhysicsShape, arg0);}
ShaderCompileException *f175(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return NEW(ShaderCompileException, arg0, arg1, arg2, arg3);}
Exception *f176(const char * arg0, size_t arg1, const char * arg2) {return NEW(Exception, arg0, arg1, arg2);}
PhysicsDebugDrawer *f177() {return NEW(PhysicsDebugDrawer);}
PhysicsDebugDrawer *f178(size_t count) {return NEW_ARRAY(PhysicsDebugDrawer, count);}
FileException *f179(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return NEW(FileException, arg0, arg1, arg2, arg3, arg4);}
AABB *f180() {return NEW(AABB);}
AABB *f181(size_t count) {return NEW_ARRAY(AABB, count);}
AABB *f182(const Position3D & arg0, const Position3D & arg1) {return NEW(AABB, arg0, arg1);}
ResourceIOException *f183(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return NEW(ResourceIOException, arg0, arg1, arg2, arg3, arg4, arg5);}
GfxTexture *f184(const String & arg0) {return NEW(GfxTexture, arg0);}
GfxTexture *f185() {return NEW(GfxTexture);}
GfxTexture *f186(size_t count) {return NEW_ARRAY(GfxTexture, count);}
PhysicsShapeImpl *f187() {return NEW(PhysicsShapeImpl);}
PhysicsShapeImpl *f188(size_t count) {return NEW_ARRAY(PhysicsShapeImpl, count);}
UserData *f189(const ScriptFunction<void *> & arg0, const ScriptFunction<void, void *> & arg1) {return NEW(UserData, arg0, arg1);}
Application *f190(const char * arg0) {return NEW(Application, arg0);}
GfxModel *f191() {return NEW(GfxModel);}
GfxModel *f192(size_t count) {return NEW_ARRAY(GfxModel, count);}
GfxModel *f193(const String & arg0) {return NEW(GfxModel, arg0);}
Scene *f194() {return NEW(Scene);}
Scene *f195(size_t count) {return NEW_ARRAY(Scene, count);}
Scene *f196(const String & arg0) {return NEW(Scene, arg0);}
File *f197(const char * arg0, const char * arg1) {return NEW(File, arg0, arg1);}
GfxShaderCombination *f198(ResPtr<GfxShader> arg0, ResPtr<GfxShader> arg1) {return NEW(GfxShaderCombination, arg0, arg1);}
Matrix3x3 *f199() {return NEW(Matrix3x3);}
Matrix3x3 *f200(size_t count) {return NEW_ARRAY(Matrix3x3, count);}
Matrix3x3 *f201(const Matrix4x4 & arg0) {return NEW(Matrix3x3, arg0);}
Matrix3x3 *f202(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return NEW(Matrix3x3, arg0, arg1, arg2);}
Font *f203(const char * arg0) {return NEW(Font, arg0);}
GfxDebugDrawer *f204(GfxApi * arg0) {return NEW(GfxDebugDrawer, arg0);}
static const _functionStruct functions = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64, f65, f66, f67, f68, f69, f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f80, f81, f82, f83, f84, f85, f86, f87, f88, f89, f90, f91, f92, f93, f94, f95, f96, f97, f98, f99, f100, f101, f102, f103, f104, f105, f106, f107, f108, f109, f110, f111, f112, f113, f114, f115, f116, f117, f118, f119, f120, f121, f122, f123, f124, f125, f126, f127, f128, f129, f130, f131, f132, f133, f134, f135, f136, f137, f138, f139, f140, f141, f142, f143, f144, f145, f146, f147, f148, f149, f150, f151, f152, f153, f154, f155, f156, f157, f158, f159, f160, f161, f162, f163, f164, f165, f166, f167, f168, f169, f170, f171, f172, f173, f174, f175, f176, f177, f178, f179, f180, f181, f182, f183, f184, f185, f186, f187, f188, f189, f190, f191, f192, f193, f194, f195, f196, f197, f198, f199, f200, f201, f202, f203, f204};
const void *getScriptFunctionStruct() {return &functions;}