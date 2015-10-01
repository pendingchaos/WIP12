#include "physics/physicsshape.h"

#include "memory.h"
#include "file.h"
#include "globals.h"
#include "resource/resourcemanager.h"
#include "physics/rigidbody.h"
#include "physics/ghostobject.h"

#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include <cstring>

PhysicsShape::PhysicsShape() : Resource(ResType::PhysicsShapeType),
                               impl(NEW(PhysicsShapeImpl, this, PhysicsShapeImpl::Empty, NEW(btEmptyShape))) {}

PhysicsShape::PhysicsShape(const String& filename) : Resource(filename, ResType::PhysicsShapeType),
                                                     impl(NEW(PhysicsShapeImpl, this, PhysicsShapeImpl::Empty, NEW(btEmptyShape))) {}

PhysicsShape::~PhysicsShape()
{
    DELETE(impl);
}

void PhysicsShape::setEmpty()
{
    DELETE(impl);

    impl = NEW(PhysicsShapeImpl, this, PhysicsShapeImpl::Empty, NEW(btEmptyShape));

    impl->updateRigidBodies();
}

void PhysicsShape::setSphere(float radius)
{
    DELETE(impl);

    impl = NEW(PhysicsSphereShape, this, radius);
}

void PhysicsShape::setBox(const Vector3D& halfExtents)
{
    DELETE(impl);

    impl = NEW(PhysicsBoxShape, this, halfExtents);
}

void PhysicsShape::setCylinder(Axis axis,
                               float height,
                               float radius)
{
    DELETE(impl);

    impl = NEW(PhysicsCylinderShape, this, axis, height, radius);
}

void PhysicsShape::setCapsule(Axis axis,
                              float height,
                              float radius)
{
    DELETE(impl);

    impl = NEW(PhysicsCapsuleShape, this, axis, height, radius);
}

void PhysicsShape::setCone(Axis axis,
                           float height,
                           float radius)
{
    DELETE(impl);

    impl = NEW(PhysicsConeShape, this, axis, height, radius);
}

void PhysicsShape::setConvexHull(size_t pointCount, const Position3D *points)
{
    DELETE(impl);

    impl = NEW(PhysicsConvexHullShape, this, pointCount, points);
}

void PhysicsShape::setStaticTriangleMesh(size_t vertexCount, const Position3D *vertices)
{
    DELETE(impl);

    impl = NEW(PhysicsStaticTriangleMesh, this, vertexCount, vertices);
}

void PhysicsShape::setHeightfield(uint32_t width, uint32_t height, const float *data)
{
    DELETE(impl);

    impl = NEW(PhysicsHeightfield, this, width, height, data);
}

void PhysicsShape::setPlane(const Vector3D& normal, float distance)
{
    DELETE(impl);

    impl = NEW(PhysicsPlaneShape, this, normal, distance);
}

void PhysicsShape::setCompound(size_t childCount,
                               const PhysicsCompoundShape::Child *children)
{
    DELETE(impl);

    impl = NEW(PhysicsCompoundShape, this, childCount, children);
}

void saveShape(PhysicsShape *shape, File *file)
{
    if (shape->getFilename().getLength() != 0)
    {
        file->writeUInt8(11);

        file->writeUInt32LE(shape->getFilename().getLength());
        file->write(shape->getFilename().getLength(), shape->getFilename().getData());
    }

    switch (shape->getShapeType())
    {
        case PhysicsShapeImpl::Sphere:
        {
            file->writeUInt8(0);
            file->writeFloat32(((PhysicsSphereShape *)shape->getImpl())->getRadius());
            break;
        }
        case PhysicsShapeImpl::Box:
        {
            Vector3D extents = (((PhysicsBoxShape *)shape->getImpl())->getHalfExtents());

            file->writeUInt8(1);
            file->writeFloat32(extents.x);
            file->writeFloat32(extents.y);
            file->writeFloat32(extents.z);
            break;
        }
        case PhysicsShapeImpl::Cylinder:
        {
            PhysicsCylinderShape *impl = (PhysicsCylinderShape *)shape->getImpl();

            file->writeUInt8(2);
            file->writeFloat32(impl->getHeight());
            file->writeFloat32(impl->getRadius());
            file->writeUInt8((uint8_t)impl->getAxis());
            break;
        }
        case PhysicsShapeImpl::Capsule:
        {
            PhysicsCapsuleShape *impl = (PhysicsCapsuleShape *)shape->getImpl();

            file->writeUInt8(3);
            file->writeFloat32(impl->getHeight());
            file->writeFloat32(impl->getRadius());
            file->writeUInt8((uint8_t)impl->getAxis());
            break;
        }
        case PhysicsShapeImpl::Cone:
        {
            PhysicsConeShape *impl = (PhysicsConeShape *)shape->getImpl();

            file->writeUInt8(4);
            file->writeFloat32(impl->getHeight());
            file->writeFloat32(impl->getRadius());
            file->writeUInt8((uint8_t)impl->getAxis());
            break;
        }
        case PhysicsShapeImpl::ConvexHull:
        {
            PhysicsConvexHullShape *impl = (PhysicsConvexHullShape *)shape->getImpl();

            file->writeUInt8(5);
            file->writeUInt32LE(impl->getNumPoints());

            for (size_t i = 0; i < impl->getNumPoints(); ++i)
            {
                file->writeFloat32(impl->getPoints()[i].x);
                file->writeFloat32(impl->getPoints()[i].y);
                file->writeFloat32(impl->getPoints()[i].z);
            }
            break;
        }
        case PhysicsShapeImpl::StaticTriangleMesh:
        {
            PhysicsStaticTriangleMesh *impl = (PhysicsStaticTriangleMesh *)shape->getImpl();

            file->writeUInt8(6);
            file->writeUInt32LE(impl->getNumTriangles());

            for (size_t i = 0; i < impl->getNumTriangles()*3; ++i)
            {
                file->writeFloat32(impl->getTriangles()[i].x);
                file->writeFloat32(impl->getTriangles()[i].y);
                file->writeFloat32(impl->getTriangles()[i].z);
            }
            break;
        }
        case PhysicsShapeImpl::Heightfield:
        {
            PhysicsHeightfield *impl = (PhysicsHeightfield *)shape->getImpl();

            file->writeUInt8(7);
            file->writeUInt32LE(impl->getWidth());
            file->writeUInt32LE(impl->getHeight());

            for (size_t i = 0; i < impl->getWidth()*impl->getHeight(); ++i)
            {
                file->writeFloat32(impl->getData()[i]);
            }
            break;
        }
        case PhysicsShapeImpl::Plane:
        {
            PhysicsPlaneShape *impl = (PhysicsPlaneShape *)shape->getImpl();

            file->writeUInt8(8);
            file->writeFloat32(impl->getDistance());
            file->writeFloat32(impl->getNormal().x);
            file->writeFloat32(impl->getNormal().y);
            file->writeFloat32(impl->getNormal().z);
            break;
        }
        case PhysicsShapeImpl::Compound:
        {
            PhysicsCompoundShape *impl = (PhysicsCompoundShape *)shape->getImpl();

            file->writeUInt8(9);
            file->writeUInt32LE(impl->getShapeCount());

            for (size_t i = 0; i < impl->getShapeCount(); ++i)
            {
                const PhysicsCompoundShape::Child& child = impl->getShapes()[i];

                file->writeFloat32(child.orientation.x);
                file->writeFloat32(child.orientation.y);
                file->writeFloat32(child.orientation.z);
                file->writeFloat32(child.orientation.w);
                file->writeFloat32(child.position.x);
                file->writeFloat32(child.position.y);
                file->writeFloat32(child.position.z);

                saveShape(child.shape, file);
            }
            break;
        }
        case PhysicsShapeImpl::Empty:
        {
            file->writeUInt8(10);
            break;
        }
    }
}

void PhysicsShape::save()
{
    try
    {
        File file(getFilename().getData(), "wb");

        file.write(6, "shpe\x01\x00");

        saveShape(this, &file);
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "physicsShape",
              getFilename(),
              e.getString());
    }
}

PhysicsShape *loadShape(PhysicsShape *dest, File *file, const String& filename)
{
    uint8_t shapeType = file->readUInt8();

    if (dest == nullptr and shapeType != 11)
    {
        dest = NEW(PhysicsShape, "shape");
    }

    switch (shapeType)
    {
    case 0:
    {
        dest->setSphere(file->readFloat32());
        break;
    }
    case 1:
    {
        float x = file->readFloat32();
        float y = file->readFloat32();
        float z = file->readFloat32();
        dest->setBox(Vector3D(x, y, z));
        break;
    }
    case 2:
    {
        float height = file->readFloat32();
        float radius = file->readFloat32();
        uint8_t axis = file->readUInt8();

        switch (axis)
        {
        case 0:
        {
            dest->setCylinder(Axis::X, height, radius);
            break;
        }
        case 1:
        {
            dest->setCylinder(Axis::Y, height, radius);
            break;
        }
        case 2:
        {
            dest->setCylinder(Axis::Z, height, radius);
            break;
        }
        }
        break;
    }
    case 3:
    {
        float height = file->readFloat32();
        float radius = file->readFloat32();
        uint8_t axis = file->readUInt8();

        switch (axis)
        {
        case 0:
        {
            dest->setCapsule(Axis::X, height, radius);
            break;
        }
        case 1:
        {
            dest->setCapsule(Axis::Y, height, radius);
            break;
        }
        case 2:
        {
            dest->setCapsule(Axis::Z, height, radius);
            break;
        }
        }
        break;
    }
    case 4:
    {
        float height = file->readFloat32();
        float radius = file->readFloat32();
        uint8_t axis = file->readUInt8();

        switch (axis)
        {
        case 0:
        {
            dest->setCone(Axis::X, height, radius);
            break;
        }
        case 1:
        {
            dest->setCone(Axis::Y, height, radius);
            break;
        }
        case 2:
        {
            dest->setCone(Axis::Z, height, radius);
            break;
        }
        }
        break;
    }
    case 5:
    {
        uint32_t numPoints = file->readUInt32LE();

        float *data = NEW_ARRAY(float, numPoints*3);

        for (size_t i = 0; i < numPoints*3; ++i)
        {
            data[i] = file->readFloat32();
        }

        dest->setConvexHull(numPoints, (Position3D *)data);

        DELETE_ARRAY(data);
        break;
    }
    case 6:
    {
        uint32_t numTriangles = file->readUInt32LE();

        float *data = NEW_ARRAY(float, numTriangles*9);

        for (size_t i = 0; i < numTriangles*9; ++i)
        {
            data[i] = file->readFloat32();
        }

        dest->setStaticTriangleMesh(numTriangles, (Position3D *)data);

        DELETE_ARRAY(data);
        break;
    }
    case 7:
    {
        uint32_t width = file->readUInt32LE();
        uint32_t height = file->readUInt32LE();

        float *data = NEW_ARRAY(float, width*height);

        for (size_t i = 0; i < width*height; ++i)
        {
            data[i] = file->readFloat32();
        }

        dest->setHeightfield(width, height, data);

        DELETE_ARRAY(data);
        break;
    }
    case 8:
    {
        float distance = file->readFloat32();
        float nx = file->readFloat32();
        float ny = file->readFloat32();
        float nz = file->readFloat32();

        dest->setPlane(Vector3D(nx, ny, nz), distance);
        break;
    }
    case 9:
    {
        uint32_t count = file->readUInt32LE();

        PhysicsCompoundShape::Child *children = NEW_ARRAY(PhysicsCompoundShape::Child, count);

        for (size_t i = 0; i < count; ++i)
        {
            float ox = file->readFloat32();
            float oy = file->readFloat32();
            float oz = file->readFloat32();
            float ow = file->readFloat32();
            float px = file->readFloat32();
            float py = file->readFloat32();
            float pz = file->readFloat32();

            children[i].orientation = Quaternion(ox, oy, oz, ow);
            children[i].position = Position3D(px, py, pz);
            children[i].shape = loadShape(nullptr, file, filename);
        }

        dest->setCompound(count, children);

        DELETE_ARRAY(children);
        break;
    }
    case 10:
    {
        dest->setEmpty();
        break;
    }
    case 11:
    {
        uint32_t length = file->readUInt32LE();
        String filename2((size_t)length);
        file->read(length, filename2.getData());

        dest = resMgr->load<PhysicsShape>(filename2);
        break;
    }
    default:
    {
        THROW(ResourceIOException, "physicsShape", filename, "Invalid shape type.")
    }
    }

    return dest;
}

void PhysicsShape::_load()
{
    try
    {
        File file(getFilename().getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 's' or
            magic[1] != 'h' or
            magic[2] != 'p' or
            magic[3] != 'e')
        {
            THROW(ResourceIOException, "physicsShape", getFilename(), "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException, "physicsShape", getFilename(), "Unsupported version.");
        }

        loadShape(this, &file, getFilename());
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "physicsShape",
              getFilename(),
              e.getString());
    }
}

PhysicsShapeImpl::PhysicsShapeImpl(PhysicsShape *physShape_,
                                   Type type_,
                                   btCollisionShape *shape_) : type(type_),
                                                               shape(shape_),
                                                               physShape(physShape_) {}

PhysicsShapeImpl::~PhysicsShapeImpl()
{
    DELETE(shape);
}

void PhysicsShapeImpl::updateRigidBodies()
{
    for (auto rigidBody : physShape->rigidBodies)
    {
        rigidBody->updateShape();
    }

    for (auto ghost : physShape->ghosts)
    {
        ghost->ghostObject->setCollisionShape(shape);
    }
}

PhysicsSphereShape::PhysicsSphereShape(PhysicsShape *physShape, float radius_)
: PhysicsShapeImpl(physShape, Sphere, nullptr), radius(radius_) {create();}

void PhysicsSphereShape::setRadius(float radius_)
{
    radius = radius_;

    DELETE(shape);

    create();
}

void PhysicsSphereShape::create()
{
    shape = NEW(btSphereShape, radius);

    updateRigidBodies();
}

PhysicsBoxShape::PhysicsBoxShape(PhysicsShape *physShape, const Vector3D& halfExtents_)
 : PhysicsShapeImpl(physShape, Box, NEW(btBoxShape, btVector3(halfExtents_.x,
                                                              halfExtents_.y,
                                                              halfExtents_.z))),
   halfExtents(halfExtents_) {}

void PhysicsBoxShape::setHalfExtents(const Vector3D& halfExtents_)
{
    halfExtents = halfExtents_;

    DELETE(shape);

    create();
}

void PhysicsBoxShape::create()
{
    shape = NEW(btBoxShape, btVector3(halfExtents.x, halfExtents.y, halfExtents.z));

    updateRigidBodies();
}

PhysicsCylinderShape::PhysicsCylinderShape(PhysicsShape *physShape,
                                           Axis axis_,
                                           float height_,
                                           float radius_) : PhysicsShapeImpl(physShape,
                                                                             Cylinder,
                                                                             nullptr),
                                                            axis(axis_),
                                                            height(height_),
                                                            radius(radius_) {create();}

void PhysicsCylinderShape::create()
{
    switch (axis)
    {
    case Axis::X:
    {
        shape = NEW(btCylinderShapeX, btVector3(height/2.0f, radius, radius));
        break;
    }
    case Axis::Y:
    {
        shape = NEW(btCylinderShape, btVector3(radius, height/2.0f, radius));
        break;
    }
    case Axis::Z:
    {
        shape = NEW(btCylinderShapeZ, btVector3(radius, radius, height/2.0f));
        break;
    }
    }

    updateRigidBodies();
}

void PhysicsCylinderShape::setAxis(Axis axis_)
{
    axis = axis_;

    DELETE(shape);

    create();
}

void PhysicsCylinderShape::setHeight(float height_)
{
    height = height_;

    DELETE(shape);

    create();
}

void PhysicsCylinderShape::setRadius(float radius_)
{
    radius = radius_;

    DELETE(shape);

    create();
}

PhysicsCapsuleShape::PhysicsCapsuleShape(PhysicsShape *physShape,
                                         Axis axis_,
                                         float height_,
                                         float radius_) : PhysicsShapeImpl(physShape,
                                                                           Capsule,
                                                                           nullptr),
                                                          axis(axis_),
                                                          height(height_),
                                                          radius(radius_) {create();}

void PhysicsCapsuleShape::create()
{
    switch (axis)
    {
    case Axis::X:
    {
        shape = NEW(btCapsuleShapeX, radius, height);
        break;
    }
    case Axis::Y:
    {
        shape = NEW(btCapsuleShape, radius, height);
        break;
    }
    case Axis::Z:
    {
        shape = NEW(btCapsuleShapeZ, radius, height);
        break;
    }
    }

    updateRigidBodies();
}

void PhysicsCapsuleShape::setAxis(Axis axis_)
{
    axis = axis_;

    DELETE(shape);

    create();
}

void PhysicsCapsuleShape::setHeight(float height_)
{
    height = height_;

    DELETE(shape);

    create();
}

void PhysicsCapsuleShape::setRadius(float radius_)
{
    radius = radius_;

    DELETE(shape);

    create();
}

PhysicsConeShape::PhysicsConeShape(PhysicsShape *physShape,
                                   Axis axis_,
                                   float height_,
                                   float radius_) : PhysicsShapeImpl(physShape,
                                                                     Cone,
                                                                     nullptr),
                                                    axis(axis_),
                                                    height(height_),
                                                    radius(radius_) {create();}

void PhysicsConeShape::create()
{
    switch (axis)
    {
    case Axis::X:
    {
        shape = NEW(btConeShapeX, radius, height);
        break;
    }
    case Axis::Y:
    {
        shape = NEW(btConeShape, radius, height);
        break;
    }
    case Axis::Z:
    {
        shape = NEW(btConeShapeZ, radius, height);
        break;
    }
    }

    updateRigidBodies();
}

void PhysicsConeShape::setAxis(Axis axis_)
{
    axis = axis_;

    DELETE(shape);

    create();
}

void PhysicsConeShape::setHeight(float height_)
{
    height = height_;

    DELETE(shape);

    create();
}

void PhysicsConeShape::setRadius(float radius_)
{
    radius = radius_;

    DELETE(shape);

    create();
}

PhysicsConvexHullShape::PhysicsConvexHullShape(PhysicsShape *physShape,
                                               size_t numPoints_,
                                               const Position3D *points_)
 : PhysicsShapeImpl(physShape,
                    ConvexHull,
                    nullptr),
   numPoints(numPoints_) {create(points_);}

PhysicsConvexHullShape::~PhysicsConvexHullShape()
{
    DELETE_ARRAY(points);
}

void PhysicsConvexHullShape::create(const Position3D *points_)
{
    points = NEW_ARRAY(Position3D, numPoints);

    std::memcpy(points, points_, sizeof(Position3D)*numPoints);

    shape = NEW(btConvexHullShape,
                reinterpret_cast<const btScalar *>(points),
                numPoints,
                sizeof(Position3D));

    updateRigidBodies();
}

void PhysicsConvexHullShape::setPoints(size_t numPoints_, const Position3D *points_)
{
    DELETE_ARRAY(points);

    numPoints = numPoints_;

    create(points_);
}

PhysicsStaticTriangleMesh::PhysicsStaticTriangleMesh(PhysicsShape *physShape,
                                                     size_t numTriangles_,
                                                     const Position3D *triangles_)
 : PhysicsShapeImpl(physShape, StaticTriangleMesh, nullptr),
   numTriangles(numTriangles_) {create(triangles_);}

PhysicsStaticTriangleMesh::~PhysicsStaticTriangleMesh()
{
    DELETE_ARRAY(triangles);
    DELETE_ARRAY(btTriangles);
    DELETE_ARRAY(indices);
    DELETE(vertexArray);
}

void PhysicsStaticTriangleMesh::create(const Position3D *triangles_)
{
    indices = NEW_ARRAY(int, numTriangles*3);

    for (size_t i = 0; i < numTriangles*3; ++i)
    {
        indices[i] = i;
    }

    btTriangles = NEW_ARRAY(btScalar, numTriangles*12);

    for (size_t i = 0; i < numTriangles*12; i += 3)
    {
        btTriangles[i] = triangles[i].x;
        btTriangles[i+1] = triangles[i+1].y;
        btTriangles[i+2] = triangles[i+2].z;
    }

    vertexArray = NEW(btTriangleIndexVertexArray,
                      numTriangles,
                      indices,
                      sizeof(int)*3,
                      numTriangles*3,
                      btTriangles,
                      12);

    shape = NEW(btBvhTriangleMeshShape, vertexArray, true);

    triangles = NEW_ARRAY(Position3D, numTriangles * 3);

    std::memcpy(triangles, triangles_, sizeof(Position3D)*numTriangles*3);

    updateRigidBodies();
}

void PhysicsStaticTriangleMesh::setTriangles(size_t numTriangles_, const Position3D *triangles_)
{
    DELETE_ARRAY(triangles);
    DELETE_ARRAY(btTriangles);
    DELETE_ARRAY(indices);
    DELETE(vertexArray);

    numTriangles = numTriangles_;

    create(triangles_);
}

PhysicsHeightfield::PhysicsHeightfield(PhysicsShape *physShape,
                                       uint32_t width_,
                                       uint32_t height_,
                                       const float *data_)
 : PhysicsShapeImpl(physShape, Heightfield, nullptr),
   width(width_),
   height(height_) {create(data_);}

PhysicsHeightfield::~PhysicsHeightfield()
{
    DELETE_ARRAY(data);
}

void PhysicsHeightfield::create(const float *data_)
{
    data = NEW_ARRAY(float, width*height);
    float maxHeight = -INFINITY;

    float value;
    for (size_t i = 0; i < width*height; ++i)
    {
        value = data_[i];

        data[i] = value;

        if (value > maxHeight)
        {
            maxHeight = value;
        }
    }

    shape = NEW(btHeightfieldTerrainShape,
                width,
                height,
                data,
                1.0f,
                0.0f,
                maxHeight,
                1,
                PHY_FLOAT,
                false);

    updateRigidBodies();
}

void PhysicsHeightfield::setData(uint32_t width_, uint32_t height_, const float *data_)
{
    DELETE_ARRAY(data);

    width = width_;
    height = height_;

    create(data_);
}

PhysicsPlaneShape::PhysicsPlaneShape(PhysicsShape *physShape, const Vector3D& normal_, float distance_)
: PhysicsShapeImpl(physShape, Plane, nullptr),
  normal(normal_.normalize()),
  distance(distance_) {create();}

void PhysicsPlaneShape::create()
{
    Vector3D normalized = normal.normalize();

    shape = NEW(btStaticPlaneShape, btVector3(normalized.x, normalized.y, normalized.z), distance);
}

void PhysicsPlaneShape::setNormal(const Vector3D& normal_)
{
    normal = normal_;

    DELETE(shape);

    create();
}

void PhysicsPlaneShape::setDistance(float distance_)
{
    distance = distance_;

    DELETE(shape);

    create();
}

PhysicsCompoundShape::PhysicsCompoundShape(PhysicsShape *physShape,
                                           size_t shapeCount_,
                                           const Child *shapes_)
 : PhysicsShapeImpl(physShape,
                    Compound,
                    nullptr),
   shapeCount(shapeCount_) {create(shapes_);}

PhysicsCompoundShape::~PhysicsCompoundShape()
{
    for (size_t i = 0; i < shapeCount; ++i)
    {
        shapes[i].shape->release();
    }

    DELETE_ARRAY(shapes);
}

void PhysicsCompoundShape::create(const Child *shapes_)
{
    shapes = NEW_ARRAY(Child, shapeCount);

    for (size_t i = 0; i < shapeCount; ++i)
    {
        shapes[i] = shapes_[i];
    }

    btCompoundShape *shape_ = NEW(btCompoundShape);

    for (size_t i = 0; i < shapeCount; ++i)
    {
        const Child& child = shapes_[i];

        btTransform transform;

        transform.setRotation(btQuaternion(child.orientation.x,
                                           child.orientation.y,
                                           child.orientation.z,
                                           child.orientation.w));
        transform.setOrigin(btVector3(child.position.x,
                                      child.position.y,
                                      child.position.z));

        shape_->addChildShape(transform, child.shape->getBulletShape());
    }

    shape_->recalculateLocalAabb();

    shape = shape_;

    updateRigidBodies();
}

void PhysicsCompoundShape::setChildren(size_t count, const Child *children)
{
    shapeCount = count;

    DELETE(shape);

    create(children);
}

Resource *PhysicsShape::_copy() const
{
    PhysicsShape *shape = NEW(PhysicsShape);

    shape->setMargin(getMargin());
    shape->setScale(getScale());

    switch (getShapeType())
    {
    case PhysicsShapeImpl::Empty:
    {
        break;
    }
    case PhysicsShapeImpl::Sphere:
    {
        shape->setSphere(((PhysicsSphereShape *)impl)->getRadius());
        break;
    }
    case PhysicsShapeImpl::Box:
    {
        shape->setBox(((PhysicsBoxShape *)impl)->getHalfExtents());
        break;
    }
    case PhysicsShapeImpl::Cylinder:
    {
        PhysicsCylinderShape *impl_ = (PhysicsCylinderShape *)impl;

        shape->setCylinder(impl_->getAxis(), impl_->getHeight(), impl_->getRadius());
        break;
    }
    case PhysicsShapeImpl::Capsule:
    {
        PhysicsCapsuleShape *impl_ = (PhysicsCapsuleShape *)impl;

        shape->setCapsule(impl_->getAxis(), impl_->getHeight(), impl_->getRadius());
        break;
    }
    case PhysicsShapeImpl::Cone:
    {
        PhysicsConeShape *impl_ = (PhysicsConeShape *)impl;

        shape->setCone(impl_->getAxis(), impl_->getHeight(), impl_->getRadius());
        break;
    }
    case PhysicsShapeImpl::ConvexHull:
    {
        PhysicsConvexHullShape *impl_ = (PhysicsConvexHullShape *)impl;

        shape->setConvexHull(impl_->getNumPoints(), impl_->getPoints());
        break;
    }
    case PhysicsShapeImpl::StaticTriangleMesh:
    {
        PhysicsStaticTriangleMesh *impl_ = (PhysicsStaticTriangleMesh *)impl;

        shape->setStaticTriangleMesh(impl_->getNumTriangles()*3, impl_->getTriangles());
        break;
    }
    case PhysicsShapeImpl::Heightfield:
    {
        PhysicsHeightfield *impl_ = (PhysicsHeightfield *)impl;

        shape->setHeightfield(impl_->getWidth(), impl_->getHeight(), impl_->getData());
        break;
    }
    case PhysicsShapeImpl::Plane:
    {
        PhysicsPlaneShape *impl_ = (PhysicsPlaneShape *)impl;

        shape->setPlane(impl_->getNormal(), impl_->getDistance());
        break;
    }
    case PhysicsShapeImpl::Compound:
    {
        PhysicsCompoundShape *impl_ = (PhysicsCompoundShape *)impl;

        PhysicsCompoundShape::Child children[impl_->getShapeCount()];

        for (size_t i = 0; i < impl_->getShapeCount(); ++i)
        {
            children[i].orientation = impl_->getShapes()[i].orientation;
            children[i].position = impl_->getShapes()[i].position;
            children[i].shape = (PhysicsShape *)impl_->getShapes()[i].shape->copy();
        }

        shape->setCompound(impl_->getShapeCount(), children);
        break;
    }
    }

    return (Resource *)shape;
}
