#ifndef PHYSICSSHAPE_H
#define PHYSICSSHAPE_H

#include "math/t3.h"
#include "math/quaternion.h"
#include "misc_macros.h"
#include "containers/list.h"
#include "resource/resource.h"

#include "btBulletCollisionCommon.h"
#include <stdint.h>

//PhysicsConvexHull do not work with doubles.
#ifdef BT_USE_DOUBLE_PRECISION
STATIC_ASSERT_FAIL_IF_TRUE(true);
#endif

class PhysicsShape;

class PhysicsShapeImpl
{
    friend PhysicsShape;

    public:
        enum Type
        {
            Sphere,
            Box,
            Cylinder,
            Capsule,
            Cone,
            ConvexHull,
            StaticTriangleMesh,
            Heightfield,
            Plane,
            Compound,
            Empty
        };

        Type getType() const
        {
            return type;
        }

        float getMargin() const
        {
            return shape->getMargin();
        }

        void setMargin(float margin)
        {
            shape->setMargin(margin);
        }

        Direction3D getScale() const
        {
            btVector3 scale = shape->getLocalScaling();

            return Direction3D(scale.getX(), scale.getY(), scale.getZ());
        }

        void setScale(const Direction3D& scale)
        {
            shape->setLocalScaling(btVector3(scale.x, scale.y, scale.z));
        }

        btCollisionShape *getBulletShape() const
        {
            return shape;
        }
    private:
        Type type;
    protected:
        PhysicsShapeImpl(PhysicsShape *physShape, Type type, btCollisionShape *shape);
        virtual ~PhysicsShapeImpl();

        void updateRigidBodies();

        btCollisionShape *shape;
        PhysicsShape *physShape;

    NO_COPY(PhysicsShapeImpl)
};

class PhysicsSphereShape : public PhysicsShapeImpl
{
    public:
        PhysicsSphereShape(PhysicsShape *physShape, float radius);

        float getRadius() const
        {
            return radius;
        }

        void setRadius(float radius);
    private:
        void create();

        float radius;

    NO_COPY_INHERITED(PhysicsSphereShape, PhysicsShapeImpl)
};

class PhysicsBoxShape : public PhysicsShapeImpl
{
    public:
        PhysicsBoxShape(PhysicsShape *physShape, const Vector3D& halfExtents);

        Vector3D getHalfExtents() const
        {
            return halfExtents;
        }

        void setHalfExtents(const Vector3D& halfExtents);
    private:
        void create();

        Vector3D halfExtents;

    NO_COPY_INHERITED(PhysicsBoxShape, PhysicsShapeImpl)
};

enum class Axis
{
    X,
    Y,
    Z
} ENUM_CLASS BIND;

class PhysicsCylinderShape : public PhysicsShapeImpl
{
    public:
        PhysicsCylinderShape(PhysicsShape *physShape, Axis axis, float height, float radius);

        Axis getAxis() const
        {
            return axis;
        }

        float getHeight() const
        {
            return height;
        }

        float getRadius() const
        {
            return radius;
        }

        void setAxis(Axis axis);
        void setHeight(float height);
        void setRadius(float radius);
    private:
        void create();

        Axis axis;
        float height;
        float radius;

    NO_COPY_INHERITED(PhysicsCylinderShape, PhysicsShapeImpl)
};

class PhysicsCapsuleShape : public PhysicsShapeImpl
{
    public:
        PhysicsCapsuleShape(PhysicsShape *physShape, Axis axis, float height, float radius);

        Axis getAxis() const
        {
            return axis;
        }

        float getHeight() const
        {
            return height;
        }

        float getRadius() const
        {
            return radius;
        }

        void setAxis(Axis axis);
        void setHeight(float height);
        void setRadius(float radius);
    private:
        void create();

        Axis axis;
        float height;
        float radius;

    NO_COPY_INHERITED(PhysicsCapsuleShape, PhysicsShapeImpl)
};

class PhysicsConeShape : public PhysicsShapeImpl
{
    public:
        PhysicsConeShape(PhysicsShape *physShape, Axis axis, float height, float radius);

        Axis getAxis() const
        {
            return axis;
        }

        float getHeight() const
        {
            return height;
        }

        float getRadius() const
        {
            return radius;
        }

        void setAxis(Axis axis);
        void setHeight(float height);
        void setRadius(float radius);
    private:
        void create();

        Axis axis;
        float height;
        float radius;

    NO_COPY_INHERITED(PhysicsConeShape, PhysicsShapeImpl)
};

class PhysicsConvexHullShape : public PhysicsShapeImpl
{
    public:
        PhysicsConvexHullShape(PhysicsShape *physShape, size_t numPoints, const Position3D *points);
        virtual ~PhysicsConvexHullShape();

        size_t getNumPoints() const
        {
            return numPoints;
        }

        const Position3D *getPoints() const
        {
            return points;
        }

        void setPoints(size_t numPoints, const Position3D *points);
    private:
        void create(const Position3D *points);

        size_t numPoints;
        Position3D *points;

    NO_COPY_INHERITED(PhysicsConvexHullShape, PhysicsShapeImpl)
};

class PhysicsStaticTriangleMesh : public PhysicsShapeImpl
{
    public:
        PhysicsStaticTriangleMesh(PhysicsShape *physShape, size_t numTriangles, const Position3D *triangles);
        virtual ~PhysicsStaticTriangleMesh();

        size_t getNumTriangles() const
        {
            return numTriangles;
        }

        const Position3D *getTriangles() const
        {
            return triangles;
        }

        void setTriangles(size_t numTriangles, const Position3D *triangles);
    private:
        void create(const Position3D *triangles);

        size_t numTriangles;
        Position3D *triangles;
        btTriangleIndexVertexArray *vertexArray;
        int *indices;
        btScalar *btTriangles;

    NO_COPY_INHERITED(PhysicsStaticTriangleMesh, PhysicsShapeImpl)
};

class PhysicsHeightfield : public PhysicsShapeImpl
{
    public:
        PhysicsHeightfield(PhysicsShape *physShape, uint32_t width, uint32_t height, const float *data);
        virtual ~PhysicsHeightfield();

        uint32_t getWidth() const
        {
            return width;
        }

        uint32_t getHeight() const
        {
            return height;
        }

        const float *getData() const
        {
            return data;
        }

        void setData(uint32_t width, uint32_t height, const float *data);
    private:
        void create(const float *data);

        uint32_t width;
        uint32_t height;
        float *data;

    NO_COPY_INHERITED(PhysicsHeightfield, PhysicsShapeImpl)
};

class PhysicsPlaneShape : public PhysicsShapeImpl
{
    public:
        PhysicsPlaneShape(PhysicsShape *physShape, const Vector3D& normal, float distance);

        Vector3D getNormal() const
        {
            return normal;
        }

        float getDistance() const
        {
            return distance;
        }

        void setNormal(const Vector3D& normal);
        void setDistance(float distance);
    private:
        void create();

        Vector3D normal;
        float distance;

    NO_COPY_INHERITED(PhysicsPlaneShape, PhysicsShapeImpl)
};

class PhysicsShape;

class PhysicsCompoundShape : public PhysicsShapeImpl
{
    public:
        class Child
        {
            friend PhysicsCompoundShape;

            public:
                Child() {}
                Child(PhysicsShape *shape_) : shape(shape_) {}

                Quaternion orientation;
                Position3D position;
                PhysicsShape *shape;
        };

        PhysicsCompoundShape(PhysicsShape *physShape, size_t shapeCount, const Child *shapes);
        virtual ~PhysicsCompoundShape();

        size_t getShapeCount() const
        {
            return shapeCount;
        }

        const PhysicsCompoundShape::Child *getShapes() const
        {
            return shapes;
        }

        void setChildren(size_t count, const Child *children);
    private:
        void create(const Child *shapes);

        size_t shapeCount;
        Child *shapes;

        static btCollisionShape *createCompoundShape(size_t shapeCount,
                                                     const Child *shapes,
                                                     Child *& destShapes);

    NO_COPY_INHERITED(PhysicsCompoundShape, PhysicsShapeImpl)
};

class RigidBody;
class GhostObject;

class PhysicsShape : public Resource
{
    friend PhysicsShapeImpl;
    friend RigidBody;
    friend GhostObject;

    public:
        static const ResType resource_type = ResType::PhysicsShapeType;

        PhysicsShape();
        PhysicsShape(const Str& filename);
        virtual ~PhysicsShape();

        virtual void removeContent()
        {
            setEmpty();
        }

        PhysicsShapeImpl *getImpl() const NO_BIND
        {
            return impl;
        }

        PhysicsShapeImpl::Type getShapeType() const NO_BIND
        {
            return impl->getType();
        }

        float getMargin() const
        {
            return impl->getMargin();
        }

        void setMargin(float margin)
        {
            impl->setMargin(margin);
        }

        Vector3D getScale() const
        {
            return impl->getScale();
        }

        void setScale(const Vector3D& scale)
        {
            impl->setScale(scale);
        }

        btCollisionShape *getBulletShape() const NO_BIND
        {
            return impl->getBulletShape();
        }

        void setEmpty();
        void setSphere(float radius);
        void setBox(const Vector3D& halfExtents);
        void setCylinder(Axis axis, float height, float radius);
        void setCapsule(Axis axis, float height, float radius);
        void setCone(Axis axis, float height, float radius);
        void setConvexHull(size_t pointCount, const Position3D *points) NO_BIND;
        void setStaticTriangleMesh(size_t numVertices, const Position3D *vertices) NO_BIND;
        void setHeightfield(uint32_t width, uint32_t height, const float *data) NO_BIND;
        void setPlane(const Vector3D& normal, float distance);
        void setCompound(size_t childCount, const PhysicsCompoundShape::Child *children) NO_BIND;

        virtual void save();
    private:
        PhysicsShapeImpl *impl;
        List<RigidBody *> rigidBodies;
        List<GhostObject *> ghosts;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;
} DESTROY(obj->release()) BIND;

#endif // PHYSICSSHAPE_H
