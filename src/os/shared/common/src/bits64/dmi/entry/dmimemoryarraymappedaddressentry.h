#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiMemoryArrayMappedAddressEntry
{
    DmiEntryHeader header;
    u32            startingAddress;
    u32            endingAddress;
    u16            memoryArrayHandle;
    u8             partitionWidth;
    u64            extendedStartingAddress;
    u64            extendedEndingAddress;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H
