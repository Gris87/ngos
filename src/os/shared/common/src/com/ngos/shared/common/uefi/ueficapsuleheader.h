#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFICAPSULEHEADER_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFICAPSULEHEADER_H



#include <com/ngos/shared/common/guid/guid.h>



struct UefiCapsuleHeader
{
    Guid capsuleGuid;
    bad_uint32  headerSize;
    bad_uint32  flags;
    bad_uint32  capsuleImageSize;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFICAPSULEHEADER_H
