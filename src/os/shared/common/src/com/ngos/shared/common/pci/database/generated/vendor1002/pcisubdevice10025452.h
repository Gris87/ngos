// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025452_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025452_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025452: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002001C = 0x1002001C,
    SUBDEVICE_103C1279 = 0x103C1279
};



inline const char8* enumToString(PciSubDevice10025452 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025452::NONE:               return "NONE";
        case PciSubDevice10025452::SUBDEVICE_1002001C: return "SUBDEVICE_1002001C";
        case PciSubDevice10025452::SUBDEVICE_103C1279: return "SUBDEVICE_103C1279";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025452 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025452 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025452::SUBDEVICE_1002001C: return "Rage 128 Pro 4XL";
        case PciSubDevice10025452::SUBDEVICE_103C1279: return "Rage 128 Pro 4XL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025452_H
