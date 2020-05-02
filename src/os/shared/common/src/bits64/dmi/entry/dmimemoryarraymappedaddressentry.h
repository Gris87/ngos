#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmimemoryarraymappedaddressrange.h>



#define DMI_MEMORY_ARRAY_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND 0xFFFFFFFF
#define DMI_MEMORY_ARRAY_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND   0xFFFFFFFF



struct DmiMemoryArrayMappedAddressEntry
{
    DmiEntryHeader                   header;
    DmiMemoryArrayMappedAddressRange startingAddress;
    DmiMemoryArrayMappedAddressRange endingAddress;
    u16                              memoryArrayHandle;
    u8                               partitionWidth;
} __attribute__((packed));



struct DmiMemoryArrayMappedAddressEntryV27: public DmiMemoryArrayMappedAddressEntry
{
    u64 extendedStartingAddress;
    u64 extendedEndingAddress;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H
