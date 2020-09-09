// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90047815_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90047815_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90047815: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90047815 = 0x90047815,
    SUBDEVICE_90047840 = 0x90047840
};



inline const char8* enumToString(PciSubDevice90047815 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90047815::NONE:               return "NONE";
        case PciSubDevice90047815::SUBDEVICE_90047815: return "SUBDEVICE_90047815";
        case PciSubDevice90047815::SUBDEVICE_90047840: return "SUBDEVICE_90047840";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90047815 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90047815 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90047815::SUBDEVICE_90047815: return "ARO-1130U2 RAID Controller";
        case PciSubDevice90047815::SUBDEVICE_90047840: return "AIC-7815 RAID+Memory Controller IC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90047815_H
