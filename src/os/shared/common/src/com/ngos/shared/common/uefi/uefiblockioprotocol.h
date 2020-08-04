#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/uefiblockiomedia.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_BLOCK_IO_PROTOCOL_GUID \
    { 0x964E5B21, 0x6459, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }



struct UefiBlockIoProtocol
{
    u64               revision;
    UefiBlockIoMedia *media;

    UefiStatus (UEFI_API *reset)(UefiBlockIoProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *readBlocks)(UefiBlockIoProtocol *obj, u32 mediaId, uefi_lba lba, u64 bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *writeBlocks)(UefiBlockIoProtocol *obj, u32 mediaId, uefi_lba lba, u64 bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *flushBlocks)(UefiBlockIoProtocol *obj); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOPROTOCOL_H
