// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086107A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C12A8 = 0x103C12A8,
    SUBDEVICE_8086107A = 0x8086107A,
    SUBDEVICE_8086127A = 0x8086127A
};



inline const char8* enumToString(PciSubDevice8086107A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107A::NONE:               return "NONE";
        case PciSubDevice8086107A::SUBDEVICE_103C12A8: return "SUBDEVICE_103C12A8";
        case PciSubDevice8086107A::SUBDEVICE_8086107A: return "SUBDEVICE_8086107A";
        case PciSubDevice8086107A::SUBDEVICE_8086127A: return "SUBDEVICE_8086127A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086107A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086107A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107A::SUBDEVICE_103C12A8: return "Dual Port 1000base-SX [A9899A]";
        case PciSubDevice8086107A::SUBDEVICE_8086107A: return "PRO/1000 MF Dual Port Server Adapter";
        case PciSubDevice8086107A::SUBDEVICE_8086127A: return "PRO/1000 MF Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107A_H
