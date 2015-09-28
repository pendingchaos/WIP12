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
#include "containers/string.h"
#include "containers/hashmap.h"
#include "containers/resizabledata.h"
#include "physics/physicsworld.h"
#include "physics/rigidbody.h"
#include "physics/physicsshape.h"
#include "physics/physicsdebugdrawer.h"
#include "platform.h"
#include "audio/audio.h"
#include "audio/audioworld.h"
#include "audio/audiodevice.h"
#include "imgui.h"
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
    void (*f8)( Platform *obj, uint32_t arg0, uint32_t arg1);
    void (*f9)( Platform *obj);
    bool (*f10)( Platform *obj, Event & arg0);
    bool (*f11)(const Platform *obj);
    uint64_t (*f12)(const Platform *obj);
    uint64_t (*f13)(const Platform *obj);
    size_t (*f14)(const Platform *obj);
    size_t (*f15)(const Platform *obj);
    Int2 (*f16)(const Platform *obj);
    void (*f17)( Platform *obj, Int2 arg0);
    bool (*f18)(const Platform *obj);
    bool (*f19)(const Platform *obj);
    bool (*f20)(const Platform *obj);
    Int2 (*f21)(const Platform *obj);
    bool (*f22)(const Platform *obj);
    void (*f23)(const Platform *obj, bool arg0);
    bool (*f24)(const Platform *obj, Key arg0);
    bool (*f25)(const Platform *obj);
    void (*f26)( Platform *obj, bool arg0);
    String (*f27)( AudioDevice *obj);
    String (*f28)(size_t arg0);
    size_t (*f29)();
    void (*f30)( AudioDevice *obj, size_t arg0);
    void (*f31)( AudioDevice *obj, size_t arg0);
    void (*f32)( AudioDevice *obj, size_t arg0);
    void (*f33)( AudioDevice *obj);
    void (*f34)( AudioDevice *obj);
    bool (*f35)( AudioDevice *obj);
    void (*f36)( AudioDevice *obj, size_t arg0);
    void (*f37)( AudioDevice *obj, size_t arg0, size_t arg1, size_t arg2);
    void (*f38)( AudioDevice *obj);
    void (*f39)( GfxMaterial *obj, GfxTexture * arg0);
    void (*f40)( GfxMaterial *obj, bool arg0);
    void (*f41)( GfxRenderer *obj, const UInt2 & arg0);
    void (*f42)( GfxRenderer *obj);
    AABB (*f43)(const GfxRenderer *obj);
    AABB (*f44)(const GfxRenderer *obj);
    void (*f45)( GfxRenderer *obj);
    void (*f46)( GfxRenderer *obj);
    GfxTerrain * (*f47)( GfxRenderer *obj, float arg0, size_t arg1, GfxTexture * arg2);
    void (*f48)( GfxRenderer *obj);
    void (*f49)( GfxRenderer *obj);
    Quaternion (*f50)(const Quaternion *obj, const Quaternion & arg0);
    Matrix4x4 (*f51)(const Quaternion *obj);
    Float4 (*f52)(const Quaternion *obj);
    void (*f53)( Quaternion *obj, const Direction3D & arg0);
    void (*f54)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f55)( Quaternion *obj, const Float3 & arg0);
    Float3 (*f56)( Quaternion *obj);
    void (*f57)( Quaternion *obj);
    void (*f58)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f59)( Quaternion *obj, float arg0, float arg1, float arg2, float arg3);
    void (*f60)( Quaternion *obj, const Float3 & arg0);
    LogEntry & (*f61)( LogEntry *obj, const char * arg0, uint8_t arg1);
    LogEntry & (*f62)( LogEntry *obj, const char * arg0, int8_t arg1);
    LogEntry & (*f63)( LogEntry *obj, const char * arg0, uint16_t arg1);
    LogEntry & (*f64)( LogEntry *obj, const char * arg0, int16_t arg1);
    LogEntry & (*f65)( LogEntry *obj, const char * arg0, uint32_t arg1);
    LogEntry & (*f66)( LogEntry *obj, const char * arg0, int32_t arg1);
    LogEntry & (*f67)( LogEntry *obj, const char * arg0, uint64_t arg1);
    LogEntry & (*f68)( LogEntry *obj, const char * arg0, int64_t arg1);
    LogEntry & (*f69)( LogEntry *obj, const char * arg0, bool arg1);
    LogEntry & (*f70)( LogEntry *obj, const char * arg0, float arg1);
    LogEntry & (*f71)( LogEntry *obj, const char * arg0, double arg1);
    LogEntry & (*f72)( LogEntry *obj, const char * arg0, long double arg1);
    LogEntry & (*f73)( LogEntry *obj, const char * arg0, const char * arg1);
    LogEntry & (*f74)( LogEntry *obj, const char * arg0, const String & arg1);
    LogEntry & (*f75)( LogEntry *obj);
    LogEntry & (*f76)( LogEntry *obj, unsigned int arg0, const char ** arg1);
    int (*f77)( LogEntry *obj);
    int (*f78)( LogEntry *obj);
    void (*f79)( Light *obj, size_t arg0, GfxShadowmapPrecision arg1);
    float (*f80)(const Light *obj, float arg0);
    float (*f81)(const Light *obj, float arg0);
    void (*f82)( Light *obj, GfxRenderer * arg0);
    void (*f83)( PhysicsShape *obj);
    void (*f84)( PhysicsShape *obj, float arg0);
    void (*f85)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f86)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f87)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f88)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f89)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f90)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f91)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f92)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f93)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    bool (*f94)(const Serializable *obj, const Serializable & arg0);
    void (*f95)( Serializable *obj, File * arg0);
    void (*f96)( Serializable *obj, File * arg0);
    void (*f97)( Resource *obj);
    void (*f98)( GfxAnimationState *obj);
    void (*f99)( GfxAnimationState *obj, GfxMesh * arg0, const String & arg1);
    void (*f100)( GfxAnimationState *obj);
    bool (*f101)( GuiPlacer *obj, const char * arg0, size_t arg1, size_t arg2);
    void (*f102)( GuiPlacer *obj, const char * arg0);
    GuiPlacer (*f103)( GuiPlacer *obj, size_t arg0, size_t arg1);
    void (*f104)( GuiPlacer *obj);
    void (*f105)( GuiPlacer *obj, const GuiPlacer & arg0);
    void (*f106)( GuiPlacer *obj);
    void (*f107)( GuiPlacer *obj, XOrigin arg0, int arg1);
    void (*f108)( GuiPlacer *obj, ImGui * arg0, int arg1, int arg2, size_t arg3);
    void (*f109)( GfxTexture *obj, GfxTextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexPurpose arg6, GfxTexFormat arg7);
    void (*f110)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, const void * arg3);
    void (*f111)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f112)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, void * arg3);
    void (*f113)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f114)( GfxTexture *obj);
    void (*f115)( GfxTexture *obj, float arg0);
    void (*f116)( GfxTexture *obj, GfxFilter arg0);
    void (*f117)( GfxTexture *obj, GfxFilter arg0);
    void (*f118)( GfxTexture *obj, GfxMipmapMode arg0);
    void (*f119)( GfxTexture *obj, GfxWrapMode arg0);
    void (*f120)( GfxTexture *obj, bool arg0);
    Transform (*f121)( GhostObject *obj);
    void (*f122)(const GhostObject *obj, const Transform & arg0);
    void (*f123)( GhostObject *obj, PhysicsShape * arg0);
    void (*f124)(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1);
    void (*f125)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, Float3 arg8, Float4 arg9);
    void (*f126)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, Container * arg4);
    void (*f127)( ImGui *obj, Container * arg0);
    void (*f128)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6);
    void (*f129)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6);
    bool (*f130)( ImGui *obj, const char * arg0, int arg1, int arg2, int arg3, int arg4);
    size_t (*f131)( ImGui *obj, const char * arg0, int arg1, int arg2, bool arg3, bool arg4);
    void (*f132)( ImGui *obj);
    void (*f133)( ImGui *obj);
    void (*f134)( ImGui *obj);
    void (*f135)( Application *obj);
    void (*f136)( Application *obj, const char * arg0);
    void (*f137)( Application *obj);
    void (*f138)( Scene *obj);
    void (*f139)( Scene *obj);
    void (*f140)( Scene *obj, float arg0);
    void (*f141)( Scene *obj);
    Entity * (*f142)( Scene *obj, const String & arg0);
    void (*f143)( Scene *obj, size_t arg0);
    RigidBody * (*f144)( Entity *obj, const RigidBodyConstructionInfo & arg0, PhysicsShape * arg1);
    Scene * (*f145)(const Entity *obj);
    Entity * (*f146)( Entity *obj, const String & arg0);
    void (*f147)( Entity *obj, size_t arg0);
    void (*f148)( Entity *obj);
    AudioSource * (*f149)( Entity *obj, Audio * arg0);
    void (*f150)( Entity *obj, size_t arg0);
    void (*f151)( File *obj, size_t arg0, void * arg1);
    void (*f152)( File *obj, size_t arg0, const void * arg1);
    void (*f153)( File *obj, long arg0, FileOrigin arg1);
    long (*f154)( File *obj);
    void (*f155)( File *obj);
    bool (*f156)( File *obj);
    size_t (*f157)( File *obj);
    uint8_t (*f158)( File *obj);
    int8_t (*f159)( File *obj);
    uint16_t (*f160)( File *obj);
    int16_t (*f161)( File *obj);
    uint32_t (*f162)( File *obj);
    int32_t (*f163)( File *obj);
    uint64_t (*f164)( File *obj);
    int64_t (*f165)( File *obj);
    uint16_t (*f166)( File *obj);
    int16_t (*f167)( File *obj);
    uint32_t (*f168)( File *obj);
    int32_t (*f169)( File *obj);
    uint64_t (*f170)( File *obj);
    int64_t (*f171)( File *obj);
    float (*f172)( File *obj);
    char (*f173)( File *obj);
    void (*f174)( File *obj, uint8_t arg0);
    void (*f175)( File *obj, int8_t arg0);
    void (*f176)( File *obj, uint16_t arg0);
    void (*f177)( File *obj, int16_t arg0);
    void (*f178)( File *obj, uint32_t arg0);
    void (*f179)( File *obj, int32_t arg0);
    void (*f180)( File *obj, uint64_t arg0);
    void (*f181)( File *obj, int64_t arg0);
    void (*f182)( File *obj, uint16_t arg0);
    void (*f183)( File *obj, int16_t arg0);
    void (*f184)( File *obj, uint32_t arg0);
    void (*f185)( File *obj, int32_t arg0);
    void (*f186)( File *obj, uint64_t arg0);
    void (*f187)( File *obj, int64_t arg0);
    void (*f188)( File *obj, float arg0);
    void (*f189)( File *obj, const char * arg0, va_list arg1);
    void (*f190)( File *obj, char arg0);
    void (*f191)( File *obj, const char * arg0, const char * arg1);
    void (*f192)( File *obj);
    Matrix3x3 (*f193)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f194)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f195)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f196)(const Matrix3x3 *obj);
    Matrix3x3 (*f197)(const Matrix3x3 *obj);
    Matrix3x3 (*f198)(const Float2 & arg0);
    Matrix3x3 (*f199)(const Float3 & arg0);
    Matrix3x3 (*f200)(float arg0);
    Matrix3x3 (*f201)(float arg0);
    Matrix3x3 (*f202)(float arg0);
    Matrix3x3 (*f203)(float arg0);
    void (*f204)( Matrix3x3 *obj);
    void (*f205)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f206)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    size_t (*f207)( Font *obj, size_t arg0, const char * arg1);
    void (*f208)( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4);
    void (*f209)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f210)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f211)( GfxDebugDrawer *obj);
    AudioSource *(*f212)(Audio * arg0);
    Script *(*f213)();
    Script *(*f214)(size_t count);
    Script *(*f215)(const String & arg0);
    Transform *(*f216)();
    Transform *(*f217)(size_t count);
    Platform *(*f218)();
    Platform *(*f219)(size_t count);
    AudioDevice *(*f220)(size_t arg0, size_t arg1, size_t arg2);
    GfxMaterial *(*f221)();
    GfxMaterial *(*f222)(size_t count);
    GfxMaterial *(*f223)(const String & arg0);
    SerializeException *(*f224)(const char * arg0, size_t arg1, const char * arg2);
    LookupException *(*f225)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f226)();
    Quaternion *(*f227)(size_t count);
    Quaternion *(*f228)(const Direction3D & arg0, float arg1);
    Quaternion *(*f229)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f230)(const Float3 & arg0);
    Light *(*f231)();
    Light *(*f232)(size_t count);
    PhysicsShape *(*f233)();
    PhysicsShape *(*f234)(size_t count);
    PhysicsShape *(*f235)(const String & arg0);
    Serializable *(*f236)();
    Serializable *(*f237)(size_t count);
    Serializable *(*f238)(uint8_t arg0);
    Serializable *(*f239)(int8_t arg0);
    Serializable *(*f240)(uint16_t arg0);
    Serializable *(*f241)(int16_t arg0);
    Serializable *(*f242)(uint32_t arg0);
    Serializable *(*f243)(int32_t arg0);
    Serializable *(*f244)(uint64_t arg0);
    Serializable *(*f245)(int64_t arg0);
    Serializable *(*f246)(const String & arg0);
    Serializable *(*f247)(bool arg0);
    Serializable *(*f248)(float arg0);
    Serializable *(*f249)(const Float2 & arg0);
    Serializable *(*f250)(const Float3 & arg0);
    Serializable *(*f251)(const Float4 & arg0);
    Serializable *(*f252)(const Int2 & arg0);
    Serializable *(*f253)(const Int3 & arg0);
    Serializable *(*f254)(const Int4 & arg0);
    Serializable *(*f255)(const UInt2 & arg0);
    Serializable *(*f256)(const UInt3 & arg0);
    Serializable *(*f257)(const UInt4 & arg0);
    ShaderCompileException *(*f258)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f259)(const char * arg0, size_t arg1, const char * arg2);
    FileException *(*f260)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    AABB *(*f261)();
    AABB *(*f262)(size_t count);
    AABB *(*f263)(const Position3D & arg0, const Position3D & arg1);
    ResourceIOException *(*f264)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxAnimationState *(*f265)(GfxMesh * arg0, const String & arg1);
    GuiPlacer *(*f266)(ImGui * arg0, int arg1, int arg2, size_t arg3);
    Audio *(*f267)();
    Audio *(*f268)(size_t count);
    Audio *(*f269)(const String & arg0);
    GfxTexture *(*f270)(const String & arg0);
    GfxTexture *(*f271)();
    GfxTexture *(*f272)(size_t count);
    PhysicsDebugDrawer *(*f273)();
    PhysicsDebugDrawer *(*f274)(size_t count);
    ImGui *(*f275)();
    ImGui *(*f276)(size_t count);
    Application *(*f277)(const char * arg0);
    GfxModel *(*f278)();
    GfxModel *(*f279)(size_t count);
    GfxModel *(*f280)(const String & arg0);
    Scene *(*f281)();
    Scene *(*f282)(size_t count);
    Scene *(*f283)(const String & arg0);
    File *(*f284)(const char * arg0, const char * arg1);
    Matrix3x3 *(*f285)();
    Matrix3x3 *(*f286)(size_t count);
    Matrix3x3 *(*f287)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f288)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    Font *(*f289)();
    Font *(*f290)(size_t count);
    Font *(*f291)(const String & arg0);
    GfxDebugDrawer *(*f292)(GfxApi * arg0);
};
const char ** f0(unsigned int & arg0) {return getBacktrace(arg0);}
size_t f1(const String & arg0) {return getHash(arg0);}
bool f2(const char * arg0) {return doesFileExist(arg0);}
List<String> f3(const char * arg0) {return listFiles(arg0);}
void f4(Application * arg0) { setApplication(arg0);}
ScriptInstance * f5( Script *obj, const char * arg0, Entity * arg1, Scene * arg2) {return obj->createInstance(arg0, arg1, arg2);}
Matrix4x4 f6(const Transform *obj) {return obj->createMatrix();}
void f7( Transform *obj) {new (obj) Transform();}
void f8( Platform *obj, uint32_t arg0, uint32_t arg1) { obj->initWindow(arg0, arg1);}
void f9( Platform *obj) { obj->destroyWindow();}
bool f10( Platform *obj, Event & arg0) {return obj->pollEvent(arg0);}
bool f11(const Platform *obj) {return obj->eventsLeft();}
uint64_t f12(const Platform *obj) {return obj->getTime();}
uint64_t f13(const Platform *obj) {return obj->getTimerFrequency();}
size_t f14(const Platform *obj) {return obj->getWindowWidth();}
size_t f15(const Platform *obj) {return obj->getWindowHeight();}
Int2 f16(const Platform *obj) {return obj->getMousePosition();}
void f17( Platform *obj, Int2 arg0) { obj->setMousePosition(arg0);}
bool f18(const Platform *obj) {return obj->isLeftMouseButtonPressed();}
bool f19(const Platform *obj) {return obj->isRightMouseButtonPressed();}
bool f20(const Platform *obj) {return obj->isMiddleMouseButtonPressed();}
Int2 f21(const Platform *obj) {return obj->getMouseWheel();}
bool f22(const Platform *obj) {return obj->isCursorVisible();}
void f23(const Platform *obj, bool arg0) { obj->setCursorVisible(arg0);}
bool f24(const Platform *obj, Key arg0) {return obj->isKeyPressed(arg0);}
bool f25(const Platform *obj) {return obj->getFullscreen();}
void f26( Platform *obj, bool arg0) { obj->setFullscreen(arg0);}
String f27( AudioDevice *obj) {return obj->getName();}
String f28(size_t arg0) {return AudioDevice::getName(arg0);}
size_t f29() {return AudioDevice::getDeviceCount();}
void f30( AudioDevice *obj, size_t arg0) { obj->setIndex(arg0);}
void f31( AudioDevice *obj, size_t arg0) { obj->setFrequency(arg0);}
void f32( AudioDevice *obj, size_t arg0) { obj->setSamples(arg0);}
void f33( AudioDevice *obj) { obj->pause();}
void f34( AudioDevice *obj) { obj->play();}
bool f35( AudioDevice *obj) {return obj->getPaused();}
void f36( AudioDevice *obj, size_t arg0) { obj->runCallbacks(arg0);}
void f37( AudioDevice *obj, size_t arg0, size_t arg1, size_t arg2) {new (obj) AudioDevice(arg0, arg1, arg2);}
void f38( AudioDevice *obj) { obj->~AudioDevice();}
void f39( GfxMaterial *obj, GfxTexture * arg0) { obj->setDisplacementMap(arg0);}
void f40( GfxMaterial *obj, bool arg0) { obj->setForward(arg0);}
void f41( GfxRenderer *obj, const UInt2 & arg0) { obj->resize(arg0);}
void f42( GfxRenderer *obj) { obj->render();}
AABB f43(const GfxRenderer *obj) {return obj->computeSceneAABB();}
AABB f44(const GfxRenderer *obj) {return obj->computeShadowCasterAABB();}
void f45( GfxRenderer *obj) { obj->updateStats();}
void f46( GfxRenderer *obj) { obj->updateColorModifierShader();}
GfxTerrain * f47( GfxRenderer *obj, float arg0, size_t arg1, GfxTexture * arg2) {return obj->addTerrain(arg0, arg1, arg2);}
void f48( GfxRenderer *obj) { obj->removeTerrain();}
void f49( GfxRenderer *obj) { obj->~GfxRenderer();}
Quaternion f50(const Quaternion *obj, const Quaternion & arg0) {return obj->operator*(arg0);}
Matrix4x4 f51(const Quaternion *obj) {return obj->toMatrix();}
Float4 f52(const Quaternion *obj) {return obj->getAxisAndAngle();}
void f53( Quaternion *obj, const Direction3D & arg0) { obj->setAxis(arg0);}
void f54( Quaternion *obj, const Direction3D & arg0, float arg1) { obj->setAxisAndAngle(arg0, arg1);}
void f55( Quaternion *obj, const Float3 & arg0) { obj->setEulerAngles(arg0);}
Float3 f56( Quaternion *obj) {return obj->getEulerAngles();}
void f57( Quaternion *obj) {new (obj) Quaternion();}
void f58( Quaternion *obj, const Direction3D & arg0, float arg1) {new (obj) Quaternion(arg0, arg1);}
void f59( Quaternion *obj, float arg0, float arg1, float arg2, float arg3) {new (obj) Quaternion(arg0, arg1, arg2, arg3);}
void f60( Quaternion *obj, const Float3 & arg0) {new (obj) Quaternion(arg0);}
LogEntry & f61( LogEntry *obj, const char * arg0, uint8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f62( LogEntry *obj, const char * arg0, int8_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f63( LogEntry *obj, const char * arg0, uint16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f64( LogEntry *obj, const char * arg0, int16_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f65( LogEntry *obj, const char * arg0, uint32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f66( LogEntry *obj, const char * arg0, int32_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f67( LogEntry *obj, const char * arg0, uint64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f68( LogEntry *obj, const char * arg0, int64_t arg1) {return obj->variable(arg0, arg1);}
LogEntry & f69( LogEntry *obj, const char * arg0, bool arg1) {return obj->variable(arg0, arg1);}
LogEntry & f70( LogEntry *obj, const char * arg0, float arg1) {return obj->variable(arg0, arg1);}
LogEntry & f71( LogEntry *obj, const char * arg0, double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f72( LogEntry *obj, const char * arg0, long double arg1) {return obj->variable(arg0, arg1);}
LogEntry & f73( LogEntry *obj, const char * arg0, const char * arg1) {return obj->variable(arg0, arg1);}
LogEntry & f74( LogEntry *obj, const char * arg0, const String & arg1) {return obj->variable(arg0, arg1);}
LogEntry & f75( LogEntry *obj) {return obj->printBacktrace();}
LogEntry & f76( LogEntry *obj, unsigned int arg0, const char ** arg1) {return obj->printBacktrace(arg0, arg1);}
int f77( LogEntry *obj) {return obj->end();}
int f78( LogEntry *obj) {return obj->fatalEnd();}
void f79( Light *obj, size_t arg0, GfxShadowmapPrecision arg1) { obj->addShadowmap(arg0, arg1);}
float f80(const Light *obj, float arg0) {return obj->getPointLightInfluence(arg0);}
float f81(const Light *obj, float arg0) {return obj->getSpotLightInfluence(arg0);}
void f82( Light *obj, GfxRenderer * arg0) { obj->updateMatrices(arg0);}
void f83( PhysicsShape *obj) { obj->setEmpty();}
void f84( PhysicsShape *obj, float arg0) { obj->setSphere(arg0);}
void f85( PhysicsShape *obj, const Vector3D & arg0) { obj->setBox(arg0);}
void f86( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2) { obj->setCylinder(arg0, arg1, arg2);}
void f87( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2) { obj->setCapsule(arg0, arg1, arg2);}
void f88( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2) { obj->setCone(arg0, arg1, arg2);}
void f89( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setConvexHull(arg0, arg1);}
void f90( PhysicsShape *obj, size_t arg0, const Position3D * arg1) { obj->setStaticTriangleMesh(arg0, arg1);}
void f91( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2) { obj->setHeightfield(arg0, arg1, arg2);}
void f92( PhysicsShape *obj, const Vector3D & arg0, float arg1) { obj->setPlane(arg0, arg1);}
void f93( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1) { obj->setCompound(arg0, arg1);}
bool f94(const Serializable *obj, const Serializable & arg0) {return obj->operator==(arg0);}
void f95( Serializable *obj, File * arg0) { obj->writeToFile(arg0);}
void f96( Serializable *obj, File * arg0) { obj->readFromFile(arg0);}
void f97( Resource *obj) { obj->load();}
void f98( GfxAnimationState *obj) { obj->updateMatrices();}
void f99( GfxAnimationState *obj, GfxMesh * arg0, const String & arg1) {new (obj) GfxAnimationState(arg0, arg1);}
void f100( GfxAnimationState *obj) { obj->~GfxAnimationState();}
bool f101( GuiPlacer *obj, const char * arg0, size_t arg1, size_t arg2) {return obj->button(arg0, arg1, arg2);}
void f102( GuiPlacer *obj, const char * arg0) { obj->label(arg0);}
GuiPlacer f103( GuiPlacer *obj, size_t arg0, size_t arg1) {return obj->placer(arg0, arg1);}
void f104( GuiPlacer *obj) { obj->advanceY();}
void f105( GuiPlacer *obj, const GuiPlacer & arg0) { obj->advanceY(arg0);}
void f106( GuiPlacer *obj) { obj->resetY();}
void f107( GuiPlacer *obj, XOrigin arg0, int arg1) { obj->setXOrigin(arg0, arg1);}
void f108( GuiPlacer *obj, ImGui * arg0, int arg1, int arg2, size_t arg3) {new (obj) GuiPlacer(arg0, arg1, arg2, arg3);}
void f109( GfxTexture *obj, GfxTextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexPurpose arg6, GfxTexFormat arg7) { obj->startCreation(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void f110( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, const void * arg3) { obj->allocMipmapFace(arg0, arg1, arg2, arg3);}
void f111( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2) { obj->allocMipmap(arg0, arg1, arg2);}
void f112(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, void * arg3) { obj->getMipmapFace(arg0, arg1, arg2, arg3);}
void f113(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2) { obj->getMipmap(arg0, arg1, arg2);}
void f114( GfxTexture *obj) { obj->generateMipmaps();}
void f115( GfxTexture *obj, float arg0) { obj->setMaximumAnisotropy(arg0);}
void f116( GfxTexture *obj, GfxFilter arg0) { obj->setMinFilter(arg0);}
void f117( GfxTexture *obj, GfxFilter arg0) { obj->setMagFilter(arg0);}
void f118( GfxTexture *obj, GfxMipmapMode arg0) { obj->setMipmapMode(arg0);}
void f119( GfxTexture *obj, GfxWrapMode arg0) { obj->setWrapMode(arg0);}
void f120( GfxTexture *obj, bool arg0) { obj->setShadowmap(arg0);}
Transform f121( GhostObject *obj) {return obj->getTransform();}
void f122(const GhostObject *obj, const Transform & arg0) { obj->setTransform(arg0);}
void f123( GhostObject *obj, PhysicsShape * arg0) { obj->setShape(arg0);}
void f124(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1) { obj->getCollisions(arg0, arg1);}
void f125( ImGui *obj, int arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, Float3 arg8, Float4 arg9) { obj->rectangle(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);}
void f126( ImGui *obj, int arg0, int arg1, int arg2, int arg3, Container * arg4) { obj->beginContainer(arg0, arg1, arg2, arg3, arg4);}
void f127( ImGui *obj, Container * arg0) { obj->endContainer(arg0);}
void f128( ImGui *obj, int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6) { obj->verticalScrollBar(arg0, arg1, arg2, arg3, arg4, arg5, arg6);}
void f129( ImGui *obj, int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6) { obj->horizontalScrollBar(arg0, arg1, arg2, arg3, arg4, arg5, arg6);}
bool f130( ImGui *obj, const char * arg0, int arg1, int arg2, int arg3, int arg4) {return obj->button(arg0, arg1, arg2, arg3, arg4);}
size_t f131( ImGui *obj, const char * arg0, int arg1, int arg2, bool arg3, bool arg4) {return obj->label(arg0, arg1, arg2, arg3, arg4);}
void f132( ImGui *obj) { obj->render();}
void f133( ImGui *obj) {new (obj) ImGui();}
void f134( ImGui *obj) { obj->~ImGui();}
void f135( Application *obj) { obj->mainloop();}
void f136( Application *obj, const char * arg0) {new (obj) Application(arg0);}
void f137( Application *obj) { obj->~Application();}
void f138( Scene *obj) { obj->handleInput();}
void f139( Scene *obj) { obj->update();}
void f140( Scene *obj, float arg0) { obj->fixedUpdate(arg0);}
void f141( Scene *obj) { obj->render();}
Entity * f142( Scene *obj, const String & arg0) {return obj->createEntity(arg0);}
void f143( Scene *obj, size_t arg0) { obj->removeEntity(arg0);}
RigidBody * f144( Entity *obj, const RigidBodyConstructionInfo & arg0, PhysicsShape * arg1) {return obj->addRigidBody(arg0, arg1);}
Scene * f145(const Entity *obj) {return obj->getScene();}
Entity * f146( Entity *obj, const String & arg0) {return obj->createEntity(arg0);}
void f147( Entity *obj, size_t arg0) { obj->removeEntity(arg0);}
void f148( Entity *obj) { obj->updateFinalTransform();}
AudioSource * f149( Entity *obj, Audio * arg0) {return obj->addAudioSource(arg0);}
void f150( Entity *obj, size_t arg0) { obj->removeAudioSource(arg0);}
void f151( File *obj, size_t arg0, void * arg1) { obj->read(arg0, arg1);}
void f152( File *obj, size_t arg0, const void * arg1) { obj->write(arg0, arg1);}
void f153( File *obj, long arg0, FileOrigin arg1) { obj->seek(arg0, arg1);}
long f154( File *obj) {return obj->tell();}
void f155( File *obj) { obj->flush();}
bool f156( File *obj) {return obj->isAtEndOfFile();}
size_t f157( File *obj) {return obj->getSize();}
uint8_t f158( File *obj) {return obj->readUInt8();}
int8_t f159( File *obj) {return obj->readInt8();}
uint16_t f160( File *obj) {return obj->readUInt16LE();}
int16_t f161( File *obj) {return obj->readInt16LE();}
uint32_t f162( File *obj) {return obj->readUInt32LE();}
int32_t f163( File *obj) {return obj->readInt32LE();}
uint64_t f164( File *obj) {return obj->readUInt64LE();}
int64_t f165( File *obj) {return obj->readInt64LE();}
uint16_t f166( File *obj) {return obj->readUInt16BE();}
int16_t f167( File *obj) {return obj->readInt16BE();}
uint32_t f168( File *obj) {return obj->readUInt32BE();}
int32_t f169( File *obj) {return obj->readInt32BE();}
uint64_t f170( File *obj) {return obj->readUInt64BE();}
int64_t f171( File *obj) {return obj->readInt64BE();}
float f172( File *obj) {return obj->readFloat32();}
char f173( File *obj) {return obj->readChar();}
void f174( File *obj, uint8_t arg0) { obj->writeUInt8(arg0);}
void f175( File *obj, int8_t arg0) { obj->writeInt8(arg0);}
void f176( File *obj, uint16_t arg0) { obj->writeUInt16LE(arg0);}
void f177( File *obj, int16_t arg0) { obj->writeInt16LE(arg0);}
void f178( File *obj, uint32_t arg0) { obj->writeUInt32LE(arg0);}
void f179( File *obj, int32_t arg0) { obj->writeInt32LE(arg0);}
void f180( File *obj, uint64_t arg0) { obj->writeUInt64LE(arg0);}
void f181( File *obj, int64_t arg0) { obj->writeInt64LE(arg0);}
void f182( File *obj, uint16_t arg0) { obj->writeUInt16BE(arg0);}
void f183( File *obj, int16_t arg0) { obj->writeInt16BE(arg0);}
void f184( File *obj, uint32_t arg0) { obj->writeUInt32BE(arg0);}
void f185( File *obj, int32_t arg0) { obj->writeInt32BE(arg0);}
void f186( File *obj, uint64_t arg0) { obj->writeUInt64BE(arg0);}
void f187( File *obj, int64_t arg0) { obj->writeInt64BE(arg0);}
void f188( File *obj, float arg0) { obj->writeFloat32(arg0);}
void f189( File *obj, const char * arg0, va_list arg1) { obj->vprintf(arg0, arg1);}
void f190( File *obj, char arg0) { obj->writeChar(arg0);}
void f191( File *obj, const char * arg0, const char * arg1) {new (obj) File(arg0, arg1);}
void f192( File *obj) { obj->~File();}
Matrix3x3 f193(const Matrix3x3 *obj, const Matrix3x3 & arg0) {return obj->operator*(arg0);}
Float3 f194(const Matrix3x3 *obj, const Float3 & arg0) {return obj->operator*(arg0);}
Matrix3x3 f195(const Matrix3x3 *obj, float arg0) {return obj->operator/(arg0);}
Matrix3x3 f196(const Matrix3x3 *obj) {return obj->transpose();}
Matrix3x3 f197(const Matrix3x3 *obj) {return obj->inverse();}
Matrix3x3 f198(const Float2 & arg0) {return Matrix3x3::translate(arg0);}
Matrix3x3 f199(const Float3 & arg0) {return Matrix3x3::scale(arg0);}
Matrix3x3 f200(float arg0) {return Matrix3x3::rotate(arg0);}
Matrix3x3 f201(float arg0) {return Matrix3x3::rotatex(arg0);}
Matrix3x3 f202(float arg0) {return Matrix3x3::rotatey(arg0);}
Matrix3x3 f203(float arg0) {return Matrix3x3::rotatez(arg0);}
void f204( Matrix3x3 *obj) {new (obj) Matrix3x3();}
void f205( Matrix3x3 *obj, const Matrix4x4 & arg0) {new (obj) Matrix3x3(arg0);}
void f206( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {new (obj) Matrix3x3(arg0, arg1, arg2);}
size_t f207( Font *obj, size_t arg0, const char * arg1) {return obj->predictWidth(arg0, arg1);}
void f208( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4) { obj->render(arg0, arg1, arg2, arg3, arg4);}
void f209( GfxDebugDrawer *obj, const Camera & arg0) { obj->render(arg0);}
void f210( GfxDebugDrawer *obj, GfxApi * arg0) {new (obj) GfxDebugDrawer(arg0);}
void f211( GfxDebugDrawer *obj) { obj->~GfxDebugDrawer();}
AudioSource *f212(Audio * arg0) {return NEW(AudioSource, arg0);}
Script *f213() {return NEW(Script);}
Script *f214(size_t count) {return NEW_ARRAY(Script, count);}
Script *f215(const String & arg0) {return NEW(Script, arg0);}
Transform *f216() {return NEW(Transform);}
Transform *f217(size_t count) {return NEW_ARRAY(Transform, count);}
Platform *f218() {return NEW(Platform);}
Platform *f219(size_t count) {return NEW_ARRAY(Platform, count);}
AudioDevice *f220(size_t arg0, size_t arg1, size_t arg2) {return NEW(AudioDevice, arg0, arg1, arg2);}
GfxMaterial *f221() {return NEW(GfxMaterial);}
GfxMaterial *f222(size_t count) {return NEW_ARRAY(GfxMaterial, count);}
GfxMaterial *f223(const String & arg0) {return NEW(GfxMaterial, arg0);}
SerializeException *f224(const char * arg0, size_t arg1, const char * arg2) {return NEW(SerializeException, arg0, arg1, arg2);}
LookupException *f225(const char * arg0, size_t arg1, const char * arg2) {return NEW(LookupException, arg0, arg1, arg2);}
Quaternion *f226() {return NEW(Quaternion);}
Quaternion *f227(size_t count) {return NEW_ARRAY(Quaternion, count);}
Quaternion *f228(const Direction3D & arg0, float arg1) {return NEW(Quaternion, arg0, arg1);}
Quaternion *f229(float arg0, float arg1, float arg2, float arg3) {return NEW(Quaternion, arg0, arg1, arg2, arg3);}
Quaternion *f230(const Float3 & arg0) {return NEW(Quaternion, arg0);}
Light *f231() {return NEW(Light);}
Light *f232(size_t count) {return NEW_ARRAY(Light, count);}
PhysicsShape *f233() {return NEW(PhysicsShape);}
PhysicsShape *f234(size_t count) {return NEW_ARRAY(PhysicsShape, count);}
PhysicsShape *f235(const String & arg0) {return NEW(PhysicsShape, arg0);}
Serializable *f236() {return NEW(Serializable);}
Serializable *f237(size_t count) {return NEW_ARRAY(Serializable, count);}
Serializable *f238(uint8_t arg0) {return NEW(Serializable, arg0);}
Serializable *f239(int8_t arg0) {return NEW(Serializable, arg0);}
Serializable *f240(uint16_t arg0) {return NEW(Serializable, arg0);}
Serializable *f241(int16_t arg0) {return NEW(Serializable, arg0);}
Serializable *f242(uint32_t arg0) {return NEW(Serializable, arg0);}
Serializable *f243(int32_t arg0) {return NEW(Serializable, arg0);}
Serializable *f244(uint64_t arg0) {return NEW(Serializable, arg0);}
Serializable *f245(int64_t arg0) {return NEW(Serializable, arg0);}
Serializable *f246(const String & arg0) {return NEW(Serializable, arg0);}
Serializable *f247(bool arg0) {return NEW(Serializable, arg0);}
Serializable *f248(float arg0) {return NEW(Serializable, arg0);}
Serializable *f249(const Float2 & arg0) {return NEW(Serializable, arg0);}
Serializable *f250(const Float3 & arg0) {return NEW(Serializable, arg0);}
Serializable *f251(const Float4 & arg0) {return NEW(Serializable, arg0);}
Serializable *f252(const Int2 & arg0) {return NEW(Serializable, arg0);}
Serializable *f253(const Int3 & arg0) {return NEW(Serializable, arg0);}
Serializable *f254(const Int4 & arg0) {return NEW(Serializable, arg0);}
Serializable *f255(const UInt2 & arg0) {return NEW(Serializable, arg0);}
Serializable *f256(const UInt3 & arg0) {return NEW(Serializable, arg0);}
Serializable *f257(const UInt4 & arg0) {return NEW(Serializable, arg0);}
ShaderCompileException *f258(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return NEW(ShaderCompileException, arg0, arg1, arg2, arg3);}
Exception *f259(const char * arg0, size_t arg1, const char * arg2) {return NEW(Exception, arg0, arg1, arg2);}
FileException *f260(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return NEW(FileException, arg0, arg1, arg2, arg3, arg4);}
AABB *f261() {return NEW(AABB);}
AABB *f262(size_t count) {return NEW_ARRAY(AABB, count);}
AABB *f263(const Position3D & arg0, const Position3D & arg1) {return NEW(AABB, arg0, arg1);}
ResourceIOException *f264(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return NEW(ResourceIOException, arg0, arg1, arg2, arg3, arg4, arg5);}
GfxAnimationState *f265(GfxMesh * arg0, const String & arg1) {return NEW(GfxAnimationState, arg0, arg1);}
GuiPlacer *f266(ImGui * arg0, int arg1, int arg2, size_t arg3) {return NEW(GuiPlacer, arg0, arg1, arg2, arg3);}
Audio *f267() {return NEW(Audio);}
Audio *f268(size_t count) {return NEW_ARRAY(Audio, count);}
Audio *f269(const String & arg0) {return NEW(Audio, arg0);}
GfxTexture *f270(const String & arg0) {return NEW(GfxTexture, arg0);}
GfxTexture *f271() {return NEW(GfxTexture);}
GfxTexture *f272(size_t count) {return NEW_ARRAY(GfxTexture, count);}
PhysicsDebugDrawer *f273() {return NEW(PhysicsDebugDrawer);}
PhysicsDebugDrawer *f274(size_t count) {return NEW_ARRAY(PhysicsDebugDrawer, count);}
ImGui *f275() {return NEW(ImGui);}
ImGui *f276(size_t count) {return NEW_ARRAY(ImGui, count);}
Application *f277(const char * arg0) {return NEW(Application, arg0);}
GfxModel *f278() {return NEW(GfxModel);}
GfxModel *f279(size_t count) {return NEW_ARRAY(GfxModel, count);}
GfxModel *f280(const String & arg0) {return NEW(GfxModel, arg0);}
Scene *f281() {return NEW(Scene);}
Scene *f282(size_t count) {return NEW_ARRAY(Scene, count);}
Scene *f283(const String & arg0) {return NEW(Scene, arg0);}
File *f284(const char * arg0, const char * arg1) {return NEW(File, arg0, arg1);}
Matrix3x3 *f285() {return NEW(Matrix3x3);}
Matrix3x3 *f286(size_t count) {return NEW_ARRAY(Matrix3x3, count);}
Matrix3x3 *f287(const Matrix4x4 & arg0) {return NEW(Matrix3x3, arg0);}
Matrix3x3 *f288(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return NEW(Matrix3x3, arg0, arg1, arg2);}
Font *f289() {return NEW(Font);}
Font *f290(size_t count) {return NEW_ARRAY(Font, count);}
Font *f291(const String & arg0) {return NEW(Font, arg0);}
GfxDebugDrawer *f292(GfxApi * arg0) {return NEW(GfxDebugDrawer, arg0);}
static const _functionStruct functions = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64, f65, f66, f67, f68, f69, f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f80, f81, f82, f83, f84, f85, f86, f87, f88, f89, f90, f91, f92, f93, f94, f95, f96, f97, f98, f99, f100, f101, f102, f103, f104, f105, f106, f107, f108, f109, f110, f111, f112, f113, f114, f115, f116, f117, f118, f119, f120, f121, f122, f123, f124, f125, f126, f127, f128, f129, f130, f131, f132, f133, f134, f135, f136, f137, f138, f139, f140, f141, f142, f143, f144, f145, f146, f147, f148, f149, f150, f151, f152, f153, f154, f155, f156, f157, f158, f159, f160, f161, f162, f163, f164, f165, f166, f167, f168, f169, f170, f171, f172, f173, f174, f175, f176, f177, f178, f179, f180, f181, f182, f183, f184, f185, f186, f187, f188, f189, f190, f191, f192, f193, f194, f195, f196, f197, f198, f199, f200, f201, f202, f203, f204, f205, f206, f207, f208, f209, f210, f211, f212, f213, f214, f215, f216, f217, f218, f219, f220, f221, f222, f223, f224, f225, f226, f227, f228, f229, f230, f231, f232, f233, f234, f235, f236, f237, f238, f239, f240, f241, f242, f243, f244, f245, f246, f247, f248, f249, f250, f251, f252, f253, f254, f255, f256, f257, f258, f259, f260, f261, f262, f263, f264, f265, f266, f267, f268, f269, f270, f271, f272, f273, f274, f275, f276, f277, f278, f279, f280, f281, f282, f283, f284, f285, f286, f287, f288, f289, f290, f291, f292};
const void *getScriptFunctionStruct() {return &functions;}