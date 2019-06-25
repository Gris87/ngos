#ifndef BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H
#define BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H



#include <ngos/types.h>



enum class VolumeType: u8
{
    INTERNAL,
    EXTERNAL,
    OPTICAL,
    NETWORK
};



inline const char* volumeTypeToString(VolumeType type) // TEST: NO
{
    switch (type)
    {
        case VolumeType::INTERNAL: return "INTERNAL";
        case VolumeType::EXTERNAL: return "EXTERNAL";
        case VolumeType::OPTICAL:  return "OPTICAL";
        case VolumeType::NETWORK:  return "NETWORK";

        default: return "UNKNOWN";
    }
}



#endif // BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H
