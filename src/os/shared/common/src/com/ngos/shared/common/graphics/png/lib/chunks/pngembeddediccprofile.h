#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGEMBEDDEDICCPROFILE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGEMBEDDEDICCPROFILE_H



#include <com/ngos/shared/common/ngos/types.h>



struct PngEmbeddedIccProfile
{
    char8 profileName[80];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGEMBEDDEDICCPROFILE_H
