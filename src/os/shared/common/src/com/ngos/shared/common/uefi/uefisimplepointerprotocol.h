#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefisimplepointermode.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerstate.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_SIMPLE_POINTER_PROTOCOL_GUID \
    { 0x31878C87, 0x0B75, 0x11D5, { 0x9A, 0x4F, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }



struct UefiSimplePointerProtocol
{
    UefiStatus (UEFI_API *reset)(UefiSimplePointerProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *getState)(UefiSimplePointerProtocol *obj, UefiSimplePointerState *state); // TEST: NO

    uefi_event             waitForInput;
    UefiSimplePointerMode *mode;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERPROTOCOL_H
