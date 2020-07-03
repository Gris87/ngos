#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEINPUTINTERFACE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEINPUTINTERFACE_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinputkey.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiSimpleInputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleInputInterface *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *readKeyStroke)(UefiSimpleInputInterface *obj, UefiInputKey *key); // TEST: NO

    uefi_event waitForKey;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEINPUTINTERFACE_H
