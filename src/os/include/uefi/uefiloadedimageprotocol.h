#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFILOADEDIMAGEPROTOCOL_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFILOADEDIMAGEPROTOCOL_H



#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efidevicepath.h"
#include "src/bits64/a_uefi/uefi/lib/efimemorytype.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"
#include "src/bits64/a_uefi/uefi/lib/efisystemtable.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
    { 0x5B1B31A1, 0x9562, 0x11D2, {0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B} }



struct EfiLoadedImageProtocol
{
    u32             revision;
    EfiHandle       parentHandle;
    EfiSystemTable *systemTable;

    EfiHandle       deviceHandle;
    EfiDevicePath  *filePath;
    void           *reserved;

    u32             loadOptionsSize;
    void           *loadOptions;

    void           *imageBase;
    u64             imageSize;
    EfiMemoryType   imageCodeType;
    EfiMemoryType   imageDataType;

    EfiStatus (EFIAPI *unload)(EfiHandle imageHandle); // TEST: NO
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFILOADEDIMAGEPROTOCOL_H
