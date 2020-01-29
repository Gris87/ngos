#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiMemoryDeviceMappedAddressEntry
{
    DmiEntryHeader header;
    u32            startingAddress;
    u32            endingAddress;
    u16            memoryDeviceHandle;
    u16            memoryArrayMappedAddressHandle;
    u8             partitionRowPosition;
    u8             interleavePosition;
    u8             interleavedDataDepth;
    u64            extendedStartingAddress;
    u64            extendedEndingAddress;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H
