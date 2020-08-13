// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CD7_PCIDEVICE1CD7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CD7_PCIDEVICE1CD7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CD7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0014 = 0x0014,
    DEVICE_0017 = 0x0017,
    DEVICE_0051 = 0x0051,
    DEVICE_0052 = 0x0052,
    DEVICE_0053 = 0x0053,
    DEVICE_0054 = 0x0054
};



inline const char8* enumToString(PciDevice1CD7 device1CD7) // TEST: NO
{
    // COMMON_LT((" | device1CD7 = %u", device1CD7)); // Commented to avoid bad looking logs



    switch (device1CD7)
    {
        case PciDevice1CD7::NONE:        return "NONE";
        case PciDevice1CD7::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1CD7::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1CD7::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1CD7::DEVICE_0051: return "DEVICE_0051";
        case PciDevice1CD7::DEVICE_0052: return "DEVICE_0052";
        case PciDevice1CD7::DEVICE_0053: return "DEVICE_0053";
        case PciDevice1CD7::DEVICE_0054: return "DEVICE_0054";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CD7 device1CD7) // TEST: NO
{
    // COMMON_LT((" | device1CD7 = %u", device1CD7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CD7, enumToString(device1CD7));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CD7 device1CD7) // TEST: NO
{
    // COMMON_LT((" | device1CD7 = %u", device1CD7)); // Commented to avoid bad looking logs



    switch (device1CD7)
    {
        case PciDevice1CD7::DEVICE_0010: return "Pro Capture Endpoint";
        case PciDevice1CD7::DEVICE_0014: return "PRO CAPTURE AIO 4K PLUS";
        case PciDevice1CD7::DEVICE_0017: return "PRO CAPTURE AIO 4K";
        case PciDevice1CD7::DEVICE_0051: return "Eco Capture Dual HDMI M.2";
        case PciDevice1CD7::DEVICE_0052: return "Eco Capture HDMI 4K M.2";
        case PciDevice1CD7::DEVICE_0053: return "Eco Capture Dual SDI M.2";
        case PciDevice1CD7::DEVICE_0054: return "Eco Capture Quad SDI M.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CD7_PCIDEVICE1CD7_H
