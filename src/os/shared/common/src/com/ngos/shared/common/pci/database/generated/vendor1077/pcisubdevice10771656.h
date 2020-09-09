// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771656_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771656_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10771656: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770033 = 0x10770033,
    SUBDEVICE_107702A7 = 0x107702A7,
    SUBDEVICE_1077E4F6 = 0x1077E4F6,
    SUBDEVICE_1077E4F7 = 0x1077E4F7,
    SUBDEVICE_15900245 = 0x15900245
};



inline const char8* enumToString(PciSubDevice10771656 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771656::NONE:               return "NONE";
        case PciSubDevice10771656::SUBDEVICE_10770033: return "SUBDEVICE_10770033";
        case PciSubDevice10771656::SUBDEVICE_107702A7: return "SUBDEVICE_107702A7";
        case PciSubDevice10771656::SUBDEVICE_1077E4F6: return "SUBDEVICE_1077E4F6";
        case PciSubDevice10771656::SUBDEVICE_1077E4F7: return "SUBDEVICE_1077E4F7";
        case PciSubDevice10771656::SUBDEVICE_15900245: return "SUBDEVICE_15900245";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10771656 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10771656 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771656::SUBDEVICE_10770033: return "QL45214 Flex 25Gb 4-port Ethernet Adapter";
        case PciSubDevice10771656::SUBDEVICE_107702A7: return "QL45212-DE 25GbE Adapter";
        case PciSubDevice10771656::SUBDEVICE_1077E4F6: return "FastLinQ QL45211H 25GbE Adapter";
        case PciSubDevice10771656::SUBDEVICE_1077E4F7: return "FastLinQ QL45212H 25GbE Adapter";
        case PciSubDevice10771656::SUBDEVICE_15900245: return "10/20/25GbE 2P 4820c CNA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771656_H
