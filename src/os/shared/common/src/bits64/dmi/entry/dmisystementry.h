#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <uuid/uuid.h>



struct DmiSystemEntry
{
    DmiEntryHeader header;
    u8             manufacturer;
    u8             productName;
    u8             version;
    u8             serialNumber;
    Uuid           uuid;
    u8             wakeUpTime;
    u8             skuNumber;
    u8             family;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMENTRY_H
