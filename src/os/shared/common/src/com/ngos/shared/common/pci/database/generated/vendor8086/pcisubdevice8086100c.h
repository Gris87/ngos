// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086100C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861112 = 0x80861112,
    SUBDEVICE_80862112 = 0x80862112
};



inline const char8* enumToString(PciSubDevice8086100C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100C::NONE:               return "NONE";
        case PciSubDevice8086100C::SUBDEVICE_80861112: return "SUBDEVICE_80861112";
        case PciSubDevice8086100C::SUBDEVICE_80862112: return "SUBDEVICE_80862112";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086100C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086100C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100C::SUBDEVICE_80861112: return "PRO/1000 T Desktop Adapter";
        case PciSubDevice8086100C::SUBDEVICE_80862112: return "PRO/1000 T Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100C_H
