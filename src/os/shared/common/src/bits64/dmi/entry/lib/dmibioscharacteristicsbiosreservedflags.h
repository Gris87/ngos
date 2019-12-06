#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSBIOSRESERVEDFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSBIOSRESERVEDFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u8 dmi_bios_characteristics_bios_reserved_flags;

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



inline const char8* dmiBiosCharacteristicsBiosReservedFlagToString(DmiBiosCharacteristicsBiosReservedFlag flag) // TEST: NO
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



inline const char8* dmiBiosCharacteristicsBiosReservedFlagsToString(dmi_bios_characteristics_bios_reserved_flags flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char8 res[194];

    FLAGS_TO_STRING(res, flags, dmiBiosCharacteristicsBiosReservedFlagToString, DmiBiosCharacteristicsBiosReservedFlag);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSBIOSRESERVEDFLAGS_H