#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint64 dmi_bios_characteristics_flags;

enum class DmiBiosCharacteristicsFlag: dmi_bios_characteristics_flags
{
    NONE                               = 0,
    UNKNOWN                            = (1ULL << 2),
    BIOS_CHARACTERISTICS_NOT_SUPPORTED = (1ULL << 3),
    ISA_SUPPORTED                      = (1ULL << 4),
    MCA_SUPPORTED                      = (1ULL << 5),
    EISA_SUPPORTED                     = (1ULL << 6),
    PCI_SUPPORTED                      = (1ULL << 7),
    PCMCIA_SUPPORTED                   = (1ULL << 8),
    PLUG_AND_PLAY_SUPPORTED            = (1ULL << 9),
    APM_SUPPORTED                      = (1ULL << 10),
    BIOS_UPGRADABLE                    = (1ULL << 11),
    BIOS_SHADOWING_ALLOWED             = (1ULL << 12),
    VL_VESA_SUPPORTED                  = (1ULL << 13),
    ESCD_SUPPORT_AVAILABLE             = (1ULL << 14),
    BOOT_FROM_CD_SUPPORTED             = (1ULL << 15),
    SELECTABLE_BOOT_SUPPORTED          = (1ULL << 16),
    BIOS_ROM_SOCKETED                  = (1ULL << 17),
    BOOT_FROM_PCMCIA_SUPPORTED         = (1ULL << 18),
    EDD_SPECIFICATION_SUPPORTED        = (1ULL << 19),
    JAPANESE_NEC_FLOPPY_SUPPORTED      = (1ULL << 20),
    JAPANESE_TOSHIBA_FLOPPY_SUPPORTED  = (1ULL << 21),
    FLOPPY_525_360_SUPPORTED           = (1ULL << 22),
    FLOPPY_525_12_SUPPORTED            = (1ULL << 23),
    FLOPPY_35_720_SUPPORTED            = (1ULL << 24),
    FLOPPY_35_288_SUPPORTED            = (1ULL << 25),
    PRINT_SCREEN_SUPPORTED             = (1ULL << 26),
    KEYBOARD_8042_SUPPORTED            = (1ULL << 27),
    SERIAL_SUPPORTED                   = (1ULL << 28),
    PRINTER_SUPPORTED                  = (1ULL << 29),
    CGA_MONO_SUPPORTED                 = (1ULL << 30),
    NEC_PC_98                          = (1ULL << 31),
    RESERVED                           = (1ULL << 32)
};

DEFINE_FLAGS(DmiBiosCharacteristicsFlags, dmi_bios_characteristics_flags); // TEST: NO



inline const char8* flagToString(DmiBiosCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiBiosCharacteristicsFlag::NONE:                               return "NONE";
        case DmiBiosCharacteristicsFlag::UNKNOWN:                            return "UNKNOWN";
        case DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED: return "BIOS_CHARACTERISTICS_NOT_SUPPORTED";
        case DmiBiosCharacteristicsFlag::ISA_SUPPORTED:                      return "ISA_SUPPORTED";
        case DmiBiosCharacteristicsFlag::MCA_SUPPORTED:                      return "MCA_SUPPORTED";
        case DmiBiosCharacteristicsFlag::EISA_SUPPORTED:                     return "EISA_SUPPORTED";
        case DmiBiosCharacteristicsFlag::PCI_SUPPORTED:                      return "PCI_SUPPORTED";
        case DmiBiosCharacteristicsFlag::PCMCIA_SUPPORTED:                   return "PCMCIA_SUPPORTED";
        case DmiBiosCharacteristicsFlag::PLUG_AND_PLAY_SUPPORTED:            return "PLUG_AND_PLAY_SUPPORTED";
        case DmiBiosCharacteristicsFlag::APM_SUPPORTED:                      return "APM_SUPPORTED";
        case DmiBiosCharacteristicsFlag::BIOS_UPGRADABLE:                    return "BIOS_UPGRADABLE";
        case DmiBiosCharacteristicsFlag::BIOS_SHADOWING_ALLOWED:             return "BIOS_SHADOWING_ALLOWED";
        case DmiBiosCharacteristicsFlag::VL_VESA_SUPPORTED:                  return "VL_VESA_SUPPORTED";
        case DmiBiosCharacteristicsFlag::ESCD_SUPPORT_AVAILABLE:             return "ESCD_SUPPORT_AVAILABLE";
        case DmiBiosCharacteristicsFlag::BOOT_FROM_CD_SUPPORTED:             return "BOOT_FROM_CD_SUPPORTED";
        case DmiBiosCharacteristicsFlag::SELECTABLE_BOOT_SUPPORTED:          return "SELECTABLE_BOOT_SUPPORTED";
        case DmiBiosCharacteristicsFlag::BIOS_ROM_SOCKETED:                  return "BIOS_ROM_SOCKETED";
        case DmiBiosCharacteristicsFlag::BOOT_FROM_PCMCIA_SUPPORTED:         return "BOOT_FROM_PCMCIA_SUPPORTED";
        case DmiBiosCharacteristicsFlag::EDD_SPECIFICATION_SUPPORTED:        return "EDD_SPECIFICATION_SUPPORTED";
        case DmiBiosCharacteristicsFlag::JAPANESE_NEC_FLOPPY_SUPPORTED:      return "JAPANESE_NEC_FLOPPY_SUPPORTED";
        case DmiBiosCharacteristicsFlag::JAPANESE_TOSHIBA_FLOPPY_SUPPORTED:  return "JAPANESE_TOSHIBA_FLOPPY_SUPPORTED";
        case DmiBiosCharacteristicsFlag::FLOPPY_525_360_SUPPORTED:           return "FLOPPY_525_360_SUPPORTED";
        case DmiBiosCharacteristicsFlag::FLOPPY_525_12_SUPPORTED:            return "FLOPPY_525_12_SUPPORTED";
        case DmiBiosCharacteristicsFlag::FLOPPY_35_720_SUPPORTED:            return "FLOPPY_35_720_SUPPORTED";
        case DmiBiosCharacteristicsFlag::FLOPPY_35_288_SUPPORTED:            return "FLOPPY_35_288_SUPPORTED";
        case DmiBiosCharacteristicsFlag::PRINT_SCREEN_SUPPORTED:             return "PRINT_SCREEN_SUPPORTED";
        case DmiBiosCharacteristicsFlag::KEYBOARD_8042_SUPPORTED:            return "KEYBOARD_8042_SUPPORTED";
        case DmiBiosCharacteristicsFlag::SERIAL_SUPPORTED:                   return "SERIAL_SUPPORTED";
        case DmiBiosCharacteristicsFlag::PRINTER_SUPPORTED:                  return "PRINTER_SUPPORTED";
        case DmiBiosCharacteristicsFlag::CGA_MONO_SUPPORTED:                 return "CGA_MONO_SUPPORTED";
        case DmiBiosCharacteristicsFlag::NEC_PC_98:                          return "NEC_PC_98";
        case DmiBiosCharacteristicsFlag::RESERVED:                           return "RESERVED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiBiosCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[56];

    sprintf(res, "0x%016llX (%s)", (dmi_bios_characteristics_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiBiosCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[713];

    FLAGS_TO_STRING(res, flags.flags, DmiBiosCharacteristicsFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiBiosCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[734];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiBiosCharacteristicsFlag, "0x%016llX");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSCHARACTERISTICSFLAGS_H
