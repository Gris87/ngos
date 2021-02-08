// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C0C30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C0C30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102C0C30: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C531000 = 0x4C531000,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051,
    SUBDEVICE_4C531080 = 0x4C531080
};



inline const char8* enumToString(PciSubDevice102C0C30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102C0C30::NONE:               return "NONE";
        case PciSubDevice102C0C30::SUBDEVICE_4C531000: return "SUBDEVICE_4C531000";
        case PciSubDevice102C0C30::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice102C0C30::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";
        case PciSubDevice102C0C30::SUBDEVICE_4C531080: return "SUBDEVICE_4C531080";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102C0C30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102C0C30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102C0C30::SUBDEVICE_4C531000: return "CC7/CR7/CP7/VC7/VP7/VR7 mainboard";
        case PciSubDevice102C0C30::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice102C0C30::SUBDEVICE_4C531051: return "CE7 mainboard";
        case PciSubDevice102C0C30::SUBDEVICE_4C531080: return "CT8 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C0C30_H
