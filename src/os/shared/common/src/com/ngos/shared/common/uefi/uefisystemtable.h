#ifndef UEFI_UEFISYSTEMTABLE_H
#define UEFI_UEFISYSTEMTABLE_H



#include <uefi/types.h>
#include <uefi/uefibootservices.h>
#include <uefi/ueficonfigurationtable.h>
#include <uefi/uefiruntimeservices.h>
#include <uefi/uefisimpleinputinterface.h>
#include <uefi/uefisimpletextoutputinterface.h>
#include <uefi/uefitableheader.h>



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
