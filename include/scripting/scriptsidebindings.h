#ifdef _SCRIPT_SIDE_IMPLS
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
    void (*f43)( PhysicsShape *obj);
    void (*f44)( PhysicsShape *obj, float arg0);
    void (*f45)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f46)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f47)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f48)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f49)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f50)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f51)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f52)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f53)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    Vector3D (*f54)(const RigidBody *obj);
    void (*f55)( RigidBody *obj, const Vector3D & arg0);
    void (*f56)( RigidBody *obj, float arg0);
    float (*f57)(const RigidBody *obj);
    void (*f58)( RigidBody *obj, float arg0);
    float (*f59)(const RigidBody *obj);
    void (*f60)(const RigidBody *obj, float arg0);
    float (*f61)(const RigidBody *obj);
    float (*f62)(const RigidBody *obj);
    void (*f63)( RigidBody *obj, float arg0);
    float (*f64)(const RigidBody *obj);
    void (*f65)( RigidBody *obj, float arg0);
    void (*f66)( RigidBody *obj, const Vector3D & arg0);
    void (*f67)( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1);
    void (*f68)( RigidBody *obj, const Vector3D & arg0);
    void (*f69)( RigidBody *obj, const Vector3D & arg0);
    void (*f70)( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1);
    void (*f71)( RigidBody *obj);
    Vector3D (*f72)(const RigidBody *obj);
    void (*f73)(const RigidBody *obj, const Vector3D & arg0);
    Vector3D (*f74)(const RigidBody *obj);
    void (*f75)(const RigidBody *obj, const Vector3D & arg0);
    Vector3D (*f76)(const RigidBody *obj, const Position3D & arg0);
    float (*f77)(const RigidBody *obj);
    void (*f78)( RigidBody *obj, float arg0);
    float (*f79)(const RigidBody *obj);
    void (*f80)( RigidBody *obj, float arg0);
    float (*f81)(const RigidBody *obj);
    void (*f82)( RigidBody *obj, float arg0);
    Float3 (*f83)(const RigidBody *obj);
    void (*f84)(const RigidBody *obj, const Float3 & arg0);
    Float3 (*f85)(const RigidBody *obj);
    void (*f86)(const RigidBody *obj, const Float3 & arg0);
    void (*f87)(const RigidBody *obj, const Transform & arg0);
    void (*f88)( RigidBody *obj);
    void (*f89)( RigidBody *obj, float arg0);
    void (*f90)( RigidBody *obj, const Vector3D & arg0);
    void (*f91)( RigidBody *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f92)( RigidBody *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f93)( RigidBody *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f94)( RigidBody *obj, size_t arg0, const Position3D * arg1);
    void (*f95)( RigidBody *obj, size_t arg0, const Position3D * arg1);
    void (*f96)( RigidBody *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f97)( RigidBody *obj, const Vector3D & arg0, float arg1);
    void (*f98)( RigidBody *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    void (*f99)( RigidBody *obj, ResPtr<PhysicsShape> arg0);
    void (*f100)( Resource *obj);
    bool (*f101)(const Resource *obj);
    void (*f102)( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, uint8_t arg4, GfxTexture::Purpose arg5, GfxTexture::Format arg6);
    void (*f103)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3);
    void (*f104)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f105)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3);
    void (*f106)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f107)( GfxTexture *obj);
    void (*f108)( GfxTexture *obj, float arg0);
    void (*f109)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f110)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f111)( GfxTexture *obj, GfxTexture::MipmapMode arg0);
    void (*f112)( GfxTexture *obj, GfxTexture::WrapMode arg0);
    void (*f113)( GfxTexture *obj, bool arg0);
    void (*f114)( PhysicsShapeImpl *obj);
    void (*f115)( Application *obj);
    void (*f116)( Application *obj, const char * arg0);
    void (*f117)( Application *obj);
    void (*f118)( Scene *obj);
    void (*f119)( Scene *obj);
    void (*f120)( Scene *obj, float arg0);
    Entity * (*f121)( Scene *obj, const String & arg0);
    void (*f122)( Scene *obj, size_t arg0);
    void (*f123)( Entity *obj, PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1);
    void (*f124)( File *obj, size_t arg0, void * arg1);
    void (*f125)( File *obj, size_t arg0, const void * arg1);
    void (*f126)( File *obj, long arg0, File::Origin arg1);
    long (*f127)( File *obj);
    void (*f128)( File *obj);
    bool (*f129)( File *obj);
    size_t (*f130)( File *obj);
    uint8_t (*f131)( File *obj);
    int8_t (*f132)( File *obj);
    uint16_t (*f133)( File *obj);
    int16_t (*f134)( File *obj);
    uint32_t (*f135)( File *obj);
    int32_t (*f136)( File *obj);
    uint64_t (*f137)( File *obj);
    int64_t (*f138)( File *obj);
    uint16_t (*f139)( File *obj);
    int16_t (*f140)( File *obj);
    uint32_t (*f141)( File *obj);
    int32_t (*f142)( File *obj);
    uint64_t (*f143)( File *obj);
    int64_t (*f144)( File *obj);
    float (*f145)( File *obj);
    char (*f146)( File *obj);
    void (*f147)( File *obj, uint8_t arg0);
    void (*f148)( File *obj, int8_t arg0);
    void (*f149)( File *obj, uint16_t arg0);
    void (*f150)( File *obj, int16_t arg0);
    void (*f151)( File *obj, uint32_t arg0);
    void (*f152)( File *obj, int32_t arg0);
    void (*f153)( File *obj, uint64_t arg0);
    void (*f154)( File *obj, int64_t arg0);
    void (*f155)( File *obj, uint16_t arg0);
    void (*f156)( File *obj, int16_t arg0);
    void (*f157)( File *obj, uint32_t arg0);
    void (*f158)( File *obj, int32_t arg0);
    void (*f159)( File *obj, uint64_t arg0);
    void (*f160)( File *obj, int64_t arg0);
    void (*f161)( File *obj, float arg0);
    void (*f162)( File *obj, const char * arg0, va_list arg1);
    void (*f163)( File *obj, char arg0);
    void (*f164)( File *obj, const char * arg0, const char * arg1);
    void (*f165)( File *obj);
    GfxCompiledShader * (*f166)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f167)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f168)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f169)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f170)(const GfxShaderCombination *obj);
    Matrix3x3 (*f171)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f172)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f173)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f174)(const Matrix3x3 *obj);
    Matrix3x3 (*f175)(const Matrix3x3 *obj);
    Matrix3x3 (*f176)(const Float2 & arg0);
    Matrix3x3 (*f177)(const Float3 & arg0);
    Matrix3x3 (*f178)(float arg0);
    Matrix3x3 (*f179)(float arg0);
    Matrix3x3 (*f180)(float arg0);
    Matrix3x3 (*f181)(float arg0);
    void (*f182)( Matrix3x3 *obj);
    void (*f183)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f184)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    void (*f185)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f186)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f187)( GfxDebugDrawer *obj);
    Script *(*f188)(const String & arg0);
    Script *(*f189)(const String & arg0, const String & arg1);
    GfxMaterial *(*f190)(const String & arg0);
    GfxMaterial *(*f191)(const String & arg0, const String & arg1);
    LookupException *(*f192)(const char * arg0, size_t arg1, const char * arg2);
    Quaternion *(*f193)();
    Quaternion *(*f194)(size_t count);
    Quaternion *(*f195)(const Direction3D & arg0, float arg1);
    Quaternion *(*f196)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f197)(const Float3 & arg0);
    Light *(*f198)();
    Light *(*f199)(size_t count);
    PhysicsShape *(*f200)(const String & arg0);
    PhysicsShape *(*f201)(const String & arg0, const String & arg1);
    ShaderCompileException *(*f202)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f203)(const char * arg0, size_t arg1, const char * arg2);
    FileException *(*f204)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    ResourceIOException *(*f205)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxLitMaterialImpl *(*f206)(bool arg0);
    GfxTexture *(*f207)(const String & arg0, const String & arg1);
    GfxTexture *(*f208)(const String & arg0);
    PhysicsShapeImpl *(*f209)();
    PhysicsShapeImpl *(*f210)(size_t count);
    PhysicsDebugDrawer *(*f211)();
    PhysicsDebugDrawer *(*f212)(size_t count);
    Application *(*f213)(const char * arg0);
    GfxModel *(*f214)(const String & arg0);
    GfxModel *(*f215)(const String & arg0, const String & arg1);
    Scene *(*f216)(const String & arg0);
    Scene *(*f217)(const String & arg0, const String & arg1);
    File *(*f218)(const char * arg0, const char * arg1);
    Matrix3x3 *(*f219)();
    Matrix3x3 *(*f220)(size_t count);
    Matrix3x3 *(*f221)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f222)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    GfxDebugDrawer *(*f223)(GfxApi * arg0);
};
const _functionStruct *_functions;
const char ** getBacktrace(unsigned int & arg0) {return _functions->f0(arg0);}
size_t getHash(const String & arg0) {return _functions->f1(arg0);}
bool doesFileExist(const char * arg0) {return _functions->f2(arg0);}
List<String> listFiles(const char * arg0) {return _functions->f3(arg0);}
void setApplication(Application * arg0) { _functions->f4(arg0);}
ScriptInstance * Script::createInstance(Entity * arg0)  {return _functions->f5(this, arg0);}
void GfxMaterial::setMatType(GfxMaterial::MaterialType arg0)  { _functions->f6(this, arg0);}
void GfxRenderer::beginRenderMesh(const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3)  { _functions->f7(arg0, arg1, arg2, arg3);}
void GfxRenderer::endRenderMesh(ResPtr<GfxMesh> arg0)  { _functions->f8(arg0);}
void GfxRenderer::resize(const UInt2 & arg0)  { _functions->f9(this, arg0);}
void GfxRenderer::render()  { _functions->f10(this);}
void GfxRenderer::updateStats()  { _functions->f11(this);}
 GfxRenderer::~GfxRenderer()  { _functions->f12(this);}
Quaternion Quaternion::operator*(const Quaternion & arg0) const {return _functions->f13(this, arg0);}
Matrix4x4 Quaternion::toMatrix() const {return _functions->f14(this);}
Float4 Quaternion::getAxisAndAngle() const {return _functions->f15(this);}
void Quaternion::setAxis(const Direction3D & arg0)  { _functions->f16(this, arg0);}
void Quaternion::setAxisAndAngle(const Direction3D & arg0, float arg1)  { _functions->f17(this, arg0, arg1);}
void Quaternion::setEulerAngles(const Float3 & arg0)  { _functions->f18(this, arg0);}
Float3 Quaternion::getEulerAngles()  {return _functions->f19(this);}
 Quaternion::Quaternion()  { _functions->f20(this);}
 Quaternion::Quaternion(const Direction3D & arg0, float arg1)  { _functions->f21(this, arg0, arg1);}
 Quaternion::Quaternion(float arg0, float arg1, float arg2, float arg3)  { _functions->f22(this, arg0, arg1, arg2, arg3);}
 Quaternion::Quaternion(const Float3 & arg0)  { _functions->f23(this, arg0);}
LogEntry & LogEntry::variable(const char * arg0, uint8_t arg1)  {return _functions->f24(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int8_t arg1)  {return _functions->f25(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint16_t arg1)  {return _functions->f26(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int16_t arg1)  {return _functions->f27(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint32_t arg1)  {return _functions->f28(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int32_t arg1)  {return _functions->f29(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint64_t arg1)  {return _functions->f30(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int64_t arg1)  {return _functions->f31(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, bool arg1)  {return _functions->f32(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, float arg1)  {return _functions->f33(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, double arg1)  {return _functions->f34(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, long double arg1)  {return _functions->f35(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const char * arg1)  {return _functions->f36(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const String & arg1)  {return _functions->f37(this, arg0, arg1);}
LogEntry & LogEntry::printBacktrace()  {return _functions->f38(this);}
LogEntry & LogEntry::printBacktrace(unsigned int arg0, const char ** arg1)  {return _functions->f39(this, arg0, arg1);}
int LogEntry::end()  {return _functions->f40(this);}
int LogEntry::fatalEnd()  {return _functions->f41(this);}
void Light::addShadowmap(size_t arg0, Light::ShadowmapQuality arg1)  { _functions->f42(this, arg0, arg1);}
void PhysicsShape::setEmpty()  { _functions->f43(this);}
void PhysicsShape::setSphere(float arg0)  { _functions->f44(this, arg0);}
void PhysicsShape::setBox(const Vector3D & arg0)  { _functions->f45(this, arg0);}
void PhysicsShape::setCylinder(PhysicsCylinderShape::Axis arg0, float arg1, float arg2)  { _functions->f46(this, arg0, arg1, arg2);}
void PhysicsShape::setCapsule(PhysicsCapsuleShape::Axis arg0, float arg1, float arg2)  { _functions->f47(this, arg0, arg1, arg2);}
void PhysicsShape::setCone(PhysicsConeShape::Axis arg0, float arg1, float arg2)  { _functions->f48(this, arg0, arg1, arg2);}
void PhysicsShape::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f49(this, arg0, arg1);}
void PhysicsShape::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f50(this, arg0, arg1);}
void PhysicsShape::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f51(this, arg0, arg1, arg2);}
void PhysicsShape::setPlane(const Vector3D & arg0, float arg1)  { _functions->f52(this, arg0, arg1);}
void PhysicsShape::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f53(this, arg0, arg1);}
Vector3D RigidBody::getGravity() const {return _functions->f54(this);}
void RigidBody::setGravity(const Vector3D & arg0)  { _functions->f55(this, arg0);}
void RigidBody::setLinearDamping(float arg0)  { _functions->f56(this, arg0);}
float RigidBody::getLinearDamping() const {return _functions->f57(this);}
void RigidBody::setAngularDamping(float arg0)  { _functions->f58(this, arg0);}
float RigidBody::getAngularDamping() const {return _functions->f59(this);}
void RigidBody::setMass(float arg0) const { _functions->f60(this, arg0);}
float RigidBody::getMass() const {return _functions->f61(this);}
float RigidBody::getLinearSleepingThreshold() const {return _functions->f62(this);}
void RigidBody::setLinearSleepingThreshold(float arg0)  { _functions->f63(this, arg0);}
float RigidBody::getAngularSleepingThreshold() const {return _functions->f64(this);}
void RigidBody::setAngularSleepingThreshold(float arg0)  { _functions->f65(this, arg0);}
void RigidBody::applyTorque(const Vector3D & arg0)  { _functions->f66(this, arg0);}
void RigidBody::applyForce(const Vector3D & arg0, const Position3D & arg1)  { _functions->f67(this, arg0, arg1);}
void RigidBody::applyCentralImpulse(const Vector3D & arg0)  { _functions->f68(this, arg0);}
void RigidBody::applyTorqueImpulse(const Vector3D & arg0)  { _functions->f69(this, arg0);}
void RigidBody::applyImpulse(const Vector3D & arg0, const Position3D & arg1)  { _functions->f70(this, arg0, arg1);}
void RigidBody::clearForces()  { _functions->f71(this);}
Vector3D RigidBody::getLinearVelocity() const {return _functions->f72(this);}
void RigidBody::setLinearVelocity(const Vector3D & arg0) const { _functions->f73(this, arg0);}
Vector3D RigidBody::getAngularVelocity() const {return _functions->f74(this);}
void RigidBody::setAngularVelocity(const Vector3D & arg0) const { _functions->f75(this, arg0);}
Vector3D RigidBody::getVelocityOfPoint(const Position3D & arg0) const {return _functions->f76(this, arg0);}
float RigidBody::getRestitution() const {return _functions->f77(this);}
void RigidBody::setRestitution(float arg0)  { _functions->f78(this, arg0);}
float RigidBody::getFriction() const {return _functions->f79(this);}
void RigidBody::setFriction(float arg0)  { _functions->f80(this, arg0);}
float RigidBody::getRollingFriction() const {return _functions->f81(this);}
void RigidBody::setRollingFriction(float arg0)  { _functions->f82(this, arg0);}
Float3 RigidBody::getLinearFactor() const {return _functions->f83(this);}
void RigidBody::setLinearFactor(const Float3 & arg0) const { _functions->f84(this, arg0);}
Float3 RigidBody::getAngularFactor() const {return _functions->f85(this);}
void RigidBody::setAngularFactor(const Float3 & arg0) const { _functions->f86(this, arg0);}
void RigidBody::setTransform(const Transform & arg0) const { _functions->f87(this, arg0);}
void RigidBody::setEmpty()  { _functions->f88(this);}
void RigidBody::setSphere(float arg0)  { _functions->f89(this, arg0);}
void RigidBody::setBox(const Vector3D & arg0)  { _functions->f90(this, arg0);}
void RigidBody::setCylinder(PhysicsCylinderShape::Axis arg0, float arg1, float arg2)  { _functions->f91(this, arg0, arg1, arg2);}
void RigidBody::setCapsule(PhysicsCapsuleShape::Axis arg0, float arg1, float arg2)  { _functions->f92(this, arg0, arg1, arg2);}
void RigidBody::setCone(PhysicsConeShape::Axis arg0, float arg1, float arg2)  { _functions->f93(this, arg0, arg1, arg2);}
void RigidBody::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f94(this, arg0, arg1);}
void RigidBody::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f95(this, arg0, arg1);}
void RigidBody::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f96(this, arg0, arg1, arg2);}
void RigidBody::setPlane(const Vector3D & arg0, float arg1)  { _functions->f97(this, arg0, arg1);}
void RigidBody::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f98(this, arg0, arg1);}
void RigidBody::setShape(ResPtr<PhysicsShape> arg0)  { _functions->f99(this, arg0);}
void Resource::load()  { _functions->f100(this);}
bool Resource::shouldReload() const {return _functions->f101(this);}
void GfxTexture::startCreation(GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, uint8_t arg4, GfxTexture::Purpose arg5, GfxTexture::Format arg6)  { _functions->f102(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6);}
void GfxTexture::allocMipmapFace(unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3)  { _functions->f103(this, arg0, arg1, arg2, arg3);}
void GfxTexture::allocMipmap(unsigned int arg0, unsigned int arg1, const void * arg2)  { _functions->f104(this, arg0, arg1, arg2);}
void GfxTexture::getMipmapFace(unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3)  { _functions->f105(this, arg0, arg1, arg2, arg3);}
void GfxTexture::getMipmap(unsigned int arg0, unsigned int arg1, void * arg2)  { _functions->f106(this, arg0, arg1, arg2);}
void GfxTexture::generateMipmaps()  { _functions->f107(this);}
void GfxTexture::setMaximumAnisotropy(float arg0)  { _functions->f108(this, arg0);}
void GfxTexture::setMinFilter(GfxTexture::Filter arg0)  { _functions->f109(this, arg0);}
void GfxTexture::setMagFilter(GfxTexture::Filter arg0)  { _functions->f110(this, arg0);}
void GfxTexture::setMipmapMode(GfxTexture::MipmapMode arg0)  { _functions->f111(this, arg0);}
void GfxTexture::setWrapMode(GfxTexture::WrapMode arg0)  { _functions->f112(this, arg0);}
void GfxTexture::setShadowmap(bool arg0)  { _functions->f113(this, arg0);}
 PhysicsShapeImpl::PhysicsShapeImpl()  { _functions->f114(this);}
void Application::mainloop()  { _functions->f115(this);}
 Application::Application(const char * arg0)  { _functions->f116(this, arg0);}
 Application::~Application()  { _functions->f117(this);}
void Scene::handleInput()  { _functions->f118(this);}
void Scene::update()  { _functions->f119(this);}
void Scene::fixedUpdate(float arg0)  { _functions->f120(this, arg0);}
Entity * Scene::createEntity(const String & arg0)  {return _functions->f121(this, arg0);}
void Scene::removeEntity(size_t arg0)  { _functions->f122(this, arg0);}
void Entity::addRigidBody(PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1)  { _functions->f123(this, arg0, arg1);}
void File::read(size_t arg0, void * arg1)  { _functions->f124(this, arg0, arg1);}
void File::write(size_t arg0, const void * arg1)  { _functions->f125(this, arg0, arg1);}
void File::seek(long arg0, File::Origin arg1)  { _functions->f126(this, arg0, arg1);}
long File::tell()  {return _functions->f127(this);}
void File::flush()  { _functions->f128(this);}
bool File::isAtEndOfFile()  {return _functions->f129(this);}
size_t File::getSize()  {return _functions->f130(this);}
uint8_t File::readUInt8()  {return _functions->f131(this);}
int8_t File::readInt8()  {return _functions->f132(this);}
uint16_t File::readUInt16LE()  {return _functions->f133(this);}
int16_t File::readInt16LE()  {return _functions->f134(this);}
uint32_t File::readUInt32LE()  {return _functions->f135(this);}
int32_t File::readInt32LE()  {return _functions->f136(this);}
uint64_t File::readUInt64LE()  {return _functions->f137(this);}
int64_t File::readInt64LE()  {return _functions->f138(this);}
uint16_t File::readUInt16BE()  {return _functions->f139(this);}
int16_t File::readInt16BE()  {return _functions->f140(this);}
uint32_t File::readUInt32BE()  {return _functions->f141(this);}
int32_t File::readInt32BE()  {return _functions->f142(this);}
uint64_t File::readUInt64BE()  {return _functions->f143(this);}
int64_t File::readInt64BE()  {return _functions->f144(this);}
float File::readFloat32()  {return _functions->f145(this);}
char File::readChar()  {return _functions->f146(this);}
void File::writeUInt8(uint8_t arg0)  { _functions->f147(this, arg0);}
void File::writeInt8(int8_t arg0)  { _functions->f148(this, arg0);}
void File::writeUInt16LE(uint16_t arg0)  { _functions->f149(this, arg0);}
void File::writeInt16LE(int16_t arg0)  { _functions->f150(this, arg0);}
void File::writeUInt32LE(uint32_t arg0)  { _functions->f151(this, arg0);}
void File::writeInt32LE(int32_t arg0)  { _functions->f152(this, arg0);}
void File::writeUInt64LE(uint64_t arg0)  { _functions->f153(this, arg0);}
void File::writeInt64LE(int64_t arg0)  { _functions->f154(this, arg0);}
void File::writeUInt16BE(uint16_t arg0)  { _functions->f155(this, arg0);}
void File::writeInt16BE(int16_t arg0)  { _functions->f156(this, arg0);}
void File::writeUInt32BE(uint32_t arg0)  { _functions->f157(this, arg0);}
void File::writeInt32BE(int32_t arg0)  { _functions->f158(this, arg0);}
void File::writeUInt64BE(uint64_t arg0)  { _functions->f159(this, arg0);}
void File::writeInt64BE(int64_t arg0)  { _functions->f160(this, arg0);}
void File::writeFloat32(float arg0)  { _functions->f161(this, arg0);}
void File::vprintf(const char * arg0, va_list arg1)  { _functions->f162(this, arg0, arg1);}
void File::writeChar(char arg0)  { _functions->f163(this, arg0);}
 File::File(const char * arg0, const char * arg1)  { _functions->f164(this, arg0, arg1);}
 File::~File()  { _functions->f165(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledVertexShader() const {return _functions->f166(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledTessControlShader() const {return _functions->f167(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledTessEvalShader() const {return _functions->f168(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledGeometryShader() const {return _functions->f169(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledFragmentShader() const {return _functions->f170(this);}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & arg0) const {return _functions->f171(this, arg0);}
Float3 Matrix3x3::operator*(const Float3 & arg0) const {return _functions->f172(this, arg0);}
Matrix3x3 Matrix3x3::operator/(float arg0) const {return _functions->f173(this, arg0);}
Matrix3x3 Matrix3x3::transpose() const {return _functions->f174(this);}
Matrix3x3 Matrix3x3::inverse() const {return _functions->f175(this);}
Matrix3x3 Matrix3x3::translate(const Float2 & arg0)  {return _functions->f176(arg0);}
Matrix3x3 Matrix3x3::scale(const Float3 & arg0)  {return _functions->f177(arg0);}
Matrix3x3 Matrix3x3::rotate(float arg0)  {return _functions->f178(arg0);}
Matrix3x3 Matrix3x3::rotatex(float arg0)  {return _functions->f179(arg0);}
Matrix3x3 Matrix3x3::rotatey(float arg0)  {return _functions->f180(arg0);}
Matrix3x3 Matrix3x3::rotatez(float arg0)  {return _functions->f181(arg0);}
 Matrix3x3::Matrix3x3()  { _functions->f182(this);}
 Matrix3x3::Matrix3x3(const Matrix4x4 & arg0)  { _functions->f183(this, arg0);}
 Matrix3x3::Matrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2)  { _functions->f184(this, arg0, arg1, arg2);}
void GfxDebugDrawer::render(const Camera & arg0)  { _functions->f185(this, arg0);}
 GfxDebugDrawer::GfxDebugDrawer(GfxApi * arg0)  { _functions->f186(this, arg0);}
 GfxDebugDrawer::~GfxDebugDrawer()  { _functions->f187(this);}
Script *_newScript(const String & arg0) {return _functions->f188(arg0);}
Script *_newScript(const String & arg0, const String & arg1) {return _functions->f189(arg0, arg1);}
GfxMaterial *_newGfxMaterial(const String & arg0) {return _functions->f190(arg0);}
GfxMaterial *_newGfxMaterial(const String & arg0, const String & arg1) {return _functions->f191(arg0, arg1);}
LookupException *_newLookupException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f192(arg0, arg1, arg2);}
Quaternion *_newQuaternion() {return _functions->f193();}
Quaternion *_newArrayQuaternion(size_t count) {return _functions->f194(count);}
Quaternion *_newQuaternion(const Direction3D & arg0, float arg1) {return _functions->f195(arg0, arg1);}
Quaternion *_newQuaternion(float arg0, float arg1, float arg2, float arg3) {return _functions->f196(arg0, arg1, arg2, arg3);}
Quaternion *_newQuaternion(const Float3 & arg0) {return _functions->f197(arg0);}
Light *_newLight() {return _functions->f198();}
Light *_newArrayLight(size_t count) {return _functions->f199(count);}
PhysicsShape *_newPhysicsShape(const String & arg0) {return _functions->f200(arg0);}
PhysicsShape *_newPhysicsShape(const String & arg0, const String & arg1) {return _functions->f201(arg0, arg1);}
ShaderCompileException *_newShaderCompileException(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return _functions->f202(arg0, arg1, arg2, arg3);}
Exception *_newException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f203(arg0, arg1, arg2);}
FileException *_newFileException(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return _functions->f204(arg0, arg1, arg2, arg3, arg4);}
ResourceIOException *_newResourceIOException(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return _functions->f205(arg0, arg1, arg2, arg3, arg4, arg5);}
GfxLitMaterialImpl *_newGfxLitMaterialImpl(bool arg0) {return _functions->f206(arg0);}
GfxTexture *_newGfxTexture(const String & arg0, const String & arg1) {return _functions->f207(arg0, arg1);}
GfxTexture *_newGfxTexture(const String & arg0) {return _functions->f208(arg0);}
PhysicsShapeImpl *_newPhysicsShapeImpl() {return _functions->f209();}
PhysicsShapeImpl *_newArrayPhysicsShapeImpl(size_t count) {return _functions->f210(count);}
PhysicsDebugDrawer *_newPhysicsDebugDrawer() {return _functions->f211();}
PhysicsDebugDrawer *_newArrayPhysicsDebugDrawer(size_t count) {return _functions->f212(count);}
Application *_newApplication(const char * arg0) {return _functions->f213(arg0);}
GfxModel *_newGfxModel(const String & arg0) {return _functions->f214(arg0);}
GfxModel *_newGfxModel(const String & arg0, const String & arg1) {return _functions->f215(arg0, arg1);}
Scene *_newScene(const String & arg0) {return _functions->f216(arg0);}
Scene *_newScene(const String & arg0, const String & arg1) {return _functions->f217(arg0, arg1);}
File *_newFile(const char * arg0, const char * arg1) {return _functions->f218(arg0, arg1);}
Matrix3x3 *_newMatrix3x3() {return _functions->f219();}
Matrix3x3 *_newArrayMatrix3x3(size_t count) {return _functions->f220(count);}
Matrix3x3 *_newMatrix3x3(const Matrix4x4 & arg0) {return _functions->f221(arg0);}
Matrix3x3 *_newMatrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return _functions->f222(arg0, arg1, arg2);}
GfxDebugDrawer *_newGfxDebugDrawer(GfxApi * arg0) {return _functions->f223(arg0);}
template <typename T0>
Script *_new<Script>::f(T0 arg0) {return _newScript(arg0);}

template <typename T0, typename T1>
Script *_new<Script>::f(T0 arg0, T1 arg1) {return _newScript(arg0, arg1);}

template <typename T0>
GfxMaterial *_new<GfxMaterial>::f(T0 arg0) {return _newGfxMaterial(arg0);}

template <typename T0, typename T1>
GfxMaterial *_new<GfxMaterial>::f(T0 arg0, T1 arg1) {return _newGfxMaterial(arg0, arg1);}

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

template <typename T0>
PhysicsShape *_new<PhysicsShape>::f(T0 arg0) {return _newPhysicsShape(arg0);}

template <typename T0, typename T1>
PhysicsShape *_new<PhysicsShape>::f(T0 arg0, T1 arg1) {return _newPhysicsShape(arg0, arg1);}

template <typename T0, typename T1, typename T2, typename T3>
ShaderCompileException *_new<ShaderCompileException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {return _newShaderCompileException(arg0, arg1, arg2, arg3);}

template <typename T0, typename T1, typename T2>
Exception *_new<Exception>::f(T0 arg0, T1 arg1, T2 arg2) {return _newException(arg0, arg1, arg2);}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
FileException *_new<FileException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4) {return _newFileException(arg0, arg1, arg2, arg3, arg4);}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
ResourceIOException *_new<ResourceIOException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5) {return _newResourceIOException(arg0, arg1, arg2, arg3, arg4, arg5);}

template <typename T0>
GfxLitMaterialImpl *_new<GfxLitMaterialImpl>::f(T0 arg0) {return _newGfxLitMaterialImpl(arg0);}

template <typename T0, typename T1>
GfxTexture *_new<GfxTexture>::f(T0 arg0, T1 arg1) {return _newGfxTexture(arg0, arg1);}

template <typename T0>
GfxTexture *_new<GfxTexture>::f(T0 arg0) {return _newGfxTexture(arg0);}

PhysicsShapeImpl *_new<PhysicsShapeImpl>::f() {return _newPhysicsShapeImpl();}

PhysicsDebugDrawer *_new<PhysicsDebugDrawer>::f() {return _newPhysicsDebugDrawer();}

template <typename T0>
Application *_new<Application>::f(T0 arg0) {return _newApplication(arg0);}

template <typename T0>
GfxModel *_new<GfxModel>::f(T0 arg0) {return _newGfxModel(arg0);}

template <typename T0, typename T1>
GfxModel *_new<GfxModel>::f(T0 arg0, T1 arg1) {return _newGfxModel(arg0, arg1);}

template <typename T0>
Scene *_new<Scene>::f(T0 arg0) {return _newScene(arg0);}

template <typename T0, typename T1>
Scene *_new<Scene>::f(T0 arg0, T1 arg1) {return _newScene(arg0, arg1);}

template <typename T0, typename T1>
File *_new<File>::f(T0 arg0, T1 arg1) {return _newFile(arg0, arg1);}

Matrix3x3 *_new<Matrix3x3>::f() {return _newMatrix3x3();}

template <typename T0>
Matrix3x3 *_new<Matrix3x3>::f(T0 arg0) {return _newMatrix3x3(arg0);}

template <typename T0, typename T1, typename T2>
Matrix3x3 *_new<Matrix3x3>::f(T0 arg0, T1 arg1, T2 arg2) {return _newMatrix3x3(arg0, arg1, arg2);}

template <typename T0>
GfxDebugDrawer *_new<GfxDebugDrawer>::f(T0 arg0) {return _newGfxDebugDrawer(arg0);}

Quaternion *_newArray<Quaternion>::f(size_t count) {return _newArrayQuaternion(count);}

Light *_newArray<Light>::f(size_t count) {return _newArrayLight(count);}

PhysicsShapeImpl *_newArray<PhysicsShapeImpl>::f(size_t count) {return _newArrayPhysicsShapeImpl(count);}

PhysicsDebugDrawer *_newArray<PhysicsDebugDrawer>::f(size_t count) {return _newArrayPhysicsDebugDrawer(count);}

Matrix3x3 *_newArray<Matrix3x3>::f(size_t count) {return _newArrayMatrix3x3(count);}

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

class Script;
template <>
struct _new<Script>
{
    template <typename T0>
    static Script *f(T0 arg0);
    template <typename T0, typename T1>
    static Script *f(T0 arg0, T1 arg1);
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

class GfxMaterial;
template <>
struct _new<GfxMaterial>
{
    template <typename T0>
    static GfxMaterial *f(T0 arg0);
    template <typename T0, typename T1>
    static GfxMaterial *f(T0 arg0, T1 arg1);
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
    template <typename T0>
    static PhysicsShape *f(T0 arg0);
    template <typename T0, typename T1>
    static PhysicsShape *f(T0 arg0, T1 arg1);
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

class ResourceIOException;
template <>
struct _new<ResourceIOException>
{
    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    static ResourceIOException *f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);
};

class GfxLitMaterialImpl;
template <>
struct _new<GfxLitMaterialImpl>
{
    template <typename T0>
    static GfxLitMaterialImpl *f(T0 arg0);
};

class Filesystem;
template <>
struct _new<Filesystem>
{
};

class GfxTexture;
template <>
struct _new<GfxTexture>
{
    template <typename T0, typename T1>
    static GfxTexture *f(T0 arg0, T1 arg1);
    template <typename T0>
    static GfxTexture *f(T0 arg0);
};

class PhysicsShapeImpl;
template <>
struct _new<PhysicsShapeImpl>
{
    static PhysicsShapeImpl *f();
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
    template <typename T0>
    static GfxModel *f(T0 arg0);
    template <typename T0, typename T1>
    static GfxModel *f(T0 arg0, T1 arg1);
};

class Scene;
template <>
struct _new<Scene>
{
    template <typename T0>
    static Scene *f(T0 arg0);
    template <typename T0, typename T1>
    static Scene *f(T0 arg0, T1 arg1);
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

class Script;
template <>
struct _newArray<Script>
{
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

class GfxMaterial;
template <>
struct _newArray<GfxMaterial>
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

class ResourceIOException;
template <>
struct _newArray<ResourceIOException>
{
};

class GfxLitMaterialImpl;
template <>
struct _newArray<GfxLitMaterialImpl>
{
};

class Filesystem;
template <>
struct _newArray<Filesystem>
{
};

class GfxTexture;
template <>
struct _newArray<GfxTexture>
{
};

class PhysicsShapeImpl;
template <>
struct _newArray<PhysicsShapeImpl>
{
    static PhysicsShapeImpl *f(size_t count);
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
};

class Scene;
template <>
struct _newArray<Scene>
{
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

class Matrix3x3;
template <>
struct _newArray<Matrix3x3>
{
    static Matrix3x3 *f(size_t count);
};

class GfxDebugDrawer;
template <>
struct _newArray<GfxDebugDrawer>
{
};

#endif