// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCIDEVICE17D5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCIDEVICE17D5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17d5/pcisubdevice17d55831.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17d5/pcisubdevice17d55832.h>
#include <com/ngos/shared/common/pci/database/generated/vendor17d5/pcisubdevice17d55833.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17D5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5731 = 0x5731,
    DEVICE_5732 = 0x5732,
    DEVICE_5831 = 0x5831,
    DEVICE_5832 = 0x5832,
    DEVICE_5833 = 0x5833
};



inline const char8* enumToString(PciDevice17D5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17D5::NONE:        return "NONE";
        case PciDevice17D5::DEVICE_5731: return "DEVICE_5731";
        case PciDevice17D5::DEVICE_5732: return "DEVICE_5732";
        case PciDevice17D5::DEVICE_5831: return "DEVICE_5831";
        case PciDevice17D5::DEVICE_5832: return "DEVICE_5832";
        case PciDevice17D5::DEVICE_5833: return "DEVICE_5833";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17D5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice17D5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17D5::DEVICE_5731: return "Xframe 10-Gigabit Ethernet PCI-X";
        case PciDevice17D5::DEVICE_5732: return "Xframe II 10-Gigabit Ethernet PCI-X 2.0";
        case PciDevice17D5::DEVICE_5831: return "Xframe 10-Gigabit Ethernet PCI-X";
        case PciDevice17D5::DEVICE_5832: return "Xframe II 10-Gigabit Ethernet PCI-X 2.0";
        case PciDevice17D5::DEVICE_5833: return "X3100 Series 10 Gigabit Ethernet PCIe";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice17D5 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17D5::DEVICE_5731: return "Unknown device";
        case PciDevice17D5::DEVICE_5732: return "Unknown device";
        case PciDevice17D5::DEVICE_5831: return enumToHumanString((PciSubDevice17D55831)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice17D5::DEVICE_5832: return enumToHumanString((PciSubDevice17D55832)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice17D5::DEVICE_5833: return enumToHumanString((PciSubDevice17D55833)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCIDEVICE17D5_H
