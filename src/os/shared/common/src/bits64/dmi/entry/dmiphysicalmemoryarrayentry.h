#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarraylocation.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayuse.h>



struct DmiPhysicalMemoryArrayEntry
{
    DmiEntryHeader                        header;
    DmiPhysicalMemoryArrayLocation        location;
    DmiPhysicalMemoryArrayUse             use;
    DmiPhysicalMemoryArrayErrorCorrection memoryErrorCorrection;
    u32                                   maximumCapacity;
    u16                                   memoryErrorInformationHandle;
    u16                                   numberOfMemoryDevices;
    u64                                   extendedMaximumCapacity;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H
