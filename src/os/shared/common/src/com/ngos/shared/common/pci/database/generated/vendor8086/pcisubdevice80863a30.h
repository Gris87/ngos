// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A30: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104382D4 = 0x104382D4,
    SUBDEVICE_14585001 = 0x14585001
};



inline const char8* enumToString(PciSubDevice80863A30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A30::NONE:               return "NONE";
        case PciSubDevice80863A30::SUBDEVICE_104382D4: return "SUBDEVICE_104382D4";
        case PciSubDevice80863A30::SUBDEVICE_14585001: return "SUBDEVICE_14585001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A30::SUBDEVICE_104382D4: return "P5Q Deluxe Motherboard";
        case PciSubDevice80863A30::SUBDEVICE_14585001: return "GA-EP45-DS5/GA-EG45M-DS2H Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A30_H
