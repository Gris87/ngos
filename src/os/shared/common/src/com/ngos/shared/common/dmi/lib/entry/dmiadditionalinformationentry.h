#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiadditionalinformation.h>



struct DmiAdditionalInformationEntry
{
    DmiEntryHeader           header;
    u8                       numberOfAdditionalInformationEntries;
    DmiAdditionalInformation additionalInformationEntries[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H
