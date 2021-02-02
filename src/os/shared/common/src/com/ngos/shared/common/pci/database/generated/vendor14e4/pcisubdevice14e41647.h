// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41647_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41647_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41647: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110099 = 0x0E110099,
    SUBDEVICE_0E11009A = 0x0E11009A,
    SUBDEVICE_10A98010 = 0x10A98010,
    SUBDEVICE_14E40009 = 0x14E40009,
    SUBDEVICE_14E4000A = 0x14E4000A,
    SUBDEVICE_14E4000B = 0x14E4000B,
    SUBDEVICE_14E48009 = 0x14E48009,
    SUBDEVICE_14E4800A = 0x14E4800A
};



inline const char8* enumToString(PciSubDevice14E41647 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41647::NONE:               return "NONE";
        case PciSubDevice14E41647::SUBDEVICE_0E110099: return "SUBDEVICE_0E110099";
        case PciSubDevice14E41647::SUBDEVICE_0E11009A: return "SUBDEVICE_0E11009A";
        case PciSubDevice14E41647::SUBDEVICE_10A98010: return "SUBDEVICE_10A98010";
        case PciSubDevice14E41647::SUBDEVICE_14E40009: return "SUBDEVICE_14E40009";
        case PciSubDevice14E41647::SUBDEVICE_14E4000A: return "SUBDEVICE_14E4000A";
        case PciSubDevice14E41647::SUBDEVICE_14E4000B: return "SUBDEVICE_14E4000B";
        case PciSubDevice14E41647::SUBDEVICE_14E48009: return "SUBDEVICE_14E48009";
        case PciSubDevice14E41647::SUBDEVICE_14E4800A: return "SUBDEVICE_14E4800A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41647 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41647 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41647::SUBDEVICE_0E110099: return "NC7780 1000BaseTX";
        case PciSubDevice14E41647::SUBDEVICE_0E11009A: return "NC7770 1000BaseTX";
        case PciSubDevice14E41647::SUBDEVICE_10A98010: return "IO9 Gigabit Ethernet (Copper)";
        case PciSubDevice14E41647::SUBDEVICE_14E40009: return "BCM5703 1000BaseTX";
        case PciSubDevice14E41647::SUBDEVICE_14E4000A: return "BCM5703 1000BaseSX";
        case PciSubDevice14E41647::SUBDEVICE_14E4000B: return "BCM5703 1000BaseTX";
        case PciSubDevice14E41647::SUBDEVICE_14E48009: return "BCM5703 1000BaseTX";
        case PciSubDevice14E41647::SUBDEVICE_14E4800A: return "BCM5703 1000BaseTX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41647_H
