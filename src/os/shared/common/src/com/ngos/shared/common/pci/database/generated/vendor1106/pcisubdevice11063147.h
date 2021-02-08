// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063147_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063147_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063147: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043808C = 0x1043808C
};



inline const char8* enumToString(PciSubDevice11063147 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063147::NONE:               return "NONE";
        case PciSubDevice11063147::SUBDEVICE_1043808C: return "SUBDEVICE_1043808C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063147 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063147 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063147::SUBDEVICE_1043808C: return "A7V333 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063147_H
