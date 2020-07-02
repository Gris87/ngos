#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarraylocation.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h>
#include <common/src/bits64/dmi/entry/lib/dmiphysicalmemoryarrayuse.h>
#include <macro/constants.h>



#define DMI_PHYSICAL_MEMORY_ARRAY_MAXIMUM_CAPACITY_NEED_TO_EXTEND               0x80000000
#define DMI_PHYSICAL_MEMORY_ARRAY_MEMORY_ERROR_INFORMATION_HANDLE_NOT_AVAILABLE 0xFFFE
#define DMI_PHYSICAL_MEMORY_ARRAY_MEMORY_ERROR_INFORMATION_HANDLE_NO_ERROR      0xFFFF



struct DmiPhysicalMemoryArrayEntry
{
    DmiEntryHeader                        header;
    DmiPhysicalMemoryArrayLocation        location;
    DmiPhysicalMemoryArrayUse             use;
    DmiPhysicalMemoryArrayErrorCorrection memoryErrorCorrection;
    DmiPhysicalMemoryArrayMaximumCapacity maximumCapacity;
    u16                                   memoryErrorInformationHandle;
    u16                                   numberOfMemoryDevices;
} __attribute__((packed));



struct DmiPhysicalMemoryArrayEntryV27: public DmiPhysicalMemoryArrayEntry
{
    u64 extendedMaximumCapacity;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H
