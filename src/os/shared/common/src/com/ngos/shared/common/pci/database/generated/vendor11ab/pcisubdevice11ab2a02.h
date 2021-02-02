// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB2A02_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB2A02_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB2A02: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07D13B02 = 0x07D13B02,
    SUBDEVICE_13857C00 = 0x13857C00,
    SUBDEVICE_13857C01 = 0x13857C01,
    SUBDEVICE_13857E00 = 0x13857E00,
    SUBDEVICE_1799801B = 0x1799801B
};



inline const char8* enumToString(PciSubDevice11AB2A02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB2A02::NONE:               return "NONE";
        case PciSubDevice11AB2A02::SUBDEVICE_07D13B02: return "SUBDEVICE_07D13B02";
        case PciSubDevice11AB2A02::SUBDEVICE_13857C00: return "SUBDEVICE_13857C00";
        case PciSubDevice11AB2A02::SUBDEVICE_13857C01: return "SUBDEVICE_13857C01";
        case PciSubDevice11AB2A02::SUBDEVICE_13857E00: return "SUBDEVICE_13857E00";
        case PciSubDevice11AB2A02::SUBDEVICE_1799801B: return "SUBDEVICE_1799801B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB2A02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB2A02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB2A02::SUBDEVICE_07D13B02: return "DIR-615 rev. A1 Mini PCI Wireless Module";
        case PciSubDevice11AB2A02::SUBDEVICE_13857C00: return "WN511T RangeMax Next 300 Mbps Wireless PC Card";
        case PciSubDevice11AB2A02::SUBDEVICE_13857C01: return "WN511T RangeMax Next 300 Mbps Wireless Notebook Adapter";
        case PciSubDevice11AB2A02::SUBDEVICE_13857E00: return "WN311T RangeMax Next 300 Mbps Wireless PCI Adapter";
        case PciSubDevice11AB2A02::SUBDEVICE_1799801B: return "F5D8011 v2 802.11n N1 Wireless Notebook Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB2A02_H
