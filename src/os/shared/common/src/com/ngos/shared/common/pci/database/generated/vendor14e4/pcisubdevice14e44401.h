// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44401_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44401_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44401: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250035 = 0x10250035,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_10288127 = 0x10288127,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_104380A8 = 0x104380A8
};



inline const char8* enumToString(PciSubDevice14E44401 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44401::NONE:               return "NONE";
        case PciSubDevice14E44401::SUBDEVICE_10250035: return "SUBDEVICE_10250035";
        case PciSubDevice14E44401::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice14E44401::SUBDEVICE_10288127: return "SUBDEVICE_10288127";
        case PciSubDevice14E44401::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice14E44401::SUBDEVICE_104380A8: return "SUBDEVICE_104380A8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44401 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44401 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44401::SUBDEVICE_10250035: return "TravelMate 660";
        case PciSubDevice14E44401::SUBDEVICE_10250064: return "Extensa 3000 series laptop";
        case PciSubDevice14E44401::SUBDEVICE_10288127: return "Dimension 2400";
        case PciSubDevice14E44401::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice14E44401::SUBDEVICE_104380A8: return "A7V8X motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44401_H
