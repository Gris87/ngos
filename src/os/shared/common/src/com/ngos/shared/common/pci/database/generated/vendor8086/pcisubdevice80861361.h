// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861361_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861361_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861361: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861361 = 0x80861361,
    SUBDEVICE_80868000 = 0x80868000
};



inline const char8* enumToString(PciSubDevice80861361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861361::NONE:               return "NONE";
        case PciSubDevice80861361::SUBDEVICE_80861361: return "SUBDEVICE_80861361";
        case PciSubDevice80861361::SUBDEVICE_80868000: return "SUBDEVICE_80868000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861361::SUBDEVICE_80861361: return "82806AA PCI64 Hub Controller (HRes)";
        case PciSubDevice80861361::SUBDEVICE_80868000: return "82806AA PCI64 Hub Controller (HRes)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861361_H
