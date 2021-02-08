// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026819_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026819_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026819: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043042C = 0x1043042C,
    SUBDEVICE_16827269 = 0x16827269,
    SUBDEVICE_16829278 = 0x16829278,
    SUBDEVICE_174BA008 = 0x174BA008,
    SUBDEVICE_174BE221 = 0x174BE221
};



inline const char8* enumToString(PciSubDevice10026819 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026819::NONE:               return "NONE";
        case PciSubDevice10026819::SUBDEVICE_1043042C: return "SUBDEVICE_1043042C";
        case PciSubDevice10026819::SUBDEVICE_16827269: return "SUBDEVICE_16827269";
        case PciSubDevice10026819::SUBDEVICE_16829278: return "SUBDEVICE_16829278";
        case PciSubDevice10026819::SUBDEVICE_174BA008: return "SUBDEVICE_174BA008";
        case PciSubDevice10026819::SUBDEVICE_174BE221: return "SUBDEVICE_174BE221";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026819 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026819 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026819::SUBDEVICE_1043042C: return "Radeon HD 7850";
        case PciSubDevice10026819::SUBDEVICE_16827269: return "Radeon R9 270 1024SP";
        case PciSubDevice10026819::SUBDEVICE_16829278: return "Radeon R9 270 1024SP";
        case PciSubDevice10026819::SUBDEVICE_174BA008: return "Radeon R9 270 1024SP";
        case PciSubDevice10026819::SUBDEVICE_174BE221: return "Radeon HD 7850 2GB GDDR5 DVI-I/DVI-D/HDMI/DP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026819_H
