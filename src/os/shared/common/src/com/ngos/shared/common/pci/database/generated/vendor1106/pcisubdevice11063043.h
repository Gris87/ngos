// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063043_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063043_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063043: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10BD0000 = 0x10BD0000,
    SUBDEVICE_11060100 = 0x11060100,
    SUBDEVICE_11861400 = 0x11861400
};



inline const char8* enumToString(PciSubDevice11063043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063043::NONE:               return "NONE";
        case PciSubDevice11063043::SUBDEVICE_10BD0000: return "SUBDEVICE_10BD0000";
        case PciSubDevice11063043::SUBDEVICE_11060100: return "SUBDEVICE_11060100";
        case PciSubDevice11063043::SUBDEVICE_11861400: return "SUBDEVICE_11861400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063043::SUBDEVICE_10BD0000: return "VT86C100A Fast Ethernet Adapter";
        case PciSubDevice11063043::SUBDEVICE_11060100: return "VT86C100A Fast Ethernet Adapter";
        case PciSubDevice11063043::SUBDEVICE_11861400: return "DFE-530TX PCI Fast Ethernet Adapter (rev. A)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063043_H
