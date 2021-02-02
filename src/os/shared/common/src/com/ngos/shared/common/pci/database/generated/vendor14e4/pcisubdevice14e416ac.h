// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416AC: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140304 = 0x10140304,
    SUBDEVICE_102801BB = 0x102801BB,
    SUBDEVICE_1028020C = 0x1028020C,
    SUBDEVICE_103C1706 = 0x103C1706,
    SUBDEVICE_103C7038 = 0x103C7038,
    SUBDEVICE_103C703B = 0x103C703B,
    SUBDEVICE_103C703D = 0x103C703D
};



inline const char8* enumToString(PciSubDevice14E416AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416AC::NONE:               return "NONE";
        case PciSubDevice14E416AC::SUBDEVICE_10140304: return "SUBDEVICE_10140304";
        case PciSubDevice14E416AC::SUBDEVICE_102801BB: return "SUBDEVICE_102801BB";
        case PciSubDevice14E416AC::SUBDEVICE_1028020C: return "SUBDEVICE_1028020C";
        case PciSubDevice14E416AC::SUBDEVICE_103C1706: return "SUBDEVICE_103C1706";
        case PciSubDevice14E416AC::SUBDEVICE_103C7038: return "SUBDEVICE_103C7038";
        case PciSubDevice14E416AC::SUBDEVICE_103C703B: return "SUBDEVICE_103C703B";
        case PciSubDevice14E416AC::SUBDEVICE_103C703D: return "SUBDEVICE_103C703D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416AC::SUBDEVICE_10140304: return "NetXtreme II BCM5708S Gigabit Ethernet";
        case PciSubDevice14E416AC::SUBDEVICE_102801BB: return "PowerEdge 1955 Broadcom NetXtreme II BCM5708S";
        case PciSubDevice14E416AC::SUBDEVICE_1028020C: return "PowerEdge M605 Broadcom NetXtreme II BCM5708S";
        case PciSubDevice14E416AC::SUBDEVICE_103C1706: return "NC373m Multifunction Gigabit Server Adapter";
        case PciSubDevice14E416AC::SUBDEVICE_103C7038: return "NC373i PCI Express Multifunction Gigabit Server Adapter";
        case PciSubDevice14E416AC::SUBDEVICE_103C703B: return "NC373i Integrated Multifunction Gigabit Server Adapter";
        case PciSubDevice14E416AC::SUBDEVICE_103C703D: return "NC373F PCI Express Multifunction Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AC_H
