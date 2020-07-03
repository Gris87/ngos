#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPRIMARYCHROMATICITIES_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPRIMARYCHROMATICITIES_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



#define PNG_DEFAULT_WHITE_POINT_X 31270
#define PNG_DEFAULT_WHITE_POINT_Y 32900
#define PNG_DEFAULT_RED_X         64000
#define PNG_DEFAULT_RED_Y         33000
#define PNG_DEFAULT_GREEN_X       30000
#define PNG_DEFAULT_GREEN_Y       60000
#define PNG_DEFAULT_BLUE_X        15000
#define PNG_DEFAULT_BLUE_Y        6000



struct PngPrimaryChromaticities
{
    u32 whitePointX;
    u32 whitePointY;
    u32 redX;
    u32 redY;
    u32 greenX;
    u32 greenY;
    u32 blueX;
    u32 blueY;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPRIMARYCHROMATICITIES_H
