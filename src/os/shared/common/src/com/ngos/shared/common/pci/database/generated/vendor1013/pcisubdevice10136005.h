// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10136005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10134281 = 0x10134281,
    SUBDEVICE_10CF10A8 = 0x10CF10A8,
    SUBDEVICE_10CF10A9 = 0x10CF10A9,
    SUBDEVICE_10CF10AA = 0x10CF10AA,
    SUBDEVICE_10CF10AB = 0x10CF10AB,
    SUBDEVICE_10CF10AC = 0x10CF10AC,
    SUBDEVICE_10CF10AD = 0x10CF10AD,
    SUBDEVICE_10CF10B4 = 0x10CF10B4,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_14C0000C = 0x14C0000C
};



inline const char8* enumToString(PciSubDevice10136005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10136005::NONE:               return "NONE";
        case PciSubDevice10136005::SUBDEVICE_10134281: return "SUBDEVICE_10134281";
        case PciSubDevice10136005::SUBDEVICE_10CF10A8: return "SUBDEVICE_10CF10A8";
        case PciSubDevice10136005::SUBDEVICE_10CF10A9: return "SUBDEVICE_10CF10A9";
        case PciSubDevice10136005::SUBDEVICE_10CF10AA: return "SUBDEVICE_10CF10AA";
        case PciSubDevice10136005::SUBDEVICE_10CF10AB: return "SUBDEVICE_10CF10AB";
        case PciSubDevice10136005::SUBDEVICE_10CF10AC: return "SUBDEVICE_10CF10AC";
        case PciSubDevice10136005::SUBDEVICE_10CF10AD: return "SUBDEVICE_10CF10AD";
        case PciSubDevice10136005::SUBDEVICE_10CF10B4: return "SUBDEVICE_10CF10B4";
        case PciSubDevice10136005::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice10136005::SUBDEVICE_14C0000C: return "SUBDEVICE_14C0000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10136005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10136005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10136005::SUBDEVICE_10134281: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10A8: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10A9: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10AA: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10AB: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10AC: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10AD: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_10CF10B4: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_11790001: return "Crystal CS4281 PCI Audio";
        case PciSubDevice10136005::SUBDEVICE_14C0000C: return "Crystal CS4281 PCI Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136005_H
