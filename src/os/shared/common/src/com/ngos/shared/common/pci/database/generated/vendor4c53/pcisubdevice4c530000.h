// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCISUBDEVICE4C530000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCISUBDEVICE4C530000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice4C530000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C533000 = 0x4C533000,
    SUBDEVICE_4C533001 = 0x4C533001
};



inline const char8* enumToString(PciSubDevice4C530000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice4C530000::NONE:               return "NONE";
        case PciSubDevice4C530000::SUBDEVICE_4C533000: return "SUBDEVICE_4C533000";
        case PciSubDevice4C530000::SUBDEVICE_4C533001: return "SUBDEVICE_4C533001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice4C530000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice4C530000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice4C530000::SUBDEVICE_4C533000: return "PLUSTEST card (PC104+)";
        case PciSubDevice4C530000::SUBDEVICE_4C533001: return "PLUSTEST card (PMC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCISUBDEVICE4C530000_H
