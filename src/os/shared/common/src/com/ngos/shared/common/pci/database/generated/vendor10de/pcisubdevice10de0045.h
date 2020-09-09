// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0045_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0045_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0045: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043817D = 0x1043817D,
    SUBDEVICE_14583140 = 0x14583140
};



inline const char8* enumToString(PciSubDevice10DE0045 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0045::NONE:               return "NONE";
        case PciSubDevice10DE0045::SUBDEVICE_1043817D: return "SUBDEVICE_1043817D";
        case PciSubDevice10DE0045::SUBDEVICE_14583140: return "SUBDEVICE_14583140";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0045 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0045 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0045::SUBDEVICE_1043817D: return "V9999GT";
        case PciSubDevice10DE0045::SUBDEVICE_14583140: return "GV-N68T256D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0045_H
