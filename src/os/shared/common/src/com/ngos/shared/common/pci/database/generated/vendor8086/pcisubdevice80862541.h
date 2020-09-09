// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862541_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862541_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862541: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15D93480 = 0x15D93480,
    SUBDEVICE_4C531090 = 0x4C531090,
    SUBDEVICE_80863424 = 0x80863424
};



inline const char8* enumToString(PciSubDevice80862541 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862541::NONE:               return "NONE";
        case PciSubDevice80862541::SUBDEVICE_15D93480: return "SUBDEVICE_15D93480";
        case PciSubDevice80862541::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";
        case PciSubDevice80862541::SUBDEVICE_80863424: return "SUBDEVICE_80863424";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862541 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862541 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862541::SUBDEVICE_15D93480: return "P4DP6";
        case PciSubDevice80862541::SUBDEVICE_4C531090: return "Cx9 / Vx9 mainboard";
        case PciSubDevice80862541::SUBDEVICE_80863424: return "SE7501HG2 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862541_H
