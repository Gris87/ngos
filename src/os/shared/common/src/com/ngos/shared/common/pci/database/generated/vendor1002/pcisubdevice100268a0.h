// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268A0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102812EF = 0x102812EF,
    SUBDEVICE_103C1520 = 0x103C1520
};



inline const char8* enumToString(PciSubDevice100268A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268A0::NONE:               return "NONE";
        case PciSubDevice100268A0::SUBDEVICE_102812EF: return "SUBDEVICE_102812EF";
        case PciSubDevice100268A0::SUBDEVICE_103C1520: return "SUBDEVICE_103C1520";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268A0::SUBDEVICE_102812EF: return "FirePro M7820";
        case PciSubDevice100268A0::SUBDEVICE_103C1520: return "FirePro M7820";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A0_H
