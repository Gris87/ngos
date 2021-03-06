#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEFILESYSTEMPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEFILESYSTEMPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefifileprotocol.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID \
    { 0x964E5B22, 0x6459, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }



struct UefiSimpleFileSystemProtocol
{
    u64 revision;

    UefiStatus (UEFI_API *openVolume)(UefiSimpleFileSystemProtocol *obj, UefiFileProtocol **root); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEFILESYSTEMPROTOCOL_H
