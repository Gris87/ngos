// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086254C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086254C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086254C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C531090 = 0x4C531090,
    SUBDEVICE_80863424 = 0x80863424
};



inline const char8* enumToString(PciSubDevice8086254C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086254C::NONE:               return "NONE";
        case PciSubDevice8086254C::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";
        case PciSubDevice8086254C::SUBDEVICE_80863424: return "SUBDEVICE_80863424";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086254C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086254C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086254C::SUBDEVICE_4C531090: return "Cx9 / Vx9 mainboard";
        case PciSubDevice8086254C::SUBDEVICE_80863424: return "SE7501HG2 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086254C_H
