// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086156F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086156F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086156F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806DC = 0x102806DC,
    SUBDEVICE_103C8079 = 0x103C8079
};



inline const char8* enumToString(PciSubDevice8086156F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086156F::NONE:               return "NONE";
        case PciSubDevice8086156F::SUBDEVICE_102806DC: return "SUBDEVICE_102806DC";
        case PciSubDevice8086156F::SUBDEVICE_103C8079: return "SUBDEVICE_103C8079";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086156F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086156F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086156F::SUBDEVICE_102806DC: return "Latitude E7470";
        case PciSubDevice8086156F::SUBDEVICE_103C8079: return "EliteBook 840 G3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086156F_H
