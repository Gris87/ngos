// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE026C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE026C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE026C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2A34 = 0x103C2A34,
    SUBDEVICE_103C30B5 = 0x103C30B5,
    SUBDEVICE_103C30B7 = 0x103C30B7,
    SUBDEVICE_10DECB84 = 0x10DECB84,
    SUBDEVICE_14627207 = 0x14627207
};



inline const char8* enumToString(PciSubDevice10DE026C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE026C::NONE:               return "NONE";
        case PciSubDevice10DE026C::SUBDEVICE_103C2A34: return "SUBDEVICE_103C2A34";
        case PciSubDevice10DE026C::SUBDEVICE_103C30B5: return "SUBDEVICE_103C30B5";
        case PciSubDevice10DE026C::SUBDEVICE_103C30B7: return "SUBDEVICE_103C30B7";
        case PciSubDevice10DE026C::SUBDEVICE_10DECB84: return "SUBDEVICE_10DECB84";
        case PciSubDevice10DE026C::SUBDEVICE_14627207: return "SUBDEVICE_14627207";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE026C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE026C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE026C::SUBDEVICE_103C2A34: return "Pavilion a1677c";
        case PciSubDevice10DE026C::SUBDEVICE_103C30B5: return "Presario V3242AU";
        case PciSubDevice10DE026C::SUBDEVICE_103C30B7: return "Presario V6133CL";
        case PciSubDevice10DE026C::SUBDEVICE_10DECB84: return "ASUSTeK Computer Inc. A8N-VM CSM Mainboard";
        case PciSubDevice10DE026C::SUBDEVICE_14627207: return "K8NGM2 series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE026C_H
