// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029903_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029903_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029903: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C194E = 0x103C194E,
    SUBDEVICE_103C1952 = 0x103C1952
};



inline const char8* enumToString(PciSubDevice10029903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029903::NONE:               return "NONE";
        case PciSubDevice10029903::SUBDEVICE_103C194E: return "SUBDEVICE_103C194E";
        case PciSubDevice10029903::SUBDEVICE_103C1952: return "SUBDEVICE_103C1952";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029903::SUBDEVICE_103C194E: return "ProBook 455 G1 Notebook";
        case PciSubDevice10029903::SUBDEVICE_103C1952: return "ProBook 455 G1 Notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029903_H
