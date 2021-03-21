// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DEF_PCIDEVICE1DEF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DEF_PCIDEVICE1DEF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DEF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E005 = 0xE005,
    DEVICE_E006 = 0xE006,
    DEVICE_E007 = 0xE007,
    DEVICE_E008 = 0xE008,
    DEVICE_E009 = 0xE009,
    DEVICE_E00A = 0xE00A,
    DEVICE_E00B = 0xE00B,
    DEVICE_E00C = 0xE00C,
    DEVICE_E100 = 0xE100,
    DEVICE_E101 = 0xE101,
    DEVICE_E102 = 0xE102,
    DEVICE_E103 = 0xE103,
    DEVICE_E104 = 0xE104,
    DEVICE_E105 = 0xE105,
    DEVICE_E106 = 0xE106,
    DEVICE_E107 = 0xE107,
    DEVICE_E108 = 0xE108,
    DEVICE_E110 = 0xE110,
    DEVICE_E111 = 0xE111,
    DEVICE_E112 = 0xE112,
    DEVICE_E113 = 0xE113,
    DEVICE_E114 = 0xE114,
    DEVICE_E115 = 0xE115,
    DEVICE_E116 = 0xE116,
    DEVICE_E117 = 0xE117,
    DEVICE_E118 = 0xE118
};



inline const char8* enumToString(PciDevice1DEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DEF::NONE:        return "NONE";
        case PciDevice1DEF::DEVICE_E005: return "DEVICE_E005";
        case PciDevice1DEF::DEVICE_E006: return "DEVICE_E006";
        case PciDevice1DEF::DEVICE_E007: return "DEVICE_E007";
        case PciDevice1DEF::DEVICE_E008: return "DEVICE_E008";
        case PciDevice1DEF::DEVICE_E009: return "DEVICE_E009";
        case PciDevice1DEF::DEVICE_E00A: return "DEVICE_E00A";
        case PciDevice1DEF::DEVICE_E00B: return "DEVICE_E00B";
        case PciDevice1DEF::DEVICE_E00C: return "DEVICE_E00C";
        case PciDevice1DEF::DEVICE_E100: return "DEVICE_E100";
        case PciDevice1DEF::DEVICE_E101: return "DEVICE_E101";
        case PciDevice1DEF::DEVICE_E102: return "DEVICE_E102";
        case PciDevice1DEF::DEVICE_E103: return "DEVICE_E103";
        case PciDevice1DEF::DEVICE_E104: return "DEVICE_E104";
        case PciDevice1DEF::DEVICE_E105: return "DEVICE_E105";
        case PciDevice1DEF::DEVICE_E106: return "DEVICE_E106";
        case PciDevice1DEF::DEVICE_E107: return "DEVICE_E107";
        case PciDevice1DEF::DEVICE_E108: return "DEVICE_E108";
        case PciDevice1DEF::DEVICE_E110: return "DEVICE_E110";
        case PciDevice1DEF::DEVICE_E111: return "DEVICE_E111";
        case PciDevice1DEF::DEVICE_E112: return "DEVICE_E112";
        case PciDevice1DEF::DEVICE_E113: return "DEVICE_E113";
        case PciDevice1DEF::DEVICE_E114: return "DEVICE_E114";
        case PciDevice1DEF::DEVICE_E115: return "DEVICE_E115";
        case PciDevice1DEF::DEVICE_E116: return "DEVICE_E116";
        case PciDevice1DEF::DEVICE_E117: return "DEVICE_E117";
        case PciDevice1DEF::DEVICE_E118: return "DEVICE_E118";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DEF::DEVICE_E005: return "eMAG PCI Express Root Port 0";
        case PciDevice1DEF::DEVICE_E006: return "eMAG PCI Express Root Port 1";
        case PciDevice1DEF::DEVICE_E007: return "eMAG PCI Express Root Port 2";
        case PciDevice1DEF::DEVICE_E008: return "eMAG PCI Express Root Port 3";
        case PciDevice1DEF::DEVICE_E009: return "eMAG PCI Express Root Port 4";
        case PciDevice1DEF::DEVICE_E00A: return "eMAG PCI Express Root Port 5";
        case PciDevice1DEF::DEVICE_E00B: return "eMAG PCI Express Root Port 6";
        case PciDevice1DEF::DEVICE_E00C: return "eMAG PCI Express Root Port 7";
        case PciDevice1DEF::DEVICE_E100: return "Altra PCI Express Root Complex A";
        case PciDevice1DEF::DEVICE_E101: return "Altra PCI Express Root Port a0";
        case PciDevice1DEF::DEVICE_E102: return "Altra PCI Express Root Port a1";
        case PciDevice1DEF::DEVICE_E103: return "Altra PCI Express Root Port a2";
        case PciDevice1DEF::DEVICE_E104: return "Altra PCI Express Root Port a3";
        case PciDevice1DEF::DEVICE_E105: return "Altra PCI Express Root Port a4";
        case PciDevice1DEF::DEVICE_E106: return "Altra PCI Express Root Port a5";
        case PciDevice1DEF::DEVICE_E107: return "Altra PCI Express Root Port a6";
        case PciDevice1DEF::DEVICE_E108: return "Altra PCI Express Root Port a7";
        case PciDevice1DEF::DEVICE_E110: return "Altra PCI Express Root Complex B";
        case PciDevice1DEF::DEVICE_E111: return "Altra PCI Express Root Port b0";
        case PciDevice1DEF::DEVICE_E112: return "Altra PCI Express Root Port b1";
        case PciDevice1DEF::DEVICE_E113: return "Altra PCI Express Root Port b2";
        case PciDevice1DEF::DEVICE_E114: return "Altra PCI Express Root Port b3";
        case PciDevice1DEF::DEVICE_E115: return "Altra PCI Express Root Port b4";
        case PciDevice1DEF::DEVICE_E116: return "Altra PCI Express Root Port b5";
        case PciDevice1DEF::DEVICE_E117: return "Altra PCI Express Root Port b6";
        case PciDevice1DEF::DEVICE_E118: return "Altra PCI Express Root Port b7";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DEF_PCIDEVICE1DEF_H
