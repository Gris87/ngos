// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808671A0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808671A0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808671A0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051
};



inline const char8* enumToString(PciSubDevice808671A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808671A0::NONE:               return "NONE";
        case PciSubDevice808671A0::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice808671A0::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808671A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808671A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808671A0::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice808671A0::SUBDEVICE_4C531051: return "CE7 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808671A0_H
