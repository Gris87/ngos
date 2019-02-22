#ifndef UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H
#define UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H



#include <ngos/types.h>

#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefisimpletextoutputmode.h>
#include <uefi/uefistatus.h>



struct UefiSimpleTextOutputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleTextOutputInterface *obj, bool extendedVerification); // TEST: NO

    UefiStatus (UEFI_API *outputString)(UefiSimpleTextOutputInterface *obj, uefi_char16 *string); // TEST: NO
    UefiStatus (UEFI_API *testString)(UefiSimpleTextOutputInterface *obj, uefi_char16 *string); // TEST: NO

    UefiStatus (UEFI_API *queryMode)(UefiSimpleTextOutputInterface *obj, u64 modeNumber, u64 *columns, u64 *rows); // TEST: NO
    UefiStatus (UEFI_API *setMode)(UefiSimpleTextOutputInterface *obj, u64 modeNumber); // TEST: NO
    UefiStatus (UEFI_API *setAttribute)(UefiSimpleTextOutputInterface *obj, u64 attribute); // TEST: NO

    UefiStatus (UEFI_API *clearScreen)(UefiSimpleTextOutputInterface *obj); // TEST: NO
    UefiStatus (UEFI_API *setCursorPosition)(UefiSimpleTextOutputInterface *obj, u64 column, u64 row); // TEST: NO
    UefiStatus (UEFI_API *enableCursor)(UefiSimpleTextOutputInterface *obj, bool enable); // TEST: NO

    UefiSimpleTextOutputMode *mode;
};



#endif // UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H
