// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862930_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862930_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862930: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_10280211 = 0x10280211,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_103C3628 = 0x103C3628,
    SUBDEVICE_10438277 = 0x10438277,
    SUBDEVICE_14627345 = 0x14627345,
    SUBDEVICE_14627360 = 0x14627360,
    SUBDEVICE_17AA20F9 = 0x17AA20F9,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_80865044 = 0x80865044,
    SUBDEVICE_E4BFCC4D = 0xE4BFCC4D
};



inline const char8* enumToString(PciSubDevice80862930 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862930::NONE:               return "NONE";
        case PciSubDevice80862930::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice80862930::SUBDEVICE_10280211: return "SUBDEVICE_10280211";
        case PciSubDevice80862930::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice80862930::SUBDEVICE_103C3628: return "SUBDEVICE_103C3628";
        case PciSubDevice80862930::SUBDEVICE_10438277: return "SUBDEVICE_10438277";
        case PciSubDevice80862930::SUBDEVICE_14627345: return "SUBDEVICE_14627345";
        case PciSubDevice80862930::SUBDEVICE_14627360: return "SUBDEVICE_14627360";
        case PciSubDevice80862930::SUBDEVICE_17AA20F9: return "SUBDEVICE_17AA20F9";
        case PciSubDevice80862930::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice80862930::SUBDEVICE_80865044: return "SUBDEVICE_80865044";
        case PciSubDevice80862930::SUBDEVICE_E4BFCC4D: return "SUBDEVICE_E4BFCC4D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862930 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862930 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862930::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice80862930::SUBDEVICE_10280211: return "Optiplex 755";
        case PciSubDevice80862930::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice80862930::SUBDEVICE_103C3628: return "dv6-1190en";
        case PciSubDevice80862930::SUBDEVICE_10438277: return "P5K PRO Motherboard: 82801IR [ICH9R]";
        case PciSubDevice80862930::SUBDEVICE_14627345: return "MS-7345 Motherboard: Intel 82801I/IR [ICH9/ICH9R]";
        case PciSubDevice80862930::SUBDEVICE_14627360: return "G33/P35 Neo";
        case PciSubDevice80862930::SUBDEVICE_17AA20F9: return "ThinkPad T400";
        case PciSubDevice80862930::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice80862930::SUBDEVICE_80865044: return "Desktop Board DP35DP";
        case PciSubDevice80862930::SUBDEVICE_E4BFCC4D: return "CCM-BOOGIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862930_H
