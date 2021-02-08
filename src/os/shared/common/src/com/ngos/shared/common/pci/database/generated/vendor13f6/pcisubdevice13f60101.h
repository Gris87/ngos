// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13F60101: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13F60101 = 0x13F60101
};



inline const char8* enumToString(PciSubDevice13F60101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F60101::NONE:               return "NONE";
        case PciSubDevice13F60101::SUBDEVICE_13F60101: return "SUBDEVICE_13F60101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13F60101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13F60101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F60101::SUBDEVICE_13F60101: return "CMi8338-031 PCI Audio Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60101_H
