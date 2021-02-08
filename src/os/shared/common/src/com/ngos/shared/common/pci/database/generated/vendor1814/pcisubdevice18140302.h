// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140302_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140302_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18140302: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11863A71 = 0x11863A71,
    SUBDEVICE_11863C08 = 0x11863C08,
    SUBDEVICE_11863C09 = 0x11863C09,
    SUBDEVICE_1462B834 = 0x1462B834,
    SUBDEVICE_19483C23 = 0x19483C23,
    SUBDEVICE_19483C24 = 0x19483C24
};



inline const char8* enumToString(PciSubDevice18140302 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140302::NONE:               return "NONE";
        case PciSubDevice18140302::SUBDEVICE_11863A71: return "SUBDEVICE_11863A71";
        case PciSubDevice18140302::SUBDEVICE_11863C08: return "SUBDEVICE_11863C08";
        case PciSubDevice18140302::SUBDEVICE_11863C09: return "SUBDEVICE_11863C09";
        case PciSubDevice18140302::SUBDEVICE_1462B834: return "SUBDEVICE_1462B834";
        case PciSubDevice18140302::SUBDEVICE_19483C23: return "SUBDEVICE_19483C23";
        case PciSubDevice18140302::SUBDEVICE_19483C24: return "SUBDEVICE_19483C24";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18140302 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18140302 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140302::SUBDEVICE_11863A71: return "DWA-510 Wireless G Desktop Adapter";
        case PciSubDevice18140302::SUBDEVICE_11863C08: return "AirPlus G DWL-G630 Wireless Cardbus Adapter (rev.E2)";
        case PciSubDevice18140302::SUBDEVICE_11863C09: return "AirPlus G DWL-G510 Wireless Network Adapter (Rev.C)";
        case PciSubDevice18140302::SUBDEVICE_1462B834: return "PC54G3 Wireless 11g PCI Card";
        case PciSubDevice18140302::SUBDEVICE_19483C23: return "C54RC v2 Wireless 11g CardBus Adapter";
        case PciSubDevice18140302::SUBDEVICE_19483C24: return "C54Ri v2 Wireless 11g PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140302_H
