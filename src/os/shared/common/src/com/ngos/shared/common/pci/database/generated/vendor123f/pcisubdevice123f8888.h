// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCISUBDEVICE123F8888_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCISUBDEVICE123F8888_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice123F8888: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020001 = 0x10020001,
    SUBDEVICE_10020002 = 0x10020002,
    SUBDEVICE_13280001 = 0x13280001
};



inline const char8* enumToString(PciSubDevice123F8888 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice123F8888::NONE:               return "NONE";
        case PciSubDevice123F8888::SUBDEVICE_10020001: return "SUBDEVICE_10020001";
        case PciSubDevice123F8888::SUBDEVICE_10020002: return "SUBDEVICE_10020002";
        case PciSubDevice123F8888::SUBDEVICE_13280001: return "SUBDEVICE_13280001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice123F8888 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice123F8888 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice123F8888::SUBDEVICE_10020001: return "Cinemaster C 3.0 DVD Decoder";
        case PciSubDevice123F8888::SUBDEVICE_10020002: return "Cinemaster C 3.0 DVD Decoder";
        case PciSubDevice123F8888::SUBDEVICE_13280001: return "Cinemaster C 3.0 DVD Decoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCISUBDEVICE123F8888_H
