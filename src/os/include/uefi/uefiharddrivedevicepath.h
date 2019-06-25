#ifndef UEFI_UEFIHARDDRIVEDEVICEPATH_H
#define UEFI_UEFIHARDDRIVEDEVICEPATH_H



#include <ngos/types.h>
#include <uefi/types.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefiharddrivedevicepathmbrtype.h>
#include <uefi/uefiharddrivedevicepathsignaturetype.h>



struct UefiHardDriveDevicePath
{
    UefiDevicePath                       header;
    u32                                  partitionNumber;
    u64                                  partitionStart;
    u64                                  partitionSize;
    u8                                   signature[16];
    UefiHardDriveDevicePathMbrType       mbrType;
    UefiHardDriveDevicePathSignatureType signatureType;
};



#endif // UEFI_UEFIHARDDRIVEDEVICEPATH_H
