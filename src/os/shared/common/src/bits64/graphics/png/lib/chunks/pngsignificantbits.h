#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H



#include <ngos/types.h>



struct PngSignificantBits
{
    u8 redBits;
    u8 greenBits;
    u8 blueBits;
    u8 alphaBits;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H