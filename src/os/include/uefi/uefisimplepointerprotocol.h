#ifndef UEFI_UEFISIMPLEPOINTERPROTOCOL_H
#define UEFI_UEFISIMPLEPOINTERPROTOCOL_H



#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefisimplepointermode.h>
#include <uefi/uefisimplepointerstate.h>
#include <uefi/uefistatus.h>



#define UEFI_SIMPLE_POINTER_PROTOCOL_GUID \
    { 0x31878C87, 0x0B75, 0x11D5, { 0x9A, 0x4F, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }



struct UefiSimplePointerProtocol
{
    UefiStatus (UEFI_API *reset)(UefiSimplePointerProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *getState)(UefiSimplePointerProtocol *obj, UefiSimplePointerState *state); // TEST: NO

    uefi_event             waitForInput;
    UefiSimplePointerMode *mode;
};



#endif // UEFI_UEFISIMPLEPOINTERPROTOCOL_H
