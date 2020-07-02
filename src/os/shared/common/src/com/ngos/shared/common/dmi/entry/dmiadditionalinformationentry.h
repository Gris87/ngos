#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmiadditionalinformation.h>



struct DmiAdditionalInformationEntry
{
    DmiEntryHeader           header;
    u8                       numberOfAdditionalInformationEntries;
    DmiAdditionalInformation additionalInformationEntries[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H
