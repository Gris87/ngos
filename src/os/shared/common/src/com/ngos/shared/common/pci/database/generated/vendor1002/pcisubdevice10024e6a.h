// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E6A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E6A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024E6A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10024E6A = 0x10024E6A,
    SUBDEVICE_10024E71 = 0x10024E71
};



inline const char8* enumToString(PciSubDevice10024E6A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E6A::NONE:               return "NONE";
        case PciSubDevice10024E6A::SUBDEVICE_10024E6A: return "SUBDEVICE_10024E6A";
        case PciSubDevice10024E6A::SUBDEVICE_10024E71: return "SUBDEVICE_10024E71";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024E6A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024E6A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E6A::SUBDEVICE_10024E6A: return "R360 [Radeon 9800 XT] (Secondary)";
        case PciSubDevice10024E6A::SUBDEVICE_10024E71: return "M10 NQ [Radeon Mobility 9600]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E6A_H
