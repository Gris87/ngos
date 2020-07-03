#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraylocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarrayuse.h>
#include <com/ngos/shared/common/macro/constants.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H
