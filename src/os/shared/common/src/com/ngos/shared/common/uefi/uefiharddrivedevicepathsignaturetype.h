#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H



#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class UefiHardDriveDevicePathSignatureType: u8
{
    NONE = 0,
    MBR  = 1,
    GUID = 2
};



inline const char8* enumToString(UefiHardDriveDevicePathSignatureType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiHardDriveDevicePathSignatureType::NONE: return "NONE";
        case UefiHardDriveDevicePathSignatureType::MBR:  return "MBR";
        case UefiHardDriveDevicePathSignatureType::GUID: return "GUID";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiHardDriveDevicePathSignatureType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
