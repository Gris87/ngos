#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFILOADEDIMAGEPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFILOADEDIMAGEPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefidevicepath.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>
#include <com/ngos/shared/common/uefi/uefisystemtable.h>



#define UEFI_LOADED_IMAGE_PROTOCOL_GUID \
    { 0x5B1B31A1, 0x9562, 0x11D2, { 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }



struct UefiLoadedImageProtocol
{
    bad_uint32              revision;
    uefi_handle      parentHandle;
    UefiSystemTable *systemTable;

    uefi_handle      deviceHandle;
    UefiDevicePath  *filePath;
    void            *reserved;

    bad_uint32              loadOptionsSize;
    char16          *loadOptions;

    void            *imageBase;
    bad_uint64              imageSize;
    UefiMemoryType   imageCodeType;
    UefiMemoryType   imageDataType;

    UefiStatus (UEFI_API *unload)(uefi_handle imageHandle); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFILOADEDIMAGEPROTOCOL_H
