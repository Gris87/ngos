#ifndef UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H
#define UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H



#include <ngos/types.h>



enum class UefiHardDriveDevicePathMbrType: u8
{
    NONE                        = 0,
    PCAT                        = 0x01,
    UEFI_PARTITION_TABLE_HEADER = 0x02
};



inline const char8* uefiHardDriveDevicePathMbrTypeToString(UefiHardDriveDevicePathMbrType type) // TEST: NO
{
    switch (type)
    {
        case UefiHardDriveDevicePathMbrType::NONE:                        return "NONE";
        case UefiHardDriveDevicePathMbrType::PCAT:                        return "PCAT";
        case UefiHardDriveDevicePathMbrType::UEFI_PARTITION_TABLE_HEADER: return "UEFI_PARTITION_TABLE_HEADER";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H
