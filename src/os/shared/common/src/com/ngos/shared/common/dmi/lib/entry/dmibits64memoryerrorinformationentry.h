#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS64MEMORYERRORINFORMATIONENTRY_H                                                                                                                          // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS64MEMORYERRORINFORMATIONENTRY_H                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibits64memoryerrorinformationerrorgranularity.h>                                                                                                    // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibits64memoryerrorinformationerroroperation.h>                                                                                                      // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibits64memoryerrorinformationerrortype.h>                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_VENDOR_SYNDROME_UNKNOWN            0x00000000                                                                                                                // Colorize: green
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_MEMORY_ARRAY_ERROR_ADDRESS_UNKNOWN 0x8000000000000000                                                                                                        // Colorize: green
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_DEVICE_ERROR_ADDRESS_UNKNOWN       0x8000000000000000                                                                                                        // Colorize: green
#define DMI_BITS64_MEMORY_ERROR_INFORMATION_ERROR_RESOLUTION_UNKNOWN           0x80000000                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiBits64MemoryErrorInformationEntry                                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader                                  header;                                                                                                                                              // Colorize: green
    DmiBits64MemoryErrorInformationErrorType        errorType;                                                                                                                                           // Colorize: green
    DmiBits64MemoryErrorInformationErrorGranularity errorGranularity;                                                                                                                                    // Colorize: green
    DmiBits64MemoryErrorInformationErrorOperation   errorOperation;                                                                                                                                      // Colorize: green
    u32                                             vendorSyndrome;                                                                                                                                      // Colorize: green
    u64                                             memoryArrayErrorAddress;                                                                                                                             // Colorize: green
    u64                                             deviceErrorAddress;                                                                                                                                  // Colorize: green
    u32                                             errorResolution;                                                                                                                                     // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBITS64MEMORYERRORINFORMATIONENTRY_H                                                                                                                        // Colorize: green