// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C323B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3350 = 0x103C3350,
    SUBDEVICE_103C3351 = 0x103C3351,
    SUBDEVICE_103C3352 = 0x103C3352,
    SUBDEVICE_103C3354 = 0x103C3354,
    SUBDEVICE_103C3355 = 0x103C3355
};



inline const char8* enumToString(PciSubDevice103C323B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C323B::NONE:               return "NONE";
        case PciSubDevice103C323B::SUBDEVICE_103C3350: return "SUBDEVICE_103C3350";
        case PciSubDevice103C323B::SUBDEVICE_103C3351: return "SUBDEVICE_103C3351";
        case PciSubDevice103C323B::SUBDEVICE_103C3352: return "SUBDEVICE_103C3352";
        case PciSubDevice103C323B::SUBDEVICE_103C3354: return "SUBDEVICE_103C3354";
        case PciSubDevice103C323B::SUBDEVICE_103C3355: return "SUBDEVICE_103C3355";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C323B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C323B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C323B::SUBDEVICE_103C3350: return "P222";
        case PciSubDevice103C323B::SUBDEVICE_103C3351: return "P420";
        case PciSubDevice103C323B::SUBDEVICE_103C3352: return "P421";
        case PciSubDevice103C323B::SUBDEVICE_103C3354: return "P420i";
        case PciSubDevice103C323B::SUBDEVICE_103C3355: return "P220i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323B_H
