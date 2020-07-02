#ifndef UEFI_UEFICAPSULEHEADER_H
#define UEFI_UEFICAPSULEHEADER_H



#include <guid/guid.h>



struct UefiCapsuleHeader
{
    Guid capsuleGuid;
    u32  headerSize;
    u32  flags;
    u32  capsuleImageSize;
};



#endif // UEFI_UEFICAPSULEHEADER_H
