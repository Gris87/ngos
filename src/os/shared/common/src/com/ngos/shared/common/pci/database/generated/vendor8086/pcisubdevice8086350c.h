// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086350C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086350C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086350C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C31FE = 0x103C31FE,
    SUBDEVICE_15D99680 = 0x15D99680
};



inline const char8* enumToString(PciSubDevice8086350C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086350C::NONE:               return "NONE";
        case PciSubDevice8086350C::SUBDEVICE_103C31FE: return "SUBDEVICE_103C31FE";
        case PciSubDevice8086350C::SUBDEVICE_15D99680: return "SUBDEVICE_15D99680";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086350C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086350C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086350C::SUBDEVICE_103C31FE: return "ProLiant DL140 G3";
        case PciSubDevice8086350C::SUBDEVICE_15D99680: return "X7DBN Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086350C_H
