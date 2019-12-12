#ifndef BOOTLOADER_SRC_BITS64_OTHER_OSTYPE_H
#define BOOTLOADER_SRC_BITS64_OTHER_OSTYPE_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class OsType: u8
{
    NGOS,
    WINDOWS_10,
    UBUNTU_19,
    CENTOS_8,
    MAXIMUM
};



inline const char8* enumToString(OsType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case OsType::NGOS:       return "NGOS";
        case OsType::WINDOWS_10: return "WINDOWS_10";
        case OsType::UBUNTU_19:  return "UBUNTU_19";
        case OsType::CENTOS_8:   return "CENTOS_8";
        case OsType::MAXIMUM:    return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(OsType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // BOOTLOADER_SRC_BITS64_OTHER_OSTYPE_H
