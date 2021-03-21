// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD0_PCIDEVICE1BD0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD0_PCIDEVICE1BD0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BD0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1008 = 0x1008,
    DEVICE_100A = 0x100A,
    DEVICE_1101 = 0x1101,
    DEVICE_1102 = 0x1102,
    DEVICE_1103 = 0x1103,
    DEVICE_1200 = 0x1200,
    DEVICE_1201 = 0x1201,
    DEVICE_1202 = 0x1202,
    DEVICE_1203 = 0x1203
};



inline const char8* enumToString(PciDevice1BD0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BD0::NONE:        return "NONE";
        case PciDevice1BD0::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1BD0::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1BD0::DEVICE_1004: return "DEVICE_1004";
        case PciDevice1BD0::DEVICE_1005: return "DEVICE_1005";
        case PciDevice1BD0::DEVICE_1006: return "DEVICE_1006";
        case PciDevice1BD0::DEVICE_1007: return "DEVICE_1007";
        case PciDevice1BD0::DEVICE_1008: return "DEVICE_1008";
        case PciDevice1BD0::DEVICE_100A: return "DEVICE_100A";
        case PciDevice1BD0::DEVICE_1101: return "DEVICE_1101";
        case PciDevice1BD0::DEVICE_1102: return "DEVICE_1102";
        case PciDevice1BD0::DEVICE_1103: return "DEVICE_1103";
        case PciDevice1BD0::DEVICE_1200: return "DEVICE_1200";
        case PciDevice1BD0::DEVICE_1201: return "DEVICE_1201";
        case PciDevice1BD0::DEVICE_1202: return "DEVICE_1202";
        case PciDevice1BD0::DEVICE_1203: return "DEVICE_1203";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BD0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BD0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BD0::DEVICE_1001: return "Mx5 PMC/XMC Databus Interface Card";
        case PciDevice1BD0::DEVICE_1002: return "PM1553-5 (PC/104+ MIL-STD-1553 Interface Card)";
        case PciDevice1BD0::DEVICE_1004: return "AB3000 Series Rugged Computer";
        case PciDevice1BD0::DEVICE_1005: return "PE1000 (Multi-Protocol PCIe/104 Interface Card)";
        case PciDevice1BD0::DEVICE_1006: return "webCS Wireless Aircraft Communications Server";
        case PciDevice1BD0::DEVICE_1007: return "AB3000 Series Rugged Computer (Series N)";
        case PciDevice1BD0::DEVICE_1008: return "ME1000 mPCIe Avionics Interface Card";
        case PciDevice1BD0::DEVICE_100A: return "NG1 Series Avionics Converter";
        case PciDevice1BD0::DEVICE_1101: return "OmniBus II PCIe Multi-Protocol Interface Card";
        case PciDevice1BD0::DEVICE_1102: return "OmniBusBox II Multi-Protocol Interface Core";
        case PciDevice1BD0::DEVICE_1103: return "OmniBus II cPCIe/PXIe Multi-Protocol Interface Card";
        case PciDevice1BD0::DEVICE_1200: return "NG3 Series Mil-Std-1553 Interface";
        case PciDevice1BD0::DEVICE_1201: return "NG3 Series ARINC 429 Interface";
        case PciDevice1BD0::DEVICE_1202: return "NG3 Series Avionics Discrete & Serial Interface";
        case PciDevice1BD0::DEVICE_1203: return "NG3 Series Avionics Discrete Interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD0_PCIDEVICE1BD0_H
