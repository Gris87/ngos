// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026610_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026610_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026610: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190030 = 0x10190030,
    SUBDEVICE_10280081 = 0x10280081,
    SUBDEVICE_10280083 = 0x10280083,
    SUBDEVICE_10282120 = 0x10282120,
    SUBDEVICE_10282322 = 0x10282322,
    SUBDEVICE_14622910 = 0x14622910,
    SUBDEVICE_14622911 = 0x14622911,
    SUBDEVICE_148C7350 = 0x148C7350,
    SUBDEVICE_16423C81 = 0x16423C81,
    SUBDEVICE_16423C91 = 0x16423C91,
    SUBDEVICE_16423F09 = 0x16423F09
};



inline const char8* enumToString(PciSubDevice10026610 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026610::NONE:               return "NONE";
        case PciSubDevice10026610::SUBDEVICE_10190030: return "SUBDEVICE_10190030";
        case PciSubDevice10026610::SUBDEVICE_10280081: return "SUBDEVICE_10280081";
        case PciSubDevice10026610::SUBDEVICE_10280083: return "SUBDEVICE_10280083";
        case PciSubDevice10026610::SUBDEVICE_10282120: return "SUBDEVICE_10282120";
        case PciSubDevice10026610::SUBDEVICE_10282322: return "SUBDEVICE_10282322";
        case PciSubDevice10026610::SUBDEVICE_14622910: return "SUBDEVICE_14622910";
        case PciSubDevice10026610::SUBDEVICE_14622911: return "SUBDEVICE_14622911";
        case PciSubDevice10026610::SUBDEVICE_148C7350: return "SUBDEVICE_148C7350";
        case PciSubDevice10026610::SUBDEVICE_16423C81: return "SUBDEVICE_16423C81";
        case PciSubDevice10026610::SUBDEVICE_16423C91: return "SUBDEVICE_16423C91";
        case PciSubDevice10026610::SUBDEVICE_16423F09: return "SUBDEVICE_16423F09";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026610 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026610 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026610::SUBDEVICE_10190030: return "Radeon HD 8670";
        case PciSubDevice10026610::SUBDEVICE_10280081: return "Radeon R7 350X OEM";
        case PciSubDevice10026610::SUBDEVICE_10280083: return "Radeon R5 340X OEM";
        case PciSubDevice10026610::SUBDEVICE_10282120: return "Radeon R7 250";
        case PciSubDevice10026610::SUBDEVICE_10282322: return "Radeon R7 250";
        case PciSubDevice10026610::SUBDEVICE_14622910: return "Radeon HD 8670";
        case PciSubDevice10026610::SUBDEVICE_14622911: return "Radeon HD 8670";
        case PciSubDevice10026610::SUBDEVICE_148C7350: return "Radeon R7 350";
        case PciSubDevice10026610::SUBDEVICE_16423C81: return "Radeon HD 8670";
        case PciSubDevice10026610::SUBDEVICE_16423C91: return "Radeon HD 8670";
        case PciSubDevice10026610::SUBDEVICE_16423F09: return "Radeon R7 350";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026610_H
