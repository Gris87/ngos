// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0202_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0202_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0202: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043405B = 0x1043405B,
    SUBDEVICE_1545002F = 0x1545002F
};



inline const char8* enumToString(PciSubDevice10DE0202 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0202::NONE:               return "NONE";
        case PciSubDevice10DE0202::SUBDEVICE_1043405B: return "SUBDEVICE_1043405B";
        case PciSubDevice10DE0202::SUBDEVICE_1545002F: return "SUBDEVICE_1545002F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0202 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0202 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0202::SUBDEVICE_1043405B: return "V8200 T5";
        case PciSubDevice10DE0202::SUBDEVICE_1545002F: return "Xtasy 6964";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0202_H
