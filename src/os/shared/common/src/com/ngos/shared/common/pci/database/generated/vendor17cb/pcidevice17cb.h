// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCIDEVICE17CB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCIDEVICE17CB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17cb/pcisubdevice17cb0001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17cb/pcisubdevice17cb0002.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17CB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0105 = 0x0105,
    DEVICE_0108 = 0x0108,
    DEVICE_0109 = 0x0109,
    DEVICE_0300 = 0x0300,
    DEVICE_0301 = 0x0301,
    DEVICE_0302 = 0x0302,
    DEVICE_0400 = 0x0400,
    DEVICE_0401 = 0x0401,
    DEVICE_1000 = 0x1000,
    DEVICE_1101 = 0x1101,
    DEVICE_1103 = 0x1103,
    DEVICE_1104 = 0x1104
};



inline const char8* enumToString(PciDevice17CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17CB::NONE:        return "NONE";
        case PciDevice17CB::DEVICE_0001: return "DEVICE_0001";
        case PciDevice17CB::DEVICE_0002: return "DEVICE_0002";
        case PciDevice17CB::DEVICE_0105: return "DEVICE_0105";
        case PciDevice17CB::DEVICE_0108: return "DEVICE_0108";
        case PciDevice17CB::DEVICE_0109: return "DEVICE_0109";
        case PciDevice17CB::DEVICE_0300: return "DEVICE_0300";
        case PciDevice17CB::DEVICE_0301: return "DEVICE_0301";
        case PciDevice17CB::DEVICE_0302: return "DEVICE_0302";
        case PciDevice17CB::DEVICE_0400: return "DEVICE_0400";
        case PciDevice17CB::DEVICE_0401: return "DEVICE_0401";
        case PciDevice17CB::DEVICE_1000: return "DEVICE_1000";
        case PciDevice17CB::DEVICE_1101: return "DEVICE_1101";
        case PciDevice17CB::DEVICE_1103: return "DEVICE_1103";
        case PciDevice17CB::DEVICE_1104: return "DEVICE_1104";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice17CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17CB::DEVICE_0001: return "AGN100 802.11 a/b/g True MIMO Wireless Card";
        case PciDevice17CB::DEVICE_0002: return "AGN300 802.11 a/b/g True MIMO Wireless Card";
        case PciDevice17CB::DEVICE_0105: return "MSM8998 PCIe Root Complex";
        case PciDevice17CB::DEVICE_0108: return "SM8150 PCIe Root Complex";
        case PciDevice17CB::DEVICE_0109: return "SA8195P PCIe Root Complex";
        case PciDevice17CB::DEVICE_0300: return "MDM9x35 LTE Modem [Snapdragon X7]";
        case PciDevice17CB::DEVICE_0301: return "MDM9x45 LTE Modem [Snapdragon X12]";
        case PciDevice17CB::DEVICE_0302: return "MDM9x55 LTE Modem [Snapdragon X16]";
        case PciDevice17CB::DEVICE_0400: return "Datacenter Technologies QDF2432 PCI Express Root Port";
        case PciDevice17CB::DEVICE_0401: return "Datacenter Technologies QDF2400 PCI Express Root Port";
        case PciDevice17CB::DEVICE_1000: return "QCS405 PCIe Root Complex";
        case PciDevice17CB::DEVICE_1101: return "QCA6390 Wireless Network Adapter";
        case PciDevice17CB::DEVICE_1103: return "QCNFA765 Wireless Network Adapter";
        case PciDevice17CB::DEVICE_1104: return "QCN6024/9024/9074 Wireless Network Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice17CB device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17CB::DEVICE_0001: return enumToHumanString((PciSubDevice17CB0001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice17CB::DEVICE_0002: return enumToHumanString((PciSubDevice17CB0002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice17CB::DEVICE_0105: return "Unknown device";
        case PciDevice17CB::DEVICE_0108: return "Unknown device";
        case PciDevice17CB::DEVICE_0109: return "Unknown device";
        case PciDevice17CB::DEVICE_0300: return "Unknown device";
        case PciDevice17CB::DEVICE_0301: return "Unknown device";
        case PciDevice17CB::DEVICE_0302: return "Unknown device";
        case PciDevice17CB::DEVICE_0400: return "Unknown device";
        case PciDevice17CB::DEVICE_0401: return "Unknown device";
        case PciDevice17CB::DEVICE_1000: return "Unknown device";
        case PciDevice17CB::DEVICE_1101: return "Unknown device";
        case PciDevice17CB::DEVICE_1103: return "Unknown device";
        case PciDevice17CB::DEVICE_1104: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCIDEVICE17CB_H
