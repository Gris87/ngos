#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMI_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMI_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmiidentity.h>
#include <common/src/bits64/dmi/dmimemorydevice.h>
#include <common/src/bits64/dmi/dmistoreduuid.h>
#include <common/src/bits64/dmi/entry/dmibaseboardentry.h>
#include <common/src/bits64/dmi/entry/dmibiosentry.h>
#include <common/src/bits64/dmi/entry/dmichassisentry.h>
#include <common/src/bits64/dmi/entry/dmimemoryarraymappedaddressentry.h>
#include <common/src/bits64/dmi/entry/dmiphysicalmemoryarrayentry.h>
#include <common/src/bits64/dmi/entry/dmiprocessorentry.h>
#include <common/src/bits64/dmi/entry/dmisystembootentry.h>
#include <common/src/bits64/dmi/entry/dmisystementry.h>
#include <ngos/status.h>
#include <uefi/config/uefismbios3configurationtable.h>
#include <uefi/config/uefismbiosconfigurationtable.h>



typedef NgosStatus (*process_dmi_entry) (DmiEntryHeader *header);



class DMI
{
public:
    static NgosStatus init(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initFromSmbios3(UefiSmbios3ConfigurationTable *smbios3); // TEST: NO
    static NgosStatus initFromSmbios(UefiSmbiosConfigurationTable *smbios); // TEST: NO
    static NgosStatus iterateDmiEntries(u8 *buf, process_dmi_entry processDmiEntry);
    static NgosStatus decodeDmiEntry(DmiEntryHeader *header); // TEST: NO
    static NgosStatus saveDmiBiosEntry(DmiBiosEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemEntry(DmiSystemEntry *entry); // TEST: NO
    static NgosStatus saveDmiBaseboardEntry(DmiBaseboardEntry *entry); // TEST: NO
    static NgosStatus saveDmiChassisEntry(DmiChassisEntry *entry); // TEST: NO
    static NgosStatus saveDmiProcessorEntry(DmiProcessorEntry *entry); // TEST: NO
    static NgosStatus saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry); // TEST: NO
    static NgosStatus saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry); // TEST: NO
    static NgosStatus saveDmiSystemBootEntry(DmiSystemBootEntry *entry); // TEST: NO
    static NgosStatus storeDmiMemoryDevices(u8 *buf); // TEST: NO
    static NgosStatus countDmiMemoryDevices(DmiEntryHeader *header); // TEST: NO
    static NgosStatus saveDmiMemoryDevice(DmiEntryHeader *header); // TEST: NO
    static NgosStatus saveIdentity(DmiIdentity id, u8 *address, u64 size); // TEST: NO
    static NgosStatus saveUuid(DmiStoredUuid id, const Uuid &uuid); // TEST: NO
    static NgosStatus getString(u8 *address, u64 size, u8 **destination); // TEST: NO
    static u8 checksum(u8 *address, u64 size, u8 checksumValue);

    static u32              sVersion;
    static u16              sNumberOfSmbiosStructures;
    static u32              sStructureTableLength;
    static u64              sStructureTableAddress;
    static DmiChassisType   sChassisType;
    static u64              sNumberOfMemoryDevices;
    static DmiMemoryDevice *sMemoryDevices;
    static const char8*     sIdentities[(u64)DmiIdentity::MAXIMUM];
    static Uuid*            sUuids[(u64)DmiStoredUuid::MAXIMUM];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMI_H
