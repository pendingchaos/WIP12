#ifndef HASHMAP_H
#define HASHMAP_H

#include "containers/list.h"
#include "error.h"
#include "scripting/bindings.h"

#include <stddef.h>
#include <stdint.h>
#include <unordered_map>

inline size_t getHash(const bool& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const uint8_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const int8_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const uint16_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const int16_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const uint32_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const int32_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const uint64_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const int64_t& value)
{
    return static_cast<size_t>(value);
}

inline size_t getHash(const float& value)
{
    const uint32_t *pointer = reinterpret_cast<const uint32_t *>(&value);

    return getHash(*pointer);
}

inline size_t getHash(const double& value)
{
    const uint64_t *pointer = reinterpret_cast<const uint64_t *>(&value);

    return getHash(*pointer);
}

template <typename T>
size_t getHash(const T& value)
{
    return 0;
}

namespace std
{
    template <typename T>
    struct hash
    {
        size_t operator () (const T& v) const
        {
            return getHash(v);
        }
    };
};

class LookupException : public Exception
{
    public:
        LookupException(const char *file_,
                        size_t line_,
                        const char *function_) : Exception(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "A hash map lookup failed.";
        }
};

template <typename Key,
          typename Value>
class HashMap
{
    public:
        bool operator == (const HashMap<Key,
                                        Value>& other) const
        {
            if (getCount() != other.getCount())
            {
                return false;
            }

            for (auto kv : *this)
            {
                auto otherPos = other.find(kv.first);

                if (otherPos == other.end())
                {
                    return false;
                }

                if (kv.second != otherPos->second)
                {
                    return false;
                }
            }

            return true;
        }

        bool operator != (const HashMap<Key,
                                        Value>& other) const
        {
            return not (*this == other);
        }

        const Value& get(const Key& key) const
        {
            try
            {
                return data.at(key);
            } catch (std::exception& e)
            {
                THROW(LookupException);
            }
        }

        Value& get(const Key& key)
        {
            try
            {
                return data[key];
            } catch (std::exception& e)
            {
                THROW(LookupException);
            }
        }

        const Value& set(const Key& key, const Value& value)
        {
            return data[key] = value;
        }

        void remove(const Key& key)
        {
            auto pos = data.find(key);

            if (pos != data.end())
            {
                data.erase(pos);
            }
        }

        bool isEntry(const Key& key) const
        {
            return data.find(key) != data.end();
        }

        typename std::unordered_map<Key, Value>::iterator begin() NO_BIND
        {
            return data.begin();
        }

        typename std::unordered_map<Key, Value>::iterator end() NO_BIND
        {
            return data.end();
        }

        typename std::unordered_map<Key, Value>::const_iterator begin() const NO_BIND
        {
            return data.begin();
        }

        typename std::unordered_map<Key, Value>::const_iterator end() const NO_BIND
        {
            return data.end();
        }

        typename std::unordered_map<Key, Value>::const_iterator find(const Key& key) const NO_BIND
        {
            return data.find(key);
        }

        typename std::unordered_map<Key, Value>::iterator find(const Key& key) NO_BIND
        {
            return data.find(key);
        }

        void removeEntry(const typename std::unordered_map<Key, Value>::iterator& it) NO_BIND
        {
            data.erase(it);
        }

        void removeEntry(const typename std::unordered_map<Key, Value>::const_iterator& it) NO_BIND
        {
            data.erase(it);
        }

        size_t getCount() const
        {
            return data.size();
        }

        const Key& getKey(size_t index) const
        {
            typename std::unordered_map<Key, Value>::const_iterator it = begin();
            for (size_t i = 0; i < index; ++i) {++it;}
            return it->first;
        }

        const Key& getValue(size_t index) const
        {
            typename std::unordered_map<Key, Value>::const_iterator it = begin();
            for (size_t i = 0; i < index; ++i) {++it;}
            return it->second;
        }

        void clear()
        {
            data.clear();
        }
    private:
        std::unordered_map<Key, Value> data;
};

BIND_CLASS(HashMap)
TEMPLATE_TYPES(HashMap:Key:Value, <Str,Str>@StrStrMap <AutoVal,AutoVal>@Map)

template <typename Key, typename Value>
class HashMapBuilder
{
    public:
        HashMapBuilder& add(const Key& key, const Value& value)
        {
            hashMap.set(key, value);

            return *this;
        }

        operator HashMap<Key, Value>() const
        {
            return hashMap;
        }

        HashMap<Key, Value> hashMap;
};

#endif // HASHMAP_H
