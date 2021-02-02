// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624C6: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140524 = 0x10140524,
    SUBDEVICE_10140525 = 0x10140525,
    SUBDEVICE_10140559 = 0x10140559,
    SUBDEVICE_1025003C = 0x1025003C,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_10280196 = 0x10280196,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_10431716 = 0x10431716,
    SUBDEVICE_10431826 = 0x10431826,
    SUBDEVICE_10718160 = 0x10718160,
    SUBDEVICE_134D4C21 = 0x134D4C21,
    SUBDEVICE_144D2115 = 0x144D2115,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_14F15422 = 0x14F15422
};



inline const char8* enumToString(PciSubDevice808624C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C6::NONE:               return "NONE";
        case PciSubDevice808624C6::SUBDEVICE_10140524: return "SUBDEVICE_10140524";
        case PciSubDevice808624C6::SUBDEVICE_10140525: return "SUBDEVICE_10140525";
        case PciSubDevice808624C6::SUBDEVICE_10140559: return "SUBDEVICE_10140559";
        case PciSubDevice808624C6::SUBDEVICE_1025003C: return "SUBDEVICE_1025003C";
        case PciSubDevice808624C6::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice808624C6::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice808624C6::SUBDEVICE_10280196: return "SUBDEVICE_10280196";
        case PciSubDevice808624C6::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice808624C6::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice808624C6::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice808624C6::SUBDEVICE_10431716: return "SUBDEVICE_10431716";
        case PciSubDevice808624C6::SUBDEVICE_10431826: return "SUBDEVICE_10431826";
        case PciSubDevice808624C6::SUBDEVICE_10718160: return "SUBDEVICE_10718160";
        case PciSubDevice808624C6::SUBDEVICE_134D4C21: return "SUBDEVICE_134D4C21";
        case PciSubDevice808624C6::SUBDEVICE_144D2115: return "SUBDEVICE_144D2115";
        case PciSubDevice808624C6::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice808624C6::SUBDEVICE_14F15422: return "SUBDEVICE_14F15422";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C6::SUBDEVICE_10140524: return "ThinkPad T4x Series";
        case PciSubDevice808624C6::SUBDEVICE_10140525: return "ThinkPad";
        case PciSubDevice808624C6::SUBDEVICE_10140559: return "ThinkPad R50e";
        case PciSubDevice808624C6::SUBDEVICE_1025003C: return "Aspire 2001WLCi (Compal CL50 motherboard) implementation";
        case PciSubDevice808624C6::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice808624C6::SUBDEVICE_10250064: return "Extensa 3000 series laptop: Intel 82801DBM (ICH4-M)";
        case PciSubDevice808624C6::SUBDEVICE_10280196: return "Inspiron 5160";
        case PciSubDevice808624C6::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice808624C6::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice808624C6::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice808624C6::SUBDEVICE_10431716: return "M2400N laptop";
        case PciSubDevice808624C6::SUBDEVICE_10431826: return "M6800N";
        case PciSubDevice808624C6::SUBDEVICE_10718160: return "MIM2000";
        case PciSubDevice808624C6::SUBDEVICE_134D4C21: return "Latitude D500";
        case PciSubDevice808624C6::SUBDEVICE_144D2115: return "X10 Laptop";
        case PciSubDevice808624C6::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice808624C6::SUBDEVICE_14F15422: return "D480 MDC V.9x Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C6_H
