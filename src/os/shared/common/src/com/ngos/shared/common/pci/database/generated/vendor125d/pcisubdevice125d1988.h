// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1988_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1988_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125D1988: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110098 = 0x0E110098,
    SUBDEVICE_10924100 = 0x10924100,
    SUBDEVICE_125D0431 = 0x125D0431,
    SUBDEVICE_125D1988 = 0x125D1988,
    SUBDEVICE_125D1998 = 0x125D1998,
    SUBDEVICE_125D1999 = 0x125D1999
};



inline const char8* enumToString(PciSubDevice125D1988 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1988::NONE:               return "NONE";
        case PciSubDevice125D1988::SUBDEVICE_0E110098: return "SUBDEVICE_0E110098";
        case PciSubDevice125D1988::SUBDEVICE_10924100: return "SUBDEVICE_10924100";
        case PciSubDevice125D1988::SUBDEVICE_125D0431: return "SUBDEVICE_125D0431";
        case PciSubDevice125D1988::SUBDEVICE_125D1988: return "SUBDEVICE_125D1988";
        case PciSubDevice125D1988::SUBDEVICE_125D1998: return "SUBDEVICE_125D1998";
        case PciSubDevice125D1988::SUBDEVICE_125D1999: return "SUBDEVICE_125D1999";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125D1988 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125D1988 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1988::SUBDEVICE_0E110098: return "Evo N600c";
        case PciSubDevice125D1988::SUBDEVICE_10924100: return "Sonic Impact S100";
        case PciSubDevice125D1988::SUBDEVICE_125D0431: return "Allegro AudioDrive";
        case PciSubDevice125D1988::SUBDEVICE_125D1988: return "ESS Allegro-1 Audiodrive";
        case PciSubDevice125D1988::SUBDEVICE_125D1998: return "Allegro AudioDrive";
        case PciSubDevice125D1988::SUBDEVICE_125D1999: return "Allegro-1 AudioDrive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1988_H
