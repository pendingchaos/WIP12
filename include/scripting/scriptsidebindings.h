//Generated from script_binding_generator.py. Do not edit. Edit script_binding_generator.py instead.
#ifdef _SCRIPT_SIDE_IMPLS
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
    void (*f47)( GfxRenderer *obj);
    Quaternion (*f48)(const Quaternion *obj, const Quaternion & arg0);
    Matrix4x4 (*f49)(const Quaternion *obj);
    Float4 (*f50)(const Quaternion *obj);
    void (*f51)( Quaternion *obj, const Direction3D & arg0);
    void (*f52)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f53)( Quaternion *obj, const Float3 & arg0);
    Float3 (*f54)( Quaternion *obj);
    void (*f55)( Quaternion *obj);
    void (*f56)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f57)( Quaternion *obj, float arg0, float arg1, float arg2, float arg3);
    void (*f58)( Quaternion *obj, const Float3 & arg0);
    LogEntry & (*f59)( LogEntry *obj, const char * arg0, uint8_t arg1);
    LogEntry & (*f60)( LogEntry *obj, const char * arg0, int8_t arg1);
    LogEntry & (*f61)( LogEntry *obj, const char * arg0, uint16_t arg1);
    LogEntry & (*f62)( LogEntry *obj, const char * arg0, int16_t arg1);
    LogEntry & (*f63)( LogEntry *obj, const char * arg0, uint32_t arg1);
    LogEntry & (*f64)( LogEntry *obj, const char * arg0, int32_t arg1);
    LogEntry & (*f65)( LogEntry *obj, const char * arg0, uint64_t arg1);
    LogEntry & (*f66)( LogEntry *obj, const char * arg0, int64_t arg1);
    LogEntry & (*f67)( LogEntry *obj, const char * arg0, bool arg1);
    LogEntry & (*f68)( LogEntry *obj, const char * arg0, float arg1);
    LogEntry & (*f69)( LogEntry *obj, const char * arg0, double arg1);
    LogEntry & (*f70)( LogEntry *obj, const char * arg0, long double arg1);
    LogEntry & (*f71)( LogEntry *obj, const char * arg0, const char * arg1);
    LogEntry & (*f72)( LogEntry *obj, const char * arg0, const String & arg1);
    LogEntry & (*f73)( LogEntry *obj);
    LogEntry & (*f74)( LogEntry *obj, unsigned int arg0, const char ** arg1);
    int (*f75)( LogEntry *obj);
    int (*f76)( LogEntry *obj);
    void (*f77)( Light *obj, size_t arg0, GfxShadowmapPrecision arg1);
    void (*f78)( Light *obj, GfxRenderer * arg0);
    void (*f79)( PhysicsShape *obj);
    void (*f80)( PhysicsShape *obj, float arg0);
    void (*f81)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f82)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f83)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f84)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f85)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f86)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f87)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f88)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f89)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    bool (*f90)(const Serializable *obj, const Serializable & arg0);
    void (*f91)( Serializable *obj, File * arg0);
    void (*f92)( Serializable *obj, File * arg0);
    void (*f93)( Resource *obj);
    bool (*f94)(const Resource *obj);
    void (*f95)( GfxAnimationState *obj);
    void (*f96)( GfxAnimationState *obj, GfxMesh * arg0, const String & arg1);
    void (*f97)( GfxAnimationState *obj);
    void (*f98)( GfxTexture *obj, GfxTextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexPurpose arg6, GfxTexFormat arg7);
    void (*f99)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, const void * arg3);
    void (*f100)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f101)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxFace arg2, void * arg3);
    void (*f102)(const GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f103)( GfxTexture *obj);
    void (*f104)( GfxTexture *obj, float arg0);
    void (*f105)( GfxTexture *obj, GfxFilter arg0);
    void (*f106)( GfxTexture *obj, GfxFilter arg0);
    void (*f107)( GfxTexture *obj, GfxMipmapMode arg0);
    void (*f108)( GfxTexture *obj, GfxWrapMode arg0);
    void (*f109)( GfxTexture *obj, bool arg0);
    Transform (*f110)( GhostObject *obj);
    void (*f111)(const GhostObject *obj, const Transform & arg0);
    void (*f112)( GhostObject *obj, PhysicsShape * arg0);
    void (*f113)(const GhostObject *obj, List<RigidBody *> & arg0, List<GhostObject *> & arg1);
    void (*f114)( Application *obj);
    void (*f115)( Application *obj, const char * arg0);
    void (*f116)( Application *obj);
    void (*f117)( Scene *obj);
    void (*f118)( Scene *obj);
    void (*f119)( Scene *obj, float arg0);
    void (*f120)( Scene *obj);
    Entity * (*f121)( Scene *obj, const String & arg0);
    void (*f122)( Scene *obj, size_t arg0);
    RigidBody * (*f123)( Entity *obj, const RigidBodyConstructionInfo & arg0, PhysicsShape * arg1);
    Scene * (*f124)(const Entity *obj);
    Entity * (*f125)( Entity *obj, const String & arg0);
    void (*f126)( Entity *obj, size_t arg0);
    void (*f127)( Entity *obj);
    AudioSource * (*f128)( Entity *obj, Audio * arg0);
    void (*f129)( Entity *obj, size_t arg0);
    void (*f130)( File *obj, size_t arg0, void * arg1);
    void (*f131)( File *obj, size_t arg0, const void * arg1);
    void (*f132)( File *obj, long arg0, FileOrigin arg1);
    long (*f133)( File *obj);
    void (*f134)( File *obj);
    bool (*f135)( File *obj);
    size_t (*f136)( File *obj);
    uint8_t (*f137)( File *obj);
    int8_t (*f138)( File *obj);
    uint16_t (*f139)( File *obj);
    int16_t (*f140)( File *obj);
    uint32_t (*f141)( File *obj);
    int32_t (*f142)( File *obj);
    uint64_t (*f143)( File *obj);
    int64_t (*f144)( File *obj);
    uint16_t (*f145)( File *obj);
    int16_t (*f146)( File *obj);
    uint32_t (*f147)( File *obj);
    int32_t (*f148)( File *obj);
    uint64_t (*f149)( File *obj);
    int64_t (*f150)( File *obj);
    float (*f151)( File *obj);
    char (*f152)( File *obj);
    void (*f153)( File *obj, uint8_t arg0);
    void (*f154)( File *obj, int8_t arg0);
    void (*f155)( File *obj, uint16_t arg0);
    void (*f156)( File *obj, int16_t arg0);
    void (*f157)( File *obj, uint32_t arg0);
    void (*f158)( File *obj, int32_t arg0);
    void (*f159)( File *obj, uint64_t arg0);
    void (*f160)( File *obj, int64_t arg0);
    void (*f161)( File *obj, uint16_t arg0);
    void (*f162)( File *obj, int16_t arg0);
    void (*f163)( File *obj, uint32_t arg0);
    void (*f164)( File *obj, int32_t arg0);
    void (*f165)( File *obj, uint64_t arg0);
    void (*f166)( File *obj, int64_t arg0);
    void (*f167)( File *obj, float arg0);
    void (*f168)( File *obj, const char * arg0, va_list arg1);
    void (*f169)( File *obj, char arg0);
    void (*f170)( File *obj, const char * arg0, const char * arg1);
    void (*f171)( File *obj);
    void (*f172)( GfxShaderCombination *obj, GfxShaderType arg0, const String & arg1, const String & arg2);
    const String & (*f173)( GfxShaderCombination *obj, GfxShaderType arg0, const String & arg1);
    void (*f174)( GfxShaderCombination *obj, GfxShaderType arg0, const String & arg1);
    GfxShader * (*f175)( GfxShaderCombination *obj, GfxShaderType arg0);
    void (*f176)( GfxShaderCombination *obj, GfxShaderType arg0, GfxShader * arg1);
    GfxCompiledShader * (*f177)(const GfxShaderCombination *obj, GfxShaderType arg0);
    void (*f178)( GfxShaderCombination *obj, GfxShader * arg0, GfxShader * arg1);
    Matrix3x3 (*f179)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f180)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f181)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f182)(const Matrix3x3 *obj);
    Matrix3x3 (*f183)(const Matrix3x3 *obj);
    Matrix3x3 (*f184)(const Float2 & arg0);
    Matrix3x3 (*f185)(const Float3 & arg0);
    Matrix3x3 (*f186)(float arg0);
    Matrix3x3 (*f187)(float arg0);
    Matrix3x3 (*f188)(float arg0);
    Matrix3x3 (*f189)(float arg0);
    void (*f190)( Matrix3x3 *obj);
    void (*f191)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f192)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    void (*f193)( Font *obj, size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4);
    void (*f194)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f195)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f196)( GfxDebugDrawer *obj);
    AudioSource *(*f197)(Audio * arg0);
    Script *(*f198)();
    Script *(*f199)(size_t count);
    Script *(*f200)(const String & arg0);
    Transform *(*f201)();
    Transform *(*f202)(size_t count);
    Platform *(*f203)();
    Platform *(*f204)(size_t count);
    AudioDevice *(*f205)(size_t arg0, size_t arg1, size_t arg2);
    GfxMaterial *(*f206)();
    GfxMaterial *(*f207)(size_t count);
    GfxMaterial *(*f208)(const String & arg0);
    SerializeException *(*f209)(const char * arg0, size_t arg1, const char * arg2);
    LookupException *(*f210)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f211)();
    Quaternion *(*f212)(size_t count);
    Quaternion *(*f213)(const Direction3D & arg0, float arg1);
    Quaternion *(*f214)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f215)(const Float3 & arg0);
    Light *(*f216)();
    Light *(*f217)(size_t count);
    PhysicsShape *(*f218)();
    PhysicsShape *(*f219)(size_t count);
    PhysicsShape *(*f220)(const String & arg0);
    Serializable *(*f221)();
    Serializable *(*f222)(size_t count);
    Serializable *(*f223)(uint8_t arg0);
    Serializable *(*f224)(int8_t arg0);
    Serializable *(*f225)(uint16_t arg0);
    Serializable *(*f226)(int16_t arg0);
    Serializable *(*f227)(uint32_t arg0);
    Serializable *(*f228)(int32_t arg0);
    Serializable *(*f229)(uint64_t arg0);
    Serializable *(*f230)(int64_t arg0);
    Serializable *(*f231)(const String & arg0);
    Serializable *(*f232)(bool arg0);
    Serializable *(*f233)(float arg0);
    Serializable *(*f234)(const Float2 & arg0);
    Serializable *(*f235)(const Float3 & arg0);
    Serializable *(*f236)(const Float4 & arg0);
    Serializable *(*f237)(const Int2 & arg0);
    Serializable *(*f238)(const Int3 & arg0);
    Serializable *(*f239)(const Int4 & arg0);
    Serializable *(*f240)(const UInt2 & arg0);
    Serializable *(*f241)(const UInt3 & arg0);
    Serializable *(*f242)(const UInt4 & arg0);
    ShaderCompileException *(*f243)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f244)(const char * arg0, size_t arg1, const char * arg2);
    FileException *(*f245)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    AABB *(*f246)();
    AABB *(*f247)(size_t count);
    AABB *(*f248)(const Position3D & arg0, const Position3D & arg1);
    ResourceIOException *(*f249)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxAnimationState *(*f250)(GfxMesh * arg0, const String & arg1);
    Audio *(*f251)();
    Audio *(*f252)(size_t count);
    Audio *(*f253)(const String & arg0);
    GfxTexture *(*f254)(const String & arg0);
    GfxTexture *(*f255)();
    GfxTexture *(*f256)(size_t count);
    PhysicsDebugDrawer *(*f257)();
    PhysicsDebugDrawer *(*f258)(size_t count);
    Application *(*f259)(const char * arg0);
    GfxModel *(*f260)();
    GfxModel *(*f261)(size_t count);
    GfxModel *(*f262)(const String & arg0);
    Scene *(*f263)();
    Scene *(*f264)(size_t count);
    Scene *(*f265)(const String & arg0);
    File *(*f266)(const char * arg0, const char * arg1);
    GfxShaderCombination *(*f267)(GfxShader * arg0, GfxShader * arg1);
    Matrix3x3 *(*f268)();
    Matrix3x3 *(*f269)(size_t count);
    Matrix3x3 *(*f270)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f271)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    Font *(*f272)();
    Font *(*f273)(size_t count);
    Font *(*f274)(const String & arg0);
    GfxDebugDrawer *(*f275)(GfxApi * arg0);
};
const _functionStruct *_functions;
const char ** getBacktrace(unsigned int & arg0) {return _functions->f0(arg0);}
size_t getHash(const String & arg0) {return _functions->f1(arg0);}
bool doesFileExist(const char * arg0) {return _functions->f2(arg0);}
List<String> listFiles(const char * arg0) {return _functions->f3(arg0);}
void setApplication(Application * arg0) { _functions->f4(arg0);}
ScriptInstance * Script::createInstance(const char * arg0, Entity * arg1, Scene * arg2)  {return _functions->f5(this, arg0, arg1, arg2);}
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
 GfxRenderer::~GfxRenderer()  { _functions->f47(this);}
Quaternion Quaternion::operator*(const Quaternion & arg0) const {return _functions->f48(this, arg0);}
Matrix4x4 Quaternion::toMatrix() const {return _functions->f49(this);}
Float4 Quaternion::getAxisAndAngle() const {return _functions->f50(this);}
void Quaternion::setAxis(const Direction3D & arg0)  { _functions->f51(this, arg0);}
void Quaternion::setAxisAndAngle(const Direction3D & arg0, float arg1)  { _functions->f52(this, arg0, arg1);}
void Quaternion::setEulerAngles(const Float3 & arg0)  { _functions->f53(this, arg0);}
Float3 Quaternion::getEulerAngles()  {return _functions->f54(this);}
 Quaternion::Quaternion()  { _functions->f55(this);}
 Quaternion::Quaternion(const Direction3D & arg0, float arg1)  { _functions->f56(this, arg0, arg1);}
 Quaternion::Quaternion(float arg0, float arg1, float arg2, float arg3)  { _functions->f57(this, arg0, arg1, arg2, arg3);}
 Quaternion::Quaternion(const Float3 & arg0)  { _functions->f58(this, arg0);}
LogEntry & LogEntry::variable(const char * arg0, uint8_t arg1)  {return _functions->f59(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int8_t arg1)  {return _functions->f60(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint16_t arg1)  {return _functions->f61(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int16_t arg1)  {return _functions->f62(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint32_t arg1)  {return _functions->f63(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int32_t arg1)  {return _functions->f64(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint64_t arg1)  {return _functions->f65(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int64_t arg1)  {return _functions->f66(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, bool arg1)  {return _functions->f67(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, float arg1)  {return _functions->f68(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, double arg1)  {return _functions->f69(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, long double arg1)  {return _functions->f70(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const char * arg1)  {return _functions->f71(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const String & arg1)  {return _functions->f72(this, arg0, arg1);}
LogEntry & LogEntry::printBacktrace()  {return _functions->f73(this);}
LogEntry & LogEntry::printBacktrace(unsigned int arg0, const char ** arg1)  {return _functions->f74(this, arg0, arg1);}
int LogEntry::end()  {return _functions->f75(this);}
int LogEntry::fatalEnd()  {return _functions->f76(this);}
void Light::addShadowmap(size_t arg0, GfxShadowmapPrecision arg1)  { _functions->f77(this, arg0, arg1);}
void Light::updateMatrices(GfxRenderer * arg0)  { _functions->f78(this, arg0);}
void PhysicsShape::setEmpty()  { _functions->f79(this);}
void PhysicsShape::setSphere(float arg0)  { _functions->f80(this, arg0);}
void PhysicsShape::setBox(const Vector3D & arg0)  { _functions->f81(this, arg0);}
void PhysicsShape::setCylinder(PhysicsCylinderShape::Axis arg0, float arg1, float arg2)  { _functions->f82(this, arg0, arg1, arg2);}
void PhysicsShape::setCapsule(PhysicsCapsuleShape::Axis arg0, float arg1, float arg2)  { _functions->f83(this, arg0, arg1, arg2);}
void PhysicsShape::setCone(PhysicsConeShape::Axis arg0, float arg1, float arg2)  { _functions->f84(this, arg0, arg1, arg2);}
void PhysicsShape::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f85(this, arg0, arg1);}
void PhysicsShape::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f86(this, arg0, arg1);}
void PhysicsShape::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f87(this, arg0, arg1, arg2);}
void PhysicsShape::setPlane(const Vector3D & arg0, float arg1)  { _functions->f88(this, arg0, arg1);}
void PhysicsShape::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f89(this, arg0, arg1);}
bool Serializable::operator==(const Serializable & arg0) const {return _functions->f90(this, arg0);}
void Serializable::writeToFile(File * arg0)  { _functions->f91(this, arg0);}
void Serializable::readFromFile(File * arg0)  { _functions->f92(this, arg0);}
void Resource::load()  { _functions->f93(this);}
bool Resource::shouldReload() const {return _functions->f94(this);}
void GfxAnimationState::updateMatrices()  { _functions->f95(this);}
 GfxAnimationState::GfxAnimationState(GfxMesh * arg0, const String & arg1)  { _functions->f96(this, arg0, arg1);}
 GfxAnimationState::~GfxAnimationState()  { _functions->f97(this);}
void GfxTexture::startCreation(GfxTextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexPurpose arg6, GfxTexFormat arg7)  { _functions->f98(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void GfxTexture::allocMipmapFace(unsigned int arg0, unsigned int arg1, GfxFace arg2, const void * arg3)  { _functions->f99(this, arg0, arg1, arg2, arg3);}
void GfxTexture::allocMipmap(unsigned int arg0, unsigned int arg1, const void * arg2)  { _functions->f100(this, arg0, arg1, arg2);}
void GfxTexture::getMipmapFace(unsigned int arg0, unsigned int arg1, GfxFace arg2, void * arg3) const { _functions->f101(this, arg0, arg1, arg2, arg3);}
void GfxTexture::getMipmap(unsigned int arg0, unsigned int arg1, void * arg2) const { _functions->f102(this, arg0, arg1, arg2);}
void GfxTexture::generateMipmaps()  { _functions->f103(this);}
void GfxTexture::setMaximumAnisotropy(float arg0)  { _functions->f104(this, arg0);}
void GfxTexture::setMinFilter(GfxFilter arg0)  { _functions->f105(this, arg0);}
void GfxTexture::setMagFilter(GfxFilter arg0)  { _functions->f106(this, arg0);}
void GfxTexture::setMipmapMode(GfxMipmapMode arg0)  { _functions->f107(this, arg0);}
void GfxTexture::setWrapMode(GfxWrapMode arg0)  { _functions->f108(this, arg0);}
void GfxTexture::setShadowmap(bool arg0)  { _functions->f109(this, arg0);}
Transform GhostObject::getTransform()  {return _functions->f110(this);}
void GhostObject::setTransform(const Transform & arg0) const { _functions->f111(this, arg0);}
void GhostObject::setShape(PhysicsShape * arg0)  { _functions->f112(this, arg0);}
void GhostObject::getCollisions(List<RigidBody *> & arg0, List<GhostObject *> & arg1) const { _functions->f113(this, arg0, arg1);}
void Application::mainloop()  { _functions->f114(this);}
 Application::Application(const char * arg0)  { _functions->f115(this, arg0);}
 Application::~Application()  { _functions->f116(this);}
void Scene::handleInput()  { _functions->f117(this);}
void Scene::update()  { _functions->f118(this);}
void Scene::fixedUpdate(float arg0)  { _functions->f119(this, arg0);}
void Scene::render()  { _functions->f120(this);}
Entity * Scene::createEntity(const String & arg0)  {return _functions->f121(this, arg0);}
void Scene::removeEntity(size_t arg0)  { _functions->f122(this, arg0);}
RigidBody * Entity::addRigidBody(const RigidBodyConstructionInfo & arg0, PhysicsShape * arg1)  {return _functions->f123(this, arg0, arg1);}
Scene * Entity::getScene() const {return _functions->f124(this);}
Entity * Entity::createEntity(const String & arg0)  {return _functions->f125(this, arg0);}
void Entity::removeEntity(size_t arg0)  { _functions->f126(this, arg0);}
void Entity::updateFinalTransform()  { _functions->f127(this);}
AudioSource * Entity::addAudioSource(Audio * arg0)  {return _functions->f128(this, arg0);}
void Entity::removeAudioSource(size_t arg0)  { _functions->f129(this, arg0);}
void File::read(size_t arg0, void * arg1)  { _functions->f130(this, arg0, arg1);}
void File::write(size_t arg0, const void * arg1)  { _functions->f131(this, arg0, arg1);}
void File::seek(long arg0, FileOrigin arg1)  { _functions->f132(this, arg0, arg1);}
long File::tell()  {return _functions->f133(this);}
void File::flush()  { _functions->f134(this);}
bool File::isAtEndOfFile()  {return _functions->f135(this);}
size_t File::getSize()  {return _functions->f136(this);}
uint8_t File::readUInt8()  {return _functions->f137(this);}
int8_t File::readInt8()  {return _functions->f138(this);}
uint16_t File::readUInt16LE()  {return _functions->f139(this);}
int16_t File::readInt16LE()  {return _functions->f140(this);}
uint32_t File::readUInt32LE()  {return _functions->f141(this);}
int32_t File::readInt32LE()  {return _functions->f142(this);}
uint64_t File::readUInt64LE()  {return _functions->f143(this);}
int64_t File::readInt64LE()  {return _functions->f144(this);}
uint16_t File::readUInt16BE()  {return _functions->f145(this);}
int16_t File::readInt16BE()  {return _functions->f146(this);}
uint32_t File::readUInt32BE()  {return _functions->f147(this);}
int32_t File::readInt32BE()  {return _functions->f148(this);}
uint64_t File::readUInt64BE()  {return _functions->f149(this);}
int64_t File::readInt64BE()  {return _functions->f150(this);}
float File::readFloat32()  {return _functions->f151(this);}
char File::readChar()  {return _functions->f152(this);}
void File::writeUInt8(uint8_t arg0)  { _functions->f153(this, arg0);}
void File::writeInt8(int8_t arg0)  { _functions->f154(this, arg0);}
void File::writeUInt16LE(uint16_t arg0)  { _functions->f155(this, arg0);}
void File::writeInt16LE(int16_t arg0)  { _functions->f156(this, arg0);}
void File::writeUInt32LE(uint32_t arg0)  { _functions->f157(this, arg0);}
void File::writeInt32LE(int32_t arg0)  { _functions->f158(this, arg0);}
void File::writeUInt64LE(uint64_t arg0)  { _functions->f159(this, arg0);}
void File::writeInt64LE(int64_t arg0)  { _functions->f160(this, arg0);}
void File::writeUInt16BE(uint16_t arg0)  { _functions->f161(this, arg0);}
void File::writeInt16BE(int16_t arg0)  { _functions->f162(this, arg0);}
void File::writeUInt32BE(uint32_t arg0)  { _functions->f163(this, arg0);}
void File::writeInt32BE(int32_t arg0)  { _functions->f164(this, arg0);}
void File::writeUInt64BE(uint64_t arg0)  { _functions->f165(this, arg0);}
void File::writeInt64BE(int64_t arg0)  { _functions->f166(this, arg0);}
void File::writeFloat32(float arg0)  { _functions->f167(this, arg0);}
void File::vprintf(const char * arg0, va_list arg1)  { _functions->f168(this, arg0, arg1);}
void File::writeChar(char arg0)  { _functions->f169(this, arg0);}
 File::File(const char * arg0, const char * arg1)  { _functions->f170(this, arg0, arg1);}
 File::~File()  { _functions->f171(this);}
void GfxShaderCombination::setDefine(GfxShaderType arg0, const String & arg1, const String & arg2)  { _functions->f172(this, arg0, arg1, arg2);}
const String & GfxShaderCombination::getDefine(GfxShaderType arg0, const String & arg1)  {return _functions->f173(this, arg0, arg1);}
void GfxShaderCombination::removeDefine(GfxShaderType arg0, const String & arg1)  { _functions->f174(this, arg0, arg1);}
GfxShader * GfxShaderCombination::getShader(GfxShaderType arg0)  {return _functions->f175(this, arg0);}
void GfxShaderCombination::setShader(GfxShaderType arg0, GfxShader * arg1)  { _functions->f176(this, arg0, arg1);}
GfxCompiledShader * GfxShaderCombination::getCompiled(GfxShaderType arg0) const {return _functions->f177(this, arg0);}
 GfxShaderCombination::GfxShaderCombination(GfxShader * arg0, GfxShader * arg1)  { _functions->f178(this, arg0, arg1);}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & arg0) const {return _functions->f179(this, arg0);}
Float3 Matrix3x3::operator*(const Float3 & arg0) const {return _functions->f180(this, arg0);}
Matrix3x3 Matrix3x3::operator/(float arg0) const {return _functions->f181(this, arg0);}
Matrix3x3 Matrix3x3::transpose() const {return _functions->f182(this);}
Matrix3x3 Matrix3x3::inverse() const {return _functions->f183(this);}
Matrix3x3 Matrix3x3::translate(const Float2 & arg0)  {return _functions->f184(arg0);}
Matrix3x3 Matrix3x3::scale(const Float3 & arg0)  {return _functions->f185(arg0);}
Matrix3x3 Matrix3x3::rotate(float arg0)  {return _functions->f186(arg0);}
Matrix3x3 Matrix3x3::rotatex(float arg0)  {return _functions->f187(arg0);}
Matrix3x3 Matrix3x3::rotatey(float arg0)  {return _functions->f188(arg0);}
Matrix3x3 Matrix3x3::rotatez(float arg0)  {return _functions->f189(arg0);}
 Matrix3x3::Matrix3x3()  { _functions->f190(this);}
 Matrix3x3::Matrix3x3(const Matrix4x4 & arg0)  { _functions->f191(this, arg0);}
 Matrix3x3::Matrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2)  { _functions->f192(this, arg0, arg1, arg2);}
void Font::render(size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4)  { _functions->f193(this, arg0, arg1, arg2, arg3, arg4);}
void GfxDebugDrawer::render(const Camera & arg0)  { _functions->f194(this, arg0);}
 GfxDebugDrawer::GfxDebugDrawer(GfxApi * arg0)  { _functions->f195(this, arg0);}
 GfxDebugDrawer::~GfxDebugDrawer()  { _functions->f196(this);}
AudioSource *_newAudioSource(Audio * arg0) {return _functions->f197(arg0);}
Script *_newScript() {return _functions->f198();}
Script *_newArrayScript(size_t count) {return _functions->f199(count);}
Script *_newScript(const String & arg0) {return _functions->f200(arg0);}
Transform *_newTransform() {return _functions->f201();}
Transform *_newArrayTransform(size_t count) {return _functions->f202(count);}
Platform *_newPlatform() {return _functions->f203();}
Platform *_newArrayPlatform(size_t count) {return _functions->f204(count);}
AudioDevice *_newAudioDevice(size_t arg0, size_t arg1, size_t arg2) {return _functions->f205(arg0, arg1, arg2);}
GfxMaterial *_newGfxMaterial() {return _functions->f206();}
GfxMaterial *_newArrayGfxMaterial(size_t count) {return _functions->f207(count);}
GfxMaterial *_newGfxMaterial(const String & arg0) {return _functions->f208(arg0);}
SerializeException *_newSerializeException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f209(arg0, arg1, arg2);}
LookupException *_newLookupException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f210(arg0, arg1, arg2);}
Quaternion *_newQuaternion() {return _functions->f211();}
Quaternion *_newArrayQuaternion(size_t count) {return _functions->f212(count);}
Quaternion *_newQuaternion(const Direction3D & arg0, float arg1) {return _functions->f213(arg0, arg1);}
Quaternion *_newQuaternion(float arg0, float arg1, float arg2, float arg3) {return _functions->f214(arg0, arg1, arg2, arg3);}
Quaternion *_newQuaternion(const Float3 & arg0) {return _functions->f215(arg0);}
Light *_newLight() {return _functions->f216();}
Light *_newArrayLight(size_t count) {return _functions->f217(count);}
PhysicsShape *_newPhysicsShape() {return _functions->f218();}
PhysicsShape *_newArrayPhysicsShape(size_t count) {return _functions->f219(count);}
PhysicsShape *_newPhysicsShape(const String & arg0) {return _functions->f220(arg0);}
Serializable *_newSerializable() {return _functions->f221();}
Serializable *_newArraySerializable(size_t count) {return _functions->f222(count);}
Serializable *_newSerializable(uint8_t arg0) {return _functions->f223(arg0);}
Serializable *_newSerializable(int8_t arg0) {return _functions->f224(arg0);}
Serializable *_newSerializable(uint16_t arg0) {return _functions->f225(arg0);}
Serializable *_newSerializable(int16_t arg0) {return _functions->f226(arg0);}
Serializable *_newSerializable(uint32_t arg0) {return _functions->f227(arg0);}
Serializable *_newSerializable(int32_t arg0) {return _functions->f228(arg0);}
Serializable *_newSerializable(uint64_t arg0) {return _functions->f229(arg0);}
Serializable *_newSerializable(int64_t arg0) {return _functions->f230(arg0);}
Serializable *_newSerializable(const String & arg0) {return _functions->f231(arg0);}
Serializable *_newSerializable(bool arg0) {return _functions->f232(arg0);}
Serializable *_newSerializable(float arg0) {return _functions->f233(arg0);}
Serializable *_newSerializable(const Float2 & arg0) {return _functions->f234(arg0);}
Serializable *_newSerializable(const Float3 & arg0) {return _functions->f235(arg0);}
Serializable *_newSerializable(const Float4 & arg0) {return _functions->f236(arg0);}
Serializable *_newSerializable(const Int2 & arg0) {return _functions->f237(arg0);}
Serializable *_newSerializable(const Int3 & arg0) {return _functions->f238(arg0);}
Serializable *_newSerializable(const Int4 & arg0) {return _functions->f239(arg0);}
Serializable *_newSerializable(const UInt2 & arg0) {return _functions->f240(arg0);}
Serializable *_newSerializable(const UInt3 & arg0) {return _functions->f241(arg0);}
Serializable *_newSerializable(const UInt4 & arg0) {return _functions->f242(arg0);}
ShaderCompileException *_newShaderCompileException(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return _functions->f243(arg0, arg1, arg2, arg3);}
Exception *_newException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f244(arg0, arg1, arg2);}
FileException *_newFileException(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return _functions->f245(arg0, arg1, arg2, arg3, arg4);}
AABB *_newAABB() {return _functions->f246();}
AABB *_newArrayAABB(size_t count) {return _functions->f247(count);}
AABB *_newAABB(const Position3D & arg0, const Position3D & arg1) {return _functions->f248(arg0, arg1);}
ResourceIOException *_newResourceIOException(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return _functions->f249(arg0, arg1, arg2, arg3, arg4, arg5);}
GfxAnimationState *_newGfxAnimationState(GfxMesh * arg0, const String & arg1) {return _functions->f250(arg0, arg1);}
Audio *_newAudio() {return _functions->f251();}
Audio *_newArrayAudio(size_t count) {return _functions->f252(count);}
Audio *_newAudio(const String & arg0) {return _functions->f253(arg0);}
GfxTexture *_newGfxTexture(const String & arg0) {return _functions->f254(arg0);}
GfxTexture *_newGfxTexture() {return _functions->f255();}
GfxTexture *_newArrayGfxTexture(size_t count) {return _functions->f256(count);}
PhysicsDebugDrawer *_newPhysicsDebugDrawer() {return _functions->f257();}
PhysicsDebugDrawer *_newArrayPhysicsDebugDrawer(size_t count) {return _functions->f258(count);}
Application *_newApplication(const char * arg0) {return _functions->f259(arg0);}
GfxModel *_newGfxModel() {return _functions->f260();}
GfxModel *_newArrayGfxModel(size_t count) {return _functions->f261(count);}
GfxModel *_newGfxModel(const String & arg0) {return _functions->f262(arg0);}
Scene *_newScene() {return _functions->f263();}
Scene *_newArrayScene(size_t count) {return _functions->f264(count);}
Scene *_newScene(const String & arg0) {return _functions->f265(arg0);}
File *_newFile(const char * arg0, const char * arg1) {return _functions->f266(arg0, arg1);}
GfxShaderCombination *_newGfxShaderCombination(GfxShader * arg0, GfxShader * arg1) {return _functions->f267(arg0, arg1);}
Matrix3x3 *_newMatrix3x3() {return _functions->f268();}
Matrix3x3 *_newArrayMatrix3x3(size_t count) {return _functions->f269(count);}
Matrix3x3 *_newMatrix3x3(const Matrix4x4 & arg0) {return _functions->f270(arg0);}
Matrix3x3 *_newMatrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return _functions->f271(arg0, arg1, arg2);}
Font *_newFont() {return _functions->f272();}
Font *_newArrayFont(size_t count) {return _functions->f273(count);}
Font *_newFont(const String & arg0) {return _functions->f274(arg0);}
GfxDebugDrawer *_newGfxDebugDrawer(GfxApi * arg0) {return _functions->f275(arg0);}
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
SerializeException *_new<SerializeException>::f(T0 arg0, T1 arg1, T2 arg2) {return _newSerializeException(arg0, arg1, arg2);}

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

Serializable *_new<Serializable>::f() {return _newSerializable();}

template <typename T0>
Serializable *_new<Serializable>::f(T0 arg0) {return _newSerializable(arg0);}

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

Audio *_new<Audio>::f() {return _newAudio();}

template <typename T0>
Audio *_new<Audio>::f(T0 arg0) {return _newAudio(arg0);}

template <typename T0>
GfxTexture *_new<GfxTexture>::f(T0 arg0) {return _newGfxTexture(arg0);}

GfxTexture *_new<GfxTexture>::f() {return _newGfxTexture();}

PhysicsDebugDrawer *_new<PhysicsDebugDrawer>::f() {return _newPhysicsDebugDrawer();}

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

template <typename T0, typename T1>
GfxShaderCombination *_new<GfxShaderCombination>::f(T0 arg0, T1 arg1) {return _newGfxShaderCombination(arg0, arg1);}

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

Serializable *_newArray<Serializable>::f(size_t count) {return _newArraySerializable(count);}

AABB *_newArray<AABB>::f(size_t count) {return _newArrayAABB(count);}

Audio *_newArray<Audio>::f(size_t count) {return _newArrayAudio(count);}

GfxTexture *_newArray<GfxTexture>::f(size_t count) {return _newArrayGfxTexture(count);}

PhysicsDebugDrawer *_newArray<PhysicsDebugDrawer>::f(size_t count) {return _newArrayPhysicsDebugDrawer(count);}

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

class SerializeException;
template <>
struct _new<SerializeException>
{
    template <typename T0, typename T1, typename T2>
    static SerializeException *f(T0 arg0, T1 arg1, T2 arg2);
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

class Serializable;
template <>
struct _new<Serializable>
{
    static Serializable *f();
    template <typename T0>
    static Serializable *f(T0 arg0);
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
    template <typename T0, typename T1>
    static GfxShaderCombination *f(T0 arg0, T1 arg1);
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

class SerializeException;
template <>
struct _newArray<SerializeException>
{
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

class Serializable;
template <>
struct _newArray<Serializable>
{
    static Serializable *f(size_t count);
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