// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1516_PCISUBDEVICE15160803_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1516_PCISUBDEVICE15160803_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15160803: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_132010BD = 0x132010BD
};



inline const char8* enumToString(PciSubDevice15160803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15160803::NONE:               return "NONE";
        case PciSubDevice15160803::SUBDEVICE_132010BD: return "SUBDEVICE_132010BD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15160803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15160803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15160803::SUBDEVICE_132010BD: return "SURECOM EP-320X-S 100/10M Ethernet PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1516_PCISUBDEVICE15160803_H
