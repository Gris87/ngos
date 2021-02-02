// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AD_PCISUBDEVICE15AD0801_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AD_PCISUBDEVICE15AD0801_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15AD0801: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15AD0800 = 0x15AD0800
};



inline const char8* enumToString(PciSubDevice15AD0801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15AD0801::NONE:               return "NONE";
        case PciSubDevice15AD0801::SUBDEVICE_15AD0800: return "SUBDEVICE_15AD0800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15AD0801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15AD0801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15AD0801::SUBDEVICE_15AD0800: return "Hypervisor ROM Interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AD_PCISUBDEVICE15AD0801_H
