// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862425_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862425_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862425: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11D40040 = 0x11D40040,
    SUBDEVICE_11D40048 = 0x11D40048
};



inline const char8* enumToString(PciSubDevice80862425 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862425::NONE:               return "NONE";
        case PciSubDevice80862425::SUBDEVICE_11D40040: return "SUBDEVICE_11D40040";
        case PciSubDevice80862425::SUBDEVICE_11D40048: return "SUBDEVICE_11D40048";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862425 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862425 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862425::SUBDEVICE_11D40040: return "SoundMAX Integrated Digital Audio";
        case PciSubDevice80862425::SUBDEVICE_11D40048: return "SoundMAX Integrated Digital Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862425_H
