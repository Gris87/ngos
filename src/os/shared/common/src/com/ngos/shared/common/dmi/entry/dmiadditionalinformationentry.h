#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiadditionalinformation.h>



struct DmiAdditionalInformationEntry
{
    DmiEntryHeader           header;
    u8                       numberOfAdditionalInformationEntries;
    DmiAdditionalInformation additionalInformationEntries[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIADDITIONALINFORMATIONENTRY_H
