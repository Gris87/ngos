// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0103_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0103_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice115D0103: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10149181 = 0x10149181,
    SUBDEVICE_11151181 = 0x11151181,
    SUBDEVICE_115D1181 = 0x115D1181,
    SUBDEVICE_80869181 = 0x80869181
};



inline const char8* enumToString(PciSubDevice115D0103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0103::NONE:               return "NONE";
        case PciSubDevice115D0103::SUBDEVICE_10149181: return "SUBDEVICE_10149181";
        case PciSubDevice115D0103::SUBDEVICE_11151181: return "SUBDEVICE_11151181";
        case PciSubDevice115D0103::SUBDEVICE_115D1181: return "SUBDEVICE_115D1181";
        case PciSubDevice115D0103::SUBDEVICE_80869181: return "SUBDEVICE_80869181";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice115D0103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice115D0103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice115D0103::SUBDEVICE_10149181: return "Cardbus 56k Modem";
        case PciSubDevice115D0103::SUBDEVICE_11151181: return "Cardbus Ethernet 100 + 56k Modem";
        case PciSubDevice115D0103::SUBDEVICE_115D1181: return "CBEM56G-100 Ethernet + 56k Modem";
        case PciSubDevice115D0103::SUBDEVICE_80869181: return "PRO/100 LAN + Modem56 CardBus";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCISUBDEVICE115D0103_H
