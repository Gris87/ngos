#ifndef UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H
#define UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H



#include <ngos/types.h>
#include <uefi/uefimemorydescriptor.h>



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



#endif // UEFI_CONFIG_UEFIMEMORYATTRIBUTESCONFIGURATIONTABLE_H
