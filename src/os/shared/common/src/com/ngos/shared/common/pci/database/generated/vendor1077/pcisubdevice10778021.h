// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778021_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778021_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10778021: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3348 = 0x103C3348,
    SUBDEVICE_10770211 = 0x10770211
};



inline const char8* enumToString(PciSubDevice10778021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778021::NONE:               return "NONE";
        case PciSubDevice10778021::SUBDEVICE_103C3348: return "SUBDEVICE_103C3348";
        case PciSubDevice10778021::SUBDEVICE_10770211: return "SUBDEVICE_10770211";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10778021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10778021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778021::SUBDEVICE_103C3348: return "CN1000Q Dual Port Converged Network Adapter";
        case PciSubDevice10778021::SUBDEVICE_10770211: return "QME8242-k 10GbE Dual Port Mezzanine Card, FCoE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778021_H
