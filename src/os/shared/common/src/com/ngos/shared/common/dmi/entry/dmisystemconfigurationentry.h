#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiSystemConfigurationEntry
{
    DmiEntryHeader header;
    u8             stringCount;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMCONFIGURATIONENTRY_H
