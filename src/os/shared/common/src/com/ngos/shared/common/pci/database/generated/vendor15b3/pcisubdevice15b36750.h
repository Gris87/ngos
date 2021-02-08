// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B36750_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B36750_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B36750: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140416 = 0x10140416,
    SUBDEVICE_10140461 = 0x10140461,
    SUBDEVICE_15B30018 = 0x15B30018,
    SUBDEVICE_15B36572 = 0x15B36572
};



inline const char8* enumToString(PciSubDevice15B36750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B36750::NONE:               return "NONE";
        case PciSubDevice15B36750::SUBDEVICE_10140416: return "SUBDEVICE_10140416";
        case PciSubDevice15B36750::SUBDEVICE_10140461: return "SUBDEVICE_10140461";
        case PciSubDevice15B36750::SUBDEVICE_15B30018: return "SUBDEVICE_15B30018";
        case PciSubDevice15B36750::SUBDEVICE_15B36572: return "SUBDEVICE_15B36572";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B36750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B36750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B36750::SUBDEVICE_10140416: return "PCIe2 2-Port 10GbE RoCE SFP+ Adapter";
        case PciSubDevice15B36750::SUBDEVICE_10140461: return "PCIe2 2-Port 10GbE RoCE SR Adapter";
        case PciSubDevice15B36750::SUBDEVICE_15B30018: return "HP 10 GbE PCI-e G2 Dual-Port NIC (rev C1)";
        case PciSubDevice15B36750::SUBDEVICE_15B36572: return "IBM Flex System EN4132 2-port 10Gb RoCE Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B36750_H
