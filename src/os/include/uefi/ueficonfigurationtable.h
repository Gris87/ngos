#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFICONFIGURATIONTABLE_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFICONFIGURATIONTABLE_H



#include "src/bits64/a_uefi/uefi/lib/efiguid.h"



struct EfiConfigurationTable
{
    EfiGuid  vendorGuid;
    void    *vendorTable;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFICONFIGURATIONTABLE_H
