// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102F_PCIDEVICE102F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102F_PCIDEVICE102F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102f/pcisubdevice102f0020.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice102F: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_0020 = 0x0020,
    DEVICE_0030 = 0x0030,
    DEVICE_0031 = 0x0031,
    DEVICE_0032 = 0x0032,
    DEVICE_0105 = 0x0105,
    DEVICE_0106 = 0x0106,
    DEVICE_0107 = 0x0107,
    DEVICE_0108 = 0x0108,
    DEVICE_0180 = 0x0180,
    DEVICE_0181 = 0x0181,
    DEVICE_0182 = 0x0182,
    DEVICE_01B4 = 0x01B4,
    DEVICE_01B5 = 0x01B5,
    DEVICE_01B6 = 0x01B6
};



inline const char8* enumToString(PciDevice102F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice102F::NONE:        return "NONE";
        case PciDevice102F::DEVICE_0009: return "DEVICE_0009";
        case PciDevice102F::DEVICE_000A: return "DEVICE_000A";
        case PciDevice102F::DEVICE_0020: return "DEVICE_0020";
        case PciDevice102F::DEVICE_0030: return "DEVICE_0030";
        case PciDevice102F::DEVICE_0031: return "DEVICE_0031";
        case PciDevice102F::DEVICE_0032: return "DEVICE_0032";
        case PciDevice102F::DEVICE_0105: return "DEVICE_0105";
        case PciDevice102F::DEVICE_0106: return "DEVICE_0106";
        case PciDevice102F::DEVICE_0107: return "DEVICE_0107";
        case PciDevice102F::DEVICE_0108: return "DEVICE_0108";
        case PciDevice102F::DEVICE_0180: return "DEVICE_0180";
        case PciDevice102F::DEVICE_0181: return "DEVICE_0181";
        case PciDevice102F::DEVICE_0182: return "DEVICE_0182";
        case PciDevice102F::DEVICE_01B4: return "DEVICE_01B4";
        case PciDevice102F::DEVICE_01B5: return "DEVICE_01B5";
        case PciDevice102F::DEVICE_01B6: return "DEVICE_01B6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice102F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice102F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice102F::DEVICE_0009: return "r4x00";
        case PciDevice102F::DEVICE_000A: return "TX3927 MIPS RISC PCI Controller";
        case PciDevice102F::DEVICE_0020: return "ATM Meteor 155";
        case PciDevice102F::DEVICE_0030: return "TC35815CF PCI 10/100 Mbit Ethernet Controller";
        case PciDevice102F::DEVICE_0031: return "TC35815CF PCI 10/100 Mbit Ethernet Controller with WOL";
        case PciDevice102F::DEVICE_0032: return "TC35815CF PCI 10/100 Mbit Ethernet Controller on TX4939";
        case PciDevice102F::DEVICE_0105: return "TC86C001 [goku-s] IDE";
        case PciDevice102F::DEVICE_0106: return "TC86C001 [goku-s] USB 1.1 Host";
        case PciDevice102F::DEVICE_0107: return "TC86C001 [goku-s] USB Device Controller";
        case PciDevice102F::DEVICE_0108: return "TC86C001 [goku-s] I2C/SIO/GPIO Controller";
        case PciDevice102F::DEVICE_0180: return "TX4927/38 MIPS RISC PCI Controller";
        case PciDevice102F::DEVICE_0181: return "TX4925 MIPS RISC PCI Controller";
        case PciDevice102F::DEVICE_0182: return "TX4937 MIPS RISC PCI Controller";
        case PciDevice102F::DEVICE_01B4: return "Celleb platform IDE interface";
        case PciDevice102F::DEVICE_01B5: return "SCC USB 2.0 EHCI controller";
        case PciDevice102F::DEVICE_01B6: return "SCC USB 1.1 OHCI controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice102F device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice102F::DEVICE_0009: return "Unknown device";
        case PciDevice102F::DEVICE_000A: return "Unknown device";
        case PciDevice102F::DEVICE_0020: return enumToHumanString((PciSubDevice102F0020)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice102F::DEVICE_0030: return "Unknown device";
        case PciDevice102F::DEVICE_0031: return "Unknown device";
        case PciDevice102F::DEVICE_0032: return "Unknown device";
        case PciDevice102F::DEVICE_0105: return "Unknown device";
        case PciDevice102F::DEVICE_0106: return "Unknown device";
        case PciDevice102F::DEVICE_0107: return "Unknown device";
        case PciDevice102F::DEVICE_0108: return "Unknown device";
        case PciDevice102F::DEVICE_0180: return "Unknown device";
        case PciDevice102F::DEVICE_0181: return "Unknown device";
        case PciDevice102F::DEVICE_0182: return "Unknown device";
        case PciDevice102F::DEVICE_01B4: return "Unknown device";
        case PciDevice102F::DEVICE_01B5: return "Unknown device";
        case PciDevice102F::DEVICE_01B6: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102F_PCIDEVICE102F_H
