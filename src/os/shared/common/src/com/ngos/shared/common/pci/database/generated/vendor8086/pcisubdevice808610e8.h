// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610E8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610E8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610E8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086A02B = 0x8086A02B,
    SUBDEVICE_8086A02C = 0x8086A02C
};



inline const char8* enumToString(PciSubDevice808610E8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610E8::NONE:               return "NONE";
        case PciSubDevice808610E8::SUBDEVICE_8086A02B: return "SUBDEVICE_8086A02B";
        case PciSubDevice808610E8::SUBDEVICE_8086A02C: return "SUBDEVICE_8086A02C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610E8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610E8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610E8::SUBDEVICE_8086A02B: return "Gigabit ET Quad Port Server Adapter";
        case PciSubDevice808610E8::SUBDEVICE_8086A02C: return "Gigabit ET Quad Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610E8_H
