// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0527_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0527_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B0527: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0840 = 0x102B0840,
    SUBDEVICE_102B0850 = 0x102B0850,
    SUBDEVICE_102B0870 = 0x102B0870,
    SUBDEVICE_102B0880 = 0x102B0880
};



inline const char8* enumToString(PciSubDevice102B0527 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0527::NONE:               return "NONE";
        case PciSubDevice102B0527::SUBDEVICE_102B0840: return "SUBDEVICE_102B0840";
        case PciSubDevice102B0527::SUBDEVICE_102B0850: return "SUBDEVICE_102B0850";
        case PciSubDevice102B0527::SUBDEVICE_102B0870: return "SUBDEVICE_102B0870";
        case PciSubDevice102B0527::SUBDEVICE_102B0880: return "SUBDEVICE_102B0880";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B0527 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B0527 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0527::SUBDEVICE_102B0840: return "Parhelia 128Mb";
        case PciSubDevice102B0527::SUBDEVICE_102B0850: return "Parhelia 256MB";
        case PciSubDevice102B0527::SUBDEVICE_102B0870: return "MED2mp-DVI";
        case PciSubDevice102B0527::SUBDEVICE_102B0880: return "P-256 Edge Overlap Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0527_H
