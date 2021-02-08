// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE1077165C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE1077165C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1077165C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770034 = 0x10770034,
    SUBDEVICE_1077E4F1 = 0x1077E4F1,
    SUBDEVICE_1077E4F2 = 0x1077E4F2,
    SUBDEVICE_15900245 = 0x15900245
};



inline const char8* enumToString(PciSubDevice1077165C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1077165C::NONE:               return "NONE";
        case PciSubDevice1077165C::SUBDEVICE_10770034: return "SUBDEVICE_10770034";
        case PciSubDevice1077165C::SUBDEVICE_1077E4F1: return "SUBDEVICE_1077E4F1";
        case PciSubDevice1077165C::SUBDEVICE_1077E4F2: return "SUBDEVICE_1077E4F2";
        case PciSubDevice1077165C::SUBDEVICE_15900245: return "SUBDEVICE_15900245";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1077165C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1077165C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1077165C::SUBDEVICE_10770034: return "QL45262 Flex 50Gb 2-port Ethernet Adapter w/ iSCSI/FCoE";
        case PciSubDevice1077165C::SUBDEVICE_1077E4F1: return "FastLinQ QL45462H 40GbE FCoE Adapter";
        case PciSubDevice1077165C::SUBDEVICE_1077E4F2: return "FastLinQ QL45461H 40GbE FCoE Adapter";
        case PciSubDevice1077165C::SUBDEVICE_15900245: return "10/20/25GbE 2P 4820c CNA FCoE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE1077165C_H
