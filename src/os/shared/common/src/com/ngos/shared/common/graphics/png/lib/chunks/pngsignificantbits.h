#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PngSignificantBits
{
    u8 redBits;
    u8 greenBits;
    u8 blueBits;
    u8 alphaBits;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGSIGNIFICANTBITS_H
