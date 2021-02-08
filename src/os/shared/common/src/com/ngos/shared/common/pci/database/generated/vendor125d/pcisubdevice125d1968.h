// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1968_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1968_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125D1968: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280085 = 0x10280085,
    SUBDEVICE_10338051 = 0x10338051
};



inline const char8* enumToString(PciSubDevice125D1968 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1968::NONE:               return "NONE";
        case PciSubDevice125D1968::SUBDEVICE_10280085: return "SUBDEVICE_10280085";
        case PciSubDevice125D1968::SUBDEVICE_10338051: return "SUBDEVICE_10338051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125D1968 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125D1968 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1968::SUBDEVICE_10280085: return "ES1968 Maestro-2 PCI";
        case PciSubDevice125D1968::SUBDEVICE_10338051: return "ES1968 Maestro-2 Audiodrive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1968_H
