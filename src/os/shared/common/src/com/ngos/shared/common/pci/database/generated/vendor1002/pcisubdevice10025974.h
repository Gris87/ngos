// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025974_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025974_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025974: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C280A = 0x103C280A,
    SUBDEVICE_14627141 = 0x14627141
};



inline const char8* enumToString(PciSubDevice10025974 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025974::NONE:               return "NONE";
        case PciSubDevice10025974::SUBDEVICE_103C280A: return "SUBDEVICE_103C280A";
        case PciSubDevice10025974::SUBDEVICE_14627141: return "SUBDEVICE_14627141";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025974 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025974 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025974::SUBDEVICE_103C280A: return "DC5750 Microtower";
        case PciSubDevice10025974::SUBDEVICE_14627141: return "Aspire L250";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025974_H
