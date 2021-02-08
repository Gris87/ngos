// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FE3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FE3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0FE3: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2B16 = 0x103C2B16,
    SUBDEVICE_17AA3675 = 0x17AA3675
};



inline const char8* enumToString(PciSubDevice10DE0FE3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0FE3::NONE:               return "NONE";
        case PciSubDevice10DE0FE3::SUBDEVICE_103C2B16: return "SUBDEVICE_103C2B16";
        case PciSubDevice10DE0FE3::SUBDEVICE_17AA3675: return "SUBDEVICE_17AA3675";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0FE3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0FE3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0FE3::SUBDEVICE_103C2B16: return "GeForce GT 745A";
        case PciSubDevice10DE0FE3::SUBDEVICE_17AA3675: return "GeForce GT 745A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FE3_H
