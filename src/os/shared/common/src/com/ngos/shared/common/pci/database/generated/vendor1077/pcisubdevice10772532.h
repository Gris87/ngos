// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772532_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772532_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772532: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014041E = 0x1014041E,
    SUBDEVICE_103C3262 = 0x103C3262,
    SUBDEVICE_103C3263 = 0x103C3263,
    SUBDEVICE_1077015C = 0x1077015C,
    SUBDEVICE_1077015D = 0x1077015D,
    SUBDEVICE_1077015E = 0x1077015E,
    SUBDEVICE_10770167 = 0x10770167,
    SUBDEVICE_159000FC = 0x159000FC
};



inline const char8* enumToString(PciSubDevice10772532 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772532::NONE:               return "NONE";
        case PciSubDevice10772532::SUBDEVICE_1014041E: return "SUBDEVICE_1014041E";
        case PciSubDevice10772532::SUBDEVICE_103C3262: return "SUBDEVICE_103C3262";
        case PciSubDevice10772532::SUBDEVICE_103C3263: return "SUBDEVICE_103C3263";
        case PciSubDevice10772532::SUBDEVICE_1077015C: return "SUBDEVICE_1077015C";
        case PciSubDevice10772532::SUBDEVICE_1077015D: return "SUBDEVICE_1077015D";
        case PciSubDevice10772532::SUBDEVICE_1077015E: return "SUBDEVICE_1077015E";
        case PciSubDevice10772532::SUBDEVICE_10770167: return "SUBDEVICE_10770167";
        case PciSubDevice10772532::SUBDEVICE_159000FC: return "SUBDEVICE_159000FC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772532 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772532 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772532::SUBDEVICE_1014041E: return "FC EN0Y/EN12 PCIe2 LP 8 Gb 4-port Fibre Channel Adapter for POWER";
        case PciSubDevice10772532::SUBDEVICE_103C3262: return "StorageWorks 81Q";
        case PciSubDevice10772532::SUBDEVICE_103C3263: return "StorageWorks 82Q";
        case PciSubDevice10772532::SUBDEVICE_1077015C: return "QLE2560 PCI Express to 8Gb FC Single Channel";
        case PciSubDevice10772532::SUBDEVICE_1077015D: return "QLE2562 PCI Express to 8Gb FC Dual Channel";
        case PciSubDevice10772532::SUBDEVICE_1077015E: return "QLE2564 PCI Express to 8Gb FC Quad Channel";
        case PciSubDevice10772532::SUBDEVICE_10770167: return "QME2572 Dual Port FC8 HBA Mezzanine";
        case PciSubDevice10772532::SUBDEVICE_159000FC: return "StoreFabric 84Q 8Gb Quad Port Fibre Channel Host Bus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772532_H
