#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEGAMMA_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEGAMMA_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



#define PNG_DEFAULT_IMAGE_GAMMA 45455



struct PngImageGamma
{
    u32 gamma;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEGAMMA_H
