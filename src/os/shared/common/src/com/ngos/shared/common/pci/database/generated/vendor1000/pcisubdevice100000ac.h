// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000AC: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003000 = 0x10003000,
    SUBDEVICE_10003020 = 0x10003020,
    SUBDEVICE_10281FE3 = 0x10281FE3,
    SUBDEVICE_10281FE4 = 0x10281FE4,
    SUBDEVICE_1D490201 = 0x1D490201,
    SUBDEVICE_1D490203 = 0x1D490203,
    SUBDEVICE_80863000 = 0x80863000,
    SUBDEVICE_80863020 = 0x80863020
};



inline const char8* enumToString(PciSubDevice100000AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000AC::NONE:               return "NONE";
        case PciSubDevice100000AC::SUBDEVICE_10003000: return "SUBDEVICE_10003000";
        case PciSubDevice100000AC::SUBDEVICE_10003020: return "SUBDEVICE_10003020";
        case PciSubDevice100000AC::SUBDEVICE_10281FE3: return "SUBDEVICE_10281FE3";
        case PciSubDevice100000AC::SUBDEVICE_10281FE4: return "SUBDEVICE_10281FE4";
        case PciSubDevice100000AC::SUBDEVICE_1D490201: return "SUBDEVICE_1D490201";
        case PciSubDevice100000AC::SUBDEVICE_1D490203: return "SUBDEVICE_1D490203";
        case PciSubDevice100000AC::SUBDEVICE_80863000: return "SUBDEVICE_80863000";
        case PciSubDevice100000AC::SUBDEVICE_80863020: return "SUBDEVICE_80863020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000AC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000AC::SUBDEVICE_10003000: return "HBA 9400-16i";
        case PciSubDevice100000AC::SUBDEVICE_10003020: return "HBA 9400-16e";
        case PciSubDevice100000AC::SUBDEVICE_10281FE3: return "HBA345 Adapter";
        case PciSubDevice100000AC::SUBDEVICE_10281FE4: return "HBA345 Front";
        case PciSubDevice100000AC::SUBDEVICE_1D490201: return "ThinkSystem 430-16i SAS/SATA 12Gb HBA";
        case PciSubDevice100000AC::SUBDEVICE_1D490203: return "ThinkSystem 430-16e SAS/SATA 12Gb HBA";
        case PciSubDevice100000AC::SUBDEVICE_80863000: return "RAID Controller RSP3QD160J";
        case PciSubDevice100000AC::SUBDEVICE_80863020: return "RAID Controller RSP3GD016J";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AC_H
