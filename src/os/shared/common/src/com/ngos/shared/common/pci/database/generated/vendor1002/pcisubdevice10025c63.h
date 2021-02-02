// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025C63_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025C63_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025C63: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10025C63 = 0x10025C63,
    SUBDEVICE_144DC00C = 0x144DC00C
};



inline const char8* enumToString(PciSubDevice10025C63 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025C63::NONE:               return "NONE";
        case PciSubDevice10025C63::SUBDEVICE_10025C63: return "SUBDEVICE_10025C63";
        case PciSubDevice10025C63::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025C63 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025C63 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025C63::SUBDEVICE_10025C63: return "Apple iBook G4 2004";
        case PciSubDevice10025C63::SUBDEVICE_144DC00C: return "P30 notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025C63_H
