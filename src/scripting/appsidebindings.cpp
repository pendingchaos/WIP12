//Generated from script_binding_generator.py. Do not edit. Edit script_binding_generator.py instead.
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
#include "audio/audio.h"
#include "audio/audioworld.h"
#include "audio/audiodevice.h"
struct _functionStruct
{
    const char ** (*f0)(unsigned int & arg0);
    size_t (*f1)(const String & arg0);
    bool (*f2)(const char * arg0);
    List<String> (*f3)(const char * arg0);
    void (*f4)(Application * arg0);
    ScriptInstance * (*f5)( Script *obj, const char * arg0, Entity * arg1, Scene * arg2);
    Matrix4x4 (*f6)(const Transform *obj);
    void (*f7)( Transform *obj);
    String (*f8)( AudioDevice *obj);
    String (*f9)(size_t arg0);
    size_t (*f10)();
    void (*f11)( AudioDevice *obj, size_t arg0);
    void (*f12)( AudioDevice *obj, size_t arg0);
    void (*f13)( AudioDevice *obj, size_t arg0);
    void (*f14)( AudioDevice *obj);
    void (*f15)( AudioDevice *obj);
    bool (*f16)( AudioDevice *obj);
    void (*f17)( AudioDevice *obj, size_t arg0);
    void (*f18)( AudioDevice *obj, size_t arg0, size_t arg1, size_t arg2);
    void (*f19)( AudioDevice *obj);
    void (*f20)( GfxMaterial *obj, GfxTexture * arg0);
    void (*f21)( GfxMaterial *obj, bool arg0);
    void (*f22)(const Camera & arg0, const Matrix4x4 & arg1, GfxMesh * arg2, GfxShaderCombination * arg3);
    void (*f23)(GfxMesh * arg0);
    void (*f24)( GfxRenderer *obj, const UInt2 & arg0);
    void (*f25)( GfxRenderer *obj);
    AABB (*f26)(const GfxRenderer *obj);
    AABB (*f27)(const GfxRenderer *obj);
    void (*f28)( GfxRenderer *obj);
    void (*f29)( GfxRenderer *obj);
    void (*f30)( GfxRenderer *obj);
    Quaternion (*f31)(const Quaternion *obj, const Quaternion & arg0);
    Matrix4x4 (*f32)(const Quaternion *obj);
    Float4 (*f33)(const Quaternion *obj);
    void (*f34)( Quaternion *obj, const Direction3D & arg0);
    void (*f35)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f36)( Quaternion *obj, const Float3 & arg0);
    Float3 (*f37)( Quaternion *obj);
    void (*f38)( Quaternion *obj);
    void (*f39)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f40)( Quaternion *obj, float arg0, float arg1, float arg2, float arg3);
    void (*f41)( Quaternion *obj, const Float3 & arg0);
    LogEntry & (*f42)( LogEntry *obj, const char * arg0, uint8_t arg1);
    LogEntry & (*f43)( LogEntry *obj, const char * arg0, int8_t arg1);
    LogEntry & (*f44)( LogEntry *obj, const char * arg0, uint16_t arg1);
    LogEntry & (*f45)( LogEntry *obj, const char * arg0, int16_t arg1);
    LogEntry & (*f46)( LogEntry *obj, const char * arg0, uint32_t arg1);
    LogEntry & (*f47)( LogEntry *obj, const char * arg0, int32_t arg1);
    LogEntry & (*f48)( LogEntry *obj, const char * arg0, uint64_t arg1);
    LogEntry & (*f49)( LogEntry *obj, const char * arg0, int64_t arg1);
    LogEntry & (*f50)( LogEntry *obj, const char * arg0, bool arg1);
    LogEntry & (*f51)( LogEntry *obj, const char * arg0, float arg1);
    LogEntry & (*f52)( LogEntry *obj, const char * arg0, double arg1);
    LogEntry & (*f53)( LogEntry *obj, const char * arg0, long double arg1);
    LogEntry & (*f54)( LogEntry *obj, const char * arg0, const char * arg1);
    LogEntry & (*f55)( LogEntry *obj, const char * arg0, const String & arg1);
    LogEntry & (*f56)( LogEntry *obj);
    LogEntry & (*f57)( LogEntry *obj, unsigned int arg0, const char ** arg1);
    int (*f58)( LogEntry *obj);
    int (*f59)( LogEntry *obj);
    void (*f60)( Light *obj, size_t arg0, Light::ShadowmapPrecision arg1);
    void (*f61)( Light *obj, GfxRenderer * arg0);
    void (*f62)( PhysicsShape *obj);
    void (*f63)( PhysicsShape *obj, float arg0);
    void (*f64)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f65)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f66)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f67)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f68)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f69)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f70)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f71)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f72)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    bool (*f73)(const Serializable *obj, const Serializable & arg0);
    void (*f74)( Serializable *obj, File * arg0);
    void (*f75)( Serializable *obj, File * arg0);
    void (*f76)( Resource *obj);
    bool (*f77)(const Resource *obj);
    void (*f78)( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7);
    void (*f79)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3);
    void (*f80)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f81)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3);
    void (*f82)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f83)( GfxTexture *obj);
    void (*f84)( GfxTexture *obj, float arg0);
    void (*f85)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f86)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f87)( GfxTexture *obj, GfxTexture::MipmapMode arg0);
    void (*f88)( GfxTexture *obj, GfxTexture::WrapMode arg0);
    void (*f89)( GfxTexture *obj, bool arg0);
    Transform (*f90)( GhostObject *obj);
    void (*f91)(const GhostObject *obj, const Transform & arg0);
    void (*f92)( GhostObject *obj, PhysicsShape * arg0);
    void (*f93)(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1);
    void (*f94)( Application *obj);
    void (*f95)( Application *obj, const char * arg0);
    void (*f96)( Application *obj);
    void (*f97)( Scene *obj);
    void (*f98)( Scene *obj);
    void (*f99)( Scene *obj, float arg0);
    void (*f100)( Scene *obj);
    Entity * (*f101)( Scene *obj, const String & arg0);
    void (*f102)( Scene *obj, size_t arg0);
    RigidBody * (*f103)( Entity *obj, const RigidBody::ConstructionInfo & arg0, PhysicsShape * arg1);
    Scene * (*f104)(const Entity *obj);
    Entity * (*f105)( Entity *obj, const String & arg0);
    void (*f106)( Entity *obj, size_t arg0);
    void (*f107)( Entity *obj);
    AudioSource * (*f108)( Entity *obj, Audio * arg0);
    void (*f109)( Entity *obj, size_t arg0);
    void (*f110)( File *obj, size_t arg0, void * arg1);
    void (*f111)( File *obj, size_t arg0, const void * arg1);
    void (*f112)( File *obj, long arg0, File::Origin arg1);
    long (*f113)( File *obj);
    void (*f114)( File *obj);
    bool (*f115)( File *obj);
    size_t (*f116)( File *obj);
    uint8_t (*f117)( File *obj);
    int8_t (*f118)( File *obj);
    uint16_t (*f119)( File *obj);
    int16_t (*f120)( File *obj);
    uint32_t (*f121)( File *obj);
    int32_t (*f122)( File *obj);
    uint64_t (*f123)( File *obj);
    int64_t (*f124)( File *obj);
    uint16_t (*f125)( File *obj);
    int16_t (*f126)( File *obj);
    uint32_t (*f127)( File *obj);
    int32_t (*f128)( File *obj);
    uint64_t (*f129)( File *obj);
    int64_t (*f130)( File *obj);
    float (*f131)( File *obj);
    char (*f132)( File *obj);
    void (*f133)( File *obj, uint8_t arg0);
    void (*f134)( File *obj, int8_t arg0);
    void (*f135)( File *obj, uint16_t arg0);
    void (*f136)( File *obj, int16_t arg0);
    void (*f137)( File *obj, uint32_t arg0);
    void (*f138)( File *obj, int32_t arg0);
    void (*f139)( File *obj, uint64_t arg0);
    void (*f140)( File *obj, int64_t arg0);
    void (*f141)( File *obj, uint16_t arg0);
    void (*f142)( File *obj, int16_t arg0);
    void (*f143)( File *obj, uint32_t arg0);
    void (*f144)( File *obj, int32_t arg0);
    void (*f145)( File *obj, uint64_t arg0);
    void (*f146)( File *obj, int64_t arg0);
    void (*f147)( File *obj, float arg0);
    void (*f148)( File *obj, const char * arg0, va_list arg1);
    void (*f149)( File *obj, char arg0);
    void (*f150)( File *obj, const char * arg0, const char * arg1);
    void (*f151)( File *obj);
    Matrix3x3 (*f152)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f153)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f154)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f155)(const Matrix3x3 *obj);
    Matrix3x3 (*f156)(const Matrix3x3 *obj);
    Matrix3x3 (*f157)(const Float2 & arg0);
    Matrix3x3 (*f158)(const Float3 & arg0);
    Matrix3x3 (*f159)(float arg0);
    Matrix3x3 (*f160)(float arg0);
    Matrix3x3 (*f161)(float arg0);
    Matrix3x3 (*f162)(float arg0);
    void (*f163)( Matrix3x3 *obj);
    void (*f164)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f165)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    void (*f166)( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4);
    void (*f167)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f168)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f169)( GfxDebugDrawer *obj);
    AudioSource *(*f170)(Audio * arg0);
    Script *(*f171)();
    Script *(*f172)(size_t count);
    Script *(*f173)(const String & arg0);
    Transform *(*f174)();
    Transform *(*f175)(size_t count);
    AudioDevice *(*f176)(size_t arg0, size_t arg1, size_t arg2);
    GfxMaterial *(*f177)();
    GfxMaterial *(*f178)(size_t count);
    GfxMaterial *(*f179)(const String & arg0);
    SerializeException *(*f180)(const char * arg0, size_t arg1, const char * arg2);
    LookupException *(*f181)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f182)();
    Quaternion *(*f183)(size_t count);
    Quaternion *(*f184)(const Direction3D & arg0, float arg1);
    Quaternion *(*f185)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f186)(const Float3 & arg0);
    Light *(*f187)();
    Light *(*f188)(size_t count);
    PhysicsShape *(*f189)();
    PhysicsShape *(*f190)(size_t count);
    PhysicsShape *(*f191)(const String & arg0);
    Serializable *(*f192)();
    Serializable *(*f193)(size_t count);
    Serializable *(*f194)(uint8_t arg0);
    Serializable *(*f195)(int8_t arg0);
    Serializable *(*f196)(uint16_t arg0);
    Serializable *(*f197)(int16_t arg0);
    Serializable *(*f198)(uint32_t arg0);
    Serializable *(*f199)(int32_t arg0);
    Serializable *(*f200)(uint64_t arg0);
    Serializable *(*f201)(int64_t arg0);
    Serializable *(*f202)(const String & arg0);
    Serializable *(*f203)(bool arg0);
    Serializable *(*f204)(float arg0);
    Serializable *(*f205)(const Float2 & arg0);
    Serializable *(*f206)(const Float3 & arg0);
    Serializable *(*f207)(const Float4 & arg0);
    Serializable *(*f208)(const Int2 & arg0);
    Serializable *(*f209)(const Int3 & arg0);
    Serializable *(*f210)(const Int4 & arg0);
    Serializable *(*f211)(const UInt2 & arg0);
    Serializable *(*f212)(const UInt3 & arg0);
    Serializable *(*f213)(const UInt4 & arg0);
    ShaderCompileException *(*f214)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f215)(const char * arg0, size_t arg1, const char * arg2);
    FileException *(*f216)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    AABB *(*f217)();
    AABB *(*f218)(size_t count);
    AABB *(*f219)(const Position3D & arg0, const Position3D & arg1);
    ResourceIOException *(*f220)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    Audio *(*f221)();
    Audio *(*f222)(size_t count);
    Audio *(*f223)(const String & arg0);
    GfxTexture *(*f224)(const String & arg0);
    GfxTexture *(*f225)();
    GfxTexture *(*f226)(size_t count);
    PhysicsDebugDrawer *(*f227)();
    PhysicsDebugDrawer *(*f228)(size_t count);
    Application *(*f229)(const char * arg0);
    GfxModel *(*f230)();
    GfxModel *(*f231)(size_t count);
    GfxModel *(*f232)(const String & arg0);
    Scene *(*f233)();
    Scene *(*f234)(size_t count);
    Scene *(*f235)(const String & arg0);
    File *(*f236)(const char * arg0, const char * arg1);
    GfxShaderCombination *(*f237)(GfxShader * arg0, GfxShader * arg1);
    Matrix3x3 *(*f238)();
    Matrix3x3 *(*f239)(size_t count);
    Matrix3x3 *(*f240)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f241)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    Font *(*f242)();
    Font *(*f243)(size_t count);
    Font *(*f244)(const String & arg0);
    GfxDebugDrawer *(*f245)(GfxApi * arg0);
};
const char ** f0(unsigned int & arg0) {return getBacktrace(arg0);}
size_t f1(const String & arg0) {return getHash(arg0);}
bool f2(const char * arg0) {return doesFileExist(arg0);}
List<String> f3(const char * arg0) {return listFiles(arg0);}
void f4(Application * arg0) { setApplication(arg0);}
ScriptInstance * f5( Script *obj, const char * arg0, Entity * arg1, Scene * arg2) {return obj->createInstance(arg0, arg1, arg2);}
Matrix4x4 f6(const Transform *obj) {return obj->createMatrix();}
void f7( Transform *obj) {new (obj) Transform();}
String f8( AudioDevice *obj) {return obj->getName();}
String f9(size_t arg0) {return AudioDevice::getName(arg0);}
size_t f10() {return AudioDevice::getDeviceCount();}
void f11( AudioDevice *obj, size_t arg0) { obj->setIndex(arg0);}
void f12( AudioDevice *obj, size_t arg0) { obj->setFrequency(arg0);}
void f13( AudioDevice *obj, size_t arg0) { obj->setSamples(arg0);}
void f14( AudioDevice *obj) { obj->pause();}
void f15( AudioDevice *obj) { obj->play();}
bool f16( AudioDevice *obj) {return obj->getPaused();}
void f17( AudioDevice *obj, size_t arg0) { obj->runCallbacks(arg0);}
void f18( AudioDevice *obj, size_t arg0, size_t arg1, size_t arg2) {new (obj) AudioDevice(arg0, arg1, arg2);}
void f19( AudioDevice *obj) { obj->~AudioDevice();}
void f20( GfxMaterial *obj, GfxTexture * arg0) { obj->setDisplacementMap(arg0);}
void f21( GfxMaterial *obj, bool arg0) { obj->setForward(arg0);}
void f22(const Camera & arg0, const Matrix4x4 & arg1, GfxMesh * arg2, GfxShaderCombination * arg3) { GfxRenderer::beginRenderMesh(arg0, arg1, arg2, arg3);}
void f23(GfxMesh * arg0) { GfxRenderer::endRenderMesh(arg0);}
void f24( GfxRenderer *obj, const UInt2 & arg0) { obj->resize(arg0);}
void f25( GfxRenderer *obj) { obj->render();}
AABB f26(const GfxRenderer *obj) {return obj->computeSceneAABB();}
AABB f27(const GfxRenderer *obj) {return obj->computeShadowCasterAABB();}
void f28( GfxRenderer *obj) { obj->updateStats();}
void f29( GfxRenderer *obj) { obj->updateColorModifierShader();}
void f30( GfxRenderer *obj) { obj->~GfxRenderer();}
Quaternion f31(const Quaternion *obj, const Quaternion & arg0) {return obj->operator*(arg0);}
Matrix4x4 f32(const Quaternion *obj) {return obj->toMatrix();}
Float4 f33(const Quaternion *obj) {return obj->getAxisAndAngle();}
void f34( Quaternion *obj, const Direction3D & arg0) { obj->setAxis(arg0);}
void f35( Quaternion *obj, const Direction3D & arg0, float arg1) { obj->setAxisAndAngle(arg0, arg1);}
void f36( Quaternion *obj, const Float3 & arg0) { obj->setEulerAngles(arg0);}
Float3 f37( Quaternion *obj) {return obj->getEulerAngles();}
void f38( Quaternion *obj) {new (obj) Quaternion();}
void f39( Quaternion *obj, const Direction3D & arg0, float arg1) {new (obj) Quaternion(arg0, arg1);}
void f40( Quaternion *obj, float arg0, float arg1, float arg2, float arg3) {new (obj) Quaternion(arg0, arg1, arg2, arg3);}
void f41( Quaternion *obj, const Float3 & arg0) {new (obj) Quaternion(arg0);}
LogEntry & f42( LogEntry *obj, const char * arg0, uint8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f43( LogEntry *obj, const char * arg0, int8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f44( LogEntry *obj, const char * arg0, uint16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f45( LogEntry *obj, const char * arg0, int16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f46( LogEntry *obj, const char * arg0, uint32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f47( LogEntry *obj, const char * arg0, int32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f48( LogEntry *obj, const char * arg0, uint64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f49( LogEntry *obj, const char * arg0, int64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f50( LogEntry *obj, const char * arg0, bool arg1) {return obj->variable(arg0, arg1);}
LogEntry & f51( LogEntry *obj, const char * arg0, float arg1) {return obj->variable(arg0, arg1);}
LogEntry & f52( LogEntry *obj, const char * arg0, double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f53( LogEntry *obj, const char * arg0, long double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f54( LogEntry *obj, const char * arg0, const char * arg1) {return obj->variable(arg0, arg1);}
LogEntry & f55( LogEntry *obj, const char * arg0, const String & arg1) {return obj->variable(arg0, arg1);}
LogEntry & f56( LogEntry *obj) {return obj->printBacktrace();}
LogEntry & f57( LogEntry *obj, unsigned int arg0, const char ** arg1) {return obj->printBacktrace(arg0, arg1);}
int f58( LogEntry *obj) {return obj->end();}
int f59( LogEntry *obj) {return obj->fatalEnd();}
void f60( Light *obj, size_t arg0, Light::ShadowmapPrecision arg1) { obj->addShadowmap(arg0, arg1);}
void f61( Light *obj, GfxRenderer * arg0) { obj->updateMatrices(arg0);}
void f62( PhysicsShape *obj) { obj->setEmpty();}
void f63( PhysicsShape *obj, float arg0) { obj->setSphere(arg0);}
void f64( PhysicsShape *obj, const Vector3D & arg0) { obj->setBox(arg0);}
void f65( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2) { obj->setCylinder(arg0, arg1, arg2);}
void f66( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2) { obj->setCapsule(arg0, arg1, arg2);}
void f67( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2) { obj->setCone(arg0, arg1, arg2);}
void f68( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setConvexHull(arg0, arg1);}
void f69( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setStaticTriangleMesh(arg0, arg1);}
void f70( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2) { obj->setHeightfield(arg0, arg1, arg2);}
void f71( PhysicsShape *obj, const Vector3D & arg0, float arg1) { obj->setPlane(arg0, arg1);}
void f72( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1) { obj->setCompound(arg0, arg1);}
bool f73(const Serializable *obj, const Serializable & arg0) {return obj->operator==(arg0);}
void f74( Serializable *obj, File * arg0) { obj->writeToFile(arg0);}
void f75( Serializable *obj, File * arg0) { obj->readFromFile(arg0);}
void f76( Resource *obj) { obj->load();}
bool f77(const Resource *obj) {return obj->shouldReload();}
void f78( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7) { obj->startCreation(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void f79( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3) { obj->allocMipmapFace(arg0, arg1, arg2, arg3);}
void f80( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2) { obj->allocMipmap(arg0, arg1, arg2);}
void f81(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3) { obj->getMipmapFace(arg0, arg1, arg2, arg3);}
void f82(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2) { obj->getMipmap(arg0, arg1, arg2);}
void f83( GfxTexture *obj) { obj->generateMipmaps();}
void f84( GfxTexture *obj, float arg0) { obj->setMaximumAnisotropy(arg0);}
void f85( GfxTexture *obj, GfxTexture::Filter arg0) { obj->setMinFilter(arg0);}
void f86( GfxTexture *obj, GfxTexture::Filter arg0) { obj->setMagFilter(arg0);}
void f87( GfxTexture *obj, GfxTexture::MipmapMode arg0) { obj->setMipmapMode(arg0);}
void f88( GfxTexture *obj, GfxTexture::WrapMode arg0) { obj->setWrapMode(arg0);}
void f89( GfxTexture *obj, bool arg0) { obj->setShadowmap(arg0);}
Transform f90( GhostObject *obj) {return obj->getTransform();}
void f91(const GhostObject *obj, const Transform & arg0) { obj->setTransform(arg0);}
void f92( GhostObject *obj, PhysicsShape * arg0) { obj->setShape(arg0);}
void f93(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1) { obj->getCollisions(arg0, arg1);}
void f94( Application *obj) { obj->mainloop();}
void f95( Application *obj, const char * arg0) {new (obj) Application(arg0);}
void f96( Application *obj) { obj->~Application();}
void f97( Scene *obj) { obj->handleInput();}
void f98( Scene *obj) { obj->update();}
void f99( Scene *obj, float arg0) { obj->fixedUpdate(arg0);}
void f100( Scene *obj) { obj->render();}
Entity * f101( Scene *obj, const String & arg0) {return obj->createEntity(arg0);}
void f102( Scene *obj, size_t arg0) { obj->removeEntity(arg0);}
RigidBody * f103( Entity *obj, const RigidBody::ConstructionInfo & arg0, PhysicsShape * arg1) {return obj->addRigidBody(arg0, arg1);}
Scene * f104(const Entity *obj) {return obj->getScene();}
Entity * f105( Entity *obj, const String & arg0) {return obj->createEntity(arg0);}
void f106( Entity *obj, size_t arg0) { obj->removeEntity(arg0);}
void f107( Entity *obj) { obj->updateFinalTransform();}
AudioSource * f108( Entity *obj, Audio * arg0) {return obj->addAudioSource(arg0);}
void f109( Entity *obj, size_t arg0) { obj->removeAudioSource(arg0);}
void f110( File *obj, size_t arg0, void * arg1) { obj->read(arg0, arg1);}
void f111( File *obj, size_t arg0, const void * arg1) { obj->write(arg0, arg1);}
void f112( File *obj, long arg0, File::Origin arg1) { obj->seek(arg0, arg1);}
long f113( File *obj) {return obj->tell();}
void f114( File *obj) { obj->flush();}
bool f115( File *obj) {return obj->isAtEndOfFile();}
size_t f116( File *obj) {return obj->getSize();}
uint8_t f117( File *obj) {return obj->readUInt8();}
int8_t f118( File *obj) {return obj->readInt8();}
uint16_t f119( File *obj) {return obj->readUInt16LE();}
int16_t f120( File *obj) {return obj->readInt16LE();}
uint32_t f121( File *obj) {return obj->readUInt32LE();}
int32_t f122( File *obj) {return obj->readInt32LE();}
uint64_t f123( File *obj) {return obj->readUInt64LE();}
int64_t f124( File *obj) {return obj->readInt64LE();}
uint16_t f125( File *obj) {return obj->readUInt16BE();}
int16_t f126( File *obj) {return obj->readInt16BE();}
uint32_t f127( File *obj) {return obj->readUInt32BE();}
int32_t f128( File *obj) {return obj->readInt32BE();}
uint64_t f129( File *obj) {return obj->readUInt64BE();}
int64_t f130( File *obj) {return obj->readInt64BE();}
float f131( File *obj) {return obj->readFloat32();}
char f132( File *obj) {return obj->readChar();}
void f133( File *obj, uint8_t arg0) { obj->writeUInt8(arg0);}
void f134( File *obj, int8_t arg0) { obj->writeInt8(arg0);}
void f135( File *obj, uint16_t arg0) { obj->writeUInt16LE(arg0);}
void f136( File *obj, int16_t arg0) { obj->writeInt16LE(arg0);}
void f137( File *obj, uint32_t arg0) { obj->writeUInt32LE(arg0);}
void f138( File *obj, int32_t arg0) { obj->writeInt32LE(arg0);}
void f139( File *obj, uint64_t arg0) { obj->writeUInt64LE(arg0);}
void f140( File *obj, int64_t arg0) { obj->writeInt64LE(arg0);}
void f141( File *obj, uint16_t arg0) { obj->writeUInt16BE(arg0);}
void f142( File *obj, int16_t arg0) { obj->writeInt16BE(arg0);}
void f143( File *obj, uint32_t arg0) { obj->writeUInt32BE(arg0);}
void f144( File *obj, int32_t arg0) { obj->writeInt32BE(arg0);}
void f145( File *obj, uint64_t arg0) { obj->writeUInt64BE(arg0);}
void f146( File *obj, int64_t arg0) { obj->writeInt64BE(arg0);}
void f147( File *obj, float arg0) { obj->writeFloat32(arg0);}
void f148( File *obj, const char * arg0, va_list arg1) { obj->vprintf(arg0, arg1);}
void f149( File *obj, char arg0) { obj->writeChar(arg0);}
void f150( File *obj, const char * arg0, const char * arg1) {new (obj) File(arg0, arg1);}
void f151( File *obj) { obj->~File();}
Matrix3x3 f152(const Matrix3x3 *obj, const Matrix3x3 & arg0) {return obj->operator*(arg0);}
Float3 f153(const Matrix3x3 *obj, const Float3 & arg0) {return obj->operator*(arg0);}
Matrix3x3 f154(const Matrix3x3 *obj, float arg0) {return obj->operator/(arg0);}
Matrix3x3 f155(const Matrix3x3 *obj) {return obj->transpose();}
Matrix3x3 f156(const Matrix3x3 *obj) {return obj->inverse();}
Matrix3x3 f157(const Float2 & arg0) {return Matrix3x3::translate(arg0);}
Matrix3x3 f158(const Float3 & arg0) {return Matrix3x3::scale(arg0);}
Matrix3x3 f159(float arg0) {return Matrix3x3::rotate(arg0);}
Matrix3x3 f160(float arg0) {return Matrix3x3::rotatex(arg0);}
Matrix3x3 f161(float arg0) {return Matrix3x3::rotatey(arg0);}
Matrix3x3 f162(float arg0) {return Matrix3x3::rotatez(arg0);}
void f163( Matrix3x3 *obj) {new (obj) Matrix3x3();}
void f164( Matrix3x3 *obj, const Matrix4x4 & arg0) {new (obj) Matrix3x3(arg0);}
void f165( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {new (obj) Matrix3x3(arg0, arg1, arg2);}
void f166( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4) { obj->render(arg0, arg1, arg2, arg3, arg4);}
void f167( GfxDebugDrawer *obj, const Camera & arg0) { obj->render(arg0);}
void f168( GfxDebugDrawer *obj, GfxApi * arg0) {new (obj) GfxDebugDrawer(arg0);}
void f169( GfxDebugDrawer *obj) { obj->~GfxDebugDrawer();}
AudioSource *f170(Audio * arg0) {return NEW(AudioSource, arg0);}
Script *f171() {return NEW(Script);}
Script *f172(size_t count) {return NEW_ARRAY(Script, count);}
Script *f173(const String & arg0) {return NEW(Script, arg0);}
Transform *f174() {return NEW(Transform);}
Transform *f175(size_t count) {return NEW_ARRAY(Transform, count);}
AudioDevice *f176(size_t arg0, size_t arg1, size_t arg2) {return NEW(AudioDevice, arg0, arg1, arg2);}
GfxMaterial *f177() {return NEW(GfxMaterial);}
GfxMaterial *f178(size_t count) {return NEW_ARRAY(GfxMaterial, count);}
GfxMaterial *f179(const String & arg0) {return NEW(GfxMaterial, arg0);}
SerializeException *f180(const char * arg0, size_t arg1, const char * arg2) {return NEW(SerializeException, arg0, arg1, arg2);}
LookupException *f181(const char * arg0, size_t arg1, const char * arg2) {return NEW(LookupException, arg0, arg1, arg2);}
Quaternion *f182() {return NEW(Quaternion);}
Quaternion *f183(size_t count) {return NEW_ARRAY(Quaternion, count);}
Quaternion *f184(const Direction3D & arg0, float arg1) {return NEW(Quaternion, arg0, arg1);}
Quaternion *f185(float arg0, float arg1, float arg2, float arg3) {return NEW(Quaternion, arg0, arg1, arg2, arg3);}
Quaternion *f186(const Float3 & arg0) {return NEW(Quaternion, arg0);}
Light *f187() {return NEW(Light);}
Light *f188(size_t count) {return NEW_ARRAY(Light, count);}
PhysicsShape *f189() {return NEW(PhysicsShape);}
PhysicsShape *f190(size_t count) {return NEW_ARRAY(PhysicsShape, count);}
PhysicsShape *f191(const String & arg0) {return NEW(PhysicsShape, arg0);}
Serializable *f192() {return NEW(Serializable);}
Serializable *f193(size_t count) {return NEW_ARRAY(Serializable, count);}
Serializable *f194(uint8_t arg0) {return NEW(Serializable, arg0);}
Serializable *f195(int8_t arg0) {return NEW(Serializable, arg0);}
Serializable *f196(uint16_t arg0) {return NEW(Serializable, arg0);}
Serializable *f197(int16_t arg0) {return NEW(Serializable, arg0);}
Serializable *f198(uint32_t arg0) {return NEW(Serializable, arg0);}
Serializable *f199(int32_t arg0) {return NEW(Serializable, arg0);}
Serializable *f200(uint64_t arg0) {return NEW(Serializable, arg0);}
Serializable *f201(int64_t arg0) {return NEW(Serializable, arg0);}
Serializable *f202(const String & arg0) {return NEW(Serializable, arg0);}
Serializable *f203(bool arg0) {return NEW(Serializable, arg0);}
Serializable *f204(float arg0) {return NEW(Serializable, arg0);}
Serializable *f205(const Float2 & arg0) {return NEW(Serializable, arg0);}
Serializable *f206(const Float3 & arg0) {return NEW(Serializable, arg0);}
Serializable *f207(const Float4 & arg0) {return NEW(Serializable, arg0);}
Serializable *f208(const Int2 & arg0) {return NEW(Serializable, arg0);}
Serializable *f209(const Int3 & arg0) {return NEW(Serializable, arg0);}
Serializable *f210(const Int4 & arg0) {return NEW(Serializable, arg0);}
Serializable *f211(const UInt2 & arg0) {return NEW(Serializable, arg0);}
Serializable *f212(const UInt3 & arg0) {return NEW(Serializable, arg0);}
Serializable *f213(const UInt4 & arg0) {return NEW(Serializable, arg0);}
ShaderCompileException *f214(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return NEW(ShaderCompileException, arg0, arg1, arg2, arg3);}
Exception *f215(const char * arg0, size_t arg1, const char * arg2) {return NEW(Exception, arg0, arg1, arg2);}
FileException *f216(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return NEW(FileException, arg0, arg1, arg2, arg3, arg4);}
AABB *f217() {return NEW(AABB);}
AABB *f218(size_t count) {return NEW_ARRAY(AABB, count);}
AABB *f219(const Position3D & arg0, const Position3D & arg1) {return NEW(AABB, arg0, arg1);}
ResourceIOException *f220(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return NEW(ResourceIOException, arg0, arg1, arg2, arg3, arg4, arg5);}
Audio *f221() {return NEW(Audio);}
Audio *f222(size_t count) {return NEW_ARRAY(Audio, count);}
Audio *f223(const String & arg0) {return NEW(Audio, arg0);}
GfxTexture *f224(const String & arg0) {return NEW(GfxTexture, arg0);}
GfxTexture *f225() {return NEW(GfxTexture);}
GfxTexture *f226(size_t count) {return NEW_ARRAY(GfxTexture, count);}
PhysicsDebugDrawer *f227() {return NEW(PhysicsDebugDrawer);}
PhysicsDebugDrawer *f228(size_t count) {return NEW_ARRAY(PhysicsDebugDrawer, count);}
Application *f229(const char * arg0) {return NEW(Application, arg0);}
GfxModel *f230() {return NEW(GfxModel);}
GfxModel *f231(size_t count) {return NEW_ARRAY(GfxModel, count);}
GfxModel *f232(const String & arg0) {return NEW(GfxModel, arg0);}
Scene *f233() {return NEW(Scene);}
Scene *f234(size_t count) {return NEW_ARRAY(Scene, count);}
Scene *f235(const String & arg0) {return NEW(Scene, arg0);}
File *f236(const char * arg0, const char * arg1) {return NEW(File, arg0, arg1);}
GfxShaderCombination *f237(GfxShader * arg0, GfxShader * arg1) {return NEW(GfxShaderCombination, arg0, arg1);}
Matrix3x3 *f238() {return NEW(Matrix3x3);}
Matrix3x3 *f239(size_t count) {return NEW_ARRAY(Matrix3x3, count);}
Matrix3x3 *f240(const Matrix4x4 & arg0) {return NEW(Matrix3x3, arg0);}
Matrix3x3 *f241(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return NEW(Matrix3x3, arg0, arg1, arg2);}
Font *f242() {return NEW(Font);}
Font *f243(size_t count) {return NEW_ARRAY(Font, count);}
Font *f244(const String & arg0) {return NEW(Font, arg0);}
GfxDebugDrawer *f245(GfxApi * arg0) {return NEW(GfxDebugDrawer, arg0);}
static const _functionStruct functions = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64, f65, f66, f67, f68, f69, f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f80, f81, f82, f83, f84, f85, f86, f87, f88, f89, f90, f91, f92, f93, f94, f95, f96, f97, f98, f99, f100, f101, f102, f103, f104, f105, f106, f107, f108, f109, f110, f111, f112, f113, f114, f115, f116, f117, f118, f119, f120, f121, f122, f123, f124, f125, f126, f127, f128, f129, f130, f131, f132, f133, f134, f135, f136, f137, f138, f139, f140, f141, f142, f143, f144, f145, f146, f147, f148, f149, f150, f151, f152, f153, f154, f155, f156, f157, f158, f159, f160, f161, f162, f163, f164, f165, f166, f167, f168, f169, f170, f171, f172, f173, f174, f175, f176, f177, f178, f179, f180, f181, f182, f183, f184, f185, f186, f187, f188, f189, f190, f191, f192, f193, f194, f195, f196, f197, f198, f199, f200, f201, f202, f203, f204, f205, f206, f207, f208, f209, f210, f211, f212, f213, f214, f215, f216, f217, f218, f219, f220, f221, f222, f223, f224, f225, f226, f227, f228, f229, f230, f231, f232, f233, f234, f235, f236, f237, f238, f239, f240, f241, f242, f243, f244, f245};
const void *getScriptFunctionStruct() {return &functions;}