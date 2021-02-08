// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCISUBDEVICE104A0500_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCISUBDEVICE104A0500_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104A0500: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104A0500 = 0x104A0500
};



inline const char8* enumToString(PciSubDevice104A0500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104A0500::NONE:               return "NONE";
        case PciSubDevice104A0500::SUBDEVICE_104A0500: return "SUBDEVICE_104A0500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104A0500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104A0500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104A0500::SUBDEVICE_104A0500: return "BeWAN ADSL PCI st";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCISUBDEVICE104A0500_H
