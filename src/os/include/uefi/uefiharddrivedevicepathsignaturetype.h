#ifndef UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
#define UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H



#include <ngos/types.h>



enum class UefiHardDriveDevicePathSignatureType: u8
{
    NO_DISK_SIGNATURE = 0x00,
    MBR               = 0x01,
    GUID              = 0x02
};



#endif // UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
