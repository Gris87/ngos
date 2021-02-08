// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCIDEVICE15B7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCIDEVICE15B7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15b7/pcisubdevice15b75009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15b7/pcisubdevice15b7500b.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15B7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2001 = 0x2001,
    DEVICE_5001 = 0x5001,
    DEVICE_5002 = 0x5002,
    DEVICE_5003 = 0x5003,
    DEVICE_5004 = 0x5004,
    DEVICE_5005 = 0x5005,
    DEVICE_5006 = 0x5006,
    DEVICE_5009 = 0x5009,
    DEVICE_500B = 0x500B,
    DEVICE_500D = 0x500D
};



inline const char8* enumToString(PciDevice15B7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15B7::NONE:        return "NONE";
        case PciDevice15B7::DEVICE_2001: return "DEVICE_2001";
        case PciDevice15B7::DEVICE_5001: return "DEVICE_5001";
        case PciDevice15B7::DEVICE_5002: return "DEVICE_5002";
        case PciDevice15B7::DEVICE_5003: return "DEVICE_5003";
        case PciDevice15B7::DEVICE_5004: return "DEVICE_5004";
        case PciDevice15B7::DEVICE_5005: return "DEVICE_5005";
        case PciDevice15B7::DEVICE_5006: return "DEVICE_5006";
        case PciDevice15B7::DEVICE_5009: return "DEVICE_5009";
        case PciDevice15B7::DEVICE_500B: return "DEVICE_500B";
        case PciDevice15B7::DEVICE_500D: return "DEVICE_500D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15B7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15B7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15B7::DEVICE_2001: return "Skyhawk Series NVME SSD";
        case PciDevice15B7::DEVICE_5001: return "WD Black NVMe SSD";
        case PciDevice15B7::DEVICE_5002: return "WD Black 2018 / PC SN720 NVMe SSD";
        case PciDevice15B7::DEVICE_5003: return "WD Blue SN500 / PC SN520 NVMe SSD";
        case PciDevice15B7::DEVICE_5004: return "PC SN520 NVMe SSD";
        case PciDevice15B7::DEVICE_5005: return "PC SN520 NVMe SSD";
        case PciDevice15B7::DEVICE_5006: return "WD Black SN750 / PC SN730 NVMe SSD";
        case PciDevice15B7::DEVICE_5009: return "WD Blue SN550 NVMe SSD";
        case PciDevice15B7::DEVICE_500B: return "PC SN530 NVMe SSD";
        case PciDevice15B7::DEVICE_500D: return "WD Ultrastar DC SN340 NVMe SSD";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice15B7 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15B7::DEVICE_2001: return "Unknown device";
        case PciDevice15B7::DEVICE_5001: return "Unknown device";
        case PciDevice15B7::DEVICE_5002: return "Unknown device";
        case PciDevice15B7::DEVICE_5003: return "Unknown device";
        case PciDevice15B7::DEVICE_5004: return "Unknown device";
        case PciDevice15B7::DEVICE_5005: return "Unknown device";
        case PciDevice15B7::DEVICE_5006: return "Unknown device";
        case PciDevice15B7::DEVICE_5009: return enumToHumanString((PciSubDevice15B75009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice15B7::DEVICE_500B: return enumToHumanString((PciSubDevice15B7500B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice15B7::DEVICE_500D: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCIDEVICE15B7_H
