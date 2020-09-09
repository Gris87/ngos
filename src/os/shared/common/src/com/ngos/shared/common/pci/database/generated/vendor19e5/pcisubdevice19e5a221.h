// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E5A221_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E5A221_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E5A221: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E50454 = 0x19E50454,
    SUBDEVICE_19E504CC = 0x19E504CC,
    SUBDEVICE_19E5D14A = 0x19E5D14A,
    SUBDEVICE_19E5D14B = 0x19E5D14B
};



inline const char8* enumToString(PciSubDevice19E5A221 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E5A221::NONE:               return "NONE";
        case PciSubDevice19E5A221::SUBDEVICE_19E50454: return "SUBDEVICE_19E50454";
        case PciSubDevice19E5A221::SUBDEVICE_19E504CC: return "SUBDEVICE_19E504CC";
        case PciSubDevice19E5A221::SUBDEVICE_19E5D14A: return "SUBDEVICE_19E5D14A";
        case PciSubDevice19E5A221::SUBDEVICE_19E5D14B: return "SUBDEVICE_19E5D14B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E5A221 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E5A221 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E5A221::SUBDEVICE_19E50454: return "TM280";
        case PciSubDevice19E5A221::SUBDEVICE_19E504CC: return "TM210";
        case PciSubDevice19E5A221::SUBDEVICE_19E5D14A: return "TM280 4*25G";
        case PciSubDevice19E5A221::SUBDEVICE_19E5D14B: return "TM210 4*GE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E5A221_H
