#ifndef UEFI_UEFIDEVICEPATHTYPE_H
#define UEFI_UEFIDEVICEPATHTYPE_H



#include <ngos/types.h>



enum class UefiDevicePathType : u8
{
    HARDWARE_DEVICE_PATH  = 0x01,
    ACPI_DEVICE_PATH      = 0x02,
    MESSAGING_DEVICE_PATH = 0x03,
    MEDIA_DEVICE_PATH     = 0x04,
    BBS_DEVICE_PATH       = 0x05,
    END_DEVICE_PATH_TYPE  = 0x7F
};



#endif // UEFI_UEFIDEVICEPATHTYPE_H
