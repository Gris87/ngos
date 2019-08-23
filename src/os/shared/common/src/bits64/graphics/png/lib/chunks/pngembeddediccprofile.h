#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGEMBEDDEDICCPROFILE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGEMBEDDEDICCPROFILE_H



#include <common/src/bits64/graphics/png/lib/pngcompressionmethod.h>
#include <ngos/types.h>



struct PngEmbeddedIccProfile
{
    char8 profileName[80];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGEMBEDDEDICCPROFILE_H
