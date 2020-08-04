#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEINPUTINTERFACE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEINPUTINTERFACE_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/uefiinputkey.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



struct UefiSimpleInputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleInputInterface *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *readKeyStroke)(UefiSimpleInputInterface *obj, UefiInputKey *key); // TEST: NO

    uefi_event waitForKey;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEINPUTINTERFACE_H
