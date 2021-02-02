// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861526_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861526_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861526: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086A05C = 0x8086A05C,
    SUBDEVICE_8086A06C = 0x8086A06C
};



inline const char8* enumToString(PciSubDevice80861526 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861526::NONE:               return "NONE";
        case PciSubDevice80861526::SUBDEVICE_8086A05C: return "SUBDEVICE_8086A05C";
        case PciSubDevice80861526::SUBDEVICE_8086A06C: return "SUBDEVICE_8086A06C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861526 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861526 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861526::SUBDEVICE_8086A05C: return "Gigabit ET2 Quad Port Server Adapter";
        case PciSubDevice80861526::SUBDEVICE_8086A06C: return "Gigabit ET2 Quad Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861526_H
