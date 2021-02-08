// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E3_PCIDEVICE10E3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E3_PCIDEVICE10E3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e3/pcisubdevice10e30148.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10E3: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0108 = 0x0108,
    DEVICE_0148 = 0x0148,
    DEVICE_0860 = 0x0860,
    DEVICE_0862 = 0x0862,
    DEVICE_8111 = 0x8111,
    DEVICE_8260 = 0x8260,
    DEVICE_8261 = 0x8261,
    DEVICE_A108 = 0xA108
};



inline const char8* enumToString(PciDevice10E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E3::DEVICE_0000: return "DEVICE_0000";
        case PciDevice10E3::DEVICE_0108: return "DEVICE_0108";
        case PciDevice10E3::DEVICE_0148: return "DEVICE_0148";
        case PciDevice10E3::DEVICE_0860: return "DEVICE_0860";
        case PciDevice10E3::DEVICE_0862: return "DEVICE_0862";
        case PciDevice10E3::DEVICE_8111: return "DEVICE_8111";
        case PciDevice10E3::DEVICE_8260: return "DEVICE_8260";
        case PciDevice10E3::DEVICE_8261: return "DEVICE_8261";
        case PciDevice10E3::DEVICE_A108: return "DEVICE_A108";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E3::DEVICE_0000: return "CA91C042 [Universe]";
        case PciDevice10E3::DEVICE_0108: return "Tsi108 Host Bridge for Single PowerPC";
        case PciDevice10E3::DEVICE_0148: return "Tsi148 [Tempe]";
        case PciDevice10E3::DEVICE_0860: return "CA91C860 [QSpan]";
        case PciDevice10E3::DEVICE_0862: return "CA91C862A [QSpan-II]";
        case PciDevice10E3::DEVICE_8111: return "Tsi381 PCIe to PCI Bridge";
        case PciDevice10E3::DEVICE_8260: return "CA91L8200B [Dual PCI PowerSpan II]";
        case PciDevice10E3::DEVICE_8261: return "CA91L8260B [Single PCI PowerSpan II]";
        case PciDevice10E3::DEVICE_A108: return "Tsi109 Host Bridge for Dual PowerPC";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10E3 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E3::DEVICE_0000: return "Unknown device";
        case PciDevice10E3::DEVICE_0108: return "Unknown device";
        case PciDevice10E3::DEVICE_0148: return enumToHumanString((PciSubDevice10E30148)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10E3::DEVICE_0860: return "Unknown device";
        case PciDevice10E3::DEVICE_0862: return "Unknown device";
        case PciDevice10E3::DEVICE_8111: return "Unknown device";
        case PciDevice10E3::DEVICE_8260: return "Unknown device";
        case PciDevice10E3::DEVICE_8261: return "Unknown device";
        case PciDevice10E3::DEVICE_A108: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E3_PCIDEVICE10E3_H
