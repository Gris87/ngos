#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTPROTOCOL_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTPROTOCOL_H



#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efigraphicsoutputbltoperation.h"
#include "src/bits64/a_uefi/uefi/lib/efigraphicsoutputbltpixel.h"
#include "src/bits64/a_uefi/uefi/lib/efigraphicsoutputmodeinformation.h"
#include "src/bits64/a_uefi/uefi/lib/efigraphicsoutputprotocolmode.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"



#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
    { 0x9042A9DE, 0x23DC, 0x4A38, {0x96, 0xFB, 0x7A, 0xDE, 0xD0, 0x80, 0x51, 0x6A} }



struct EfiGraphicsOutputProtocol
{
    EfiStatus (EFIAPI *queryMode)(EfiGraphicsOutputProtocol *obj, u32 modeNumber, u64 *sizeOfInfo, EfiGraphicsOutputModeInformation **info); // TEST: NO
    EfiStatus (EFIAPI *setMode)(EfiGraphicsOutputProtocol *obj, u32 modeNumber); // TEST: NO
    EfiStatus (EFIAPI *blt)(EfiGraphicsOutputProtocol *obj, EfiGraphicsOutputBltPixel *bltBuffer, EfiGraphicsOutputBltOperation bltOperation, u64 sourceX, u64 sourceY, u64 destinationX, u64 destinationY, u64 width, u64 height, u64 delta); // TEST: NO

    EfiGraphicsOutputProtocolMode *mode;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTPROTOCOL_H
