#ifndef UEFI_UEFIHARDDRIVEDEVICEPATH_H
#define UEFI_UEFIHARDDRIVEDEVICEPATH_H



#include <guid/guid.h>
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

    union
    {
        struct
        {
            u32                          signature;
        };

        Guid                             signatureGuid;
    };

    UefiHardDriveDevicePathMbrType       mbrType;
    UefiHardDriveDevicePathSignatureType signatureType;
};



#endif // UEFI_UEFIHARDDRIVEDEVICEPATH_H
