// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCIDEVICE8088_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCIDEVICE8088_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880101.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880102.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880103.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880104.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880105.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880106.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880107.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80880108.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice8088010b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80881001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor8088/pcisubdevice80882001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8088: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0105 = 0x0105,
    DEVICE_0106 = 0x0106,
    DEVICE_0107 = 0x0107,
    DEVICE_0108 = 0x0108,
    DEVICE_0109 = 0x0109,
    DEVICE_010A = 0x010A,
    DEVICE_010B = 0x010B,
    DEVICE_0111 = 0x0111,
    DEVICE_0113 = 0x0113,
    DEVICE_0115 = 0x0115,
    DEVICE_0117 = 0x0117,
    DEVICE_0119 = 0x0119,
    DEVICE_011A = 0x011A,
    DEVICE_011B = 0x011B,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_2000 = 0x2000,
    DEVICE_2001 = 0x2001
};



inline const char8* enumToString(PciDevice8088 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8088::NONE:        return "NONE";
        case PciDevice8088::DEVICE_0101: return "DEVICE_0101";
        case PciDevice8088::DEVICE_0102: return "DEVICE_0102";
        case PciDevice8088::DEVICE_0103: return "DEVICE_0103";
        case PciDevice8088::DEVICE_0104: return "DEVICE_0104";
        case PciDevice8088::DEVICE_0105: return "DEVICE_0105";
        case PciDevice8088::DEVICE_0106: return "DEVICE_0106";
        case PciDevice8088::DEVICE_0107: return "DEVICE_0107";
        case PciDevice8088::DEVICE_0108: return "DEVICE_0108";
        case PciDevice8088::DEVICE_0109: return "DEVICE_0109";
        case PciDevice8088::DEVICE_010A: return "DEVICE_010A";
        case PciDevice8088::DEVICE_010B: return "DEVICE_010B";
        case PciDevice8088::DEVICE_0111: return "DEVICE_0111";
        case PciDevice8088::DEVICE_0113: return "DEVICE_0113";
        case PciDevice8088::DEVICE_0115: return "DEVICE_0115";
        case PciDevice8088::DEVICE_0117: return "DEVICE_0117";
        case PciDevice8088::DEVICE_0119: return "DEVICE_0119";
        case PciDevice8088::DEVICE_011A: return "DEVICE_011A";
        case PciDevice8088::DEVICE_011B: return "DEVICE_011B";
        case PciDevice8088::DEVICE_1000: return "DEVICE_1000";
        case PciDevice8088::DEVICE_1001: return "DEVICE_1001";
        case PciDevice8088::DEVICE_2000: return "DEVICE_2000";
        case PciDevice8088::DEVICE_2001: return "DEVICE_2001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8088 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice8088 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8088::DEVICE_0101: return "WX1860A2 Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0102: return "WX1860A2S Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0103: return "WX1860A4 Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0104: return "WX1860A4S Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0105: return "WX1860AL2 Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0106: return "WX1860AL2S Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0107: return "WX1860AL4 Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0108: return "WX1860AL4S Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0109: return "WX1860-LC Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_010A: return "WX1860A1 Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_010B: return "WX1860AL1 Gigabit Ethernet Controller";
        case PciDevice8088::DEVICE_0111: return "WX1860A2 Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_0113: return "WX1860A4 Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_0115: return "WX1860AL2 Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_0117: return "WX1860AL4 Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_0119: return "WX1860-LC Gigabit Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_011A: return "WX1860A1 Gigabit Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_011B: return "WX1860AL1 Gigabit Ethernet Controller Virtual Function";
        case PciDevice8088::DEVICE_1000: return "Ethernet Controller RP1000 Virtual Function for 10GbE SFP+";
        case PciDevice8088::DEVICE_1001: return "Ethernet Controller RP1000 for 10GbE SFP+";
        case PciDevice8088::DEVICE_2000: return "Ethernet Controller RP2000 Virtual Function for 10GbE SFP+";
        case PciDevice8088::DEVICE_2001: return "Ethernet Controller RP2000 for 10GbE SFP+";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice8088 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8088::DEVICE_0101: return enumToHumanString((PciSubDevice80880101)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0102: return enumToHumanString((PciSubDevice80880102)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0103: return enumToHumanString((PciSubDevice80880103)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0104: return enumToHumanString((PciSubDevice80880104)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0105: return enumToHumanString((PciSubDevice80880105)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0106: return enumToHumanString((PciSubDevice80880106)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0107: return enumToHumanString((PciSubDevice80880107)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0108: return enumToHumanString((PciSubDevice80880108)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0109: return "Unknown device";
        case PciDevice8088::DEVICE_010A: return "Unknown device";
        case PciDevice8088::DEVICE_010B: return enumToHumanString((PciSubDevice8088010B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_0111: return "Unknown device";
        case PciDevice8088::DEVICE_0113: return "Unknown device";
        case PciDevice8088::DEVICE_0115: return "Unknown device";
        case PciDevice8088::DEVICE_0117: return "Unknown device";
        case PciDevice8088::DEVICE_0119: return "Unknown device";
        case PciDevice8088::DEVICE_011A: return "Unknown device";
        case PciDevice8088::DEVICE_011B: return "Unknown device";
        case PciDevice8088::DEVICE_1000: return "Unknown device";
        case PciDevice8088::DEVICE_1001: return enumToHumanString((PciSubDevice80881001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice8088::DEVICE_2000: return "Unknown device";
        case PciDevice8088::DEVICE_2001: return enumToHumanString((PciSubDevice80882001)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCIDEVICE8088_H
