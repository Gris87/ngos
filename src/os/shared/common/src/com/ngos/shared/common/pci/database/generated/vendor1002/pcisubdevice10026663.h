// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026663_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026663_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026663: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250846 = 0x10250846,
    SUBDEVICE_17AA3805 = 0x17AA3805
};



inline const char8* enumToString(PciSubDevice10026663 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026663::NONE:               return "NONE";
        case PciSubDevice10026663::SUBDEVICE_10250846: return "SUBDEVICE_10250846";
        case PciSubDevice10026663::SUBDEVICE_17AA3805: return "SUBDEVICE_17AA3805";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026663 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026663 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026663::SUBDEVICE_10250846: return "Radeon HD 8570A";
        case PciSubDevice10026663::SUBDEVICE_17AA3805: return "Radeon HD 8570M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026663_H
