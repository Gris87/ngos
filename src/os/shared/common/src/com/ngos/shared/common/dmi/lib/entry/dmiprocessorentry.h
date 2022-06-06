#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPROCESSORENTRY_H                                                                                                                                             // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPROCESSORENTRY_H                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorcharacteristicsflags.h>                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorfamily.h>                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorfamily2.h>                                                                                                                                // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorid.h>                                                                                                                                     // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorstatusandsocketpopulated.h>                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessortype.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorupgrade.h>                                                                                                                                // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorvoltage.h>                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define DMI_PROCESSOR_EXTERNAL_CLOCK_UNKNOWN            0x0000                                                                                                                                           // Colorize: green
#define DMI_PROCESSOR_MAX_SPEED_UNKNOWN                 0x0000                                                                                                                                           // Colorize: green
#define DMI_PROCESSOR_CURRENT_SPEED_UNKNOWN             0x0000                                                                                                                                           // Colorize: green
#define DMI_PROCESSOR_L1_CACHE_HANDLE_NOT_AVAILABLE     0xFFFF                                                                                                                                           // Colorize: green
#define DMI_PROCESSOR_L2_CACHE_HANDLE_NOT_AVAILABLE     0xFFFF                                                                                                                                           // Colorize: green
#define DMI_PROCESSOR_L3_CACHE_HANDLE_NOT_AVAILABLE     0xFFFF                                                                                                                                           // Colorize: green
#define DMI_PROCESSOR_CORE_COUNT_UNKNOWN                0x00                                                                                                                                             // Colorize: green
#define DMI_PROCESSOR_CORE_COUNT_NEED_TO_EXTEND         0xFF                                                                                                                                             // Colorize: green
#define DMI_PROCESSOR_ENABLED_CORE_COUNT_UNKNOWN        0x00                                                                                                                                             // Colorize: green
#define DMI_PROCESSOR_ENABLED_CORE_COUNT_NEED_TO_EXTEND 0xFF                                                                                                                                             // Colorize: green
#define DMI_PROCESSOR_THREAD_COUNT_UNKNOWN              0x00                                                                                                                                             // Colorize: green
#define DMI_PROCESSOR_THREAD_COUNT_NEED_TO_EXTEND       0xFF                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorEntry                                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader                       header;                                                                                                                                                         // Colorize: green
    DmiStringId                          socketDesignation;                                                                                                                                              // Colorize: green
    DmiProcessorType                     processorType;                                                                                                                                                  // Colorize: green
    DmiProcessorFamily                   processorFamily;                                                                                                                                                // Colorize: green
    DmiStringId                          processorManufacturer;                                                                                                                                          // Colorize: green
    DmiProcessorId                       processorId;                                                                                                                                                    // Colorize: green
    DmiStringId                          processorVersion;                                                                                                                                               // Colorize: green
    DmiProcessorVoltage                  voltage;                                                                                                                                                        // Colorize: green
    u16                                  externalClock;                                                                                                                                                  // Colorize: green
    u16                                  maxSpeed;                                                                                                                                                       // Colorize: green
    u16                                  currentSpeed;                                                                                                                                                   // Colorize: green
    DmiProcessorStatusAndSocketPopulated processorStatusAndSocketPopulated;                                                                                                                              // Colorize: green
    DmiProcessorUpgrade                  processorUpgrade;                                                                                                                                               // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorEntryV21: public DmiProcessorEntry                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    u16 l1CacheHandle;                                                                                                                                                                                   // Colorize: green
    u16 l2CacheHandle;                                                                                                                                                                                   // Colorize: green
    u16 l3CacheHandle;                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorEntryV23: public DmiProcessorEntryV21                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiStringId serialNumber;                                                                                                                                                                            // Colorize: green
    DmiStringId assetTag;                                                                                                                                                                                // Colorize: green
    DmiStringId partNumber;                                                                                                                                                                              // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorEntryV25: public DmiProcessorEntryV23                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    u8                               coreCount;                                                                                                                                                          // Colorize: green
    u8                               enabledCoreCount;                                                                                                                                                   // Colorize: green
    u8                               threadCount;                                                                                                                                                        // Colorize: green
    DmiProcessorCharacteristicsFlags processorCharacteristics;                                                                                                                                           // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorEntryV26: public DmiProcessorEntryV25                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiProcessorFamily2 processorFamily2;                                                                                                                                                                // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorEntryV30: public DmiProcessorEntryV26                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    u16 coreCount2;                                                                                                                                                                                      // Colorize: green
    u16 enabledCoreCount2;                                                                                                                                                                               // Colorize: green
    u16 threadCount2;                                                                                                                                                                                    // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPROCESSORENTRY_H                                                                                                                                           // Colorize: green