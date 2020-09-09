// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063038_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063038_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063038: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_09251234 = 0x09251234,
    SUBDEVICE_10190985 = 0x10190985,
    SUBDEVICE_10190A81 = 0x10190A81,
    SUBDEVICE_10438080 = 0x10438080,
    SUBDEVICE_1043808C = 0x1043808C,
    SUBDEVICE_104380A1 = 0x104380A1,
    SUBDEVICE_104380ED = 0x104380ED,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_14585004 = 0x14585004,
    SUBDEVICE_14625901 = 0x14625901,
    SUBDEVICE_14627020 = 0x14627020,
    SUBDEVICE_14627094 = 0x14627094,
    SUBDEVICE_14627120 = 0x14627120,
    SUBDEVICE_14627181 = 0x14627181,
    SUBDEVICE_147B1407 = 0x147B1407,
    SUBDEVICE_182D201D = 0x182D201D,
    SUBDEVICE_18493038 = 0x18493038,
    SUBDEVICE_19DAA179 = 0x19DAA179,
    SUBDEVICE_1AF41100 = 0x1AF41100
};



inline const char8* enumToString(PciSubDevice11063038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063038::NONE:               return "NONE";
        case PciSubDevice11063038::SUBDEVICE_09251234: return "SUBDEVICE_09251234";
        case PciSubDevice11063038::SUBDEVICE_10190985: return "SUBDEVICE_10190985";
        case PciSubDevice11063038::SUBDEVICE_10190A81: return "SUBDEVICE_10190A81";
        case PciSubDevice11063038::SUBDEVICE_10438080: return "SUBDEVICE_10438080";
        case PciSubDevice11063038::SUBDEVICE_1043808C: return "SUBDEVICE_1043808C";
        case PciSubDevice11063038::SUBDEVICE_104380A1: return "SUBDEVICE_104380A1";
        case PciSubDevice11063038::SUBDEVICE_104380ED: return "SUBDEVICE_104380ED";
        case PciSubDevice11063038::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11063038::SUBDEVICE_14585004: return "SUBDEVICE_14585004";
        case PciSubDevice11063038::SUBDEVICE_14625901: return "SUBDEVICE_14625901";
        case PciSubDevice11063038::SUBDEVICE_14627020: return "SUBDEVICE_14627020";
        case PciSubDevice11063038::SUBDEVICE_14627094: return "SUBDEVICE_14627094";
        case PciSubDevice11063038::SUBDEVICE_14627120: return "SUBDEVICE_14627120";
        case PciSubDevice11063038::SUBDEVICE_14627181: return "SUBDEVICE_14627181";
        case PciSubDevice11063038::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";
        case PciSubDevice11063038::SUBDEVICE_182D201D: return "SUBDEVICE_182D201D";
        case PciSubDevice11063038::SUBDEVICE_18493038: return "SUBDEVICE_18493038";
        case PciSubDevice11063038::SUBDEVICE_19DAA179: return "SUBDEVICE_19DAA179";
        case PciSubDevice11063038::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063038::SUBDEVICE_09251234: return "onboard UHCI USB 1.1 Controller";
        case PciSubDevice11063038::SUBDEVICE_10190985: return "P6VXA Motherboard";
        case PciSubDevice11063038::SUBDEVICE_10190A81: return "L7VTA v1.0 Motherboard (KT400-8235)";
        case PciSubDevice11063038::SUBDEVICE_10438080: return "A7V333 motherboard";
        case PciSubDevice11063038::SUBDEVICE_1043808C: return "VT6202 USB2.0 4 port controller";
        case PciSubDevice11063038::SUBDEVICE_104380A1: return "A7V8X-X motherboard";
        case PciSubDevice11063038::SUBDEVICE_104380ED: return "A7V600/K8V-X/A8V Deluxe motherboard";
        case PciSubDevice11063038::SUBDEVICE_11790001: return "Magnia Z310";
        case PciSubDevice11063038::SUBDEVICE_14585004: return "GA-7VAX Mainboard";
        case PciSubDevice11063038::SUBDEVICE_14625901: return "KT6 Delta-FIS2R (MS-6590)";
        case PciSubDevice11063038::SUBDEVICE_14627020: return "K8T NEO 2 motherboard";
        case PciSubDevice11063038::SUBDEVICE_14627094: return "K8T Neo2-F V2.0";
        case PciSubDevice11063038::SUBDEVICE_14627120: return "KT4AV motherboard";
        case PciSubDevice11063038::SUBDEVICE_14627181: return "K8MM3-V mainboard";
        case PciSubDevice11063038::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";
        case PciSubDevice11063038::SUBDEVICE_182D201D: return "CN-029 USB2.0 4 port PCI Card";
        case PciSubDevice11063038::SUBDEVICE_18493038: return "K7VT series Motherboards";
        case PciSubDevice11063038::SUBDEVICE_19DAA179: return "ZBOX nano VD01";
        case PciSubDevice11063038::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063038_H
