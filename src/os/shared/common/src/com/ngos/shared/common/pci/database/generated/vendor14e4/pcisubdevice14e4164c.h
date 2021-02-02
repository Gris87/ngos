// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4164C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801F0 = 0x102801F0,
    SUBDEVICE_10280205 = 0x10280205,
    SUBDEVICE_1028020B = 0x1028020B,
    SUBDEVICE_10280221 = 0x10280221,
    SUBDEVICE_10280223 = 0x10280223,
    SUBDEVICE_10281F12 = 0x10281F12,
    SUBDEVICE_103C7037 = 0x103C7037,
    SUBDEVICE_103C7038 = 0x103C7038,
    SUBDEVICE_103C7045 = 0x103C7045
};



inline const char8* enumToString(PciSubDevice14E4164C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4164C::NONE:               return "NONE";
        case PciSubDevice14E4164C::SUBDEVICE_102801F0: return "SUBDEVICE_102801F0";
        case PciSubDevice14E4164C::SUBDEVICE_10280205: return "SUBDEVICE_10280205";
        case PciSubDevice14E4164C::SUBDEVICE_1028020B: return "SUBDEVICE_1028020B";
        case PciSubDevice14E4164C::SUBDEVICE_10280221: return "SUBDEVICE_10280221";
        case PciSubDevice14E4164C::SUBDEVICE_10280223: return "SUBDEVICE_10280223";
        case PciSubDevice14E4164C::SUBDEVICE_10281F12: return "SUBDEVICE_10281F12";
        case PciSubDevice14E4164C::SUBDEVICE_103C7037: return "SUBDEVICE_103C7037";
        case PciSubDevice14E4164C::SUBDEVICE_103C7038: return "SUBDEVICE_103C7038";
        case PciSubDevice14E4164C::SUBDEVICE_103C7045: return "SUBDEVICE_103C7045";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4164C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4164C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4164C::SUBDEVICE_102801F0: return "PowerEdge R900 Broadcom NetXtreme II BCM5708";
        case PciSubDevice14E4164C::SUBDEVICE_10280205: return "PowerEdge 2970 Broadcom NetXtreme II BCM5708";
        case PciSubDevice14E4164C::SUBDEVICE_1028020B: return "PowerEdge T605 Broadcom NetXtreme II BCM5708";
        case PciSubDevice14E4164C::SUBDEVICE_10280221: return "PowerEdge R805 Broadcom NetXtreme II BCM5708";
        case PciSubDevice14E4164C::SUBDEVICE_10280223: return "PowerEdge R905 Broadcom NetXtreme II BCM5708";
        case PciSubDevice14E4164C::SUBDEVICE_10281F12: return "PowerEdge R805/R905 Broadcom NetXtreme II BCM5708";
        case PciSubDevice14E4164C::SUBDEVICE_103C7037: return "NC373T PCI Express Multifunction Gigabit Server Adapter";
        case PciSubDevice14E4164C::SUBDEVICE_103C7038: return "NC373i Integrated Multifunction Gigabit Server Adapter";
        case PciSubDevice14E4164C::SUBDEVICE_103C7045: return "NC374m PCI Express Dual Port Multifunction Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164C_H
