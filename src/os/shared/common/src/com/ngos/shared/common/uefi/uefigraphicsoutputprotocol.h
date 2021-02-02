#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputbltoperation.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputbltpixel.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocolmode.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
    { 0x9042A9DE, 0x23DC, 0x4A38, { 0x96, 0xFB, 0x7A, 0xDE, 0xD0, 0x80, 0x51, 0x6A } }



struct UefiGraphicsOutputProtocol
{
    UefiStatus (UEFI_API *queryMode)(UefiGraphicsOutputProtocol *obj, bad_uint32 modeNumber, bad_uint64 *sizeOfInfo, UefiGraphicsOutputModeInformation **info); // TEST: NO
    UefiStatus (UEFI_API *setMode)(UefiGraphicsOutputProtocol *obj, bad_uint32 modeNumber); // TEST: NO
    UefiStatus (UEFI_API *blt)(UefiGraphicsOutputProtocol *obj, UefiGraphicsOutputBltPixel *bltBuffer, UefiGraphicsOutputBltOperation bltOperation, bad_uint64 sourceX, bad_uint64 sourceY, bad_uint64 destinationX, bad_uint64 destinationY, bad_uint64 width, bad_uint64 height, bad_uint64 delta); // TEST: NO

    UefiGraphicsOutputProtocolMode *mode;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOL_H
