#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISYSTEMTABLE_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISYSTEMTABLE_H



#include "src/bits64/a_uefi/uefi/lib/efibootservices.h"
#include "src/bits64/a_uefi/uefi/lib/eficonfigurationtable.h"
#include "src/bits64/a_uefi/uefi/lib/efiruntimeservices.h"
#include "src/bits64/a_uefi/uefi/lib/efisimpleinputinterface.h"
#include "src/bits64/a_uefi/uefi/lib/efisimpletextoutputinterface.h"
#include "src/bits64/a_uefi/uefi/lib/efitableheader.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiSystemTable
{
    EfiTableHeader                header;

    efi_char16                   *firmwareVendor;
    u32                           firmwareRevision;

    EfiHandle                     stdinHandle;
    EfiSimpleInputInterface      *stdin;

    EfiHandle                     stdoutHandle;
    EfiSimpleTextOutputInterface *stdout;

    EfiHandle                     stderrHandle;
    EfiSimpleTextOutputInterface *stderr;

    EfiRuntimeServices           *runtimeServices;
    EfiBootServices              *bootServices;

    u64                           numberOfTableEntries;
    EfiConfigurationTable        *configurationTable;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISYSTEMTABLE_H
