#ifndef COM_NGOS_SHARED_COMMON_NGOS_UTILS_H
#define COM_NGOS_SHARED_COMMON_NGOS_UTILS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>



#define __ROUND_MASK(x, y) ((__typeof__(x))((y) - 1))
#define ROUND_UP(x, y) ((((x) - 1) | __ROUND_MASK(x, y)) + 1)
#define ROUND_DOWN(x, y) ((x) & ~__ROUND_MASK(x, y))

#define ALIGN_2(a)    ROUND_UP(a, 2)
#define ALIGN_4(a)    ROUND_UP(a, 4)
#define ALIGN_8(a)    ROUND_UP(a, 8)
#define ALIGN_16(a)   ROUND_UP(a, 16)
#define ALIGN_32(a)   ROUND_UP(a, 32)
#define ALIGN_64(a)   ROUND_UP(a, 64)
#define ALIGN_128(a)  ROUND_UP(a, 128)
#define ALIGN_256(a)  ROUND_UP(a, 256)
#define ALIGN_512(a)  ROUND_UP(a, 512)
#define ALIGN_1024(a) ROUND_UP(a, 1024)
#define ALIGN_2048(a) ROUND_UP(a, 2048)
#define ALIGN_4096(a) ROUND_UP(a, 4096)

#define IS_ALIGNED(a, b) (((u64)(a) & ((u64)(b) - 1)) == 0)
#define IS_POWER_OF_2(a) IS_ALIGNED(a, a)



#define DIV_UP(x, y) (((x) + (y) - 1) / (y))



#define WORD_BIT(wordId, bitId) (((u64)(wordId) * 32) + (bitId))



#define OFFSET_OF(type, field) ((u64)&(((type *)nullptr)->field))



#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MIN_TYPED(type, a, b) MIN((type)(a), (type)(b))

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MAX_TYPED(type, a, b) MAX((type)(a), (type)(b))

#define ABS(a) ((a) >= 0 ? (a) : -(a)) // Ignore CppOperatorSpacesVerifier

#define CLAMP(a, minValue, maxValue) MIN(MAX(a, minValue), maxValue)

#define IS_IN_RANGE(a, minValue, maxValue) ((a) >= (minValue) && (a) <= (maxValue))



// Ignore CppAlignmentVerifier [BEGIN]
inline u16 htons(u16 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline u16 ntohs(u16 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline u32 htonl(u32 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline u32 ntohl(u32 value)
{
    COMMON_LT((" | value = %u", value));



    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline u64 htonll(u64 value)
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

inline u64 ntohll(u64 value)
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

inline u8 clamp(u8 value, u8 minValue, u8 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline u16 clamp(u16 value, u16 minValue, u16 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline u32 clamp(u32 value, u32 minValue, u32 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline u64 clamp(u64 value, u64 minValue, u64 maxValue)
{
    COMMON_LT((" | value = %u, minValue = %u, maxValue = %u", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i8 clamp(i8 value, i8 minValue, i8 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i16 clamp(i16 value, i16 minValue, i16 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i32 clamp(i32 value, i32 minValue, i32 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i64 clamp(i64 value, i64 minValue, i64 maxValue)
{
    COMMON_LT((" | value = %d, minValue = %d, maxValue = %d", value, minValue, maxValue));

    COMMON_ASSERT(minValue <= maxValue, "minValue is invalid", value);



    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}



#endif // COM_NGOS_SHARED_COMMON_NGOS_UTILS_H
