#ifndef UEFI_CONFIG_UEFISMBIOS3CONFIGURATIONTABLE_H
#define UEFI_CONFIG_UEFISMBIOS3CONFIGURATIONTABLE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



#define UEFI_SMBIOS_3_CONFIGURATION_TABLE_GUID \
    { 0xF2FD1544, 0x9794, 0x4A2C, { 0x99, 0x2E, 0xE5, 0xBB, 0xCF, 0x20, 0xE3, 0x94 } }

#define SMBIOS_3_ANCHOR  0x0000005F334D535F  // _SM3_



struct UefiSmbios3ConfigurationTable
{
    u8  anchor[5];
    u8  entryPointStructureChecksum;
    u8  entryPointLength;
    u8  majorVersion;
    u8  minorVersion;
    u8  docRevision;
    u8  entryPointRevision;
    u8  __reserved;
    u32 structureTableMaximumSize;
    u64 structureTableAddress;
} __attribute__((packed));



#endif // UEFI_CONFIG_UEFISMBIOS3CONFIGURATIONTABLE_H
