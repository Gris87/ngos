// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863EC2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863EC2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863EC2: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280869 = 0x10280869,
    SUBDEVICE_10438694 = 0x10438694
};



inline const char8* enumToString(PciSubDevice80863EC2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863EC2::NONE:               return "NONE";
        case PciSubDevice80863EC2::SUBDEVICE_10280869: return "SUBDEVICE_10280869";
        case PciSubDevice80863EC2::SUBDEVICE_10438694: return "SUBDEVICE_10438694";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863EC2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863EC2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863EC2::SUBDEVICE_10280869: return "Vostro 3470";
        case PciSubDevice80863EC2::SUBDEVICE_10438694: return "PRIME H310M-D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863EC2_H
