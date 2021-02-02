// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100002B0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100002B0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100002B0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1D490001 = 0x1D490001,
    SUBDEVICE_1D490002 = 0x1D490002
};



inline const char8* enumToString(PciSubDevice100002B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100002B0::NONE:               return "NONE";
        case PciSubDevice100002B0::SUBDEVICE_1D490001: return "SUBDEVICE_1D490001";
        case PciSubDevice100002B0::SUBDEVICE_1D490002: return "SUBDEVICE_1D490002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100002B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100002B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100002B0::SUBDEVICE_1D490001: return "ThinkSystem 1610-4P NVMe Switch Adapter";
        case PciSubDevice100002B0::SUBDEVICE_1D490002: return "ThinkSystem 810-4P NVMe Switch Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100002B0_H
