#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISYSTEMTABLE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISYSTEMTABLE_H



#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefibootservices.h>
#include <com/ngos/shared/common/uefi/ueficonfigurationtable.h>
#include <com/ngos/shared/common/uefi/uefiruntimeservices.h>
#include <com/ngos/shared/common/uefi/uefisimpleinputinterface.h>
#include <com/ngos/shared/common/uefi/uefisimpletextoutputinterface.h>
#include <com/ngos/shared/common/uefi/uefitableheader.h>



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



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISYSTEMTABLE_H
