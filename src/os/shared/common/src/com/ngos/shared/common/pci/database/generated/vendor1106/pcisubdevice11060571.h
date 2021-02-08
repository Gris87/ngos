// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060571_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060571_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060571: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190985 = 0x10190985,
    SUBDEVICE_10190A81 = 0x10190A81,
    SUBDEVICE_10438052 = 0x10438052,
    SUBDEVICE_1043808C = 0x1043808C,
    SUBDEVICE_104380A1 = 0x104380A1,
    SUBDEVICE_104380ED = 0x104380ED,
    SUBDEVICE_11060571 = 0x11060571,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_1297F641 = 0x1297F641,
    SUBDEVICE_14585002 = 0x14585002,
    SUBDEVICE_14625901 = 0x14625901,
    SUBDEVICE_14627020 = 0x14627020,
    SUBDEVICE_14627094 = 0x14627094,
    SUBDEVICE_14627120 = 0x14627120,
    SUBDEVICE_14627181 = 0x14627181,
    SUBDEVICE_147B1407 = 0x147B1407,
    SUBDEVICE_18490571 = 0x18490571
};



inline const char8* enumToString(PciSubDevice11060571 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060571::NONE:               return "NONE";
        case PciSubDevice11060571::SUBDEVICE_10190985: return "SUBDEVICE_10190985";
        case PciSubDevice11060571::SUBDEVICE_10190A81: return "SUBDEVICE_10190A81";
        case PciSubDevice11060571::SUBDEVICE_10438052: return "SUBDEVICE_10438052";
        case PciSubDevice11060571::SUBDEVICE_1043808C: return "SUBDEVICE_1043808C";
        case PciSubDevice11060571::SUBDEVICE_104380A1: return "SUBDEVICE_104380A1";
        case PciSubDevice11060571::SUBDEVICE_104380ED: return "SUBDEVICE_104380ED";
        case PciSubDevice11060571::SUBDEVICE_11060571: return "SUBDEVICE_11060571";
        case PciSubDevice11060571::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11060571::SUBDEVICE_1297F641: return "SUBDEVICE_1297F641";
        case PciSubDevice11060571::SUBDEVICE_14585002: return "SUBDEVICE_14585002";
        case PciSubDevice11060571::SUBDEVICE_14625901: return "SUBDEVICE_14625901";
        case PciSubDevice11060571::SUBDEVICE_14627020: return "SUBDEVICE_14627020";
        case PciSubDevice11060571::SUBDEVICE_14627094: return "SUBDEVICE_14627094";
        case PciSubDevice11060571::SUBDEVICE_14627120: return "SUBDEVICE_14627120";
        case PciSubDevice11060571::SUBDEVICE_14627181: return "SUBDEVICE_14627181";
        case PciSubDevice11060571::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";
        case PciSubDevice11060571::SUBDEVICE_18490571: return "SUBDEVICE_18490571";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060571 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060571 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060571::SUBDEVICE_10190985: return "P6VXA Motherboard";
        case PciSubDevice11060571::SUBDEVICE_10190A81: return "L7VTA v1.0 Motherboard (KT400-8235)";
        case PciSubDevice11060571::SUBDEVICE_10438052: return "VT8233A Bus Master ATA100/66/33 IDE";
        case PciSubDevice11060571::SUBDEVICE_1043808C: return "A7V8X / A7V333 motherboard";
        case PciSubDevice11060571::SUBDEVICE_104380A1: return "A7V8X-X motherboard rev. 1.01";
        case PciSubDevice11060571::SUBDEVICE_104380ED: return "A7V600/K8V-X/A8V Deluxe motherboard";
        case PciSubDevice11060571::SUBDEVICE_11060571: return "VT82C586/B/VT82C686/A/B/VT8233/A/C/VT8235 PIPC Bus Master IDE";
        case PciSubDevice11060571::SUBDEVICE_11790001: return "Magnia Z310";
        case PciSubDevice11060571::SUBDEVICE_1297F641: return "FX41 motherboard";
        case PciSubDevice11060571::SUBDEVICE_14585002: return "GA-7VAX Mainboard";
        case PciSubDevice11060571::SUBDEVICE_14625901: return "KT6 Delta-FIS2R (MS-6590)";
        case PciSubDevice11060571::SUBDEVICE_14627020: return "K8T NEO 2 motherboard";
        case PciSubDevice11060571::SUBDEVICE_14627094: return "K8T Neo2-F V2.0";
        case PciSubDevice11060571::SUBDEVICE_14627120: return "KT4AV motherboard";
        case PciSubDevice11060571::SUBDEVICE_14627181: return "K8MM3-V mainboard";
        case PciSubDevice11060571::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";
        case PciSubDevice11060571::SUBDEVICE_18490571: return "K7VT series Motherboards";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060571_H
