#include "physics/physicsshape.h"

#include "memory.h"
#include "file.h"
#include "globals.h"
#include "resource/resourcemanager.h"

#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include <cstring>

PhysicsShape::PhysicsShape(const String& name) : Resource(name, Resource::PhysicsShapeType),
                                                 impl(NEW(PhysicsShapeImpl)) {}

PhysicsShape::PhysicsShape(const String& filename,
                           const String& name) : Resource(filename, name, Resource::PhysicsShapeType),
                                                 impl(NEW(PhysicsShapeImpl)) {}

PhysicsShape::~PhysicsShape() {}

void PhysicsShape::setEmpty()
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsShapeImpl);
}

void PhysicsShape::setSphere(float radius)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsSphereShape, radius);
}

void PhysicsShape::setBox(const Vector3D& halfExtents)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsBoxShape, halfExtents);
}

void PhysicsShape::setCylinder(PhysicsCylinderShape::Axis axis,
                               float height,
                               float radius)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsCylinderShape, axis, height, radius);
}

void PhysicsShape::setCapsule(PhysicsCapsuleShape::Axis axis,
                              float height,
                              float radius)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsCapsuleShape, axis, height, radius);
}

void PhysicsShape::setCone(PhysicsConeShape::Axis axis,
                           float height,
                           float radius)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsConeShape, axis, height, radius);
}

void PhysicsShape::setConvexHull(size_t pointCount, const Position3D *points)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsConvexHullShape, pointCount, points);
}

void PhysicsShape::setStaticTriangleMesh(size_t vertexCount, const Position3D *vertices)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsStaticTriangleMesh, vertexCount, vertices);
}

void PhysicsShape::setHeightfield(uint32_t width, uint32_t height, const float *data)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsHeightfield, width, height, data);
}

void PhysicsShape::setPlane(const Vector3D& normal, float distance)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsPlaneShape, normal, distance);
}

void PhysicsShape::setCompound(size_t childCount,
                               const PhysicsCompoundShape::Child *children)
{
    DELETE(PhysicsShapeImpl, impl);

    impl = NEW(PhysicsCompoundShape, childCount, children);
}

void saveShape(ResPtr<PhysicsShape> shape, File *file)
{
    if (shape->filename.getLength() != 0)
    {
        file->writeUInt8(11);

        file->writeUInt32LE(shape->filename.getLength());
        file->write(shape->filename.getLength(), shape->filename.getData());
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
        File file(filename.getData(), "wb");

        file.write(6, "shpe\x01\x00");

        saveShape(this, &file);
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "physicsShape",
              filename,
              e.getString());
    }
}

ResPtr<PhysicsShape> loadShape(ResPtr<PhysicsShape> dest, File *file, const String& filename)
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
            dest->setCylinder(PhysicsCylinderShape::X, height, radius);
            break;
        }
        case 1:
        {
            dest->setCylinder(PhysicsCylinderShape::Y, height, radius);
            break;
        }
        case 2:
        {
            dest->setCylinder(PhysicsCylinderShape::Z, height, radius);
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
            dest->setCapsule(PhysicsCapsuleShape::X, height, radius);
            break;
        }
        case 1:
        {
            dest->setCapsule(PhysicsCapsuleShape::Y, height, radius);
            break;
        }
        case 2:
        {
            dest->setCapsule(PhysicsCapsuleShape::Z, height, radius);
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
            dest->setCone(PhysicsConeShape::X, height, radius);
            break;
        }
        case 1:
        {
            dest->setCone(PhysicsConeShape::Y, height, radius);
            break;
        }
        case 2:
        {
            dest->setCone(PhysicsConeShape::Z, height, radius);
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

        DELETE_ARRAY(float, data);
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

        DELETE_ARRAY(float, data);
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

        DELETE_ARRAY(float, data);
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

        DELETE_ARRAY(PhysicsCompoundShape::Child, children);
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
        String filename2(length);
        file->read(length, filename2.getData());

        dest = resMgr->getResourceByFilename<PhysicsShape>(filename2);
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
        File file(filename.getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 's' or
            magic[1] != 'h' or
            magic[2] != 'p' or
            magic[3] != 'e')
        {
            THROW(ResourceIOException, "physicsShape", filename, "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException, "physicsShape", filename, "Unsupported version.");
        }

        loadShape(this, &file, filename);
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "physicsShape",
              filename,
              e.getString());
    }
}

PhysicsShapeImpl::PhysicsShapeImpl() : type(Empty),
                                       shape(NEW(btEmptyShape)) {}

PhysicsShapeImpl::PhysicsShapeImpl(Type type_,
                                   btCollisionShape *shape_) : type(type_),
                                                               shape(shape_) {}

PhysicsShapeImpl::~PhysicsShapeImpl()
{
    DELETE(btCollisionShape, shape);
}

PhysicsSphereShape::PhysicsSphereShape(float radius_)
: PhysicsShapeImpl(Sphere, NEW(btSphereShape, radius_)) {}

PhysicsBoxShape::PhysicsBoxShape(const Vector3D& halfExtents_)
 : PhysicsShapeImpl(Box, NEW(btBoxShape, btVector3(halfExtents_.x,
                                                   halfExtents_.y,
                                                   halfExtents_.z))),
   halfExtents(halfExtents_) {}

btCollisionShape *createCylinder(PhysicsCylinderShape::Axis axis,
                                 float height,
                                 float radius)
{
    switch (axis)
    {
    case PhysicsCylinderShape::X:
    {
        return NEW(btCylinderShapeX, btVector3(height/2.0f, radius, radius));
    }
    case PhysicsCylinderShape::Y:
    {
        return NEW(btCylinderShape, btVector3(radius, height/2.0f, radius));
    }
    case PhysicsCylinderShape::Z:
    {
        return NEW(btCylinderShapeZ, btVector3(radius, radius, height/2.0f));
    }
    }

    return NEW(btCylinderShape, btVector3(radius, height/2.0f, radius));
}

PhysicsCylinderShape::PhysicsCylinderShape(Axis axis_,
                                           float height_,
                                           float radius_) : PhysicsShapeImpl(Cylinder,
                                                                             createCylinder(axis_,
                                                                                            height_,
                                                                                            radius_)),
                                                            axis(axis_),
                                                            height(height_),
                                                            radius(radius_) {}

btCollisionShape *createCapsule(PhysicsCapsuleShape::Axis axis,
                                float height,
                                float radius)
{
    switch (axis)
    {
    case PhysicsCapsuleShape::X:
    {
        return NEW(btCapsuleShapeX, radius, height);
    }
    case PhysicsCapsuleShape::Y:
    {
        return NEW(btCapsuleShape, radius, height);
    }
    case PhysicsCapsuleShape::Z:
    {
        return NEW(btCapsuleShapeZ, radius, height);
    }
    }

    return NEW(btConeShape, radius, height);
}

PhysicsCapsuleShape::PhysicsCapsuleShape(Axis axis_,
                                         float height_,
                                         float radius_) : PhysicsShapeImpl(Capsule,
                                                                           createCapsule(axis_,
                                                                                         height_,
                                                                                         radius_)),
                                                          axis(axis_),
                                                          height(height_),
                                                          radius(radius_) {}

btCollisionShape *createCone(PhysicsConeShape::Axis axis,
                             float height,
                             float radius)
{
    switch (axis)
    {
    case PhysicsConeShape::X:
    {
        return NEW(btConeShapeX, radius, height);
    }
    case PhysicsConeShape::Y:
    {
        return NEW(btConeShape, radius, height);
    }
    case PhysicsConeShape::Z:
    {
        return NEW(btConeShapeZ, radius, height);
    }
    }

    return NEW(btConeShape, radius, height);
}

PhysicsConeShape::PhysicsConeShape(Axis axis_,
                                   float height_,
                                   float radius_) : PhysicsShapeImpl(Cone,
                                                                     createCone(axis_,
                                                                                height_,
                                                                                radius_)),
                                                    axis(axis_),
                                                    height(height_),
                                                    radius(radius_) {}

PhysicsConvexHullShape::PhysicsConvexHullShape(size_t numPoints_,
                                               const Position3D *points_)
 : PhysicsShapeImpl(ConvexHull, NEW(btConvexHullShape,
                                    reinterpret_cast<const btScalar *>(points_),
                                    numPoints_,
                                    sizeof(Position3D))),
   numPoints(numPoints_)
{
    points = NEW_ARRAY(Position3D, numPoints);

    std::memcpy(points, points_, sizeof(Position3D)*numPoints);
}

PhysicsConvexHullShape::~PhysicsConvexHullShape()
{
    DELETE_ARRAY(Position3D, points);
}

btCollisionShape *createBVHMesh(size_t numTriangles,
                                const Position3D *triangles,
                                btTriangleIndexVertexArray*& vertexArray,
                                int*& indices,
                                btScalar*& btTriangles)
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

    return NEW(btBvhTriangleMeshShape, vertexArray, true);
}

PhysicsStaticTriangleMesh::PhysicsStaticTriangleMesh(size_t numTriangles_,
                                                     const Position3D *triangles_)
 : PhysicsShapeImpl(StaticTriangleMesh, createBVHMesh(numTriangles_,
                                                      triangles_,
                                                      vertexArray,
                                                      indices,
                                                      btTriangles)),
   numTriangles(numTriangles_)
{
    triangles = NEW_ARRAY(Position3D, numTriangles_ * 3);

    std::memcpy(triangles, triangles_, sizeof(Position3D)*numTriangles*3);
}

PhysicsStaticTriangleMesh::~PhysicsStaticTriangleMesh()
{
    DELETE_ARRAY(Position3D, triangles);
    DELETE_ARRAY(btScalar, btTriangles);
    DELETE_ARRAY(int, indices);
    DELETE(btTriangleIndexVertexArray, vertexArray);
}

btCollisionShape *createHeightfield(uint32_t width,
                                    uint32_t height,
                                    const float *data,
                                    float*& destData)
{
    destData = NEW_ARRAY(float, width*height);
    float maxHeight = -INFINITY;

    float value;
    for (size_t i = 0; i < width*height; ++i)
    {
        value = data[i];

        destData[i] = value;

        if (value > maxHeight)
        {
            maxHeight = value;
        }
    }

    return NEW(btHeightfieldTerrainShape,
               width,
               height,
               destData,
               1.0f,
               0.0f,
               maxHeight,
               1,
               PHY_FLOAT,
               false);
}

PhysicsHeightfield::PhysicsHeightfield(uint32_t width_,
                                       uint32_t height_,
                                       const float *data_)
 : PhysicsShapeImpl(Heightfield, createHeightfield(width_, height_, data_, data)),
   width(width_),
   height(height_) {}

PhysicsHeightfield::~PhysicsHeightfield()
{
    DELETE_ARRAY(float, data);
}

btVector3 getPlaneNormal(const Vector3D& normal)
{
    Vector3D normalized = normal.normalize();

    return btVector3(normalized.x, normalized.y, normalized.z);
}

PhysicsPlaneShape::PhysicsPlaneShape(const Vector3D& normal_, float distance_)
: PhysicsShapeImpl(Plane, NEW(btStaticPlaneShape,
                              getPlaneNormal(normal_),
                              distance_)),
  normal(normal_.normalize()),
  distance(distance_) {}

btCollisionShape *PhysicsCompoundShape::createCompoundShape(size_t shapeCount,
                                                            const PhysicsCompoundShape::Child *shapes,
                                                            PhysicsCompoundShape::Child *& destShapes)
{
    destShapes = NEW_ARRAY(PhysicsCompoundShape::Child, shapeCount);

    for (size_t i = 0; i < shapeCount; ++i)
    {
        destShapes[i] = shapes[i];
    }

    btCompoundShape *shape = NEW(btCompoundShape);

    for (size_t i = 0; i < shapeCount; ++i)
    {
        const PhysicsCompoundShape::Child& child = shapes[i];

        btTransform transform;

        transform.setRotation(btQuaternion(child.orientation.x,
                                           child.orientation.y,
                                           child.orientation.z,
                                           child.orientation.w));
        transform.setOrigin(btVector3(child.position.x,
                                      child.position.y,
                                      child.position.z));

        shape->addChildShape(transform, child.shape->getBulletShape());
    }

    shape->recalculateLocalAabb();

    return shape;
}

PhysicsCompoundShape::PhysicsCompoundShape(size_t shapeCount_,
                                           const Child *shapes_)
 : PhysicsShapeImpl(Compound,
                    createCompoundShape(shapeCount_, shapes_, shapes)),
   shapeCount(shapeCount_) {}

PhysicsCompoundShape::~PhysicsCompoundShape()
{
    DELETE_ARRAY(PhysicsCompoundShape::Child, shapes);
}
