// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55833_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55833_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D55833: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17D56030 = 0x17D56030,
    SUBDEVICE_17D56031 = 0x17D56031,
    SUBDEVICE_17D56430 = 0x17D56430,
    SUBDEVICE_17D56431 = 0x17D56431,
    SUBDEVICE_17D57030 = 0x17D57030,
    SUBDEVICE_17D57031 = 0x17D57031,
    SUBDEVICE_17D57430 = 0x17D57430,
    SUBDEVICE_17D57431 = 0x17D57431,
    SUBDEVICE_17D57830 = 0x17D57830,
    SUBDEVICE_17D57831 = 0x17D57831
};



inline const char8* enumToString(PciSubDevice17D55833 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D55833::NONE:               return "NONE";
        case PciSubDevice17D55833::SUBDEVICE_17D56030: return "SUBDEVICE_17D56030";
        case PciSubDevice17D55833::SUBDEVICE_17D56031: return "SUBDEVICE_17D56031";
        case PciSubDevice17D55833::SUBDEVICE_17D56430: return "SUBDEVICE_17D56430";
        case PciSubDevice17D55833::SUBDEVICE_17D56431: return "SUBDEVICE_17D56431";
        case PciSubDevice17D55833::SUBDEVICE_17D57030: return "SUBDEVICE_17D57030";
        case PciSubDevice17D55833::SUBDEVICE_17D57031: return "SUBDEVICE_17D57031";
        case PciSubDevice17D55833::SUBDEVICE_17D57430: return "SUBDEVICE_17D57430";
        case PciSubDevice17D55833::SUBDEVICE_17D57431: return "SUBDEVICE_17D57431";
        case PciSubDevice17D55833::SUBDEVICE_17D57830: return "SUBDEVICE_17D57830";
        case PciSubDevice17D55833::SUBDEVICE_17D57831: return "SUBDEVICE_17D57831";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D55833 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D55833 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D55833::SUBDEVICE_17D56030: return "X3110 Single Port SR";
        case PciSubDevice17D55833::SUBDEVICE_17D56031: return "X3120 Dual Port SR";
        case PciSubDevice17D55833::SUBDEVICE_17D56430: return "X3110 Single Port LR";
        case PciSubDevice17D55833::SUBDEVICE_17D56431: return "X3120 Dual Port LR";
        case PciSubDevice17D55833::SUBDEVICE_17D57030: return "X3110 Single Port LRM";
        case PciSubDevice17D55833::SUBDEVICE_17D57031: return "X3120 Dual Port LRM";
        case PciSubDevice17D55833::SUBDEVICE_17D57430: return "X3110 Single Port 10GBase-T";
        case PciSubDevice17D55833::SUBDEVICE_17D57431: return "X3120 Dual Port 10GBase-T";
        case PciSubDevice17D55833::SUBDEVICE_17D57830: return "X3110 Single Port 10GBase-CR";
        case PciSubDevice17D55833::SUBDEVICE_17D57831: return "X3120 Dual Port 10GBase-CR";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55833_H
