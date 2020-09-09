// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0540_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0540_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B0540: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B2080 = 0x102B2080,
    SUBDEVICE_102B20C0 = 0x102B20C0,
    SUBDEVICE_102B20C1 = 0x102B20C1,
    SUBDEVICE_102B2100 = 0x102B2100,
    SUBDEVICE_102B2140 = 0x102B2140,
    SUBDEVICE_102B2180 = 0x102B2180,
    SUBDEVICE_102B21C0 = 0x102B21C0,
    SUBDEVICE_102B2200 = 0x102B2200,
    SUBDEVICE_102B2240 = 0x102B2240,
    SUBDEVICE_102B2241 = 0x102B2241,
    SUBDEVICE_102B2280 = 0x102B2280,
    SUBDEVICE_102B22C0 = 0x102B22C0
};



inline const char8* enumToString(PciSubDevice102B0540 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0540::NONE:               return "NONE";
        case PciSubDevice102B0540::SUBDEVICE_102B2080: return "SUBDEVICE_102B2080";
        case PciSubDevice102B0540::SUBDEVICE_102B20C0: return "SUBDEVICE_102B20C0";
        case PciSubDevice102B0540::SUBDEVICE_102B20C1: return "SUBDEVICE_102B20C1";
        case PciSubDevice102B0540::SUBDEVICE_102B2100: return "SUBDEVICE_102B2100";
        case PciSubDevice102B0540::SUBDEVICE_102B2140: return "SUBDEVICE_102B2140";
        case PciSubDevice102B0540::SUBDEVICE_102B2180: return "SUBDEVICE_102B2180";
        case PciSubDevice102B0540::SUBDEVICE_102B21C0: return "SUBDEVICE_102B21C0";
        case PciSubDevice102B0540::SUBDEVICE_102B2200: return "SUBDEVICE_102B2200";
        case PciSubDevice102B0540::SUBDEVICE_102B2240: return "SUBDEVICE_102B2240";
        case PciSubDevice102B0540::SUBDEVICE_102B2241: return "SUBDEVICE_102B2241";
        case PciSubDevice102B0540::SUBDEVICE_102B2280: return "SUBDEVICE_102B2280";
        case PciSubDevice102B0540::SUBDEVICE_102B22C0: return "SUBDEVICE_102B22C0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B0540 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B0540 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0540::SUBDEVICE_102B2080: return "M9140 LP PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B20C0: return "Xenia";
        case PciSubDevice102B0540::SUBDEVICE_102B20C1: return "Xenia Pro";
        case PciSubDevice102B0540::SUBDEVICE_102B2100: return "M9120 PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B2140: return "M9125 PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B2180: return "M9120 Plus LP PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B21C0: return "M9120 Plus LP PCIe x1";
        case PciSubDevice102B0540::SUBDEVICE_102B2200: return "VDA1164 Output Board";
        case PciSubDevice102B0540::SUBDEVICE_102B2240: return "M9148 LP PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B2241: return "M9138 LP PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B2280: return "M9188 ATX PCIe x16";
        case PciSubDevice102B0540::SUBDEVICE_102B22C0: return "M9128 LP PCIe x16";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0540_H
