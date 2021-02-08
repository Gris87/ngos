// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA821_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA821_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA821: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281FB7 = 0x10281FB7,
    SUBDEVICE_10281FB8 = 0x10281FB8,
    SUBDEVICE_10281FB9 = 0x10281FB9,
    SUBDEVICE_10281FC1 = 0x10281FC1,
    SUBDEVICE_10281FC2 = 0x10281FC2,
    SUBDEVICE_10281FC4 = 0x10281FC4
};



inline const char8* enumToString(PciSubDevice144DA821 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA821::NONE:               return "NONE";
        case PciSubDevice144DA821::SUBDEVICE_10281FB7: return "SUBDEVICE_10281FB7";
        case PciSubDevice144DA821::SUBDEVICE_10281FB8: return "SUBDEVICE_10281FB8";
        case PciSubDevice144DA821::SUBDEVICE_10281FB9: return "SUBDEVICE_10281FB9";
        case PciSubDevice144DA821::SUBDEVICE_10281FC1: return "SUBDEVICE_10281FC1";
        case PciSubDevice144DA821::SUBDEVICE_10281FC2: return "SUBDEVICE_10281FC2";
        case PciSubDevice144DA821::SUBDEVICE_10281FC4: return "SUBDEVICE_10281FC4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA821 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA821 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA821::SUBDEVICE_10281FB7: return "Express Flash NVMe PM1725 3.2TB SFF";
        case PciSubDevice144DA821::SUBDEVICE_10281FB8: return "Express Flash NVMe PM1725 3.2TB AIC";
        case PciSubDevice144DA821::SUBDEVICE_10281FB9: return "Express Flash NVMe PM1725 6.4TB AIC";
        case PciSubDevice144DA821::SUBDEVICE_10281FC1: return "Express Flash NVMe PM1725 800GB SFF";
        case PciSubDevice144DA821::SUBDEVICE_10281FC2: return "Express Flash NVMe PM1725 1.6TB SFF";
        case PciSubDevice144DA821::SUBDEVICE_10281FC4: return "Express Flash NVMe PM1725 1.6TB AIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA821_H
