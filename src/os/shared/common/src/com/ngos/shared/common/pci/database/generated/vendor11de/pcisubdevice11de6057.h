// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCISUBDEVICE11DE6057_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCISUBDEVICE11DE6057_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11DE6057: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10317EFE = 0x10317EFE,
    SUBDEVICE_1031FC00 = 0x1031FC00,
    SUBDEVICE_12F88A02 = 0x12F88A02,
    SUBDEVICE_13CA4231 = 0x13CA4231
};



inline const char8* enumToString(PciSubDevice11DE6057 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11DE6057::NONE:               return "NONE";
        case PciSubDevice11DE6057::SUBDEVICE_10317EFE: return "SUBDEVICE_10317EFE";
        case PciSubDevice11DE6057::SUBDEVICE_1031FC00: return "SUBDEVICE_1031FC00";
        case PciSubDevice11DE6057::SUBDEVICE_12F88A02: return "SUBDEVICE_12F88A02";
        case PciSubDevice11DE6057::SUBDEVICE_13CA4231: return "SUBDEVICE_13CA4231";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11DE6057 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11DE6057 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11DE6057::SUBDEVICE_10317EFE: return "DC10 Plus";
        case PciSubDevice11DE6057::SUBDEVICE_1031FC00: return "MiroVIDEO DC50, Motion JPEG Capture/CODEC Board";
        case PciSubDevice11DE6057::SUBDEVICE_12F88A02: return "Tekram Video Kit";
        case PciSubDevice11DE6057::SUBDEVICE_13CA4231: return "JPEG/TV Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCISUBDEVICE11DE6057_H
