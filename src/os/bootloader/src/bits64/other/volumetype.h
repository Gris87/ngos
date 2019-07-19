#ifndef BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H
#define BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H



#include <ngos/types.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class VolumeType: u8
{
    NONE     = 0,
    INTERNAL = 1,
    EXTERNAL = 2,
    OPTICAL  = 3,
    NETWORK  = 4
};



inline const char* volumeTypeToString(VolumeType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case VolumeType::NONE:     return "NONE";
        case VolumeType::INTERNAL: return "INTERNAL";
        case VolumeType::EXTERNAL: return "EXTERNAL";
        case VolumeType::OPTICAL:  return "OPTICAL";
        case VolumeType::NETWORK:  return "NETWORK";

        default: return "UNKNOWN";
    }
}



#endif // BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H
