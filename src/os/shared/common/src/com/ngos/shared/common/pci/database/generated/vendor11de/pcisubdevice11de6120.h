// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCISUBDEVICE11DE6120_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCISUBDEVICE11DE6120_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11DE6120: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1328F001 = 0x1328F001,
    SUBDEVICE_13C20000 = 0x13C20000,
    SUBDEVICE_1DE19FFF = 0x1DE19FFF
};



inline const char8* enumToString(PciSubDevice11DE6120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11DE6120::NONE:               return "NONE";
        case PciSubDevice11DE6120::SUBDEVICE_1328F001: return "SUBDEVICE_1328F001";
        case PciSubDevice11DE6120::SUBDEVICE_13C20000: return "SUBDEVICE_13C20000";
        case PciSubDevice11DE6120::SUBDEVICE_1DE19FFF: return "SUBDEVICE_1DE19FFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11DE6120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11DE6120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11DE6120::SUBDEVICE_1328F001: return "Cinemaster C DVD Decoder";
        case PciSubDevice11DE6120::SUBDEVICE_13C20000: return "MediaFocus Satellite TV Card";
        case PciSubDevice11DE6120::SUBDEVICE_1DE19FFF: return "Video Kit C210";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCISUBDEVICE11DE6120_H
