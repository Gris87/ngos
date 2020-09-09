// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4164A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1709 = 0x103C1709,
    SUBDEVICE_103C3070 = 0x103C3070,
    SUBDEVICE_103C3101 = 0x103C3101,
    SUBDEVICE_103C3106 = 0x103C3106
};



inline const char8* enumToString(PciSubDevice14E4164A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4164A::NONE:               return "NONE";
        case PciSubDevice14E4164A::SUBDEVICE_103C1709: return "SUBDEVICE_103C1709";
        case PciSubDevice14E4164A::SUBDEVICE_103C3070: return "SUBDEVICE_103C3070";
        case PciSubDevice14E4164A::SUBDEVICE_103C3101: return "SUBDEVICE_103C3101";
        case PciSubDevice14E4164A::SUBDEVICE_103C3106: return "SUBDEVICE_103C3106";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4164A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4164A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4164A::SUBDEVICE_103C1709: return "NC371i Integrated PCI-X Multifunction Gigabit Server Adapter";
        case PciSubDevice14E4164A::SUBDEVICE_103C3070: return "NC380T PCI Express Dual Port Multifunction Gigabit Server Adapter";
        case PciSubDevice14E4164A::SUBDEVICE_103C3101: return "NC370T MultifuNCtion Gigabit Server Adapter";
        case PciSubDevice14E4164A::SUBDEVICE_103C3106: return "NC370i Multifunction Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164A_H
