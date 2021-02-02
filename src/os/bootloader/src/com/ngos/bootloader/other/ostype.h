#ifndef COM_NGOS_BOOTLOADER_OTHER_OSTYPE_H
#define COM_NGOS_BOOTLOADER_OTHER_OSTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



enum class OsType: bad_uint8
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

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_BOOTLOADER_OTHER_OSTYPE_H
