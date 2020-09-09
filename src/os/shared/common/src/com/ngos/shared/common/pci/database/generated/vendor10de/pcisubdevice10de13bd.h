// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE13BD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE13BD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE13BD: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE110A = 0x10DE110A,
    SUBDEVICE_10DE1160 = 0x10DE1160,
    SUBDEVICE_10DE11D2 = 0x10DE11D2
};



inline const char8* enumToString(PciSubDevice10DE13BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE13BD::NONE:               return "NONE";
        case PciSubDevice10DE13BD::SUBDEVICE_10DE110A: return "SUBDEVICE_10DE110A";
        case PciSubDevice10DE13BD::SUBDEVICE_10DE1160: return "SUBDEVICE_10DE1160";
        case PciSubDevice10DE13BD::SUBDEVICE_10DE11D2: return "SUBDEVICE_10DE11D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE13BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE13BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE13BD::SUBDEVICE_10DE110A: return "GRID M40";
        case PciSubDevice10DE13BD::SUBDEVICE_10DE1160: return "Tesla M10";
        case PciSubDevice10DE13BD::SUBDEVICE_10DE11D2: return "GRID M10-8Q";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE13BD_H
