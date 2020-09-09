// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771654_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771654_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10771654: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770032 = 0x10770032,
    SUBDEVICE_15900223 = 0x15900223,
    SUBDEVICE_15900287 = 0x15900287
};



inline const char8* enumToString(PciSubDevice10771654 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771654::NONE:               return "NONE";
        case PciSubDevice10771654::SUBDEVICE_10770032: return "SUBDEVICE_10770032";
        case PciSubDevice10771654::SUBDEVICE_15900223: return "SUBDEVICE_15900223";
        case PciSubDevice10771654::SUBDEVICE_15900287: return "SUBDEVICE_15900287";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10771654 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10771654 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771654::SUBDEVICE_10770032: return "QL45212 Flex 50Gb 2-port Ethernet Adapter";
        case PciSubDevice10771654::SUBDEVICE_15900223: return "Synergy 6810C 25/50Gb Ethernet Adapter";
        case PciSubDevice10771654::SUBDEVICE_15900287: return "Synergy 6820C 25/50Gb CNA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771654_H
