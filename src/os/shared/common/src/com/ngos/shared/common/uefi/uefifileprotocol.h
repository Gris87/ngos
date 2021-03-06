#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPROTOCOL_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefifileattributeflags.h>
#include <com/ngos/shared/common/uefi/uefifileiotoken.h>
#include <com/ngos/shared/common/uefi/uefifilemodeflags.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



struct UefiFileProtocol
{
    u64 revision;

    UefiStatus (UEFI_API *open)(UefiFileProtocol *obj, UefiFileProtocol **newHandle, const char16 *fileName, uefi_file_mode_flags openMode, uefi_file_attribute_flags attributes); // TEST: NO
    UefiStatus (UEFI_API *close)(UefiFileProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *deleteFile)(UefiFileProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *read)(UefiFileProtocol *obj, u64 *bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiFileProtocol *obj, u64 *bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *getPosition)(UefiFileProtocol *obj, u64 *position); // TEST: NO
    UefiStatus (UEFI_API *setPosition)(UefiFileProtocol *obj, u64 position); // TEST: NO
    UefiStatus (UEFI_API *getInfo)(UefiFileProtocol *obj, Guid *informationType, u64 *bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *setInfo)(UefiFileProtocol *obj, Guid *informationType, u64 bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *flush)(UefiFileProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *openEx)(UefiFileProtocol *obj, UefiFileProtocol **newHandle, const char16 *fileName, uefi_file_mode_flags openMode, uefi_file_attribute_flags attributes, UefiFileIoToken *token); // TEST: NO
    UefiStatus (UEFI_API *readEx)(UefiFileProtocol *obj, UefiFileIoToken *token); // TEST: NO
    UefiStatus (UEFI_API *writeEx)(UefiFileProtocol *obj, UefiFileIoToken *token); // TEST: NO
    UefiStatus (UEFI_API *flushEx)(UefiFileProtocol *obj, UefiFileIoToken *token); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPROTOCOL_H
