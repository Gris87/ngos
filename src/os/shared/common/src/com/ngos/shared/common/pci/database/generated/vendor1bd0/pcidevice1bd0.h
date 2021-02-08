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
    DEVICE_1101 = 0x1101,
    DEVICE_1102 = 0x1102,
    DEVICE_1103 = 0x1103
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
        case PciDevice1BD0::DEVICE_1101: return "DEVICE_1101";
        case PciDevice1BD0::DEVICE_1102: return "DEVICE_1102";
        case PciDevice1BD0::DEVICE_1103: return "DEVICE_1103";

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
        case PciDevice1BD0::DEVICE_1101: return "OmniBus II PCIe Multi-Protocol Interface Card";
        case PciDevice1BD0::DEVICE_1102: return "OmniBusBox II Multi-Protocol Interface Core";
        case PciDevice1BD0::DEVICE_1103: return "OmniBus II cPCIe/PXIe Multi-Protocol Interface Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD0_PCIDEVICE1BD0_H
