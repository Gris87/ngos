// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860A55_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860A55_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860A55: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281FE5 = 0x10281FE5,
    SUBDEVICE_10281FE6 = 0x10281FE6,
    SUBDEVICE_10281FE7 = 0x10281FE7,
    SUBDEVICE_10281FE8 = 0x10281FE8,
    SUBDEVICE_10281FE9 = 0x10281FE9
};



inline const char8* enumToString(PciSubDevice80860A55 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860A55::NONE:               return "NONE";
        case PciSubDevice80860A55::SUBDEVICE_10281FE5: return "SUBDEVICE_10281FE5";
        case PciSubDevice80860A55::SUBDEVICE_10281FE6: return "SUBDEVICE_10281FE6";
        case PciSubDevice80860A55::SUBDEVICE_10281FE7: return "SUBDEVICE_10281FE7";
        case PciSubDevice80860A55::SUBDEVICE_10281FE8: return "SUBDEVICE_10281FE8";
        case PciSubDevice80860A55::SUBDEVICE_10281FE9: return "SUBDEVICE_10281FE9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860A55 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860A55 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860A55::SUBDEVICE_10281FE5: return "Express Flash NVMe 1.6TB 2.5\" U.2 (P4600)";
        case PciSubDevice80860A55::SUBDEVICE_10281FE6: return "Express Flash NVMe 2TB 2.5\" U.2 (P4600)";
        case PciSubDevice80860A55::SUBDEVICE_10281FE7: return "Express Flash NVMe 3.2TB 2.5\" U.2 (P4600)";
        case PciSubDevice80860A55::SUBDEVICE_10281FE8: return "Express Flash NVMe 2.0TB HHHL AIC (P4600)";
        case PciSubDevice80860A55::SUBDEVICE_10281FE9: return "Express Flash NVMe 4.0TB HHHL AIC (P4600)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860A55_H
