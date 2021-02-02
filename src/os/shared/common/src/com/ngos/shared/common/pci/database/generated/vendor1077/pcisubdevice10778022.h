// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778022_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778022_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10778022: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3347 = 0x103C3347,
    SUBDEVICE_10770212 = 0x10770212
};



inline const char8* enumToString(PciSubDevice10778022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778022::NONE:               return "NONE";
        case PciSubDevice10778022::SUBDEVICE_103C3347: return "SUBDEVICE_103C3347";
        case PciSubDevice10778022::SUBDEVICE_10770212: return "SUBDEVICE_10770212";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10778022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10778022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778022::SUBDEVICE_103C3347: return "CN1000Q Dual Port Converged Network Adapter";
        case PciSubDevice10778022::SUBDEVICE_10770212: return "QME8242-k 10GbE Dual Port Mezzanine Card, iSCSI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778022_H
