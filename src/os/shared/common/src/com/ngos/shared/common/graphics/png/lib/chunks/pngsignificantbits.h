#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PngSignificantBits
{
    bad_uint8 redBits;
    bad_uint8 greenBits;
    bad_uint8 blueBits;
    bad_uint8 alphaBits;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H
