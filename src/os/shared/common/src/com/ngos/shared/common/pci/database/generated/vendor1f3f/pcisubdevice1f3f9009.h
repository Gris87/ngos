// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1F3F9009: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1F3F1000 = 0x1F3F1000
};



inline const char8* enumToString(PciSubDevice1F3F9009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F9009::NONE:               return "NONE";
        case PciSubDevice1F3F9009::SUBDEVICE_1F3F1000: return "SUBDEVICE_1F3F1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1F3F9009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1F3F9009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F9009::SUBDEVICE_1F3F1000: return "3SFC VF Hyper-V";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9009_H
