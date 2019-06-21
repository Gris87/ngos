#ifndef UEFI_UEFIDEVICEPATH_H
#define UEFI_UEFIDEVICEPATH_H



#include <ngos/types.h>
#include <uefi/uefidevicepathsubtype.h>
#include <uefi/uefidevicepathtype.h>



struct UefiDevicePath
{
    UefiDevicePathType    type;
    UefiDevicePathSubType subType;
    u16                   length;
};



#endif // UEFI_UEFIDEVICEPATH_H
