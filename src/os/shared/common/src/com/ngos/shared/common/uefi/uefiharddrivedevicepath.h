#ifndef UEFI_UEFIHARDDRIVEDEVICEPATH_H
#define UEFI_UEFIHARDDRIVEDEVICEPATH_H



#include <common/src/com/ngos/shared/common/guid/guid.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepath.h>
#include <common/src/com/ngos/shared/common/uefi/uefiharddrivedevicepathmbrtype.h>
#include <common/src/com/ngos/shared/common/uefi/uefiharddrivedevicepathsignaturetype.h>



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
