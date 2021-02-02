// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063177_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063177_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063177: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190A81 = 0x10190A81,
    SUBDEVICE_10191841 = 0x10191841,
    SUBDEVICE_1043808C = 0x1043808C,
    SUBDEVICE_104380A1 = 0x104380A1,
    SUBDEVICE_11060000 = 0x11060000,
    SUBDEVICE_1297F641 = 0x1297F641,
    SUBDEVICE_14585001 = 0x14585001,
    SUBDEVICE_18493177 = 0x18493177
};



inline const char8* enumToString(PciSubDevice11063177 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063177::NONE:               return "NONE";
        case PciSubDevice11063177::SUBDEVICE_10190A81: return "SUBDEVICE_10190A81";
        case PciSubDevice11063177::SUBDEVICE_10191841: return "SUBDEVICE_10191841";
        case PciSubDevice11063177::SUBDEVICE_1043808C: return "SUBDEVICE_1043808C";
        case PciSubDevice11063177::SUBDEVICE_104380A1: return "SUBDEVICE_104380A1";
        case PciSubDevice11063177::SUBDEVICE_11060000: return "SUBDEVICE_11060000";
        case PciSubDevice11063177::SUBDEVICE_1297F641: return "SUBDEVICE_1297F641";
        case PciSubDevice11063177::SUBDEVICE_14585001: return "SUBDEVICE_14585001";
        case PciSubDevice11063177::SUBDEVICE_18493177: return "SUBDEVICE_18493177";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063177 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063177 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063177::SUBDEVICE_10190A81: return "L7VTA v1.0 Motherboard (KT400-8235)";
        case PciSubDevice11063177::SUBDEVICE_10191841: return "M811 (VT8367/VT8235/VT6103) [KT333] motherboard";
        case PciSubDevice11063177::SUBDEVICE_1043808C: return "A7V8X motherboard";
        case PciSubDevice11063177::SUBDEVICE_104380A1: return "A7V8X-X motherboard";
        case PciSubDevice11063177::SUBDEVICE_11060000: return "KT4AV motherboard";
        case PciSubDevice11063177::SUBDEVICE_1297F641: return "FX41 motherboard";
        case PciSubDevice11063177::SUBDEVICE_14585001: return "GA-7VAX Mainboard";
        case PciSubDevice11063177::SUBDEVICE_18493177: return "K7VT series Motherboards";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063177_H
