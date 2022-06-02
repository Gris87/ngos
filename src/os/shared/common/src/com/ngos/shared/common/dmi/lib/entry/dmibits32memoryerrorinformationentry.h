#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS32MEMORYERRORINFORMATIONENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS32MEMORYERRORINFORMATIONENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibits32memoryerrorinformationerrorgranularity.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibits32memoryerrorinformationerroroperation.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibits32memoryerrorinformationerrortype.h>



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



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS32MEMORYERRORINFORMATIONENTRY_H
