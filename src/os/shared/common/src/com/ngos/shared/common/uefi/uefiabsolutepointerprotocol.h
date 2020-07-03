#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointermode.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerstate.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_ABSOLUTE_POINTER_PROTOCOL_GUID \
    { 0x8D59D32B, 0xC655, 0x4AE9, { 0x9B, 0x15, 0xF2, 0x59, 0x04, 0x99, 0x2A, 0x43 } }



struct UefiAbsolutePointerProtocol
{
    UefiStatus (UEFI_API *reset)(UefiAbsolutePointerProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *getState)(UefiAbsolutePointerProtocol *obj, UefiAbsolutePointerState *state); // TEST: NO

    uefi_event               waitForInput;
    UefiAbsolutePointerMode *mode;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERPROTOCOL_H
