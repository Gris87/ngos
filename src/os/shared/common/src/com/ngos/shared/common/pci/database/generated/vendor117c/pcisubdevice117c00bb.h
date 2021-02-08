// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00BB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00BB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C00BB: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C00BC = 0x117C00BC,
    SUBDEVICE_117C00BD = 0x117C00BD,
    SUBDEVICE_117C00BE = 0x117C00BE
};



inline const char8* enumToString(PciSubDevice117C00BB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C00BB::NONE:               return "NONE";
        case PciSubDevice117C00BB::SUBDEVICE_117C00BC: return "SUBDEVICE_117C00BC";
        case PciSubDevice117C00BB::SUBDEVICE_117C00BD: return "SUBDEVICE_117C00BD";
        case PciSubDevice117C00BB::SUBDEVICE_117C00BE: return "SUBDEVICE_117C00BE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C00BB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C00BB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C00BB::SUBDEVICE_117C00BC: return "Celerity FC-321P";
        case PciSubDevice117C00BB::SUBDEVICE_117C00BD: return "Celerity FC-322P";
        case PciSubDevice117C00BB::SUBDEVICE_117C00BE: return "Celerity FC-324P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00BB_H
