#ifndef UEFI_UEFIFILEPATH_H
#define UEFI_UEFIFILEPATH_H



#include <ngos/types.h>
#include <uefi/types.h>
#include <uefi/uefidevicepath.h>



struct UefiFilePath
{
    UefiDevicePath header;
    char16         pathName[0];
};



#endif // UEFI_UEFIFILEPATH_H
