// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C323C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1920 = 0x103C1920,
    SUBDEVICE_103C1921 = 0x103C1921,
    SUBDEVICE_103C1922 = 0x103C1922,
    SUBDEVICE_103C1923 = 0x103C1923,
    SUBDEVICE_103C1924 = 0x103C1924,
    SUBDEVICE_103C1925 = 0x103C1925,
    SUBDEVICE_103C1926 = 0x103C1926,
    SUBDEVICE_103C1928 = 0x103C1928
};



inline const char8* enumToString(PciSubDevice103C323C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C323C::NONE:               return "NONE";
        case PciSubDevice103C323C::SUBDEVICE_103C1920: return "SUBDEVICE_103C1920";
        case PciSubDevice103C323C::SUBDEVICE_103C1921: return "SUBDEVICE_103C1921";
        case PciSubDevice103C323C::SUBDEVICE_103C1922: return "SUBDEVICE_103C1922";
        case PciSubDevice103C323C::SUBDEVICE_103C1923: return "SUBDEVICE_103C1923";
        case PciSubDevice103C323C::SUBDEVICE_103C1924: return "SUBDEVICE_103C1924";
        case PciSubDevice103C323C::SUBDEVICE_103C1925: return "SUBDEVICE_103C1925";
        case PciSubDevice103C323C::SUBDEVICE_103C1926: return "SUBDEVICE_103C1926";
        case PciSubDevice103C323C::SUBDEVICE_103C1928: return "SUBDEVICE_103C1928";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C323C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C323C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C323C::SUBDEVICE_103C1920: return "P430i";
        case PciSubDevice103C323C::SUBDEVICE_103C1921: return "P830i";
        case PciSubDevice103C323C::SUBDEVICE_103C1922: return "P430";
        case PciSubDevice103C323C::SUBDEVICE_103C1923: return "P431";
        case PciSubDevice103C323C::SUBDEVICE_103C1924: return "P830";
        case PciSubDevice103C323C::SUBDEVICE_103C1925: return "Smart Array";
        case PciSubDevice103C323C::SUBDEVICE_103C1926: return "P731m";
        case PciSubDevice103C323C::SUBDEVICE_103C1928: return "P230i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323C_H
