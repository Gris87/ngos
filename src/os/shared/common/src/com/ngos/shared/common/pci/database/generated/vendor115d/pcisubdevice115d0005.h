// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice115D0005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140182 = 0x10140182,
    SUBDEVICE_10141182 = 0x10141182,
    SUBDEVICE_115D0182 = 0x115D0182,
    SUBDEVICE_115D1182 = 0x115D1182
};



inline const char8* enumToString(PciSubDevice115D0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0005::NONE:               return "NONE";
        case PciSubDevice115D0005::SUBDEVICE_10140182: return "SUBDEVICE_10140182";
        case PciSubDevice115D0005::SUBDEVICE_10141182: return "SUBDEVICE_10141182";
        case PciSubDevice115D0005::SUBDEVICE_115D0182: return "SUBDEVICE_115D0182";
        case PciSubDevice115D0005::SUBDEVICE_115D1182: return "SUBDEVICE_115D1182";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice115D0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice115D0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0005::SUBDEVICE_10140182: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D0005::SUBDEVICE_10141182: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D0005::SUBDEVICE_115D0182: return "Cardbus Ethernet 10/100";
        case PciSubDevice115D0005::SUBDEVICE_115D1182: return "Cardbus Ethernet 10/100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0005_H
