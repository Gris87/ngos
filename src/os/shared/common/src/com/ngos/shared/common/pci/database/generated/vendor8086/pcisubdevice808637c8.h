// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637C8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637C8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808637C8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002
};



inline const char8* enumToString(PciSubDevice808637C8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637C8::NONE:               return "NONE";
        case PciSubDevice808637C8::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice808637C8::SUBDEVICE_80860002: return "SUBDEVICE_80860002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808637C8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808637C8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637C8::SUBDEVICE_80860001: return "QuickAssist Adapter 8960";
        case PciSubDevice808637C8::SUBDEVICE_80860002: return "QuickAssist Adapter 8970";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637C8_H
