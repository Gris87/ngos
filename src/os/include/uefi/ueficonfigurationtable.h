#ifndef UEFI_UEFICONFIGURATIONTABLE_H
#define UEFI_UEFICONFIGURATIONTABLE_H



#include <guid/guid.h>



struct UefiConfigurationTable
{
    Guid  vendorGuid;
    void *vendorTable;
};



#endif // UEFI_UEFICONFIGURATIONTABLE_H
