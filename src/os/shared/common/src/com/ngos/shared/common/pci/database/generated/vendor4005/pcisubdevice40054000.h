// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4005_PCISUBDEVICE40054000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4005_PCISUBDEVICE40054000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice40054000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_40054000 = 0x40054000
};



inline const char8* enumToString(PciSubDevice40054000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice40054000::NONE:               return "NONE";
        case PciSubDevice40054000::SUBDEVICE_40054000: return "SUBDEVICE_40054000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice40054000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice40054000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice40054000::SUBDEVICE_40054000: return "ALS4000 Audio Chipset";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4005_PCISUBDEVICE40054000_H
