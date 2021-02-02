#ifndef COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H
#define COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>



#define UEFI_MEMORY_ATTRIBUTES_CONFIGURATION_TABLE_GUID \
    { 0xDCFA911D, 0x26EB, 0x469F, { 0xA2, 0x20, 0x38, 0xB7, 0xDC, 0x46, 0x12, 0x20 } }



struct UefiMemoryAttributesConfigurationTable
{
    bad_uint32                  version;
    bad_uint32                  numberOfEntries;
    bad_uint32                  descriptorSize;
    bad_uint32                  __reserved;
    UefiMemoryDescriptor entries[0];
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H
