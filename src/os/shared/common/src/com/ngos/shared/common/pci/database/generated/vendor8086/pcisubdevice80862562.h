// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862562_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862562_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862562: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100B9 = 0x0E1100B9,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_10280160 = 0x10280160,
    SUBDEVICE_17341003 = 0x17341003,
    SUBDEVICE_17341004 = 0x17341004
};



inline const char8* enumToString(PciSubDevice80862562 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862562::NONE:               return "NONE";
        case PciSubDevice80862562::SUBDEVICE_0E1100B9: return "SUBDEVICE_0E1100B9";
        case PciSubDevice80862562::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice80862562::SUBDEVICE_10280160: return "SUBDEVICE_10280160";
        case PciSubDevice80862562::SUBDEVICE_17341003: return "SUBDEVICE_17341003";
        case PciSubDevice80862562::SUBDEVICE_17341004: return "SUBDEVICE_17341004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862562 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862562 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862562::SUBDEVICE_0E1100B9: return "Evo D510 SFF";
        case PciSubDevice80862562::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice80862562::SUBDEVICE_10280160: return "Dimension 2400";
        case PciSubDevice80862562::SUBDEVICE_17341003: return "D1521 Mainboard (Fujitsu-Siemens)";
        case PciSubDevice80862562::SUBDEVICE_17341004: return "D1451 Mainboard (SCENIC N300, bad_int845GV)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862562_H
