// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice115D0101: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_115D1081 = 0x115D1081
};



inline const char8* enumToString(PciSubDevice115D0101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0101::NONE:               return "NONE";
        case PciSubDevice115D0101::SUBDEVICE_115D1081: return "SUBDEVICE_115D1081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice115D0101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice115D0101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0101::SUBDEVICE_115D1081: return "Cardbus 56k Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0101_H
