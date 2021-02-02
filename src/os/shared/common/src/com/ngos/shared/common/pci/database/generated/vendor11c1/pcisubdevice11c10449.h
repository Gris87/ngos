// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10449_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10449_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10449: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B14D = 0x0E11B14D,
    SUBDEVICE_1014018C = 0x1014018C,
    SUBDEVICE_13E00020 = 0x13E00020,
    SUBDEVICE_13E00041 = 0x13E00041,
    SUBDEVICE_14360440 = 0x14360440,
    SUBDEVICE_144F0449 = 0x144F0449,
    SUBDEVICE_14680410 = 0x14680410,
    SUBDEVICE_14680440 = 0x14680440,
    SUBDEVICE_14680449 = 0x14680449
};



inline const char8* enumToString(PciSubDevice11C10449 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10449::NONE:               return "NONE";
        case PciSubDevice11C10449::SUBDEVICE_0E11B14D: return "SUBDEVICE_0E11B14D";
        case PciSubDevice11C10449::SUBDEVICE_1014018C: return "SUBDEVICE_1014018C";
        case PciSubDevice11C10449::SUBDEVICE_13E00020: return "SUBDEVICE_13E00020";
        case PciSubDevice11C10449::SUBDEVICE_13E00041: return "SUBDEVICE_13E00041";
        case PciSubDevice11C10449::SUBDEVICE_14360440: return "SUBDEVICE_14360440";
        case PciSubDevice11C10449::SUBDEVICE_144F0449: return "SUBDEVICE_144F0449";
        case PciSubDevice11C10449::SUBDEVICE_14680410: return "SUBDEVICE_14680410";
        case PciSubDevice11C10449::SUBDEVICE_14680440: return "SUBDEVICE_14680440";
        case PciSubDevice11C10449::SUBDEVICE_14680449: return "SUBDEVICE_14680449";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10449 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10449 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10449::SUBDEVICE_0E11B14D: return "56k V.90 Modem";
        case PciSubDevice11C10449::SUBDEVICE_1014018C: return "ThinkPad 600X";
        case PciSubDevice11C10449::SUBDEVICE_13E00020: return "LT WinModem 56k Data+Fax";
        case PciSubDevice11C10449::SUBDEVICE_13E00041: return "TelePath Internet 56k WinModem";
        case PciSubDevice11C10449::SUBDEVICE_14360440: return "Lucent Win Modem";
        case PciSubDevice11C10449::SUBDEVICE_144F0449: return "Lucent 56k V.90 DFi Modem";
        case PciSubDevice11C10449::SUBDEVICE_14680410: return "IBM ThinkPad T23";
        case PciSubDevice11C10449::SUBDEVICE_14680440: return "Lucent Win Modem";
        case PciSubDevice11C10449::SUBDEVICE_14680449: return "Presario 56k V.90 DFi Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10449_H
