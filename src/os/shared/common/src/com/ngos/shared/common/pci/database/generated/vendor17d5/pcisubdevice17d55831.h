// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55831_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55831_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D55831: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C12D5 = 0x103C12D5,
    SUBDEVICE_10A98020 = 0x10A98020,
    SUBDEVICE_10A98024 = 0x10A98024
};



inline const char8* enumToString(PciSubDevice17D55831 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D55831::NONE:               return "NONE";
        case PciSubDevice17D55831::SUBDEVICE_103C12D5: return "SUBDEVICE_103C12D5";
        case PciSubDevice17D55831::SUBDEVICE_10A98020: return "SUBDEVICE_10A98020";
        case PciSubDevice17D55831::SUBDEVICE_10A98024: return "SUBDEVICE_10A98024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D55831 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D55831 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D55831::SUBDEVICE_103C12D5: return "PCI-X 133MHz 10GbE SR Fiber";
        case PciSubDevice17D55831::SUBDEVICE_10A98020: return "Single Port 10-Gigabit Ethernet (PCI-X, Fiber)";
        case PciSubDevice17D55831::SUBDEVICE_10A98024: return "Single Port 10-Gigabit Ethernet (PCI-X, Fiber)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55831_H
