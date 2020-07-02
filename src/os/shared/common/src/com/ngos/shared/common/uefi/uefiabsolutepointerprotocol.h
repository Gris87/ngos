#ifndef UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H
#define UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H



#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefiabsolutepointermode.h>
#include <uefi/uefiabsolutepointerstate.h>
#include <uefi/uefistatus.h>



#define UEFI_ABSOLUTE_POINTER_PROTOCOL_GUID \
    { 0x8D59D32B, 0xC655, 0x4AE9, { 0x9B, 0x15, 0xF2, 0x59, 0x04, 0x99, 0x2A, 0x43 } }



struct UefiAbsolutePointerProtocol
{
    UefiStatus (UEFI_API *reset)(UefiAbsolutePointerProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *getState)(UefiAbsolutePointerProtocol *obj, UefiAbsolutePointerState *state); // TEST: NO

    uefi_event               waitForInput;
    UefiAbsolutePointerMode *mode;
};



#endif // UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H
