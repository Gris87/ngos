#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSSYSTEMRESERVEDFLAGS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSSYSTEMRESERVEDFLAGS_H



#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>



typedef u8 dmi_bios_characteristics_system_reserved_flags;

enum class DmiBiosCharacteristicsSystemReservedFlag: dmi_bios_characteristics_system_reserved_flags
{
    NONE                                = 0,
    BIOS_BOOT_SPECIFICATION_SUPPORTED   = (1ULL << 0),
    FUNCTION_KEY_NETWORK_BOOT_SUPPORTED = (1ULL << 1),
    TARGET_CONTENT_DISTRIBUTION_ENABLED = (1ULL << 2),
    UEFI_SPECIFICATION_SUPPORTED        = (1ULL << 3),
    VIRTUAL_MACHINE_SUPPORTED           = (1ULL << 4)
};

DEFINE_FLAGS(DmiBiosCharacteristicsSystemReservedFlags, dmi_bios_characteristics_system_reserved_flags); // TEST: NO



inline const char8* flagToString(DmiBiosCharacteristicsSystemReservedFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiBiosCharacteristicsSystemReservedFlag::NONE:                                return "NONE";
        case DmiBiosCharacteristicsSystemReservedFlag::BIOS_BOOT_SPECIFICATION_SUPPORTED:   return "BIOS_BOOT_SPECIFICATION_SUPPORTED";
        case DmiBiosCharacteristicsSystemReservedFlag::FUNCTION_KEY_NETWORK_BOOT_SUPPORTED: return "FUNCTION_KEY_NETWORK_BOOT_SUPPORTED";
        case DmiBiosCharacteristicsSystemReservedFlag::TARGET_CONTENT_DISTRIBUTION_ENABLED: return "TARGET_CONTENT_DISTRIBUTION_ENABLED";
        case DmiBiosCharacteristicsSystemReservedFlag::UEFI_SPECIFICATION_SUPPORTED:        return "UEFI_SPECIFICATION_SUPPORTED";
        case DmiBiosCharacteristicsSystemReservedFlag::VIRTUAL_MACHINE_SUPPORTED:           return "VIRTUAL_MACHINE_SUPPORTED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiBiosCharacteristicsSystemReservedFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[43];

    sprintf(res, "0x%02X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiBiosCharacteristicsSystemReservedFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[184];

    FLAGS_TO_STRING(res, flags.flags, DmiBiosCharacteristicsSystemReservedFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiBiosCharacteristicsSystemReservedFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[191];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiBiosCharacteristicsSystemReservedFlag, "0x%02X");

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSSYSTEMRESERVEDFLAGS_H
