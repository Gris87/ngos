// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050284_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050284_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050284: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050284 = 0x90050284
};



inline const char8* enumToString(PciSubDevice90050284 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050284::NONE:               return "NONE";
        case PciSubDevice90050284::SUBDEVICE_90050284: return "SUBDEVICE_90050284";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050284 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050284 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050284::SUBDEVICE_90050284: return "Tomcat";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050284_H
