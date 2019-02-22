#ifndef UEFI_UEFIDEVICEPATH_H
#define UEFI_UEFIDEVICEPATH_H



#include <ngos/types.h>



struct UefiDevicePath
{
    u8 type;
    u8 subType;
    u8 length[2];
};



#endif // UEFI_UEFIDEVICEPATH_H
