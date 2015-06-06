#ifndef LIST_H
#define LIST_H

#include "containers/resizabledata.h"
#include "error.h"

#include <vector>

template <typename T>
inline bool listIsEqual(const T& v1, const T& v2)
{
    return v1 == v2;
}

template <typename T,
          bool (*Equal)(const T&, const T&)=listIsEqual>
class List
{
    public:
        List() {}
        List(std::size_t count) : data(count) {}
        List(std::size_t count, const T *data_) : data(data_, data_+count) {}

        List(const ResizableData& other)
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
                if (not Equal(data[i], other.data[i]))
                {
                    return false;
                }
            }

            return true;
        }

        inline bool operator != (const List& other) const
        {
            return not (*this == other);
        }

        inline const T& operator [] (std::size_t index) const
        {
            if (index >= data.size())
            {
                THROW(BoundsException);
            }

            return data[index];
        }

        inline T& operator [] (std::size_t index)
        {
            if (index >= data.size())
            {
                THROW(BoundsException);
            }

            return data[index];
        }

        inline std::size_t getCount() const
        {
            return data.size();
        }

        inline T *getData()
        {
            return data.data();
        }

        inline const T *getData() const
        {
            return data.data();
        }

        void append(const T& toAppend)
        {
            data.push_back(toAppend);
        }

        void append(std::size_t count, const T *toAppend)
        {
            data.insert(data.end(), toAppend, toAppend+count);
        }

        void append(const List& toAppend)
        {
            data.insert(data.end(), toAppend.data.begin(), toAppend.data.end());
        }

        void insert(std::size_t start, std::size_t count, const T *toInsert)
        {
            if (start > data.size())
            {
                THROW(BoundsException);
            }

            data.insert(data.begin()+start, toInsert, toInsert+count);
        }

        inline void insert(std::size_t start, const List& toInsert)
        {
            if (start > data.size())
            {
                THROW(BoundsException);
            }

            data.insert(data.begin()+start, toInsert.data.begin(), toInsert.data.end());
        }

        void remove(std::size_t index, std::size_t count=1)
        {
            if (index+count > data.size())
            {
                THROW(BoundsException);
            }

            data.erase(data.begin()+index, data.begin()+index+count);
        }

        void clear()
        {
            data.clear();
        }

        int find(const T& toFind)
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

        inline List copy() const
        {
            return List(getCount(), data.data());
        }
    private:
        std::vector<T> data;
};

#endif // LIST_H
