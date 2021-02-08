// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861026_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861026_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861026: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280168 = 0x10280168,
    SUBDEVICE_10280169 = 0x10280169,
    SUBDEVICE_80861000 = 0x80861000,
    SUBDEVICE_80861001 = 0x80861001,
    SUBDEVICE_80861002 = 0x80861002,
    SUBDEVICE_80861003 = 0x80861003,
    SUBDEVICE_80861026 = 0x80861026
};



inline const char8* enumToString(PciSubDevice80861026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861026::NONE:               return "NONE";
        case PciSubDevice80861026::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice80861026::SUBDEVICE_10280169: return "SUBDEVICE_10280169";
        case PciSubDevice80861026::SUBDEVICE_80861000: return "SUBDEVICE_80861000";
        case PciSubDevice80861026::SUBDEVICE_80861001: return "SUBDEVICE_80861001";
        case PciSubDevice80861026::SUBDEVICE_80861002: return "SUBDEVICE_80861002";
        case PciSubDevice80861026::SUBDEVICE_80861003: return "SUBDEVICE_80861003";
        case PciSubDevice80861026::SUBDEVICE_80861026: return "SUBDEVICE_80861026";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861026::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice80861026::SUBDEVICE_10280169: return "Precision 470";
        case PciSubDevice80861026::SUBDEVICE_80861000: return "PRO/1000 MT Server Connection";
        case PciSubDevice80861026::SUBDEVICE_80861001: return "PRO/1000 MT Server Adapter";
        case PciSubDevice80861026::SUBDEVICE_80861002: return "PRO/1000 MT Server Adapter";
        case PciSubDevice80861026::SUBDEVICE_80861003: return "PRO/1000 GT Server Adapter";
        case PciSubDevice80861026::SUBDEVICE_80861026: return "PRO/1000 MT Server Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861026_H
