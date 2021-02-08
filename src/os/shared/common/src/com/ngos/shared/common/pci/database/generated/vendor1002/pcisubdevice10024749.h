// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024749_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024749_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024749: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020061 = 0x10020061,
    SUBDEVICE_10020062 = 0x10020062
};



inline const char8* enumToString(PciSubDevice10024749 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024749::NONE:               return "NONE";
        case PciSubDevice10024749::SUBDEVICE_10020061: return "SUBDEVICE_10020061";
        case PciSubDevice10024749::SUBDEVICE_10020062: return "SUBDEVICE_10020062";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024749 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024749 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024749::SUBDEVICE_10020061: return "Rage Pro AIW";
        case PciSubDevice10024749::SUBDEVICE_10020062: return "Rage Pro AIW";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024749_H
