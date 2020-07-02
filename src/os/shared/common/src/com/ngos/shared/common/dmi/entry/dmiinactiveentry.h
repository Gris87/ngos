#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIINACTIVEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIINACTIVEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiInactiveEntry
{
    DmiEntryHeader header;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIINACTIVEENTRY_H
