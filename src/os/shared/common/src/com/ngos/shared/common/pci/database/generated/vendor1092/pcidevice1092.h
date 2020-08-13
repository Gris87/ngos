// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1092_PCIDEVICE1092_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1092_PCIDEVICE1092_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1092: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0028 = 0x0028,
    DEVICE_00A0 = 0x00A0,
    DEVICE_00A8 = 0x00A8,
    DEVICE_0550 = 0x0550,
    DEVICE_08D4 = 0x08D4,
    DEVICE_094C = 0x094C,
    DEVICE_1001 = 0x1001,
    DEVICE_1092 = 0x1092,
    DEVICE_6120 = 0x6120,
    DEVICE_8810 = 0x8810,
    DEVICE_8811 = 0x8811,
    DEVICE_8880 = 0x8880,
    DEVICE_8881 = 0x8881,
    DEVICE_88B0 = 0x88B0,
    DEVICE_88B1 = 0x88B1,
    DEVICE_88C0 = 0x88C0,
    DEVICE_88C1 = 0x88C1,
    DEVICE_88D0 = 0x88D0,
    DEVICE_88D1 = 0x88D1,
    DEVICE_88F0 = 0x88F0,
    DEVICE_88F1 = 0x88F1,
    DEVICE_9999 = 0x9999
};



inline const char8* enumToString(PciDevice1092 device1092) // TEST: NO
{
    // COMMON_LT((" | device1092 = %u", device1092)); // Commented to avoid bad looking logs



    switch (device1092)
    {
        case PciDevice1092::NONE:        return "NONE";
        case PciDevice1092::DEVICE_0028: return "DEVICE_0028";
        case PciDevice1092::DEVICE_00A0: return "DEVICE_00A0";
        case PciDevice1092::DEVICE_00A8: return "DEVICE_00A8";
        case PciDevice1092::DEVICE_0550: return "DEVICE_0550";
        case PciDevice1092::DEVICE_08D4: return "DEVICE_08D4";
        case PciDevice1092::DEVICE_094C: return "DEVICE_094C";
        case PciDevice1092::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1092::DEVICE_1092: return "DEVICE_1092";
        case PciDevice1092::DEVICE_6120: return "DEVICE_6120";
        case PciDevice1092::DEVICE_8810: return "DEVICE_8810";
        case PciDevice1092::DEVICE_8811: return "DEVICE_8811";
        case PciDevice1092::DEVICE_8880: return "DEVICE_8880";
        case PciDevice1092::DEVICE_8881: return "DEVICE_8881";
        case PciDevice1092::DEVICE_88B0: return "DEVICE_88B0";
        case PciDevice1092::DEVICE_88B1: return "DEVICE_88B1";
        case PciDevice1092::DEVICE_88C0: return "DEVICE_88C0";
        case PciDevice1092::DEVICE_88C1: return "DEVICE_88C1";
        case PciDevice1092::DEVICE_88D0: return "DEVICE_88D0";
        case PciDevice1092::DEVICE_88D1: return "DEVICE_88D1";
        case PciDevice1092::DEVICE_88F0: return "DEVICE_88F0";
        case PciDevice1092::DEVICE_88F1: return "DEVICE_88F1";
        case PciDevice1092::DEVICE_9999: return "DEVICE_9999";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1092 device1092) // TEST: NO
{
    // COMMON_LT((" | device1092 = %u", device1092)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1092, enumToString(device1092));

    return res;
}



inline const char8* enumToHumanString(PciDevice1092 device1092) // TEST: NO
{
    // COMMON_LT((" | device1092 = %u", device1092)); // Commented to avoid bad looking logs



    switch (device1092)
    {
        case PciDevice1092::DEVICE_0028: return "Viper V770";
        case PciDevice1092::DEVICE_00A0: return "Speedstar Pro SE";
        case PciDevice1092::DEVICE_00A8: return "Speedstar 64";
        case PciDevice1092::DEVICE_0550: return "Viper V550";
        case PciDevice1092::DEVICE_08D4: return "Supra 2260 Modem";
        case PciDevice1092::DEVICE_094C: return "SupraExpress 56i Pro";
        case PciDevice1092::DEVICE_1001: return "Video Crunch It 1001 capture card";
        case PciDevice1092::DEVICE_1092: return "Viper V330";
        case PciDevice1092::DEVICE_6120: return "Maximum DVD";
        case PciDevice1092::DEVICE_8810: return "Stealth SE";
        case PciDevice1092::DEVICE_8811: return "Stealth 64/SE";
        case PciDevice1092::DEVICE_8880: return "Stealth";
        case PciDevice1092::DEVICE_8881: return "Stealth";
        case PciDevice1092::DEVICE_88B0: return "Stealth 64";
        case PciDevice1092::DEVICE_88B1: return "Stealth 64";
        case PciDevice1092::DEVICE_88C0: return "Stealth 64";
        case PciDevice1092::DEVICE_88C1: return "Stealth 64";
        case PciDevice1092::DEVICE_88D0: return "Stealth 64";
        case PciDevice1092::DEVICE_88D1: return "Stealth 64";
        case PciDevice1092::DEVICE_88F0: return "Stealth 64";
        case PciDevice1092::DEVICE_88F1: return "Stealth 64";
        case PciDevice1092::DEVICE_9999: return "DMD-I0928-1 \"Monster sound\" sound chip";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1092_PCIDEVICE1092_H
