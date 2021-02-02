#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSBIOSRESERVEDFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSBIOSRESERVEDFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint8 dmi_bios_characteristics_bios_reserved_flags;

enum class DmiBiosCharacteristicsBiosReservedFlag: dmi_bios_characteristics_bios_reserved_flags
{
    NONE                           = 0,
    ACPI_SUPPORTED                 = (1ULL << 0),
    USB_LEGACY_SUPPORTED           = (1ULL << 1),
    AGP_SUPPORTED                  = (1ULL << 2),
    I2O_BOOT_SUPPORTED             = (1ULL << 3),
    LS120_BOOT_SUPPORTED           = (1ULL << 4),
    ATAPI_ZIP_DRIVE_BOOT_SUPPORTED = (1ULL << 5),
    BOOT_1394_SUPPORTED            = (1ULL << 6),
    SMART_BATTERY_SUPPORTED        = (1ULL << 7)
};

DEFINE_FLAGS(DmiBiosCharacteristicsBiosReservedFlags, dmi_bios_characteristics_bios_reserved_flags); // TEST: NO



inline const char8* flagToString(DmiBiosCharacteristicsBiosReservedFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiBiosCharacteristicsBiosReservedFlag::NONE:                           return "NONE";
        case DmiBiosCharacteristicsBiosReservedFlag::ACPI_SUPPORTED:                 return "ACPI_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::USB_LEGACY_SUPPORTED:           return "USB_LEGACY_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::AGP_SUPPORTED:                  return "AGP_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::I2O_BOOT_SUPPORTED:             return "I2O_BOOT_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::LS120_BOOT_SUPPORTED:           return "LS120_BOOT_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::ATAPI_ZIP_DRIVE_BOOT_SUPPORTED: return "ATAPI_ZIP_DRIVE_BOOT_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::BOOT_1394_SUPPORTED:            return "BOOT_1394_SUPPORTED";
        case DmiBiosCharacteristicsBiosReservedFlag::SMART_BATTERY_SUPPORTED:        return "SMART_BATTERY_SUPPORTED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiBiosCharacteristicsBiosReservedFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%02X (%s)", (dmi_bios_characteristics_bios_reserved_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiBiosCharacteristicsBiosReservedFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[194];

    FLAGS_TO_STRING(res, flags.flags, DmiBiosCharacteristicsBiosReservedFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiBiosCharacteristicsBiosReservedFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[201];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiBiosCharacteristicsBiosReservedFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSBIOSRESERVEDFLAGS_H
