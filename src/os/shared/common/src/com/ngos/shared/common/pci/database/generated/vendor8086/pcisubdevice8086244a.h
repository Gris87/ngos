// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086244A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10251016 = 0x10251016,
    SUBDEVICE_104D80DF = 0x104D80DF
};



inline const char8* enumToString(PciSubDevice8086244A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086244A::NONE:               return "NONE";
        case PciSubDevice8086244A::SUBDEVICE_10251016: return "SUBDEVICE_10251016";
        case PciSubDevice8086244A::SUBDEVICE_104D80DF: return "SUBDEVICE_104D80DF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086244A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086244A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086244A::SUBDEVICE_10251016: return "Travelmate 612TX";
        case PciSubDevice8086244A::SUBDEVICE_104D80DF: return "Vaio PCG-FX403";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244A_H
