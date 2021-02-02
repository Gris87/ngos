// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025B70_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025B70_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025B70: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14620403 = 0x14620403,
    SUBDEVICE_174B0501 = 0x174B0501,
    SUBDEVICE_196D1087 = 0x196D1087
};



inline const char8* enumToString(PciSubDevice10025B70 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025B70::NONE:               return "NONE";
        case PciSubDevice10025B70::SUBDEVICE_14620403: return "SUBDEVICE_14620403";
        case PciSubDevice10025B70::SUBDEVICE_174B0501: return "SUBDEVICE_174B0501";
        case PciSubDevice10025B70::SUBDEVICE_196D1087: return "SUBDEVICE_196D1087";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025B70 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025B70 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025B70::SUBDEVICE_14620403: return "Radeon X300 SE 128MB DDR";
        case PciSubDevice10025B70::SUBDEVICE_174B0501: return "Radeon X300 SE";
        case PciSubDevice10025B70::SUBDEVICE_196D1087: return "Radeon X300 SE HyperMemory";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025B70_H
