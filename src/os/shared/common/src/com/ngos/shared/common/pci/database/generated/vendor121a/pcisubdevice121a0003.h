// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice121A0003: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10920003 = 0x10920003,
    SUBDEVICE_10924000 = 0x10924000,
    SUBDEVICE_10924002 = 0x10924002,
    SUBDEVICE_10924801 = 0x10924801,
    SUBDEVICE_10924803 = 0x10924803,
    SUBDEVICE_10928030 = 0x10928030,
    SUBDEVICE_10928035 = 0x10928035,
    SUBDEVICE_10B00001 = 0x10B00001,
    SUBDEVICE_11021017 = 0x11021017,
    SUBDEVICE_11021018 = 0x11021018,
    SUBDEVICE_121A0001 = 0x121A0001,
    SUBDEVICE_121A0003 = 0x121A0003,
    SUBDEVICE_121A0004 = 0x121A0004,
    SUBDEVICE_139C0016 = 0x139C0016,
    SUBDEVICE_139C0017 = 0x139C0017,
    SUBDEVICE_14AF0002 = 0x14AF0002
};



inline const char8* enumToString(PciSubDevice121A0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121A0003::NONE:               return "NONE";
        case PciSubDevice121A0003::SUBDEVICE_10920003: return "SUBDEVICE_10920003";
        case PciSubDevice121A0003::SUBDEVICE_10924000: return "SUBDEVICE_10924000";
        case PciSubDevice121A0003::SUBDEVICE_10924002: return "SUBDEVICE_10924002";
        case PciSubDevice121A0003::SUBDEVICE_10924801: return "SUBDEVICE_10924801";
        case PciSubDevice121A0003::SUBDEVICE_10924803: return "SUBDEVICE_10924803";
        case PciSubDevice121A0003::SUBDEVICE_10928030: return "SUBDEVICE_10928030";
        case PciSubDevice121A0003::SUBDEVICE_10928035: return "SUBDEVICE_10928035";
        case PciSubDevice121A0003::SUBDEVICE_10B00001: return "SUBDEVICE_10B00001";
        case PciSubDevice121A0003::SUBDEVICE_11021017: return "SUBDEVICE_11021017";
        case PciSubDevice121A0003::SUBDEVICE_11021018: return "SUBDEVICE_11021018";
        case PciSubDevice121A0003::SUBDEVICE_121A0001: return "SUBDEVICE_121A0001";
        case PciSubDevice121A0003::SUBDEVICE_121A0003: return "SUBDEVICE_121A0003";
        case PciSubDevice121A0003::SUBDEVICE_121A0004: return "SUBDEVICE_121A0004";
        case PciSubDevice121A0003::SUBDEVICE_139C0016: return "SUBDEVICE_139C0016";
        case PciSubDevice121A0003::SUBDEVICE_139C0017: return "SUBDEVICE_139C0017";
        case PciSubDevice121A0003::SUBDEVICE_14AF0002: return "SUBDEVICE_14AF0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice121A0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice121A0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121A0003::SUBDEVICE_10920003: return "Monster Fusion";
        case PciSubDevice121A0003::SUBDEVICE_10924000: return "Monster Fusion";
        case PciSubDevice121A0003::SUBDEVICE_10924002: return "Monster Fusion";
        case PciSubDevice121A0003::SUBDEVICE_10924801: return "Monster Fusion AGP";
        case PciSubDevice121A0003::SUBDEVICE_10924803: return "Monster Fusion AGP";
        case PciSubDevice121A0003::SUBDEVICE_10928030: return "Monster Fusion";
        case PciSubDevice121A0003::SUBDEVICE_10928035: return "Monster Fusion AGP";
        case PciSubDevice121A0003::SUBDEVICE_10B00001: return "Dragon 4000";
        case PciSubDevice121A0003::SUBDEVICE_11021017: return "3D Blaster Banshee PCI (CT6760)";
        case PciSubDevice121A0003::SUBDEVICE_11021018: return "3D Blaster Banshee VE";
        case PciSubDevice121A0003::SUBDEVICE_121A0001: return "Voodoo Banshee AGP";
        case PciSubDevice121A0003::SUBDEVICE_121A0003: return "Voodoo Banshee AGP SGRAM";
        case PciSubDevice121A0003::SUBDEVICE_121A0004: return "Voodoo Banshee";
        case PciSubDevice121A0003::SUBDEVICE_139C0016: return "Raven";
        case PciSubDevice121A0003::SUBDEVICE_139C0017: return "Raven";
        case PciSubDevice121A0003::SUBDEVICE_14AF0002: return "Maxi Gamer Phoenix";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0003_H
