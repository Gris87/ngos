#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointermode.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerstate.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_ABSOLUTE_POINTER_PROTOCOL_GUID \
    { 0x8D59D32B, 0xC655, 0x4AE9, { 0x9B, 0x15, 0xF2, 0x59, 0x04, 0x99, 0x2A, 0x43 } }



struct UefiAbsolutePointerProtocol
{
    UefiStatus (UEFI_API *reset)(UefiAbsolutePointerProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *getState)(UefiAbsolutePointerProtocol *obj, UefiAbsolutePointerState *state); // TEST: NO

    uefi_event               waitForInput;
    UefiAbsolutePointerMode *mode;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H
