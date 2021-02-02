// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCISUBDEVICE101E1960_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCISUBDEVICE101E1960_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101E1960: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101E0471 = 0x101E0471,
    SUBDEVICE_101E0475 = 0x101E0475,
    SUBDEVICE_101E0477 = 0x101E0477,
    SUBDEVICE_101E0493 = 0x101E0493,
    SUBDEVICE_101E0494 = 0x101E0494,
    SUBDEVICE_101E0503 = 0x101E0503,
    SUBDEVICE_101E0511 = 0x101E0511,
    SUBDEVICE_101E0522 = 0x101E0522,
    SUBDEVICE_10280471 = 0x10280471,
    SUBDEVICE_10280475 = 0x10280475,
    SUBDEVICE_10280493 = 0x10280493,
    SUBDEVICE_10280511 = 0x10280511,
    SUBDEVICE_103C60E7 = 0x103C60E7,
    SUBDEVICE_103C60E8 = 0x103C60E8
};



inline const char8* enumToString(PciSubDevice101E1960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101E1960::NONE:               return "NONE";
        case PciSubDevice101E1960::SUBDEVICE_101E0471: return "SUBDEVICE_101E0471";
        case PciSubDevice101E1960::SUBDEVICE_101E0475: return "SUBDEVICE_101E0475";
        case PciSubDevice101E1960::SUBDEVICE_101E0477: return "SUBDEVICE_101E0477";
        case PciSubDevice101E1960::SUBDEVICE_101E0493: return "SUBDEVICE_101E0493";
        case PciSubDevice101E1960::SUBDEVICE_101E0494: return "SUBDEVICE_101E0494";
        case PciSubDevice101E1960::SUBDEVICE_101E0503: return "SUBDEVICE_101E0503";
        case PciSubDevice101E1960::SUBDEVICE_101E0511: return "SUBDEVICE_101E0511";
        case PciSubDevice101E1960::SUBDEVICE_101E0522: return "SUBDEVICE_101E0522";
        case PciSubDevice101E1960::SUBDEVICE_10280471: return "SUBDEVICE_10280471";
        case PciSubDevice101E1960::SUBDEVICE_10280475: return "SUBDEVICE_10280475";
        case PciSubDevice101E1960::SUBDEVICE_10280493: return "SUBDEVICE_10280493";
        case PciSubDevice101E1960::SUBDEVICE_10280511: return "SUBDEVICE_10280511";
        case PciSubDevice101E1960::SUBDEVICE_103C60E7: return "SUBDEVICE_103C60E7";
        case PciSubDevice101E1960::SUBDEVICE_103C60E8: return "SUBDEVICE_103C60E8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101E1960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101E1960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101E1960::SUBDEVICE_101E0471: return "MegaRAID 471 Enterprise 1600 RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0475: return "MegaRAID 475 Express 500/500LC RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0477: return "MegaRAID 477 Elite 3100 RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0493: return "MegaRAID 493 Elite 1600 RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0494: return "MegaRAID 494 Elite 1650 RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0503: return "MegaRAID 503 Enterprise 1650 RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0511: return "MegaRAID 511 i4 IDE RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_101E0522: return "MegaRAID 522 i4133 RAID Controller";
        case PciSubDevice101E1960::SUBDEVICE_10280471: return "PowerEdge RAID Controller 3/QC";
        case PciSubDevice101E1960::SUBDEVICE_10280475: return "PowerEdge RAID Controller 3/SC";
        case PciSubDevice101E1960::SUBDEVICE_10280493: return "PowerEdge RAID Controller 3/DC";
        case PciSubDevice101E1960::SUBDEVICE_10280511: return "PowerEdge Cost Effective RAID Controller ATA100/4Ch";
        case PciSubDevice101E1960::SUBDEVICE_103C60E7: return "NetRAID-1M";
        case PciSubDevice101E1960::SUBDEVICE_103C60E8: return "NetRaid 2M [AMI MegaRaid 493]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCISUBDEVICE101E1960_H
