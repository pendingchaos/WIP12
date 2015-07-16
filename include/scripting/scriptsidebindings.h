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
const _functionStruct *_functions;
const char ** getBacktrace(unsigned int & arg0) {return _functions->f0(arg0);}
size_t getHash(const String & arg0) {return _functions->f1(arg0);}
bool doesFileExist(const char * arg0) {return _functions->f2(arg0);}
List<String> listFiles(const char * arg0) {return _functions->f3(arg0);}
void setApplication(Application * arg0) { _functions->f4(arg0);}
ScriptInstance * Script::createInstance(const char * arg0, Entity * arg1, Scene * arg2)  {return _functions->f5(this, arg0, arg1, arg2);}
Matrix4x4 Transform::createMatrix() const {return _functions->f6(this);}
 Transform::Transform()  { _functions->f7(this);}
String AudioDevice::getName()  {return _functions->f8(this);}
String AudioDevice::getName(size_t arg0)  {return _functions->f9(arg0);}
size_t AudioDevice::getDeviceCount()  {return _functions->f10();}
void AudioDevice::setIndex(size_t arg0)  { _functions->f11(this, arg0);}
void AudioDevice::setFrequency(size_t arg0)  { _functions->f12(this, arg0);}
void AudioDevice::setSamples(size_t arg0)  { _functions->f13(this, arg0);}
void AudioDevice::pause()  { _functions->f14(this);}
void AudioDevice::play()  { _functions->f15(this);}
bool AudioDevice::getPaused()  {return _functions->f16(this);}
void AudioDevice::runCallbacks(size_t arg0)  { _functions->f17(this, arg0);}
 AudioDevice::AudioDevice(size_t arg0, size_t arg1, size_t arg2)  { _functions->f18(this, arg0, arg1, arg2);}
 AudioDevice::~AudioDevice()  { _functions->f19(this);}
void GfxMaterial::setDisplacementMap(GfxTexture * arg0)  { _functions->f20(this, arg0);}
void GfxMaterial::setForward(bool arg0)  { _functions->f21(this, arg0);}
void GfxRenderer::beginRenderMesh(const Camera & arg0, const Matrix4x4 & arg1, GfxMesh * arg2, GfxShaderCombination * arg3)  { _functions->f22(arg0, arg1, arg2, arg3);}
void GfxRenderer::endRenderMesh(GfxMesh * arg0)  { _functions->f23(arg0);}
void GfxRenderer::resize(const UInt2 & arg0)  { _functions->f24(this, arg0);}
void GfxRenderer::render()  { _functions->f25(this);}
AABB GfxRenderer::computeSceneAABB() const {return _functions->f26(this);}
AABB GfxRenderer::computeShadowCasterAABB() const {return _functions->f27(this);}
void GfxRenderer::updateStats()  { _functions->f28(this);}
void GfxRenderer::updateColorModifierShader()  { _functions->f29(this);}
 GfxRenderer::~GfxRenderer()  { _functions->f30(this);}
Quaternion Quaternion::operator*(const Quaternion & arg0) const {return _functions->f31(this, arg0);}
Matrix4x4 Quaternion::toMatrix() const {return _functions->f32(this);}
Float4 Quaternion::getAxisAndAngle() const {return _functions->f33(this);}
void Quaternion::setAxis(const Direction3D & arg0)  { _functions->f34(this, arg0);}
void Quaternion::setAxisAndAngle(const Direction3D & arg0, float arg1)  { _functions->f35(this, arg0, arg1);}
void Quaternion::setEulerAngles(const Float3 & arg0)  { _functions->f36(this, arg0);}
Float3 Quaternion::getEulerAngles()  {return _functions->f37(this);}
 Quaternion::Quaternion()  { _functions->f38(this);}
 Quaternion::Quaternion(const Direction3D & arg0, float arg1)  { _functions->f39(this, arg0, arg1);}
 Quaternion::Quaternion(float arg0, float arg1, float arg2, float arg3)  { _functions->f40(this, arg0, arg1, arg2, arg3);}
 Quaternion::Quaternion(const Float3 & arg0)  { _functions->f41(this, arg0);}
LogEntry & LogEntry::variable(const char * arg0, uint8_t arg1)  {return _functions->f42(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int8_t arg1)  {return _functions->f43(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint16_t arg1)  {return _functions->f44(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int16_t arg1)  {return _functions->f45(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint32_t arg1)  {return _functions->f46(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int32_t arg1)  {return _functions->f47(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint64_t arg1)  {return _functions->f48(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int64_t arg1)  {return _functions->f49(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, bool arg1)  {return _functions->f50(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, float arg1)  {return _functions->f51(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, double arg1)  {return _functions->f52(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, long double arg1)  {return _functions->f53(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const char * arg1)  {return _functions->f54(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const String & arg1)  {return _functions->f55(this, arg0, arg1);}
LogEntry & LogEntry::printBacktrace()  {return _functions->f56(this);}
LogEntry & LogEntry::printBacktrace(unsigned int arg0, const char ** arg1)  {return _functions->f57(this, arg0, arg1);}
int LogEntry::end()  {return _functions->f58(this);}
int LogEntry::fatalEnd()  {return _functions->f59(this);}
void Light::addShadowmap(size_t arg0, Light::ShadowmapPrecision arg1)  { _functions->f60(this, arg0, arg1);}
void Light::updateMatrices(GfxRenderer * arg0)  { _functions->f61(this, arg0);}
void PhysicsShape::setEmpty()  { _functions->f62(this);}
void PhysicsShape::setSphere(float arg0)  { _functions->f63(this, arg0);}
void PhysicsShape::setBox(const Vector3D & arg0)  { _functions->f64(this, arg0);}
void PhysicsShape::setCylinder(PhysicsCylinderShape::Axis arg0, float arg1, float arg2)  { _functions->f65(this, arg0, arg1, arg2);}
void PhysicsShape::setCapsule(PhysicsCapsuleShape::Axis arg0, float arg1, float arg2)  { _functions->f66(this, arg0, arg1, arg2);}
void PhysicsShape::setCone(PhysicsConeShape::Axis arg0, float arg1, float arg2)  { _functions->f67(this, arg0, arg1, arg2);}
void PhysicsShape::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f68(this, arg0, arg1);}
void PhysicsShape::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f69(this, arg0, arg1);}
void PhysicsShape::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f70(this, arg0, arg1, arg2);}
void PhysicsShape::setPlane(const Vector3D & arg0, float arg1)  { _functions->f71(this, arg0, arg1);}
void PhysicsShape::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f72(this, arg0, arg1);}
bool Serializable::operator==(const Serializable & arg0) const {return _functions->f73(this, arg0);}
void Serializable::writeToFile(File * arg0)  { _functions->f74(this, arg0);}
void Serializable::readFromFile(File * arg0)  { _functions->f75(this, arg0);}
void Resource::load()  { _functions->f76(this);}
bool Resource::shouldReload() const {return _functions->f77(this);}
void GfxTexture::startCreation(GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, uint8_t arg5, GfxTexture::Purpose arg6, GfxTexture::Format arg7)  { _functions->f78(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);}
void GfxTexture::allocMipmapFace(unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3)  { _functions->f79(this, arg0, arg1, arg2, arg3);}
void GfxTexture::allocMipmap(unsigned int arg0, unsigned int arg1, const void * arg2)  { _functions->f80(this, arg0, arg1, arg2);}
void GfxTexture::getMipmapFace(unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3) const { _functions->f81(this, arg0, arg1, arg2, arg3);}
void GfxTexture::getMipmap(unsigned int arg0, unsigned int arg1, void * arg2) const { _functions->f82(this, arg0, arg1, arg2);}
void GfxTexture::generateMipmaps()  { _functions->f83(this);}
void GfxTexture::setMaximumAnisotropy(float arg0)  { _functions->f84(this, arg0);}
void GfxTexture::setMinFilter(GfxTexture::Filter arg0)  { _functions->f85(this, arg0);}
void GfxTexture::setMagFilter(GfxTexture::Filter arg0)  { _functions->f86(this, arg0);}
void GfxTexture::setMipmapMode(GfxTexture::MipmapMode arg0)  { _functions->f87(this, arg0);}
void GfxTexture::setWrapMode(GfxTexture::WrapMode arg0)  { _functions->f88(this, arg0);}
void GfxTexture::setShadowmap(bool arg0)  { _functions->f89(this, arg0);}
Transform GhostObject::getTransform()  {return _functions->f90(this);}
void GhostObject::setTransform(const Transform & arg0) const { _functions->f91(this, arg0);}
void GhostObject::setShape(PhysicsShape * arg0)  { _functions->f92(this, arg0);}
void GhostObject::getCollisions(List<RigidBody *> & arg0, List<GhostObject *> & arg1) const { _functions->f93(this, arg0, arg1);}
void Application::mainloop()  { _functions->f94(this);}
 Application::Application(const char * arg0)  { _functions->f95(this, arg0);}
 Application::~Application()  { _functions->f96(this);}
void Scene::handleInput()  { _functions->f97(this);}
void Scene::update()  { _functions->f98(this);}
void Scene::fixedUpdate(float arg0)  { _functions->f99(this, arg0);}
void Scene::render()  { _functions->f100(this);}
Entity * Scene::createEntity(const String & arg0)  {return _functions->f101(this, arg0);}
void Scene::removeEntity(size_t arg0)  { _functions->f102(this, arg0);}
RigidBody * Entity::addRigidBody(const RigidBody::ConstructionInfo & arg0, PhysicsShape * arg1)  {return _functions->f103(this, arg0, arg1);}
Scene * Entity::getScene() const {return _functions->f104(this);}
Entity * Entity::createEntity(const String & arg0)  {return _functions->f105(this, arg0);}
void Entity::removeEntity(size_t arg0)  { _functions->f106(this, arg0);}
void Entity::updateFinalTransform()  { _functions->f107(this);}
AudioSource * Entity::addAudioSource(Audio * arg0)  {return _functions->f108(this, arg0);}
void Entity::removeAudioSource(size_t arg0)  { _functions->f109(this, arg0);}
void File::read(size_t arg0, void * arg1)  { _functions->f110(this, arg0, arg1);}
void File::write(size_t arg0, const void * arg1)  { _functions->f111(this, arg0, arg1);}
void File::seek(long arg0, File::Origin arg1)  { _functions->f112(this, arg0, arg1);}
long File::tell()  {return _functions->f113(this);}
void File::flush()  { _functions->f114(this);}
bool File::isAtEndOfFile()  {return _functions->f115(this);}
size_t File::getSize()  {return _functions->f116(this);}
uint8_t File::readUInt8()  {return _functions->f117(this);}
int8_t File::readInt8()  {return _functions->f118(this);}
uint16_t File::readUInt16LE()  {return _functions->f119(this);}
int16_t File::readInt16LE()  {return _functions->f120(this);}
uint32_t File::readUInt32LE()  {return _functions->f121(this);}
int32_t File::readInt32LE()  {return _functions->f122(this);}
uint64_t File::readUInt64LE()  {return _functions->f123(this);}
int64_t File::readInt64LE()  {return _functions->f124(this);}
uint16_t File::readUInt16BE()  {return _functions->f125(this);}
int16_t File::readInt16BE()  {return _functions->f126(this);}
uint32_t File::readUInt32BE()  {return _functions->f127(this);}
int32_t File::readInt32BE()  {return _functions->f128(this);}
uint64_t File::readUInt64BE()  {return _functions->f129(this);}
int64_t File::readInt64BE()  {return _functions->f130(this);}
float File::readFloat32()  {return _functions->f131(this);}
char File::readChar()  {return _functions->f132(this);}
void File::writeUInt8(uint8_t arg0)  { _functions->f133(this, arg0);}
void File::writeInt8(int8_t arg0)  { _functions->f134(this, arg0);}
void File::writeUInt16LE(uint16_t arg0)  { _functions->f135(this, arg0);}
void File::writeInt16LE(int16_t arg0)  { _functions->f136(this, arg0);}
void File::writeUInt32LE(uint32_t arg0)  { _functions->f137(this, arg0);}
void File::writeInt32LE(int32_t arg0)  { _functions->f138(this, arg0);}
void File::writeUInt64LE(uint64_t arg0)  { _functions->f139(this, arg0);}
void File::writeInt64LE(int64_t arg0)  { _functions->f140(this, arg0);}
void File::writeUInt16BE(uint16_t arg0)  { _functions->f141(this, arg0);}
void File::writeInt16BE(int16_t arg0)  { _functions->f142(this, arg0);}
void File::writeUInt32BE(uint32_t arg0)  { _functions->f143(this, arg0);}
void File::writeInt32BE(int32_t arg0)  { _functions->f144(this, arg0);}
void File::writeUInt64BE(uint64_t arg0)  { _functions->f145(this, arg0);}
void File::writeInt64BE(int64_t arg0)  { _functions->f146(this, arg0);}
void File::writeFloat32(float arg0)  { _functions->f147(this, arg0);}
void File::vprintf(const char * arg0, va_list arg1)  { _functions->f148(this, arg0, arg1);}
void File::writeChar(char arg0)  { _functions->f149(this, arg0);}
 File::File(const char * arg0, const char * arg1)  { _functions->f150(this, arg0, arg1);}
 File::~File()  { _functions->f151(this);}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & arg0) const {return _functions->f152(this, arg0);}
Float3 Matrix3x3::operator*(const Float3 & arg0) const {return _functions->f153(this, arg0);}
Matrix3x3 Matrix3x3::operator/(float arg0) const {return _functions->f154(this, arg0);}
Matrix3x3 Matrix3x3::transpose() const {return _functions->f155(this);}
Matrix3x3 Matrix3x3::inverse() const {return _functions->f156(this);}
Matrix3x3 Matrix3x3::translate(const Float2 & arg0)  {return _functions->f157(arg0);}
Matrix3x3 Matrix3x3::scale(const Float3 & arg0)  {return _functions->f158(arg0);}
Matrix3x3 Matrix3x3::rotate(float arg0)  {return _functions->f159(arg0);}
Matrix3x3 Matrix3x3::rotatex(float arg0)  {return _functions->f160(arg0);}
Matrix3x3 Matrix3x3::rotatey(float arg0)  {return _functions->f161(arg0);}
Matrix3x3 Matrix3x3::rotatez(float arg0)  {return _functions->f162(arg0);}
 Matrix3x3::Matrix3x3()  { _functions->f163(this);}
 Matrix3x3::Matrix3x3(const Matrix4x4 & arg0)  { _functions->f164(this, arg0);}
 Matrix3x3::Matrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2)  { _functions->f165(this, arg0, arg1, arg2);}
void Font::render(size_t arg0, const Float2 & arg1, const char * arg2, GfxFramebuffer * arg3, const Float3 & arg4)  { _functions->f166(this, arg0, arg1, arg2, arg3, arg4);}
void GfxDebugDrawer::render(const Camera & arg0)  { _functions->f167(this, arg0);}
 GfxDebugDrawer::GfxDebugDrawer(GfxApi * arg0)  { _functions->f168(this, arg0);}
 GfxDebugDrawer::~GfxDebugDrawer()  { _functions->f169(this);}
AudioSource *_newAudioSource(Audio * arg0) {return _functions->f170(arg0);}
Script *_newScript() {return _functions->f171();}
Script *_newArrayScript(size_t count) {return _functions->f172(count);}
Script *_newScript(const String & arg0) {return _functions->f173(arg0);}
Transform *_newTransform() {return _functions->f174();}
Transform *_newArrayTransform(size_t count) {return _functions->f175(count);}
AudioDevice *_newAudioDevice(size_t arg0, size_t arg1, size_t arg2) {return _functions->f176(arg0, arg1, arg2);}
GfxMaterial *_newGfxMaterial() {return _functions->f177();}
GfxMaterial *_newArrayGfxMaterial(size_t count) {return _functions->f178(count);}
GfxMaterial *_newGfxMaterial(const String & arg0) {return _functions->f179(arg0);}
SerializeException *_newSerializeException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f180(arg0, arg1, arg2);}
LookupException *_newLookupException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f181(arg0, arg1, arg2);}
Quaternion *_newQuaternion() {return _functions->f182();}
Quaternion *_newArrayQuaternion(size_t count) {return _functions->f183(count);}
Quaternion *_newQuaternion(const Direction3D & arg0, float arg1) {return _functions->f184(arg0, arg1);}
Quaternion *_newQuaternion(float arg0, float arg1, float arg2, float arg3) {return _functions->f185(arg0, arg1, arg2, arg3);}
Quaternion *_newQuaternion(const Float3 & arg0) {return _functions->f186(arg0);}
Light *_newLight() {return _functions->f187();}
Light *_newArrayLight(size_t count) {return _functions->f188(count);}
PhysicsShape *_newPhysicsShape() {return _functions->f189();}
PhysicsShape *_newArrayPhysicsShape(size_t count) {return _functions->f190(count);}
PhysicsShape *_newPhysicsShape(const String & arg0) {return _functions->f191(arg0);}
Serializable *_newSerializable() {return _functions->f192();}
Serializable *_newArraySerializable(size_t count) {return _functions->f193(count);}
Serializable *_newSerializable(uint8_t arg0) {return _functions->f194(arg0);}
Serializable *_newSerializable(int8_t arg0) {return _functions->f195(arg0);}
Serializable *_newSerializable(uint16_t arg0) {return _functions->f196(arg0);}
Serializable *_newSerializable(int16_t arg0) {return _functions->f197(arg0);}
Serializable *_newSerializable(uint32_t arg0) {return _functions->f198(arg0);}
Serializable *_newSerializable(int32_t arg0) {return _functions->f199(arg0);}
Serializable *_newSerializable(uint64_t arg0) {return _functions->f200(arg0);}
Serializable *_newSerializable(int64_t arg0) {return _functions->f201(arg0);}
Serializable *_newSerializable(const String & arg0) {return _functions->f202(arg0);}
Serializable *_newSerializable(bool arg0) {return _functions->f203(arg0);}
Serializable *_newSerializable(float arg0) {return _functions->f204(arg0);}
Serializable *_newSerializable(const Float2 & arg0) {return _functions->f205(arg0);}
Serializable *_newSerializable(const Float3 & arg0) {return _functions->f206(arg0);}
Serializable *_newSerializable(const Float4 & arg0) {return _functions->f207(arg0);}
Serializable *_newSerializable(const Int2 & arg0) {return _functions->f208(arg0);}
Serializable *_newSerializable(const Int3 & arg0) {return _functions->f209(arg0);}
Serializable *_newSerializable(const Int4 & arg0) {return _functions->f210(arg0);}
Serializable *_newSerializable(const UInt2 & arg0) {return _functions->f211(arg0);}
Serializable *_newSerializable(const UInt3 & arg0) {return _functions->f212(arg0);}
Serializable *_newSerializable(const UInt4 & arg0) {return _functions->f213(arg0);}
ShaderCompileException *_newShaderCompileException(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return _functions->f214(arg0, arg1, arg2, arg3);}
Exception *_newException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f215(arg0, arg1, arg2);}
FileException *_newFileException(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return _functions->f216(arg0, arg1, arg2, arg3, arg4);}
AABB *_newAABB() {return _functions->f217();}
AABB *_newArrayAABB(size_t count) {return _functions->f218(count);}
AABB *_newAABB(const Position3D & arg0, const Position3D & arg1) {return _functions->f219(arg0, arg1);}
ResourceIOException *_newResourceIOException(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return _functions->f220(arg0, arg1, arg2, arg3, arg4, arg5);}
Audio *_newAudio() {return _functions->f221();}
Audio *_newArrayAudio(size_t count) {return _functions->f222(count);}
Audio *_newAudio(const String & arg0) {return _functions->f223(arg0);}
GfxTexture *_newGfxTexture(const String & arg0) {return _functions->f224(arg0);}
GfxTexture *_newGfxTexture() {return _functions->f225();}
GfxTexture *_newArrayGfxTexture(size_t count) {return _functions->f226(count);}
PhysicsDebugDrawer *_newPhysicsDebugDrawer() {return _functions->f227();}
PhysicsDebugDrawer *_newArrayPhysicsDebugDrawer(size_t count) {return _functions->f228(count);}
Application *_newApplication(const char * arg0) {return _functions->f229(arg0);}
GfxModel *_newGfxModel() {return _functions->f230();}
GfxModel *_newArrayGfxModel(size_t count) {return _functions->f231(count);}
GfxModel *_newGfxModel(const String & arg0) {return _functions->f232(arg0);}
Scene *_newScene() {return _functions->f233();}
Scene *_newArrayScene(size_t count) {return _functions->f234(count);}
Scene *_newScene(const String & arg0) {return _functions->f235(arg0);}
File *_newFile(const char * arg0, const char * arg1) {return _functions->f236(arg0, arg1);}
GfxShaderCombination *_newGfxShaderCombination(GfxShader * arg0, GfxShader * arg1) {return _functions->f237(arg0, arg1);}
Matrix3x3 *_newMatrix3x3() {return _functions->f238();}
Matrix3x3 *_newArrayMatrix3x3(size_t count) {return _functions->f239(count);}
Matrix3x3 *_newMatrix3x3(const Matrix4x4 & arg0) {return _functions->f240(arg0);}
Matrix3x3 *_newMatrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return _functions->f241(arg0, arg1, arg2);}
Font *_newFont() {return _functions->f242();}
Font *_newArrayFont(size_t count) {return _functions->f243(count);}
Font *_newFont(const String & arg0) {return _functions->f244(arg0);}
GfxDebugDrawer *_newGfxDebugDrawer(GfxApi * arg0) {return _functions->f245(arg0);}
template <typename T0>
AudioSource *_new<AudioSource>::f(T0 arg0) {return _newAudioSource(arg0);}

Script *_new<Script>::f() {return _newScript();}

template <typename T0>
Script *_new<Script>::f(T0 arg0) {return _newScript(arg0);}

Transform *_new<Transform>::f() {return _newTransform();}

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