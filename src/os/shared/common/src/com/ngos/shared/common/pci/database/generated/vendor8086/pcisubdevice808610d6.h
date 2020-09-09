// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610D6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610D6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610D6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_808610D6 = 0x808610D6,
    SUBDEVICE_8086145A = 0x8086145A,
    SUBDEVICE_8086147A = 0x8086147A
};



inline const char8* enumToString(PciSubDevice808610D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610D6::NONE:               return "NONE";
        case PciSubDevice808610D6::SUBDEVICE_808610D6: return "SUBDEVICE_808610D6";
        case PciSubDevice808610D6::SUBDEVICE_8086145A: return "SUBDEVICE_8086145A";
        case PciSubDevice808610D6::SUBDEVICE_8086147A: return "SUBDEVICE_8086147A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610D6::SUBDEVICE_808610D6: return "Gigabit VT Quad Port Server Adapter";
        case PciSubDevice808610D6::SUBDEVICE_8086145A: return "Gigabit VT Quad Port Server Adapter";
        case PciSubDevice808610D6::SUBDEVICE_8086147A: return "Gigabit VT Quad Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610D6_H
