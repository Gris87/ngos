// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A1002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1092094C = 0x1092094C,
    SUBDEVICE_122D4002 = 0x122D4002,
    SUBDEVICE_122D4005 = 0x122D4005,
    SUBDEVICE_122D4007 = 0x122D4007,
    SUBDEVICE_122D4012 = 0x122D4012,
    SUBDEVICE_122D4017 = 0x122D4017,
    SUBDEVICE_122D4018 = 0x122D4018,
    SUBDEVICE_127A1002 = 0x127A1002
};



inline const char8* enumToString(PciSubDevice127A1002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1002::NONE:               return "NONE";
        case PciSubDevice127A1002::SUBDEVICE_1092094C: return "SUBDEVICE_1092094C";
        case PciSubDevice127A1002::SUBDEVICE_122D4002: return "SUBDEVICE_122D4002";
        case PciSubDevice127A1002::SUBDEVICE_122D4005: return "SUBDEVICE_122D4005";
        case PciSubDevice127A1002::SUBDEVICE_122D4007: return "SUBDEVICE_122D4007";
        case PciSubDevice127A1002::SUBDEVICE_122D4012: return "SUBDEVICE_122D4012";
        case PciSubDevice127A1002::SUBDEVICE_122D4017: return "SUBDEVICE_122D4017";
        case PciSubDevice127A1002::SUBDEVICE_122D4018: return "SUBDEVICE_122D4018";
        case PciSubDevice127A1002::SUBDEVICE_127A1002: return "SUBDEVICE_127A1002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A1002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A1002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1002::SUBDEVICE_1092094C: return "SupraExpress 56i PRO [Diamond SUP2380]";
        case PciSubDevice127A1002::SUBDEVICE_122D4002: return "HPG / MDP3858-U";
        case PciSubDevice127A1002::SUBDEVICE_122D4005: return "MDP3858-E";
        case PciSubDevice127A1002::SUBDEVICE_122D4007: return "MDP3858-A/-NZ";
        case PciSubDevice127A1002::SUBDEVICE_122D4012: return "MDP3858-SA";
        case PciSubDevice127A1002::SUBDEVICE_122D4017: return "MDP3858-W";
        case PciSubDevice127A1002::SUBDEVICE_122D4018: return "MDP3858-W";
        case PciSubDevice127A1002::SUBDEVICE_127A1002: return "Rockwell 56K D/F HCF Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1002_H
