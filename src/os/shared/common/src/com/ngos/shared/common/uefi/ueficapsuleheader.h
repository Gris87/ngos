#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICAPSULEHEADER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICAPSULEHEADER_H



#include <common/src/com/ngos/shared/common/guid/guid.h>



struct UefiCapsuleHeader
{
    Guid capsuleGuid;
    u32  headerSize;
    u32  flags;
    u32  capsuleImageSize;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICAPSULEHEADER_H
