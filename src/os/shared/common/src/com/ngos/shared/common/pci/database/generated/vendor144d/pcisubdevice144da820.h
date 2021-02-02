// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA820_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA820_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA820: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F95 = 0x10281F95,
    SUBDEVICE_10281F96 = 0x10281F96,
    SUBDEVICE_10281F97 = 0x10281F97,
    SUBDEVICE_10281FA4 = 0x10281FA4,
    SUBDEVICE_10281FA6 = 0x10281FA6,
    SUBDEVICE_10281FBA = 0x10281FBA,
    SUBDEVICE_10281FBB = 0x10281FBB,
    SUBDEVICE_10281FBC = 0x10281FBC
};



inline const char8* enumToString(PciSubDevice144DA820 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA820::NONE:               return "NONE";
        case PciSubDevice144DA820::SUBDEVICE_10281F95: return "SUBDEVICE_10281F95";
        case PciSubDevice144DA820::SUBDEVICE_10281F96: return "SUBDEVICE_10281F96";
        case PciSubDevice144DA820::SUBDEVICE_10281F97: return "SUBDEVICE_10281F97";
        case PciSubDevice144DA820::SUBDEVICE_10281FA4: return "SUBDEVICE_10281FA4";
        case PciSubDevice144DA820::SUBDEVICE_10281FA6: return "SUBDEVICE_10281FA6";
        case PciSubDevice144DA820::SUBDEVICE_10281FBA: return "SUBDEVICE_10281FBA";
        case PciSubDevice144DA820::SUBDEVICE_10281FBB: return "SUBDEVICE_10281FBB";
        case PciSubDevice144DA820::SUBDEVICE_10281FBC: return "SUBDEVICE_10281FBC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA820 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA820 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA820::SUBDEVICE_10281F95: return "Express Flash NVMe XS1715 SSD 400GB";
        case PciSubDevice144DA820::SUBDEVICE_10281F96: return "Express Flash NVMe XS1715 SSD 800GB";
        case PciSubDevice144DA820::SUBDEVICE_10281F97: return "Express Flash NVMe XS1715 SSD 1600GB";
        case PciSubDevice144DA820::SUBDEVICE_10281FA4: return "Express Flash NVMe SM1715 3.2TB SFF";
        case PciSubDevice144DA820::SUBDEVICE_10281FA6: return "Express Flash NVMe SM1715 3.2TB AIC";
        case PciSubDevice144DA820::SUBDEVICE_10281FBA: return "Express Flash NVMe SM1715 800GB SFF";
        case PciSubDevice144DA820::SUBDEVICE_10281FBB: return "Express Flash NVMe SM1715 1.6TB SFF";
        case PciSubDevice144DA820::SUBDEVICE_10281FBC: return "Express Flash NVMe SM1715 1.6TB AIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA820_H
