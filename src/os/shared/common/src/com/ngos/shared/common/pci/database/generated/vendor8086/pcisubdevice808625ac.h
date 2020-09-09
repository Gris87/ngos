// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808625AC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808625AC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808625AC: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17341073 = 0x17341073,
    SUBDEVICE_177510D0 = 0x177510D0,
    SUBDEVICE_17751100 = 0x17751100,
    SUBDEVICE_1775CE90 = 0x1775CE90,
    SUBDEVICE_4C5310B0 = 0x4C5310B0,
    SUBDEVICE_4C5310D0 = 0x4C5310D0,
    SUBDEVICE_4C5310E0 = 0x4C5310E0
};



inline const char8* enumToString(PciSubDevice808625AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808625AC::NONE:               return "NONE";
        case PciSubDevice808625AC::SUBDEVICE_17341073: return "SUBDEVICE_17341073";
        case PciSubDevice808625AC::SUBDEVICE_177510D0: return "SUBDEVICE_177510D0";
        case PciSubDevice808625AC::SUBDEVICE_17751100: return "SUBDEVICE_17751100";
        case PciSubDevice808625AC::SUBDEVICE_1775CE90: return "SUBDEVICE_1775CE90";
        case PciSubDevice808625AC::SUBDEVICE_4C5310B0: return "SUBDEVICE_4C5310B0";
        case PciSubDevice808625AC::SUBDEVICE_4C5310D0: return "SUBDEVICE_4C5310D0";
        case PciSubDevice808625AC::SUBDEVICE_4C5310E0: return "SUBDEVICE_4C5310E0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808625AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808625AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808625AC::SUBDEVICE_17341073: return "Primergy Econel 200 D2020 mainboard";
        case PciSubDevice808625AC::SUBDEVICE_177510D0: return "V5D Single Board Computer";
        case PciSubDevice808625AC::SUBDEVICE_17751100: return "CR11/VR11 Single Board Computer";
        case PciSubDevice808625AC::SUBDEVICE_1775CE90: return "CE9";
        case PciSubDevice808625AC::SUBDEVICE_4C5310B0: return "CL9 mainboard";
        case PciSubDevice808625AC::SUBDEVICE_4C5310D0: return "Telum ASLP10 Processor AMC";
        case PciSubDevice808625AC::SUBDEVICE_4C5310E0: return "PSL09 PrPMC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808625AC_H
