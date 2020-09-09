// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4361_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4361_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4361: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107B3015 = 0x107B3015,
    SUBDEVICE_11AB5021 = 0x11AB5021,
    SUBDEVICE_80863063 = 0x80863063,
    SUBDEVICE_80863439 = 0x80863439
};



inline const char8* enumToString(PciSubDevice11AB4361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4361::NONE:               return "NONE";
        case PciSubDevice11AB4361::SUBDEVICE_107B3015: return "SUBDEVICE_107B3015";
        case PciSubDevice11AB4361::SUBDEVICE_11AB5021: return "SUBDEVICE_11AB5021";
        case PciSubDevice11AB4361::SUBDEVICE_80863063: return "SUBDEVICE_80863063";
        case PciSubDevice11AB4361::SUBDEVICE_80863439: return "SUBDEVICE_80863439";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4361::SUBDEVICE_107B3015: return "Marvell 88E8050 Gigabit Ethernet Controller (Gateway)";
        case PciSubDevice11AB4361::SUBDEVICE_11AB5021: return "Marvell 88E8050 Gigabit Ethernet Controller (Intel)";
        case PciSubDevice11AB4361::SUBDEVICE_80863063: return "D925XCVLK mainboard";
        case PciSubDevice11AB4361::SUBDEVICE_80863439: return "Marvell 88E8050 Gigabit Ethernet Controller (Intel)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4361_H
