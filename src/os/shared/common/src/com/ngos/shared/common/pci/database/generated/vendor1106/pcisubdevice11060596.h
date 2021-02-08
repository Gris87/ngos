// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060596_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060596_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060596: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11060000 = 0x11060000,
    SUBDEVICE_14580596 = 0x14580596
};



inline const char8* enumToString(PciSubDevice11060596 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060596::NONE:               return "NONE";
        case PciSubDevice11060596::SUBDEVICE_11060000: return "SUBDEVICE_11060000";
        case PciSubDevice11060596::SUBDEVICE_14580596: return "SUBDEVICE_14580596";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060596 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060596 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060596::SUBDEVICE_11060000: return "VT82C596/A/B PCI to ISA Bridge";
        case PciSubDevice11060596::SUBDEVICE_14580596: return "VT82C596/A/B PCI to ISA Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060596_H
