#ifndef UEFI_UEFISYSTEMTABLE_H
#define UEFI_UEFISYSTEMTABLE_H



#include <uefi/uefibootservices.h>
#include <uefi/ueficonfigurationtable.h>
#include <uefi/uefiruntimeservices.h>
#include <uefi/uefisimpleinputinterface.h>
#include <uefi/uefisimpletextoutputinterface.h>
#include <uefi/uefitableheader.h>
#include <uefi/types.h>



struct UefiSystemTable
{
    UefiTableHeader                header;

    uefi_char16                   *firmwareVendor;
    u32                            firmwareRevision;

    uefi_handle                    stdinHandle;
    UefiSimpleInputInterface      *stdin;

    uefi_handle                    stdoutHandle;
    UefiSimpleTextOutputInterface *stdout;

    uefi_handle                    stderrHandle;
    UefiSimpleTextOutputInterface *stderr;

    UefiRuntimeServices           *runtimeServices;
    UefiBootServices              *bootServices;

    u64                            numberOfTableEntries;
    UefiConfigurationTable        *configurationTable;
};



#endif // UEFI_UEFISYSTEMTABLE_H
