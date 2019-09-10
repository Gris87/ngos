#ifndef BOOTLOADER_SRC_BITS64_OTHER_OSTYPE_H
#define BOOTLOADER_SRC_BITS64_OTHER_OSTYPE_H



#include <ngos/types.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class OsType: u8
{
    NONE       = 0,
    NGOS       = 1,
    WINDOWS_10 = 2,
    UBUNTU_19  = 3
};



inline const char8* osTypeToString(OsType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case OsType::NONE:       return "NONE";
        case OsType::NGOS:       return "NGOS";
        case OsType::WINDOWS_10: return "WINDOWS_10";
        case OsType::UBUNTU_19:  return "UBUNTU_19";

        default: return "UNKNOWN";
    }
}



#endif // BOOTLOADER_SRC_BITS64_OTHER_OSTYPE_H
