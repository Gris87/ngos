// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19692062_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19692062_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19692062: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438468 = 0x10438468
};



inline const char8* enumToString(PciSubDevice19692062 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19692062::NONE:               return "NONE";
        case PciSubDevice19692062::SUBDEVICE_10438468: return "SUBDEVICE_10438468";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19692062 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19692062 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19692062::SUBDEVICE_10438468: return "Eee PC 1015PX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19692062_H
