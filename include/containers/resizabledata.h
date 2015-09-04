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

        inline bool operator != (const ResizableData& other) const
        {
            return not (*this == other);
        }

        inline void *getData() NO_BIND
        {
            return data.data();
        }

        inline const void *getData() const NO_BIND
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

        inline void insert(std::size_t start, std::size_t size, const void *dataToInsert) NO_BIND
        {
            if (start > data.size())
            {
                THROW(BoundsException);
            }

            data.insert(data.begin()+start, (uint8_t *)dataToInsert, (uint8_t *)dataToInsert+size);
        }

        inline void insert(std::size_t start, const ResizableData& data_)
        {
            if (start > data.size())
            {
                THROW(BoundsException);
            }

            data.insert(data.begin()+start, data_.data.begin(), data_.data.end());
        }

        inline void append(std::size_t size, const void *dataToAppend) NO_BIND
        {
            data.insert(data.end(), (uint8_t *)dataToAppend, (uint8_t *)dataToAppend+size);
        }

        inline void append(const ResizableData& data_)
        {
            data.insert(data.end(), data_.data.begin(), data_.data.end());
        }

        inline void remove(std::size_t start, std::size_t size)
        {
            if (start+size > data.size())
            {
                THROW(BoundsException);
            }

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

        template <typename T>
        inline T get(size_t offset) const NO_BIND
        {
            if (offset+sizeof(T) > data.size())
            {
                THROW(BoundsException);
            }

            return *(T *)(data.data()+offset);
        }

        template <typename T>
        inline void set(size_t offset, const T& v) const NO_BIND
        {
            if (offset+sizeof(T) > data.size())
            {
                THROW(BoundsException);
            }

            *(T *)(data.data()+offset) = v;
        }

        inline uint8_t getUInt8(size_t offset) const {return get<uint8_t>(offset);}
        inline int8_t getInt8(size_t offset) const {return get<int8_t>(offset);}
        inline uint16_t getUInt16(size_t offset) const {return get<uint16_t>(offset);}
        inline int16_t getInt16(size_t offset) const {return get<int16_t>(offset);}
        inline uint32_t getUInt32(size_t offset) const {return get<uint32_t>(offset);}
        inline int32_t getInt32(size_t offset) const {return get<int32_t>(offset);}
        inline uint64_t getUInt64(size_t offset) const {return get<uint64_t>(offset);}
        inline int64_t getInt64(size_t offset) const {return get<int64_t>(offset);}

        inline uint16_t getUInt16LE(size_t offset) const {return FROM_LE_U16(get<uint16_t>(offset));}
        inline int16_t getInt16LE(size_t offset) const {return FROM_LE_S16(get<int16_t>(offset));}
        inline uint32_t getUInt32LE(size_t offset) const {return FROM_LE_U32(get<uint32_t>(offset));}
        inline int32_t getInt32LE(size_t offset) const {return FROM_LE_S32(get<int32_t>(offset));}
        inline uint64_t getUInt64LE(size_t offset) const {return FROM_LE_U64(get<uint64_t>(offset));}
        inline int64_t getInt64LE(size_t offset) const {return FROM_LE_S64(get<int64_t>(offset));}

        inline uint16_t getUInt16BE(size_t offset) const {return FROM_BE_U16(get<uint16_t>(offset));}
        inline int16_t getInt16BE(size_t offset) const {return FROM_BE_S16(get<int16_t>(offset));}
        inline uint32_t getUInt32BE(size_t offset) const {return FROM_BE_U32(get<uint32_t>(offset));}
        inline int32_t getInt32BE(size_t offset) const {return FROM_BE_S32(get<int32_t>(offset));}
        inline uint64_t getUInt64BE(size_t offset) const {return FROM_BE_U64(get<uint64_t>(offset));}
        inline int64_t getInt64BE(size_t offset) const {return FROM_BE_S64(get<int64_t>(offset));}

        inline void setUInt8(size_t offset, uint8_t v) const {set<uint8_t>(offset, v);}
        inline void setInt8(size_t offset, int8_t v) const {set<int8_t>(offset, v);}
        inline void setUInt16(size_t offset, uint16_t v) const {set<uint16_t>(offset, v);}
        inline void setInt16(size_t offset, int16_t v) const {set<int16_t>(offset, v);}
        inline void setUInt32(size_t offset, uint32_t v) const {set<uint32_t>(offset, v);}
        inline void setInt32(size_t offset, int32_t v) const {set<int32_t>(offset, v);}
        inline void setUInt64(size_t offset, uint64_t v) const {set<uint64_t>(offset, v);}
        inline void setInt64(size_t offset, int64_t v) const {set<int64_t>(offset, v);}

        inline void setUInt16LE(size_t offset, uint16_t v) const {set<uint16_t>(offset, TO_LE_U16(v));}
        inline void setInt16LE(size_t offset, int16_t v) const {set<int16_t>(offset, TO_LE_S16(v));}
        inline void setUInt32LE(size_t offset, uint32_t v) const {set<uint32_t>(offset, TO_LE_U32(v));}
        inline void setInt32LE(size_t offset, int32_t v) const {set<int32_t>(offset, TO_LE_S32(v));}
        inline void setUInt64LE(size_t offset, uint64_t v) const {set<uint64_t>(offset, TO_LE_U64(v));}
        inline void setInt64LE(size_t offset, int64_t v) const {set<int64_t>(offset, TO_LE_S64(v));}

        inline void setUInt16BE(size_t offset, uint16_t v) const {set<uint16_t>(offset, TO_BE_U16(v));}
        inline void setInt16BE(size_t offset, int16_t v) const {set<int16_t>(offset, TO_BE_S16(v));}
        inline void setUInt32BE(size_t offset, uint32_t v) const {set<uint32_t>(offset, TO_BE_U32(v));}
        inline void setInt32BE(size_t offset, int32_t v) const {set<int32_t>(offset, TO_BE_S32(v));}
        inline void setUInt64BE(size_t offset, uint64_t v) const {set<uint64_t>(offset, TO_BE_U64(v));}
        inline void setInt64BE(size_t offset, int64_t v) const {set<int64_t>(offset, TO_BE_S64(v));}

        inline char getChar(size_t offset) const {return get<char>(offset);}
        inline void setChar(size_t offset, char c) const {set<char>(offset, c);}
    private:
        std::vector<uint8_t> data;
} BIND;

#endif // RESIZABLEDATA_H
