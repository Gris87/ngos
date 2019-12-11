#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u8 dmi_processor_voltage_flags;

enum class DmiProcessorVoltageFlag: dmi_processor_voltage_flags
{
    NONE            = 0,
    CAPABILITY_5V   = (1ULL << 0),
    CAPABILITY_3_3V = (1ULL << 1),
    CAPABILITY_2_9V = (1ULL << 2),
    INDICATE_LEGACY = (1ULL << 7)
};

DEFINE_FLAGS(DmiProcessorVoltageFlags, dmi_processor_voltage_flags);



inline const char8* flagToString(DmiProcessorVoltageFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiProcessorVoltageFlag::NONE:            return "NONE";
        case DmiProcessorVoltageFlag::CAPABILITY_5V:   return "CAPABILITY_5V";
        case DmiProcessorVoltageFlag::CAPABILITY_3_3V: return "CAPABILITY_3_3V";
        case DmiProcessorVoltageFlag::CAPABILITY_2_9V: return "CAPABILITY_2_9V";
        case DmiProcessorVoltageFlag::INDICATE_LEGACY: return "INDICATE_LEGACY";

        default: return "UNKNOWN";
    }
}



inline const char8* flagsToString(const DmiProcessorVoltageFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[83];

    FLAGS_TO_STRING(res, flags.flags, flagToString, DmiProcessorVoltageFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiProcessorVoltageFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[83];

    FLAGS_TO_STRING(res, flags.flags, flagToString, DmiProcessorVoltageFlag);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORVOLTAGEFLAGS_H
