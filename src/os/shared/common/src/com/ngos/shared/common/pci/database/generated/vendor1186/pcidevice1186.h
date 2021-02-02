// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCIDEVICE1186_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCIDEVICE1186_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcisubdevice11861002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcisubdevice11861300.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcisubdevice11863300.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcisubdevice11864200.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcisubdevice11864300.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1186/pcisubdevice11864c00.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1186: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1002 = 0x1002,
    DEVICE_1025 = 0x1025,
    DEVICE_1026 = 0x1026,
    DEVICE_1043 = 0x1043,
    DEVICE_1300 = 0x1300,
    DEVICE_1340 = 0x1340,
    DEVICE_1540 = 0x1540,
    DEVICE_1541 = 0x1541,
    DEVICE_1561 = 0x1561,
    DEVICE_3300 = 0x3300,
    DEVICE_3A10 = 0x3A10,
    DEVICE_3A11 = 0x3A11,
    DEVICE_4000 = 0x4000,
    DEVICE_4001 = 0x4001,
    DEVICE_4200 = 0x4200,
    DEVICE_4300 = 0x4300,
    DEVICE_4302 = 0x4302,
    DEVICE_4B00 = 0x4B00,
    DEVICE_4B01 = 0x4B01,
    DEVICE_4B02 = 0x4B02,
    DEVICE_4B03 = 0x4B03,
    DEVICE_4C00 = 0x4C00,
    DEVICE_8400 = 0x8400
};



inline const char8* enumToString(PciDevice1186 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1186::NONE:        return "NONE";
        case PciDevice1186::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1186::DEVICE_1025: return "DEVICE_1025";
        case PciDevice1186::DEVICE_1026: return "DEVICE_1026";
        case PciDevice1186::DEVICE_1043: return "DEVICE_1043";
        case PciDevice1186::DEVICE_1300: return "DEVICE_1300";
        case PciDevice1186::DEVICE_1340: return "DEVICE_1340";
        case PciDevice1186::DEVICE_1540: return "DEVICE_1540";
        case PciDevice1186::DEVICE_1541: return "DEVICE_1541";
        case PciDevice1186::DEVICE_1561: return "DEVICE_1561";
        case PciDevice1186::DEVICE_3300: return "DEVICE_3300";
        case PciDevice1186::DEVICE_3A10: return "DEVICE_3A10";
        case PciDevice1186::DEVICE_3A11: return "DEVICE_3A11";
        case PciDevice1186::DEVICE_4000: return "DEVICE_4000";
        case PciDevice1186::DEVICE_4001: return "DEVICE_4001";
        case PciDevice1186::DEVICE_4200: return "DEVICE_4200";
        case PciDevice1186::DEVICE_4300: return "DEVICE_4300";
        case PciDevice1186::DEVICE_4302: return "DEVICE_4302";
        case PciDevice1186::DEVICE_4B00: return "DEVICE_4B00";
        case PciDevice1186::DEVICE_4B01: return "DEVICE_4B01";
        case PciDevice1186::DEVICE_4B02: return "DEVICE_4B02";
        case PciDevice1186::DEVICE_4B03: return "DEVICE_4B03";
        case PciDevice1186::DEVICE_4C00: return "DEVICE_4C00";
        case PciDevice1186::DEVICE_8400: return "DEVICE_8400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1186 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1186 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1186::DEVICE_1002: return "DL10050 Sundance Ethernet";
        case PciDevice1186::DEVICE_1025: return "AirPlus Xtreme G DWL-G650 Adapter";
        case PciDevice1186::DEVICE_1026: return "AirXpert DWL-AG650 Wireless Cardbus Adapter";
        case PciDevice1186::DEVICE_1043: return "AirXpert DWL-AG650 Wireless Cardbus Adapter";
        case PciDevice1186::DEVICE_1300: return "RTL8139 Ethernet";
        case PciDevice1186::DEVICE_1340: return "DFE-690TXD CardBus PC Card";
        case PciDevice1186::DEVICE_1540: return "DFE-680TX";
        case PciDevice1186::DEVICE_1541: return "DFE-680TXD CardBus PC Card";
        case PciDevice1186::DEVICE_1561: return "DRP-32TXD Cardbus PC Card";
        case PciDevice1186::DEVICE_3300: return "DWL-510 / DWL-610 802.11b [Realtek RTL8180L]";
        case PciDevice1186::DEVICE_3A10: return "AirXpert DWL-AG650 Wireless Cardbus Adapter(rev.B)";
        case PciDevice1186::DEVICE_3A11: return "AirXpert DWL-AG520 Wireless PCI Adapter(rev.B)";
        case PciDevice1186::DEVICE_4000: return "DL2000-based Gigabit Ethernet";
        case PciDevice1186::DEVICE_4001: return "DGE-550SX PCI-X Gigabit Ethernet Adapter";
        case PciDevice1186::DEVICE_4200: return "DFE-520TX Fast Ethernet PCI Adapter";
        case PciDevice1186::DEVICE_4300: return "DGE-528T Gigabit Ethernet Adapter";
        case PciDevice1186::DEVICE_4302: return "DGE-530T Gigabit Ethernet Adapter (rev.C1) [Realtek RTL8169]";
        case PciDevice1186::DEVICE_4B00: return "DGE-560T PCI Express Gigabit Ethernet Adapter";
        case PciDevice1186::DEVICE_4B01: return "DGE-530T Gigabit Ethernet Adapter (rev 11)";
        case PciDevice1186::DEVICE_4B02: return "DGE-560SX PCI Express Gigabit Ethernet Adapter";
        case PciDevice1186::DEVICE_4B03: return "DGE-550T Gigabit Ethernet Adapter V.B1";
        case PciDevice1186::DEVICE_4C00: return "Gigabit Ethernet Adapter";
        case PciDevice1186::DEVICE_8400: return "D-Link DWL-650+ CardBus PC Card";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1186 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1186::DEVICE_1002: return enumToHumanString((PciSubDevice11861002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1186::DEVICE_1025: return "Unknown device";
        case PciDevice1186::DEVICE_1026: return "Unknown device";
        case PciDevice1186::DEVICE_1043: return "Unknown device";
        case PciDevice1186::DEVICE_1300: return enumToHumanString((PciSubDevice11861300)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1186::DEVICE_1340: return "Unknown device";
        case PciDevice1186::DEVICE_1540: return "Unknown device";
        case PciDevice1186::DEVICE_1541: return "Unknown device";
        case PciDevice1186::DEVICE_1561: return "Unknown device";
        case PciDevice1186::DEVICE_3300: return enumToHumanString((PciSubDevice11863300)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1186::DEVICE_3A10: return "Unknown device";
        case PciDevice1186::DEVICE_3A11: return "Unknown device";
        case PciDevice1186::DEVICE_4000: return "Unknown device";
        case PciDevice1186::DEVICE_4001: return "Unknown device";
        case PciDevice1186::DEVICE_4200: return enumToHumanString((PciSubDevice11864200)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1186::DEVICE_4300: return enumToHumanString((PciSubDevice11864300)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1186::DEVICE_4302: return "Unknown device";
        case PciDevice1186::DEVICE_4B00: return "Unknown device";
        case PciDevice1186::DEVICE_4B01: return "Unknown device";
        case PciDevice1186::DEVICE_4B02: return "Unknown device";
        case PciDevice1186::DEVICE_4B03: return "Unknown device";
        case PciDevice1186::DEVICE_4C00: return enumToHumanString((PciSubDevice11864C00)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1186::DEVICE_8400: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCIDEVICE1186_H
