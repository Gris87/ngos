// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DFE300: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140614 = 0x10140614,
    SUBDEVICE_10140615 = 0x10140615,
    SUBDEVICE_10DFE300 = 0x10DFE300,
    SUBDEVICE_10DFE301 = 0x10DFE301,
    SUBDEVICE_10DFE310 = 0x10DFE310,
    SUBDEVICE_10DFE311 = 0x10DFE311,
    SUBDEVICE_10DFE312 = 0x10DFE312,
    SUBDEVICE_10DFE320 = 0x10DFE320,
    SUBDEVICE_10DFE321 = 0x10DFE321,
    SUBDEVICE_10DFE322 = 0x10DFE322,
    SUBDEVICE_10DFE323 = 0x10DFE323,
    SUBDEVICE_10DFE324 = 0x10DFE324,
    SUBDEVICE_10DFE325 = 0x10DFE325,
    SUBDEVICE_10DFE330 = 0x10DFE330,
    SUBDEVICE_10DFE331 = 0x10DFE331,
    SUBDEVICE_10DFE332 = 0x10DFE332,
    SUBDEVICE_10DFE333 = 0x10DFE333,
    SUBDEVICE_15900201 = 0x15900201,
    SUBDEVICE_15900202 = 0x15900202,
    SUBDEVICE_15900213 = 0x15900213,
    SUBDEVICE_15900214 = 0x15900214,
    SUBDEVICE_1590022E = 0x1590022E
};



inline const char8* enumToString(PciSubDevice10DFE300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFE300::NONE:               return "NONE";
        case PciSubDevice10DFE300::SUBDEVICE_10140614: return "SUBDEVICE_10140614";
        case PciSubDevice10DFE300::SUBDEVICE_10140615: return "SUBDEVICE_10140615";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE300: return "SUBDEVICE_10DFE300";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE301: return "SUBDEVICE_10DFE301";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE310: return "SUBDEVICE_10DFE310";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE311: return "SUBDEVICE_10DFE311";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE312: return "SUBDEVICE_10DFE312";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE320: return "SUBDEVICE_10DFE320";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE321: return "SUBDEVICE_10DFE321";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE322: return "SUBDEVICE_10DFE322";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE323: return "SUBDEVICE_10DFE323";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE324: return "SUBDEVICE_10DFE324";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE325: return "SUBDEVICE_10DFE325";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE330: return "SUBDEVICE_10DFE330";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE331: return "SUBDEVICE_10DFE331";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE332: return "SUBDEVICE_10DFE332";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE333: return "SUBDEVICE_10DFE333";
        case PciSubDevice10DFE300::SUBDEVICE_15900201: return "SUBDEVICE_15900201";
        case PciSubDevice10DFE300::SUBDEVICE_15900202: return "SUBDEVICE_15900202";
        case PciSubDevice10DFE300::SUBDEVICE_15900213: return "SUBDEVICE_15900213";
        case PciSubDevice10DFE300::SUBDEVICE_15900214: return "SUBDEVICE_15900214";
        case PciSubDevice10DFE300::SUBDEVICE_1590022E: return "SUBDEVICE_1590022E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DFE300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DFE300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFE300::SUBDEVICE_10140614: return "PCIe3 4-Port 16Gb Fibre Channel Adapter for POWER (FC EN1C/EN1D; CCIN 578E)";
        case PciSubDevice10DFE300::SUBDEVICE_10140615: return "PCIe3 2-Port 32Gb Fibre Channel Adapter for POWER (FC EN1A/EN1B; CCIN 578F)";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE300: return "LPe32002-M2 2-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE301: return "LPe32000-M2 1-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE310: return "LPe31002-M6 2-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE311: return "LPe31000-M6 1-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE312: return "LPe31004-M6 4-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE320: return "LPe32002-M2-D 2-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE321: return "LPe32000-M2-D 1-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE322: return "LPe31002-M6-D 2-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE323: return "LPe31000-M6-D 1-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE324: return "LPm32002-D 2-Port 32Gb Fibre Channel Mezz Card";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE325: return "LPm31002-D 2-Port 16Gb Fibre Channel Mezz Card";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE330: return "LPe32002-M2-L 2-Port 32Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE331: return "LPe32000-M2-L 1-Port 32Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE332: return "LPe31002-M6-L 2-Port 16Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_10DFE333: return "LPe31000-M6-L 1-Port 16Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_15900201: return "StoreFabric SN1600E 1-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_15900202: return "StoreFabric SN1600E 2-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_15900213: return "StoreFabric SN1200E 1-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_15900214: return "StoreFabric SN1200E 2-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE300::SUBDEVICE_1590022E: return "Synergy 5330C 2-Port 32Gb Fibre Channel Mezz Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE300_H
