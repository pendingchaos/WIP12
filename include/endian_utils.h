#ifndef ENDIAN_UTIL_H
#define ENDIAN_UTIL_H

#include <stdint.h>

#if 1145258561 == 0x44434241
#define IS_LITTLE_ENDIAN true
#define IS_BIG_ENDIAN false
#else
#define IS_LITTLE_ENDIAN false
#define IS_BIG_ENDIAN true
#endif

inline uint16_t swapEndianU16(uint16_t integer)
{
    return ((integer & 0xFF00) >> 8) |
           ((integer & 0x00FF) << 8);
}

inline int16_t swapEndianS16(int16_t integer)
{
    return ((integer & 0xFF00) >> 8) |
           ((integer & 0x00FF) << 8);
}

inline uint32_t swapEndianU32(uint32_t integer)
{
    return ((integer & 0xFF000000) >> 24) |
           ((integer & 0x00FF0000) >> 8)  |
           ((integer & 0x0000FF00) << 8)  |
           ((integer & 0xF00000FF) << 24);
}

inline int32_t swapEndianS32(int32_t integer)
{
    return ((integer & 0xFF000000) >> 24) |
           ((integer & 0x00FF0000) >> 8)  |
           ((integer & 0x0000FF00) << 8)  |
           ((integer & 0xF00000FF) << 24);
}

inline uint64_t swapEndianU64(uint64_t integer)
{
    return ((integer & 0xFF00000000000000) >> 56) |
           ((integer & 0x00FF000000000000) >> 48) |
           ((integer & 0x0000FF0000000000) >> 40) |
           ((integer & 0x000000FF00000000) >> 32) |
           ((integer & 0x00000000FF000000) << 32) |
           ((integer & 0x0000000000FF0000) << 40) |
           ((integer & 0x000000000000FF00) << 48) |
           ((integer & 0x00000000000000FF) << 56);
}

inline int64_t swapEndianS64(int64_t integer)
{
    return ((integer & 0xFF00000000000000) >> 56) |
           ((integer & 0x00FF000000000000) >> 48) |
           ((integer & 0x0000FF0000000000) >> 40) |
           ((integer & 0x000000FF00000000) >> 32) |
           ((integer & 0x00000000FF000000) << 32) |
           ((integer & 0x0000000000FF0000) << 40) |
           ((integer & 0x000000000000FF00) << 48) |
           ((integer & 0x00000000000000FF) << 56);
}

#if IS_LITTLE_ENDIAN
#define TO_LE_U16(integer) integer
#define TO_LE_S16(integer) integer

#define TO_LE_U32(integer) integer
#define TO_LE_S32(integer) integer

#define TO_LE_U64(integer) integer
#define TO_LE_S64(integer) integer

#define TO_BE_U16(integer) swapEndianU16(integer)
#define TO_BE_S16(integer) swapEndianS16(integer)

#define TO_BE_U32(integer) swapEndianU32(integer)
#define TO_BE_S32(integer) swapEndianS32(integer)

#define TO_BE_U64(integer) swapEndianU64(integer)
#define TO_BE_S64(integer) swapEndianS64(integer)

#define FROM_LE_U16(integer) integer
#define FROM_LE_S16(integer) integer

#define FROM_LE_U32(integer) integer
#define FROM_LE_S32(integer) integer

#define FROM_LE_U64(integer) integer
#define FROM_LE_S64(integer) integer

#define FROM_BE_U16(integer) swapEndianU16(integer)
#define FROM_BE_S16(integer) swapEndianS16(integer)

#define FROM_BE_U32(integer) swapEndianU32(integer)
#define FROM_BE_S32(integer) swapEndianS32(integer)

#define FROM_BE_U64(integer) swapEndianU64(integer)
#define FROM_BE_S64(integer) swapEndianS64(integer)
#else
#define TO_LE_U16(integer) swapEndianU16(integer)
#define TO_LE_S16(integer) swapEndianS16(integer)

#define TO_LE_U32(integer) swapEndianU32(integer)
#define TO_LE_S32(integer) swapEndianS32(integer)

#define TO_LE_U64(integer) swapEndianU64(integer)
#define TO_LE_S64(integer) swapEndianS64(integer)

#define TO_BE_U16(integer) integer
#define TO_BE_S16(integer) integer

#define TO_BE_U32(integer) integer
#define TO_BE_S32(integer) integer

#define TO_BE_U64(integer) integer
#define TO_BE_S64(integer) integer

#define FROM_LE_U16(integer) swapEndianU16(integer)
#define FROM_LE_S16(integer) swapEndianS16(integer)

#define FROM_LE_U32(integer) swapEndianU32(integer)
#define FROM_LE_S32(integer) swapEndianS32(integer)

#define FROM_LE_U64(integer) swapEndianU64(integer)
#define FROM_LE_S64(integer) swapEndianS64(integer)

#define FROM_BE_U16(integer) integer
#define FROM_BE_S16(integer) integer

#define FROM_BE_U32(integer) integer
#define FROM_BE_S32(integer) integer

#define FROM_BE_U64(integer) integer
#define FROM_BE_S64(integer) integer
#endif

#endif // ENDIAN_UTIL_H
