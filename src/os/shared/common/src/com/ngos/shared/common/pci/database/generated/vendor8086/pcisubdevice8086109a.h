// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086109A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086109A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086109A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1179FF10 = 0x1179FF10,
    SUBDEVICE_17AA2001 = 0x17AA2001,
    SUBDEVICE_17AA207E = 0x17AA207E,
    SUBDEVICE_8086109A = 0x8086109A,
    SUBDEVICE_8086309C = 0x8086309C,
    SUBDEVICE_808630A5 = 0x808630A5
};



inline const char8* enumToString(PciSubDevice8086109A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086109A::NONE:               return "NONE";
        case PciSubDevice8086109A::SUBDEVICE_1179FF10: return "SUBDEVICE_1179FF10";
        case PciSubDevice8086109A::SUBDEVICE_17AA2001: return "SUBDEVICE_17AA2001";
        case PciSubDevice8086109A::SUBDEVICE_17AA207E: return "SUBDEVICE_17AA207E";
        case PciSubDevice8086109A::SUBDEVICE_8086109A: return "SUBDEVICE_8086109A";
        case PciSubDevice8086109A::SUBDEVICE_8086309C: return "SUBDEVICE_8086309C";
        case PciSubDevice8086109A::SUBDEVICE_808630A5: return "SUBDEVICE_808630A5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086109A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086109A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086109A::SUBDEVICE_1179FF10: return "PRO/1000 PL";
        case PciSubDevice8086109A::SUBDEVICE_17AA2001: return "ThinkPad T60";
        case PciSubDevice8086109A::SUBDEVICE_17AA207E: return "ThinkPad X60/X60s";
        case PciSubDevice8086109A::SUBDEVICE_8086109A: return "PRO/1000 PL Network Connection";
        case PciSubDevice8086109A::SUBDEVICE_8086309C: return "Desktop Board D945GTP";
        case PciSubDevice8086109A::SUBDEVICE_808630A5: return "Desktop Board D975XBX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086109A_H
