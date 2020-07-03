#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimpletextoutputmode.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiSimpleTextOutputInterface
{
    UefiStatus (UEFI_API *reset)(UefiSimpleTextOutputInterface *obj, bool extendedVerification); // TEST: NO

    UefiStatus (UEFI_API *outputString)(UefiSimpleTextOutputInterface *obj, const char16 *string); // TEST: NO
    UefiStatus (UEFI_API *testString)(UefiSimpleTextOutputInterface *obj, const char16 *string); // TEST: NO

    UefiStatus (UEFI_API *queryMode)(UefiSimpleTextOutputInterface *obj, u64 modeNumber, u64 *columns, u64 *rows); // TEST: NO
    UefiStatus (UEFI_API *setMode)(UefiSimpleTextOutputInterface *obj, u64 modeNumber); // TEST: NO
    UefiStatus (UEFI_API *setAttribute)(UefiSimpleTextOutputInterface *obj, u64 attribute); // TEST: NO

    UefiStatus (UEFI_API *clearScreen)(UefiSimpleTextOutputInterface *obj); // TEST: NO
    UefiStatus (UEFI_API *setCursorPosition)(UefiSimpleTextOutputInterface *obj, u64 column, u64 row); // TEST: NO
    UefiStatus (UEFI_API *enableCursor)(UefiSimpleTextOutputInterface *obj, bool enable); // TEST: NO

    UefiSimpleTextOutputMode *mode;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTINTERFACE_H
