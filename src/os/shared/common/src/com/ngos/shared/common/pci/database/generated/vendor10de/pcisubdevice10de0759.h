// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0759_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0759_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0759: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104382E8 = 0x104382E8,
    SUBDEVICE_14627508 = 0x14627508,
    SUBDEVICE_18490759 = 0x18490759
};



inline const char8* enumToString(PciSubDevice10DE0759 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0759::NONE:               return "NONE";
        case PciSubDevice10DE0759::SUBDEVICE_104382E8: return "SUBDEVICE_104382E8";
        case PciSubDevice10DE0759::SUBDEVICE_14627508: return "SUBDEVICE_14627508";
        case PciSubDevice10DE0759::SUBDEVICE_18490759: return "SUBDEVICE_18490759";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0759 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0759 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0759::SUBDEVICE_104382E8: return "M3N72-D";
        case PciSubDevice10DE0759::SUBDEVICE_14627508: return "K9N2GM-FIH";
        case PciSubDevice10DE0759::SUBDEVICE_18490759: return "K10N78FullHD-hSLI R3.0 IDE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0759_H
