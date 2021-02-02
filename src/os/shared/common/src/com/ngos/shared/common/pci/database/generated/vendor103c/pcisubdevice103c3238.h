// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3238_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3238_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C3238: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3211 = 0x103C3211,
    SUBDEVICE_103C3212 = 0x103C3212
};



inline const char8* enumToString(PciSubDevice103C3238 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3238::NONE:               return "NONE";
        case PciSubDevice103C3238::SUBDEVICE_103C3211: return "SUBDEVICE_103C3211";
        case PciSubDevice103C3238::SUBDEVICE_103C3212: return "SUBDEVICE_103C3212";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C3238 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C3238 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3238::SUBDEVICE_103C3211: return "Smart Array E200i";
        case PciSubDevice103C3238::SUBDEVICE_103C3212: return "Smart Array E200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3238_H
