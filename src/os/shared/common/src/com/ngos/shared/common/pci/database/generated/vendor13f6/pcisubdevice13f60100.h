// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13F60100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13F6FFFF = 0x13F6FFFF
};



inline const char8* enumToString(PciSubDevice13F60100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F60100::NONE:               return "NONE";
        case PciSubDevice13F60100::SUBDEVICE_13F6FFFF: return "SUBDEVICE_13F6FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13F60100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13F60100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F60100::SUBDEVICE_13F6FFFF: return "CMi8338/C3DX PCI Audio Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60100_H
