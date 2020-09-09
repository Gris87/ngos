// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861A30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861A30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861A30: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028010E = 0x1028010E,
    SUBDEVICE_147B0505 = 0x147B0505,
    SUBDEVICE_15D93280 = 0x15D93280
};



inline const char8* enumToString(PciSubDevice80861A30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861A30::NONE:               return "NONE";
        case PciSubDevice80861A30::SUBDEVICE_1028010E: return "SUBDEVICE_1028010E";
        case PciSubDevice80861A30::SUBDEVICE_147B0505: return "SUBDEVICE_147B0505";
        case PciSubDevice80861A30::SUBDEVICE_15D93280: return "SUBDEVICE_15D93280";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861A30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861A30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861A30::SUBDEVICE_1028010E: return "Optiplex GX240";
        case PciSubDevice80861A30::SUBDEVICE_147B0505: return "BL7 motherboard";
        case PciSubDevice80861A30::SUBDEVICE_15D93280: return "Supermicro P4SBE Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861A30_H
