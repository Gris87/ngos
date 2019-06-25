#ifndef UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H
#define UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H



#include <ngos/types.h>



enum class UefiHardDriveDevicePathMbrType: u8
{
    NONE                       = 0x00,
    PCAT                       = 0x01,
    EFI_PARTITION_TABLE_HEADER = 0x02
};



#endif // UEFI_UEFIHARDDRIVEDEVICEPATHMBRTYPE_H
