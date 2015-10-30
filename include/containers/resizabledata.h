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
#include "endian_utils.h"
#include "scripting/bindings.h"

class ResizableData
{
    public:
        ResizableData() {}

        ResizableData(std::size_t size) : data(size) {}

        ResizableData(std::size_t size, const void *data_) NO_BIND : data((uint8_t *)data_, (uint8_t *)data_+size) {}

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

        bool operator != (const ResizableData& other) const
        {
            return not (*this == other);
        }

        void *getData() NO_BIND
        {
            return data.data();
        }

        const void *getData() const NO_BIND
        {
            return data.data();
        }

        size_t getSize() const
        {
            return data.size();
        }

        void resize(std::size_t newSize)
        {
            data.resize(newSize);
        }

        void insert(std::size_t start, std::size_t size, const void *dataToInsert) NO_BIND
        {
            if (start > data.size())
            {
                THROW(BoundsException);
            }

            data.insert(data.begin()+start, (uint8_t *)dataToInsert, (uint8_t *)dataToInsert+size);
        }

        void insert(std::size_t start, const ResizableData& data_)
        {
            if (start > data.size())
            {
                THROW(BoundsException);
            }

            data.insert(data.begin()+start, data_.data.begin(), data_.data.end());
        }

        void append(std::size_t size, const void *dataToAppend) NO_BIND
        {
            data.insert(data.end(), (uint8_t *)dataToAppend, (uint8_t *)dataToAppend+size);
        }

        void append(const ResizableData& data_)
        {
            data.insert(data.end(), data_.data.begin(), data_.data.end());
        }

        void remove(std::size_t start, std::size_t size)
        {
            if (start+size > data.size())
            {
                THROW(BoundsException);
            }

            data.erase(data.begin()+start, data.begin()+start+size);
        }

        void clear()
        {
            data.clear();
        }

        ResizableData copy() const
        {
            return ResizableData(data.size(), data.data());
        }

        template <typename T>
        T get(size_t offset) const NO_BIND
        {
            if (offset+sizeof(T) > data.size())
            {
                THROW(BoundsException);
            }

            return *(T *)(data.data()+offset);
        }

        template <typename T>
        void set(size_t offset, const T& v) const NO_BIND
        {
            if (offset+sizeof(T) > data.size())
            {
                THROW(BoundsException);
            }

            *(T *)(data.data()+offset) = v;
        }

        uint8_t getUInt8(size_t offset) const {return get<uint8_t>(offset);}
        int8_t getInt8(size_t offset) const {return get<int8_t>(offset);}
        uint16_t getUInt16(size_t offset) const {return get<uint16_t>(offset);}
        int16_t getInt16(size_t offset) const {return get<int16_t>(offset);}
        uint32_t getUInt32(size_t offset) const {return get<uint32_t>(offset);}
        int32_t getInt32(size_t offset) const {return get<int32_t>(offset);}
        uint64_t getUInt64(size_t offset) const {return get<uint64_t>(offset);}
        int64_t getInt64(size_t offset) const {return get<int64_t>(offset);}
        float getFloat32(size_t offset) const {return get<float>(offset);}
        double getFloat64(size_t offset) const {return get<double>(offset);}

        uint16_t getUInt16LE(size_t offset) const {return FROM_LE_U16(get<uint16_t>(offset));}
        int16_t getInt16LE(size_t offset) const {return FROM_LE_S16(get<int16_t>(offset));}
        uint32_t getUInt32LE(size_t offset) const {return FROM_LE_U32(get<uint32_t>(offset));}
        int32_t getInt32LE(size_t offset) const {return FROM_LE_S32(get<int32_t>(offset));}
        uint64_t getUInt64LE(size_t offset) const {return FROM_LE_U64(get<uint64_t>(offset));}
        int64_t getInt64LE(size_t offset) const {return FROM_LE_S64(get<int64_t>(offset));}

        uint16_t getUInt16BE(size_t offset) const {return FROM_BE_U16(get<uint16_t>(offset));}
        int16_t getInt16BE(size_t offset) const {return FROM_BE_S16(get<int16_t>(offset));}
        uint32_t getUInt32BE(size_t offset) const {return FROM_BE_U32(get<uint32_t>(offset));}
        int32_t getInt32BE(size_t offset) const {return FROM_BE_S32(get<int32_t>(offset));}
        uint64_t getUInt64BE(size_t offset) const {return FROM_BE_U64(get<uint64_t>(offset));}
        int64_t getInt64BE(size_t offset) const {return FROM_BE_S64(get<int64_t>(offset));}

        void setUInt8(size_t offset, uint8_t v) const {set<uint8_t>(offset, v);}
        void setInt8(size_t offset, int8_t v) const {set<int8_t>(offset, v);}
        void setUInt16(size_t offset, uint16_t v) const {set<uint16_t>(offset, v);}
        void setInt16(size_t offset, int16_t v) const {set<int16_t>(offset, v);}
        void setUInt32(size_t offset, uint32_t v) const {set<uint32_t>(offset, v);}
        void setInt32(size_t offset, int32_t v) const {set<int32_t>(offset, v);}
        void setUInt64(size_t offset, uint64_t v) const {set<uint64_t>(offset, v);}
        void setInt64(size_t offset, int64_t v) const {set<int64_t>(offset, v);}
        void setFloat32(size_t offset, float v) const {set<float>(offset, v);}
        void setFloat64(size_t offset, double v) const {set<double>(offset, v);}

        void setUInt16LE(size_t offset, uint16_t v) const {set<uint16_t>(offset, TO_LE_U16(v));}
        void setInt16LE(size_t offset, int16_t v) const {set<int16_t>(offset, TO_LE_S16(v));}
        void setUInt32LE(size_t offset, uint32_t v) const {set<uint32_t>(offset, TO_LE_U32(v));}
        void setInt32LE(size_t offset, int32_t v) const {set<int32_t>(offset, TO_LE_S32(v));}
        void setUInt64LE(size_t offset, uint64_t v) const {set<uint64_t>(offset, TO_LE_U64(v));}
        void setInt64LE(size_t offset, int64_t v) const {set<int64_t>(offset, TO_LE_S64(v));}

        void setUInt16BE(size_t offset, uint16_t v) const {set<uint16_t>(offset, TO_BE_U16(v));}
        void setInt16BE(size_t offset, int16_t v) const {set<int16_t>(offset, TO_BE_S16(v));}
        void setUInt32BE(size_t offset, uint32_t v) const {set<uint32_t>(offset, TO_BE_U32(v));}
        void setInt32BE(size_t offset, int32_t v) const {set<int32_t>(offset, TO_BE_S32(v));}
        void setUInt64BE(size_t offset, uint64_t v) const {set<uint64_t>(offset, TO_BE_U64(v));}
        void setInt64BE(size_t offset, int64_t v) const {set<int64_t>(offset, TO_BE_S64(v));}

        char getChar(size_t offset) const {return get<char>(offset);}
        void setChar(size_t offset, char c) const {set<char>(offset, c);}
    private:
        std::vector<uint8_t> data;
} BIND;

#endif // RESIZABLEDATA_H
