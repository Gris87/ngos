// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D94_PCIDEVICE1D94_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D94_PCIDEVICE1D94_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D94: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1450 = 0x1450,
    DEVICE_1451 = 0x1451,
    DEVICE_1452 = 0x1452,
    DEVICE_1453 = 0x1453,
    DEVICE_1454 = 0x1454,
    DEVICE_1455 = 0x1455,
    DEVICE_1456 = 0x1456,
    DEVICE_1458 = 0x1458,
    DEVICE_1459 = 0x1459,
    DEVICE_145A = 0x145A,
    DEVICE_145B = 0x145B,
    DEVICE_145C = 0x145C,
    DEVICE_145D = 0x145D,
    DEVICE_145E = 0x145E,
    DEVICE_145F = 0x145F,
    DEVICE_1460 = 0x1460,
    DEVICE_1461 = 0x1461,
    DEVICE_1462 = 0x1462,
    DEVICE_1463 = 0x1463,
    DEVICE_1464 = 0x1464,
    DEVICE_1465 = 0x1465,
    DEVICE_1466 = 0x1466,
    DEVICE_1467 = 0x1467,
    DEVICE_1468 = 0x1468,
    DEVICE_7901 = 0x7901,
    DEVICE_7904 = 0x7904,
    DEVICE_7906 = 0x7906,
    DEVICE_790B = 0x790B,
    DEVICE_790E = 0x790E
};



inline const char8* enumToString(PciDevice1D94 device1D94) // TEST: NO
{
    // COMMON_LT((" | device1D94 = %u", device1D94)); // Commented to avoid bad looking logs



    switch (device1D94)
    {
        case PciDevice1D94::NONE:        return "NONE";
        case PciDevice1D94::DEVICE_1450: return "DEVICE_1450";
        case PciDevice1D94::DEVICE_1451: return "DEVICE_1451";
        case PciDevice1D94::DEVICE_1452: return "DEVICE_1452";
        case PciDevice1D94::DEVICE_1453: return "DEVICE_1453";
        case PciDevice1D94::DEVICE_1454: return "DEVICE_1454";
        case PciDevice1D94::DEVICE_1455: return "DEVICE_1455";
        case PciDevice1D94::DEVICE_1456: return "DEVICE_1456";
        case PciDevice1D94::DEVICE_1458: return "DEVICE_1458";
        case PciDevice1D94::DEVICE_1459: return "DEVICE_1459";
        case PciDevice1D94::DEVICE_145A: return "DEVICE_145A";
        case PciDevice1D94::DEVICE_145B: return "DEVICE_145B";
        case PciDevice1D94::DEVICE_145C: return "DEVICE_145C";
        case PciDevice1D94::DEVICE_145D: return "DEVICE_145D";
        case PciDevice1D94::DEVICE_145E: return "DEVICE_145E";
        case PciDevice1D94::DEVICE_145F: return "DEVICE_145F";
        case PciDevice1D94::DEVICE_1460: return "DEVICE_1460";
        case PciDevice1D94::DEVICE_1461: return "DEVICE_1461";
        case PciDevice1D94::DEVICE_1462: return "DEVICE_1462";
        case PciDevice1D94::DEVICE_1463: return "DEVICE_1463";
        case PciDevice1D94::DEVICE_1464: return "DEVICE_1464";
        case PciDevice1D94::DEVICE_1465: return "DEVICE_1465";
        case PciDevice1D94::DEVICE_1466: return "DEVICE_1466";
        case PciDevice1D94::DEVICE_1467: return "DEVICE_1467";
        case PciDevice1D94::DEVICE_1468: return "DEVICE_1468";
        case PciDevice1D94::DEVICE_7901: return "DEVICE_7901";
        case PciDevice1D94::DEVICE_7904: return "DEVICE_7904";
        case PciDevice1D94::DEVICE_7906: return "DEVICE_7906";
        case PciDevice1D94::DEVICE_790B: return "DEVICE_790B";
        case PciDevice1D94::DEVICE_790E: return "DEVICE_790E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D94 device1D94) // TEST: NO
{
    // COMMON_LT((" | device1D94 = %u", device1D94)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D94, enumToString(device1D94));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D94 device1D94) // TEST: NO
{
    // COMMON_LT((" | device1D94 = %u", device1D94)); // Commented to avoid bad looking logs



    switch (device1D94)
    {
        case PciDevice1D94::DEVICE_1450: return "Root Complex";
        case PciDevice1D94::DEVICE_1451: return "I/O Memory Management Unit";
        case PciDevice1D94::DEVICE_1452: return "PCIe Dummy Host Bridge";
        case PciDevice1D94::DEVICE_1453: return "PCIE GPP Bridge";
        case PciDevice1D94::DEVICE_1454: return "Internal PCIe GPP Bridge 0 to Bus B";
        case PciDevice1D94::DEVICE_1455: return "PCIe Dummy Function";
        case PciDevice1D94::DEVICE_1456: return "PSPCCP Command DMA Processor";
        case PciDevice1D94::DEVICE_1458: return "10 Gb Ethernet Controller Port 0/Port1";
        case PciDevice1D94::DEVICE_1459: return "10 Gb Ethernet Controller Port 2/Port3";
        case PciDevice1D94::DEVICE_145A: return "PCIe Dummy Function";
        case PciDevice1D94::DEVICE_145B: return "PCIE Non-Transparent Bridge";
        case PciDevice1D94::DEVICE_145C: return "USB3 XHCI";
        case PciDevice1D94::DEVICE_145D: return "Switch upstream in PCIe";
        case PciDevice1D94::DEVICE_145E: return "Switch downstream in PCIe";
        case PciDevice1D94::DEVICE_145F: return "USB 3.0 Host controller";
        case PciDevice1D94::DEVICE_1460: return "Data Fabric: Device 18h; Function 0";
        case PciDevice1D94::DEVICE_1461: return "Data Fabric: Device 18h; Function 1";
        case PciDevice1D94::DEVICE_1462: return "Data Fabric: Device 18h; Function 2";
        case PciDevice1D94::DEVICE_1463: return "Data Fabric: Device 18h; Function 3";
        case PciDevice1D94::DEVICE_1464: return "Data Fabric: Device 18h; Function 4";
        case PciDevice1D94::DEVICE_1465: return "Data Fabric: Device 18h; Function 5";
        case PciDevice1D94::DEVICE_1466: return "Data Fabric: Device 18h; Function 6";
        case PciDevice1D94::DEVICE_1467: return "Data Fabric: Device 18h; Function 7";
        case PciDevice1D94::DEVICE_1468: return "NTBCCP";
        case PciDevice1D94::DEVICE_7901: return "FCH SATA Controller [AHCI mode]";
        case PciDevice1D94::DEVICE_7904: return "FCH SATA Controller [AHCI mode]";
        case PciDevice1D94::DEVICE_7906: return "FCH SD Flash Controller";
        case PciDevice1D94::DEVICE_790B: return "FCH SMBus Controller";
        case PciDevice1D94::DEVICE_790E: return "FCH LPC Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D94_PCIDEVICE1D94_H
