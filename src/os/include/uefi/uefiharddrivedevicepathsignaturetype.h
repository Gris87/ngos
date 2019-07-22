#ifndef UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
#define UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H



#include <ngos/types.h>



enum class UefiHardDriveDevicePathSignatureType: u8
{
    NO_DISK_SIGNATURE = 0x00,
    MBR               = 0x01,
    GUID              = 0x02
};



inline const char* uefiHardDriveDevicePathSignatureTypeToString(UefiHardDriveDevicePathSignatureType type) // TEST: NO
{
    switch (type)
    {
        case UefiHardDriveDevicePathSignatureType::NO_DISK_SIGNATURE: return "NO_DISK_SIGNATURE";
        case UefiHardDriveDevicePathSignatureType::MBR:               return "MBR";
        case UefiHardDriveDevicePathSignatureType::GUID:              return "GUID";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
