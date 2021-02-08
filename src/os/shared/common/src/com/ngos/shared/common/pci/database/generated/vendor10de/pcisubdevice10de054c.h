// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE054C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE054C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE054C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438308 = 0x10438308,
    SUBDEVICE_1849054C = 0x1849054C
};



inline const char8* enumToString(PciSubDevice10DE054C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE054C::NONE:               return "NONE";
        case PciSubDevice10DE054C::SUBDEVICE_10438308: return "SUBDEVICE_10438308";
        case PciSubDevice10DE054C::SUBDEVICE_1849054C: return "SUBDEVICE_1849054C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE054C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE054C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE054C::SUBDEVICE_10438308: return "M2N68-AM Motherboard";
        case PciSubDevice10DE054C::SUBDEVICE_1849054C: return "ALiveNF7G-HDready, MCP67 Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE054C_H
