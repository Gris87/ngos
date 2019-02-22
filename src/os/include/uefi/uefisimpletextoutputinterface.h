#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLETEXTOUTPUTINTERFACE_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLETEXTOUTPUTINTERFACE_H



#include <ngos/types.h>

#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efisimpletextoutputmode.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiSimpleTextOutputInterface
{
    EfiStatus (EFIAPI *reset)(EfiSimpleTextOutputInterface *obj, bool extendedVerification); // TEST: NO

    EfiStatus (EFIAPI *outputString)(EfiSimpleTextOutputInterface *obj, efi_char16 *string); // TEST: NO
    EfiStatus (EFIAPI *testString)(EfiSimpleTextOutputInterface *obj, efi_char16 *string); // TEST: NO

    EfiStatus (EFIAPI *queryMode)(EfiSimpleTextOutputInterface *obj, u64 modeNumber, u64 *columns, u64 *rows); // TEST: NO
    EfiStatus (EFIAPI *setMode)(EfiSimpleTextOutputInterface *obj, u64 modeNumber); // TEST: NO
    EfiStatus (EFIAPI *setAttribute)(EfiSimpleTextOutputInterface *obj, u64 attribute); // TEST: NO

    EfiStatus (EFIAPI *clearScreen)(EfiSimpleTextOutputInterface *obj); // TEST: NO
    EfiStatus (EFIAPI *setCursorPosition)(EfiSimpleTextOutputInterface *obj, u64 column, u64 row); // TEST: NO
    EfiStatus (EFIAPI *enableCursor)(EfiSimpleTextOutputInterface *obj, bool enable); // TEST: NO

    EfiSimpleTextOutputMode *mode;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLETEXTOUTPUTINTERFACE_H
