// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CF_PCIDEVICE10CF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CF_PCIDEVICE10CF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10CF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_01EF = 0x01EF,
    DEVICE_1414 = 0x1414,
    DEVICE_1415 = 0x1415,
    DEVICE_1422 = 0x1422,
    DEVICE_142D = 0x142D,
    DEVICE_1430 = 0x1430,
    DEVICE_1623 = 0x1623,
    DEVICE_2001 = 0x2001,
    DEVICE_200C = 0x200C,
    DEVICE_2010 = 0x2010,
    DEVICE_2019 = 0x2019,
    DEVICE_201E = 0x201E,
    DEVICE_202B = 0x202B
};



inline const char8* enumToString(PciDevice10CF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10CF::NONE:        return "NONE";
        case PciDevice10CF::DEVICE_01EF: return "DEVICE_01EF";
        case PciDevice10CF::DEVICE_1414: return "DEVICE_1414";
        case PciDevice10CF::DEVICE_1415: return "DEVICE_1415";
        case PciDevice10CF::DEVICE_1422: return "DEVICE_1422";
        case PciDevice10CF::DEVICE_142D: return "DEVICE_142D";
        case PciDevice10CF::DEVICE_1430: return "DEVICE_1430";
        case PciDevice10CF::DEVICE_1623: return "DEVICE_1623";
        case PciDevice10CF::DEVICE_2001: return "DEVICE_2001";
        case PciDevice10CF::DEVICE_200C: return "DEVICE_200C";
        case PciDevice10CF::DEVICE_2010: return "DEVICE_2010";
        case PciDevice10CF::DEVICE_2019: return "DEVICE_2019";
        case PciDevice10CF::DEVICE_201E: return "DEVICE_201E";
        case PciDevice10CF::DEVICE_202B: return "DEVICE_202B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10CF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10CF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10CF::DEVICE_01EF: return "PCEA4 PCI-Express Dual Port ESCON Adapter";
        case PciDevice10CF::DEVICE_1414: return "On-board USB 1.1 companion controller";
        case PciDevice10CF::DEVICE_1415: return "On-board USB 2.0 EHCI controller";
        case PciDevice10CF::DEVICE_1422: return "E8410 nVidia graphics adapter";
        case PciDevice10CF::DEVICE_142D: return "HD audio (Realtek ALC262)";
        case PciDevice10CF::DEVICE_1430: return "82566MM Intel 1Gb copper LAN interface";
        case PciDevice10CF::DEVICE_1623: return "PCEA4 PCI-Express Dual Port ESCON Adapter";
        case PciDevice10CF::DEVICE_2001: return "mb86605";
        case PciDevice10CF::DEVICE_200C: return "MB86613L IEEE1394 OHCI 1.0 Controller";
        case PciDevice10CF::DEVICE_2010: return "MB86613S IEEE1394 OHCI 1.1 Controller";
        case PciDevice10CF::DEVICE_2019: return "MB86295S [CORAL P]";
        case PciDevice10CF::DEVICE_201E: return "MB86296S [CORAL PA]";
        case PciDevice10CF::DEVICE_202B: return "MB86297A [Carmine Graphics Controller]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CF_PCIDEVICE10CF_H
