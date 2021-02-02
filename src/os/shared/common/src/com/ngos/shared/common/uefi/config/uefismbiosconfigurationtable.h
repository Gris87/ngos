#ifndef COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOSCONFIGURATIONTABLE_H
#define COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOSCONFIGURATIONTABLE_H



#include <com/ngos/shared/common/ngos/types.h>



#define UEFI_SMBIOS_CONFIGURATION_TABLE_GUID \
    { 0xEB9D2D31, 0x2D88, 0x11D3, { 0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }

#define SMBIOS_ANCHOR               0x5F4D535F          // _SM_
#define SMBIOS_INTERMEDIATE_ANCHOR  0x0000005F494D445F  // _DMI_



struct UefiSmbiosConfigurationTable
{
    bad_uint32 anchor;
    bad_uint8  entryPointStructureChecksum;
    bad_uint8  entryPointLength;
    bad_uint8  majorVersion;
    bad_uint8  minorVersion;
    bad_uint16 maximumStructureSize;
    bad_uint8  entryPointRevision;
    bad_uint8  formattedArea[5];
    bad_uint8  intermediateAnchor[5];
    bad_uint8  intermediateChecksum;
    bad_uint16 structureTableLength;
    bad_uint32 structureTableAddress;
    bad_uint16 numberOfSmbiosStructures;
    bad_uint8  bcdRevision;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_UEFI_CONFIG_UEFISMBIOSCONFIGURATIONTABLE_H
