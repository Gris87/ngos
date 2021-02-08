// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10221414_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10221414_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10221414: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10221234 = 0x10221234
};



inline const char8* enumToString(PciSubDevice10221414 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10221414::NONE:               return "NONE";
        case PciSubDevice10221414::SUBDEVICE_10221234: return "SUBDEVICE_10221234";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10221414 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10221414 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10221414::SUBDEVICE_10221234: return "Trinity A-series APU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10221414_H
