// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772281_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772281_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772281: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107702E2 = 0x107702E2,
    SUBDEVICE_107702E4 = 0x107702E4,
    SUBDEVICE_107702EE = 0x107702EE,
    SUBDEVICE_107702F0 = 0x107702F0,
    SUBDEVICE_107702F2 = 0x107702F2,
    SUBDEVICE_107702F3 = 0x107702F3,
    SUBDEVICE_159002D3 = 0x159002D3,
    SUBDEVICE_159002D4 = 0x159002D4
};



inline const char8* enumToString(PciSubDevice10772281 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772281::NONE:               return "NONE";
        case PciSubDevice10772281::SUBDEVICE_107702E2: return "SUBDEVICE_107702E2";
        case PciSubDevice10772281::SUBDEVICE_107702E4: return "SUBDEVICE_107702E4";
        case PciSubDevice10772281::SUBDEVICE_107702EE: return "SUBDEVICE_107702EE";
        case PciSubDevice10772281::SUBDEVICE_107702F0: return "SUBDEVICE_107702F0";
        case PciSubDevice10772281::SUBDEVICE_107702F2: return "SUBDEVICE_107702F2";
        case PciSubDevice10772281::SUBDEVICE_107702F3: return "SUBDEVICE_107702F3";
        case PciSubDevice10772281::SUBDEVICE_159002D3: return "SUBDEVICE_159002D3";
        case PciSubDevice10772281::SUBDEVICE_159002D4: return "SUBDEVICE_159002D4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772281 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772281 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772281::SUBDEVICE_107702E2: return "QLE2872 Dual Port 64GFC PCIe Gen4 x8 Adapter";
        case PciSubDevice10772281::SUBDEVICE_107702E4: return "QLE2772 Dual Port 32GFC PCIe Gen4 x8 Adapter";
        case PciSubDevice10772281::SUBDEVICE_107702EE: return "QLE2870 Single Port 64GFC PCIe Gen4 x8 Adapter";
        case PciSubDevice10772281::SUBDEVICE_107702F0: return "QLE2770 Single Port 32GFC PCIe Gen4 x8 Adapter";
        case PciSubDevice10772281::SUBDEVICE_107702F2: return "QLogic 1x32Gb QLE2770 FC HBA";
        case PciSubDevice10772281::SUBDEVICE_107702F3: return "QLogic 2x32Gb QLE2772 FC HBA";
        case PciSubDevice10772281::SUBDEVICE_159002D3: return "SN1610Q - 1P Enhanced 32GFC Single Port Fibre Channel Host Bus Adapter";
        case PciSubDevice10772281::SUBDEVICE_159002D4: return "SN1610Q – 2P Enhanced 32GFC Dual Port Fibre Channel Host Bus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772281_H
