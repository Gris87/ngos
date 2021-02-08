// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4A14_PCISUBDEVICE4A145000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4A14_PCISUBDEVICE4A145000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice4A145000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4A145000 = 0x4A145000
};



inline const char8* enumToString(PciSubDevice4A145000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice4A145000::NONE:               return "NONE";
        case PciSubDevice4A145000::SUBDEVICE_4A145000: return "SUBDEVICE_4A145000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice4A145000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice4A145000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice4A145000::SUBDEVICE_4A145000: return "RT8029-Based Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4A14_PCISUBDEVICE4A145000_H
