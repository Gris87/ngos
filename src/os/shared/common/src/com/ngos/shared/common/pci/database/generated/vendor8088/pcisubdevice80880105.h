// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880105_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880105_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80880105: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80880202 = 0x80880202,
    SUBDEVICE_80884202 = 0x80884202,
    SUBDEVICE_80888202 = 0x80888202,
    SUBDEVICE_8088C202 = 0x8088C202
};



inline const char8* enumToString(PciSubDevice80880105 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880105::NONE:               return "NONE";
        case PciSubDevice80880105::SUBDEVICE_80880202: return "SUBDEVICE_80880202";
        case PciSubDevice80880105::SUBDEVICE_80884202: return "SUBDEVICE_80884202";
        case PciSubDevice80880105::SUBDEVICE_80888202: return "SUBDEVICE_80888202";
        case PciSubDevice80880105::SUBDEVICE_8088C202: return "SUBDEVICE_8088C202";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80880105 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80880105 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880105::SUBDEVICE_80880202: return "Dual-Port Ethernet Network Adaptor SF200HT";
        case PciSubDevice80880105::SUBDEVICE_80884202: return "Dual-Port Ethernet Network Adaptor SF200HT (WOL)";
        case PciSubDevice80880105::SUBDEVICE_80888202: return "Dual-Port Ethernet Network Adaptor SF200HT (NCSI)";
        case PciSubDevice80880105::SUBDEVICE_8088C202: return "Dual-Port Ethernet Network Adaptor SF200HT (WOL, NCSI)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880105_H
