#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorydescriptor.h>



#define UEFI_MEMORY_ATTRIBUTES_CONFIGURATION_TABLE_GUID \
    { 0xDCFA911D, 0x26EB, 0x469F, { 0xA2, 0x20, 0x38, 0xB7, 0xDC, 0x46, 0x12, 0x20 } }



struct UefiMemoryAttributesConfigurationTable
{
    u32                  version;
    u32                  numberOfEntries;
    u32                  descriptorSize;
    u32                  __reserved;
    UefiMemoryDescriptor entries[0];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H
