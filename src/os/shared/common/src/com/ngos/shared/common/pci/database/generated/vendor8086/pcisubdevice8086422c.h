// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086422C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086422C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086422C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861301 = 0x80861301,
    SUBDEVICE_80861306 = 0x80861306,
    SUBDEVICE_80861307 = 0x80861307,
    SUBDEVICE_80861321 = 0x80861321,
    SUBDEVICE_80861326 = 0x80861326
};



inline const char8* enumToString(PciSubDevice8086422C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086422C::NONE:               return "NONE";
        case PciSubDevice8086422C::SUBDEVICE_80861301: return "SUBDEVICE_80861301";
        case PciSubDevice8086422C::SUBDEVICE_80861306: return "SUBDEVICE_80861306";
        case PciSubDevice8086422C::SUBDEVICE_80861307: return "SUBDEVICE_80861307";
        case PciSubDevice8086422C::SUBDEVICE_80861321: return "SUBDEVICE_80861321";
        case PciSubDevice8086422C::SUBDEVICE_80861326: return "SUBDEVICE_80861326";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086422C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086422C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086422C::SUBDEVICE_80861301: return "Centrino Advanced-N 6200 2x2 AGN";
        case PciSubDevice8086422C::SUBDEVICE_80861306: return "Centrino Advanced-N 6200 2x2 ABG";
        case PciSubDevice8086422C::SUBDEVICE_80861307: return "Centrino Advanced-N 6200 2x2 BG";
        case PciSubDevice8086422C::SUBDEVICE_80861321: return "Centrino Advanced-N 6200 2x2 AGN";
        case PciSubDevice8086422C::SUBDEVICE_80861326: return "Centrino Advanced-N 6200 2x2 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086422C_H
