// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE105A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE105A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE105A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10432111 = 0x10432111,
    SUBDEVICE_10432112 = 0x10432112
};



inline const char8* enumToString(PciSubDevice10DE105A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE105A::NONE:               return "NONE";
        case PciSubDevice10DE105A::SUBDEVICE_10432111: return "SUBDEVICE_10432111";
        case PciSubDevice10DE105A::SUBDEVICE_10432112: return "SUBDEVICE_10432112";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE105A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE105A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE105A::SUBDEVICE_10432111: return "GeForce GT 610M";
        case PciSubDevice10DE105A::SUBDEVICE_10432112: return "GeForce GT 610M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE105A_H
