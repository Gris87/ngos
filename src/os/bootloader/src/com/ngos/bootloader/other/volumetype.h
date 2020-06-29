#ifndef BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_VOLUMETYPE_H
#define BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_VOLUMETYPE_H



#include <common/src/bits64/printf/printf.h>
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



inline const char8* enumToString(VolumeType type) // TEST: NO
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



inline const char8* enumToFullString(VolumeType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_VOLUMETYPE_H
