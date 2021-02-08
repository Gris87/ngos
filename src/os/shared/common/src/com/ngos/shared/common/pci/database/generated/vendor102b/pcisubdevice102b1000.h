// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B1000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B1000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B1000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102BFF01 = 0x102BFF01,
    SUBDEVICE_102BFF05 = 0x102BFF05
};



inline const char8* enumToString(PciSubDevice102B1000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B1000::NONE:               return "NONE";
        case PciSubDevice102B1000::SUBDEVICE_102BFF01: return "SUBDEVICE_102BFF01";
        case PciSubDevice102B1000::SUBDEVICE_102BFF05: return "SUBDEVICE_102BFF05";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B1000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B1000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B1000::SUBDEVICE_102BFF01: return "Productiva G100";
        case PciSubDevice102B1000::SUBDEVICE_102BFF05: return "Productiva G100 Multi-Monitor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B1000_H
