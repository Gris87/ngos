// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE8088010B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE8088010B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8088010B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80880102 = 0x80880102,
    SUBDEVICE_80884102 = 0x80884102,
    SUBDEVICE_80888102 = 0x80888102,
    SUBDEVICE_8088C102 = 0x8088C102
};



inline const char8* enumToString(PciSubDevice8088010B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8088010B::NONE:               return "NONE";
        case PciSubDevice8088010B::SUBDEVICE_80880102: return "SUBDEVICE_80880102";
        case PciSubDevice8088010B::SUBDEVICE_80884102: return "SUBDEVICE_80884102";
        case PciSubDevice8088010B::SUBDEVICE_80888102: return "SUBDEVICE_80888102";
        case PciSubDevice8088010B::SUBDEVICE_8088C102: return "SUBDEVICE_8088C102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8088010B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8088010B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8088010B::SUBDEVICE_80880102: return "Single-Port Ethernet Network Adaptor SF100HT";
        case PciSubDevice8088010B::SUBDEVICE_80884102: return "Single-Port Ethernet Network Adaptor SF100HT (WOL)";
        case PciSubDevice8088010B::SUBDEVICE_80888102: return "Single-Port Ethernet Network Adaptor SF100HT (NCSI)";
        case PciSubDevice8088010B::SUBDEVICE_8088C102: return "Single-Port Ethernet Network Adaptor SF100HT (WOL, NCSI)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE8088010B_H
