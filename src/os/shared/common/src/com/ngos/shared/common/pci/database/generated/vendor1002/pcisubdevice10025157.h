// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025157_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025157_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025157: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002013A = 0x1002013A,
    SUBDEVICE_10020F2B = 0x10020F2B,
    SUBDEVICE_1002103A = 0x1002103A,
    SUBDEVICE_14584000 = 0x14584000,
    SUBDEVICE_148C2024 = 0x148C2024,
    SUBDEVICE_148C2025 = 0x148C2025,
    SUBDEVICE_148C2036 = 0x148C2036,
    SUBDEVICE_174B7146 = 0x174B7146,
    SUBDEVICE_174B7147 = 0x174B7147,
    SUBDEVICE_174B7161 = 0x174B7161,
    SUBDEVICE_17AF0202 = 0x17AF0202
};



inline const char8* enumToString(PciSubDevice10025157 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025157::NONE:               return "NONE";
        case PciSubDevice10025157::SUBDEVICE_1002013A: return "SUBDEVICE_1002013A";
        case PciSubDevice10025157::SUBDEVICE_10020F2B: return "SUBDEVICE_10020F2B";
        case PciSubDevice10025157::SUBDEVICE_1002103A: return "SUBDEVICE_1002103A";
        case PciSubDevice10025157::SUBDEVICE_14584000: return "SUBDEVICE_14584000";
        case PciSubDevice10025157::SUBDEVICE_148C2024: return "SUBDEVICE_148C2024";
        case PciSubDevice10025157::SUBDEVICE_148C2025: return "SUBDEVICE_148C2025";
        case PciSubDevice10025157::SUBDEVICE_148C2036: return "SUBDEVICE_148C2036";
        case PciSubDevice10025157::SUBDEVICE_174B7146: return "SUBDEVICE_174B7146";
        case PciSubDevice10025157::SUBDEVICE_174B7147: return "SUBDEVICE_174B7147";
        case PciSubDevice10025157::SUBDEVICE_174B7161: return "SUBDEVICE_174B7161";
        case PciSubDevice10025157::SUBDEVICE_17AF0202: return "SUBDEVICE_17AF0202";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025157 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025157 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025157::SUBDEVICE_1002013A: return "Radeon 7500";
        case PciSubDevice10025157::SUBDEVICE_10020F2B: return "ALL-IN-WONDER VE PCI";
        case PciSubDevice10025157::SUBDEVICE_1002103A: return "Dell Optiplex GX260";
        case PciSubDevice10025157::SUBDEVICE_14584000: return "RV200 QW [RADEON 7500 PRO MAYA AR]";
        case PciSubDevice10025157::SUBDEVICE_148C2024: return "RV200 QW [Radeon 7500LE Dual Display]";
        case PciSubDevice10025157::SUBDEVICE_148C2025: return "RV200 QW [Radeon 7500 Evil Master Multi Display Edition]";
        case PciSubDevice10025157::SUBDEVICE_148C2036: return "RV200 QW [Radeon 7500 PCI Dual Display]";
        case PciSubDevice10025157::SUBDEVICE_174B7146: return "RV200 QW [Radeon 7500 LE]";
        case PciSubDevice10025157::SUBDEVICE_174B7147: return "Radeon 7500 LE";
        case PciSubDevice10025157::SUBDEVICE_174B7161: return "Radeon RV200 QW [Radeon 7500 LE]";
        case PciSubDevice10025157::SUBDEVICE_17AF0202: return "RV200 QW [Excalibur Radeon 7500LE]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025157_H
