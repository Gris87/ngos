// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE002C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE002C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE002C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430200 = 0x10430200,
    SUBDEVICE_10430201 = 0x10430201,
    SUBDEVICE_10480C20 = 0x10480C20,
    SUBDEVICE_10480C21 = 0x10480C21,
    SUBDEVICE_10480C25 = 0x10480C25,
    SUBDEVICE_10926820 = 0x10926820,
    SUBDEVICE_11021031 = 0x11021031,
    SUBDEVICE_11021034 = 0x11021034,
    SUBDEVICE_14AF5008 = 0x14AF5008
};



inline const char8* enumToString(PciSubDevice10DE002C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE002C::NONE:               return "NONE";
        case PciSubDevice10DE002C::SUBDEVICE_10430200: return "SUBDEVICE_10430200";
        case PciSubDevice10DE002C::SUBDEVICE_10430201: return "SUBDEVICE_10430201";
        case PciSubDevice10DE002C::SUBDEVICE_10480C20: return "SUBDEVICE_10480C20";
        case PciSubDevice10DE002C::SUBDEVICE_10480C21: return "SUBDEVICE_10480C21";
        case PciSubDevice10DE002C::SUBDEVICE_10480C25: return "SUBDEVICE_10480C25";
        case PciSubDevice10DE002C::SUBDEVICE_10926820: return "SUBDEVICE_10926820";
        case PciSubDevice10DE002C::SUBDEVICE_11021031: return "SUBDEVICE_11021031";
        case PciSubDevice10DE002C::SUBDEVICE_11021034: return "SUBDEVICE_11021034";
        case PciSubDevice10DE002C::SUBDEVICE_14AF5008: return "SUBDEVICE_14AF5008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE002C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE002C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE002C::SUBDEVICE_10430200: return "AGP-V3800 Combat SDRAM";
        case PciSubDevice10DE002C::SUBDEVICE_10430201: return "AGP-V3800 Combat";
        case PciSubDevice10DE002C::SUBDEVICE_10480C20: return "TNT2 Vanta";
        case PciSubDevice10DE002C::SUBDEVICE_10480C21: return "TNT2 Vanta";
        case PciSubDevice10DE002C::SUBDEVICE_10480C25: return "TNT2 Vanta 16MB";
        case PciSubDevice10DE002C::SUBDEVICE_10926820: return "Viper V730";
        case PciSubDevice10DE002C::SUBDEVICE_11021031: return "CT6938 VANTA 8MB";
        case PciSubDevice10DE002C::SUBDEVICE_11021034: return "CT6894 VANTA 16MB";
        case PciSubDevice10DE002C::SUBDEVICE_14AF5008: return "Maxi Gamer Phoenix 2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE002C_H
