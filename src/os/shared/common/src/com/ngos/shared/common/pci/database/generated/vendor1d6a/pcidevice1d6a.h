// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6A_PCIDEVICE1D6A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6A_PCIDEVICE1D6A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d6a/pcisubdevice1d6a07b1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d6a/pcisubdevice1d6a94c0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d6a/pcisubdevice1d6ad107.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D6A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_00B1 = 0x00B1,
    DEVICE_07B1 = 0x07B1,
    DEVICE_08B1 = 0x08B1,
    DEVICE_11B1 = 0x11B1,
    DEVICE_12B1 = 0x12B1,
    DEVICE_87B1 = 0x87B1,
    DEVICE_94C0 = 0x94C0,
    DEVICE_D107 = 0xD107,
    DEVICE_D108 = 0xD108
};



inline const char8* enumToString(PciDevice1D6A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D6A::NONE:        return "NONE";
        case PciDevice1D6A::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1D6A::DEVICE_00B1: return "DEVICE_00B1";
        case PciDevice1D6A::DEVICE_07B1: return "DEVICE_07B1";
        case PciDevice1D6A::DEVICE_08B1: return "DEVICE_08B1";
        case PciDevice1D6A::DEVICE_11B1: return "DEVICE_11B1";
        case PciDevice1D6A::DEVICE_12B1: return "DEVICE_12B1";
        case PciDevice1D6A::DEVICE_87B1: return "DEVICE_87B1";
        case PciDevice1D6A::DEVICE_94C0: return "DEVICE_94C0";
        case PciDevice1D6A::DEVICE_D107: return "DEVICE_D107";
        case PciDevice1D6A::DEVICE_D108: return "DEVICE_D108";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D6A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D6A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D6A::DEVICE_0001: return "AQC107 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_00B1: return "AQC100 10G Ethernet MAC controller [AQtion]";
        case PciDevice1D6A::DEVICE_07B1: return "AQC107 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_08B1: return "AQC108 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_11B1: return "AQC111 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_12B1: return "AQC112 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_87B1: return "AQC107 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_94C0: return "AQC113CS NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_D107: return "AQC107 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";
        case PciDevice1D6A::DEVICE_D108: return "AQC108 NBase-T/IEEE 802.3bz Ethernet Controller [AQtion]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1D6A device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D6A::DEVICE_0001: return "Unknown device";
        case PciDevice1D6A::DEVICE_00B1: return "Unknown device";
        case PciDevice1D6A::DEVICE_07B1: return enumToHumanString((PciSubDevice1D6A07B1)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1D6A::DEVICE_08B1: return "Unknown device";
        case PciDevice1D6A::DEVICE_11B1: return "Unknown device";
        case PciDevice1D6A::DEVICE_12B1: return "Unknown device";
        case PciDevice1D6A::DEVICE_87B1: return "Unknown device";
        case PciDevice1D6A::DEVICE_94C0: return enumToHumanString((PciSubDevice1D6A94C0)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1D6A::DEVICE_D107: return enumToHumanString((PciSubDevice1D6AD107)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1D6A::DEVICE_D108: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6A_PCIDEVICE1D6A_H
