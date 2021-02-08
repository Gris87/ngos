// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C002B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C002B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C002B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280204 = 0x10280204,
    SUBDEVICE_10280205 = 0x10280205,
    SUBDEVICE_103C303F = 0x103C303F,
    SUBDEVICE_103C3040 = 0x103C3040,
    SUBDEVICE_105BE017 = 0x105BE017,
    SUBDEVICE_105BE023 = 0x105BE023,
    SUBDEVICE_105BE025 = 0x105BE025,
    SUBDEVICE_1113E811 = 0x1113E811,
    SUBDEVICE_185F30AF = 0x185F30AF,
    SUBDEVICE_19310023 = 0x19310023,
    SUBDEVICE_1A3B1089 = 0x1A3B1089,
    SUBDEVICE_1A3B2C37 = 0x1A3B2C37,
    SUBDEVICE_1B9A0401 = 0x1B9A0401,
    SUBDEVICE_1B9A0C03 = 0x1B9A0C03
};



inline const char8* enumToString(PciSubDevice168C002B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C002B::NONE:               return "NONE";
        case PciSubDevice168C002B::SUBDEVICE_10280204: return "SUBDEVICE_10280204";
        case PciSubDevice168C002B::SUBDEVICE_10280205: return "SUBDEVICE_10280205";
        case PciSubDevice168C002B::SUBDEVICE_103C303F: return "SUBDEVICE_103C303F";
        case PciSubDevice168C002B::SUBDEVICE_103C3040: return "SUBDEVICE_103C3040";
        case PciSubDevice168C002B::SUBDEVICE_105BE017: return "SUBDEVICE_105BE017";
        case PciSubDevice168C002B::SUBDEVICE_105BE023: return "SUBDEVICE_105BE023";
        case PciSubDevice168C002B::SUBDEVICE_105BE025: return "SUBDEVICE_105BE025";
        case PciSubDevice168C002B::SUBDEVICE_1113E811: return "SUBDEVICE_1113E811";
        case PciSubDevice168C002B::SUBDEVICE_185F30AF: return "SUBDEVICE_185F30AF";
        case PciSubDevice168C002B::SUBDEVICE_19310023: return "SUBDEVICE_19310023";
        case PciSubDevice168C002B::SUBDEVICE_1A3B1089: return "SUBDEVICE_1A3B1089";
        case PciSubDevice168C002B::SUBDEVICE_1A3B2C37: return "SUBDEVICE_1A3B2C37";
        case PciSubDevice168C002B::SUBDEVICE_1B9A0401: return "SUBDEVICE_1B9A0401";
        case PciSubDevice168C002B::SUBDEVICE_1B9A0C03: return "SUBDEVICE_1B9A0C03";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C002B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C002B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C002B::SUBDEVICE_10280204: return "Wireless 1502 802.11bgn Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_10280205: return "Wireless 1702 802.11bgn Half-size Mini PCIe Card [AR9002WB-1NGCD]";
        case PciSubDevice168C002B::SUBDEVICE_103C303F: return "U98Z062.10 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_103C3040: return "U98Z062.12 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_105BE017: return "T77H126.00 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_105BE023: return "T77H121.04 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_105BE025: return "T77H121.05 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_1113E811: return "WN7811A (Toshiba PA3722U-1MPC) 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_185F30AF: return "DNXA-95 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_19310023: return "Option GTM67x PCIe WiFi Adapter";
        case PciSubDevice168C002B::SUBDEVICE_1A3B1089: return "AW-NE785 / AW-NE785H 802.11bgn Wireless Full or Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_1A3B2C37: return "AW-NB037H 802.11bgn Wireless Half-size Mini PCIe Card [AR9002WB-1NGCD]";
        case PciSubDevice168C002B::SUBDEVICE_1B9A0401: return "XW204E 802.11bgn Wireless Half-size Mini PCIe Card";
        case PciSubDevice168C002B::SUBDEVICE_1B9A0C03: return "WB214E 802.11bgn Wireless Half-size Mini PCIe Card [AR9002WB-1NGCD]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C002B_H
