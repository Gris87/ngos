// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A3E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A3E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A3E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438311 = 0x10438311,
    SUBDEVICE_1458A002 = 0x1458A002,
    SUBDEVICE_1458A102 = 0x1458A102
};



inline const char8* enumToString(PciSubDevice80863A3E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A3E::NONE:               return "NONE";
        case PciSubDevice80863A3E::SUBDEVICE_10438311: return "SUBDEVICE_10438311";
        case PciSubDevice80863A3E::SUBDEVICE_1458A002: return "SUBDEVICE_1458A002";
        case PciSubDevice80863A3E::SUBDEVICE_1458A102: return "SUBDEVICE_1458A102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A3E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A3E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A3E::SUBDEVICE_10438311: return "P5Q Deluxe Motherboard";
        case PciSubDevice80863A3E::SUBDEVICE_1458A002: return "GA-EP45-UD3R Motherboard";
        case PciSubDevice80863A3E::SUBDEVICE_1458A102: return "GA-EP45-DS5/GA-EG45M-DS2H Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A3E_H
