// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953512_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953512_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10953512: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10953512 = 0x10953512,
    SUBDEVICE_10956512 = 0x10956512
};



inline const char8* enumToString(PciSubDevice10953512 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10953512::NONE:               return "NONE";
        case PciSubDevice10953512::SUBDEVICE_10953512: return "SUBDEVICE_10953512";
        case PciSubDevice10953512::SUBDEVICE_10956512: return "SUBDEVICE_10956512";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10953512 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10953512 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10953512::SUBDEVICE_10953512: return "SiI 3512 SATALink Controller";
        case PciSubDevice10953512::SUBDEVICE_10956512: return "SiI 3512 SATARaid Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953512_H
