#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEGAMMA_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEGAMMA_H



#include <com/ngos/shared/common/ngos/types.h>



#define PNG_DEFAULT_IMAGE_GAMMA 45455



struct PngImageGamma
{
    bad_uint32 gamma;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEGAMMA_H
