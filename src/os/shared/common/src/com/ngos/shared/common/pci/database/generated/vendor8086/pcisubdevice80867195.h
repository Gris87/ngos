// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867195_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867195_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867195: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103380CC = 0x103380CC,
    SUBDEVICE_10CF1099 = 0x10CF1099,
    SUBDEVICE_11D40040 = 0x11D40040,
    SUBDEVICE_11D40048 = 0x11D40048
};



inline const char8* enumToString(PciSubDevice80867195 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867195::NONE:               return "NONE";
        case PciSubDevice80867195::SUBDEVICE_103380CC: return "SUBDEVICE_103380CC";
        case PciSubDevice80867195::SUBDEVICE_10CF1099: return "SUBDEVICE_10CF1099";
        case PciSubDevice80867195::SUBDEVICE_11D40040: return "SUBDEVICE_11D40040";
        case PciSubDevice80867195::SUBDEVICE_11D40048: return "SUBDEVICE_11D40048";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867195 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867195 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867195::SUBDEVICE_103380CC: return "Versa Note VXi";
        case PciSubDevice80867195::SUBDEVICE_10CF1099: return "QSound_SigmaTel Stac97 PCI Audio";
        case PciSubDevice80867195::SUBDEVICE_11D40040: return "SoundMAX Integrated Digital Audio";
        case PciSubDevice80867195::SUBDEVICE_11D40048: return "SoundMAX Integrated Digital Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867195_H
