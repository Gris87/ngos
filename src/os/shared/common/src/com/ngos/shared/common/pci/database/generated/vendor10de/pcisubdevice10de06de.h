// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE06DE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE06DE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE06DE: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE0773 = 0x10DE0773,
    SUBDEVICE_10DE082F = 0x10DE082F,
    SUBDEVICE_10DE0840 = 0x10DE0840,
    SUBDEVICE_10DE0842 = 0x10DE0842,
    SUBDEVICE_10DE0846 = 0x10DE0846,
    SUBDEVICE_10DE0866 = 0x10DE0866,
    SUBDEVICE_10DE0907 = 0x10DE0907,
    SUBDEVICE_10DE091E = 0x10DE091E
};



inline const char8* enumToString(PciSubDevice10DE06DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE06DE::NONE:               return "NONE";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0773: return "SUBDEVICE_10DE0773";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE082F: return "SUBDEVICE_10DE082F";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0840: return "SUBDEVICE_10DE0840";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0842: return "SUBDEVICE_10DE0842";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0846: return "SUBDEVICE_10DE0846";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0866: return "SUBDEVICE_10DE0866";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0907: return "SUBDEVICE_10DE0907";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE091E: return "SUBDEVICE_10DE091E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE06DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE06DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0773: return "Tesla S2050";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE082F: return "Tesla M2050";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0840: return "Tesla X2070";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0842: return "Tesla M2050";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0846: return "Tesla M2050";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0866: return "Tesla M2050";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE0907: return "Tesla M2050";
        case PciSubDevice10DE06DE::SUBDEVICE_10DE091E: return "Tesla M2050";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE06DE_H
