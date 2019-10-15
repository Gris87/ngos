#ifndef BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H
#define BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H



#include <ngos/types.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class VolumeType: u8
{
    INTERNAL,
    EXTERNAL,
    OPTICAL,
    NETWORK,
    MAXIMUM
};



inline const char8* volumeTypeToString(VolumeType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case VolumeType::INTERNAL: return "INTERNAL";
        case VolumeType::EXTERNAL: return "EXTERNAL";
        case VolumeType::OPTICAL:  return "OPTICAL";
        case VolumeType::NETWORK:  return "NETWORK";
        case VolumeType::MAXIMUM:  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // BOOTLOADER_SRC_BITS64_OTHER_VOLUMETYPE_H
