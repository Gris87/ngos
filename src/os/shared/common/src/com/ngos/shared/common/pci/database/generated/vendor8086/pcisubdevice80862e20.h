// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862E20_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862E20_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862E20: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280283 = 0x10280283,
    SUBDEVICE_104382D3 = 0x104382D3,
    SUBDEVICE_14585000 = 0x14585000
};



inline const char8* enumToString(PciSubDevice80862E20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862E20::NONE:               return "NONE";
        case PciSubDevice80862E20::SUBDEVICE_10280283: return "SUBDEVICE_10280283";
        case PciSubDevice80862E20::SUBDEVICE_104382D3: return "SUBDEVICE_104382D3";
        case PciSubDevice80862E20::SUBDEVICE_14585000: return "SUBDEVICE_14585000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862E20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862E20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862E20::SUBDEVICE_10280283: return "Vostro 220";
        case PciSubDevice80862E20::SUBDEVICE_104382D3: return "P5Q Deluxe Motherboard";
        case PciSubDevice80862E20::SUBDEVICE_14585000: return "GA-EP45-DS5/GA-EG45M-DS2H Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862E20_H
