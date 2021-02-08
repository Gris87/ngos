// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086A001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1458D000 = 0x1458D000,
    SUBDEVICE_80864F4D = 0x80864F4D,
    SUBDEVICE_8086544B = 0x8086544B
};



inline const char8* enumToString(PciSubDevice8086A001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086A001::NONE:               return "NONE";
        case PciSubDevice8086A001::SUBDEVICE_1458D000: return "SUBDEVICE_1458D000";
        case PciSubDevice8086A001::SUBDEVICE_80864F4D: return "SUBDEVICE_80864F4D";
        case PciSubDevice8086A001::SUBDEVICE_8086544B: return "SUBDEVICE_8086544B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086A001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086A001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086A001::SUBDEVICE_1458D000: return "GA-D525TUD";
        case PciSubDevice8086A001::SUBDEVICE_80864F4D: return "DeskTop Board D510MO";
        case PciSubDevice8086A001::SUBDEVICE_8086544B: return "Desktop Board D425KT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A001_H
