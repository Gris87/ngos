#ifndef UEFI_UEFIDEVICEPATH_H
#define UEFI_UEFIDEVICEPATH_H



#include <ngos/types.h>
#include <uefi/uefidevicepathsubtype.h>
#include <uefi/uefidevicepathtype.h>



#define UEFI_DEVICE_PATH_PROTOCOL_GUID \
    { 0x9576E91, 0x6D3F, 0x11D2, {0x8E, 0x39, 0x0, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }



struct UefiDevicePath
{
    UefiDevicePathType    type;
    UefiDevicePathSubType subType;
    u16                   length;
};



#endif // UEFI_UEFIDEVICEPATH_H
