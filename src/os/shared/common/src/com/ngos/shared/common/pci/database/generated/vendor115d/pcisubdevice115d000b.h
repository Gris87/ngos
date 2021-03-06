// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D000B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D000B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice115D000B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140183 = 0x10140183,
    SUBDEVICE_115D0183 = 0x115D0183
};



inline const char8* enumToString(PciSubDevice115D000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D000B::NONE:               return "NONE";
        case PciSubDevice115D000B::SUBDEVICE_10140183: return "SUBDEVICE_10140183";
        case PciSubDevice115D000B::SUBDEVICE_115D0183: return "SUBDEVICE_115D0183";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice115D000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice115D000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D000B::SUBDEVICE_10140183: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D000B::SUBDEVICE_115D0183: return "Cardbus Ethernet 10/100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D000B_H
