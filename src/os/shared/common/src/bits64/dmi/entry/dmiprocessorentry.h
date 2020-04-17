#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPROCESSORENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPROCESSORENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorcharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorfamily.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorfamily2.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorid.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorstatus.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessortype.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorupgrade.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorvoltage.h>



struct DmiProcessorEntry
{
    DmiEntryHeader      header;
    u8                  socketStringId;
    DmiProcessorType    processorType;
    DmiProcessorFamily  processorFamily;
    u8                  processorManufactureStringId;
    DmiProcessorId      processorId;
    u8                  processorVersionStringId;
    DmiProcessorVoltage voltage;
    u16                 externalClock;
    u16                 maxSpeed;
    u16                 currentSpeed;

    union
    {
        struct
        {
            u8 status:          3; // TODO: Use enum DmiProcessorStatus
            u8 __reserved:      3;
            u8 socketPopulated: 1;
            u8 __reserved2:     1;
        };

        u8 processorStatus;
    };

    DmiProcessorUpgrade              processorUpgrade;
    u16                              l1CacheHandle;
    u16                              l2CacheHandle;
    u16                              l3CacheHandle;
    u8                               serialNumberStringId;
    u8                               assetTagStringId;
    u8                               partNumberStringId;
    u8                               coreCount;
    u8                               enabledCoreCount;
    u8                               threadCount;
    DmiProcessorCharacteristicsFlags processorCharacteristics;
    DmiProcessorFamily2              processorFamily2;
    u16                              coreCount2;
    u16                              enabledCoreCount2;
    u16                              threadCount2;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPROCESSORENTRY_H
