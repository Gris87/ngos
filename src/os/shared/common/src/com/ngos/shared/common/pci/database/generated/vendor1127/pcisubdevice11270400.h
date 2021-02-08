// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1127_PCISUBDEVICE11270400_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1127_PCISUBDEVICE11270400_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11270400: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11270400 = 0x11270400
};



inline const char8* enumToString(PciSubDevice11270400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11270400::NONE:               return "NONE";
        case PciSubDevice11270400::SUBDEVICE_11270400: return "SUBDEVICE_11270400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11270400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11270400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11270400::SUBDEVICE_11270400: return "ForeRunnerHE ATM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1127_PCISUBDEVICE11270400_H
