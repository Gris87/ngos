#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLEINPUTINTERFACE_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLEINPUTINTERFACE_H



#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efiinputkey.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"



struct EfiSimpleInputInterface
{
    EfiStatus (EFIAPI *reset)(EfiSimpleInputInterface *obj, bool extendedVerification); // TEST: NO
    EfiStatus (EFIAPI *readKeyStroke)(EfiSimpleInputInterface *obj, EfiInputKey *key); // TEST: NO

    EfiEvent waitForKey;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLEINPUTINTERFACE_H
