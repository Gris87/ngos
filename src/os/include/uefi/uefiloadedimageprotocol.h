#ifndef UEFI_UEFILOADEDIMAGEPROTOCOL_H
#define UEFI_UEFILOADEDIMAGEPROTOCOL_H



#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefimemorytype.h>
#include <uefi/uefistatus.h>
#include <uefi/uefisystemtable.h>



#define UEFI_LOADED_IMAGE_PROTOCOL_GUID \
    { 0x5B1B31A1, 0x9562, 0x11D2, {0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B} }



struct UefiLoadedImageProtocol
{
    u32              revision;
    uefi_handle      parentHandle;
    UefiSystemTable *systemTable;

    uefi_handle      deviceHandle;
    UefiDevicePath  *filePath;
    void            *reserved;

    u32              loadOptionsSize;
    char16          *loadOptions;

    void            *imageBase;
    u64              imageSize;
    UefiMemoryType   imageCodeType;
    UefiMemoryType   imageDataType;

    UefiStatus (UEFI_API *unload)(uefi_handle imageHandle); // TEST: NO
};



#endif // UEFI_UEFILOADEDIMAGEPROTOCOL_H
