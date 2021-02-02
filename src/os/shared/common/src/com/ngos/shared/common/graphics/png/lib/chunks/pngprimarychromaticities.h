#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPRIMARYCHROMATICITIES_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPRIMARYCHROMATICITIES_H



#include <com/ngos/shared/common/ngos/types.h>



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
    bad_uint32 whitePointX;
    bad_uint32 whitePointY;
    bad_uint32 redX;
    bad_uint32 redY;
    bad_uint32 greenX;
    bad_uint32 greenY;
    bad_uint32 blueX;
    bad_uint32 blueY;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPRIMARYCHROMATICITIES_H
