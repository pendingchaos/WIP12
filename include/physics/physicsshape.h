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

        inline Type getType() const
        {
            return type;
        }

        inline float getMargin() const
        {
            return shape->getMargin();
        }

        inline void setMargin(float margin)
        {
            shape->setMargin(margin);
        }

        inline Direction3D getScale() const
        {
            btVector3 scale = shape->getLocalScaling();

            return Direction3D(scale.getX(), scale.getY(), scale.getZ());
        }

        inline void setScale(const Direction3D& scale)
        {
            shape->setLocalScaling(btVector3(scale.x, scale.y, scale.z));
        }

        inline btCollisionShape *getBulletShape() const
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

        inline float getRadius() const
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

        inline Vector3D getHalfExtents() const
        {
            return halfExtents;
        }

        void setHalfExtents(const Vector3D& halfExtents);
    private:
        void create();

        Vector3D halfExtents;

    NO_COPY_INHERITED(PhysicsBoxShape, PhysicsShapeImpl)
};

class PhysicsCylinderShape : public PhysicsShapeImpl
{
    public:
        enum Axis
        {
            X,
            Y,
            Z
        };

        PhysicsCylinderShape(PhysicsShape *physShape, PhysicsCylinderShape::Axis axis, float height, float radius);

        inline Axis getAxis() const
        {
            return axis;
        }

        inline float getHeight() const
        {
            return height;
        }

        inline float getRadius() const
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
        enum Axis
        {
            X,
            Y,
            Z
        };

        PhysicsCapsuleShape(PhysicsShape *physShape, PhysicsCapsuleShape::Axis axis, float height, float radius);

        inline PhysicsCapsuleShape::Axis getAxis() const
        {
            return axis;
        }

        inline float getHeight() const
        {
            return height;
        }

        inline float getRadius() const
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
        enum Axis
        {
            X,
            Y,
            Z
        };

        PhysicsConeShape(PhysicsShape *physShape, PhysicsConeShape::Axis axis, float height, float radius);

        inline PhysicsConeShape::Axis getAxis() const
        {
            return axis;
        }

        inline float getHeight() const
        {
            return height;
        }

        inline float getRadius() const
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

        inline size_t getNumPoints() const
        {
            return numPoints;
        }

        inline const Position3D *getPoints() const
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

        inline size_t getNumTriangles() const
        {
            return numTriangles;
        }

        inline const Position3D *getTriangles() const
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

        inline uint32_t getWidth() const
        {
            return width;
        }

        inline uint32_t getHeight() const
        {
            return height;
        }

        inline const float *getData() const
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

        inline Vector3D getNormal() const
        {
            return normal;
        }

        inline float getDistance() const
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

                bool operator == (const PhysicsCompoundShape::Child& other) const
                {
                    return orientation == other.orientation and
                           position == other.position and
                           shape == other.shape;
                }
        };

        PhysicsCompoundShape(PhysicsShape *physShape, size_t shapeCount, const Child *shapes);
        virtual ~PhysicsCompoundShape();

        inline size_t getShapeCount() const
        {
            return shapeCount;
        }

        inline const PhysicsCompoundShape::Child *getShapes() const
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
        static const Resource::Type resource_type = Resource::PhysicsShapeType;

        PhysicsShape();
        PhysicsShape(const String& filename);
        virtual ~PhysicsShape();

        virtual void removeContent()
        {
            setEmpty();
        }

        inline PhysicsShapeImpl *getImpl() const
        {
            return impl;
        }

        inline PhysicsShapeImpl::Type getShapeType() const
        {
            return impl->getType();
        }

        inline float getMargin() const
        {
            return impl->getMargin();
        }

        inline void setMargin(float margin)
        {
            impl->setMargin(margin);
        }

        inline Vector3D getScale() const
        {
            return impl->getScale();
        }

        inline void setScale(const Vector3D& scale)
        {
            impl->setScale(scale);
        }

        inline btCollisionShape *getBulletShape() const
        {
            return impl->getBulletShape();
        }

        void setEmpty();
        void setSphere(float radius);
        void setBox(const Vector3D& halfExtents);
        void setCylinder(PhysicsCylinderShape::Axis axis, float height, float radius);
        void setCapsule(PhysicsCapsuleShape::Axis axis, float height, float radius);
        void setCone(PhysicsConeShape::Axis axis, float height, float radius);
        void setConvexHull(size_t pointCount, const Position3D *points);
        void setStaticTriangleMesh(size_t numVertices, const Position3D *vertices);
        void setHeightfield(uint32_t width, uint32_t height, const float *data);
        void setPlane(const Vector3D& normal, float distance);
        void setCompound(size_t childCount, const PhysicsCompoundShape::Child *children);

        virtual void save();
    private:
        PhysicsShapeImpl *impl;
        List<RigidBody *> rigidBodies;
        List<GhostObject *> ghosts;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;
};

#endif // PHYSICSSHAPE_H
