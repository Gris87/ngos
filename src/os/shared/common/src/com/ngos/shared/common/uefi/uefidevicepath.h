#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATH_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATH_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefidevicepathsubtype.h>
#include <com/ngos/shared/common/uefi/uefidevicepathtype.h>



#define UEFI_DEVICE_PATH_PROTOCOL_GUID \
    { 0x09576E91, 0x6D3F, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }



struct UefiDevicePath
{
    UefiDevicePathType    type;
    UefiDevicePathSubType subType;
    bad_uint16                   length;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIDEVICEPATH_H
