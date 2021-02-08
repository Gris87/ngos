// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086293E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086293E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086293E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_10280211 = 0x10280211,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_103C3628 = 0x103C3628,
    SUBDEVICE_1043829F = 0x1043829F,
    SUBDEVICE_1462735A = 0x1462735A,
    SUBDEVICE_14627360 = 0x14627360,
    SUBDEVICE_17AA20F2 = 0x17AA20F2,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_8086293E = 0x8086293E,
    SUBDEVICE_80862940 = 0x80862940,
    SUBDEVICE_E4BFCC4D = 0xE4BFCC4D
};



inline const char8* enumToString(PciSubDevice8086293E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086293E::NONE:               return "NONE";
        case PciSubDevice8086293E::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice8086293E::SUBDEVICE_10280211: return "SUBDEVICE_10280211";
        case PciSubDevice8086293E::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice8086293E::SUBDEVICE_103C3628: return "SUBDEVICE_103C3628";
        case PciSubDevice8086293E::SUBDEVICE_1043829F: return "SUBDEVICE_1043829F";
        case PciSubDevice8086293E::SUBDEVICE_1462735A: return "SUBDEVICE_1462735A";
        case PciSubDevice8086293E::SUBDEVICE_14627360: return "SUBDEVICE_14627360";
        case PciSubDevice8086293E::SUBDEVICE_17AA20F2: return "SUBDEVICE_17AA20F2";
        case PciSubDevice8086293E::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice8086293E::SUBDEVICE_8086293E: return "SUBDEVICE_8086293E";
        case PciSubDevice8086293E::SUBDEVICE_80862940: return "SUBDEVICE_80862940";
        case PciSubDevice8086293E::SUBDEVICE_E4BFCC4D: return "SUBDEVICE_E4BFCC4D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086293E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086293E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086293E::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice8086293E::SUBDEVICE_10280211: return "Optiplex 755";
        case PciSubDevice8086293E::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice8086293E::SUBDEVICE_103C3628: return "dv6-1190en";
        case PciSubDevice8086293E::SUBDEVICE_1043829F: return "P5K PRO Motherboard: 82801IR [ICH9R]";
        case PciSubDevice8086293E::SUBDEVICE_1462735A: return "MS-7345 Motherboard: Intel 82801I/IR [ICH9/ICH9R]";
        case PciSubDevice8086293E::SUBDEVICE_14627360: return "G33/P35 Neo";
        case PciSubDevice8086293E::SUBDEVICE_17AA20F2: return "ThinkPad T400";
        case PciSubDevice8086293E::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice8086293E::SUBDEVICE_8086293E: return "Optiplex 755";
        case PciSubDevice8086293E::SUBDEVICE_80862940: return "Optiplex 755";
        case PciSubDevice8086293E::SUBDEVICE_E4BFCC4D: return "CCM-BOOGIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086293E_H
