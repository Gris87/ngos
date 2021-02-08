// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024757_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024757_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024757: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10024757 = 0x10024757,
    SUBDEVICE_10280089 = 0x10280089,
    SUBDEVICE_1028008E = 0x1028008E,
    SUBDEVICE_10284082 = 0x10284082,
    SUBDEVICE_10288082 = 0x10288082,
    SUBDEVICE_1028C082 = 0x1028C082
};



inline const char8* enumToString(PciSubDevice10024757 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024757::NONE:               return "NONE";
        case PciSubDevice10024757::SUBDEVICE_10024757: return "SUBDEVICE_10024757";
        case PciSubDevice10024757::SUBDEVICE_10280089: return "SUBDEVICE_10280089";
        case PciSubDevice10024757::SUBDEVICE_1028008E: return "SUBDEVICE_1028008E";
        case PciSubDevice10024757::SUBDEVICE_10284082: return "SUBDEVICE_10284082";
        case PciSubDevice10024757::SUBDEVICE_10288082: return "SUBDEVICE_10288082";
        case PciSubDevice10024757::SUBDEVICE_1028C082: return "SUBDEVICE_1028C082";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024757 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024757 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024757::SUBDEVICE_10024757: return "Rage IIC AGP";
        case PciSubDevice10024757::SUBDEVICE_10280089: return "Rage 3D IIC";
        case PciSubDevice10024757::SUBDEVICE_1028008E: return "PowerEdge 1300 onboard video";
        case PciSubDevice10024757::SUBDEVICE_10284082: return "Rage 3D IIC";
        case PciSubDevice10024757::SUBDEVICE_10288082: return "Rage 3D IIC";
        case PciSubDevice10024757::SUBDEVICE_1028C082: return "Rage 3D IIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024757_H
