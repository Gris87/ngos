#ifndef COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOS3CONFIGURATIONTABLE_H
#define COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOS3CONFIGURATIONTABLE_H



#include <com/ngos/shared/common/ngos/types.h>



#define UEFI_SMBIOS_3_CONFIGURATION_TABLE_GUID \
    { 0xF2FD1544, 0x9794, 0x4A2C, { 0x99, 0x2E, 0xE5, 0xBB, 0xCF, 0x20, 0xE3, 0x94 } }

#define SMBIOS_3_ANCHOR  0x0000005F334D535F  // _SM3_



struct UefiSmbios3ConfigurationTable
{
    bad_uint8  anchor[5];
    bad_uint8  entryPointStructureChecksum;
    bad_uint8  entryPointLength;
    bad_uint8  majorVersion;
    bad_uint8  minorVersion;
    bad_uint8  docRevision;
    bad_uint8  entryPointRevision;
    bad_uint8  __reserved;
    bad_uint32 structureTableMaximumSize;
    bad_uint64 structureTableAddress;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOS3CONFIGURATIONTABLE_H
