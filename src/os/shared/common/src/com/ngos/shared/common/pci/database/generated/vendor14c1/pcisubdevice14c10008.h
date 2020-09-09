// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCISUBDEVICE14C10008_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCISUBDEVICE14C10008_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14C10008: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14C10008 = 0x14C10008,
    SUBDEVICE_14C10009 = 0x14C10009,
    SUBDEVICE_14C1000A = 0x14C1000A
};



inline const char8* enumToString(PciSubDevice14C10008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14C10008::NONE:               return "NONE";
        case PciSubDevice14C10008::SUBDEVICE_14C10008: return "SUBDEVICE_14C10008";
        case PciSubDevice14C10008::SUBDEVICE_14C10009: return "SUBDEVICE_14C10009";
        case PciSubDevice14C10008::SUBDEVICE_14C1000A: return "SUBDEVICE_14C1000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14C10008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14C10008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14C10008::SUBDEVICE_14C10008: return "10G-PCIE-8A";
        case PciSubDevice14C10008::SUBDEVICE_14C10009: return "10G-PCIE-8A (MSI-X firmware)";
        case PciSubDevice14C10008::SUBDEVICE_14C1000A: return "10G-PCIE-8B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCISUBDEVICE14C10008_H
