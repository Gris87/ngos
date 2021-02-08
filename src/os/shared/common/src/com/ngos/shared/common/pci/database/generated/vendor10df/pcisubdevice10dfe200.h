// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE200_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE200_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DFE200: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101403F1 = 0x101403F1,
    SUBDEVICE_101404E3 = 0x101404E3,
    SUBDEVICE_101404E4 = 0x101404E4,
    SUBDEVICE_10DFE280 = 0x10DFE280,
    SUBDEVICE_10DFE281 = 0x10DFE281,
    SUBDEVICE_10DFE282 = 0x10DFE282
};



inline const char8* enumToString(PciSubDevice10DFE200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFE200::NONE:               return "NONE";
        case PciSubDevice10DFE200::SUBDEVICE_101403F1: return "SUBDEVICE_101403F1";
        case PciSubDevice10DFE200::SUBDEVICE_101404E3: return "SUBDEVICE_101404E3";
        case PciSubDevice10DFE200::SUBDEVICE_101404E4: return "SUBDEVICE_101404E4";
        case PciSubDevice10DFE200::SUBDEVICE_10DFE280: return "SUBDEVICE_10DFE280";
        case PciSubDevice10DFE200::SUBDEVICE_10DFE281: return "SUBDEVICE_10DFE281";
        case PciSubDevice10DFE200::SUBDEVICE_10DFE282: return "SUBDEVICE_10DFE282";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DFE200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DFE200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFE200::SUBDEVICE_101403F1: return "PCIe2 2-Port 16Gb Fibre Channel Adapter for POWER (FC EL5B; CCIN 577F)";
        case PciSubDevice10DFE200::SUBDEVICE_101404E3: return "PCIe3 4-Port 10GbE SR Adapter for POWER (FC EN15/EN16; CCIN 2CE3)";
        case PciSubDevice10DFE200::SUBDEVICE_101404E4: return "PCIe3 4-Port 10GbE SFP+ Adapter for POWER (FC EN18; CCIN 2CE4)";
        case PciSubDevice10DFE200::SUBDEVICE_10DFE280: return "LPe16002B-M6 2-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE200::SUBDEVICE_10DFE281: return "LPe16000B-M6 1-Port 16Gb Fibre Channel Adapter";
        case PciSubDevice10DFE200::SUBDEVICE_10DFE282: return "Flex System FC5054 4-port 16Gb FC Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE200_H
