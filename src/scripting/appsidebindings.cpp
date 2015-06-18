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
    void (*f6)( GfxMaterial *obj, GfxMaterial::MaterialType arg0);
    void (*f7)(const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3);
    void (*f8)(ResPtr<GfxMesh> arg0);
    void (*f9)( GfxRenderer *obj, const UInt2 & arg0);
    void (*f10)( GfxRenderer *obj);
    void (*f11)( GfxRenderer *obj);
    void (*f12)( GfxRenderer *obj);
    Quaternion (*f13)(const Quaternion *obj, const Quaternion & arg0);
    Matrix4x4 (*f14)(const Quaternion *obj);
    Float4 (*f15)(const Quaternion *obj);
    void (*f16)( Quaternion *obj, const Direction3D & arg0);
    void (*f17)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f18)( Quaternion *obj, const Float3 & arg0);
    Float3 (*f19)( Quaternion *obj);
    void (*f20)( Quaternion *obj);
    void (*f21)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f22)( Quaternion *obj, float arg0, float arg1, float arg2, float arg3);
    void (*f23)( Quaternion *obj, const Float3 & arg0);
    LogEntry & (*f24)( LogEntry *obj, const char * arg0, uint8_t arg1);
    LogEntry & (*f25)( LogEntry *obj, const char * arg0, int8_t arg1);
    LogEntry & (*f26)( LogEntry *obj, const char * arg0, uint16_t arg1);
    LogEntry & (*f27)( LogEntry *obj, const char * arg0, int16_t arg1);
    LogEntry & (*f28)( LogEntry *obj, const char * arg0, uint32_t arg1);
    LogEntry & (*f29)( LogEntry *obj, const char * arg0, int32_t arg1);
    LogEntry & (*f30)( LogEntry *obj, const char * arg0, uint64_t arg1);
    LogEntry & (*f31)( LogEntry *obj, const char * arg0, int64_t arg1);
    LogEntry & (*f32)( LogEntry *obj, const char * arg0, bool arg1);
    LogEntry & (*f33)( LogEntry *obj, const char * arg0, float arg1);
    LogEntry & (*f34)( LogEntry *obj, const char * arg0, double arg1);
    LogEntry & (*f35)( LogEntry *obj, const char * arg0, long double arg1);
    LogEntry & (*f36)( LogEntry *obj, const char * arg0, const char * arg1);
    LogEntry & (*f37)( LogEntry *obj, const char * arg0, const String & arg1);
    LogEntry & (*f38)( LogEntry *obj);
    LogEntry & (*f39)( LogEntry *obj, unsigned int arg0, const char ** arg1);
    int (*f40)( LogEntry *obj);
    int (*f41)( LogEntry *obj);
    void (*f42)( Light *obj, size_t arg0, Light::ShadowmapQuality arg1);
    Matrix4x4 (*f43)(const Light *obj);
    Matrix4x4 (*f44)(const Light *obj);
    void (*f45)( PhysicsShape *obj);
    void (*f46)( PhysicsShape *obj, float arg0);
    void (*f47)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f48)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f49)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f50)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f51)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f52)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f53)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f54)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f55)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    Vector3D (*f56)(const RigidBody *obj);
    void (*f57)( RigidBody *obj, const Vector3D & arg0);
    void (*f58)( RigidBody *obj, float arg0);
    float (*f59)(const RigidBody *obj);
    void (*f60)( RigidBody *obj, float arg0);
    float (*f61)(const RigidBody *obj);
    void (*f62)(const RigidBody *obj, float arg0);
    float (*f63)(const RigidBody *obj);
    float (*f64)(const RigidBody *obj);
    void (*f65)( RigidBody *obj, float arg0);
    float (*f66)(const RigidBody *obj);
    void (*f67)( RigidBody *obj, float arg0);
    void (*f68)( RigidBody *obj, const Vector3D & arg0);
    void (*f69)( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1);
    void (*f70)( RigidBody *obj, const Vector3D & arg0);
    void (*f71)( RigidBody *obj, const Vector3D & arg0);
    void (*f72)( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1);
    void (*f73)( RigidBody *obj);
    Vector3D (*f74)(const RigidBody *obj);
    void (*f75)(const RigidBody *obj, const Vector3D & arg0);
    Vector3D (*f76)(const RigidBody *obj);
    void (*f77)(const RigidBody *obj, const Vector3D & arg0);
    Vector3D (*f78)(const RigidBody *obj, const Position3D & arg0);
    float (*f79)(const RigidBody *obj);
    void (*f80)( RigidBody *obj, float arg0);
    float (*f81)(const RigidBody *obj);
    void (*f82)( RigidBody *obj, float arg0);
    float (*f83)(const RigidBody *obj);
    void (*f84)( RigidBody *obj, float arg0);
    Float3 (*f85)(const RigidBody *obj);
    void (*f86)(const RigidBody *obj, const Float3 & arg0);
    Float3 (*f87)(const RigidBody *obj);
    void (*f88)(const RigidBody *obj, const Float3 & arg0);
    void (*f89)(const RigidBody *obj, const Transform & arg0);
    void (*f90)( RigidBody *obj);
    void (*f91)( RigidBody *obj, float arg0);
    void (*f92)( RigidBody *obj, const Vector3D & arg0);
    void (*f93)( RigidBody *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f94)( RigidBody *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f95)( RigidBody *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f96)( RigidBody *obj, size_t arg0, const Position3D * arg1);
    void (*f97)( RigidBody *obj, size_t arg0, const Position3D * arg1);
    void (*f98)( RigidBody *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f99)( RigidBody *obj, const Vector3D & arg0, float arg1);
    void (*f100)( RigidBody *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    void (*f101)( RigidBody *obj, ResPtr<PhysicsShape> arg0);
    void (*f102)( Resource *obj);
    bool (*f103)(const Resource *obj);
    void (*f104)( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7);
    void (*f105)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3);
    void (*f106)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f107)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3);
    void (*f108)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f109)( GfxTexture *obj);
    void (*f110)( GfxTexture *obj, float arg0);
    void (*f111)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f112)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f113)( GfxTexture *obj, GfxTexture::MipmapMode arg0);
    void (*f114)( GfxTexture *obj, GfxTexture::WrapMode arg0);
    void (*f115)( GfxTexture *obj, bool arg0);
    void (*f116)( PhysicsShapeImpl *obj);
    void (*f117)( Application *obj);
    void (*f118)( Application *obj, const char * arg0);
    void (*f119)( Application *obj);
    void (*f120)( Scene *obj);
    void (*f121)( Scene *obj);
    void (*f122)( Scene *obj, float arg0);
    Entity * (*f123)( Scene *obj, const String & arg0);
    void (*f124)( Scene *obj, size_t arg0);
    void (*f125)( Entity *obj, PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1);
    void (*f126)( File *obj, size_t arg0, void * arg1);
    void (*f127)( File *obj, size_t arg0, const void * arg1);
    void (*f128)( File *obj, long arg0, File::Origin arg1);
    long (*f129)( File *obj);
    void (*f130)( File *obj);
    bool (*f131)( File *obj);
    size_t (*f132)( File *obj);
    uint8_t (*f133)( File *obj);
    int8_t (*f134)( File *obj);
    uint16_t (*f135)( File *obj);
    int16_t (*f136)( File *obj);
    uint32_t (*f137)( File *obj);
    int32_t (*f138)( File *obj);
    uint64_t (*f139)( File *obj);
    int64_t (*f140)( File *obj);
    uint16_t (*f141)( File *obj);
    int16_t (*f142)( File *obj);
    uint32_t (*f143)( File *obj);
    int32_t (*f144)( File *obj);
    uint64_t (*f145)( File *obj);
    int64_t (*f146)( File *obj);
    float (*f147)( File *obj);
    char (*f148)( File *obj);
    void (*f149)( File *obj, uint8_t arg0);
    void (*f150)( File *obj, int8_t arg0);
    void (*f151)( File *obj, uint16_t arg0);
    void (*f152)( File *obj, int16_t arg0);
    void (*f153)( File *obj, uint32_t arg0);
    void (*f154)( File *obj, int32_t arg0);
    void (*f155)( File *obj, uint64_t arg0);
    void (*f156)( File *obj, int64_t arg0);
    void (*f157)( File *obj, uint16_t arg0);
    void (*f158)( File *obj, int16_t arg0);
    void (*f159)( File *obj, uint32_t arg0);
    void (*f160)( File *obj, int32_t arg0);
    void (*f161)( File *obj, uint64_t arg0);
    void (*f162)( File *obj, int64_t arg0);
    void (*f163)( File *obj, float arg0);
    void (*f164)( File *obj, const char * arg0, va_list arg1);
    void (*f165)( File *obj, char arg0);
    void (*f166)( File *obj, const char * arg0, const char * arg1);
    void (*f167)( File *obj);
    Matrix3x3 (*f168)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f169)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f170)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f171)(const Matrix3x3 *obj);
    Matrix3x3 (*f172)(const Matrix3x3 *obj);
    Matrix3x3 (*f173)(const Float2 & arg0);
    Matrix3x3 (*f174)(const Float3 & arg0);
    Matrix3x3 (*f175)(float arg0);
    Matrix3x3 (*f176)(float arg0);
    Matrix3x3 (*f177)(float arg0);
    Matrix3x3 (*f178)(float arg0);
    void (*f179)( Matrix3x3 *obj);
    void (*f180)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f181)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    void (*f182)( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4);
    void (*f183)( Font *obj, const char * arg0);
    void (*f184)( Font *obj);
    void (*f185)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f186)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f187)( GfxDebugDrawer *obj);
    Script *(*f188)();
    Script *(*f189)(size_t count);
    Script *(*f190)(const String & arg0);
    GfxMaterial *(*f191)();
    GfxMaterial *(*f192)(size_t count);
    GfxMaterial *(*f193)(const String & arg0);
    LookupException *(*f194)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f195)();
    Quaternion *(*f196)(size_t count);
    Quaternion *(*f197)(const Direction3D & arg0, float arg1);
    Quaternion *(*f198)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f199)(const Float3 & arg0);
    Light *(*f200)();
    Light *(*f201)(size_t count);
    PhysicsShape *(*f202)();
    PhysicsShape *(*f203)(size_t count);
    PhysicsShape *(*f204)(const String & arg0);
    ShaderCompileException *(*f205)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f206)(const char * arg0, size_t arg1, const char * arg2);
    FileException *(*f207)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    AABB *(*f208)();
    AABB *(*f209)(size_t count);
    AABB *(*f210)(const Position3D & arg0, const Position3D & arg1);
    ResourceIOException *(*f211)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxLitMaterialImpl *(*f212)(bool arg0);
    GfxTexture *(*f213)(const String & arg0);
    GfxTexture *(*f214)();
    GfxTexture *(*f215)(size_t count);
    PhysicsShapeImpl *(*f216)();
    PhysicsShapeImpl *(*f217)(size_t count);
    PhysicsDebugDrawer *(*f218)();
    PhysicsDebugDrawer *(*f219)(size_t count);
    Application *(*f220)(const char * arg0);
    GfxModel *(*f221)();
    GfxModel *(*f222)(size_t count);
    GfxModel *(*f223)(const String & arg0);
    Scene *(*f224)();
    Scene *(*f225)(size_t count);
    Scene *(*f226)(const String & arg0);
    File *(*f227)(const char * arg0, const char * arg1);
    GfxShaderCombination *(*f228)(ResPtr<GfxShader> arg0, ResPtr<GfxShader> arg1);
    Matrix3x3 *(*f229)();
    Matrix3x3 *(*f230)(size_t count);
    Matrix3x3 *(*f231)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f232)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    Font *(*f233)(const char * arg0);
    GfxDebugDrawer *(*f234)(GfxApi * arg0);
};
const char ** f0(unsigned int & arg0) {return getBacktrace(arg0);}
size_t f1(const String & arg0) {return getHash(arg0);}
bool f2(const char * arg0) {return doesFileExist(arg0);}
List<String> f3(const char * arg0) {return listFiles(arg0);}
void f4(Application * arg0) { setApplication(arg0);}
ScriptInstance * f5( Script *obj, Entity * arg0) {return obj->createInstance(arg0);}
void f6( GfxMaterial *obj, GfxMaterial::MaterialType arg0) { obj->setMatType(arg0);}
void f7(const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3) { GfxRenderer::beginRenderMesh(arg0, arg1, arg2, arg3);}
void f8(ResPtr<GfxMesh> arg0) { GfxRenderer::endRenderMesh(arg0);}
void f9( GfxRenderer *obj, const UInt2 & arg0) { obj->resize(arg0);}
void f10( GfxRenderer *obj) { obj->render();}
void f11( GfxRenderer *obj) { obj->updateStats();}
void f12( GfxRenderer *obj) { obj->~GfxRenderer();}
Quaternion f13(const Quaternion *obj, const Quaternion & arg0) {return obj->operator*(arg0);}
Matrix4x4 f14(const Quaternion *obj) {return obj->toMatrix();}
Float4 f15(const Quaternion *obj) {return obj->getAxisAndAngle();}
void f16( Quaternion *obj, const Direction3D & arg0) { obj->setAxis(arg0);}
void f17( Quaternion *obj, const Direction3D & arg0, float arg1) { obj->setAxisAndAngle(arg0, arg1);}
void f18( Quaternion *obj, const Float3 & arg0) { obj->setEulerAngles(arg0);}
Float3 f19( Quaternion *obj) {return obj->getEulerAngles();}
void f20( Quaternion *obj) {new (obj) Quaternion();}
void f21( Quaternion *obj, const Direction3D & arg0, float arg1) {new (obj) Quaternion(arg0, arg1);}
void f22( Quaternion *obj, float arg0, float arg1, float arg2, float arg3) {new (obj) Quaternion(arg0, arg1, arg2, arg3);}
void f23( Quaternion *obj, const Float3 & arg0) {new (obj) Quaternion(arg0);}
LogEntry & f24( LogEntry *obj, const char * arg0, uint8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f25( LogEntry *obj, const char * arg0, int8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f26( LogEntry *obj, const char * arg0, uint16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f27( LogEntry *obj, const char * arg0, int16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f28( LogEntry *obj, const char * arg0, uint32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f29( LogEntry *obj, const char * arg0, int32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f30( LogEntry *obj, const char * arg0, uint64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f31( LogEntry *obj, const char * arg0, int64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f32( LogEntry *obj, const char * arg0, bool arg1) {return obj->variable(arg0, arg1);}
LogEntry & f33( LogEntry *obj, const char * arg0, float arg1) {return obj->variable(arg0, arg1);}
LogEntry & f34( LogEntry *obj, const char * arg0, double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f35( LogEntry *obj, const char * arg0, long double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f36( LogEntry *obj, const char * arg0, const char * arg1) {return obj->variable(arg0, arg1);}
LogEntry & f37( LogEntry *obj, const char * arg0, const String & arg1) {return obj->variable(arg0, arg1);}
LogEntry & f38( LogEntry *obj) {return obj->printBacktrace();}
LogEntry & f39( LogEntry *obj, unsigned int arg0, const char ** arg1) {return obj->printBacktrace(arg0, arg1);}
int f40( LogEntry *obj) {return obj->end();}
int f41( LogEntry *obj) {return obj->fatalEnd();}
void f42( Light *obj, size_t arg0, Light::ShadowmapQuality arg1) { obj->addShadowmap(arg0, arg1);}
Matrix4x4 f43(const Light *obj) {return obj->getViewMatrix();}
Matrix4x4 f44(const Light *obj) {return obj->getProjectionMatrix();}
void f45( PhysicsShape *obj) { obj->setEmpty();}
void f46( PhysicsShape *obj, float arg0) { obj->setSphere(arg0);}
void f47( PhysicsShape *obj, const Vector3D & arg0) { obj->setBox(arg0);}
void f48( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2) { obj->setCylinder(arg0, arg1, arg2);}
void f49( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2) { obj->setCapsule(arg0, arg1, arg2);}
void f50( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2) { obj->setCone(arg0, arg1, arg2);}
void f51( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setConvexHull(arg0, arg1);}
void f52( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setStaticTriangleMesh(arg0, arg1);}
void f53( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2) { obj->setHeightfield(arg0, arg1, arg2);}
void f54( PhysicsShape *obj, const Vector3D & arg0, float arg1) { obj->setPlane(arg0, arg1);}
void f55( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1) { obj->setCompound(arg0, arg1);}
Vector3D f56(const RigidBody *obj) {return obj->getGravity();}
void f57( RigidBody *obj, const Vector3D & arg0) { obj->setGravity(arg0);}
void f58( RigidBody *obj, float arg0) { obj->setLinearDamping(arg0);}
float f59(const RigidBody *obj) {return obj->getLinearDamping();}
void f60( RigidBody *obj, float arg0) { obj->setAngularDamping(arg0);}
float f61(const RigidBody *obj) {return obj->getAngularDamping();}
void f62(const RigidBody *obj, float arg0) { obj->setMass(arg0);}
float f63(const RigidBody *obj) {return obj->getMass();}
float f64(const RigidBody *obj) {return obj->getLinearSleepingThreshold();}
void f65( RigidBody *obj, float arg0) { obj->setLinearSleepingThreshold(arg0);}
float f66(const RigidBody *obj) {return obj->getAngularSleepingThreshold();}
void f67( RigidBody *obj, float arg0) { obj->setAngularSleepingThreshold(arg0);}
void f68( RigidBody *obj, const Vector3D & arg0) { obj->applyTorque(arg0);}
void f69( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1) { obj->applyForce(arg0, arg1);}
void f70( RigidBody *obj, const Vector3D & arg0) { obj->applyCentralImpulse(arg0);}
void f71( RigidBody *obj, const Vector3D & arg0) { obj->applyTorqueImpulse(arg0);}
void f72( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1) { obj->applyImpulse(arg0, arg1);}
void f73( RigidBody *obj) { obj->clearForces();}
Vector3D f74(const RigidBody *obj) {return obj->getLinearVelocity();}
void f75(const RigidBody *obj, const Vector3D & arg0) { obj->setLinearVelocity(arg0);}
Vector3D f76(const RigidBody *obj) {return obj->getAngularVelocity();}
void f77(const RigidBody *obj, const Vector3D & arg0) { obj->setAngularVelocity(arg0);}
Vector3D f78(const RigidBody *obj, const Position3D & arg0) {return obj->getVelocityOfPoint(arg0);}
float f79(const RigidBody *obj) {return obj->getRestitution();}
void f80( RigidBody *obj, float arg0) { obj->setRestitution(arg0);}
float f81(const RigidBody *obj) {return obj->getFriction();}
void f82( RigidBody *obj, float arg0) { obj->setFriction(arg0);}
float f83(const RigidBody *obj) {return obj->getRollingFriction();}
void f84( RigidBody *obj, float arg0) { obj->setRollingFriction(arg0);}
Float3 f85(const RigidBody *obj) {return obj->getLinearFactor();}
void f86(const RigidBody *obj, const Float3 & arg0) { obj->setLinearFactor(arg0);}
Float3 f87(const RigidBody *obj) {return obj->getAngularFactor();}
void f88(const RigidBody *obj, const Float3 & arg0) { obj->setAngularFactor(arg0);}
void f89(const RigidBody *obj, const Transform & arg0) { obj->setTransform(arg0);}
void f90( RigidBody *obj) { obj->setEmpty();}
void f91( RigidBody *obj, float arg0) { obj->setSphere(arg0);}
void f92( RigidBody *obj, const Vector3D & arg0) { obj->setBox(arg0);}
void f93( RigidBody *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2) { obj->setCylinder(arg0, arg1, arg2);}
void f94( RigidBody *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2) { obj->setCapsule(arg0, arg1, arg2);}
void f95( RigidBody *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2) { obj->setCone(arg0, arg1, arg2);}
void f96( RigidBody *obj, size_t arg0, const Position3D * arg1) { obj->setConvexHull(arg0, arg1);}
void f97( RigidBody *obj, size_t arg0, const Position3D * arg1) { obj->setStaticTriangleMesh(arg0, arg1);}
void f98( RigidBody *obj, uint32_t arg0, uint32_t arg1, const float * arg2) { obj->setHeightfield(arg0, arg1, arg2);}
void f99( RigidBody *obj, const Vector3D & arg0, float arg1) { obj->setPlane(arg0, arg1);}
void f100( RigidBody *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1) { obj->setCompound(arg0, arg1);}
void f101( RigidBody *obj, ResPtr<PhysicsShape> arg0) { obj->setShape(arg0);}
void f102( Resource *obj) { obj->load();}
bool f103(const Resource *obj) {return obj->shouldReload();}
void f104( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7) { obj->startCreation(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void f105( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3) { obj->allocMipmapFace(arg0, arg1, arg2, arg3);}
void f106( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2) { obj->allocMipmap(arg0, arg1, arg2);}
void f107( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3) { obj->getMipmapFace(arg0, arg1, arg2, arg3);}
void f108( GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2) { obj->getMipmap(arg0, arg1, arg2);}
void f109( GfxTexture *obj) { obj->generateMipmaps();}
void f110( GfxTexture *obj, float arg0) { obj->setMaximumAnisotropy(arg0);}
void f111( GfxTexture *obj, GfxTexture::Filter arg0) { obj->setMinFilter(arg0);}
void f112( GfxTexture *obj, GfxTexture::Filter arg0) { obj->setMagFilter(arg0);}
void f113( GfxTexture *obj, GfxTexture::MipmapMode arg0) { obj->setMipmapMode(arg0);}
void f114( GfxTexture *obj, GfxTexture::WrapMode arg0) { obj->setWrapMode(arg0);}
void f115( GfxTexture *obj, bool arg0) { obj->setShadowmap(arg0);}
void f116( PhysicsShapeImpl *obj) {new (obj) PhysicsShapeImpl();}
void f117( Application *obj) { obj->mainloop();}
void f118( Application *obj, const char * arg0) {new (obj) Application(arg0);}
void f119( Application *obj) { obj->~Application();}
void f120( Scene *obj) { obj->handleInput();}
void f121( Scene *obj) { obj->update();}
void f122( Scene *obj, float arg0) { obj->fixedUpdate(arg0);}
Entity * f123( Scene *obj, const String & arg0) {return obj->createEntity(arg0);}
void f124( Scene *obj, size_t arg0) { obj->removeEntity(arg0);}
void f125( Entity *obj, PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1) { obj->addRigidBody(arg0, arg1);}
void f126( File *obj, size_t arg0, void * arg1) { obj->read(arg0, arg1);}
void f127( File *obj, size_t arg0, const void * arg1) { obj->write(arg0, arg1);}
void f128( File *obj, long arg0, File::Origin arg1) { obj->seek(arg0, arg1);}
long f129( File *obj) {return obj->tell();}
void f130( File *obj) { obj->flush();}
bool f131( File *obj) {return obj->isAtEndOfFile();}
size_t f132( File *obj) {return obj->getSize();}
uint8_t f133( File *obj) {return obj->readUInt8();}
int8_t f134( File *obj) {return obj->readInt8();}
uint16_t f135( File *obj) {return obj->readUInt16LE();}
int16_t f136( File *obj) {return obj->readInt16LE();}
uint32_t f137( File *obj) {return obj->readUInt32LE();}
int32_t f138( File *obj) {return obj->readInt32LE();}
uint64_t f139( File *obj) {return obj->readUInt64LE();}
int64_t f140( File *obj) {return obj->readInt64LE();}
uint16_t f141( File *obj) {return obj->readUInt16BE();}
int16_t f142( File *obj) {return obj->readInt16BE();}
uint32_t f143( File *obj) {return obj->readUInt32BE();}
int32_t f144( File *obj) {return obj->readInt32BE();}
uint64_t f145( File *obj) {return obj->readUInt64BE();}
int64_t f146( File *obj) {return obj->readInt64BE();}
float f147( File *obj) {return obj->readFloat32();}
char f148( File *obj) {return obj->readChar();}
void f149( File *obj, uint8_t arg0) { obj->writeUInt8(arg0);}
void f150( File *obj, int8_t arg0) { obj->writeInt8(arg0);}
void f151( File *obj, uint16_t arg0) { obj->writeUInt16LE(arg0);}
void f152( File *obj, int16_t arg0) { obj->writeInt16LE(arg0);}
void f153( File *obj, uint32_t arg0) { obj->writeUInt32LE(arg0);}
void f154( File *obj, int32_t arg0) { obj->writeInt32LE(arg0);}
void f155( File *obj, uint64_t arg0) { obj->writeUInt64LE(arg0);}
void f156( File *obj, int64_t arg0) { obj->writeInt64LE(arg0);}
void f157( File *obj, uint16_t arg0) { obj->writeUInt16BE(arg0);}
void f158( File *obj, int16_t arg0) { obj->writeInt16BE(arg0);}
void f159( File *obj, uint32_t arg0) { obj->writeUInt32BE(arg0);}
void f160( File *obj, int32_t arg0) { obj->writeInt32BE(arg0);}
void f161( File *obj, uint64_t arg0) { obj->writeUInt64BE(arg0);}
void f162( File *obj, int64_t arg0) { obj->writeInt64BE(arg0);}
void f163( File *obj, float arg0) { obj->writeFloat32(arg0);}
void f164( File *obj, const char * arg0, va_list arg1) { obj->vprintf(arg0, arg1);}
void f165( File *obj, char arg0) { obj->writeChar(arg0);}
void f166( File *obj, const char * arg0, const char * arg1) {new (obj) File(arg0, arg1);}
void f167( File *obj) { obj->~File();}
Matrix3x3 f168(const Matrix3x3 *obj, const Matrix3x3 & arg0) {return obj->operator*(arg0);}
Float3 f169(const Matrix3x3 *obj, const Float3 & arg0) {return obj->operator*(arg0);}
Matrix3x3 f170(const Matrix3x3 *obj, float arg0) {return obj->operator/(arg0);}
Matrix3x3 f171(const Matrix3x3 *obj) {return obj->transpose();}
Matrix3x3 f172(const Matrix3x3 *obj) {return obj->inverse();}
Matrix3x3 f173(const Float2 & arg0) {return Matrix3x3::translate(arg0);}
Matrix3x3 f174(const Float3 & arg0) {return Matrix3x3::scale(arg0);}
Matrix3x3 f175(float arg0) {return Matrix3x3::rotate(arg0);}
Matrix3x3 f176(float arg0) {return Matrix3x3::rotatex(arg0);}
Matrix3x3 f177(float arg0) {return Matrix3x3::rotatey(arg0);}
Matrix3x3 f178(float arg0) {return Matrix3x3::rotatez(arg0);}
void f179( Matrix3x3 *obj) {new (obj) Matrix3x3();}
void f180( Matrix3x3 *obj, const Matrix4x4 & arg0) {new (obj) Matrix3x3(arg0);}
void f181( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {new (obj) Matrix3x3(arg0, arg1, arg2);}
void f182( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4) { obj->render(arg0, arg1, arg2, arg3, arg4);}
void f183( Font *obj, const char * arg0) {new (obj) Font(arg0);}
void f184( Font *obj) { obj->~Font();}
void f185( GfxDebugDrawer *obj, const Camera & arg0) { obj->render(arg0);}
void f186( GfxDebugDrawer *obj, GfxApi * arg0) {new (obj) GfxDebugDrawer(arg0);}
void f187( GfxDebugDrawer *obj) { obj->~GfxDebugDrawer();}
Script *f188() {return NEW(Script);}
Script *f189(size_t count) {return NEW_ARRAY(Script, count);}
Script *f190(const String & arg0) {return NEW(Script, arg0);}
GfxMaterial *f191() {return NEW(GfxMaterial);}
GfxMaterial *f192(size_t count) {return NEW_ARRAY(GfxMaterial, count);}
GfxMaterial *f193(const String & arg0) {return NEW(GfxMaterial, arg0);}
LookupException *f194(const char * arg0, size_t arg1, const char * arg2) {return NEW(LookupException, arg0, arg1, arg2);}
Quaternion *f195() {return NEW(Quaternion);}
Quaternion *f196(size_t count) {return NEW_ARRAY(Quaternion, count);}
Quaternion *f197(const Direction3D & arg0, float arg1) {return NEW(Quaternion, arg0, arg1);}
Quaternion *f198(float arg0, float arg1, float arg2, float arg3) {return NEW(Quaternion, arg0, arg1, arg2, arg3);}
Quaternion *f199(const Float3 & arg0) {return NEW(Quaternion, arg0);}
Light *f200() {return NEW(Light);}
Light *f201(size_t count) {return NEW_ARRAY(Light, count);}
PhysicsShape *f202() {return NEW(PhysicsShape);}
PhysicsShape *f203(size_t count) {return NEW_ARRAY(PhysicsShape, count);}
PhysicsShape *f204(const String & arg0) {return NEW(PhysicsShape, arg0);}
ShaderCompileException *f205(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return NEW(ShaderCompileException, arg0, arg1, arg2, arg3);}
Exception *f206(const char * arg0, size_t arg1, const char * arg2) {return NEW(Exception, arg0, arg1, arg2);}
FileException *f207(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return NEW(FileException, arg0, arg1, arg2, arg3, arg4);}
AABB *f208() {return NEW(AABB);}
AABB *f209(size_t count) {return NEW_ARRAY(AABB, count);}
AABB *f210(const Position3D & arg0, const Position3D & arg1) {return NEW(AABB, arg0, arg1);}
ResourceIOException *f211(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return NEW(ResourceIOException, arg0, arg1, arg2, arg3, arg4, arg5);}
GfxLitMaterialImpl *f212(bool arg0) {return NEW(GfxLitMaterialImpl, arg0);}
GfxTexture *f213(const String & arg0) {return NEW(GfxTexture, arg0);}
GfxTexture *f214() {return NEW(GfxTexture);}
GfxTexture *f215(size_t count) {return NEW_ARRAY(GfxTexture, count);}
PhysicsShapeImpl *f216() {return NEW(PhysicsShapeImpl);}
PhysicsShapeImpl *f217(size_t count) {return NEW_ARRAY(PhysicsShapeImpl, count);}
PhysicsDebugDrawer *f218() {return NEW(PhysicsDebugDrawer);}
PhysicsDebugDrawer *f219(size_t count) {return NEW_ARRAY(PhysicsDebugDrawer, count);}
Application *f220(const char * arg0) {return NEW(Application, arg0);}
GfxModel *f221() {return NEW(GfxModel);}
GfxModel *f222(size_t count) {return NEW_ARRAY(GfxModel, count);}
GfxModel *f223(const String & arg0) {return NEW(GfxModel, arg0);}
Scene *f224() {return NEW(Scene);}
Scene *f225(size_t count) {return NEW_ARRAY(Scene, count);}
Scene *f226(const String & arg0) {return NEW(Scene, arg0);}
File *f227(const char * arg0, const char * arg1) {return NEW(File, arg0, arg1);}
GfxShaderCombination *f228(ResPtr<GfxShader> arg0, ResPtr<GfxShader> arg1) {return NEW(GfxShaderCombination, arg0, arg1);}
Matrix3x3 *f229() {return NEW(Matrix3x3);}
Matrix3x3 *f230(size_t count) {return NEW_ARRAY(Matrix3x3, count);}
Matrix3x3 *f231(const Matrix4x4 & arg0) {return NEW(Matrix3x3, arg0);}
Matrix3x3 *f232(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return NEW(Matrix3x3, arg0, arg1, arg2);}
Font *f233(const char * arg0) {return NEW(Font, arg0);}
GfxDebugDrawer *f234(GfxApi * arg0) {return NEW(GfxDebugDrawer, arg0);}
static const _functionStruct functions = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64, f65, f66, f67, f68, f69, f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f80, f81, f82, f83, f84, f85, f86, f87, f88, f89, f90, f91, f92, f93, f94, f95, f96, f97, f98, f99, f100, f101, f102, f103, f104, f105, f106, f107, f108, f109, f110, f111, f112, f113, f114, f115, f116, f117, f118, f119, f120, f121, f122, f123, f124, f125, f126, f127, f128, f129, f130, f131, f132, f133, f134, f135, f136, f137, f138, f139, f140, f141, f142, f143, f144, f145, f146, f147, f148, f149, f150, f151, f152, f153, f154, f155, f156, f157, f158, f159, f160, f161, f162, f163, f164, f165, f166, f167, f168, f169, f170, f171, f172, f173, f174, f175, f176, f177, f178, f179, f180, f181, f182, f183, f184, f185, f186, f187, f188, f189, f190, f191, f192, f193, f194, f195, f196, f197, f198, f199, f200, f201, f202, f203, f204, f205, f206, f207, f208, f209, f210, f211, f212, f213, f214, f215, f216, f217, f218, f219, f220, f221, f222, f223, f224, f225, f226, f227, f228, f229, f230, f231, f232, f233, f234};
const void *getScriptFunctionStruct() {return &functions;}