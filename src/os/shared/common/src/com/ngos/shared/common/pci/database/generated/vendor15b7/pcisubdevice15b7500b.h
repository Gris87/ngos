// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCISUBDEVICE15B7500B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCISUBDEVICE15B7500B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B7500B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1414500B = 0x1414500B
};



inline const char8* enumToString(PciSubDevice15B7500B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B7500B::NONE:               return "NONE";
        case PciSubDevice15B7500B::SUBDEVICE_1414500B: return "SUBDEVICE_1414500B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B7500B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B7500B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B7500B::SUBDEVICE_1414500B: return "Xbox Series X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCISUBDEVICE15B7500B_H
