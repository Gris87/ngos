// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C15901_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C15901_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C15901: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11C15900 = 0x11C15900,
    SUBDEVICE_14430643 = 0x14430643,
    SUBDEVICE_15460643 = 0x15460643
};



inline const char8* enumToString(PciSubDevice11C15901 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C15901::NONE:               return "NONE";
        case PciSubDevice11C15901::SUBDEVICE_11C15900: return "SUBDEVICE_11C15900";
        case PciSubDevice11C15901::SUBDEVICE_14430643: return "SUBDEVICE_14430643";
        case PciSubDevice11C15901::SUBDEVICE_15460643: return "SUBDEVICE_15460643";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C15901 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C15901 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C15901::SUBDEVICE_11C15900: return "FW643 [TrueFire] PCIe 1394b Controller";
        case PciSubDevice11C15901::SUBDEVICE_14430643: return "FireBoard800-e V.2";
        case PciSubDevice11C15901::SUBDEVICE_15460643: return "FWB-PCIE1X2x";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C15901_H
