// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862934_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862934_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862934: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_1028020F = 0x1028020F,
    SUBDEVICE_10280210 = 0x10280210,
    SUBDEVICE_10280211 = 0x10280211,
    SUBDEVICE_10280235 = 0x10280235,
    SUBDEVICE_10280236 = 0x10280236,
    SUBDEVICE_10280237 = 0x10280237,
    SUBDEVICE_1028023C = 0x1028023C,
    SUBDEVICE_10280287 = 0x10280287,
    SUBDEVICE_1028029C = 0x1028029C,
    SUBDEVICE_10282011 = 0x10282011,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_10438277 = 0x10438277,
    SUBDEVICE_14627345 = 0x14627345,
    SUBDEVICE_14627360 = 0x14627360,
    SUBDEVICE_17AA20F0 = 0x17AA20F0,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_80865044 = 0x80865044,
    SUBDEVICE_E4BFCC4D = 0xE4BFCC4D
};



inline const char8* enumToString(PciSubDevice80862934 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862934::NONE:               return "NONE";
        case PciSubDevice80862934::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice80862934::SUBDEVICE_1028020F: return "SUBDEVICE_1028020F";
        case PciSubDevice80862934::SUBDEVICE_10280210: return "SUBDEVICE_10280210";
        case PciSubDevice80862934::SUBDEVICE_10280211: return "SUBDEVICE_10280211";
        case PciSubDevice80862934::SUBDEVICE_10280235: return "SUBDEVICE_10280235";
        case PciSubDevice80862934::SUBDEVICE_10280236: return "SUBDEVICE_10280236";
        case PciSubDevice80862934::SUBDEVICE_10280237: return "SUBDEVICE_10280237";
        case PciSubDevice80862934::SUBDEVICE_1028023C: return "SUBDEVICE_1028023C";
        case PciSubDevice80862934::SUBDEVICE_10280287: return "SUBDEVICE_10280287";
        case PciSubDevice80862934::SUBDEVICE_1028029C: return "SUBDEVICE_1028029C";
        case PciSubDevice80862934::SUBDEVICE_10282011: return "SUBDEVICE_10282011";
        case PciSubDevice80862934::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice80862934::SUBDEVICE_10438277: return "SUBDEVICE_10438277";
        case PciSubDevice80862934::SUBDEVICE_14627345: return "SUBDEVICE_14627345";
        case PciSubDevice80862934::SUBDEVICE_14627360: return "SUBDEVICE_14627360";
        case PciSubDevice80862934::SUBDEVICE_17AA20F0: return "SUBDEVICE_17AA20F0";
        case PciSubDevice80862934::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice80862934::SUBDEVICE_80865044: return "SUBDEVICE_80865044";
        case PciSubDevice80862934::SUBDEVICE_E4BFCC4D: return "SUBDEVICE_E4BFCC4D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862934 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862934 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862934::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice80862934::SUBDEVICE_1028020F: return "PowerEdge R300 onboard UHCI";
        case PciSubDevice80862934::SUBDEVICE_10280210: return "PowerEdge T300 onboard UHCI";
        case PciSubDevice80862934::SUBDEVICE_10280211: return "Optiplex 755";
        case PciSubDevice80862934::SUBDEVICE_10280235: return "PowerEdge R710 USB UHCI Controller";
        case PciSubDevice80862934::SUBDEVICE_10280236: return "PowerEdge R610 USB UHCI Controller";
        case PciSubDevice80862934::SUBDEVICE_10280237: return "PowerEdge T610 USB UHCI Controller";
        case PciSubDevice80862934::SUBDEVICE_1028023C: return "PowerEdge R200 onboard UHCI";
        case PciSubDevice80862934::SUBDEVICE_10280287: return "PowerEdge M610 onboard UHCI";
        case PciSubDevice80862934::SUBDEVICE_1028029C: return "PowerEdge M710 USB UHCI Controller";
        case PciSubDevice80862934::SUBDEVICE_10282011: return "Optiplex 755";
        case PciSubDevice80862934::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice80862934::SUBDEVICE_10438277: return "P5K PRO Motherboard: 82801IR [ICH9R]";
        case PciSubDevice80862934::SUBDEVICE_14627345: return "MS-7345 Motherboard: Intel 82801I/IR [ICH9/ICH9R]";
        case PciSubDevice80862934::SUBDEVICE_14627360: return "G33/P35 Neo";
        case PciSubDevice80862934::SUBDEVICE_17AA20F0: return "ThinkPad T400";
        case PciSubDevice80862934::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice80862934::SUBDEVICE_80865044: return "Desktop Board DP35DP";
        case PciSubDevice80862934::SUBDEVICE_E4BFCC4D: return "CCM-BOOGIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862934_H
