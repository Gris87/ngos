// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCIDEVICE1033_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCIDEVICE1033_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcisubdevice10330035.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcisubdevice10330067.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcisubdevice10330074.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcisubdevice103300cd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcisubdevice103300e0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1033/pcisubdevice10330194.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1033: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_0016 = 0x0016,
    DEVICE_001A = 0x001A,
    DEVICE_0021 = 0x0021,
    DEVICE_0029 = 0x0029,
    DEVICE_002A = 0x002A,
    DEVICE_002C = 0x002C,
    DEVICE_002D = 0x002D,
    DEVICE_0035 = 0x0035,
    DEVICE_003B = 0x003B,
    DEVICE_003E = 0x003E,
    DEVICE_0046 = 0x0046,
    DEVICE_005A = 0x005A,
    DEVICE_0063 = 0x0063,
    DEVICE_0067 = 0x0067,
    DEVICE_0072 = 0x0072,
    DEVICE_0074 = 0x0074,
    DEVICE_009B = 0x009B,
    DEVICE_00A5 = 0x00A5,
    DEVICE_00A6 = 0x00A6,
    DEVICE_00CD = 0x00CD,
    DEVICE_00CE = 0x00CE,
    DEVICE_00DF = 0x00DF,
    DEVICE_00E0 = 0x00E0,
    DEVICE_00E7 = 0x00E7,
    DEVICE_00F2 = 0x00F2,
    DEVICE_00F3 = 0x00F3,
    DEVICE_010C = 0x010C,
    DEVICE_0125 = 0x0125,
    DEVICE_013A = 0x013A,
    DEVICE_0194 = 0x0194,
    DEVICE_01E7 = 0x01E7,
    DEVICE_01F2 = 0x01F2
};



inline const char8* enumToString(PciDevice1033 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1033::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1033::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1033::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1033::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1033::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1033::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1033::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1033::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1033::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1033::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1033::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1033::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1033::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1033::DEVICE_0029: return "DEVICE_0029";
        case PciDevice1033::DEVICE_002A: return "DEVICE_002A";
        case PciDevice1033::DEVICE_002C: return "DEVICE_002C";
        case PciDevice1033::DEVICE_002D: return "DEVICE_002D";
        case PciDevice1033::DEVICE_0035: return "DEVICE_0035";
        case PciDevice1033::DEVICE_003B: return "DEVICE_003B";
        case PciDevice1033::DEVICE_003E: return "DEVICE_003E";
        case PciDevice1033::DEVICE_0046: return "DEVICE_0046";
        case PciDevice1033::DEVICE_005A: return "DEVICE_005A";
        case PciDevice1033::DEVICE_0063: return "DEVICE_0063";
        case PciDevice1033::DEVICE_0067: return "DEVICE_0067";
        case PciDevice1033::DEVICE_0072: return "DEVICE_0072";
        case PciDevice1033::DEVICE_0074: return "DEVICE_0074";
        case PciDevice1033::DEVICE_009B: return "DEVICE_009B";
        case PciDevice1033::DEVICE_00A5: return "DEVICE_00A5";
        case PciDevice1033::DEVICE_00A6: return "DEVICE_00A6";
        case PciDevice1033::DEVICE_00CD: return "DEVICE_00CD";
        case PciDevice1033::DEVICE_00CE: return "DEVICE_00CE";
        case PciDevice1033::DEVICE_00DF: return "DEVICE_00DF";
        case PciDevice1033::DEVICE_00E0: return "DEVICE_00E0";
        case PciDevice1033::DEVICE_00E7: return "DEVICE_00E7";
        case PciDevice1033::DEVICE_00F2: return "DEVICE_00F2";
        case PciDevice1033::DEVICE_00F3: return "DEVICE_00F3";
        case PciDevice1033::DEVICE_010C: return "DEVICE_010C";
        case PciDevice1033::DEVICE_0125: return "DEVICE_0125";
        case PciDevice1033::DEVICE_013A: return "DEVICE_013A";
        case PciDevice1033::DEVICE_0194: return "DEVICE_0194";
        case PciDevice1033::DEVICE_01E7: return "DEVICE_01E7";
        case PciDevice1033::DEVICE_01F2: return "DEVICE_01F2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1033 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1033 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1033::DEVICE_0000: return "Vr4181A USB Host or Function Control Unit";
        case PciDevice1033::DEVICE_0001: return "PCI to 486-like bus Bridge";
        case PciDevice1033::DEVICE_0002: return "PCI to VL98 Bridge";
        case PciDevice1033::DEVICE_0003: return "ATM Controller";
        case PciDevice1033::DEVICE_0004: return "R4000 PCI Bridge";
        case PciDevice1033::DEVICE_0005: return "PCI to 486-like bus Bridge";
        case PciDevice1033::DEVICE_0006: return "PC-9800 Graphic Accelerator";
        case PciDevice1033::DEVICE_0007: return "PCI to UX-Bus Bridge";
        case PciDevice1033::DEVICE_0008: return "PC-9800 Graphic Accelerator";
        case PciDevice1033::DEVICE_0009: return "PCI to PC9800 Core-Graph Bridge";
        case PciDevice1033::DEVICE_0016: return "PCI to VL Bridge";
        case PciDevice1033::DEVICE_001A: return "[Nile II]";
        case PciDevice1033::DEVICE_0021: return "Vrc4373 [Nile I]";
        case PciDevice1033::DEVICE_0029: return "PowerVR PCX1";
        case PciDevice1033::DEVICE_002A: return "PowerVR 3D";
        case PciDevice1033::DEVICE_002C: return "Star Alpha 2";
        case PciDevice1033::DEVICE_002D: return "PCI to C-bus Bridge";
        case PciDevice1033::DEVICE_0035: return "OHCI USB Controller";
        case PciDevice1033::DEVICE_003B: return "PCI to C-bus Bridge";
        case PciDevice1033::DEVICE_003E: return "NAPCCARD Cardbus Controller";
        case PciDevice1033::DEVICE_0046: return "PowerVR PCX2 [midas]";
        case PciDevice1033::DEVICE_005A: return "Vrc5074 [Nile 4]";
        case PciDevice1033::DEVICE_0063: return "uPD72862 [Firewarden] IEEE1394 OHCI 1.0 Link Controller";
        case PciDevice1033::DEVICE_0067: return "PowerVR Neon 250 Chipset";
        case PciDevice1033::DEVICE_0072: return "uPD72874 IEEE1394 OHCI 1.1 3-port PHY-Link Ctrlr";
        case PciDevice1033::DEVICE_0074: return "56k Voice Modem";
        case PciDevice1033::DEVICE_009B: return "Vrc5476";
        case PciDevice1033::DEVICE_00A5: return "VRC4173";
        case PciDevice1033::DEVICE_00A6: return "VRC5477 AC97";
        case PciDevice1033::DEVICE_00CD: return "uPD72870 [Firewarden] IEEE1394a OHCI 1.0 Link/3-port PHY Controller";
        case PciDevice1033::DEVICE_00CE: return "uPD72871 [Firewarden] IEEE1394a OHCI 1.0 Link/1-port PHY Controller";
        case PciDevice1033::DEVICE_00DF: return "Vr4131";
        case PciDevice1033::DEVICE_00E0: return "uPD72010x USB 2.0 Controller";
        case PciDevice1033::DEVICE_00E7: return "uPD72873 [Firewarden] IEEE1394a OHCI 1.1 Link/2-port PHY Controller";
        case PciDevice1033::DEVICE_00F2: return "uPD72874 [Firewarden] IEEE1394a OHCI 1.1 Link/3-port PHY Controller";
        case PciDevice1033::DEVICE_00F3: return "uPD6113x Multimedia Decoder/Processor [EMMA2]";
        case PciDevice1033::DEVICE_010C: return "VR7701";
        case PciDevice1033::DEVICE_0125: return "uPD720400 PCI Express - PCI/PCI-X Bridge";
        case PciDevice1033::DEVICE_013A: return "Dual Tuner/MPEG Encoder";
        case PciDevice1033::DEVICE_0194: return "uPD720200 USB 3.0 Host Controller";
        case PciDevice1033::DEVICE_01E7: return "uPD72873 [Firewarden] IEEE1394a OHCI 1.1 Link/2-port PHY Controller";
        case PciDevice1033::DEVICE_01F2: return "uPD72874 [Firewarden] IEEE1394a OHCI 1.1 Link/3-port PHY Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1033 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1033::DEVICE_0000: return "Unknown device";
        case PciDevice1033::DEVICE_0001: return "Unknown device";
        case PciDevice1033::DEVICE_0002: return "Unknown device";
        case PciDevice1033::DEVICE_0003: return "Unknown device";
        case PciDevice1033::DEVICE_0004: return "Unknown device";
        case PciDevice1033::DEVICE_0005: return "Unknown device";
        case PciDevice1033::DEVICE_0006: return "Unknown device";
        case PciDevice1033::DEVICE_0007: return "Unknown device";
        case PciDevice1033::DEVICE_0008: return "Unknown device";
        case PciDevice1033::DEVICE_0009: return "Unknown device";
        case PciDevice1033::DEVICE_0016: return "Unknown device";
        case PciDevice1033::DEVICE_001A: return "Unknown device";
        case PciDevice1033::DEVICE_0021: return "Unknown device";
        case PciDevice1033::DEVICE_0029: return "Unknown device";
        case PciDevice1033::DEVICE_002A: return "Unknown device";
        case PciDevice1033::DEVICE_002C: return "Unknown device";
        case PciDevice1033::DEVICE_002D: return "Unknown device";
        case PciDevice1033::DEVICE_0035: return enumToHumanString((PciSubDevice10330035)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1033::DEVICE_003B: return "Unknown device";
        case PciDevice1033::DEVICE_003E: return "Unknown device";
        case PciDevice1033::DEVICE_0046: return "Unknown device";
        case PciDevice1033::DEVICE_005A: return "Unknown device";
        case PciDevice1033::DEVICE_0063: return "Unknown device";
        case PciDevice1033::DEVICE_0067: return enumToHumanString((PciSubDevice10330067)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1033::DEVICE_0072: return "Unknown device";
        case PciDevice1033::DEVICE_0074: return enumToHumanString((PciSubDevice10330074)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1033::DEVICE_009B: return "Unknown device";
        case PciDevice1033::DEVICE_00A5: return "Unknown device";
        case PciDevice1033::DEVICE_00A6: return "Unknown device";
        case PciDevice1033::DEVICE_00CD: return enumToHumanString((PciSubDevice103300CD)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1033::DEVICE_00CE: return "Unknown device";
        case PciDevice1033::DEVICE_00DF: return "Unknown device";
        case PciDevice1033::DEVICE_00E0: return enumToHumanString((PciSubDevice103300E0)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1033::DEVICE_00E7: return "Unknown device";
        case PciDevice1033::DEVICE_00F2: return "Unknown device";
        case PciDevice1033::DEVICE_00F3: return "Unknown device";
        case PciDevice1033::DEVICE_010C: return "Unknown device";
        case PciDevice1033::DEVICE_0125: return "Unknown device";
        case PciDevice1033::DEVICE_013A: return "Unknown device";
        case PciDevice1033::DEVICE_0194: return enumToHumanString((PciSubDevice10330194)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1033::DEVICE_01E7: return "Unknown device";
        case PciDevice1033::DEVICE_01F2: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCIDEVICE1033_H
