// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCIDEVICE13FE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCIDEVICE13FE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13FE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1240 = 0x1240,
    DEVICE_1600 = 0x1600,
    DEVICE_1603 = 0x1603,
    DEVICE_1604 = 0x1604,
    DEVICE_1680 = 0x1680,
    DEVICE_16FF = 0x16FF,
    DEVICE_1711 = 0x1711,
    DEVICE_1713 = 0x1713,
    DEVICE_1733 = 0x1733,
    DEVICE_1734 = 0x1734,
    DEVICE_1752 = 0x1752,
    DEVICE_1754 = 0x1754,
    DEVICE_1756 = 0x1756,
    DEVICE_A004 = 0xA004,
    DEVICE_C302 = 0xC302
};



inline const char8* enumToString(PciDevice13FE device13FE) // TEST: NO
{
    // COMMON_LT((" | device13FE = %u", device13FE)); // Commented to avoid bad looking logs



    switch (device13FE)
    {
        case PciDevice13FE::NONE:        return "NONE";
        case PciDevice13FE::DEVICE_1240: return "DEVICE_1240";
        case PciDevice13FE::DEVICE_1600: return "DEVICE_1600";
        case PciDevice13FE::DEVICE_1603: return "DEVICE_1603";
        case PciDevice13FE::DEVICE_1604: return "DEVICE_1604";
        case PciDevice13FE::DEVICE_1680: return "DEVICE_1680";
        case PciDevice13FE::DEVICE_16FF: return "DEVICE_16FF";
        case PciDevice13FE::DEVICE_1711: return "DEVICE_1711";
        case PciDevice13FE::DEVICE_1713: return "DEVICE_1713";
        case PciDevice13FE::DEVICE_1733: return "DEVICE_1733";
        case PciDevice13FE::DEVICE_1734: return "DEVICE_1734";
        case PciDevice13FE::DEVICE_1752: return "DEVICE_1752";
        case PciDevice13FE::DEVICE_1754: return "DEVICE_1754";
        case PciDevice13FE::DEVICE_1756: return "DEVICE_1756";
        case PciDevice13FE::DEVICE_A004: return "DEVICE_A004";
        case PciDevice13FE::DEVICE_C302: return "DEVICE_C302";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13FE device13FE) // TEST: NO
{
    // COMMON_LT((" | device13FE = %u", device13FE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device13FE, enumToString(device13FE));

    return res;
}



inline const char8* enumToHumanString(PciDevice13FE device13FE) // TEST: NO
{
    // COMMON_LT((" | device13FE = %u", device13FE)); // Commented to avoid bad looking logs



    switch (device13FE)
    {
        case PciDevice13FE::DEVICE_1240: return "PCI-1240 4-channel stepper motor controller card";
        case PciDevice13FE::DEVICE_1600: return "PCI-16xx series PCI multiport serial board (function 0)";
        case PciDevice13FE::DEVICE_1603: return "PCI-1603 2-port isolated RS-232/current loop";
        case PciDevice13FE::DEVICE_1604: return "PCI-1604 2-port RS-232";
        case PciDevice13FE::DEVICE_1680: return "PCI-1680 Rev.A1 2-port CAN-bus with isolation protection";
        case PciDevice13FE::DEVICE_16FF: return "PCI-16xx series PCI multiport serial board (function 1: RX/TX steering CPLD)";
        case PciDevice13FE::DEVICE_1711: return "PCI-1711 16-channel data acquisition card 12-bit, 100kS/s";
        case PciDevice13FE::DEVICE_1713: return "PCI-1713 32-channel isolated analog input card";
        case PciDevice13FE::DEVICE_1733: return "PCI-1733 32-channel isolated digital input card";
        case PciDevice13FE::DEVICE_1734: return "PCI-1734 32-channel isolated digital output card";
        case PciDevice13FE::DEVICE_1752: return "PCI-1752 64-channel Isolated Digital Output Card";
        case PciDevice13FE::DEVICE_1754: return "PCI-1754 64-channel Isolated Digital Input Card";
        case PciDevice13FE::DEVICE_1756: return "PCI-1756 64-ch Isolated Digital I/O PCI Card";
        case PciDevice13FE::DEVICE_A004: return "PCI-1612 4-port RS-232/422/485";
        case PciDevice13FE::DEVICE_C302: return "MIOe-3680 2-Port CAN-Bus MIOe Module with Isolation Protection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCIDEVICE13FE_H
