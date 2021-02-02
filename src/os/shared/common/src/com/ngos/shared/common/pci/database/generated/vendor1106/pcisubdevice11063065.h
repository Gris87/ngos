// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063065_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063065_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063065: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380A1 = 0x104380A1,
    SUBDEVICE_104380ED = 0x104380ED,
    SUBDEVICE_11060102 = 0x11060102,
    SUBDEVICE_11861400 = 0x11861400,
    SUBDEVICE_11861401 = 0x11861401,
    SUBDEVICE_11861402 = 0x11861402,
    SUBDEVICE_13B91421 = 0x13B91421,
    SUBDEVICE_14627061 = 0x14627061,
    SUBDEVICE_14627181 = 0x14627181,
    SUBDEVICE_147B1C09 = 0x147B1C09,
    SUBDEVICE_16953005 = 0x16953005,
    SUBDEVICE_18493065 = 0x18493065
};



inline const char8* enumToString(PciSubDevice11063065 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063065::NONE:               return "NONE";
        case PciSubDevice11063065::SUBDEVICE_104380A1: return "SUBDEVICE_104380A1";
        case PciSubDevice11063065::SUBDEVICE_104380ED: return "SUBDEVICE_104380ED";
        case PciSubDevice11063065::SUBDEVICE_11060102: return "SUBDEVICE_11060102";
        case PciSubDevice11063065::SUBDEVICE_11861400: return "SUBDEVICE_11861400";
        case PciSubDevice11063065::SUBDEVICE_11861401: return "SUBDEVICE_11861401";
        case PciSubDevice11063065::SUBDEVICE_11861402: return "SUBDEVICE_11861402";
        case PciSubDevice11063065::SUBDEVICE_13B91421: return "SUBDEVICE_13B91421";
        case PciSubDevice11063065::SUBDEVICE_14627061: return "SUBDEVICE_14627061";
        case PciSubDevice11063065::SUBDEVICE_14627181: return "SUBDEVICE_14627181";
        case PciSubDevice11063065::SUBDEVICE_147B1C09: return "SUBDEVICE_147B1C09";
        case PciSubDevice11063065::SUBDEVICE_16953005: return "SUBDEVICE_16953005";
        case PciSubDevice11063065::SUBDEVICE_18493065: return "SUBDEVICE_18493065";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063065 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063065 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063065::SUBDEVICE_104380A1: return "A7V8X-X Motherboard";
        case PciSubDevice11063065::SUBDEVICE_104380ED: return "A7V600-X Motherboard";
        case PciSubDevice11063065::SUBDEVICE_11060102: return "VT6102/6103 [Rhine II] Ethernet Controller";
        case PciSubDevice11063065::SUBDEVICE_11861400: return "DFE-530TX PCI Fast Ethernet Adapter (rev. A)";
        case PciSubDevice11063065::SUBDEVICE_11861401: return "DFE-530TX PCI Fast Ethernet Adapter (rev. B)";
        case PciSubDevice11063065::SUBDEVICE_11861402: return "DFE-530TX PCI Fast Ethernet Adapter (rev. B)";
        case PciSubDevice11063065::SUBDEVICE_13B91421: return "LD-10/100AL PCI Fast Ethernet Adapter (rev.B)";
        case PciSubDevice11063065::SUBDEVICE_14627061: return "MS-7061";
        case PciSubDevice11063065::SUBDEVICE_14627181: return "K8MM3-V mainboard";
        case PciSubDevice11063065::SUBDEVICE_147B1C09: return "NV7 Motherboard";
        case PciSubDevice11063065::SUBDEVICE_16953005: return "VT6103";
        case PciSubDevice11063065::SUBDEVICE_18493065: return "K7VT series Motherboards";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063065_H
