// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10238620_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10238620_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10238620: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140502 = 0x10140502,
    SUBDEVICE_10141025 = 0x10141025
};



inline const char8* enumToString(PciSubDevice10238620 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10238620::NONE:               return "NONE";
        case PciSubDevice10238620::SUBDEVICE_10140502: return "SUBDEVICE_10140502";
        case PciSubDevice10238620::SUBDEVICE_10141025: return "SUBDEVICE_10141025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10238620 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10238620 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10238620::SUBDEVICE_10140502: return "ThinkPad R30/T30";
        case PciSubDevice10238620::SUBDEVICE_10141025: return "Travelmate 352TE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10238620_H
