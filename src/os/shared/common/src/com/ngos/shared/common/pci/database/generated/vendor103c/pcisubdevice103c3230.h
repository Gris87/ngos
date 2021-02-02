// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3230_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3230_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C3230: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3223 = 0x103C3223,
    SUBDEVICE_103C3234 = 0x103C3234,
    SUBDEVICE_103C3235 = 0x103C3235,
    SUBDEVICE_103C3237 = 0x103C3237,
    SUBDEVICE_103C323D = 0x103C323D
};



inline const char8* enumToString(PciSubDevice103C3230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3230::NONE:               return "NONE";
        case PciSubDevice103C3230::SUBDEVICE_103C3223: return "SUBDEVICE_103C3223";
        case PciSubDevice103C3230::SUBDEVICE_103C3234: return "SUBDEVICE_103C3234";
        case PciSubDevice103C3230::SUBDEVICE_103C3235: return "SUBDEVICE_103C3235";
        case PciSubDevice103C3230::SUBDEVICE_103C3237: return "SUBDEVICE_103C3237";
        case PciSubDevice103C3230::SUBDEVICE_103C323D: return "SUBDEVICE_103C323D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C3230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C3230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3230::SUBDEVICE_103C3223: return "Smart Array P800";
        case PciSubDevice103C3230::SUBDEVICE_103C3234: return "P400 SAS Controller";
        case PciSubDevice103C3230::SUBDEVICE_103C3235: return "P400i SAS Controller";
        case PciSubDevice103C3230::SUBDEVICE_103C3237: return "E500 SAS Controller";
        case PciSubDevice103C3230::SUBDEVICE_103C323D: return "P700m SAS Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3230_H
