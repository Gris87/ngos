// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCISUBDEVICE12BE3042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCISUBDEVICE12BE3042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12BE3042: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12BE3042 = 0x12BE3042
};



inline const char8* enumToString(PciSubDevice12BE3042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12BE3042::NONE:               return "NONE";
        case PciSubDevice12BE3042::SUBDEVICE_12BE3042: return "SUBDEVICE_12BE3042";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12BE3042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12BE3042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12BE3042::SUBDEVICE_12BE3042: return "Anchor Chips Lite Evaluation Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCISUBDEVICE12BE3042_H
