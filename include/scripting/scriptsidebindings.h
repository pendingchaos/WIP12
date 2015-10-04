//Generated from script_binding_generator.py. Do not edit. Edit script_binding_generator.py instead.
#ifdef _SCRIPT_SIDE_IMPLS
struct _functionStruct
{
    const char ** (*f0)(unsigned int & arg0);
    size_t (*f1)(const String & arg0);
    bool (*f2)(const char * arg0);
    List<String> (*f3)(const char * arg0);
    void (*f4)(Application * arg0);
    ScriptInstance * (*f5)( Script *obj, Entity * arg0, Scene * arg1);
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
    void (*f80)( Light *obj);
    float (*f81)(const Light *obj, float arg0);
    float (*f82)(const Light *obj, float arg0);
    void (*f83)( Light *obj, GfxRenderer * arg0);
    void (*f84)( PhysicsShape *obj);
    void (*f85)( PhysicsShape *obj, float arg0);
    void (*f86)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f87)( PhysicsShape *obj, Axis arg0, float arg1, float arg2);
    void (*f88)( PhysicsShape *obj, Axis arg0, float arg1, float arg2);
    void (*f89)( PhysicsShape *obj, Axis arg0, float arg1, float arg2);
    void (*f90)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f91)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f92)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f93)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f94)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    void (*f95)( Resource *obj);
    void (*f96)( GfxAnimationState *obj);
    void (*f97)( GfxAnimationState *obj, GfxMesh * arg0, const String & arg1);
    void (*f98)( GfxAnimationState *obj);
    bool (*f99)( GuiPlacer *obj, const char * arg0, size_t arg1, size_t arg2);
    void (*f100)( GuiPlacer *obj, const char * arg0);
    GuiPlacer (*f101)( GuiPlacer *obj, size_t arg0, size_t arg1);
    void (*f102)( GuiPlacer *obj);
    void (*f103)( GuiPlacer *obj, const GuiPlacer & arg0);
    void (*f104)( GuiPlacer *obj);
    void (*f105)( GuiPlacer *obj, XOrigin arg0, int arg1);
    void (*f106)( GuiPlacer *obj, ImGui * arg0, int arg1, int arg2, size_t arg3);
    void (*f107)( GfxTexture *obj, GfxTextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexPurpose arg6, GfxTexFormat arg7);
    void (*f108)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, const void * arg3);
    void (*f109)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f110)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, void * arg3);
    void (*f111)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f112)( GfxTexture *obj);
    void (*f113)( GfxTexture *obj, float arg0);
    void (*f114)( GfxTexture *obj, GfxFilter arg0);
    void (*f115)( GfxTexture *obj, GfxFilter arg0);
    void (*f116)( GfxTexture *obj, GfxMipmapMode arg0);
    void (*f117)( GfxTexture *obj, GfxWrapMode arg0);
    void (*f118)( GfxTexture *obj, bool arg0);
    Transform (*f119)( GhostObject *obj);
    void (*f120)(const GhostObject *obj, const Transform & arg0);
    void (*f121)( GhostObject *obj, PhysicsShape * arg0);
    void (*f122)(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1);
    void (*f123)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, Float3 arg8, Float4 arg9);
    void (*f124)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, Container * arg4);
    void (*f125)( ImGui *obj, Container * arg0);
    void (*f126)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6);
    void (*f127)( ImGui *obj, int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6);
    bool (*f128)( ImGui *obj, const char * arg0, int arg1, int arg2, int arg3, int arg4);
    size_t (*f129)( ImGui *obj, const char * arg0, int arg1, int arg2, bool arg3, bool arg4);
    void (*f130)( ImGui *obj);
    void (*f131)( ImGui *obj);
    void (*f132)( ImGui *obj);
    void (*f133)( Application *obj);
    void (*f134)( Application *obj, const char * arg0);
    void (*f135)( Application *obj);
    void (*f136)( Scene *obj);
    void (*f137)( Scene *obj);
    void (*f138)( Scene *obj, float arg0);
    void (*f139)( Scene *obj);
    Entity * (*f140)( Scene *obj, const String & arg0);
    void (*f141)( Scene *obj, size_t arg0);
    scripting::Value * (*f142)(const Entity *obj, const String & arg0);
    RigidBody * (*f143)( Entity *obj, const RigidBodyConstructionInfo & arg0, PhysicsShape * arg1);
    Entity * (*f144)( Entity *obj, const String & arg0);
    void (*f145)( Entity *obj, size_t arg0);
    void (*f146)( Entity *obj);
    AudioSource * (*f147)( Entity *obj, Audio * arg0);
    void (*f148)( Entity *obj, size_t arg0);
    void (*f149)( File *obj, size_t arg0, void * arg1);
    void (*f150)( File *obj, size_t arg0, const void * arg1);
    void (*f151)( File *obj, long arg0, FileOrigin arg1);
    long (*f152)( File *obj);
    void (*f153)( File *obj);
    bool (*f154)( File *obj);
    size_t (*f155)( File *obj);
    uint8_t (*f156)( File *obj);
    int8_t (*f157)( File *obj);
    uint16_t (*f158)( File *obj);
    int16_t (*f159)( File *obj);
    uint32_t (*f160)( File *obj);
    int32_t (*f161)( File *obj);
    uint64_t (*f162)( File *obj);
    int64_t (*f163)( File *obj);
    uint16_t (*f164)( File *obj);
    int16_t (*f165)( File *obj);
    uint32_t (*f166)( File *obj);
    int32_t (*f167)( File *obj);
    uint64_t (*f168)( File *obj);
    int64_t (*f169)( File *obj);
    float (*f170)( File *obj);
    char (*f171)( File *obj);
    void (*f172)( File *obj, uint8_t arg0);
    void (*f173)( File *obj, int8_t arg0);
    void (*f174)( File *obj, uint16_t arg0);
    void (*f175)( File *obj, int16_t arg0);
    void (*f176)( File *obj, uint32_t arg0);
    void (*f177)( File *obj, int32_t arg0);
    void (*f178)( File *obj, uint64_t arg0);
    void (*f179)( File *obj, int64_t arg0);
    void (*f180)( File *obj, uint16_t arg0);
    void (*f181)( File *obj, int16_t arg0);
    void (*f182)( File *obj, uint32_t arg0);
    void (*f183)( File *obj, int32_t arg0);
    void (*f184)( File *obj, uint64_t arg0);
    void (*f185)( File *obj, int64_t arg0);
    void (*f186)( File *obj, float arg0);
    void (*f187)( File *obj, const char * arg0, va_list arg1);
    void (*f188)( File *obj, char arg0);
    void (*f189)( File *obj, const char * arg0, const char * arg1);
    void (*f190)( File *obj);
    Matrix3x3 (*f191)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f192)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f193)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f194)(const Matrix3x3 *obj);
    Matrix3x3 (*f195)(const Matrix3x3 *obj);
    Matrix3x3 (*f196)(const Float2 & arg0);
    Matrix3x3 (*f197)(const Float3 & arg0);
    Matrix3x3 (*f198)(float arg0);
    Matrix3x3 (*f199)(float arg0);
    Matrix3x3 (*f200)(float arg0);
    Matrix3x3 (*f201)(float arg0);
    void (*f202)( Matrix3x3 *obj);
    void (*f203)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f204)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    size_t (*f205)(const Font *obj, size_t arg0, const char * arg1);
    void (*f206)(const Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4);
    void (*f207)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f208)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f209)( GfxDebugDrawer *obj);
    AudioSource *(*f210)(Audio * arg0);
    Script *(*f211)();
    Script *(*f212)(size_t count);
    Script *(*f213)(const String & arg0);
    Transform *(*f214)();
    Transform *(*f215)(size_t count);
    Platform *(*f216)();
    Platform *(*f217)(size_t count);
    AudioDevice *(*f218)(size_t arg0, size_t arg1, size_t arg2);
    GfxMaterial *(*f219)();
    GfxMaterial *(*f220)(size_t count);
    GfxMaterial *(*f221)(const String & arg0);
    LookupException *(*f222)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f223)();
    Quaternion *(*f224)(size_t count);
    Quaternion *(*f225)(const Direction3D & arg0, float arg1);
    Quaternion *(*f226)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f227)(const Float3 & arg0);
    Light *(*f228)();
    Light *(*f229)(size_t count);
    PhysicsShape *(*f230)();
    PhysicsShape *(*f231)(size_t count);
    PhysicsShape *(*f232)(const String & arg0);
    ShaderCompileException *(*f233)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f234)(const char * arg0, size_t arg1, const char * arg2);
    FileException *(*f235)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    AABB *(*f236)();
    AABB *(*f237)(size_t count);
    AABB *(*f238)(const Position3D & arg0, const Position3D & arg1);
    ResourceIOException *(*f239)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxAnimationState *(*f240)(GfxMesh * arg0, const String & arg1);
    GuiPlacer *(*f241)(ImGui * arg0, int arg1, int arg2, size_t arg3);
    Audio *(*f242)();
    Audio *(*f243)(size_t count);
    Audio *(*f244)(const String & arg0);
    GfxTexture *(*f245)(const String & arg0);
    GfxTexture *(*f246)();
    GfxTexture *(*f247)(size_t count);
    PhysicsDebugDrawer *(*f248)();
    PhysicsDebugDrawer *(*f249)(size_t count);
    ImGui *(*f250)();
    ImGui *(*f251)(size_t count);
    Application *(*f252)(const char * arg0);
    GfxModel *(*f253)();
    GfxModel *(*f254)(size_t count);
    GfxModel *(*f255)(const String & arg0);
    Scene *(*f256)();
    Scene *(*f257)(size_t count);
    Scene *(*f258)(const String & arg0);
    File *(*f259)(const char * arg0, const char * arg1);
    Matrix3x3 *(*f260)();
    Matrix3x3 *(*f261)(size_t count);
    Matrix3x3 *(*f262)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f263)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    Font *(*f264)();
    Font *(*f265)(size_t count);
    Font *(*f266)(const String & arg0);
    GfxDebugDrawer *(*f267)(GfxApi * arg0);
};
const _functionStruct *_functions;
const char ** getBacktrace(unsigned int & arg0) {return _functions->f0(arg0);}
size_t getHash(const String & arg0) {return _functions->f1(arg0);}
bool doesFileExist(const char * arg0) {return _functions->f2(arg0);}
List<String> listFiles(const char * arg0) {return _functions->f3(arg0);}
void setApplication(Application * arg0) { _functions->f4(arg0);}
ScriptInstance * Script::createInstance(Entity * arg0, Scene * arg1)  {return _functions->f5(this, arg0, arg1);}
Matrix4x4 Transform::createMatrix() const {return _functions->f6(this);}
 Transform::Transform()  { _functions->f7(this);}
void Platform::initWindow(uint32_t arg0, uint32_t arg1)  { _functions->f8(this, arg0, arg1);}
void Platform::destroyWindow()  { _functions->f9(this);}
bool Platform::pollEvent(Event & arg0)  {return _functions->f10(this, arg0);}
bool Platform::eventsLeft() const {return _functions->f11(this);}
uint64_t Platform::getTime() const {return _functions->f12(this);}
uint64_t Platform::getTimerFrequency() const {return _functions->f13(this);}
size_t Platform::getWindowWidth() const {return _functions->f14(this);}
size_t Platform::getWindowHeight() const {return _functions->f15(this);}
Int2 Platform::getMousePosition() const {return _functions->f16(this);}
void Platform::setMousePosition(Int2 arg0)  { _functions->f17(this, arg0);}
bool Platform::isLeftMouseButtonPressed() const {return _functions->f18(this);}
bool Platform::isRightMouseButtonPressed() const {return _functions->f19(this);}
bool Platform::isMiddleMouseButtonPressed() const {return _functions->f20(this);}
Int2 Platform::getMouseWheel() const {return _functions->f21(this);}
bool Platform::isCursorVisible() const {return _functions->f22(this);}
void Platform::setCursorVisible(bool arg0) const { _functions->f23(this, arg0);}
bool Platform::isKeyPressed(Key arg0) const {return _functions->f24(this, arg0);}
bool Platform::getFullscreen() const {return _functions->f25(this);}
void Platform::setFullscreen(bool arg0)  { _functions->f26(this, arg0);}
String AudioDevice::getName()  {return _functions->f27(this);}
String AudioDevice::getName(size_t arg0)  {return _functions->f28(arg0);}
size_t AudioDevice::getDeviceCount()  {return _functions->f29();}
void AudioDevice::setIndex(size_t arg0)  { _functions->f30(this, arg0);}
void AudioDevice::setFrequency(size_t arg0)  { _functions->f31(this, arg0);}
void AudioDevice::setSamples(size_t arg0)  { _functions->f32(this, arg0);}
void AudioDevice::pause()  { _functions->f33(this);}
void AudioDevice::play()  { _functions->f34(this);}
bool AudioDevice::getPaused()  {return _functions->f35(this);}
void AudioDevice::runCallbacks(size_t arg0)  { _functions->f36(this, arg0);}
 AudioDevice::AudioDevice(size_t arg0, size_t arg1, size_t arg2)  { _functions->f37(this, arg0, arg1, arg2);}
 AudioDevice::~AudioDevice()  { _functions->f38(this);}
void GfxMaterial::setDisplacementMap(GfxTexture * arg0)  { _functions->f39(this, arg0);}
void GfxMaterial::setForward(bool arg0)  { _functions->f40(this, arg0);}
void GfxRenderer::resize(const UInt2 & arg0)  { _functions->f41(this, arg0);}
void GfxRenderer::render()  { _functions->f42(this);}
AABB GfxRenderer::computeSceneAABB() const {return _functions->f43(this);}
AABB GfxRenderer::computeShadowCasterAABB() const {return _functions->f44(this);}
void GfxRenderer::updateStats()  { _functions->f45(this);}
void GfxRenderer::updateColorModifierShader()  { _functions->f46(this);}
GfxTerrain * GfxRenderer::addTerrain(float arg0, size_t arg1, GfxTexture * arg2)  {return _functions->f47(this, arg0, arg1, arg2);}
void GfxRenderer::removeTerrain()  { _functions->f48(this);}
 GfxRenderer::~GfxRenderer()  { _functions->f49(this);}
Quaternion Quaternion::operator*(const Quaternion & arg0) const {return _functions->f50(this, arg0);}
Matrix4x4 Quaternion::toMatrix() const {return _functions->f51(this);}
Float4 Quaternion::getAxisAndAngle() const {return _functions->f52(this);}
void Quaternion::setAxis(const Direction3D & arg0)  { _functions->f53(this, arg0);}
void Quaternion::setAxisAndAngle(const Direction3D & arg0, float arg1)  { _functions->f54(this, arg0, arg1);}
void Quaternion::setEulerAngles(const Float3 & arg0)  { _functions->f55(this, arg0);}
Float3 Quaternion::getEulerAngles()  {return _functions->f56(this);}
 Quaternion::Quaternion()  { _functions->f57(this);}
 Quaternion::Quaternion(const Direction3D & arg0, float arg1)  { _functions->f58(this, arg0, arg1);}
 Quaternion::Quaternion(float arg0, float arg1, float arg2, float arg3)  { _functions->f59(this, arg0, arg1, arg2, arg3);}
 Quaternion::Quaternion(const Float3 & arg0)  { _functions->f60(this, arg0);}
LogEntry & LogEntry::variable(const char * arg0, uint8_t arg1)  {return _functions->f61(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int8_t arg1)  {return _functions->f62(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint16_t arg1)  {return _functions->f63(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int16_t arg1)  {return _functions->f64(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint32_t arg1)  {return _functions->f65(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int32_t arg1)  {return _functions->f66(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint64_t arg1)  {return _functions->f67(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int64_t arg1)  {return _functions->f68(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, bool arg1)  {return _functions->f69(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, float arg1)  {return _functions->f70(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, double arg1)  {return _functions->f71(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, long double arg1)  {return _functions->f72(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const char * arg1)  {return _functions->f73(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const String & arg1)  {return _functions->f74(this, arg0, arg1);}
LogEntry & LogEntry::printBacktrace()  {return _functions->f75(this);}
LogEntry & LogEntry::printBacktrace(unsigned int arg0, const char ** arg1)  {return _functions->f76(this, arg0, arg1);}
int LogEntry::end()  {return _functions->f77(this);}
int LogEntry::fatalEnd()  {return _functions->f78(this);}
void Light::addShadowmap(size_t arg0, GfxShadowmapPrecision arg1)  { _functions->f79(this, arg0, arg1);}
void Light::removeShadowmap()  { _functions->f80(this);}
float Light::getPointLightInfluence(float arg0) const {return _functions->f81(this, arg0);}
float Light::getSpotLightInfluence(float arg0) const {return _functions->f82(this, arg0);}
void Light::updateMatrices(GfxRenderer * arg0)  { _functions->f83(this, arg0);}
void PhysicsShape::setEmpty()  { _functions->f84(this);}
void PhysicsShape::setSphere(float arg0)  { _functions->f85(this, arg0);}
void PhysicsShape::setBox(const Vector3D & arg0)  { _functions->f86(this, arg0);}
void PhysicsShape::setCylinder(Axis arg0, float arg1, float arg2)  { _functions->f87(this, arg0, arg1, arg2);}
void PhysicsShape::setCapsule(Axis arg0, float arg1, float arg2)  { _functions->f88(this, arg0, arg1, arg2);}
void PhysicsShape::setCone(Axis arg0, float arg1, float arg2)  { _functions->f89(this, arg0, arg1, arg2);}
void PhysicsShape::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f90(this, arg0, arg1);}
void PhysicsShape::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f91(this, arg0, arg1);}
void PhysicsShape::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f92(this, arg0, arg1, arg2);}
void PhysicsShape::setPlane(const Vector3D & arg0, float arg1)  { _functions->f93(this, arg0, arg1);}
void PhysicsShape::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f94(this, arg0, arg1);}
void Resource::load()  { _functions->f95(this);}
void GfxAnimationState::updateMatrices()  { _functions->f96(this);}
 GfxAnimationState::GfxAnimationState(GfxMesh * arg0, const String & arg1)  { _functions->f97(this, arg0, arg1);}
 GfxAnimationState::~GfxAnimationState()  { _functions->f98(this);}
bool GuiPlacer::button(const char * arg0, size_t arg1, size_t arg2)  {return _functions->f99(this, arg0, arg1, arg2);}
void GuiPlacer::label(const char * arg0)  { _functions->f100(this, arg0);}
GuiPlacer GuiPlacer::placer(size_t arg0, size_t arg1)  {return _functions->f101(this, arg0, arg1);}
void GuiPlacer::advanceY()  { _functions->f102(this);}
void GuiPlacer::advanceY(const GuiPlacer & arg0)  { _functions->f103(this, arg0);}
void GuiPlacer::resetY()  { _functions->f104(this);}
void GuiPlacer::setXOrigin(XOrigin arg0, int arg1)  { _functions->f105(this, arg0, arg1);}
 GuiPlacer::GuiPlacer(ImGui * arg0, int arg1, int arg2, size_t arg3)  { _functions->f106(this, arg0, arg1, arg2, arg3);}
void GfxTexture::startCreation(GfxTextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexPurpose arg6, GfxTexFormat arg7)  { _functions->f107(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void GfxTexture::allocMipmapFace(unsigned int arg0, unsigned int arg1, GfxFace arg2, const void * arg3)  { _functions->f108(this, arg0, arg1, arg2, arg3);}
void GfxTexture::allocMipmap(unsigned int arg0, unsigned int arg1, const void * arg2)  { _functions->f109(this, arg0, arg1, arg2);}
void GfxTexture::getMipmapFace(unsigned int arg0, unsigned int arg1, GfxFace arg2, void * arg3) const { _functions->f110(this, arg0, arg1, arg2, arg3);}
void GfxTexture::getMipmap(unsigned int arg0, unsigned int arg1, void * arg2) const { _functions->f111(this, arg0, arg1, arg2);}
void GfxTexture::generateMipmaps()  { _functions->f112(this);}
void GfxTexture::setMaximumAnisotropy(float arg0)  { _functions->f113(this, arg0);}
void GfxTexture::setMinFilter(GfxFilter arg0)  { _functions->f114(this, arg0);}
void GfxTexture::setMagFilter(GfxFilter arg0)  { _functions->f115(this, arg0);}
void GfxTexture::setMipmapMode(GfxMipmapMode arg0)  { _functions->f116(this, arg0);}
void GfxTexture::setWrapMode(GfxWrapMode arg0)  { _functions->f117(this, arg0);}
void GfxTexture::setShadowmap(bool arg0)  { _functions->f118(this, arg0);}
Transform GhostObject::getTransform()  {return _functions->f119(this);}
void GhostObject::setTransform(const Transform & arg0) const { _functions->f120(this, arg0);}
void GhostObject::setShape(PhysicsShape * arg0)  { _functions->f121(this, arg0);}
void GhostObject::getCollisions(List<RigidBody *> & arg0, List<GhostObject *> & arg1) const { _functions->f122(this, arg0, arg1);}
void ImGui::rectangle(int arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, Float3 arg8, Float4 arg9)  { _functions->f123(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);}
void ImGui::beginContainer(int arg0, int arg1, int arg2, int arg3, Container * arg4)  { _functions->f124(this, arg0, arg1, arg2, arg3, arg4);}
void ImGui::endContainer(Container * arg0)  { _functions->f125(this, arg0);}
void ImGui::verticalScrollBar(int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6)  { _functions->f126(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6);}
void ImGui::horizontalScrollBar(int arg0, int arg1, int arg2, int arg3, bool arg4, bool arg5, ScrollBar * arg6)  { _functions->f127(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6);}
bool ImGui::button(const char * arg0, int arg1, int arg2, int arg3, int arg4)  {return _functions->f128(this, arg0, arg1, arg2, arg3, arg4);}
size_t ImGui::label(const char * arg0, int arg1, int arg2, bool arg3, bool arg4)  {return _functions->f129(this, arg0, arg1, arg2, arg3, arg4);}
void ImGui::render()  { _functions->f130(this);}
 ImGui::ImGui()  { _functions->f131(this);}
 ImGui::~ImGui()  { _functions->f132(this);}
void Application::mainloop()  { _functions->f133(this);}
 Application::Application(const char * arg0)  { _functions->f134(this, arg0);}
 Application::~Application()  { _functions->f135(this);}
void Scene::handleInput()  { _functions->f136(this);}
void Scene::update()  { _functions->f137(this);}
void Scene::fixedUpdate(float arg0)  { _functions->f138(this, arg0);}
void Scene::render()  { _functions->f139(this);}
Entity * Scene::createEntity(const String & arg0)  {return _functions->f140(this, arg0);}
void Scene::removeEntity(size_t arg0)  { _functions->f141(this, arg0);}
scripting::Value * Entity::findScriptInstanceObj(const String & arg0) const {return _functions->f142(this, arg0);}
RigidBody * Entity::addRigidBody(const RigidBodyConstructionInfo & arg0, PhysicsShape * arg1)  {return _functions->f143(this, arg0, arg1);}
Entity * Entity::createEntity(const String & arg0)  {return _functions->f144(this, arg0);}
void Entity::removeEntity(size_t arg0)  { _functions->f145(this, arg0);}
void Entity::updateFinalTransform()  { _functions->f146(this);}
AudioSource * Entity::addAudioSource(Audio * arg0)  {return _functions->f147(this, arg0);}
void Entity::removeAudioSource(size_t arg0)  { _functions->f148(this, arg0);}
void File::read(size_t arg0, void * arg1)  { _functions->f149(this, arg0, arg1);}
void File::write(size_t arg0, const void * arg1)  { _functions->f150(this, arg0, arg1);}
void File::seek(long arg0, FileOrigin arg1)  { _functions->f151(this, arg0, arg1);}
long File::tell()  {return _functions->f152(this);}
void File::flush()  { _functions->f153(this);}
bool File::isAtEndOfFile()  {return _functions->f154(this);}
size_t File::getSize()  {return _functions->f155(this);}
uint8_t File::readUInt8()  {return _functions->f156(this);}
int8_t File::readInt8()  {return _functions->f157(this);}
uint16_t File::readUInt16LE()  {return _functions->f158(this);}
int16_t File::readInt16LE()  {return _functions->f159(this);}
uint32_t File::readUInt32LE()  {return _functions->f160(this);}
int32_t File::readInt32LE()  {return _functions->f161(this);}
uint64_t File::readUInt64LE()  {return _functions->f162(this);}
int64_t File::readInt64LE()  {return _functions->f163(this);}
uint16_t File::readUInt16BE()  {return _functions->f164(this);}
int16_t File::readInt16BE()  {return _functions->f165(this);}
uint32_t File::readUInt32BE()  {return _functions->f166(this);}
int32_t File::readInt32BE()  {return _functions->f167(this);}
uint64_t File::readUInt64BE()  {return _functions->f168(this);}
int64_t File::readInt64BE()  {return _functions->f169(this);}
float File::readFloat32()  {return _functions->f170(this);}
char File::readChar()  {return _functions->f171(this);}
void File::writeUInt8(uint8_t arg0)  { _functions->f172(this, arg0);}
void File::writeInt8(int8_t arg0)  { _functions->f173(this, arg0);}
void File::writeUInt16LE(uint16_t arg0)  { _functions->f174(this, arg0);}
void File::writeInt16LE(int16_t arg0)  { _functions->f175(this, arg0);}
void File::writeUInt32LE(uint32_t arg0)  { _functions->f176(this, arg0);}
void File::writeInt32LE(int32_t arg0)  { _functions->f177(this, arg0);}
void File::writeUInt64LE(uint64_t arg0)  { _functions->f178(this, arg0);}
void File::writeInt64LE(int64_t arg0)  { _functions->f179(this, arg0);}
void File::writeUInt16BE(uint16_t arg0)  { _functions->f180(this, arg0);}
void File::writeInt16BE(int16_t arg0)  { _functions->f181(this, arg0);}
void File::writeUInt32BE(uint32_t arg0)  { _functions->f182(this, arg0);}
void File::writeInt32BE(int32_t arg0)  { _functions->f183(this, arg0);}
void File::writeUInt64BE(uint64_t arg0)  { _functions->f184(this, arg0);}
void File::writeInt64BE(int64_t arg0)  { _functions->f185(this, arg0);}
void File::writeFloat32(float arg0)  { _functions->f186(this, arg0);}
void File::vprintf(const char * arg0, va_list arg1)  { _functions->f187(this, arg0, arg1);}
void File::writeChar(char arg0)  { _functions->f188(this, arg0);}
 File::File(const char * arg0, const char * arg1)  { _functions->f189(this, arg0, arg1);}
 File::~File()  { _functions->f190(this);}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & arg0) const {return _functions->f191(this, arg0);}
Float3 Matrix3x3::operator*(const Float3 & arg0) const {return _functions->f192(this, arg0);}
Matrix3x3 Matrix3x3::operator/(float arg0) const {return _functions->f193(this, arg0);}
Matrix3x3 Matrix3x3::transpose() const {return _functions->f194(this);}
Matrix3x3 Matrix3x3::inverse() const {return _functions->f195(this);}
Matrix3x3 Matrix3x3::translate(const Float2 & arg0)  {return _functions->f196(arg0);}
Matrix3x3 Matrix3x3::scale(const Float3 & arg0)  {return _functions->f197(arg0);}
Matrix3x3 Matrix3x3::rotate(float arg0)  {return _functions->f198(arg0);}
Matrix3x3 Matrix3x3::rotatex(float arg0)  {return _functions->f199(arg0);}
Matrix3x3 Matrix3x3::rotatey(float arg0)  {return _functions->f200(arg0);}
Matrix3x3 Matrix3x3::rotatez(float arg0)  {return _functions->f201(arg0);}
 Matrix3x3::Matrix3x3()  { _functions->f202(this);}
 Matrix3x3::Matrix3x3(const Matrix4x4 & arg0)  { _functions->f203(this, arg0);}
 Matrix3x3::Matrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2)  { _functions->f204(this, arg0, arg1, arg2);}
size_t Font::predictWidth(size_t arg0, const char * arg1) const {return _functions->f205(this, arg0, arg1);}
void Font::render(size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4) const { _functions->f206(this, arg0, arg1, arg2, arg3, arg4);}
void GfxDebugDrawer::render(const Camera & arg0)  { _functions->f207(this, arg0);}
 GfxDebugDrawer::GfxDebugDrawer(GfxApi * arg0)  { _functions->f208(this, arg0);}
 GfxDebugDrawer::~GfxDebugDrawer()  { _functions->f209(this);}
AudioSource *_newAudioSource(Audio * arg0) {return _functions->f210(arg0);}
Script *_newScript() {return _functions->f211();}
Script *_newArrayScript(size_t count) {return _functions->f212(count);}
Script *_newScript(const String & arg0) {return _functions->f213(arg0);}
Transform *_newTransform() {return _functions->f214();}
Transform *_newArrayTransform(size_t count) {return _functions->f215(count);}
Platform *_newPlatform() {return _functions->f216();}
Platform *_newArrayPlatform(size_t count) {return _functions->f217(count);}
AudioDevice *_newAudioDevice(size_t arg0, size_t arg1, size_t arg2) {return _functions->f218(arg0, arg1, arg2);}
GfxMaterial *_newGfxMaterial() {return _functions->f219();}
GfxMaterial *_newArrayGfxMaterial(size_t count) {return _functions->f220(count);}
GfxMaterial *_newGfxMaterial(const String & arg0) {return _functions->f221(arg0);}
LookupException *_newLookupException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f222(arg0, arg1, arg2);}
Quaternion *_newQuaternion() {return _functions->f223();}
Quaternion *_newArrayQuaternion(size_t count) {return _functions->f224(count);}
Quaternion *_newQuaternion(const Direction3D & arg0, float arg1) {return _functions->f225(arg0, arg1);}
Quaternion *_newQuaternion(float arg0, float arg1, float arg2, float arg3) {return _functions->f226(arg0, arg1, arg2, arg3);}
Quaternion *_newQuaternion(const Float3 & arg0) {return _functions->f227(arg0);}
Light *_newLight() {return _functions->f228();}
Light *_newArrayLight(size_t count) {return _functions->f229(count);}
PhysicsShape *_newPhysicsShape() {return _functions->f230();}
PhysicsShape *_newArrayPhysicsShape(size_t count) {return _functions->f231(count);}
PhysicsShape *_newPhysicsShape(const String & arg0) {return _functions->f232(arg0);}
ShaderCompileException *_newShaderCompileException(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return _functions->f233(arg0, arg1, arg2, arg3);}
Exception *_newException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f234(arg0, arg1, arg2);}
FileException *_newFileException(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return _functions->f235(arg0, arg1, arg2, arg3, arg4);}
AABB *_newAABB() {return _functions->f236();}
AABB *_newArrayAABB(size_t count) {return _functions->f237(count);}
AABB *_newAABB(const Position3D & arg0, const Position3D & arg1) {return _functions->f238(arg0, arg1);}
ResourceIOException *_newResourceIOException(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return _functions->f239(arg0, arg1, arg2, arg3, arg4, arg5);}
GfxAnimationState *_newGfxAnimationState(GfxMesh * arg0, const String & arg1) {return _functions->f240(arg0, arg1);}
GuiPlacer *_newGuiPlacer(ImGui * arg0, int arg1, int arg2, size_t arg3) {return _functions->f241(arg0, arg1, arg2, arg3);}
Audio *_newAudio() {return _functions->f242();}
Audio *_newArrayAudio(size_t count) {return _functions->f243(count);}
Audio *_newAudio(const String & arg0) {return _functions->f244(arg0);}
GfxTexture *_newGfxTexture(const String & arg0) {return _functions->f245(arg0);}
GfxTexture *_newGfxTexture() {return _functions->f246();}
GfxTexture *_newArrayGfxTexture(size_t count) {return _functions->f247(count);}
PhysicsDebugDrawer *_newPhysicsDebugDrawer() {return _functions->f248();}
PhysicsDebugDrawer *_newArrayPhysicsDebugDrawer(size_t count) {return _functions->f249(count);}
ImGui *_newImGui() {return _functions->f250();}
ImGui *_newArrayImGui(size_t count) {return _functions->f251(count);}
Application *_newApplication(const char * arg0) {return _functions->f252(arg0);}
GfxModel *_newGfxModel() {return _functions->f253();}
GfxModel *_newArrayGfxModel(size_t count) {return _functions->f254(count);}
GfxModel *_newGfxModel(const String & arg0) {return _functions->f255(arg0);}
Scene *_newScene() {return _functions->f256();}
Scene *_newArrayScene(size_t count) {return _functions->f257(count);}
Scene *_newScene(const String & arg0) {return _functions->f258(arg0);}
File *_newFile(const char * arg0, const char * arg1) {return _functions->f259(arg0, arg1);}
Matrix3x3 *_newMatrix3x3() {return _functions->f260();}
Matrix3x3 *_newArrayMatrix3x3(size_t count) {return _functions->f261(count);}
Matrix3x3 *_newMatrix3x3(const Matrix4x4 & arg0) {return _functions->f262(arg0);}
Matrix3x3 *_newMatrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return _functions->f263(arg0, arg1, arg2);}
Font *_newFont() {return _functions->f264();}
Font *_newArrayFont(size_t count) {return _functions->f265(count);}
Font *_newFont(const String & arg0) {return _functions->f266(arg0);}
GfxDebugDrawer *_newGfxDebugDrawer(GfxApi * arg0) {return _functions->f267(arg0);}
template <typename T0>
AudioSource *_new<AudioSource>::f(T0 arg0) {return _newAudioSource(arg0);}

Script *_new<Script>::f() {return _newScript();}

template <typename T0>
Script *_new<Script>::f(T0 arg0) {return _newScript(arg0);}

Transform *_new<Transform>::f() {return _newTransform();}

Platform *_new<Platform>::f() {return _newPlatform();}

template <typename T0, typename T1, typename T2>
AudioDevice *_new<AudioDevice>::f(T0 arg0, T1 arg1, T2 arg2) {return _newAudioDevice(arg0, arg1, arg2);}

GfxMaterial *_new<GfxMaterial>::f() {return _newGfxMaterial();}

template <typename T0>
GfxMaterial *_new<GfxMaterial>::f(T0 arg0) {return _newGfxMaterial(arg0);}

template <typename T0, typename T1, typename T2>
LookupException *_new<LookupException>::f(T0 arg0, T1 arg1, T2 arg2) {return _newLookupException(arg0, arg1, arg2);}

Quaternion *_new<Quaternion>::f() {return _newQuaternion();}

template <typename T0, typename T1>
Quaternion *_new<Quaternion>::f(T0 arg0, T1 arg1) {return _newQuaternion(arg0, arg1);}

template <typename T0, typename T1, typename T2, typename T3>
Quaternion *_new<Quaternion>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {return _newQuaternion(arg0, arg1, arg2, arg3);}

template <typename T0>
Quaternion *_new<Quaternion>::f(T0 arg0) {return _newQuaternion(arg0);}

Light *_new<Light>::f() {return _newLight();}

PhysicsShape *_new<PhysicsShape>::f() {return _newPhysicsShape();}

template <typename T0>
PhysicsShape *_new<PhysicsShape>::f(T0 arg0) {return _newPhysicsShape(arg0);}

template <typename T0, typename T1, typename T2, typename T3>
ShaderCompileException *_new<ShaderCompileException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {return _newShaderCompileException(arg0, arg1, arg2, arg3);}

template <typename T0, typename T1, typename T2>
Exception *_new<Exception>::f(T0 arg0, T1 arg1, T2 arg2) {return _newException(arg0, arg1, arg2);}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
FileException *_new<FileException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4) {return _newFileException(arg0, arg1, arg2, arg3, arg4);}

AABB *_new<AABB>::f() {return _newAABB();}

template <typename T0, typename T1>
AABB *_new<AABB>::f(T0 arg0, T1 arg1) {return _newAABB(arg0, arg1);}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
ResourceIOException *_new<ResourceIOException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5) {return _newResourceIOException(arg0, arg1, arg2, arg3, arg4, arg5);}

template <typename T0, typename T1>
GfxAnimationState *_new<GfxAnimationState>::f(T0 arg0, T1 arg1) {return _newGfxAnimationState(arg0, arg1);}

template <typename T0, typename T1, typename T2, typename T3>
GuiPlacer *_new<GuiPlacer>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {return _newGuiPlacer(arg0, arg1, arg2, arg3);}

Audio *_new<Audio>::f() {return _newAudio();}

template <typename T0>
Audio *_new<Audio>::f(T0 arg0) {return _newAudio(arg0);}

template <typename T0>
GfxTexture *_new<GfxTexture>::f(T0 arg0) {return _newGfxTexture(arg0);}

GfxTexture *_new<GfxTexture>::f() {return _newGfxTexture();}

PhysicsDebugDrawer *_new<PhysicsDebugDrawer>::f() {return _newPhysicsDebugDrawer();}

ImGui *_new<ImGui>::f() {return _newImGui();}

template <typename T0>
Application *_new<Application>::f(T0 arg0) {return _newApplication(arg0);}

GfxModel *_new<GfxModel>::f() {return _newGfxModel();}

template <typename T0>
GfxModel *_new<GfxModel>::f(T0 arg0) {return _newGfxModel(arg0);}

Scene *_new<Scene>::f() {return _newScene();}

template <typename T0>
Scene *_new<Scene>::f(T0 arg0) {return _newScene(arg0);}

template <typename T0, typename T1>
File *_new<File>::f(T0 arg0, T1 arg1) {return _newFile(arg0, arg1);}

Matrix3x3 *_new<Matrix3x3>::f() {return _newMatrix3x3();}

template <typename T0>
Matrix3x3 *_new<Matrix3x3>::f(T0 arg0) {return _newMatrix3x3(arg0);}

template <typename T0, typename T1, typename T2>
Matrix3x3 *_new<Matrix3x3>::f(T0 arg0, T1 arg1, T2 arg2) {return _newMatrix3x3(arg0, arg1, arg2);}

Font *_new<Font>::f() {return _newFont();}

template <typename T0>
Font *_new<Font>::f(T0 arg0) {return _newFont(arg0);}

template <typename T0>
GfxDebugDrawer *_new<GfxDebugDrawer>::f(T0 arg0) {return _newGfxDebugDrawer(arg0);}

Script *_newArray<Script>::f(size_t count) {return _newArrayScript(count);}

Transform *_newArray<Transform>::f(size_t count) {return _newArrayTransform(count);}

Platform *_newArray<Platform>::f(size_t count) {return _newArrayPlatform(count);}

GfxMaterial *_newArray<GfxMaterial>::f(size_t count) {return _newArrayGfxMaterial(count);}

Quaternion *_newArray<Quaternion>::f(size_t count) {return _newArrayQuaternion(count);}

Light *_newArray<Light>::f(size_t count) {return _newArrayLight(count);}

PhysicsShape *_newArray<PhysicsShape>::f(size_t count) {return _newArrayPhysicsShape(count);}

AABB *_newArray<AABB>::f(size_t count) {return _newArrayAABB(count);}

Audio *_newArray<Audio>::f(size_t count) {return _newArrayAudio(count);}

GfxTexture *_newArray<GfxTexture>::f(size_t count) {return _newArrayGfxTexture(count);}

PhysicsDebugDrawer *_newArray<PhysicsDebugDrawer>::f(size_t count) {return _newArrayPhysicsDebugDrawer(count);}

ImGui *_newArray<ImGui>::f(size_t count) {return _newArrayImGui(count);}

GfxModel *_newArray<GfxModel>::f(size_t count) {return _newArrayGfxModel(count);}

Scene *_newArray<Scene>::f(size_t count) {return _newArrayScene(count);}

Matrix3x3 *_newArray<Matrix3x3>::f(size_t count) {return _newArrayMatrix3x3(count);}

Font *_newArray<Font>::f(size_t count) {return _newArrayFont(count);}

extern "C" void _initFunctions(const _functionStruct *functions) {_functions = functions;}
#else
template <typename T>
struct _new {};

template <typename T>
struct _newArray {};

class PhysicsWorld;
template <>
struct _new<PhysicsWorld>
{
};

class AudioSource;
template <>
struct _new<AudioSource>
{
    template <typename T0>
    static AudioSource *f(T0 arg0);
};

class Script;
template <>
struct _new<Script>
{
    static Script *f();
    template <typename T0>
    static Script *f(T0 arg0);
};

class GfxBuffer;
template <>
struct _new<GfxBuffer>
{
};

class Transform;
template <>
struct _new<Transform>
{
    static Transform *f();
};

class Matrix4x4;
template <>
struct _new<Matrix4x4>
{
};

class Platform;
template <>
struct _new<Platform>
{
    static Platform *f();
};

class Camera;
template <>
struct _new<Camera>
{
};

class GfxMesh;
template <>
struct _new<GfxMesh>
{
};

class AudioDevice;
template <>
struct _new<AudioDevice>
{
    template <typename T0, typename T1, typename T2>
    static AudioDevice *f(T0 arg0, T1 arg1, T2 arg2);
};

class GfxMaterial;
template <>
struct _new<GfxMaterial>
{
    static GfxMaterial *f();
    template <typename T0>
    static GfxMaterial *f(T0 arg0);
};

class LookupException;
template <>
struct _new<LookupException>
{
    template <typename T0, typename T1, typename T2>
    static LookupException *f(T0 arg0, T1 arg1, T2 arg2);
};

class GfxApi;
template <>
struct _new<GfxApi>
{
};

class GfxRenderer;
template <>
struct _new<GfxRenderer>
{
};

class Quaternion;
template <>
struct _new<Quaternion>
{
    static Quaternion *f();
    template <typename T0, typename T1>
    static Quaternion *f(T0 arg0, T1 arg1);
    template <typename T0, typename T1, typename T2, typename T3>
    static Quaternion *f(T0 arg0, T1 arg1, T2 arg2, T3 arg3);
    template <typename T0>
    static Quaternion *f(T0 arg0);
};

class GfxShader;
template <>
struct _new<GfxShader>
{
};

class LogEntry;
template <>
struct _new<LogEntry>
{
};

class Light;
template <>
struct _new<Light>
{
    static Light *f();
};

class PhysicsShape;
template <>
struct _new<PhysicsShape>
{
    static PhysicsShape *f();
    template <typename T0>
    static PhysicsShape *f(T0 arg0);
};

class ShaderCompileException;
template <>
struct _new<ShaderCompileException>
{
    template <typename T0, typename T1, typename T2, typename T3>
    static ShaderCompileException *f(T0 arg0, T1 arg1, T2 arg2, T3 arg3);
};

class RigidBody;
template <>
struct _new<RigidBody>
{
};

class Exception;
template <>
struct _new<Exception>
{
    template <typename T0, typename T1, typename T2>
    static Exception *f(T0 arg0, T1 arg1, T2 arg2);
};

class FileException;
template <>
struct _new<FileException>
{
    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    static FileException *f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4);
};

class GfxShaderImpl;
template <>
struct _new<GfxShaderImpl>
{
};

class AABB;
template <>
struct _new<AABB>
{
    static AABB *f();
    template <typename T0, typename T1>
    static AABB *f(T0 arg0, T1 arg1);
};

class ResourceIOException;
template <>
struct _new<ResourceIOException>
{
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    static ResourceIOException *f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);
};

class GfxAnimationState;
template <>
struct _new<GfxAnimationState>
{
    template <typename T0, typename T1>
    static GfxAnimationState *f(T0 arg0, T1 arg1);
};

class Filesystem;
template <>
struct _new<Filesystem>
{
};

class AudioWorld;
template <>
struct _new<AudioWorld>
{
};

class GuiPlacer;
template <>
struct _new<GuiPlacer>
{
    template <typename T0, typename T1, typename T2, typename T3>
    static GuiPlacer *f(T0 arg0, T1 arg1, T2 arg2, T3 arg3);
};

class Audio;
template <>
struct _new<Audio>
{
    static Audio *f();
    template <typename T0>
    static Audio *f(T0 arg0);
};

class GfxTexture;
template <>
struct _new<GfxTexture>
{
    template <typename T0>
    static GfxTexture *f(T0 arg0);
    static GfxTexture *f();
};

class GhostObject;
template <>
struct _new<GhostObject>
{
};

class PhysicsShapeImpl;
template <>
struct _new<PhysicsShapeImpl>
{
};

class PhysicsDebugDrawer;
template <>
struct _new<PhysicsDebugDrawer>
{
    static PhysicsDebugDrawer *f();
};

class ImGui;
template <>
struct _new<ImGui>
{
    static ImGui *f();
};

class ResourceManager;
template <>
struct _new<ResourceManager>
{
};

class Application;
template <>
struct _new<Application>
{
    template <typename T0>
    static Application *f(T0 arg0);
};

class GfxModel;
template <>
struct _new<GfxModel>
{
    static GfxModel *f();
    template <typename T0>
    static GfxModel *f(T0 arg0);
};

class Scene;
template <>
struct _new<Scene>
{
    static Scene *f();
    template <typename T0>
    static Scene *f(T0 arg0);
};

class Entity;
template <>
struct _new<Entity>
{
};

class File;
template <>
struct _new<File>
{
    template <typename T0, typename T1>
    static File *f(T0 arg0, T1 arg1);
};

class GfxShaderCombination;
template <>
struct _new<GfxShaderCombination>
{
};

class Matrix3x3;
template <>
struct _new<Matrix3x3>
{
    static Matrix3x3 *f();
    template <typename T0>
    static Matrix3x3 *f(T0 arg0);
    template <typename T0, typename T1, typename T2>
    static Matrix3x3 *f(T0 arg0, T1 arg1, T2 arg2);
};

class Font;
template <>
struct _new<Font>
{
    static Font *f();
    template <typename T0>
    static Font *f(T0 arg0);
};

class GfxDebugDrawer;
template <>
struct _new<GfxDebugDrawer>
{
    template <typename T0>
    static GfxDebugDrawer *f(T0 arg0);
};

class PhysicsWorld;
template <>
struct _newArray<PhysicsWorld>
{
};

class AudioSource;
template <>
struct _newArray<AudioSource>
{
};

class Script;
template <>
struct _newArray<Script>
{
    static Script *f(size_t count);
};

class GfxBuffer;
template <>
struct _newArray<GfxBuffer>
{
};

class Transform;
template <>
struct _newArray<Transform>
{
    static Transform *f(size_t count);
};

class Matrix4x4;
template <>
struct _newArray<Matrix4x4>
{
};

class Platform;
template <>
struct _newArray<Platform>
{
    static Platform *f(size_t count);
};

class Camera;
template <>
struct _newArray<Camera>
{
};

class GfxMesh;
template <>
struct _newArray<GfxMesh>
{
};

class AudioDevice;
template <>
struct _newArray<AudioDevice>
{
};

class GfxMaterial;
template <>
struct _newArray<GfxMaterial>
{
    static GfxMaterial *f(size_t count);
};

class LookupException;
template <>
struct _newArray<LookupException>
{
};

class GfxApi;
template <>
struct _newArray<GfxApi>
{
};

class GfxRenderer;
template <>
struct _newArray<GfxRenderer>
{
};

class Quaternion;
template <>
struct _newArray<Quaternion>
{
    static Quaternion *f(size_t count);
};

class GfxShader;
template <>
struct _newArray<GfxShader>
{
};

class LogEntry;
template <>
struct _newArray<LogEntry>
{
};

class Light;
template <>
struct _newArray<Light>
{
    static Light *f(size_t count);
};

class PhysicsShape;
template <>
struct _newArray<PhysicsShape>
{
    static PhysicsShape *f(size_t count);
};

class ShaderCompileException;
template <>
struct _newArray<ShaderCompileException>
{
};

class RigidBody;
template <>
struct _newArray<RigidBody>
{
};

class Exception;
template <>
struct _newArray<Exception>
{
};

class FileException;
template <>
struct _newArray<FileException>
{
};

class GfxShaderImpl;
template <>
struct _newArray<GfxShaderImpl>
{
};

class AABB;
template <>
struct _newArray<AABB>
{
    static AABB *f(size_t count);
};

class ResourceIOException;
template <>
struct _newArray<ResourceIOException>
{
};

class GfxAnimationState;
template <>
struct _newArray<GfxAnimationState>
{
};

class Filesystem;
template <>
struct _newArray<Filesystem>
{
};

class AudioWorld;
template <>
struct _newArray<AudioWorld>
{
};

class GuiPlacer;
template <>
struct _newArray<GuiPlacer>
{
};

class Audio;
template <>
struct _newArray<Audio>
{
    static Audio *f(size_t count);
};

class GfxTexture;
template <>
struct _newArray<GfxTexture>
{
    static GfxTexture *f(size_t count);
};

class GhostObject;
template <>
struct _newArray<GhostObject>
{
};

class PhysicsShapeImpl;
template <>
struct _newArray<PhysicsShapeImpl>
{
};

class PhysicsDebugDrawer;
template <>
struct _newArray<PhysicsDebugDrawer>
{
    static PhysicsDebugDrawer *f(size_t count);
};

class ImGui;
template <>
struct _newArray<ImGui>
{
    static ImGui *f(size_t count);
};

class ResourceManager;
template <>
struct _newArray<ResourceManager>
{
};

class Application;
template <>
struct _newArray<Application>
{
};

class GfxModel;
template <>
struct _newArray<GfxModel>
{
    static GfxModel *f(size_t count);
};

class Scene;
template <>
struct _newArray<Scene>
{
    static Scene *f(size_t count);
};

class Entity;
template <>
struct _newArray<Entity>
{
};

class File;
template <>
struct _newArray<File>
{
};

class GfxShaderCombination;
template <>
struct _newArray<GfxShaderCombination>
{
};

class Matrix3x3;
template <>
struct _newArray<Matrix3x3>
{
    static Matrix3x3 *f(size_t count);
};

class Font;
template <>
struct _newArray<Font>
{
    static Font *f(size_t count);
};

class GfxDebugDrawer;
template <>
struct _newArray<GfxDebugDrawer>
{
};

#endif