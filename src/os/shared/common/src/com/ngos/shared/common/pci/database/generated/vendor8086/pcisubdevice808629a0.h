// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808629A0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808629A0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808629A0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104381EA = 0x104381EA,
    SUBDEVICE_14627276 = 0x14627276
};



inline const char8* enumToString(PciSubDevice808629A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808629A0::NONE:               return "NONE";
        case PciSubDevice808629A0::SUBDEVICE_104381EA: return "SUBDEVICE_104381EA";
        case PciSubDevice808629A0::SUBDEVICE_14627276: return "SUBDEVICE_14627276";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808629A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808629A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808629A0::SUBDEVICE_104381EA: return "P5B";
        case PciSubDevice808629A0::SUBDEVICE_14627276: return "MS-7276 [G965MDH]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808629A0_H
