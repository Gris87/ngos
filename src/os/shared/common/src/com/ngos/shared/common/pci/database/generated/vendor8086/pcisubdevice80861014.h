// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861014: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860014 = 0x80860014,
    SUBDEVICE_80861014 = 0x80861014
};



inline const char8* enumToString(PciSubDevice80861014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861014::NONE:               return "NONE";
        case PciSubDevice80861014::SUBDEVICE_80860014: return "SUBDEVICE_80860014";
        case PciSubDevice80861014::SUBDEVICE_80861014: return "SUBDEVICE_80861014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861014::SUBDEVICE_80860014: return "PRO/1000 MT Desktop Connection";
        case PciSubDevice80861014::SUBDEVICE_80861014: return "PRO/1000 MT Network Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861014_H
