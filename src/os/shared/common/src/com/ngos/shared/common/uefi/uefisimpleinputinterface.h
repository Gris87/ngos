#ifndef UEFI_UEFISIMPLEINPUTINTERFACE_H
#define UEFI_UEFISIMPLEINPUTINTERFACE_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinputkey.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiSimpleInputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleInputInterface *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *readKeyStroke)(UefiSimpleInputInterface *obj, UefiInputKey *key); // TEST: NO

    uefi_event waitForKey;
};



#endif // UEFI_UEFISIMPLEINPUTINTERFACE_H
