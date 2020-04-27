#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemwakeuptype.h>
#include <uuid/uuid.h>



struct DmiSystemEntry
{
    DmiEntryHeader      header;
    DmiStringId         manufacturer;
    DmiStringId         productName;
    DmiStringId         version;
    DmiStringId         serialNumber;
    Uuid                uuid;
    DmiSystemWakeUpType wakeUpType;
    DmiStringId         skuNumber;
    DmiStringId         family;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H
