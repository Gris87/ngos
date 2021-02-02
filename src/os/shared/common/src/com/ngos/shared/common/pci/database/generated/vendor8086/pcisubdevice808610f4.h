// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610F4: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086106F = 0x8086106F,
    SUBDEVICE_8086A06F = 0x8086A06F
};



inline const char8* enumToString(PciSubDevice808610F4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F4::NONE:               return "NONE";
        case PciSubDevice808610F4::SUBDEVICE_8086106F: return "SUBDEVICE_8086106F";
        case PciSubDevice808610F4::SUBDEVICE_8086A06F: return "SUBDEVICE_8086A06F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610F4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610F4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F4::SUBDEVICE_8086106F: return "10-Gigabit XF LR Server Adapter";
        case PciSubDevice808610F4::SUBDEVICE_8086A06F: return "10-Gigabit XF LR Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F4_H
