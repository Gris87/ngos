#ifndef UEFI_UEFICONFIGURATIONTABLE_H
#define UEFI_UEFICONFIGURATIONTABLE_H



#include <uefi/uefiguid.h>



struct UefiConfigurationTable
{
    UefiGuid  vendorGuid;
    void     *vendorTable;
};



#endif // UEFI_UEFICONFIGURATIONTABLE_H
