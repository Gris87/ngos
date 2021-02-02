// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086422B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086422B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086422B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861101 = 0x80861101,
    SUBDEVICE_80861121 = 0x80861121
};



inline const char8* enumToString(PciSubDevice8086422B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086422B::NONE:               return "NONE";
        case PciSubDevice8086422B::SUBDEVICE_80861101: return "SUBDEVICE_80861101";
        case PciSubDevice8086422B::SUBDEVICE_80861121: return "SUBDEVICE_80861121";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086422B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086422B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086422B::SUBDEVICE_80861101: return "Centrino Ultimate-N 6300 3x3 AGN";
        case PciSubDevice8086422B::SUBDEVICE_80861121: return "Centrino Ultimate-N 6300 3x3 AGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086422B_H
