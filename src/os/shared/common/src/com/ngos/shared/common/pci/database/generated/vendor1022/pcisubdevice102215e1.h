// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE102215E1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE102215E1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102215E1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8615 = 0x103C8615,
    SUBDEVICE_17AA5124 = 0x17AA5124
};



inline const char8* enumToString(PciSubDevice102215E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102215E1::NONE:               return "NONE";
        case PciSubDevice102215E1::SUBDEVICE_103C8615: return "SUBDEVICE_103C8615";
        case PciSubDevice102215E1::SUBDEVICE_17AA5124: return "SUBDEVICE_17AA5124";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102215E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102215E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102215E1::SUBDEVICE_103C8615: return "Pavilion Laptop 15-cw1xxx";
        case PciSubDevice102215E1::SUBDEVICE_17AA5124: return "ThinkPad E595";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE102215E1_H
