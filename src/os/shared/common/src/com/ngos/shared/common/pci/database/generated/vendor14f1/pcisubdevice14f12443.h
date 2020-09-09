// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12443_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12443_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F12443: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D8075 = 0x104D8075,
    SUBDEVICE_104D8083 = 0x104D8083,
    SUBDEVICE_104D8097 = 0x104D8097
};



inline const char8* enumToString(PciSubDevice14F12443 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12443::NONE:               return "NONE";
        case PciSubDevice14F12443::SUBDEVICE_104D8075: return "SUBDEVICE_104D8075";
        case PciSubDevice14F12443::SUBDEVICE_104D8083: return "SUBDEVICE_104D8083";
        case PciSubDevice14F12443::SUBDEVICE_104D8097: return "SUBDEVICE_104D8097";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F12443 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F12443 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12443::SUBDEVICE_104D8075: return "Modem";
        case PciSubDevice14F12443::SUBDEVICE_104D8083: return "Modem";
        case PciSubDevice14F12443::SUBDEVICE_104D8097: return "Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12443_H
