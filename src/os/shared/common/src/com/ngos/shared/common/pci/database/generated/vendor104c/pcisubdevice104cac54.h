// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC54_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC54_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC54: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C08B0 = 0x103C08B0
};



inline const char8* enumToString(PciSubDevice104CAC54 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC54::NONE:               return "NONE";
        case PciSubDevice104CAC54::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC54 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC54 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC54::SUBDEVICE_103C08B0: return "tc1100 tablet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC54_H
