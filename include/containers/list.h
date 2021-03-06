#ifndef LIST_H
#define LIST_H

#include "containers/resizabledata.h"
#include "error.h"

#include <vector>

template <typename T>
class List
{
    public:
        List() {}
        List(std::size_t count) : data(count) {}
        List(std::size_t count, const T *data_) NO_BIND : data(data_, data_+count) {}

        List(const ResizableData& other) NO_BIND
        : data(other.getData(), other.getData()+other.getSize()) {}

        List(const List<T>& other)
        : data(other.data) {}

        bool operator == (const List& other) const
        {
            if (getCount() != other.getCount())
            {
                return false;
            }

            for (std::size_t i = 0; i < getCount(); ++i)
            {
                if (not (data[i] == other.data[i]))
                {
                    return false;
                }
            }

            return true;
        }

        bool operator != (const List& other) const
        {
            return not (*this == other);
        }

        const T& operator [] (std::size_t index) const NO_BIND
        {
            #if DEBUG
            if (index >= data.size())
            {
                THROW(BoundsException);
            }
            #endif

            return data[index];
        }

        T& operator [] (std::size_t index) NO_BIND
        {
            if (index >= data.size())
            {
                THROW(BoundsException);
            }

            return data[index];
        }

        T get(size_t index) const
        {
            return (*this)[index];
        }

        void set(size_t index, const T& v)
        {
            (*this)[index] = v;
        }

        std::size_t getCount() const
        {
            return data.size();
        }

        T *getData() NO_BIND
        {
            return data.data();
        }

        const T *getData() const NO_BIND
        {
            return data.data();
        }

        void append(const T& toAppend)
        {
            data.push_back(toAppend);
        }

        void append(std::size_t count, const T *toAppend) NO_BIND
        {
            data.insert(data.end(), toAppend, toAppend+count);
        }

        void append(const List& toAppend)
        {
            data.insert(data.end(), toAppend.data.begin(), toAppend.data.end());
        }

        void insert(std::size_t start, std::size_t count, const T *toInsert) NO_BIND
        {
            #if DEBUG
            if (start > data.size())
            {
                THROW(BoundsException);
            }
            #endif

            data.insert(data.begin()+start, toInsert, toInsert+count);
        }

        void insert(std::size_t start, const T& toInsert)
        {
            insert(start, 1, &toInsert);
        }

        void insert(std::size_t start, const List& toInsert)
        {
            #if DEBUG
            if (start > data.size())
            {
                THROW(BoundsException);
            }
            #endif

            data.insert(data.begin()+start, toInsert.data.begin(), toInsert.data.end());
        }

        void remove(std::size_t index, std::size_t count=1)
        {
            #if DEBUG
            if (index+count > data.size())
            {
                THROW(BoundsException);
            }
            #endif

            data.erase(data.begin()+(int)index, data.begin()+(int)index+(int)count);
        }

        void clear()
        {
            data.clear();
        }

        int find(const T& toFind) const
        {
            for (std::size_t i = 0; i < getCount(); ++i)
            {
                if (data[i] == toFind)
                {
                    return i;
                }
            }

            return -1;
        }

        List copy() const
        {
            return List(getCount(), data.data());
        }

        bool in(const T& value) const
        {
            return find(value) != -1;
        }

        void reserve(size_t amount)
        {
            data.reserve(getCount()+amount);
        }

        class Iterator
        {
            friend List;

            public:
                T& operator * () const
                {
                    return list.getData()[i];
                }

                Iterator& operator ++ ()
                {
                    ++i;
                    return *this;
                }

                bool operator != (const Iterator& other) const
                {
                    return i != other.i;
                }
            private:
                Iterator(List<T>& list_, size_t i_) : list(list_), i(i_) {}

                List<T>& list;
                size_t i;
        };

        class ConstIterator
        {
            friend List;

            public:
                const T& operator * () const
                {
                    return list.getData()[i];
                }

                ConstIterator& operator ++ ()
                {
                    ++i;
                    return *this;
                }

                bool operator != (const ConstIterator& other) const
                {
                    return i != other.i;
                }
            private:
                ConstIterator(const List<T>& list_, size_t i_) : list(list_), i(i_) {}

                const List<T>& list;
                size_t i;
        };

        Iterator begin() NO_BIND
        {
            return Iterator(*this, 0);
        }

        Iterator end() NO_BIND
        {
            return Iterator(*this, getCount());
        }

        ConstIterator begin() const NO_BIND
        {
            return ConstIterator(*this, 0);
        }

        ConstIterator end() const NO_BIND
        {
            return ConstIterator(*this, getCount());
        }
    private:
        std::vector<T> data;
};

BIND_CLASS(List)
TEMPLATE_TYPES(List:T, <GfxLOD>@GfxLODList <GfxModel::SubModel>@GfxSubModelList <AutoVal>@List <GhostObject*>@GhostObjList <RigidBody*>@RigidBodyList <AudioSource*>@AudioSourceList <Entity*>@EntityList <Light*>@LightList <Str>@StringList <float>@FloatList <RayCastResult>@RayCastResultList <ScriptInstance*>@ScriptInstanceList)

#endif // LIST_H
