// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA808_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA808_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA808: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_144DA801 = 0x144DA801,
    SUBDEVICE_1D49403B = 0x1D49403B
};



inline const char8* enumToString(PciSubDevice144DA808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA808::NONE:               return "NONE";
        case PciSubDevice144DA808::SUBDEVICE_144DA801: return "SUBDEVICE_144DA801";
        case PciSubDevice144DA808::SUBDEVICE_1D49403B: return "SUBDEVICE_1D49403B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA808::SUBDEVICE_144DA801: return "SSD 970 EVO Plus 1TB";
        case PciSubDevice144DA808::SUBDEVICE_1D49403B: return "Thinksystem U.2 PM983 NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA808_H
