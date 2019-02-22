#ifndef UEFI_UEFICAPSULEHEADER_H
#define UEFI_UEFICAPSULEHEADER_H



#include <uefi/uefiguid.h>



struct UefiCapsuleHeader
{
    UefiGuid capsuleGuid;
    u32      headerSize;
    u32      flags;
    u32      capsuleImageSize;
};



#endif // UEFI_UEFICAPSULEHEADER_H
