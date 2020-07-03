#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICONFIGURATIONTABLE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICONFIGURATIONTABLE_H



#include <common/src/com/ngos/shared/common/guid/guid.h>



struct UefiConfigurationTable
{
    Guid  vendorGuid;
    void *vendorTable;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICONFIGURATIONTABLE_H
