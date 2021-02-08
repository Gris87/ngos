// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DFF100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014038A = 0x1014038A,
    SUBDEVICE_103C3282 = 0x103C3282,
    SUBDEVICE_10DFF140 = 0x10DFF140,
    SUBDEVICE_10DFF141 = 0x10DFF141
};



inline const char8* enumToString(PciSubDevice10DFF100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFF100::NONE:               return "NONE";
        case PciSubDevice10DFF100::SUBDEVICE_1014038A: return "SUBDEVICE_1014038A";
        case PciSubDevice10DFF100::SUBDEVICE_103C3282: return "SUBDEVICE_103C3282";
        case PciSubDevice10DFF100::SUBDEVICE_10DFF140: return "SUBDEVICE_10DFF140";
        case PciSubDevice10DFF100::SUBDEVICE_10DFF141: return "SUBDEVICE_10DFF141";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DFF100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DFF100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFF100::SUBDEVICE_1014038A: return "8Gb PCI Express Dual Port FC Adapter for POWER";
        case PciSubDevice10DFF100::SUBDEVICE_103C3282: return "8Gb Dual-port PCI-e FC HBA";
        case PciSubDevice10DFF100::SUBDEVICE_10DFF140: return "LPe12000-M8-L 1-Port 8Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFF100::SUBDEVICE_10DFF141: return "LPe12002-M8-L 2-Port 8Gb PCIe Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF100_H
