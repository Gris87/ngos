#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMI_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMI_H



#include <kernelbase/src/bits64/other/dmi/dmientryheader.h>
#include <kernelbase/src/bits64/other/dmi/dmiidentity.h>
#include <kernelbase/src/bits64/other/dmi/dmimemorydevice.h>
#include <kernelbase/src/bits64/other/dmi/dmistoreduuid.h>
#include <kernelbase/src/bits64/other/dmi/entry/dmibaseboardentry.h>
#include <kernelbase/src/bits64/other/dmi/entry/dmibiosentry.h>
#include <kernelbase/src/bits64/other/dmi/entry/dmichassisentry.h>
#include <kernelbase/src/bits64/other/dmi/entry/dmisystementry.h>
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
    static u8               sChassisType;
    static u64              sNumberOfMemoryDevices;
    static DmiMemoryDevice *sMemoryDevices;
    static const char8*     sIdentities[(u64)DmiIdentity::MAXIMUM];
    static Uuid*            sUuids[(u64)DmiStoredUuid::MAXIMUM];
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMI_H
