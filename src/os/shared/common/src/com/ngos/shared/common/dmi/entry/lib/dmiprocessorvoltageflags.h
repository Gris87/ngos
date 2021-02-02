#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint8 dmi_processor_voltage_flags;

enum class DmiProcessorVoltageFlag: dmi_processor_voltage_flags
{
    NONE            = 0,
    CAPABILITY_5V   = (1ULL << 0),
    CAPABILITY_3_3V = (1ULL << 1),
    CAPABILITY_2_9V = (1ULL << 2)
};

DEFINE_FLAGS(DmiProcessorVoltageFlags, dmi_processor_voltage_flags); // TEST: NO



inline const char8* flagToString(DmiProcessorVoltageFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiProcessorVoltageFlag::NONE:            return "NONE";
        case DmiProcessorVoltageFlag::CAPABILITY_5V:   return "CAPABILITY_5V";
        case DmiProcessorVoltageFlag::CAPABILITY_3_3V: return "CAPABILITY_3_3V";
        case DmiProcessorVoltageFlag::CAPABILITY_2_9V: return "CAPABILITY_2_9V";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiProcessorVoltageFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", (dmi_processor_voltage_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiProcessorVoltageFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[65];

    FLAGS_TO_STRING(res, flags.flags, DmiProcessorVoltageFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiProcessorVoltageFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[72];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiProcessorVoltageFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEFLAGS_H
