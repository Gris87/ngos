// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B1001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B1001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B1001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B1001 = 0x102B1001,
    SUBDEVICE_102BFF00 = 0x102BFF00,
    SUBDEVICE_102BFF01 = 0x102BFF01,
    SUBDEVICE_102BFF03 = 0x102BFF03,
    SUBDEVICE_102BFF04 = 0x102BFF04,
    SUBDEVICE_102BFF05 = 0x102BFF05,
    SUBDEVICE_110A001E = 0x110A001E
};



inline const char8* enumToString(PciSubDevice102B1001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B1001::NONE:               return "NONE";
        case PciSubDevice102B1001::SUBDEVICE_102B1001: return "SUBDEVICE_102B1001";
        case PciSubDevice102B1001::SUBDEVICE_102BFF00: return "SUBDEVICE_102BFF00";
        case PciSubDevice102B1001::SUBDEVICE_102BFF01: return "SUBDEVICE_102BFF01";
        case PciSubDevice102B1001::SUBDEVICE_102BFF03: return "SUBDEVICE_102BFF03";
        case PciSubDevice102B1001::SUBDEVICE_102BFF04: return "SUBDEVICE_102BFF04";
        case PciSubDevice102B1001::SUBDEVICE_102BFF05: return "SUBDEVICE_102BFF05";
        case PciSubDevice102B1001::SUBDEVICE_110A001E: return "SUBDEVICE_110A001E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B1001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B1001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B1001::SUBDEVICE_102B1001: return "MGA-G100 AGP";
        case PciSubDevice102B1001::SUBDEVICE_102BFF00: return "MGA-G100 AGP";
        case PciSubDevice102B1001::SUBDEVICE_102BFF01: return "MGA-G100 Productiva AGP";
        case PciSubDevice102B1001::SUBDEVICE_102BFF03: return "Millennium G100 AGP";
        case PciSubDevice102B1001::SUBDEVICE_102BFF04: return "MGA-G100 AGP";
        case PciSubDevice102B1001::SUBDEVICE_102BFF05: return "MGA-G100 Productiva AGP Multi-Monitor";
        case PciSubDevice102B1001::SUBDEVICE_110A001E: return "MGA-G100 AGP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B1001_H
