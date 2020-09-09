// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002515E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002515E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002515E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801BB = 0x102801BB,
    SUBDEVICE_102801DF = 0x102801DF,
    SUBDEVICE_102801E6 = 0x102801E6,
    SUBDEVICE_102801F0 = 0x102801F0,
    SUBDEVICE_10280205 = 0x10280205,
    SUBDEVICE_1028020B = 0x1028020B,
    SUBDEVICE_1028020F = 0x1028020F,
    SUBDEVICE_10280210 = 0x10280210,
    SUBDEVICE_10280221 = 0x10280221,
    SUBDEVICE_10280223 = 0x10280223,
    SUBDEVICE_10280225 = 0x10280225,
    SUBDEVICE_1028023C = 0x1028023C,
    SUBDEVICE_103C1304 = 0x103C1304,
    SUBDEVICE_15D98680 = 0x15D98680,
    SUBDEVICE_15D99680 = 0x15D99680,
    SUBDEVICE_80863476 = 0x80863476
};



inline const char8* enumToString(PciSubDevice1002515E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002515E::NONE:               return "NONE";
        case PciSubDevice1002515E::SUBDEVICE_102801BB: return "SUBDEVICE_102801BB";
        case PciSubDevice1002515E::SUBDEVICE_102801DF: return "SUBDEVICE_102801DF";
        case PciSubDevice1002515E::SUBDEVICE_102801E6: return "SUBDEVICE_102801E6";
        case PciSubDevice1002515E::SUBDEVICE_102801F0: return "SUBDEVICE_102801F0";
        case PciSubDevice1002515E::SUBDEVICE_10280205: return "SUBDEVICE_10280205";
        case PciSubDevice1002515E::SUBDEVICE_1028020B: return "SUBDEVICE_1028020B";
        case PciSubDevice1002515E::SUBDEVICE_1028020F: return "SUBDEVICE_1028020F";
        case PciSubDevice1002515E::SUBDEVICE_10280210: return "SUBDEVICE_10280210";
        case PciSubDevice1002515E::SUBDEVICE_10280221: return "SUBDEVICE_10280221";
        case PciSubDevice1002515E::SUBDEVICE_10280223: return "SUBDEVICE_10280223";
        case PciSubDevice1002515E::SUBDEVICE_10280225: return "SUBDEVICE_10280225";
        case PciSubDevice1002515E::SUBDEVICE_1028023C: return "SUBDEVICE_1028023C";
        case PciSubDevice1002515E::SUBDEVICE_103C1304: return "SUBDEVICE_103C1304";
        case PciSubDevice1002515E::SUBDEVICE_15D98680: return "SUBDEVICE_15D98680";
        case PciSubDevice1002515E::SUBDEVICE_15D99680: return "SUBDEVICE_15D99680";
        case PciSubDevice1002515E::SUBDEVICE_80863476: return "SUBDEVICE_80863476";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002515E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002515E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002515E::SUBDEVICE_102801BB: return "PowerEdge 1955 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_102801DF: return "PowerEdge SC440";
        case PciSubDevice1002515E::SUBDEVICE_102801E6: return "PowerEdge 860";
        case PciSubDevice1002515E::SUBDEVICE_102801F0: return "PowerEdge R900 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_10280205: return "PowerEdge 2970 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_1028020B: return "PowerEdge T605 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_1028020F: return "PowerEdge R300 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_10280210: return "PowerEdge T300 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_10280221: return "PowerEdge R805 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_10280223: return "PowerEdge R905 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_10280225: return "PowerEdge T105 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_1028023C: return "PowerEdge R200 Embedded ATI ES1000";
        case PciSubDevice1002515E::SUBDEVICE_103C1304: return "Integrity iLO2 Advanced KVM VGA [AD307A]";
        case PciSubDevice1002515E::SUBDEVICE_15D98680: return "X7DVL-E-O motherboard";
        case PciSubDevice1002515E::SUBDEVICE_15D99680: return "X7DBN Motherboard";
        case PciSubDevice1002515E::SUBDEVICE_80863476: return "S5000PSLSATA Server Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002515E_H
