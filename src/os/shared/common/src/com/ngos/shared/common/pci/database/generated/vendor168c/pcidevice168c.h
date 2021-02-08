// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCIDEVICE168C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCIDEVICE168C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0007.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0012.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0013.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c001a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c001b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c001c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c001d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0020.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0023.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0024.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0027.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0029.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c002a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c002b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c002e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0030.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0032.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0033.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0034.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0036.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0037.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c003e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c0042.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168c1014.h>
#include <com/ngos/shared/common/pci/database/generated/vendor168c/pcisubdevice168cff1d.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice168C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0007 = 0x0007,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_001A = 0x001A,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001D = 0x001D,
    DEVICE_0020 = 0x0020,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_0027 = 0x0027,
    DEVICE_0029 = 0x0029,
    DEVICE_002A = 0x002A,
    DEVICE_002B = 0x002B,
    DEVICE_002C = 0x002C,
    DEVICE_002D = 0x002D,
    DEVICE_002E = 0x002E,
    DEVICE_0030 = 0x0030,
    DEVICE_0032 = 0x0032,
    DEVICE_0033 = 0x0033,
    DEVICE_0034 = 0x0034,
    DEVICE_0036 = 0x0036,
    DEVICE_0037 = 0x0037,
    DEVICE_003C = 0x003C,
    DEVICE_003E = 0x003E,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0046 = 0x0046,
    DEVICE_0050 = 0x0050,
    DEVICE_0207 = 0x0207,
    DEVICE_1014 = 0x1014,
    DEVICE_9013 = 0x9013,
    DEVICE_FF19 = 0xFF19,
    DEVICE_FF1B = 0xFF1B,
    DEVICE_FF1C = 0xFF1C,
    DEVICE_FF1D = 0xFF1D
};



inline const char8* enumToString(PciDevice168C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice168C::NONE:        return "NONE";
        case PciDevice168C::DEVICE_0007: return "DEVICE_0007";
        case PciDevice168C::DEVICE_0011: return "DEVICE_0011";
        case PciDevice168C::DEVICE_0012: return "DEVICE_0012";
        case PciDevice168C::DEVICE_0013: return "DEVICE_0013";
        case PciDevice168C::DEVICE_001A: return "DEVICE_001A";
        case PciDevice168C::DEVICE_001B: return "DEVICE_001B";
        case PciDevice168C::DEVICE_001C: return "DEVICE_001C";
        case PciDevice168C::DEVICE_001D: return "DEVICE_001D";
        case PciDevice168C::DEVICE_0020: return "DEVICE_0020";
        case PciDevice168C::DEVICE_0023: return "DEVICE_0023";
        case PciDevice168C::DEVICE_0024: return "DEVICE_0024";
        case PciDevice168C::DEVICE_0027: return "DEVICE_0027";
        case PciDevice168C::DEVICE_0029: return "DEVICE_0029";
        case PciDevice168C::DEVICE_002A: return "DEVICE_002A";
        case PciDevice168C::DEVICE_002B: return "DEVICE_002B";
        case PciDevice168C::DEVICE_002C: return "DEVICE_002C";
        case PciDevice168C::DEVICE_002D: return "DEVICE_002D";
        case PciDevice168C::DEVICE_002E: return "DEVICE_002E";
        case PciDevice168C::DEVICE_0030: return "DEVICE_0030";
        case PciDevice168C::DEVICE_0032: return "DEVICE_0032";
        case PciDevice168C::DEVICE_0033: return "DEVICE_0033";
        case PciDevice168C::DEVICE_0034: return "DEVICE_0034";
        case PciDevice168C::DEVICE_0036: return "DEVICE_0036";
        case PciDevice168C::DEVICE_0037: return "DEVICE_0037";
        case PciDevice168C::DEVICE_003C: return "DEVICE_003C";
        case PciDevice168C::DEVICE_003E: return "DEVICE_003E";
        case PciDevice168C::DEVICE_0040: return "DEVICE_0040";
        case PciDevice168C::DEVICE_0041: return "DEVICE_0041";
        case PciDevice168C::DEVICE_0042: return "DEVICE_0042";
        case PciDevice168C::DEVICE_0046: return "DEVICE_0046";
        case PciDevice168C::DEVICE_0050: return "DEVICE_0050";
        case PciDevice168C::DEVICE_0207: return "DEVICE_0207";
        case PciDevice168C::DEVICE_1014: return "DEVICE_1014";
        case PciDevice168C::DEVICE_9013: return "DEVICE_9013";
        case PciDevice168C::DEVICE_FF19: return "DEVICE_FF19";
        case PciDevice168C::DEVICE_FF1B: return "DEVICE_FF1B";
        case PciDevice168C::DEVICE_FF1C: return "DEVICE_FF1C";
        case PciDevice168C::DEVICE_FF1D: return "DEVICE_FF1D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice168C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice168C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice168C::DEVICE_0007: return "AR5210 Wireless Network Adapter [AR5000 802.11a]";
        case PciDevice168C::DEVICE_0011: return "AR5211 Wireless Network Adapter [AR5001A 802.11a]";
        case PciDevice168C::DEVICE_0012: return "AR5211 Wireless Network Adapter [AR5001X 802.11ab]";
        case PciDevice168C::DEVICE_0013: return "AR5212/5213/2414 Wireless Network Adapter";
        case PciDevice168C::DEVICE_001A: return "AR2413/AR2414 Wireless Network Adapter [AR5005G(S) 802.11bg]";
        case PciDevice168C::DEVICE_001B: return "AR5413/AR5414 Wireless Network Adapter [AR5006X(S) 802.11abg]";
        case PciDevice168C::DEVICE_001C: return "AR242x / AR542x Wireless Network Adapter (PCI-Express)";
        case PciDevice168C::DEVICE_001D: return "AR2417 Wireless Network Adapter [AR5007G 802.11bg]";
        case PciDevice168C::DEVICE_0020: return "AR5513 802.11abg Wireless NIC";
        case PciDevice168C::DEVICE_0023: return "AR5416 Wireless Network Adapter [AR5008 802.11(a)bgn]";
        case PciDevice168C::DEVICE_0024: return "AR5418 Wireless Network Adapter [AR5008E 802.11(a)bgn] (PCI-Express)";
        case PciDevice168C::DEVICE_0027: return "AR9160 Wireless Network Adapter [AR9001 802.11(a)bgn]";
        case PciDevice168C::DEVICE_0029: return "AR922X Wireless Network Adapter";
        case PciDevice168C::DEVICE_002A: return "AR928X Wireless Network Adapter (PCI-Express)";
        case PciDevice168C::DEVICE_002B: return "AR9285 Wireless Network Adapter (PCI-Express)";
        case PciDevice168C::DEVICE_002C: return "AR2427 802.11bg Wireless Network Adapter (PCI-Express)";
        case PciDevice168C::DEVICE_002D: return "AR9227 Wireless Network Adapter";
        case PciDevice168C::DEVICE_002E: return "AR9287 Wireless Network Adapter (PCI-Express)";
        case PciDevice168C::DEVICE_0030: return "AR93xx Wireless Network Adapter";
        case PciDevice168C::DEVICE_0032: return "AR9485 Wireless Network Adapter";
        case PciDevice168C::DEVICE_0033: return "AR958x 802.11abgn Wireless Network Adapter";
        case PciDevice168C::DEVICE_0034: return "AR9462 Wireless Network Adapter";
        case PciDevice168C::DEVICE_0036: return "QCA9565 / AR9565 Wireless Network Adapter";
        case PciDevice168C::DEVICE_0037: return "AR9485 Wireless Network Adapter";
        case PciDevice168C::DEVICE_003C: return "QCA986x/988x 802.11ac Wireless Network Adapter";
        case PciDevice168C::DEVICE_003E: return "QCA6174 802.11ac Wireless Network Adapter";
        case PciDevice168C::DEVICE_0040: return "QCA9980/9990 802.11ac Wireless Network Adapter";
        case PciDevice168C::DEVICE_0041: return "QCA6164 802.11ac Wireless Network Adapter";
        case PciDevice168C::DEVICE_0042: return "QCA9377 802.11ac Wireless Network Adapter";
        case PciDevice168C::DEVICE_0046: return "QCA9984 802.11ac Wave 2 Wireless Network Adapter";
        case PciDevice168C::DEVICE_0050: return "QCA9887 802.11ac Wireless Network Adapter";
        case PciDevice168C::DEVICE_0207: return "AR5210 Wireless Network Adapter [AR5000 802.11a]";
        case PciDevice168C::DEVICE_1014: return "AR5212 802.11abg NIC";
        case PciDevice168C::DEVICE_9013: return "AR5002X Wireless Network Adapter";
        case PciDevice168C::DEVICE_FF19: return "AR5006X Wireless Network Adapter";
        case PciDevice168C::DEVICE_FF1B: return "AR2425 Wireless Network Adapter [AR5007EG 802.11bg]";
        case PciDevice168C::DEVICE_FF1C: return "AR5008 Wireless Network Adapter";
        case PciDevice168C::DEVICE_FF1D: return "AR922x Wireless Network Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice168C device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice168C::DEVICE_0007: return enumToHumanString((PciSubDevice168C0007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0011: return "Unknown device";
        case PciDevice168C::DEVICE_0012: return enumToHumanString((PciSubDevice168C0012)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0013: return enumToHumanString((PciSubDevice168C0013)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_001A: return enumToHumanString((PciSubDevice168C001A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_001B: return enumToHumanString((PciSubDevice168C001B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_001C: return enumToHumanString((PciSubDevice168C001C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_001D: return enumToHumanString((PciSubDevice168C001D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0020: return enumToHumanString((PciSubDevice168C0020)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0023: return enumToHumanString((PciSubDevice168C0023)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0024: return enumToHumanString((PciSubDevice168C0024)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0027: return enumToHumanString((PciSubDevice168C0027)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0029: return enumToHumanString((PciSubDevice168C0029)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_002A: return enumToHumanString((PciSubDevice168C002A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_002B: return enumToHumanString((PciSubDevice168C002B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_002C: return "Unknown device";
        case PciDevice168C::DEVICE_002D: return "Unknown device";
        case PciDevice168C::DEVICE_002E: return enumToHumanString((PciSubDevice168C002E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0030: return enumToHumanString((PciSubDevice168C0030)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0032: return enumToHumanString((PciSubDevice168C0032)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0033: return enumToHumanString((PciSubDevice168C0033)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0034: return enumToHumanString((PciSubDevice168C0034)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0036: return enumToHumanString((PciSubDevice168C0036)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0037: return enumToHumanString((PciSubDevice168C0037)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_003C: return "Unknown device";
        case PciDevice168C::DEVICE_003E: return enumToHumanString((PciSubDevice168C003E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0040: return "Unknown device";
        case PciDevice168C::DEVICE_0041: return "Unknown device";
        case PciDevice168C::DEVICE_0042: return enumToHumanString((PciSubDevice168C0042)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_0046: return "Unknown device";
        case PciDevice168C::DEVICE_0050: return "Unknown device";
        case PciDevice168C::DEVICE_0207: return "Unknown device";
        case PciDevice168C::DEVICE_1014: return enumToHumanString((PciSubDevice168C1014)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice168C::DEVICE_9013: return "Unknown device";
        case PciDevice168C::DEVICE_FF19: return "Unknown device";
        case PciDevice168C::DEVICE_FF1B: return "Unknown device";
        case PciDevice168C::DEVICE_FF1C: return "Unknown device";
        case PciDevice168C::DEVICE_FF1D: return enumToHumanString((PciSubDevice168CFF1D)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCIDEVICE168C_H
