// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10391182_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10391182_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10391182: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10390180 = 0x10390180
};



inline const char8* enumToString(PciSubDevice10391182 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10391182::NONE:               return "NONE";
        case PciSubDevice10391182::SUBDEVICE_10390180: return "SUBDEVICE_10390180";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10391182 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10391182 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10391182::SUBDEVICE_10390180: return "SiS 966 4-port SATA controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10391182_H
