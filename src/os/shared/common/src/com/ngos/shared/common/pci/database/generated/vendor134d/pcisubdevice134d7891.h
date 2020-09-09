// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134D_PCISUBDEVICE134D7891_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134D_PCISUBDEVICE134D7891_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice134D7891: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_134D0001 = 0x134D0001
};



inline const char8* enumToString(PciSubDevice134D7891 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice134D7891::NONE:               return "NONE";
        case PciSubDevice134D7891::SUBDEVICE_134D0001: return "SUBDEVICE_134D0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice134D7891 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice134D7891 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice134D7891::SUBDEVICE_134D0001: return "HSP MicroModem 56";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134D_PCISUBDEVICE134D7891_H
