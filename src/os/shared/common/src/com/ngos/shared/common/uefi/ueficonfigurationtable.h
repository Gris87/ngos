#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFICONFIGURATIONTABLE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFICONFIGURATIONTABLE_H



#include <com/ngos/shared/common/guid/guid.h>



struct UefiConfigurationTable
{
    Guid  vendorGuid;
    void *vendorTable;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFICONFIGURATIONTABLE_H
