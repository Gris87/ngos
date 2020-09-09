// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44359_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44359_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44359: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280011 = 0x10280011,
    SUBDEVICE_103C182C = 0x103C182C
};



inline const char8* enumToString(PciSubDevice14E44359 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44359::NONE:               return "NONE";
        case PciSubDevice14E44359::SUBDEVICE_10280011: return "SUBDEVICE_10280011";
        case PciSubDevice14E44359::SUBDEVICE_103C182C: return "SUBDEVICE_103C182C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44359 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44359 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44359::SUBDEVICE_10280011: return "Wireless 1530 Half-size Mini PCIe Card";
        case PciSubDevice14E44359::SUBDEVICE_103C182C: return "BCM943228HM4L 802.11a/b/g/n 2x2 Wi-Fi Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44359_H
