#ifndef UEFI_UEFISIMPLEINPUTINTERFACE_H
#define UEFI_UEFISIMPLEINPUTINTERFACE_H



#include <uefi/macros.h>
#include <uefi/uefiinputkey.h>
#include <uefi/uefistatus.h>



struct UefiSimpleInputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleInputInterface *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *readKeyStroke)(UefiSimpleInputInterface *obj, UefiInputKey *key); // TEST: NO

    uefi_event waitForKey;
};



#endif // UEFI_UEFISIMPLEINPUTINTERFACE_H
