// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610C8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086A10C = 0x8086A10C,
    SUBDEVICE_8086A11C = 0x8086A11C,
    SUBDEVICE_8086A12C = 0x8086A12C
};



inline const char8* enumToString(PciSubDevice808610C8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C8::NONE:               return "NONE";
        case PciSubDevice808610C8::SUBDEVICE_8086A10C: return "SUBDEVICE_8086A10C";
        case PciSubDevice808610C8::SUBDEVICE_8086A11C: return "SUBDEVICE_8086A11C";
        case PciSubDevice808610C8::SUBDEVICE_8086A12C: return "SUBDEVICE_8086A12C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610C8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610C8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C8::SUBDEVICE_8086A10C: return "10-Gigabit AT Server Adapter";
        case PciSubDevice808610C8::SUBDEVICE_8086A11C: return "10-Gigabit AT Server Adapter";
        case PciSubDevice808610C8::SUBDEVICE_8086A12C: return "10-Gigabit AT Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C8_H
