#ifdef _SCRIPT_SIDE_IMPLS
struct _functionStruct
{
    const char ** (*f0)(unsigned int & arg0);
    size_t (*f1)(const String & arg0);
    bool (*f2)(const char * arg0);
    List<String> (*f3)(const char * arg0);
    void (*f4)(Application * arg0);
    ScriptInstance * (*f5)( Script *obj, Entity * arg0);
    void (*f6)( GfxRenderer *obj, const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3);
    void (*f7)( GfxRenderer *obj, ResPtr<GfxMesh> arg0);
    void (*f8)( GfxRenderer *obj, const ResPtr<Scene> arg0);
    void (*f9)( GfxRenderer *obj);
    void (*f10)( GfxRenderer *obj);
    Quaternion (*f11)(const Quaternion *obj, const Quaternion & arg0);
    Matrix4x4 (*f12)(const Quaternion *obj);
    Float4 (*f13)(const Quaternion *obj);
    void (*f14)( Quaternion *obj, const Direction3D & arg0);
    void (*f15)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f16)( Quaternion *obj, const Float3 & arg0);
    Float3 (*f17)( Quaternion *obj);
    void (*f18)( Quaternion *obj);
    void (*f19)( Quaternion *obj, const Direction3D & arg0, float arg1);
    void (*f20)( Quaternion *obj, float arg0, float arg1, float arg2, float arg3);
    void (*f21)( Quaternion *obj, const Float3 & arg0);
    LogEntry & (*f22)( LogEntry *obj, const char * arg0, uint8_t arg1);
    LogEntry & (*f23)( LogEntry *obj, const char * arg0, int8_t arg1);
    LogEntry & (*f24)( LogEntry *obj, const char * arg0, uint16_t arg1);
    LogEntry & (*f25)( LogEntry *obj, const char * arg0, int16_t arg1);
    LogEntry & (*f26)( LogEntry *obj, const char * arg0, uint32_t arg1);
    LogEntry & (*f27)( LogEntry *obj, const char * arg0, int32_t arg1);
    LogEntry & (*f28)( LogEntry *obj, const char * arg0, uint64_t arg1);
    LogEntry & (*f29)( LogEntry *obj, const char * arg0, int64_t arg1);
    LogEntry & (*f30)( LogEntry *obj, const char * arg0, bool arg1);
    LogEntry & (*f31)( LogEntry *obj, const char * arg0, float arg1);
    LogEntry & (*f32)( LogEntry *obj, const char * arg0, double arg1);
    LogEntry & (*f33)( LogEntry *obj, const char * arg0, long double arg1);
    LogEntry & (*f34)( LogEntry *obj, const char * arg0, const char * arg1);
    LogEntry & (*f35)( LogEntry *obj, const char * arg0, const String & arg1);
    LogEntry & (*f36)( LogEntry *obj);
    LogEntry & (*f37)( LogEntry *obj, unsigned int arg0, const char ** arg1);
    int (*f38)( LogEntry *obj);
    int (*f39)( LogEntry *obj);
    void (*f40)( PhysicsShape *obj);
    void (*f41)( PhysicsShape *obj, float arg0);
    void (*f42)( PhysicsShape *obj, const Vector3D & arg0);
    void (*f43)( PhysicsShape *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f44)( PhysicsShape *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f45)( PhysicsShape *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f46)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f47)( PhysicsShape *obj, size_t arg0, const Position3D * arg1);
    void (*f48)( PhysicsShape *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f49)( PhysicsShape *obj, const Vector3D & arg0, float arg1);
    void (*f50)( PhysicsShape *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    Vector3D (*f51)(const RigidBody *obj);
    void (*f52)( RigidBody *obj, const Vector3D & arg0);
    void (*f53)( RigidBody *obj, float arg0);
    float (*f54)(const RigidBody *obj);
    void (*f55)( RigidBody *obj, float arg0);
    float (*f56)(const RigidBody *obj);
    void (*f57)(const RigidBody *obj, float arg0);
    float (*f58)(const RigidBody *obj);
    float (*f59)(const RigidBody *obj);
    void (*f60)( RigidBody *obj, float arg0);
    float (*f61)(const RigidBody *obj);
    void (*f62)( RigidBody *obj, float arg0);
    void (*f63)( RigidBody *obj, const Vector3D & arg0);
    void (*f64)( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1);
    void (*f65)( RigidBody *obj, const Vector3D & arg0);
    void (*f66)( RigidBody *obj, const Vector3D & arg0);
    void (*f67)( RigidBody *obj, const Vector3D & arg0, const Position3D & arg1);
    void (*f68)( RigidBody *obj);
    Vector3D (*f69)(const RigidBody *obj);
    void (*f70)(const RigidBody *obj, const Vector3D & arg0);
    Vector3D (*f71)(const RigidBody *obj);
    void (*f72)(const RigidBody *obj, const Vector3D & arg0);
    Vector3D (*f73)(const RigidBody *obj, const Position3D & arg0);
    float (*f74)(const RigidBody *obj);
    void (*f75)( RigidBody *obj, float arg0);
    float (*f76)(const RigidBody *obj);
    void (*f77)( RigidBody *obj, float arg0);
    float (*f78)(const RigidBody *obj);
    void (*f79)( RigidBody *obj, float arg0);
    Float3 (*f80)(const RigidBody *obj);
    void (*f81)(const RigidBody *obj, const Float3 & arg0);
    Float3 (*f82)(const RigidBody *obj);
    void (*f83)(const RigidBody *obj, const Float3 & arg0);
    void (*f84)(const RigidBody *obj, const Transform & arg0);
    void (*f85)( RigidBody *obj);
    void (*f86)( RigidBody *obj, float arg0);
    void (*f87)( RigidBody *obj, const Vector3D & arg0);
    void (*f88)( RigidBody *obj, PhysicsCylinderShape::Axis arg0, float arg1, float arg2);
    void (*f89)( RigidBody *obj, PhysicsCapsuleShape::Axis arg0, float arg1, float arg2);
    void (*f90)( RigidBody *obj, PhysicsConeShape::Axis arg0, float arg1, float arg2);
    void (*f91)( RigidBody *obj, size_t arg0, const Position3D * arg1);
    void (*f92)( RigidBody *obj, size_t arg0, const Position3D * arg1);
    void (*f93)( RigidBody *obj, uint32_t arg0, uint32_t arg1, const float * arg2);
    void (*f94)( RigidBody *obj, const Vector3D & arg0, float arg1);
    void (*f95)( RigidBody *obj, size_t arg0, const PhysicsCompoundShape::Child * arg1);
    void (*f96)( RigidBody *obj, ResPtr<PhysicsShape> arg0);
    void (*f97)( Resource *obj);
    bool (*f98)(const Resource *obj);
    void (*f99)( GfxTexture *obj, GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, uint8_t arg4, GfxTexture::Purpose arg5, GfxTexture::Format arg6);
    void (*f100)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3);
    void (*f101)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, const void * arg2);
    void (*f102)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3);
    void (*f103)( GfxTexture *obj, unsigned int arg0, unsigned int arg1, void * arg2);
    void (*f104)( GfxTexture *obj, float arg0);
    void (*f105)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f106)( GfxTexture *obj, GfxTexture::Filter arg0);
    void (*f107)( GfxTexture *obj, GfxTexture::MipmapMode arg0);
    void (*f108)( GfxTexture *obj, GfxTexture::WrapMode arg0);
    void (*f109)( PhysicsShapeImpl *obj);
    void (*f110)( Application *obj);
    void (*f111)( Application *obj, const char * arg0);
    void (*f112)( Application *obj);
    void (*f113)( Scene *obj);
    void (*f114)( Scene *obj);
    void (*f115)( Scene *obj, float arg0);
    Entity * (*f116)( Scene *obj, const String & arg0);
    void (*f117)( Scene *obj, size_t arg0);
    void (*f118)( Entity *obj, PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1);
    void (*f119)( File *obj, size_t arg0, void * arg1);
    void (*f120)( File *obj, size_t arg0, const void * arg1);
    void (*f121)( File *obj, long arg0, File::Origin arg1);
    long (*f122)( File *obj);
    void (*f123)( File *obj);
    bool (*f124)( File *obj);
    size_t (*f125)( File *obj);
    uint8_t (*f126)( File *obj);
    int8_t (*f127)( File *obj);
    uint16_t (*f128)( File *obj);
    int16_t (*f129)( File *obj);
    uint32_t (*f130)( File *obj);
    int32_t (*f131)( File *obj);
    uint64_t (*f132)( File *obj);
    int64_t (*f133)( File *obj);
    uint16_t (*f134)( File *obj);
    int16_t (*f135)( File *obj);
    uint32_t (*f136)( File *obj);
    int32_t (*f137)( File *obj);
    uint64_t (*f138)( File *obj);
    int64_t (*f139)( File *obj);
    float (*f140)( File *obj);
    char (*f141)( File *obj);
    void (*f142)( File *obj, uint8_t arg0);
    void (*f143)( File *obj, int8_t arg0);
    void (*f144)( File *obj, uint16_t arg0);
    void (*f145)( File *obj, int16_t arg0);
    void (*f146)( File *obj, uint32_t arg0);
    void (*f147)( File *obj, int32_t arg0);
    void (*f148)( File *obj, uint64_t arg0);
    void (*f149)( File *obj, int64_t arg0);
    void (*f150)( File *obj, uint16_t arg0);
    void (*f151)( File *obj, int16_t arg0);
    void (*f152)( File *obj, uint32_t arg0);
    void (*f153)( File *obj, int32_t arg0);
    void (*f154)( File *obj, uint64_t arg0);
    void (*f155)( File *obj, int64_t arg0);
    void (*f156)( File *obj, float arg0);
    void (*f157)( File *obj, const char * arg0, va_list arg1);
    void (*f158)( File *obj, char arg0);
    void (*f159)( File *obj, const char * arg0, const char * arg1);
    void (*f160)( File *obj);
    GfxCompiledShader * (*f161)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f162)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f163)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f164)(const GfxShaderCombination *obj);
    GfxCompiledShader * (*f165)(const GfxShaderCombination *obj);
    Matrix3x3 (*f166)(const Matrix3x3 *obj, const Matrix3x3 & arg0);
    Float3 (*f167)(const Matrix3x3 *obj, const Float3 & arg0);
    Matrix3x3 (*f168)(const Matrix3x3 *obj, float arg0);
    Matrix3x3 (*f169)(const Matrix3x3 *obj);
    Matrix3x3 (*f170)(const Matrix3x3 *obj);
    Matrix3x3 (*f171)(const Float2 & arg0);
    Matrix3x3 (*f172)(const Float3 & arg0);
    Matrix3x3 (*f173)(float arg0);
    Matrix3x3 (*f174)(float arg0);
    Matrix3x3 (*f175)(float arg0);
    Matrix3x3 (*f176)(float arg0);
    void (*f177)( Matrix3x3 *obj);
    void (*f178)( Matrix3x3 *obj, const Matrix4x4 & arg0);
    void (*f179)( Matrix3x3 *obj, const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    void (*f180)( GfxDebugDrawer *obj, const Camera & arg0);
    void (*f181)( GfxDebugDrawer *obj, GfxApi * arg0);
    void (*f182)( GfxDebugDrawer *obj);
    Script *(*f183)(const String & arg0);
    Script *(*f184)(const String & arg0, const String & arg1);
    GfxMaterial *(*f185)(const String & arg0);
    GfxMaterial *(*f186)(const String & arg0, const String & arg1);
    LookupException *(*f187)(const char * arg0, size_t arg1, const char * arg2);
    GfxRenderer *(*f188)();
    GfxRenderer *(*f189)(size_t count);
    Quaternion *(*f190)();
    Quaternion *(*f191)(size_t count);
    Quaternion *(*f192)(const Direction3D & arg0, float arg1);
    Quaternion *(*f193)(float arg0, float arg1, float arg2, float arg3);
    Quaternion *(*f194)(const Float3 & arg0);
    PhysicsShape *(*f195)(const String & arg0);
    PhysicsShape *(*f196)(const String & arg0, const String & arg1);
    ShaderCompileException *(*f197)(const char * arg0, size_t arg1, const char * arg2, const String & arg3);
    Exception *(*f198)(const char * arg0, size_t arg1, const char * arg2);
    GfxForwardMaterialImpl *(*f199)();
    GfxForwardMaterialImpl *(*f200)(size_t count);
    FileException *(*f201)(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4);
    ResourceIOException *(*f202)(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5);
    GfxTexture *(*f203)(const String & arg0, const String & arg1);
    GfxTexture *(*f204)(const String & arg0);
    PhysicsShapeImpl *(*f205)();
    PhysicsShapeImpl *(*f206)(size_t count);
    PhysicsDebugDrawer *(*f207)();
    PhysicsDebugDrawer *(*f208)(size_t count);
    Application *(*f209)(const char * arg0);
    GfxModel *(*f210)(const String & arg0);
    GfxModel *(*f211)(const String & arg0, const String & arg1);
    Scene *(*f212)(const String & arg0);
    Scene *(*f213)(const String & arg0, const String & arg1);
    File *(*f214)(const char * arg0, const char * arg1);
    Matrix3x3 *(*f215)();
    Matrix3x3 *(*f216)(size_t count);
    Matrix3x3 *(*f217)(const Matrix4x4 & arg0);
    Matrix3x3 *(*f218)(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2);
    GfxDebugDrawer *(*f219)(GfxApi * arg0);
};
const _functionStruct *_functions;
const char ** getBacktrace(unsigned int & arg0) {return _functions->f0(arg0);}
size_t getHash(const String & arg0) {return _functions->f1(arg0);}
bool doesFileExist(const char * arg0) {return _functions->f2(arg0);}
List<String> listFiles(const char * arg0) {return _functions->f3(arg0);}
void setApplication(Application * arg0) { _functions->f4(arg0);}
ScriptInstance * Script::createInstance(Entity * arg0)  {return _functions->f5(this, arg0);}
void GfxRenderer::beginRenderMesh(const Camera & arg0, const Matrix4x4 & arg1, ResPtr<GfxMesh> arg2, GfxShaderCombination * arg3)  { _functions->f6(this, arg0, arg1, arg2, arg3);}
void GfxRenderer::endRenderMesh(ResPtr<GfxMesh> arg0)  { _functions->f7(this, arg0);}
void GfxRenderer::renderScene(const ResPtr<Scene> arg0)  { _functions->f8(this, arg0);}
 GfxRenderer::GfxRenderer()  { _functions->f9(this);}
 GfxRenderer::~GfxRenderer()  { _functions->f10(this);}
Quaternion Quaternion::operator*(const Quaternion & arg0) const {return _functions->f11(this, arg0);}
Matrix4x4 Quaternion::toMatrix() const {return _functions->f12(this);}
Float4 Quaternion::getAxisAndAngle() const {return _functions->f13(this);}
void Quaternion::setAxis(const Direction3D & arg0)  { _functions->f14(this, arg0);}
void Quaternion::setAxisAndAngle(const Direction3D & arg0, float arg1)  { _functions->f15(this, arg0, arg1);}
void Quaternion::setEulerAngles(const Float3 & arg0)  { _functions->f16(this, arg0);}
Float3 Quaternion::getEulerAngles()  {return _functions->f17(this);}
 Quaternion::Quaternion()  { _functions->f18(this);}
 Quaternion::Quaternion(const Direction3D & arg0, float arg1)  { _functions->f19(this, arg0, arg1);}
 Quaternion::Quaternion(float arg0, float arg1, float arg2, float arg3)  { _functions->f20(this, arg0, arg1, arg2, arg3);}
 Quaternion::Quaternion(const Float3 & arg0)  { _functions->f21(this, arg0);}
LogEntry & LogEntry::variable(const char * arg0, uint8_t arg1)  {return _functions->f22(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int8_t arg1)  {return _functions->f23(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint16_t arg1)  {return _functions->f24(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int16_t arg1)  {return _functions->f25(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint32_t arg1)  {return _functions->f26(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int32_t arg1)  {return _functions->f27(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, uint64_t arg1)  {return _functions->f28(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, int64_t arg1)  {return _functions->f29(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, bool arg1)  {return _functions->f30(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, float arg1)  {return _functions->f31(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, double arg1)  {return _functions->f32(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, long double arg1)  {return _functions->f33(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const char * arg1)  {return _functions->f34(this, arg0, arg1);}
LogEntry & LogEntry::variable(const char * arg0, const String & arg1)  {return _functions->f35(this, arg0, arg1);}
LogEntry & LogEntry::printBacktrace()  {return _functions->f36(this);}
LogEntry & LogEntry::printBacktrace(unsigned int arg0, const char ** arg1)  {return _functions->f37(this, arg0, arg1);}
int LogEntry::end()  {return _functions->f38(this);}
int LogEntry::fatalEnd()  {return _functions->f39(this);}
void PhysicsShape::setEmpty()  { _functions->f40(this);}
void PhysicsShape::setSphere(float arg0)  { _functions->f41(this, arg0);}
void PhysicsShape::setBox(const Vector3D & arg0)  { _functions->f42(this, arg0);}
void PhysicsShape::setCylinder(PhysicsCylinderShape::Axis arg0, float arg1, float arg2)  { _functions->f43(this, arg0, arg1, arg2);}
void PhysicsShape::setCapsule(PhysicsCapsuleShape::Axis arg0, float arg1, float arg2)  { _functions->f44(this, arg0, arg1, arg2);}
void PhysicsShape::setCone(PhysicsConeShape::Axis arg0, float arg1, float arg2)  { _functions->f45(this, arg0, arg1, arg2);}
void PhysicsShape::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f46(this, arg0, arg1);}
void PhysicsShape::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f47(this, arg0, arg1);}
void PhysicsShape::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f48(this, arg0, arg1, arg2);}
void PhysicsShape::setPlane(const Vector3D & arg0, float arg1)  { _functions->f49(this, arg0, arg1);}
void PhysicsShape::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f50(this, arg0, arg1);}
Vector3D RigidBody::getGravity() const {return _functions->f51(this);}
void RigidBody::setGravity(const Vector3D & arg0)  { _functions->f52(this, arg0);}
void RigidBody::setLinearDamping(float arg0)  { _functions->f53(this, arg0);}
float RigidBody::getLinearDamping() const {return _functions->f54(this);}
void RigidBody::setAngularDamping(float arg0)  { _functions->f55(this, arg0);}
float RigidBody::getAngularDamping() const {return _functions->f56(this);}
void RigidBody::setMass(float arg0) const { _functions->f57(this, arg0);}
float RigidBody::getMass() const {return _functions->f58(this);}
float RigidBody::getLinearSleepingThreshold() const {return _functions->f59(this);}
void RigidBody::setLinearSleepingThreshold(float arg0)  { _functions->f60(this, arg0);}
float RigidBody::getAngularSleepingThreshold() const {return _functions->f61(this);}
void RigidBody::setAngularSleepingThreshold(float arg0)  { _functions->f62(this, arg0);}
void RigidBody::applyTorque(const Vector3D & arg0)  { _functions->f63(this, arg0);}
void RigidBody::applyForce(const Vector3D & arg0, const Position3D & arg1)  { _functions->f64(this, arg0, arg1);}
void RigidBody::applyCentralImpulse(const Vector3D & arg0)  { _functions->f65(this, arg0);}
void RigidBody::applyTorqueImpulse(const Vector3D & arg0)  { _functions->f66(this, arg0);}
void RigidBody::applyImpulse(const Vector3D & arg0, const Position3D & arg1)  { _functions->f67(this, arg0, arg1);}
void RigidBody::clearForces()  { _functions->f68(this);}
Vector3D RigidBody::getLinearVelocity() const {return _functions->f69(this);}
void RigidBody::setLinearVelocity(const Vector3D & arg0) const { _functions->f70(this, arg0);}
Vector3D RigidBody::getAngularVelocity() const {return _functions->f71(this);}
void RigidBody::setAngularVelocity(const Vector3D & arg0) const { _functions->f72(this, arg0);}
Vector3D RigidBody::getVelocityOfPoint(const Position3D & arg0) const {return _functions->f73(this, arg0);}
float RigidBody::getRestitution() const {return _functions->f74(this);}
void RigidBody::setRestitution(float arg0)  { _functions->f75(this, arg0);}
float RigidBody::getFriction() const {return _functions->f76(this);}
void RigidBody::setFriction(float arg0)  { _functions->f77(this, arg0);}
float RigidBody::getRollingFriction() const {return _functions->f78(this);}
void RigidBody::setRollingFriction(float arg0)  { _functions->f79(this, arg0);}
Float3 RigidBody::getLinearFactor() const {return _functions->f80(this);}
void RigidBody::setLinearFactor(const Float3 & arg0) const { _functions->f81(this, arg0);}
Float3 RigidBody::getAngularFactor() const {return _functions->f82(this);}
void RigidBody::setAngularFactor(const Float3 & arg0) const { _functions->f83(this, arg0);}
void RigidBody::setTransform(const Transform & arg0) const { _functions->f84(this, arg0);}
void RigidBody::setEmpty()  { _functions->f85(this);}
void RigidBody::setSphere(float arg0)  { _functions->f86(this, arg0);}
void RigidBody::setBox(const Vector3D & arg0)  { _functions->f87(this, arg0);}
void RigidBody::setCylinder(PhysicsCylinderShape::Axis arg0, float arg1, float arg2)  { _functions->f88(this, arg0, arg1, arg2);}
void RigidBody::setCapsule(PhysicsCapsuleShape::Axis arg0, float arg1, float arg2)  { _functions->f89(this, arg0, arg1, arg2);}
void RigidBody::setCone(PhysicsConeShape::Axis arg0, float arg1, float arg2)  { _functions->f90(this, arg0, arg1, arg2);}
void RigidBody::setConvexHull(size_t arg0, const Position3D * arg1)  { _functions->f91(this, arg0, arg1);}
void RigidBody::setStaticTriangleMesh(size_t arg0, const Position3D * arg1)  { _functions->f92(this, arg0, arg1);}
void RigidBody::setHeightfield(uint32_t arg0, uint32_t arg1, const float * arg2)  { _functions->f93(this, arg0, arg1, arg2);}
void RigidBody::setPlane(const Vector3D & arg0, float arg1)  { _functions->f94(this, arg0, arg1);}
void RigidBody::setCompound(size_t arg0, const PhysicsCompoundShape::Child * arg1)  { _functions->f95(this, arg0, arg1);}
void RigidBody::setShape(ResPtr<PhysicsShape> arg0)  { _functions->f96(this, arg0);}
void Resource::load()  { _functions->f97(this);}
bool Resource::shouldReload() const {return _functions->f98(this);}
void GfxTexture::startCreation(GfxTexture::TextureType arg0, bool arg1, unsigned int arg2, unsigned int arg3, uint8_t arg4, GfxTexture::Purpose arg5, GfxTexture::Format arg6)  { _functions->f99(this, arg0, arg1, arg2, arg3, arg4, arg5, arg6);}
void GfxTexture::allocMipmapFace(unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, const void * arg3)  { _functions->f100(this, arg0, arg1, arg2, arg3);}
void GfxTexture::allocMipmap(unsigned int arg0, unsigned int arg1, const void * arg2)  { _functions->f101(this, arg0, arg1, arg2);}
void GfxTexture::getMipmapFace(unsigned int arg0, unsigned int arg1, GfxTexture::Face arg2, void * arg3)  { _functions->f102(this, arg0, arg1, arg2, arg3);}
void GfxTexture::getMipmap(unsigned int arg0, unsigned int arg1, void * arg2)  { _functions->f103(this, arg0, arg1, arg2);}
void GfxTexture::setMaximumAnisotropy(float arg0)  { _functions->f104(this, arg0);}
void GfxTexture::setMinFilter(GfxTexture::Filter arg0)  { _functions->f105(this, arg0);}
void GfxTexture::setMagFilter(GfxTexture::Filter arg0)  { _functions->f106(this, arg0);}
void GfxTexture::setMipmapMode(GfxTexture::MipmapMode arg0)  { _functions->f107(this, arg0);}
void GfxTexture::setWrapMode(GfxTexture::WrapMode arg0)  { _functions->f108(this, arg0);}
 PhysicsShapeImpl::PhysicsShapeImpl()  { _functions->f109(this);}
void Application::mainloop()  { _functions->f110(this);}
 Application::Application(const char * arg0)  { _functions->f111(this, arg0);}
 Application::~Application()  { _functions->f112(this);}
void Scene::handleInput()  { _functions->f113(this);}
void Scene::update()  { _functions->f114(this);}
void Scene::fixedUpdate(float arg0)  { _functions->f115(this, arg0);}
Entity * Scene::createEntity(const String & arg0)  {return _functions->f116(this, arg0);}
void Scene::removeEntity(size_t arg0)  { _functions->f117(this, arg0);}
void Entity::addRigidBody(PhysicsWorld * arg0, const RigidBody::ConstructionInfo & arg1)  { _functions->f118(this, arg0, arg1);}
void File::read(size_t arg0, void * arg1)  { _functions->f119(this, arg0, arg1);}
void File::write(size_t arg0, const void * arg1)  { _functions->f120(this, arg0, arg1);}
void File::seek(long arg0, File::Origin arg1)  { _functions->f121(this, arg0, arg1);}
long File::tell()  {return _functions->f122(this);}
void File::flush()  { _functions->f123(this);}
bool File::isAtEndOfFile()  {return _functions->f124(this);}
size_t File::getSize()  {return _functions->f125(this);}
uint8_t File::readUInt8()  {return _functions->f126(this);}
int8_t File::readInt8()  {return _functions->f127(this);}
uint16_t File::readUInt16LE()  {return _functions->f128(this);}
int16_t File::readInt16LE()  {return _functions->f129(this);}
uint32_t File::readUInt32LE()  {return _functions->f130(this);}
int32_t File::readInt32LE()  {return _functions->f131(this);}
uint64_t File::readUInt64LE()  {return _functions->f132(this);}
int64_t File::readInt64LE()  {return _functions->f133(this);}
uint16_t File::readUInt16BE()  {return _functions->f134(this);}
int16_t File::readInt16BE()  {return _functions->f135(this);}
uint32_t File::readUInt32BE()  {return _functions->f136(this);}
int32_t File::readInt32BE()  {return _functions->f137(this);}
uint64_t File::readUInt64BE()  {return _functions->f138(this);}
int64_t File::readInt64BE()  {return _functions->f139(this);}
float File::readFloat32()  {return _functions->f140(this);}
char File::readChar()  {return _functions->f141(this);}
void File::writeUInt8(uint8_t arg0)  { _functions->f142(this, arg0);}
void File::writeInt8(int8_t arg0)  { _functions->f143(this, arg0);}
void File::writeUInt16LE(uint16_t arg0)  { _functions->f144(this, arg0);}
void File::writeInt16LE(int16_t arg0)  { _functions->f145(this, arg0);}
void File::writeUInt32LE(uint32_t arg0)  { _functions->f146(this, arg0);}
void File::writeInt32LE(int32_t arg0)  { _functions->f147(this, arg0);}
void File::writeUInt64LE(uint64_t arg0)  { _functions->f148(this, arg0);}
void File::writeInt64LE(int64_t arg0)  { _functions->f149(this, arg0);}
void File::writeUInt16BE(uint16_t arg0)  { _functions->f150(this, arg0);}
void File::writeInt16BE(int16_t arg0)  { _functions->f151(this, arg0);}
void File::writeUInt32BE(uint32_t arg0)  { _functions->f152(this, arg0);}
void File::writeInt32BE(int32_t arg0)  { _functions->f153(this, arg0);}
void File::writeUInt64BE(uint64_t arg0)  { _functions->f154(this, arg0);}
void File::writeInt64BE(int64_t arg0)  { _functions->f155(this, arg0);}
void File::writeFloat32(float arg0)  { _functions->f156(this, arg0);}
void File::vprintf(const char * arg0, va_list arg1)  { _functions->f157(this, arg0, arg1);}
void File::writeChar(char arg0)  { _functions->f158(this, arg0);}
 File::File(const char * arg0, const char * arg1)  { _functions->f159(this, arg0, arg1);}
 File::~File()  { _functions->f160(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledVertexShader() const {return _functions->f161(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledTessControlShader() const {return _functions->f162(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledTessEvalShader() const {return _functions->f163(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledGeometryShader() const {return _functions->f164(this);}
GfxCompiledShader * GfxShaderCombination::getCompiledFragmentShader() const {return _functions->f165(this);}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & arg0) const {return _functions->f166(this, arg0);}
Float3 Matrix3x3::operator*(const Float3 & arg0) const {return _functions->f167(this, arg0);}
Matrix3x3 Matrix3x3::operator/(float arg0) const {return _functions->f168(this, arg0);}
Matrix3x3 Matrix3x3::transpose() const {return _functions->f169(this);}
Matrix3x3 Matrix3x3::inverse() const {return _functions->f170(this);}
Matrix3x3 Matrix3x3::translate(const Float2 & arg0)  {return _functions->f171(arg0);}
Matrix3x3 Matrix3x3::scale(const Float3 & arg0)  {return _functions->f172(arg0);}
Matrix3x3 Matrix3x3::rotate(float arg0)  {return _functions->f173(arg0);}
Matrix3x3 Matrix3x3::rotatex(float arg0)  {return _functions->f174(arg0);}
Matrix3x3 Matrix3x3::rotatey(float arg0)  {return _functions->f175(arg0);}
Matrix3x3 Matrix3x3::rotatez(float arg0)  {return _functions->f176(arg0);}
 Matrix3x3::Matrix3x3()  { _functions->f177(this);}
 Matrix3x3::Matrix3x3(const Matrix4x4 & arg0)  { _functions->f178(this, arg0);}
 Matrix3x3::Matrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2)  { _functions->f179(this, arg0, arg1, arg2);}
void GfxDebugDrawer::render(const Camera & arg0)  { _functions->f180(this, arg0);}
 GfxDebugDrawer::GfxDebugDrawer(GfxApi * arg0)  { _functions->f181(this, arg0);}
 GfxDebugDrawer::~GfxDebugDrawer()  { _functions->f182(this);}
Script *_newScript(const String & arg0) {return _functions->f183(arg0);}
Script *_newScript(const String & arg0, const String & arg1) {return _functions->f184(arg0, arg1);}
GfxMaterial *_newGfxMaterial(const String & arg0) {return _functions->f185(arg0);}
GfxMaterial *_newGfxMaterial(const String & arg0, const String & arg1) {return _functions->f186(arg0, arg1);}
LookupException *_newLookupException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f187(arg0, arg1, arg2);}
GfxRenderer *_newGfxRenderer() {return _functions->f188();}
GfxRenderer *_newArrayGfxRenderer(size_t count) {return _functions->f189(count);}
Quaternion *_newQuaternion() {return _functions->f190();}
Quaternion *_newArrayQuaternion(size_t count) {return _functions->f191(count);}
Quaternion *_newQuaternion(const Direction3D & arg0, float arg1) {return _functions->f192(arg0, arg1);}
Quaternion *_newQuaternion(float arg0, float arg1, float arg2, float arg3) {return _functions->f193(arg0, arg1, arg2, arg3);}
Quaternion *_newQuaternion(const Float3 & arg0) {return _functions->f194(arg0);}
PhysicsShape *_newPhysicsShape(const String & arg0) {return _functions->f195(arg0);}
PhysicsShape *_newPhysicsShape(const String & arg0, const String & arg1) {return _functions->f196(arg0, arg1);}
ShaderCompileException *_newShaderCompileException(const char * arg0, size_t arg1, const char * arg2, const String & arg3) {return _functions->f197(arg0, arg1, arg2, arg3);}
Exception *_newException(const char * arg0, size_t arg1, const char * arg2) {return _functions->f198(arg0, arg1, arg2);}
GfxForwardMaterialImpl *_newGfxForwardMaterialImpl() {return _functions->f199();}
GfxForwardMaterialImpl *_newArrayGfxForwardMaterialImpl(size_t count) {return _functions->f200(count);}
FileException *_newFileException(const char * arg0, size_t arg1, const char * arg2, String arg3, String arg4) {return _functions->f201(arg0, arg1, arg2, arg3, arg4);}
ResourceIOException *_newResourceIOException(const char * arg0, size_t arg1, const char * arg2, const String & arg3, const String & arg4, const String & arg5) {return _functions->f202(arg0, arg1, arg2, arg3, arg4, arg5);}
GfxTexture *_newGfxTexture(const String & arg0, const String & arg1) {return _functions->f203(arg0, arg1);}
GfxTexture *_newGfxTexture(const String & arg0) {return _functions->f204(arg0);}
PhysicsShapeImpl *_newPhysicsShapeImpl() {return _functions->f205();}
PhysicsShapeImpl *_newArrayPhysicsShapeImpl(size_t count) {return _functions->f206(count);}
PhysicsDebugDrawer *_newPhysicsDebugDrawer() {return _functions->f207();}
PhysicsDebugDrawer *_newArrayPhysicsDebugDrawer(size_t count) {return _functions->f208(count);}
Application *_newApplication(const char * arg0) {return _functions->f209(arg0);}
GfxModel *_newGfxModel(const String & arg0) {return _functions->f210(arg0);}
GfxModel *_newGfxModel(const String & arg0, const String & arg1) {return _functions->f211(arg0, arg1);}
Scene *_newScene(const String & arg0) {return _functions->f212(arg0);}
Scene *_newScene(const String & arg0, const String & arg1) {return _functions->f213(arg0, arg1);}
File *_newFile(const char * arg0, const char * arg1) {return _functions->f214(arg0, arg1);}
Matrix3x3 *_newMatrix3x3() {return _functions->f215();}
Matrix3x3 *_newArrayMatrix3x3(size_t count) {return _functions->f216(count);}
Matrix3x3 *_newMatrix3x3(const Matrix4x4 & arg0) {return _functions->f217(arg0);}
Matrix3x3 *_newMatrix3x3(const Float3 & arg0, const Float3 & arg1, const Float3 & arg2) {return _functions->f218(arg0, arg1, arg2);}
GfxDebugDrawer *_newGfxDebugDrawer(GfxApi * arg0) {return _functions->f219(arg0);}
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

GfxRenderer *_new<GfxRenderer>::f() {return _newGfxRenderer();}

Quaternion *_new<Quaternion>::f() {return _newQuaternion();}

template <typename T0, typename T1>
Quaternion *_new<Quaternion>::f(T0 arg0, T1 arg1) {return _newQuaternion(arg0, arg1);}

template <typename T0, typename T1, typename T2, typename T3>
Quaternion *_new<Quaternion>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {return _newQuaternion(arg0, arg1, arg2, arg3);}

template <typename T0>
Quaternion *_new<Quaternion>::f(T0 arg0) {return _newQuaternion(arg0);}

template <typename T0>
PhysicsShape *_new<PhysicsShape>::f(T0 arg0) {return _newPhysicsShape(arg0);}

template <typename T0, typename T1>
PhysicsShape *_new<PhysicsShape>::f(T0 arg0, T1 arg1) {return _newPhysicsShape(arg0, arg1);}

template <typename T0, typename T1, typename T2, typename T3>
ShaderCompileException *_new<ShaderCompileException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {return _newShaderCompileException(arg0, arg1, arg2, arg3);}

template <typename T0, typename T1, typename T2>
Exception *_new<Exception>::f(T0 arg0, T1 arg1, T2 arg2) {return _newException(arg0, arg1, arg2);}

GfxForwardMaterialImpl *_new<GfxForwardMaterialImpl>::f() {return _newGfxForwardMaterialImpl();}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
FileException *_new<FileException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4) {return _newFileException(arg0, arg1, arg2, arg3, arg4);}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
ResourceIOException *_new<ResourceIOException>::f(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5) {return _newResourceIOException(arg0, arg1, arg2, arg3, arg4, arg5);}

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

GfxRenderer *_newArray<GfxRenderer>::f(size_t count) {return _newArrayGfxRenderer(count);}

Quaternion *_newArray<Quaternion>::f(size_t count) {return _newArrayQuaternion(count);}

GfxForwardMaterialImpl *_newArray<GfxForwardMaterialImpl>::f(size_t count) {return _newArrayGfxForwardMaterialImpl(count);}

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
    static GfxRenderer *f();
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

class GfxForwardMaterialImpl;
template <>
struct _new<GfxForwardMaterialImpl>
{
    static GfxForwardMaterialImpl *f();
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
    static GfxRenderer *f(size_t count);
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

class GfxForwardMaterialImpl;
template <>
struct _newArray<GfxForwardMaterialImpl>
{
    static GfxForwardMaterialImpl *f(size_t count);
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