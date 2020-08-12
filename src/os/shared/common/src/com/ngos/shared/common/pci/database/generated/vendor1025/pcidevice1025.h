// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCIDEVICE1025_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCIDEVICE1025_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1025: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1435 = 0x1435,
    DEVICE_1445 = 0x1445,
    DEVICE_1449 = 0x1449,
    DEVICE_1451 = 0x1451,
    DEVICE_1461 = 0x1461,
    DEVICE_1489 = 0x1489,
    DEVICE_1511 = 0x1511,
    DEVICE_1512 = 0x1512,
    DEVICE_1513 = 0x1513,
    DEVICE_1521 = 0x1521,
    DEVICE_1523 = 0x1523,
    DEVICE_1531 = 0x1531,
    DEVICE_1533 = 0x1533,
    DEVICE_1535 = 0x1535,
    DEVICE_1541 = 0x1541,
    DEVICE_1542 = 0x1542,
    DEVICE_1543 = 0x1543,
    DEVICE_1561 = 0x1561,
    DEVICE_1621 = 0x1621,
    DEVICE_1631 = 0x1631,
    DEVICE_1641 = 0x1641,
    DEVICE_1647 = 0x1647,
    DEVICE_1671 = 0x1671,
    DEVICE_1672 = 0x1672,
    DEVICE_3141 = 0x3141,
    DEVICE_3143 = 0x3143,
    DEVICE_3145 = 0x3145,
    DEVICE_3147 = 0x3147,
    DEVICE_3149 = 0x3149,
    DEVICE_3151 = 0x3151,
    DEVICE_3307 = 0x3307,
    DEVICE_3309 = 0x3309,
    DEVICE_3321 = 0x3321,
    DEVICE_5212 = 0x5212,
    DEVICE_5215 = 0x5215,
    DEVICE_5217 = 0x5217,
    DEVICE_5219 = 0x5219,
    DEVICE_5225 = 0x5225,
    DEVICE_5229 = 0x5229,
    DEVICE_5235 = 0x5235,
    DEVICE_5237 = 0x5237,
    DEVICE_5240 = 0x5240,
    DEVICE_5241 = 0x5241,
    DEVICE_5242 = 0x5242,
    DEVICE_5243 = 0x5243,
    DEVICE_5244 = 0x5244,
    DEVICE_5247 = 0x5247,
    DEVICE_5251 = 0x5251,
    DEVICE_5427 = 0x5427,
    DEVICE_5451 = 0x5451,
    DEVICE_5453 = 0x5453,
    DEVICE_7101 = 0x7101,
    DEVICE_9602 = 0x9602
};



inline const char8* enumToString(PciDevice1025 device1025) // TEST: NO
{
    // COMMON_LT((" | device1025 = %u", device1025)); // Commented to avoid bad looking logs



    switch (device1025)
    {
        case PciDevice1025::NONE:        return "NONE";
        case PciDevice1025::DEVICE_1435: return "DEVICE_1435";
        case PciDevice1025::DEVICE_1445: return "DEVICE_1445";
        case PciDevice1025::DEVICE_1449: return "DEVICE_1449";
        case PciDevice1025::DEVICE_1451: return "DEVICE_1451";
        case PciDevice1025::DEVICE_1461: return "DEVICE_1461";
        case PciDevice1025::DEVICE_1489: return "DEVICE_1489";
        case PciDevice1025::DEVICE_1511: return "DEVICE_1511";
        case PciDevice1025::DEVICE_1512: return "DEVICE_1512";
        case PciDevice1025::DEVICE_1513: return "DEVICE_1513";
        case PciDevice1025::DEVICE_1521: return "DEVICE_1521";
        case PciDevice1025::DEVICE_1523: return "DEVICE_1523";
        case PciDevice1025::DEVICE_1531: return "DEVICE_1531";
        case PciDevice1025::DEVICE_1533: return "DEVICE_1533";
        case PciDevice1025::DEVICE_1535: return "DEVICE_1535";
        case PciDevice1025::DEVICE_1541: return "DEVICE_1541";
        case PciDevice1025::DEVICE_1542: return "DEVICE_1542";
        case PciDevice1025::DEVICE_1543: return "DEVICE_1543";
        case PciDevice1025::DEVICE_1561: return "DEVICE_1561";
        case PciDevice1025::DEVICE_1621: return "DEVICE_1621";
        case PciDevice1025::DEVICE_1631: return "DEVICE_1631";
        case PciDevice1025::DEVICE_1641: return "DEVICE_1641";
        case PciDevice1025::DEVICE_1647: return "DEVICE_1647";
        case PciDevice1025::DEVICE_1671: return "DEVICE_1671";
        case PciDevice1025::DEVICE_1672: return "DEVICE_1672";
        case PciDevice1025::DEVICE_3141: return "DEVICE_3141";
        case PciDevice1025::DEVICE_3143: return "DEVICE_3143";
        case PciDevice1025::DEVICE_3145: return "DEVICE_3145";
        case PciDevice1025::DEVICE_3147: return "DEVICE_3147";
        case PciDevice1025::DEVICE_3149: return "DEVICE_3149";
        case PciDevice1025::DEVICE_3151: return "DEVICE_3151";
        case PciDevice1025::DEVICE_3307: return "DEVICE_3307";
        case PciDevice1025::DEVICE_3309: return "DEVICE_3309";
        case PciDevice1025::DEVICE_3321: return "DEVICE_3321";
        case PciDevice1025::DEVICE_5212: return "DEVICE_5212";
        case PciDevice1025::DEVICE_5215: return "DEVICE_5215";
        case PciDevice1025::DEVICE_5217: return "DEVICE_5217";
        case PciDevice1025::DEVICE_5219: return "DEVICE_5219";
        case PciDevice1025::DEVICE_5225: return "DEVICE_5225";
        case PciDevice1025::DEVICE_5229: return "DEVICE_5229";
        case PciDevice1025::DEVICE_5235: return "DEVICE_5235";
        case PciDevice1025::DEVICE_5237: return "DEVICE_5237";
        case PciDevice1025::DEVICE_5240: return "DEVICE_5240";
        case PciDevice1025::DEVICE_5241: return "DEVICE_5241";
        case PciDevice1025::DEVICE_5242: return "DEVICE_5242";
        case PciDevice1025::DEVICE_5243: return "DEVICE_5243";
        case PciDevice1025::DEVICE_5244: return "DEVICE_5244";
        case PciDevice1025::DEVICE_5247: return "DEVICE_5247";
        case PciDevice1025::DEVICE_5251: return "DEVICE_5251";
        case PciDevice1025::DEVICE_5427: return "DEVICE_5427";
        case PciDevice1025::DEVICE_5451: return "DEVICE_5451";
        case PciDevice1025::DEVICE_5453: return "DEVICE_5453";
        case PciDevice1025::DEVICE_7101: return "DEVICE_7101";
        case PciDevice1025::DEVICE_9602: return "DEVICE_9602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1025 device1025) // TEST: NO
{
    // COMMON_LT((" | device1025 = %u", device1025)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1025, enumToString(device1025));

    return res;
}



inline const char8* enumToHumanString(PciDevice1025 device1025) // TEST: NO
{
    // COMMON_LT((" | device1025 = %u", device1025)); // Commented to avoid bad looking logs



    switch (device1025)
    {
        case PciDevice1025::DEVICE_1435: return "M1435";
        case PciDevice1025::DEVICE_1445: return "M1445";
        case PciDevice1025::DEVICE_1449: return "M1449";
        case PciDevice1025::DEVICE_1451: return "M1451";
        case PciDevice1025::DEVICE_1461: return "M1461";
        case PciDevice1025::DEVICE_1489: return "M1489";
        case PciDevice1025::DEVICE_1511: return "M1511";
        case PciDevice1025::DEVICE_1512: return "ALI M1512 Aladdin";
        case PciDevice1025::DEVICE_1513: return "M1513";
        case PciDevice1025::DEVICE_1521: return "ALI M1521 Aladdin III CPU Bridge";
        case PciDevice1025::DEVICE_1523: return "ALI M1523 ISA Bridge";
        case PciDevice1025::DEVICE_1531: return "M1531 Northbridge [Aladdin IV/IV+]";
        case PciDevice1025::DEVICE_1533: return "M1533 PCI-to-ISA Bridge";
        case PciDevice1025::DEVICE_1535: return "M1535 PCI Bridge + Super I/O + FIR";
        case PciDevice1025::DEVICE_1541: return "M1541 Northbridge [Aladdin V]";
        case PciDevice1025::DEVICE_1542: return "M1542 Northbridge [Aladdin V]";
        case PciDevice1025::DEVICE_1543: return "M1543 PCI-to-ISA Bridge + Super I/O + FIR";
        case PciDevice1025::DEVICE_1561: return "M1561 Northbridge [Aladdin 7]";
        case PciDevice1025::DEVICE_1621: return "M1621 Northbridge [Aladdin-Pro II]";
        case PciDevice1025::DEVICE_1631: return "M1631 Northbridge+3D Graphics [Aladdin TNT2]";
        case PciDevice1025::DEVICE_1641: return "M1641 Northbridge [Aladdin-Pro IV]";
        case PciDevice1025::DEVICE_1647: return "M1647 [MaGiK1] PCI North Bridge";
        case PciDevice1025::DEVICE_1671: return "M1671 Northbridge [ALADDiN-P4]";
        case PciDevice1025::DEVICE_1672: return "Northbridge [CyberALADDiN-P4]";
        case PciDevice1025::DEVICE_3141: return "M3141";
        case PciDevice1025::DEVICE_3143: return "M3143";
        case PciDevice1025::DEVICE_3145: return "M3145";
        case PciDevice1025::DEVICE_3147: return "M3147";
        case PciDevice1025::DEVICE_3149: return "M3149";
        case PciDevice1025::DEVICE_3151: return "M3151";
        case PciDevice1025::DEVICE_3307: return "M3307 MPEG-I Video Controller";
        case PciDevice1025::DEVICE_3309: return "M3309 MPEG-II Video w/ Software Audio Decoder";
        case PciDevice1025::DEVICE_3321: return "M3321 MPEG-II Audio/Video Decoder";
        case PciDevice1025::DEVICE_5212: return "M4803";
        case PciDevice1025::DEVICE_5215: return "ALI PCI EIDE Controller";
        case PciDevice1025::DEVICE_5217: return "M5217H";
        case PciDevice1025::DEVICE_5219: return "M5219";
        case PciDevice1025::DEVICE_5225: return "M5225";
        case PciDevice1025::DEVICE_5229: return "M5229";
        case PciDevice1025::DEVICE_5235: return "M5235";
        case PciDevice1025::DEVICE_5237: return "M5237 PCI USB Host Controller";
        case PciDevice1025::DEVICE_5240: return "EIDE Controller";
        case PciDevice1025::DEVICE_5241: return "PCMCIA Bridge";
        case PciDevice1025::DEVICE_5242: return "General Purpose Controller";
        case PciDevice1025::DEVICE_5243: return "PCI to PCI Bridge Controller";
        case PciDevice1025::DEVICE_5244: return "Floppy Disk Controller";
        case PciDevice1025::DEVICE_5247: return "M1541 PCI to PCI Bridge";
        case PciDevice1025::DEVICE_5251: return "M5251 P1394 Controller";
        case PciDevice1025::DEVICE_5427: return "PCI to AGP Bridge";
        case PciDevice1025::DEVICE_5451: return "M5451 PCI AC-Link Controller Audio Device";
        case PciDevice1025::DEVICE_5453: return "M5453 PCI AC-Link Controller Modem Device";
        case PciDevice1025::DEVICE_7101: return "M7101 PCI PMU Power Management Controller";
        case PciDevice1025::DEVICE_9602: return "AMD RS780/RS880 PCI to PCI bridge (int gfx)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCIDEVICE1025_H
