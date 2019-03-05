#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_ENTRY_DMISYSTEMENTRY_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_ENTRY_DMISYSTEMENTRY_H



#include <kernelbase/src/bits64/other/dmi/dmientryheader.h>
#include <kernelbase/src/bits64/other/dmi/dmiuuid.h>



struct DmiSystemEntry
{
    DmiEntryHeader header;
    u8             manufacturer;
    u8             productName;
    u8             version;
    u8             serialNumber;
    DmiUuid        uuid;
    u8             wakeUpTime;
    u8             skuNumber;
    u8             family;
} __attribute__((packed));



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_ENTRY_DMISYSTEMENTRY_H
