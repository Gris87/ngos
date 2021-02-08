// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024336_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024336_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024336: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10024336 = 0x10024336,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_161F2029 = 0x161F2029
};



inline const char8* enumToString(PciSubDevice10024336 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024336::NONE:               return "NONE";
        case PciSubDevice10024336::SUBDEVICE_10024336: return "SUBDEVICE_10024336";
        case PciSubDevice10024336::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice10024336::SUBDEVICE_161F2029: return "SUBDEVICE_161F2029";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024336 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024336 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024336::SUBDEVICE_10024336: return "Pavilion ze4300 ATI Radeon Mobility U1 (IGP 320 M)";
        case PciSubDevice10024336::SUBDEVICE_103C0024: return "Pavilion ze4400 builtin Video";
        case PciSubDevice10024336::SUBDEVICE_161F2029: return "eMachines M5312 builtin Video";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024336_H
