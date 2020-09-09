// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCIDEVICE9710_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCIDEVICE9710_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9710/pcisubdevice97109815.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9710/pcisubdevice97109835.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9710/pcisubdevice97109845.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9710/pcisubdevice97109855.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9710: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9250 = 0x9250,
    DEVICE_9805 = 0x9805,
    DEVICE_9815 = 0x9815,
    DEVICE_9820 = 0x9820,
    DEVICE_9835 = 0x9835,
    DEVICE_9845 = 0x9845,
    DEVICE_9855 = 0x9855,
    DEVICE_9865 = 0x9865,
    DEVICE_9900 = 0x9900,
    DEVICE_9901 = 0x9901,
    DEVICE_9904 = 0x9904,
    DEVICE_9912 = 0x9912,
    DEVICE_9922 = 0x9922,
    DEVICE_9990 = 0x9990
};



inline const char8* enumToString(PciDevice9710 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9710::NONE:        return "NONE";
        case PciDevice9710::DEVICE_9250: return "DEVICE_9250";
        case PciDevice9710::DEVICE_9805: return "DEVICE_9805";
        case PciDevice9710::DEVICE_9815: return "DEVICE_9815";
        case PciDevice9710::DEVICE_9820: return "DEVICE_9820";
        case PciDevice9710::DEVICE_9835: return "DEVICE_9835";
        case PciDevice9710::DEVICE_9845: return "DEVICE_9845";
        case PciDevice9710::DEVICE_9855: return "DEVICE_9855";
        case PciDevice9710::DEVICE_9865: return "DEVICE_9865";
        case PciDevice9710::DEVICE_9900: return "DEVICE_9900";
        case PciDevice9710::DEVICE_9901: return "DEVICE_9901";
        case PciDevice9710::DEVICE_9904: return "DEVICE_9904";
        case PciDevice9710::DEVICE_9912: return "DEVICE_9912";
        case PciDevice9710::DEVICE_9922: return "DEVICE_9922";
        case PciDevice9710::DEVICE_9990: return "DEVICE_9990";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9710 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice9710 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9710::DEVICE_9250: return "PCI-to-PCI bridge [MCS9250]";
        case PciDevice9710::DEVICE_9805: return "PCI 1 port parallel adapter";
        case PciDevice9710::DEVICE_9815: return "PCI 9815 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9820: return "PCI 9820 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9835: return "PCI 9835 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9845: return "PCI 9845 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9855: return "PCI 9855 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9865: return "PCI 9865 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9900: return "MCS9900 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9901: return "PCIe 9901 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9904: return "4-Port PCIe Serial Adapter";
        case PciDevice9710::DEVICE_9912: return "PCIe 9912 Multi-I/O Controller";
        case PciDevice9710::DEVICE_9922: return "MCS9922 PCIe Multi-I/O Controller";
        case PciDevice9710::DEVICE_9990: return "MCS9990 PCIe to 4-Port USB 2.0 Host Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice9710 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9710::DEVICE_9250: return "Unknown device";
        case PciDevice9710::DEVICE_9805: return "Unknown device";
        case PciDevice9710::DEVICE_9815: return enumToHumanString((PciSubDevice97109815)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9710::DEVICE_9820: return "Unknown device";
        case PciDevice9710::DEVICE_9835: return enumToHumanString((PciSubDevice97109835)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9710::DEVICE_9845: return enumToHumanString((PciSubDevice97109845)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9710::DEVICE_9855: return enumToHumanString((PciSubDevice97109855)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9710::DEVICE_9865: return "Unknown device";
        case PciDevice9710::DEVICE_9900: return "Unknown device";
        case PciDevice9710::DEVICE_9901: return "Unknown device";
        case PciDevice9710::DEVICE_9904: return "Unknown device";
        case PciDevice9710::DEVICE_9912: return "Unknown device";
        case PciDevice9710::DEVICE_9922: return "Unknown device";
        case PciDevice9710::DEVICE_9990: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCIDEVICE9710_H
