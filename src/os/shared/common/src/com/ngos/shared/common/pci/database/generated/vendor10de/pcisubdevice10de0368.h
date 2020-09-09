// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0368_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0368_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0368: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020C = 0x1028020C,
    SUBDEVICE_10280221 = 0x10280221,
    SUBDEVICE_147B1C24 = 0x147B1C24
};



inline const char8* enumToString(PciSubDevice10DE0368 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0368::NONE:               return "NONE";
        case PciSubDevice10DE0368::SUBDEVICE_1028020C: return "SUBDEVICE_1028020C";
        case PciSubDevice10DE0368::SUBDEVICE_10280221: return "SUBDEVICE_10280221";
        case PciSubDevice10DE0368::SUBDEVICE_147B1C24: return "SUBDEVICE_147B1C24";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0368 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0368 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0368::SUBDEVICE_1028020C: return "PowerEdge M605 MCP55 SMBus";
        case PciSubDevice10DE0368::SUBDEVICE_10280221: return "PowerEdge R805 MCP55 SMBus";
        case PciSubDevice10DE0368::SUBDEVICE_147B1C24: return "KN9 series mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0368_H
