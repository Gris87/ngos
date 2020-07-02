#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBITS32MEMORYERRORINFORMATIONENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBITS32MEMORYERRORINFORMATIONENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmibits32memoryerrorinformationerrorgranularity.h>
#include <common/src/bits64/dmi/entry/lib/dmibits32memoryerrorinformationerroroperation.h>
#include <common/src/bits64/dmi/entry/lib/dmibits32memoryerrorinformationerrortype.h>



#define DMI_BITS32_MEMORY_ERROR_INFORMATION_VENDOR_SYNDROME_UNKNOWN            0x00000000
#define DMI_BITS32_MEMORY_ERROR_INFORMATION_MEMORY_ARRAY_ERROR_ADDRESS_UNKNOWN 0x80000000
#define DMI_BITS32_MEMORY_ERROR_INFORMATION_DEVICE_ERROR_ADDRESS_UNKNOWN       0x80000000
#define DMI_BITS32_MEMORY_ERROR_INFORMATION_ERROR_RESOLUTION_UNKNOWN           0x80000000



struct DmiBits32MemoryErrorInformationEntry
{
    DmiEntryHeader                                  header;
    DmiBits32MemoryErrorInformationErrorType        errorType;
    DmiBits32MemoryErrorInformationErrorGranularity errorGranularity;
    DmiBits32MemoryErrorInformationErrorOperation   errorOperation;
    u32                                             vendorSyndrome;
    u32                                             memoryArrayErrorAddress;
    u32                                             deviceErrorAddress;
    u32                                             errorResolution;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBITS32MEMORYERRORINFORMATIONENTRY_H
