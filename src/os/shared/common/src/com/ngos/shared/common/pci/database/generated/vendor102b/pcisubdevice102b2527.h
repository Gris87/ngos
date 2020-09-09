// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2527_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2527_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B2527: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0F42 = 0x102B0F42,
    SUBDEVICE_102B0F83 = 0x102B0F83,
    SUBDEVICE_102B0F84 = 0x102B0F84,
    SUBDEVICE_102B1E41 = 0x102B1E41,
    SUBDEVICE_102B22C0 = 0x102B22C0,
    SUBDEVICE_102B2300 = 0x102B2300
};



inline const char8* enumToString(PciSubDevice102B2527 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2527::NONE:               return "NONE";
        case PciSubDevice102B2527::SUBDEVICE_102B0F42: return "SUBDEVICE_102B0F42";
        case PciSubDevice102B2527::SUBDEVICE_102B0F83: return "SUBDEVICE_102B0F83";
        case PciSubDevice102B2527::SUBDEVICE_102B0F84: return "SUBDEVICE_102B0F84";
        case PciSubDevice102B2527::SUBDEVICE_102B1E41: return "SUBDEVICE_102B1E41";
        case PciSubDevice102B2527::SUBDEVICE_102B22C0: return "SUBDEVICE_102B22C0";
        case PciSubDevice102B2527::SUBDEVICE_102B2300: return "SUBDEVICE_102B2300";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B2527 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B2527 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2527::SUBDEVICE_102B0F42: return "Matrox G550 Low Profile PCI";
        case PciSubDevice102B2527::SUBDEVICE_102B0F83: return "Millennium G550";
        case PciSubDevice102B2527::SUBDEVICE_102B0F84: return "Millennium G550 Dual Head DDR 32Mb";
        case PciSubDevice102B2527::SUBDEVICE_102B1E41: return "Millennium G550";
        case PciSubDevice102B2527::SUBDEVICE_102B22C0: return "G550 PCIe";
        case PciSubDevice102B2527::SUBDEVICE_102B2300: return "Millennium G550 LP PCIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2527_H
