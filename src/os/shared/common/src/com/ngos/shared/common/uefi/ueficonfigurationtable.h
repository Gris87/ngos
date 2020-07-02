#ifndef UEFI_UEFICONFIGURATIONTABLE_H
#define UEFI_UEFICONFIGURATIONTABLE_H



#include <common/src/com/ngos/shared/common/guid/guid.h>



struct UefiConfigurationTable
{
    Guid  vendorGuid;
    void *vendorTable;
};



#endif // UEFI_UEFICONFIGURATIONTABLE_H
