// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC1C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC1C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC1C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B121 = 0x0E11B121,
    SUBDEVICE_10280088 = 0x10280088
};



inline const char8* enumToString(PciSubDevice104CAC1C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC1C::NONE:               return "NONE";
        case PciSubDevice104CAC1C::SUBDEVICE_0E11B121: return "SUBDEVICE_0E11B121";
        case PciSubDevice104CAC1C::SUBDEVICE_10280088: return "SUBDEVICE_10280088";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC1C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC1C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC1C::SUBDEVICE_0E11B121: return "Armada E500";
        case PciSubDevice104CAC1C::SUBDEVICE_10280088: return "Latitude CPi A400XT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC1C_H
