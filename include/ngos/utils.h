#ifndef NGOS_UTILS_H
#define NGOS_UTILS_H



#include <ngos/types.h>



#define __ROUND_MASK(x, y) ((__typeof__(x))((y) - 1))                   
#define ROUND_UP(x, y) ((((x) - 1) | __ROUND_MASK(x, y)) + 1)           
#define ROUND_DOWN(x, y) ((x) & ~__ROUND_MASK(x, y))                    



#define DIV_UP(x, y) (((x) + (y) - 1) / (y))                            



#define WORD_BIT(wordId, bitId) ((wordId << 5) + bitId)                  // "<< 5" == "* 32"



#define IS_POWER_OF_2(a) (!((a) & ((a) - 1)))                           



#define MIN(a, b) (a) < (b) ? (a) : (b)                                 
#define MIN_TYPED(type, a, b) MIN((type)(a), (type)(b))                 

#define MAX(a, b) (a) > (b) ? (a) : (b)                                 
#define MAX_TYPED(type, a, b) MAX((type)(a), (type)(b))                 

#define ABS(a) ((a) >= 0 ? (a) : -(a))                                   // Ignore CppOperatorSpacesVerifier

#define CLAMP(a, minValue, maxValue) MIN(MAX(a, minValue), maxValue)    



// Ignore CppAlignmentVerifier [BEGIN]
inline u16 htons(u16 value) 
{
    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline u16 ntohs(u16 value) 
{
    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline u32 htonl(u32 value) 
{
    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline u32 ntohl(u32 value) 
{
    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline u64 htonll(u64 value) 
{
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
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline u16 clamp(u16 value, u16 minValue, u16 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline u32 clamp(u32 value, u32 minValue, u32 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline u64 clamp(u64 value, u64 minValue, u64 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i8 clamp(i8 value, i8 minValue, i8 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i16 clamp(i16 value, i16 minValue, i16 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i32 clamp(i32 value, i32 minValue, i32 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

inline i64 clamp(i64 value, i64 minValue, i64 maxValue) 
{
    return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}



#endif // NGOS_UTILS_H
