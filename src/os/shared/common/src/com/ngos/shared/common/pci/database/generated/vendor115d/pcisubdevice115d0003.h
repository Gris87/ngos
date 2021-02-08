// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice115D0003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140181 = 0x10140181,
    SUBDEVICE_10141181 = 0x10141181,
    SUBDEVICE_10148181 = 0x10148181,
    SUBDEVICE_10149181 = 0x10149181,
    SUBDEVICE_115D0181 = 0x115D0181,
    SUBDEVICE_115D0182 = 0x115D0182,
    SUBDEVICE_115D1181 = 0x115D1181,
    SUBDEVICE_11790181 = 0x11790181,
    SUBDEVICE_80868181 = 0x80868181,
    SUBDEVICE_80869181 = 0x80869181
};



inline const char8* enumToString(PciSubDevice115D0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0003::NONE:               return "NONE";
        case PciSubDevice115D0003::SUBDEVICE_10140181: return "SUBDEVICE_10140181";
        case PciSubDevice115D0003::SUBDEVICE_10141181: return "SUBDEVICE_10141181";
        case PciSubDevice115D0003::SUBDEVICE_10148181: return "SUBDEVICE_10148181";
        case PciSubDevice115D0003::SUBDEVICE_10149181: return "SUBDEVICE_10149181";
        case PciSubDevice115D0003::SUBDEVICE_115D0181: return "SUBDEVICE_115D0181";
        case PciSubDevice115D0003::SUBDEVICE_115D0182: return "SUBDEVICE_115D0182";
        case PciSubDevice115D0003::SUBDEVICE_115D1181: return "SUBDEVICE_115D1181";
        case PciSubDevice115D0003::SUBDEVICE_11790181: return "SUBDEVICE_11790181";
        case PciSubDevice115D0003::SUBDEVICE_80868181: return "SUBDEVICE_80868181";
        case PciSubDevice115D0003::SUBDEVICE_80869181: return "SUBDEVICE_80869181";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice115D0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice115D0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0003::SUBDEVICE_10140181: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D0003::SUBDEVICE_10141181: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D0003::SUBDEVICE_10148181: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D0003::SUBDEVICE_10149181: return "10/100 EtherJet Cardbus Adapter";
        case PciSubDevice115D0003::SUBDEVICE_115D0181: return "Cardbus Ethernet 10/100";
        case PciSubDevice115D0003::SUBDEVICE_115D0182: return "RealPort2 CardBus Ethernet 10/100 (R2BE-100)";
        case PciSubDevice115D0003::SUBDEVICE_115D1181: return "Cardbus Ethernet 10/100";
        case PciSubDevice115D0003::SUBDEVICE_11790181: return "Cardbus Ethernet 10/100";
        case PciSubDevice115D0003::SUBDEVICE_80868181: return "EtherExpress PRO/100 Mobile CardBus 32 Adapter";
        case PciSubDevice115D0003::SUBDEVICE_80869181: return "EtherExpress PRO/100 Mobile CardBus 32 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0003_H
