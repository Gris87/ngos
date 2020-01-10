#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIOEMSTRINGSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIOEMSTRINGSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiOemStringsEntry
{
    DmiEntryHeader header;
    u8             stringCount;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIOEMSTRINGSENTRY_H
