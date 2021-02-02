// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice121A0009: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_121A0003 = 0x121A0003,
    SUBDEVICE_121A0009 = 0x121A0009
};



inline const char8* enumToString(PciSubDevice121A0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121A0009::NONE:               return "NONE";
        case PciSubDevice121A0009::SUBDEVICE_121A0003: return "SUBDEVICE_121A0003";
        case PciSubDevice121A0009::SUBDEVICE_121A0009: return "SUBDEVICE_121A0009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice121A0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice121A0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121A0009::SUBDEVICE_121A0003: return "Voodoo5 PCI 5500";
        case PciSubDevice121A0009::SUBDEVICE_121A0009: return "Voodoo5 AGP 5500/6000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0009_H
