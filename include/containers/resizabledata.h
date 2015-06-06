#ifndef RESIZABLEDATA_H
#define RESIZABLEDATA_H

#include <exception>
#include <new>
#include <algorithm>
#include <stdint.h>
#include <stddef.h>
#include <cstring>
#include <cstdio>
#include <vector>

#include "error.h"

class ResizableData
{
    public:
        ResizableData() {}

        ResizableData(std::size_t size) : data(size) {}

        ResizableData(std::size_t size, const void *data_) : data((uint8_t *)data_, (uint8_t *)data_+size) {}

        bool operator == (const ResizableData& other) const
        {
            const std::vector<uint8_t>& odata = other.data;

            if (data.size() != odata.size())
            {
                return false;
            }

            for (size_t i = 0; i < data.size(); ++i)
            {
                if (data[i] != odata[i])
                {
                    return false;
                }
            }

            return true;
        }

        inline bool operator != (const ResizableData& other) const
        {
            return not (*this == other);
        }

        inline void *getData()
        {
            return data.data();
        }

        inline const void *getData() const
        {
            return data.data();
        }

        inline size_t getSize() const
        {
            return data.size();
        }

        inline void resize(std::size_t newSize)
        {
            data.resize(newSize);
        }

        inline void insert(std::size_t start, std::size_t size, const void *dataToInsert)
        {
            #ifdef DEBUG
            if (start > data.size())
            {
                THROW(BoundsException);
            }
            #endif

            data.insert(data.begin()+start, (uint8_t *)dataToInsert, (uint8_t *)dataToInsert+size);
        }

        inline void insert(std::size_t start, const ResizableData& data_)
        {
            #ifdef DEBUG
            if (start > data.size())
            {
                THROW(BoundsException);
            }
            #endif

            data.insert(data.begin()+start, data_.data.begin(), data_.data.end());
        }

        inline void append(std::size_t size, const void *dataToAppend)
        {
            data.insert(data.end(), (uint8_t *)dataToAppend, (uint8_t *)dataToAppend+size);
        }

        inline void append(const ResizableData& data_)
        {
            data.insert(data.end(), data_.data.begin(), data_.data.end());
        }

        inline void remove(std::size_t start, std::size_t size)
        {
            #ifdef DEBUG
            if (start+size > data.size())
            {
                THROW(BoundsException);
            }
            #endif

            data.erase(data.begin()+start, data.begin()+start+size);
        }

        inline void clear()
        {
            data.clear();
        }

        inline ResizableData copy() const
        {
            return ResizableData(data.size(), data.data());
        }
    private:
        std::vector<uint8_t> data;
};

#endif // RESIZABLEDATA_H
