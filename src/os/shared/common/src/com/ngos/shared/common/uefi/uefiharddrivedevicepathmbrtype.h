#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiHardDriveDevicePathMbrType: u8
{
    NONE                        = 0,
    PCAT                        = 0x01,
    UEFI_PARTITION_TABLE_HEADER = 0x02
};



inline const char8* enumToString(UefiHardDriveDevicePathMbrType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiHardDriveDevicePathMbrType::NONE:                        return "NONE";
        case UefiHardDriveDevicePathMbrType::PCAT:                        return "PCAT";
        case UefiHardDriveDevicePathMbrType::UEFI_PARTITION_TABLE_HEADER: return "UEFI_PARTITION_TABLE_HEADER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiHardDriveDevicePathMbrType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H
