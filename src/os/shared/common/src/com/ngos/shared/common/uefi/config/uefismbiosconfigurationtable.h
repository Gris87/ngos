#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOSCONFIGURATIONTABLE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOSCONFIGURATIONTABLE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



#define UEFI_SMBIOS_CONFIGURATION_TABLE_GUID \
    { 0xEB9D2D31, 0x2D88, 0x11D3, { 0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }

#define SMBIOS_ANCHOR               0x5F4D535F          // _SM_
#define SMBIOS_INTERMEDIATE_ANCHOR  0x0000005F494D445F  // _DMI_



struct UefiSmbiosConfigurationTable
{
    u32 anchor;
    u8  entryPointStructureChecksum;
    u8  entryPointLength;
    u8  majorVersion;
    u8  minorVersion;
    u16 maximumStructureSize;
    u8  entryPointRevision;
    u8  formattedArea[5];
    u8  intermediateAnchor[5];
    u8  intermediateChecksum;
    u16 structureTableLength;
    u32 structureTableAddress;
    u16 numberOfSmbiosStructures;
    u8  bcdRevision;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOSCONFIGURATIONTABLE_H
