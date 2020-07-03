#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEMODETYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEMODETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



enum class DmiProcessorVoltageModeType: u8
{
    LEGACY_MODE          = 0,
    CURRENT_VOLTAGE_MODE = 1
};



inline const char8* enumToString(DmiProcessorVoltageModeType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiProcessorVoltageModeType::LEGACY_MODE:          return "LEGACY_MODE";
        case DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE: return "CURRENT_VOLTAGE_MODE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiProcessorVoltageModeType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[28];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEMODETYPE_H
