// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050013: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050003 = 0x90050003,
    SUBDEVICE_9005000F = 0x9005000F
};



inline const char8* enumToString(PciSubDevice90050013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050013::NONE:               return "NONE";
        case PciSubDevice90050013::SUBDEVICE_90050003: return "SUBDEVICE_90050003";
        case PciSubDevice90050013::SUBDEVICE_9005000F: return "SUBDEVICE_9005000F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050013::SUBDEVICE_90050003: return "AAA-131U2 Array1000 1 Channel RAID Controller";
        case PciSubDevice90050013::SUBDEVICE_9005000F: return "AIC7890_ARO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050013_H
