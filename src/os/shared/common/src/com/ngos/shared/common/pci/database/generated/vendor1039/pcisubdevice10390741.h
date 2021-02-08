// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10390741_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10390741_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10390741: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_18490741 = 0x18490741
};



inline const char8* enumToString(PciSubDevice10390741 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10390741::NONE:               return "NONE";
        case PciSubDevice10390741::SUBDEVICE_18490741: return "SUBDEVICE_18490741";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10390741 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10390741 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10390741::SUBDEVICE_18490741: return "K7S41/K7S41GX motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10390741_H
