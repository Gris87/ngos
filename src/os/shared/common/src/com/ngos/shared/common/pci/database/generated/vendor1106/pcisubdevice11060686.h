// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060686_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060686_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060686: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190985 = 0x10190985,
    SUBDEVICE_103C1256 = 0x103C1256,
    SUBDEVICE_1043802C = 0x1043802C,
    SUBDEVICE_10438033 = 0x10438033,
    SUBDEVICE_1043803E = 0x1043803E,
    SUBDEVICE_10438040 = 0x10438040,
    SUBDEVICE_10438042 = 0x10438042,
    SUBDEVICE_11060000 = 0x11060000,
    SUBDEVICE_11060686 = 0x11060686,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_147BA702 = 0x147BA702
};



inline const char8* enumToString(PciSubDevice11060686 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060686::NONE:               return "NONE";
        case PciSubDevice11060686::SUBDEVICE_10190985: return "SUBDEVICE_10190985";
        case PciSubDevice11060686::SUBDEVICE_103C1256: return "SUBDEVICE_103C1256";
        case PciSubDevice11060686::SUBDEVICE_1043802C: return "SUBDEVICE_1043802C";
        case PciSubDevice11060686::SUBDEVICE_10438033: return "SUBDEVICE_10438033";
        case PciSubDevice11060686::SUBDEVICE_1043803E: return "SUBDEVICE_1043803E";
        case PciSubDevice11060686::SUBDEVICE_10438040: return "SUBDEVICE_10438040";
        case PciSubDevice11060686::SUBDEVICE_10438042: return "SUBDEVICE_10438042";
        case PciSubDevice11060686::SUBDEVICE_11060000: return "SUBDEVICE_11060000";
        case PciSubDevice11060686::SUBDEVICE_11060686: return "SUBDEVICE_11060686";
        case PciSubDevice11060686::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11060686::SUBDEVICE_147BA702: return "SUBDEVICE_147BA702";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060686 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060686 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060686::SUBDEVICE_10190985: return "P6VXA Motherboard";
        case PciSubDevice11060686::SUBDEVICE_103C1256: return "D9840-60001 [Brio BA410 Motherboard]";
        case PciSubDevice11060686::SUBDEVICE_1043802C: return "CUV4X mainboard";
        case PciSubDevice11060686::SUBDEVICE_10438033: return "A7V Mainboard";
        case PciSubDevice11060686::SUBDEVICE_1043803E: return "A7V-E Mainboard";
        case PciSubDevice11060686::SUBDEVICE_10438040: return "A7M266 Mainboard";
        case PciSubDevice11060686::SUBDEVICE_10438042: return "A7V133/A7V133-C Mainboard";
        case PciSubDevice11060686::SUBDEVICE_11060000: return "VT82C686/A PCI to ISA Bridge";
        case PciSubDevice11060686::SUBDEVICE_11060686: return "VT82C686/A PCI to ISA Bridge";
        case PciSubDevice11060686::SUBDEVICE_11790001: return "Magnia Z310";
        case PciSubDevice11060686::SUBDEVICE_147BA702: return "KG7-Lite Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060686_H
