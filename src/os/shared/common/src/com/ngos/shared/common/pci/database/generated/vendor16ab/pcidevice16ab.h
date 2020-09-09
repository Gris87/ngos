// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AB_PCIDEVICE16AB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AB_PCIDEVICE16AB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16AB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100,
    DEVICE_1101 = 0x1101,
    DEVICE_1102 = 0x1102,
    DEVICE_8501 = 0x8501
};



inline const char8* enumToString(PciDevice16AB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16AB::NONE:        return "NONE";
        case PciDevice16AB::DEVICE_1100: return "DEVICE_1100";
        case PciDevice16AB::DEVICE_1101: return "DEVICE_1101";
        case PciDevice16AB::DEVICE_1102: return "DEVICE_1102";
        case PciDevice16AB::DEVICE_8501: return "DEVICE_8501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16AB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16AB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16AB::DEVICE_1100: return "GL24110P";
        case PciDevice16AB::DEVICE_1101: return "PLX9052 PCMCIA-to-PCI Wireless LAN";
        case PciDevice16AB::DEVICE_1102: return "PCMCIA-to-PCI Wireless Network Bridge";
        case PciDevice16AB::DEVICE_8501: return "WL-8305 Wireless LAN PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AB_PCIDEVICE16AB_H
