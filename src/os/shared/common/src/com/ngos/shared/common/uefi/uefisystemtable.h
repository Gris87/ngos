#ifndef UEFI_UEFISYSTEMTABLE_H
#define UEFI_UEFISYSTEMTABLE_H



#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefibootservices.h>
#include <common/src/com/ngos/shared/common/uefi/ueficonfigurationtable.h>
#include <common/src/com/ngos/shared/common/uefi/uefiruntimeservices.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimpleinputinterface.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimpletextoutputinterface.h>
#include <common/src/com/ngos/shared/common/uefi/uefitableheader.h>



struct UefiSystemTable
{
    UefiTableHeader                header;

    char16                        *firmwareVendor;
    u32                            firmwareRevision;

    uefi_handle                    stdinHandle;
    UefiSimpleInputInterface      *stdin;

    uefi_handle                    stdoutHandle;
    UefiSimpleTextOutputInterface *stdout;

    uefi_handle                    stderrHandle;
    UefiSimpleTextOutputInterface *stderr;

    UefiRuntimeServices           *runtimeServices;
    UefiBootServices              *bootServices;

    u64                            numberOfConfigurationTables;
    UefiConfigurationTable        *configurationTables;
};



#endif // UEFI_UEFISYSTEMTABLE_H
