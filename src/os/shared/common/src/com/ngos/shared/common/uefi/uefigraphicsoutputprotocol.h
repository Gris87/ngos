#ifndef UEFI_UEFIGRAPHICSOUTPUTPROTOCOL_H
#define UEFI_UEFIGRAPHICSOUTPUTPROTOCOL_H



#include <uefi/macros.h>
#include <uefi/uefigraphicsoutputbltoperation.h>
#include <uefi/uefigraphicsoutputbltpixel.h>
#include <uefi/uefigraphicsoutputmodeinformation.h>
#include <uefi/uefigraphicsoutputprotocolmode.h>
#include <uefi/uefistatus.h>



#define UEFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
    { 0x9042A9DE, 0x23DC, 0x4A38, { 0x96, 0xFB, 0x7A, 0xDE, 0xD0, 0x80, 0x51, 0x6A } }



struct UefiGraphicsOutputProtocol
{
    UefiStatus (UEFI_API *queryMode)(UefiGraphicsOutputProtocol *obj, u32 modeNumber, u64 *sizeOfInfo, UefiGraphicsOutputModeInformation **info); // TEST: NO
    UefiStatus (UEFI_API *setMode)(UefiGraphicsOutputProtocol *obj, u32 modeNumber); // TEST: NO
    UefiStatus (UEFI_API *blt)(UefiGraphicsOutputProtocol *obj, UefiGraphicsOutputBltPixel *bltBuffer, UefiGraphicsOutputBltOperation bltOperation, u64 sourceX, u64 sourceY, u64 destinationX, u64 destinationY, u64 width, u64 height, u64 delta); // TEST: NO

    UefiGraphicsOutputProtocolMode *mode;
};



#endif // UEFI_UEFIGRAPHICSOUTPUTPROTOCOL_H
