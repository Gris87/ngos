// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862700_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862700_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862700: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80863900 = 0x80863900,
    SUBDEVICE_80863901 = 0x80863901
};



inline const char8* enumToString(PciSubDevice80862700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862700::NONE:               return "NONE";
        case PciSubDevice80862700::SUBDEVICE_80863900: return "SUBDEVICE_80863900";
        case PciSubDevice80862700::SUBDEVICE_80863901: return "SUBDEVICE_80863901";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862700::SUBDEVICE_80863900: return "900P Series [Add-in Card]";
        case PciSubDevice80862700::SUBDEVICE_80863901: return "900P Series [2.5\" SFF]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862700_H
