// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B97101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B97101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B97101: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140510 = 0x10140510,
    SUBDEVICE_1014053C = 0x1014053C,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_103C0025 = 0x103C0025,
    SUBDEVICE_18497101 = 0x18497101
};



inline const char8* enumToString(PciSubDevice10B97101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B97101::NONE:               return "NONE";
        case PciSubDevice10B97101::SUBDEVICE_10140510: return "SUBDEVICE_10140510";
        case PciSubDevice10B97101::SUBDEVICE_1014053C: return "SUBDEVICE_1014053C";
        case PciSubDevice10B97101::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice10B97101::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";
        case PciSubDevice10B97101::SUBDEVICE_18497101: return "SUBDEVICE_18497101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B97101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B97101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B97101::SUBDEVICE_10140510: return "ThinkPad R30";
        case PciSubDevice10B97101::SUBDEVICE_1014053C: return "ThinkPad R40e";
        case PciSubDevice10B97101::SUBDEVICE_103C0024: return "Pavilion ze4400";
        case PciSubDevice10B97101::SUBDEVICE_103C0025: return "XE4500 Notebook";
        case PciSubDevice10B97101::SUBDEVICE_18497101: return "ASRock 939Dual-SATA2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B97101_H
