#ifndef COM_NGOS_SHARED_COMMON_NGOS_UTILS_H
#define COM_NGOS_SHARED_COMMON_NGOS_UTILS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>



#define __ROUND_MASK(x, y) ((__typeof__(x))((y) - 1))
#define ROUND_UP(x, y) ((((x) - 1) | __ROUND_MASK(x, y)) + 1)
#define ROUND_DOWN(x, y) ((x) & ~__ROUND_MASK(x, y))



#define DIV_UP(x, y) (((x) + (y) - 1) / (y))



#define WORD_BIT(wordId, bitId) (((bad_uint64)(wordId) * 32) + (bitId))



#define OFFSET_OF(type, field) ((bad_uint64)&(((type *)nullptr)->field))



#define IS_ALIGNED(a, b) (((bad_uint64)(a) & ((bad_uint64)(b) - 1)) == 0)
#define IS_POWER_OF_2(a) IS_ALIGNED(a, a)



#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MIN_TYPED(type, a, b) MIN((type)(a), (type)(b))

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MAX_TYPED(type, a, b) MAX((type)(a), (type)(b))

#define ABS(a) ((a) >= 0 ? (a) : -(a)) // Ignore CppOperatorSpacesVerifier

#define CLAMP(a, minValue, maxValue) MIN(MAX(a, minValue), maxValue)



// Ignore CppAlignmentVerifier [BEGIN]
inline bad_uint16 htons(bad_uint16 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline bad_uint16 ntohs(bad_uint16 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline bad_uint32 htonl(bad_uint32 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline bad_uint32 ntohl(bad_uint32 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline bad_uint64 htonll(bad_uint64 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value        & 0xFF) << 56)
        | (((value >> 8)  & 0xFF) << 48)
        | (((value >> 16) & 0xFF) << 40)
        | (((value >> 24) & 0xFF) << 32)
        | (((value >> 32) & 0xFF) << 24)
        | (((value >> 40) & 0xFF) << 16)
        | (((value >> 48) & 0xFF) << 8)
        |   (value >> 56);
}

inline bad_uint64 ntohll(bad_uint64 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value        & 0xFF) << 56)
        | (((value >> 8)  & 0xFF) << 48)
        | (((value >> 16) & 0xFF) << 40)
        | (((value >> 24) & 0xFF) << 32)
        | (((value >> 32) & 0xFF) << 24)
        | (((value >> 40) & 0xFF) << 16)
        | (((value >> 48) & 0xFF) << 8)
        |   (value >> 56);
}
// Ignore CppAlignmentVerifier [END]

inline bad_uint8 clamp(bad_uint8 value, bad_uint8 minValue, bad_uint8 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_uint16 clamp(bad_uint16 value, bad_uint16 minValue, bad_uint16 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_uint32 clamp(bad_uint32 value, bad_uint32 minValue, bad_uint32 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_uint64 clamp(bad_uint64 value, bad_uint64 minValue, bad_uint64 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_int8 clamp(bad_int8 value, bad_int8 minValue, bad_int8 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_int16 clamp(bad_int16 value, bad_int16 minValue, bad_int16 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_int32 clamp(bad_int32 value, bad_int32 minValue, bad_int32 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline bad_int64 clamp(bad_int64 value, bad_int64 minValue, bad_int64 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}



#endif // COM_NGOS_SHARED_COMMON_NGOS_UTILS_H
