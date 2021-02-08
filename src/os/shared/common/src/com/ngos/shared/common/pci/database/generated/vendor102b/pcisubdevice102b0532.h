// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0532_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0532_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B0532: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280235 = 0x10280235,
    SUBDEVICE_10280236 = 0x10280236,
    SUBDEVICE_10280237 = 0x10280237,
    SUBDEVICE_10280287 = 0x10280287,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D,
    SUBDEVICE_1028029C = 0x1028029C,
    SUBDEVICE_102802A4 = 0x102802A4,
    SUBDEVICE_15D90605 = 0x15D90605,
    SUBDEVICE_15D90624 = 0x15D90624,
    SUBDEVICE_15D9066B = 0x15D9066B,
    SUBDEVICE_15D9A811 = 0x15D9A811
};



inline const char8* enumToString(PciSubDevice102B0532 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0532::NONE:               return "NONE";
        case PciSubDevice102B0532::SUBDEVICE_10280235: return "SUBDEVICE_10280235";
        case PciSubDevice102B0532::SUBDEVICE_10280236: return "SUBDEVICE_10280236";
        case PciSubDevice102B0532::SUBDEVICE_10280237: return "SUBDEVICE_10280237";
        case PciSubDevice102B0532::SUBDEVICE_10280287: return "SUBDEVICE_10280287";
        case PciSubDevice102B0532::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice102B0532::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";
        case PciSubDevice102B0532::SUBDEVICE_1028029C: return "SUBDEVICE_1028029C";
        case PciSubDevice102B0532::SUBDEVICE_102802A4: return "SUBDEVICE_102802A4";
        case PciSubDevice102B0532::SUBDEVICE_15D90605: return "SUBDEVICE_15D90605";
        case PciSubDevice102B0532::SUBDEVICE_15D90624: return "SUBDEVICE_15D90624";
        case PciSubDevice102B0532::SUBDEVICE_15D9066B: return "SUBDEVICE_15D9066B";
        case PciSubDevice102B0532::SUBDEVICE_15D9A811: return "SUBDEVICE_15D9A811";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B0532 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B0532 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0532::SUBDEVICE_10280235: return "PowerEdge R710 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_10280236: return "PowerEdge R610 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_10280237: return "PowerEdge T610 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_10280287: return "PowerEdge M610 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_1028028C: return "PowerEdge R410 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_1028028D: return "PowerEdge T410 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_1028029C: return "PowerEdge M710 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_102802A4: return "PowerEdge T310 MGA G200eW WPCM450";
        case PciSubDevice102B0532::SUBDEVICE_15D90605: return "X8SIL";
        case PciSubDevice102B0532::SUBDEVICE_15D90624: return "X9SCM-F Motherboard";
        case PciSubDevice102B0532::SUBDEVICE_15D9066B: return "X9SRL-F";
        case PciSubDevice102B0532::SUBDEVICE_15D9A811: return "H8DGU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0532_H
