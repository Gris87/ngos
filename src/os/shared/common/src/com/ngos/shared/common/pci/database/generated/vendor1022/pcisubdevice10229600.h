// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10229600_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10229600_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10229600: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104382EE = 0x104382EE,
    SUBDEVICE_104382F1 = 0x104382F1
};



inline const char8* enumToString(PciSubDevice10229600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10229600::NONE:               return "NONE";
        case PciSubDevice10229600::SUBDEVICE_104382EE: return "SUBDEVICE_104382EE";
        case PciSubDevice10229600::SUBDEVICE_104382F1: return "SUBDEVICE_104382F1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10229600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10229600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10229600::SUBDEVICE_104382EE: return "M378A-CM Motherboard";
        case PciSubDevice10229600::SUBDEVICE_104382F1: return "M3A78-EH Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10229600_H
