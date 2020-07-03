#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS64MEMORYERRORINFORMATIONENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS64MEMORYERRORINFORMATIONENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibits64memoryerrorinformationerrorgranularity.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibits64memoryerrorinformationerroroperation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibits64memoryerrorinformationerrortype.h>



#define DMI_BITS64_MEMORY_ERROR_INFORMATION_VENDOR_SYNDROME_UNKNOWN            0x00000000
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_MEMORY_ARRAY_ERROR_ADDRESS_UNKNOWN 0x8000000000000000
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_DEVICE_ERROR_ADDRESS_UNKNOWN       0x8000000000000000
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_ERROR_RESOLUTION_UNKNOWN           0x80000000



struct DmiBits64MemoryErrorInformationEntry
{
    DmiEntryHeader                                  header;
    DmiBits64MemoryErrorInformationErrorType        errorType;
    DmiBits64MemoryErrorInformationErrorGranularity errorGranularity;
    DmiBits64MemoryErrorInformationErrorOperation   errorOperation;
    u32                                             vendorSyndrome;
    u64                                             memoryArrayErrorAddress;
    u64                                             deviceErrorAddress;
    u32                                             errorResolution;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS64MEMORYERRORINFORMATIONENTRY_H
