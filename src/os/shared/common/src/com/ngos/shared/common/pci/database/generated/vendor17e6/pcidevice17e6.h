// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17E6_PCIDEVICE17E6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17E6_PCIDEVICE17E6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17E6: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0021 = 0x0021,
    DEVICE_0025 = 0x0025,
    DEVICE_0027 = 0x0027,
    DEVICE_3700 = 0x3700,
    DEVICE_3710 = 0x3710
};



inline const char8* enumToString(PciDevice17E6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17E6::NONE:        return "NONE";
        case PciDevice17E6::DEVICE_0010: return "DEVICE_0010";
        case PciDevice17E6::DEVICE_0011: return "DEVICE_0011";
        case PciDevice17E6::DEVICE_0021: return "DEVICE_0021";
        case PciDevice17E6::DEVICE_0025: return "DEVICE_0025";
        case PciDevice17E6::DEVICE_0027: return "DEVICE_0027";
        case PciDevice17E6::DEVICE_3700: return "DEVICE_3700";
        case PciDevice17E6::DEVICE_3710: return "DEVICE_3710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17E6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice17E6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17E6::DEVICE_0010: return "EN2010 [c.Link] MoCA Network Controller (Coax, PCI interface)";
        case PciDevice17E6::DEVICE_0011: return "EN2010 [c.Link] MoCA Network Controller (Coax, MPEG interface)";
        case PciDevice17E6::DEVICE_0021: return "EN2210 [c.Link] MoCA Network Controller (Coax)";
        case PciDevice17E6::DEVICE_0025: return "EN2510 [c.Link] MoCA Network Controller (Coax, PCIe interface)";
        case PciDevice17E6::DEVICE_0027: return "EN2710 [c.Link] MoCA 2.0 Network Controller (Coax, PCIe interface)";
        case PciDevice17E6::DEVICE_3700: return "MoCA 2.0 Network Controller (Coax, PCIe interface)";
        case PciDevice17E6::DEVICE_3710: return "MoCA 2.5 Network Controller (Coax, PCIe interface)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17E6_PCIDEVICE17E6_H
