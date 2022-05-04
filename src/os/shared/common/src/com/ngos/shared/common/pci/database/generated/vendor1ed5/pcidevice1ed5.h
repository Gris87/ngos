// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ED5_PCIDEVICE1ED5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ED5_PCIDEVICE1ED5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1ED5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0105 = 0x0105,
    DEVICE_0106 = 0x0106,
    DEVICE_0111 = 0x0111,
    DEVICE_0121 = 0x0121,
    DEVICE_0122 = 0x0122,
    DEVICE_0123 = 0x0123
};



inline const char8* enumToString(PciDevice1ED5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1ED5::NONE:        return "NONE";
        case PciDevice1ED5::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1ED5::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1ED5::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1ED5::DEVICE_0105: return "DEVICE_0105";
        case PciDevice1ED5::DEVICE_0106: return "DEVICE_0106";
        case PciDevice1ED5::DEVICE_0111: return "DEVICE_0111";
        case PciDevice1ED5::DEVICE_0121: return "DEVICE_0121";
        case PciDevice1ED5::DEVICE_0122: return "DEVICE_0122";
        case PciDevice1ED5::DEVICE_0123: return "DEVICE_0123";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1ED5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1ED5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1ED5::DEVICE_0100: return "MTT S10";
        case PciDevice1ED5::DEVICE_0101: return "MTT S10";
        case PciDevice1ED5::DEVICE_0102: return "MTT S30";
        case PciDevice1ED5::DEVICE_0105: return "MTT S50";
        case PciDevice1ED5::DEVICE_0106: return "MTT S60";
        case PciDevice1ED5::DEVICE_0111: return "MTT S100";
        case PciDevice1ED5::DEVICE_0121: return "MTT S1000M";
        case PciDevice1ED5::DEVICE_0122: return "MTT S1000";
        case PciDevice1ED5::DEVICE_0123: return "MTT S2000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ED5_PCIDEVICE1ED5_H
