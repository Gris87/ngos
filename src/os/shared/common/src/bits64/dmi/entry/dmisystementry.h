#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemwakeuptype.h>
#include <uuid/uuid.h>



struct DmiSystemEntry
{
    DmiEntryHeader      header;
    u8                  manufacturerStringId;
    u8                  productNameStringId;
    u8                  versionStringId;
    u8                  serialNumberStringId;
    Uuid                uuid;
    DmiSystemWakeUpType wakeUpType;
    u8                  skuNumberStringId;
    u8                  familyStringId;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H
