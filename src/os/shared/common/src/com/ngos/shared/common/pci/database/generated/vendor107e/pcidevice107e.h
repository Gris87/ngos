// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107E_PCIDEVICE107E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107E_PCIDEVICE107E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice107E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0008 = 0x0008,
    DEVICE_9003 = 0x9003,
    DEVICE_9007 = 0x9007,
    DEVICE_9008 = 0x9008,
    DEVICE_900C = 0x900C,
    DEVICE_900E = 0x900E,
    DEVICE_9011 = 0x9011,
    DEVICE_9013 = 0x9013,
    DEVICE_9023 = 0x9023,
    DEVICE_9027 = 0x9027,
    DEVICE_9031 = 0x9031,
    DEVICE_9033 = 0x9033
};



inline const char8* enumToString(PciDevice107E device107E) // TEST: NO
{
    // COMMON_LT((" | device107E = %u", device107E)); // Commented to avoid bad looking logs



    switch (device107E)
    {
        case PciDevice107E::NONE:        return "NONE";
        case PciDevice107E::DEVICE_0001: return "DEVICE_0001";
        case PciDevice107E::DEVICE_0002: return "DEVICE_0002";
        case PciDevice107E::DEVICE_0004: return "DEVICE_0004";
        case PciDevice107E::DEVICE_0005: return "DEVICE_0005";
        case PciDevice107E::DEVICE_0008: return "DEVICE_0008";
        case PciDevice107E::DEVICE_9003: return "DEVICE_9003";
        case PciDevice107E::DEVICE_9007: return "DEVICE_9007";
        case PciDevice107E::DEVICE_9008: return "DEVICE_9008";
        case PciDevice107E::DEVICE_900C: return "DEVICE_900C";
        case PciDevice107E::DEVICE_900E: return "DEVICE_900E";
        case PciDevice107E::DEVICE_9011: return "DEVICE_9011";
        case PciDevice107E::DEVICE_9013: return "DEVICE_9013";
        case PciDevice107E::DEVICE_9023: return "DEVICE_9023";
        case PciDevice107E::DEVICE_9027: return "DEVICE_9027";
        case PciDevice107E::DEVICE_9031: return "DEVICE_9031";
        case PciDevice107E::DEVICE_9033: return "DEVICE_9033";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice107E device107E) // TEST: NO
{
    // COMMON_LT((" | device107E = %u", device107E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device107E, enumToString(device107E));

    return res;
}



inline const char8* enumToHumanString(PciDevice107E device107E) // TEST: NO
{
    // COMMON_LT((" | device107E = %u", device107E)); // Commented to avoid bad looking logs



    switch (device107E)
    {
        case PciDevice107E::DEVICE_0001: return "5515 ATM Adapter [Flipper]";
        case PciDevice107E::DEVICE_0002: return "100 VG AnyLan Controller";
        case PciDevice107E::DEVICE_0004: return "5526 Fibre Channel Host Adapter";
        case PciDevice107E::DEVICE_0005: return "x526 Fibre Channel Host Adapter";
        case PciDevice107E::DEVICE_0008: return "5525/5575 ATM Adapter (155 Mbit) [Atlantic]";
        case PciDevice107E::DEVICE_9003: return "5535-4P-BRI-ST";
        case PciDevice107E::DEVICE_9007: return "5535-4P-BRI-U";
        case PciDevice107E::DEVICE_9008: return "5535-1P-SR";
        case PciDevice107E::DEVICE_900C: return "5535-1P-SR-ST";
        case PciDevice107E::DEVICE_900E: return "5535-1P-SR-U";
        case PciDevice107E::DEVICE_9011: return "5535-1P-PRI";
        case PciDevice107E::DEVICE_9013: return "5535-2P-PRI";
        case PciDevice107E::DEVICE_9023: return "5536-4P-BRI-ST";
        case PciDevice107E::DEVICE_9027: return "5536-4P-BRI-U";
        case PciDevice107E::DEVICE_9031: return "5536-1P-PRI";
        case PciDevice107E::DEVICE_9033: return "5536-2P-PRI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107E_PCIDEVICE107E_H
