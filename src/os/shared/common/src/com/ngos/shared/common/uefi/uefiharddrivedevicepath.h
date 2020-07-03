#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATH_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATH_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefidevicepath.h>
#include <com/ngos/shared/common/uefi/uefiharddrivedevicepathmbrtype.h>
#include <com/ngos/shared/common/uefi/uefiharddrivedevicepathsignaturetype.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIHARDDRIVEDEVICEPATH_H
