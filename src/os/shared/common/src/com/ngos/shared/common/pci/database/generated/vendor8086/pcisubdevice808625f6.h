// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808625F6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808625F6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808625F6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C31FD = 0x103C31FD,
    SUBDEVICE_15D98680 = 0x15D98680,
    SUBDEVICE_15D99680 = 0x15D99680,
    SUBDEVICE_80863476 = 0x80863476
};



inline const char8* enumToString(PciSubDevice808625F6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808625F6::NONE:               return "NONE";
        case PciSubDevice808625F6::SUBDEVICE_103C31FD: return "SUBDEVICE_103C31FD";
        case PciSubDevice808625F6::SUBDEVICE_15D98680: return "SUBDEVICE_15D98680";
        case PciSubDevice808625F6::SUBDEVICE_15D99680: return "SUBDEVICE_15D99680";
        case PciSubDevice808625F6::SUBDEVICE_80863476: return "SUBDEVICE_80863476";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808625F6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808625F6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808625F6::SUBDEVICE_103C31FD: return "ProLiant DL140 G3";
        case PciSubDevice808625F6::SUBDEVICE_15D98680: return "X7DVL-E-O motherboard";
        case PciSubDevice808625F6::SUBDEVICE_15D99680: return "X7DBN Motherboard";
        case PciSubDevice808625F6::SUBDEVICE_80863476: return "S5000PSLSATA Server Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808625F6_H
