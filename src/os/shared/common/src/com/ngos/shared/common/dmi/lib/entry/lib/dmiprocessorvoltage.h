#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGE_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorvoltageflags.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorvoltagemodetype.h>



struct DmiProcessorVoltage
{
    union
    {
        // DmiProcessorVoltageModeType::LEGACY_MODE
        struct
        {
            u8 flags:    7; // TODO: Use enum DmiProcessorVoltageFlags
            u8 modeType: 1; // TODO: Use enum DmiProcessorVoltageModeType
        };

        // DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE
        struct
        {
            u8 value: 7;
            u8 __pad: 1; // Ignore this field. The same as modeType
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGE_H
