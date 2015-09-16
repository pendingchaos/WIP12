#ifndef HASHMAP_H
#define HASHMAP_H

#include "containers/list.h"
#include "error.h"
#include "scripting/bindings.h"

#include <stddef.h>
#include <stdint.h>

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

//TODO: This could be improved (performance-wise).
template <typename Key,
          typename Value>
class HashMap
{
    public:
        bool operator == (const HashMap<Key,
                                        Value>& other) const
        {
            if (entries.getCount() != other.getEntryCount())
            {
                return false;
            }

            for (auto entry : entries)
            {
                int otherIndex = other.findEntry(entry.key);

                if (otherIndex == -1)
                {
                    return false;
                }

                if (not (entry.value == other.entries[otherIndex].value))
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

        inline size_t getEntryCount() const
        {
            return entries.getCount();
        }

        /**
         *Returns -1 if it can not be found.
         */
        inline int findEntry(const Key& key) const
        {
            return _findEntry(getHash(key), key);
        }

        inline const Key& getKey(size_t entry) const
        {
            return entries[entry].key;
        }

        inline Key& getKey(size_t entry)
        {
            return entries[entry].key;
        }

        inline const Value& getValue(size_t entry) const
        {
            return entries[entry].value;
        }

        inline Value& getValue(size_t entry)
        {
            return entries[entry].value;
        }

        inline size_t getKeyHash(size_t entry) const
        {
            return entries[entry].keyHash;
        }

        Value& get(const Key& key)
        {
            int index = findEntry(key);

            if (index == -1)
            {
                THROW(LookupException);
            }

            return entries[index].value;
        }

        const Value& get(const Key& key) const
        {
            int index = findEntry(key);

            if (index == -1)
            {
                THROW(LookupException);
            }

            return entries[index].value;
        }

        Value& set(const Key& key, const Value& value)
        {
            return _set(getHash(key), key, value);
        }

        void removeEntry(int entry)
        {
            if (entry == -1)
            {
                THROW(LookupException);
            }

            entries.remove(entry);
        }

        void remove(const Key& key)
        {
            int index = findEntry(key);

            removeEntry(index);
        }

        void clear()
        {
            entries.clear();
        }

        void append(const HashMap<Key, Value>& other)
        {
            for (auto entry : other.entries)
            {
                _set(entry.keyHash, entry.key, entry.value);
            }
        }
    private:
        int _findEntry(size_t hash, const Key& key) const
        {
            for (size_t i = 0; i < entries.getCount(); ++i)
            {
                if (entries[i].keyHash == hash)
                {
                    if (entries[i].key == key)
                    {
                        return i;
                    }
                }
            }

            return -1;
        }

        Value& _set(size_t hash, const Key& key, const Value& value)
        {
            int index = _findEntry(hash, key);

            if (index == -1)
            {
                Entry entry;
                entry.key = key;
                entry.keyHash = hash;
                entry.value = value;

                entries.append(entry);

                return entries[entries.getCount()-1].value;
            } else
            {
                entries[index].value = value;

                return entries[index].value;
            }
        }

        struct Entry
        {
            Key key;
            size_t keyHash;
            Value value;

            bool operator == (const Entry& other) const
            {
                if (keyHash == other.keyHash)
                {
                    return key == other.key and value == other.value;
                }

                return false;
            }
        };

        List<Entry> entries;
};

BIND_CLASS(HashMap)
TEMPLATE_TYPES(HashMap:Key:Value, <String,String>@StrStrMap <scripting::Value*,scripting::Value*>@Map)

template <typename Key, typename Value>
class HashMapBuilder
{
    public:
        HashMapBuilder& add(const Key& key, const Value& value)
        {
            hashMap.set(key, value);

            return *this;
        }

        inline operator HashMap<Key, Value>() const
        {
            return hashMap;
        }

        HashMap<Key, Value> hashMap;
};

#endif // HASHMAP_H
