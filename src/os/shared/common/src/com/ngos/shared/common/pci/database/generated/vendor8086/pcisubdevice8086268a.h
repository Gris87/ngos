// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086268A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086268A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086268A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801F0 = 0x102801F0,
    SUBDEVICE_103C31FE = 0x103C31FE,
    SUBDEVICE_15D98680 = 0x15D98680,
    SUBDEVICE_15D99680 = 0x15D99680,
    SUBDEVICE_80863476 = 0x80863476
};



inline const char8* enumToString(PciSubDevice8086268A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086268A::NONE:               return "NONE";
        case PciSubDevice8086268A::SUBDEVICE_102801F0: return "SUBDEVICE_102801F0";
        case PciSubDevice8086268A::SUBDEVICE_103C31FE: return "SUBDEVICE_103C31FE";
        case PciSubDevice8086268A::SUBDEVICE_15D98680: return "SUBDEVICE_15D98680";
        case PciSubDevice8086268A::SUBDEVICE_15D99680: return "SUBDEVICE_15D99680";
        case PciSubDevice8086268A::SUBDEVICE_80863476: return "SUBDEVICE_80863476";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086268A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086268A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086268A::SUBDEVICE_102801F0: return "PowerEdge R900 onboard USB";
        case PciSubDevice8086268A::SUBDEVICE_103C31FE: return "ProLiant DL140 G3";
        case PciSubDevice8086268A::SUBDEVICE_15D98680: return "X7DVL-E-O motherboard";
        case PciSubDevice8086268A::SUBDEVICE_15D99680: return "X7DBN Motherboard";
        case PciSubDevice8086268A::SUBDEVICE_80863476: return "S5000PSLSATA Server Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086268A_H
