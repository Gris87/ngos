// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B58624_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B58624_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B58624: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13A31845 = 0x13A31845
};



inline const char8* enumToString(PciSubDevice10B58624 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B58624::NONE:               return "NONE";
        case PciSubDevice10B58624::SUBDEVICE_13A31845: return "SUBDEVICE_13A31845";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B58624 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B58624 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B58624::SUBDEVICE_13A31845: return "DX1845 Acceleration Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B58624_H
