#ifndef UEFI_UEFIDEVICEPATHTYPE_H
#define UEFI_UEFIDEVICEPATHTYPE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiDevicePathType: u8
{
    NONE                  = 0,
    HARDWARE_DEVICE_PATH  = 0x01,
    ACPI_DEVICE_PATH      = 0x02,
    MESSAGING_DEVICE_PATH = 0x03,
    MEDIA_DEVICE_PATH     = 0x04,
    BBS_DEVICE_PATH       = 0x05,
    END_DEVICE_PATH_TYPE  = 0x7F
};



inline const char8* enumToString(UefiDevicePathType type) // TEST: NO
{
    switch (type)
    {
        case UefiDevicePathType::NONE:                  return "NONE";
        case UefiDevicePathType::HARDWARE_DEVICE_PATH:  return "HARDWARE_DEVICE_PATH";
        case UefiDevicePathType::ACPI_DEVICE_PATH:      return "ACPI_DEVICE_PATH";
        case UefiDevicePathType::MESSAGING_DEVICE_PATH: return "MESSAGING_DEVICE_PATH";
        case UefiDevicePathType::MEDIA_DEVICE_PATH:     return "MEDIA_DEVICE_PATH";
        case UefiDevicePathType::BBS_DEVICE_PATH:       return "BBS_DEVICE_PATH";
        case UefiDevicePathType::END_DEVICE_PATH_TYPE:  return "END_DEVICE_PATH_TYPE";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiDevicePathType type) // TEST: NO
{
    static char8 res[29];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // UEFI_UEFIDEVICEPATHTYPE_H
