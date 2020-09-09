// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10440_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10440_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10440: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10338015 = 0x10338015,
    SUBDEVICE_10338047 = 0x10338047,
    SUBDEVICE_1033804F = 0x1033804F,
    SUBDEVICE_10CF102C = 0x10CF102C,
    SUBDEVICE_10CF104A = 0x10CF104A,
    SUBDEVICE_10CF105F = 0x10CF105F,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_11C10440 = 0x11C10440,
    SUBDEVICE_122D4101 = 0x122D4101,
    SUBDEVICE_122D4102 = 0x122D4102,
    SUBDEVICE_13E00040 = 0x13E00040,
    SUBDEVICE_13E00440 = 0x13E00440,
    SUBDEVICE_13E00441 = 0x13E00441,
    SUBDEVICE_13E00450 = 0x13E00450,
    SUBDEVICE_13E0F100 = 0x13E0F100,
    SUBDEVICE_13E0F101 = 0x13E0F101,
    SUBDEVICE_144D2101 = 0x144D2101,
    SUBDEVICE_149F0440 = 0x149F0440
};



inline const char8* enumToString(PciSubDevice11C10440 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10440::NONE:               return "NONE";
        case PciSubDevice11C10440::SUBDEVICE_10338015: return "SUBDEVICE_10338015";
        case PciSubDevice11C10440::SUBDEVICE_10338047: return "SUBDEVICE_10338047";
        case PciSubDevice11C10440::SUBDEVICE_1033804F: return "SUBDEVICE_1033804F";
        case PciSubDevice11C10440::SUBDEVICE_10CF102C: return "SUBDEVICE_10CF102C";
        case PciSubDevice11C10440::SUBDEVICE_10CF104A: return "SUBDEVICE_10CF104A";
        case PciSubDevice11C10440::SUBDEVICE_10CF105F: return "SUBDEVICE_10CF105F";
        case PciSubDevice11C10440::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11C10440::SUBDEVICE_11C10440: return "SUBDEVICE_11C10440";
        case PciSubDevice11C10440::SUBDEVICE_122D4101: return "SUBDEVICE_122D4101";
        case PciSubDevice11C10440::SUBDEVICE_122D4102: return "SUBDEVICE_122D4102";
        case PciSubDevice11C10440::SUBDEVICE_13E00040: return "SUBDEVICE_13E00040";
        case PciSubDevice11C10440::SUBDEVICE_13E00440: return "SUBDEVICE_13E00440";
        case PciSubDevice11C10440::SUBDEVICE_13E00441: return "SUBDEVICE_13E00441";
        case PciSubDevice11C10440::SUBDEVICE_13E00450: return "SUBDEVICE_13E00450";
        case PciSubDevice11C10440::SUBDEVICE_13E0F100: return "SUBDEVICE_13E0F100";
        case PciSubDevice11C10440::SUBDEVICE_13E0F101: return "SUBDEVICE_13E0F101";
        case PciSubDevice11C10440::SUBDEVICE_144D2101: return "SUBDEVICE_144D2101";
        case PciSubDevice11C10440::SUBDEVICE_149F0440: return "SUBDEVICE_149F0440";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10440 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10440 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10440::SUBDEVICE_10338015: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_10338047: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_1033804F: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_10CF102C: return "LB LT Modem V.90 56k";
        case PciSubDevice11C10440::SUBDEVICE_10CF104A: return "BIBLO LT Modem 56k";
        case PciSubDevice11C10440::SUBDEVICE_10CF105F: return "LB2 LT Modem V.90 56k";
        case PciSubDevice11C10440::SUBDEVICE_11790001: return "Internal V.90 Modem";
        case PciSubDevice11C10440::SUBDEVICE_11C10440: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_122D4101: return "MDP7800-U Modem";
        case PciSubDevice11C10440::SUBDEVICE_122D4102: return "MDP7800SP-U Modem";
        case PciSubDevice11C10440::SUBDEVICE_13E00040: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_13E00440: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_13E00441: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_13E00450: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_13E0F100: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_13E0F101: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10440::SUBDEVICE_144D2101: return "LT56PV Modem";
        case PciSubDevice11C10440::SUBDEVICE_149F0440: return "LT WinModem 56k Data+Fax+Voice+Dsvd";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10440_H
