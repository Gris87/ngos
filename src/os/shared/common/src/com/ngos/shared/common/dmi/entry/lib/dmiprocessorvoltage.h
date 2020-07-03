#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGE_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltageflags.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltagemodetype.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGE_H
