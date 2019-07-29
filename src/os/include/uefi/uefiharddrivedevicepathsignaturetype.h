#ifndef UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
#define UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H



#include <ngos/types.h>



enum class UefiHardDriveDevicePathSignatureType: u8
{
    NONE = 0,
    MBR  = 1,
    GUID = 2
};



inline const char8* uefiHardDriveDevicePathSignatureTypeToString(UefiHardDriveDevicePathSignatureType type) // TEST: NO
{
    switch (type)
    {
        case UefiHardDriveDevicePathSignatureType::NONE: return "NONE";
        case UefiHardDriveDevicePathSignatureType::MBR:  return "MBR";
        case UefiHardDriveDevicePathSignatureType::GUID: return "GUID";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIHARDDRIVEDEVICEPATHSIGNATURETYPE_H
