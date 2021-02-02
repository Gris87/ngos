// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139730B1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139730B1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice139730B1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_139730B1 = 0x139730B1,
    SUBDEVICE_1397B523 = 0x1397B523,
    SUBDEVICE_1397B543 = 0x1397B543,
    SUBDEVICE_1397B544 = 0x1397B544,
    SUBDEVICE_1397B553 = 0x1397B553,
    SUBDEVICE_1397B554 = 0x1397B554,
    SUBDEVICE_1397B555 = 0x1397B555,
    SUBDEVICE_1397B55A = 0x1397B55A,
    SUBDEVICE_1397B563 = 0x1397B563,
    SUBDEVICE_1397B564 = 0x1397B564,
    SUBDEVICE_1397B565 = 0x1397B565,
    SUBDEVICE_1397B56A = 0x1397B56A
};



inline const char8* enumToString(PciSubDevice139730B1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice139730B1::NONE:               return "NONE";
        case PciSubDevice139730B1::SUBDEVICE_139730B1: return "SUBDEVICE_139730B1";
        case PciSubDevice139730B1::SUBDEVICE_1397B523: return "SUBDEVICE_1397B523";
        case PciSubDevice139730B1::SUBDEVICE_1397B543: return "SUBDEVICE_1397B543";
        case PciSubDevice139730B1::SUBDEVICE_1397B544: return "SUBDEVICE_1397B544";
        case PciSubDevice139730B1::SUBDEVICE_1397B553: return "SUBDEVICE_1397B553";
        case PciSubDevice139730B1::SUBDEVICE_1397B554: return "SUBDEVICE_1397B554";
        case PciSubDevice139730B1::SUBDEVICE_1397B555: return "SUBDEVICE_1397B555";
        case PciSubDevice139730B1::SUBDEVICE_1397B55A: return "SUBDEVICE_1397B55A";
        case PciSubDevice139730B1::SUBDEVICE_1397B563: return "SUBDEVICE_1397B563";
        case PciSubDevice139730B1::SUBDEVICE_1397B564: return "SUBDEVICE_1397B564";
        case PciSubDevice139730B1::SUBDEVICE_1397B565: return "SUBDEVICE_1397B565";
        case PciSubDevice139730B1::SUBDEVICE_1397B56A: return "SUBDEVICE_1397B56A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice139730B1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice139730B1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice139730B1::SUBDEVICE_139730B1: return "HFC-E1 [Cologne Chip HFC-E1 Eval. Board]";
        case PciSubDevice139730B1::SUBDEVICE_1397B523: return "HFC-E1 [IOB1E1]";
        case PciSubDevice139730B1::SUBDEVICE_1397B543: return "HFC-E1 [Swyx SX2 SinglePRI V2]";
        case PciSubDevice139730B1::SUBDEVICE_1397B544: return "HFC-E1 [Swyx SX2 DualPRI V2]";
        case PciSubDevice139730B1::SUBDEVICE_1397B553: return "HFC-E1 [Junghanns.NET singleE1]";
        case PciSubDevice139730B1::SUBDEVICE_1397B554: return "HFC-E1 [Junghanns.NET doubleE1]";
        case PciSubDevice139730B1::SUBDEVICE_1397B555: return "HFC-E1 [Junghanns.NET doubleE1 2.0]";
        case PciSubDevice139730B1::SUBDEVICE_1397B55A: return "HFC-E1 [Junghanns.NET singleE1 miniPCI]";
        case PciSubDevice139730B1::SUBDEVICE_1397B563: return "HFC-E1 [beroNet BN1E1]";
        case PciSubDevice139730B1::SUBDEVICE_1397B564: return "HFC-E1 [beroNet BN2E1]";
        case PciSubDevice139730B1::SUBDEVICE_1397B565: return "HFC-E1 [beroNet BN2E1+]";
        case PciSubDevice139730B1::SUBDEVICE_1397B56A: return "HFC-E1 [beroNet BN1E1 miniPCI]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139730B1_H
