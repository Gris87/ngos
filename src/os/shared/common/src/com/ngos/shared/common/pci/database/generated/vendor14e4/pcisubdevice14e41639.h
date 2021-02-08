// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41639_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41639_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41639: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280235 = 0x10280235,
    SUBDEVICE_10280236 = 0x10280236,
    SUBDEVICE_10280237 = 0x10280237,
    SUBDEVICE_103C7055 = 0x103C7055,
    SUBDEVICE_103C7059 = 0x103C7059,
    SUBDEVICE_10A98027 = 0x10A98027
};



inline const char8* enumToString(PciSubDevice14E41639 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41639::NONE:               return "NONE";
        case PciSubDevice14E41639::SUBDEVICE_10280235: return "SUBDEVICE_10280235";
        case PciSubDevice14E41639::SUBDEVICE_10280236: return "SUBDEVICE_10280236";
        case PciSubDevice14E41639::SUBDEVICE_10280237: return "SUBDEVICE_10280237";
        case PciSubDevice14E41639::SUBDEVICE_103C7055: return "SUBDEVICE_103C7055";
        case PciSubDevice14E41639::SUBDEVICE_103C7059: return "SUBDEVICE_103C7059";
        case PciSubDevice14E41639::SUBDEVICE_10A98027: return "SUBDEVICE_10A98027";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41639 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41639 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41639::SUBDEVICE_10280235: return "PowerEdge R710 BCM5709 Gigabit Ethernet";
        case PciSubDevice14E41639::SUBDEVICE_10280236: return "PowerEdge R610 BCM5709 Gigabit Ethernet";
        case PciSubDevice14E41639::SUBDEVICE_10280237: return "PowerEdge T610 BCM5709 Gigabit Ethernet";
        case PciSubDevice14E41639::SUBDEVICE_103C7055: return "NC382i Integrated Multi-port PCI Express Gigabit Server Adapter";
        case PciSubDevice14E41639::SUBDEVICE_103C7059: return "NC382T PCIe Dual Port Multifunction Gigabit Server Adapter";
        case PciSubDevice14E41639::SUBDEVICE_10A98027: return "Quad port Gigabit Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41639_H
