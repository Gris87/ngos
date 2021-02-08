// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC522A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC522A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC522A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8079 = 0x103C8079,
    SUBDEVICE_103C825B = 0x103C825B,
    SUBDEVICE_17AA5124 = 0x17AA5124
};



inline const char8* enumToString(PciSubDevice10EC522A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC522A::NONE:               return "NONE";
        case PciSubDevice10EC522A::SUBDEVICE_103C8079: return "SUBDEVICE_103C8079";
        case PciSubDevice10EC522A::SUBDEVICE_103C825B: return "SUBDEVICE_103C825B";
        case PciSubDevice10EC522A::SUBDEVICE_17AA5124: return "SUBDEVICE_17AA5124";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC522A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC522A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC522A::SUBDEVICE_103C8079: return "EliteBook 840 G3";
        case PciSubDevice10EC522A::SUBDEVICE_103C825B: return "OMEN-17-w001nv";
        case PciSubDevice10EC522A::SUBDEVICE_17AA5124: return "ThinkPad E595";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC522A_H
