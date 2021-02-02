// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10441_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10441_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10441: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1033804D = 0x1033804D,
    SUBDEVICE_10338065 = 0x10338065,
    SUBDEVICE_10920440 = 0x10920440,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_11C10440 = 0x11C10440,
    SUBDEVICE_11C10441 = 0x11C10441,
    SUBDEVICE_122D4100 = 0x122D4100,
    SUBDEVICE_13E00040 = 0x13E00040,
    SUBDEVICE_13E00100 = 0x13E00100,
    SUBDEVICE_13E00410 = 0x13E00410,
    SUBDEVICE_13E00420 = 0x13E00420,
    SUBDEVICE_13E00440 = 0x13E00440,
    SUBDEVICE_13E00443 = 0x13E00443,
    SUBDEVICE_13E0F102 = 0x13E0F102,
    SUBDEVICE_14169804 = 0x14169804,
    SUBDEVICE_141D0440 = 0x141D0440,
    SUBDEVICE_144F0441 = 0x144F0441,
    SUBDEVICE_144F0449 = 0x144F0449,
    SUBDEVICE_144F110D = 0x144F110D,
    SUBDEVICE_14680441 = 0x14680441,
    SUBDEVICE_16680440 = 0x16680440
};



inline const char8* enumToString(PciSubDevice11C10441 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10441::NONE:               return "NONE";
        case PciSubDevice11C10441::SUBDEVICE_1033804D: return "SUBDEVICE_1033804D";
        case PciSubDevice11C10441::SUBDEVICE_10338065: return "SUBDEVICE_10338065";
        case PciSubDevice11C10441::SUBDEVICE_10920440: return "SUBDEVICE_10920440";
        case PciSubDevice11C10441::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11C10441::SUBDEVICE_11C10440: return "SUBDEVICE_11C10440";
        case PciSubDevice11C10441::SUBDEVICE_11C10441: return "SUBDEVICE_11C10441";
        case PciSubDevice11C10441::SUBDEVICE_122D4100: return "SUBDEVICE_122D4100";
        case PciSubDevice11C10441::SUBDEVICE_13E00040: return "SUBDEVICE_13E00040";
        case PciSubDevice11C10441::SUBDEVICE_13E00100: return "SUBDEVICE_13E00100";
        case PciSubDevice11C10441::SUBDEVICE_13E00410: return "SUBDEVICE_13E00410";
        case PciSubDevice11C10441::SUBDEVICE_13E00420: return "SUBDEVICE_13E00420";
        case PciSubDevice11C10441::SUBDEVICE_13E00440: return "SUBDEVICE_13E00440";
        case PciSubDevice11C10441::SUBDEVICE_13E00443: return "SUBDEVICE_13E00443";
        case PciSubDevice11C10441::SUBDEVICE_13E0F102: return "SUBDEVICE_13E0F102";
        case PciSubDevice11C10441::SUBDEVICE_14169804: return "SUBDEVICE_14169804";
        case PciSubDevice11C10441::SUBDEVICE_141D0440: return "SUBDEVICE_141D0440";
        case PciSubDevice11C10441::SUBDEVICE_144F0441: return "SUBDEVICE_144F0441";
        case PciSubDevice11C10441::SUBDEVICE_144F0449: return "SUBDEVICE_144F0449";
        case PciSubDevice11C10441::SUBDEVICE_144F110D: return "SUBDEVICE_144F110D";
        case PciSubDevice11C10441::SUBDEVICE_14680441: return "SUBDEVICE_14680441";
        case PciSubDevice11C10441::SUBDEVICE_16680440: return "SUBDEVICE_16680440";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10441 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10441 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10441::SUBDEVICE_1033804D: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_10338065: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_10920440: return "Supra 56i";
        case PciSubDevice11C10441::SUBDEVICE_11790001: return "Internal V.90 Modem";
        case PciSubDevice11C10441::SUBDEVICE_11C10440: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_11C10441: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_122D4100: return "MDP7800-U Modem";
        case PciSubDevice11C10441::SUBDEVICE_13E00040: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_13E00100: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_13E00410: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_13E00420: return "TelePath Internet 56k WinModem";
        case PciSubDevice11C10441::SUBDEVICE_13E00440: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_13E00443: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_13E0F102: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_14169804: return "CommWave 56k Modem";
        case PciSubDevice11C10441::SUBDEVICE_141D0440: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10441::SUBDEVICE_144F0441: return "Lucent 56k V.90 DF Modem";
        case PciSubDevice11C10441::SUBDEVICE_144F0449: return "Lucent 56k V.90 DF Modem";
        case PciSubDevice11C10441::SUBDEVICE_144F110D: return "Lucent Win Modem";
        case PciSubDevice11C10441::SUBDEVICE_14680441: return "Presario 56k V.90 DF Modem";
        case PciSubDevice11C10441::SUBDEVICE_16680440: return "Lucent Win Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10441_H
