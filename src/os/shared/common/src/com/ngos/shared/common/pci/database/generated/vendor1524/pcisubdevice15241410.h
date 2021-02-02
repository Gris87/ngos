// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCISUBDEVICE15241410_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCISUBDEVICE15241410_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15241410: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025003C = 0x1025003C,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_103C30D5 = 0x103C30D5
};



inline const char8* enumToString(PciSubDevice15241410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15241410::NONE:               return "NONE";
        case PciSubDevice15241410::SUBDEVICE_1025003C: return "SUBDEVICE_1025003C";
        case PciSubDevice15241410::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice15241410::SUBDEVICE_103C30D5: return "SUBDEVICE_103C30D5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15241410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15241410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15241410::SUBDEVICE_1025003C: return "CL50 motherboard";
        case PciSubDevice15241410::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice15241410::SUBDEVICE_103C30D5: return "530 Laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCISUBDEVICE15241410_H
