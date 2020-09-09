// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029495_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029495_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029495: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020028 = 0x10020028,
    SUBDEVICE_10920028 = 0x10920028,
    SUBDEVICE_14580028 = 0x14580028,
    SUBDEVICE_16820028 = 0x16820028,
    SUBDEVICE_174B0028 = 0x174B0028
};



inline const char8* enumToString(PciSubDevice10029495 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029495::NONE:               return "NONE";
        case PciSubDevice10029495::SUBDEVICE_10020028: return "SUBDEVICE_10020028";
        case PciSubDevice10029495::SUBDEVICE_10920028: return "SUBDEVICE_10920028";
        case PciSubDevice10029495::SUBDEVICE_14580028: return "SUBDEVICE_14580028";
        case PciSubDevice10029495::SUBDEVICE_16820028: return "SUBDEVICE_16820028";
        case PciSubDevice10029495::SUBDEVICE_174B0028: return "SUBDEVICE_174B0028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029495 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029495 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029495::SUBDEVICE_10020028: return "Radeon HD 4650/4670 AGP";
        case PciSubDevice10029495::SUBDEVICE_10920028: return "Radeon HD 4670 AGP 512MB DDR2";
        case PciSubDevice10029495::SUBDEVICE_14580028: return "Radeon HD 4650 AGP";
        case PciSubDevice10029495::SUBDEVICE_16820028: return "Radeon HD 4650 AGP";
        case PciSubDevice10029495::SUBDEVICE_174B0028: return "Radeon HD 4650 AGP DDR2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029495_H
