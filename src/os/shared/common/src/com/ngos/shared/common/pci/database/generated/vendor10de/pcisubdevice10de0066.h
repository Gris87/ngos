// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0066_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0066_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0066: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380A7 = 0x104380A7,
    SUBDEVICE_10DE0C11 = 0x10DE0C11,
    SUBDEVICE_A0A003B3 = 0xA0A003B3
};



inline const char8* enumToString(PciSubDevice10DE0066 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0066::NONE:               return "NONE";
        case PciSubDevice10DE0066::SUBDEVICE_104380A7: return "SUBDEVICE_104380A7";
        case PciSubDevice10DE0066::SUBDEVICE_10DE0C11: return "SUBDEVICE_10DE0C11";
        case PciSubDevice10DE0066::SUBDEVICE_A0A003B3: return "SUBDEVICE_A0A003B3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0066 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0066 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0066::SUBDEVICE_104380A7: return "A7N8X Mainboard onboard nForce2 Ethernet";
        case PciSubDevice10DE0066::SUBDEVICE_10DE0C11: return "nForce MCP-T Networking Adapter";
        case PciSubDevice10DE0066::SUBDEVICE_A0A003B3: return "UK79G-1394 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0066_H
