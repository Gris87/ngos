// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC1B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC1B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC1B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B113 = 0x0E11B113,
    SUBDEVICE_10140130 = 0x10140130
};



inline const char8* enumToString(PciSubDevice104CAC1B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC1B::NONE:               return "NONE";
        case PciSubDevice104CAC1B::SUBDEVICE_0E11B113: return "SUBDEVICE_0E11B113";
        case PciSubDevice104CAC1B::SUBDEVICE_10140130: return "SUBDEVICE_10140130";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC1B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC1B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC1B::SUBDEVICE_0E11B113: return "Armada M700";
        case PciSubDevice104CAC1B::SUBDEVICE_10140130: return "ThinkPad 600X/A21m/T20/T22";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC1B_H
