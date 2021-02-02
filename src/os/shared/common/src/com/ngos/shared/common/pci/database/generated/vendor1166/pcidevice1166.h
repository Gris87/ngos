// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCIDEVICE1166_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCIDEVICE1166_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660132.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660201.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660203.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660212.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660213.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660214.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660217.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660220.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660221.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660223.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660227.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660230.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice11660234.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice1166024a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice1166024b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1166/pcisubdevice1166040a.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1166: bad_uint16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_0031 = 0x0031,
    DEVICE_0036 = 0x0036,
    DEVICE_0101 = 0x0101,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0110 = 0x0110,
    DEVICE_0130 = 0x0130,
    DEVICE_0132 = 0x0132,
    DEVICE_0140 = 0x0140,
    DEVICE_0141 = 0x0141,
    DEVICE_0142 = 0x0142,
    DEVICE_0144 = 0x0144,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_0203 = 0x0203,
    DEVICE_0205 = 0x0205,
    DEVICE_0211 = 0x0211,
    DEVICE_0212 = 0x0212,
    DEVICE_0213 = 0x0213,
    DEVICE_0214 = 0x0214,
    DEVICE_0217 = 0x0217,
    DEVICE_021B = 0x021B,
    DEVICE_0220 = 0x0220,
    DEVICE_0221 = 0x0221,
    DEVICE_0223 = 0x0223,
    DEVICE_0225 = 0x0225,
    DEVICE_0227 = 0x0227,
    DEVICE_0230 = 0x0230,
    DEVICE_0234 = 0x0234,
    DEVICE_0235 = 0x0235,
    DEVICE_0238 = 0x0238,
    DEVICE_0240 = 0x0240,
    DEVICE_0241 = 0x0241,
    DEVICE_0242 = 0x0242,
    DEVICE_024A = 0x024A,
    DEVICE_024B = 0x024B,
    DEVICE_0406 = 0x0406,
    DEVICE_0408 = 0x0408,
    DEVICE_040A = 0x040A,
    DEVICE_0410 = 0x0410,
    DEVICE_0411 = 0x0411,
    DEVICE_0412 = 0x0412,
    DEVICE_0414 = 0x0414,
    DEVICE_0416 = 0x0416,
    DEVICE_0420 = 0x0420,
    DEVICE_0421 = 0x0421,
    DEVICE_0422 = 0x0422
};



inline const char8* enumToString(PciDevice1166 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1166::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1166::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1166::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1166::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1166::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1166::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1166::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1166::DEVICE_0011: return "DEVICE_0011";
        case PciDevice1166::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1166::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1166::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1166::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1166::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1166::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1166::DEVICE_0031: return "DEVICE_0031";
        case PciDevice1166::DEVICE_0036: return "DEVICE_0036";
        case PciDevice1166::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1166::DEVICE_0103: return "DEVICE_0103";
        case PciDevice1166::DEVICE_0104: return "DEVICE_0104";
        case PciDevice1166::DEVICE_0110: return "DEVICE_0110";
        case PciDevice1166::DEVICE_0130: return "DEVICE_0130";
        case PciDevice1166::DEVICE_0132: return "DEVICE_0132";
        case PciDevice1166::DEVICE_0140: return "DEVICE_0140";
        case PciDevice1166::DEVICE_0141: return "DEVICE_0141";
        case PciDevice1166::DEVICE_0142: return "DEVICE_0142";
        case PciDevice1166::DEVICE_0144: return "DEVICE_0144";
        case PciDevice1166::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1166::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1166::DEVICE_0203: return "DEVICE_0203";
        case PciDevice1166::DEVICE_0205: return "DEVICE_0205";
        case PciDevice1166::DEVICE_0211: return "DEVICE_0211";
        case PciDevice1166::DEVICE_0212: return "DEVICE_0212";
        case PciDevice1166::DEVICE_0213: return "DEVICE_0213";
        case PciDevice1166::DEVICE_0214: return "DEVICE_0214";
        case PciDevice1166::DEVICE_0217: return "DEVICE_0217";
        case PciDevice1166::DEVICE_021B: return "DEVICE_021B";
        case PciDevice1166::DEVICE_0220: return "DEVICE_0220";
        case PciDevice1166::DEVICE_0221: return "DEVICE_0221";
        case PciDevice1166::DEVICE_0223: return "DEVICE_0223";
        case PciDevice1166::DEVICE_0225: return "DEVICE_0225";
        case PciDevice1166::DEVICE_0227: return "DEVICE_0227";
        case PciDevice1166::DEVICE_0230: return "DEVICE_0230";
        case PciDevice1166::DEVICE_0234: return "DEVICE_0234";
        case PciDevice1166::DEVICE_0235: return "DEVICE_0235";
        case PciDevice1166::DEVICE_0238: return "DEVICE_0238";
        case PciDevice1166::DEVICE_0240: return "DEVICE_0240";
        case PciDevice1166::DEVICE_0241: return "DEVICE_0241";
        case PciDevice1166::DEVICE_0242: return "DEVICE_0242";
        case PciDevice1166::DEVICE_024A: return "DEVICE_024A";
        case PciDevice1166::DEVICE_024B: return "DEVICE_024B";
        case PciDevice1166::DEVICE_0406: return "DEVICE_0406";
        case PciDevice1166::DEVICE_0408: return "DEVICE_0408";
        case PciDevice1166::DEVICE_040A: return "DEVICE_040A";
        case PciDevice1166::DEVICE_0410: return "DEVICE_0410";
        case PciDevice1166::DEVICE_0411: return "DEVICE_0411";
        case PciDevice1166::DEVICE_0412: return "DEVICE_0412";
        case PciDevice1166::DEVICE_0414: return "DEVICE_0414";
        case PciDevice1166::DEVICE_0416: return "DEVICE_0416";
        case PciDevice1166::DEVICE_0420: return "DEVICE_0420";
        case PciDevice1166::DEVICE_0421: return "DEVICE_0421";
        case PciDevice1166::DEVICE_0422: return "DEVICE_0422";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1166 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1166 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1166::DEVICE_0000: return "CMIC-LE";
        case PciDevice1166::DEVICE_0005: return "CNB20-LE Host Bridge";
        case PciDevice1166::DEVICE_0006: return "CNB20HE Host Bridge";
        case PciDevice1166::DEVICE_0007: return "CNB20-LE Host Bridge";
        case PciDevice1166::DEVICE_0008: return "CNB20HE Host Bridge";
        case PciDevice1166::DEVICE_0009: return "CNB20LE Host Bridge";
        case PciDevice1166::DEVICE_0010: return "CIOB30";
        case PciDevice1166::DEVICE_0011: return "CMIC-HE";
        case PciDevice1166::DEVICE_0012: return "CMIC-WS Host Bridge (GC-LE chipset)";
        case PciDevice1166::DEVICE_0013: return "CNB20-HE Host Bridge";
        case PciDevice1166::DEVICE_0014: return "CMIC-LE Host Bridge (GC-LE chipset)";
        case PciDevice1166::DEVICE_0015: return "CMIC-GC Host Bridge";
        case PciDevice1166::DEVICE_0016: return "CMIC-GC Host Bridge";
        case PciDevice1166::DEVICE_0017: return "GCNB-LE Host Bridge";
        case PciDevice1166::DEVICE_0031: return "HT1100 HPX0 HT Host Bridge";
        case PciDevice1166::DEVICE_0036: return "BCM5785 [HT1000] PCI/PCI-X Bridge";
        case PciDevice1166::DEVICE_0101: return "CIOB-X2 PCI-X I/O Bridge";
        case PciDevice1166::DEVICE_0103: return "EPB PCI-Express to PCI-X Bridge";
        case PciDevice1166::DEVICE_0104: return "BCM5785 [HT1000] PCI/PCI-X Bridge";
        case PciDevice1166::DEVICE_0110: return "CIOB-E I/O Bridge with Gigabit Ethernet";
        case PciDevice1166::DEVICE_0130: return "BCM5780 [HT2000] PCI-X bridge";
        case PciDevice1166::DEVICE_0132: return "BCM5780 [HT2000] PCI-Express Bridge";
        case PciDevice1166::DEVICE_0140: return "HT2100 PCI-Express Bridge";
        case PciDevice1166::DEVICE_0141: return "HT2100 PCI-Express Bridge";
        case PciDevice1166::DEVICE_0142: return "HT2100 PCI-Express Bridge";
        case PciDevice1166::DEVICE_0144: return "HT2100 PCI-Express Bridge";
        case PciDevice1166::DEVICE_0200: return "OSB4 South Bridge";
        case PciDevice1166::DEVICE_0201: return "CSB5 South Bridge";
        case PciDevice1166::DEVICE_0203: return "CSB6 South Bridge";
        case PciDevice1166::DEVICE_0205: return "BCM5785 [HT1000] Legacy South Bridge";
        case PciDevice1166::DEVICE_0211: return "OSB4 IDE Controller";
        case PciDevice1166::DEVICE_0212: return "CSB5 IDE Controller";
        case PciDevice1166::DEVICE_0213: return "CSB6 RAID/IDE Controller";
        case PciDevice1166::DEVICE_0214: return "BCM5785 [HT1000] IDE";
        case PciDevice1166::DEVICE_0217: return "CSB6 IDE Controller";
        case PciDevice1166::DEVICE_021B: return "HT1100 HD Audio";
        case PciDevice1166::DEVICE_0220: return "OSB4/CSB5 OHCI USB Controller";
        case PciDevice1166::DEVICE_0221: return "CSB6 OHCI USB Controller";
        case PciDevice1166::DEVICE_0223: return "BCM5785 [HT1000] USB";
        case PciDevice1166::DEVICE_0225: return "CSB5 LPC bridge";
        case PciDevice1166::DEVICE_0227: return "GCLE-2 Host Bridge";
        case PciDevice1166::DEVICE_0230: return "CSB5 LPC bridge";
        case PciDevice1166::DEVICE_0234: return "BCM5785 [HT1000] LPC";
        case PciDevice1166::DEVICE_0235: return "BCM5785 [HT1000] XIOAPIC0-2";
        case PciDevice1166::DEVICE_0238: return "BCM5785 [HT1000] WDTimer";
        case PciDevice1166::DEVICE_0240: return "K2 SATA";
        case PciDevice1166::DEVICE_0241: return "RAIDCore RC4000";
        case PciDevice1166::DEVICE_0242: return "RAIDCore BC4000";
        case PciDevice1166::DEVICE_024A: return "BCM5785 [HT1000] SATA (Native SATA Mode)";
        case PciDevice1166::DEVICE_024B: return "BCM5785 [HT1000] SATA (PATA/IDE Mode)";
        case PciDevice1166::DEVICE_0406: return "HT1100 PCI-X Bridge";
        case PciDevice1166::DEVICE_0408: return "HT1100 Legacy Device";
        case PciDevice1166::DEVICE_040A: return "HT1100 ISA-LPC Bridge";
        case PciDevice1166::DEVICE_0410: return "HT1100 SATA Controller (Native SATA Mode)";
        case PciDevice1166::DEVICE_0411: return "HT1100 SATA Controller (PATA / IDE Mode)";
        case PciDevice1166::DEVICE_0412: return "HT1100 USB OHCI Controller";
        case PciDevice1166::DEVICE_0414: return "HT1100 USB EHCI Controller";
        case PciDevice1166::DEVICE_0416: return "HT1100 USB EHCI Controller (with Debug Port)";
        case PciDevice1166::DEVICE_0420: return "HT1100 PCI-Express Bridge";
        case PciDevice1166::DEVICE_0421: return "HT1100 SAS/SATA Controller";
        case PciDevice1166::DEVICE_0422: return "HT1100 PCI-Express Bridge";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1166 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1166::DEVICE_0000: return "Unknown device";
        case PciDevice1166::DEVICE_0005: return "Unknown device";
        case PciDevice1166::DEVICE_0006: return "Unknown device";
        case PciDevice1166::DEVICE_0007: return "Unknown device";
        case PciDevice1166::DEVICE_0008: return "Unknown device";
        case PciDevice1166::DEVICE_0009: return "Unknown device";
        case PciDevice1166::DEVICE_0010: return "Unknown device";
        case PciDevice1166::DEVICE_0011: return "Unknown device";
        case PciDevice1166::DEVICE_0012: return "Unknown device";
        case PciDevice1166::DEVICE_0013: return "Unknown device";
        case PciDevice1166::DEVICE_0014: return "Unknown device";
        case PciDevice1166::DEVICE_0015: return "Unknown device";
        case PciDevice1166::DEVICE_0016: return "Unknown device";
        case PciDevice1166::DEVICE_0017: return "Unknown device";
        case PciDevice1166::DEVICE_0031: return "Unknown device";
        case PciDevice1166::DEVICE_0036: return "Unknown device";
        case PciDevice1166::DEVICE_0101: return "Unknown device";
        case PciDevice1166::DEVICE_0103: return "Unknown device";
        case PciDevice1166::DEVICE_0104: return "Unknown device";
        case PciDevice1166::DEVICE_0110: return "Unknown device";
        case PciDevice1166::DEVICE_0130: return "Unknown device";
        case PciDevice1166::DEVICE_0132: return enumToHumanString((PciSubDevice11660132)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0140: return "Unknown device";
        case PciDevice1166::DEVICE_0141: return "Unknown device";
        case PciDevice1166::DEVICE_0142: return "Unknown device";
        case PciDevice1166::DEVICE_0144: return "Unknown device";
        case PciDevice1166::DEVICE_0200: return "Unknown device";
        case PciDevice1166::DEVICE_0201: return enumToHumanString((PciSubDevice11660201)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0203: return enumToHumanString((PciSubDevice11660203)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0205: return "Unknown device";
        case PciDevice1166::DEVICE_0211: return "Unknown device";
        case PciDevice1166::DEVICE_0212: return enumToHumanString((PciSubDevice11660212)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0213: return enumToHumanString((PciSubDevice11660213)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0214: return enumToHumanString((PciSubDevice11660214)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0217: return enumToHumanString((PciSubDevice11660217)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_021B: return "Unknown device";
        case PciDevice1166::DEVICE_0220: return enumToHumanString((PciSubDevice11660220)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0221: return enumToHumanString((PciSubDevice11660221)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0223: return enumToHumanString((PciSubDevice11660223)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0225: return "Unknown device";
        case PciDevice1166::DEVICE_0227: return enumToHumanString((PciSubDevice11660227)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0230: return enumToHumanString((PciSubDevice11660230)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0234: return enumToHumanString((PciSubDevice11660234)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0235: return "Unknown device";
        case PciDevice1166::DEVICE_0238: return "Unknown device";
        case PciDevice1166::DEVICE_0240: return "Unknown device";
        case PciDevice1166::DEVICE_0241: return "Unknown device";
        case PciDevice1166::DEVICE_0242: return "Unknown device";
        case PciDevice1166::DEVICE_024A: return enumToHumanString((PciSubDevice1166024A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_024B: return enumToHumanString((PciSubDevice1166024B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0406: return "Unknown device";
        case PciDevice1166::DEVICE_0408: return "Unknown device";
        case PciDevice1166::DEVICE_040A: return enumToHumanString((PciSubDevice1166040A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1166::DEVICE_0410: return "Unknown device";
        case PciDevice1166::DEVICE_0411: return "Unknown device";
        case PciDevice1166::DEVICE_0412: return "Unknown device";
        case PciDevice1166::DEVICE_0414: return "Unknown device";
        case PciDevice1166::DEVICE_0416: return "Unknown device";
        case PciDevice1166::DEVICE_0420: return "Unknown device";
        case PciDevice1166::DEVICE_0421: return "Unknown device";
        case PciDevice1166::DEVICE_0422: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCIDEVICE1166_H
