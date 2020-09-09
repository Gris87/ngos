// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11036_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11036_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F11036: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D8067 = 0x104D8067,
    SUBDEVICE_122D4029 = 0x122D4029,
    SUBDEVICE_122D4031 = 0x122D4031,
    SUBDEVICE_13E00209 = 0x13E00209,
    SUBDEVICE_13E0020A = 0x13E0020A,
    SUBDEVICE_13E00260 = 0x13E00260,
    SUBDEVICE_13E00270 = 0x13E00270
};



inline const char8* enumToString(PciSubDevice14F11036 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11036::NONE:               return "NONE";
        case PciSubDevice14F11036::SUBDEVICE_104D8067: return "SUBDEVICE_104D8067";
        case PciSubDevice14F11036::SUBDEVICE_122D4029: return "SUBDEVICE_122D4029";
        case PciSubDevice14F11036::SUBDEVICE_122D4031: return "SUBDEVICE_122D4031";
        case PciSubDevice14F11036::SUBDEVICE_13E00209: return "SUBDEVICE_13E00209";
        case PciSubDevice14F11036::SUBDEVICE_13E0020A: return "SUBDEVICE_13E0020A";
        case PciSubDevice14F11036::SUBDEVICE_13E00260: return "SUBDEVICE_13E00260";
        case PciSubDevice14F11036::SUBDEVICE_13E00270: return "SUBDEVICE_13E00270";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F11036 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F11036 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11036::SUBDEVICE_104D8067: return "HCF 56k Modem";
        case PciSubDevice14F11036::SUBDEVICE_122D4029: return "MDP3880SP-W";
        case PciSubDevice14F11036::SUBDEVICE_122D4031: return "MDP3880SP-U";
        case PciSubDevice14F11036::SUBDEVICE_13E00209: return "Dell Titanium";
        case PciSubDevice14F11036::SUBDEVICE_13E0020A: return "Dell Graphite";
        case PciSubDevice14F11036::SUBDEVICE_13E00260: return "Gateway Red Owl";
        case PciSubDevice14F11036::SUBDEVICE_13E00270: return "Gateway White Horse";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11036_H
