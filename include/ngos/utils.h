#ifndef NGOS_UTILS_H
#define NGOS_UTILS_H



#include <ngos/types.h>



#define __ROUND_MASK(x, y) ((__typeof__(x))((y) - 1))           // TEST: NO
#define ROUND_UP(x, y) ((((x) - 1) | __ROUND_MASK(x, y)) + 1)   // TEST: NO
#define ROUND_DOWN(x, y) ((x) & ~__ROUND_MASK(x, y))            // TEST: NO



#define MIN(a, b) (a) < (b) ? (a) : (b)                         // TEST: NO
#define MIN_TYPED(type, a, b) MIN((type)(a), (type)(b))         // TEST: NO

#define MAX(a, b) (a) > (b) ? (a) : (b)                         // TEST: NO
#define MAX_TYPED(type, a, b) MAX((type)(a), (type)(b))         // TEST: NO



// Ignore CppAlignmentVerifier [BEGIN]
inline u16 htons(u16 value) // TEST: NO
{
    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline u16 ntohs(u16 value) // TEST: NO
{
    return ((value & 0xFF) << 8)
        | (value >> 8);
}

inline u32 htonl(u32 value) // TEST: NO
{
    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline u32 ntohl(u32 value) // TEST: NO
{
    return ((value        & 0xFF) << 24)
        | (((value >> 8)  & 0xFF) << 16)
        | (((value >> 16) & 0xFF) << 8)
        |   (value >> 24);
}

inline u64 htonll(u64 value) // TEST: NO
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

inline u64 ntohll(u64 value) // TEST: NO
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



#endif // NGOS_UTILS_H
