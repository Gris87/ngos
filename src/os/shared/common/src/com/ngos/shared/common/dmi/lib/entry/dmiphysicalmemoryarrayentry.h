#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H                                                                                                                                   // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiphysicalmemoryarrayerrorcorrection.h>                                                                                                              // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiphysicalmemoryarraylocation.h>                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h>                                                                                                              // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiphysicalmemoryarrayuse.h>                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/macro/constants.h>                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define DMI_PHYSICAL_MEMORY_ARRAY_MAXIMUM_CAPACITY_NEED_TO_EXTEND               0x80000000                                                                                                               // Colorize: green
#define DMI_PHYSICAL_MEMORY_ARRAY_MEMORY_ERROR_INFORMATION_HANDLE_NOT_AVAILABLE 0xFFFE                                                                                                                   // Colorize: green
#define DMI_PHYSICAL_MEMORY_ARRAY_MEMORY_ERROR_INFORMATION_HANDLE_NO_ERROR      0xFFFF                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiPhysicalMemoryArrayEntry                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader                        header;                                                                                                                                                        // Colorize: green
    DmiPhysicalMemoryArrayLocation        location;                                                                                                                                                      // Colorize: green
    DmiPhysicalMemoryArrayUse             use;                                                                                                                                                           // Colorize: green
    DmiPhysicalMemoryArrayErrorCorrection memoryErrorCorrection;                                                                                                                                         // Colorize: green
    DmiPhysicalMemoryArrayMaximumCapacity maximumCapacity;                                                                                                                                               // Colorize: green
    u16                                   memoryErrorInformationHandle;                                                                                                                                  // Colorize: green
    u16                                   numberOfMemoryDevices;                                                                                                                                         // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiPhysicalMemoryArrayEntryV27: public DmiPhysicalMemoryArrayEntry                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    u64 extendedMaximumCapacity;                                                                                                                                                                         // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPHYSICALMEMORYARRAYENTRY_H                                                                                                                                 // Colorize: green
