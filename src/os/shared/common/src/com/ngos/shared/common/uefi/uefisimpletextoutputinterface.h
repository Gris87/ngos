#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefisimpletextoutputmode.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



struct UefiSimpleTextOutputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleTextOutputInterface *obj, bool extendedVerification); // TEST: NO

    UefiStatus (UEFI_API *outputString)(UefiSimpleTextOutputInterface *obj, const char16 *string); // TEST: NO
    UefiStatus (UEFI_API *testString)(UefiSimpleTextOutputInterface *obj, const char16 *string); // TEST: NO

    UefiStatus (UEFI_API *queryMode)(UefiSimpleTextOutputInterface *obj, bad_uint64 modeNumber, bad_uint64 *columns, bad_uint64 *rows); // TEST: NO
    UefiStatus (UEFI_API *setMode)(UefiSimpleTextOutputInterface *obj, bad_uint64 modeNumber); // TEST: NO
    UefiStatus (UEFI_API *setAttribute)(UefiSimpleTextOutputInterface *obj, bad_uint64 attribute); // TEST: NO

    UefiStatus (UEFI_API *clearScreen)(UefiSimpleTextOutputInterface *obj); // TEST: NO
    UefiStatus (UEFI_API *setCursorPosition)(UefiSimpleTextOutputInterface *obj, bad_uint64 column, bad_uint64 row); // TEST: NO
    UefiStatus (UEFI_API *enableCursor)(UefiSimpleTextOutputInterface *obj, bool enable); // TEST: NO

    UefiSimpleTextOutputMode *mode;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H
