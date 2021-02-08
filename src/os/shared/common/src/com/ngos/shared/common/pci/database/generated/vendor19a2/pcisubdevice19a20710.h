// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20710_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20710_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19A20710: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101403D0 = 0x101403D0,
    SUBDEVICE_101403D1 = 0x101403D1,
    SUBDEVICE_10140409 = 0x10140409,
    SUBDEVICE_1014040A = 0x1014040A,
    SUBDEVICE_103C3315 = 0x103C3315,
    SUBDEVICE_103C3340 = 0x103C3340,
    SUBDEVICE_103C3341 = 0x103C3341,
    SUBDEVICE_103C3345 = 0x103C3345,
    SUBDEVICE_103C337B = 0x103C337B,
    SUBDEVICE_10DFE733 = 0x10DFE733
};



inline const char8* enumToString(PciSubDevice19A20710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20710::NONE:               return "NONE";
        case PciSubDevice19A20710::SUBDEVICE_101403D0: return "SUBDEVICE_101403D0";
        case PciSubDevice19A20710::SUBDEVICE_101403D1: return "SUBDEVICE_101403D1";
        case PciSubDevice19A20710::SUBDEVICE_10140409: return "SUBDEVICE_10140409";
        case PciSubDevice19A20710::SUBDEVICE_1014040A: return "SUBDEVICE_1014040A";
        case PciSubDevice19A20710::SUBDEVICE_103C3315: return "SUBDEVICE_103C3315";
        case PciSubDevice19A20710::SUBDEVICE_103C3340: return "SUBDEVICE_103C3340";
        case PciSubDevice19A20710::SUBDEVICE_103C3341: return "SUBDEVICE_103C3341";
        case PciSubDevice19A20710::SUBDEVICE_103C3345: return "SUBDEVICE_103C3345";
        case PciSubDevice19A20710::SUBDEVICE_103C337B: return "SUBDEVICE_103C337B";
        case PciSubDevice19A20710::SUBDEVICE_10DFE733: return "SUBDEVICE_10DFE733";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19A20710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19A20710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20710::SUBDEVICE_101403D0: return "PCIe2 2-port 10GbE SR Adapter for POWER";
        case PciSubDevice19A20710::SUBDEVICE_101403D1: return "PCIe2 2-port 10GbE SFP+ Copper Adapter for POWER";
        case PciSubDevice19A20710::SUBDEVICE_10140409: return "Integrated Multifunction Card with Dual 10GbE SR Optical + Dual 1GbE for Power 750/760";
        case PciSubDevice19A20710::SUBDEVICE_1014040A: return "Integrated Multifunction Card with Dual 10GbE SR Copper + Dual 1GbE for Power 750/760";
        case PciSubDevice19A20710::SUBDEVICE_103C3315: return "NC553i 10Gb 2-port FlexFabric Converged Network Adapter";
        case PciSubDevice19A20710::SUBDEVICE_103C3340: return "NC552SFP 2-port 10Gb Server Adapter";
        case PciSubDevice19A20710::SUBDEVICE_103C3341: return "NC552m 10Gb 2-port FlexFabric Converged Network Adapter";
        case PciSubDevice19A20710::SUBDEVICE_103C3345: return "NC553m 10Gb 2-port FlexFabric Converged Network Adapter";
        case PciSubDevice19A20710::SUBDEVICE_103C337B: return "NC554FLB 10Gb 2-port FlexFabric Converged Network Adapter";
        case PciSubDevice19A20710::SUBDEVICE_10DFE733: return "Flex System EN4054 4-port 10Gb Ethernet Mezzanine Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20710_H
