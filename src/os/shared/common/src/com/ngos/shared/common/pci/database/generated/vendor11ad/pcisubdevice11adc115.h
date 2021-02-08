// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCISUBDEVICE11ADC115_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCISUBDEVICE11ADC115_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11ADC115: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11ADC001 = 0x11ADC001,
    SUBDEVICE_2646000B = 0x2646000B
};



inline const char8* enumToString(PciSubDevice11ADC115 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11ADC115::NONE:               return "NONE";
        case PciSubDevice11ADC115::SUBDEVICE_11ADC001: return "SUBDEVICE_11ADC001";
        case PciSubDevice11ADC115::SUBDEVICE_2646000B: return "SUBDEVICE_2646000B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11ADC115 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11ADC115 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11ADC115::SUBDEVICE_11ADC001: return "LNE100TX [ver 2.0]";
        case PciSubDevice11ADC115::SUBDEVICE_2646000B: return "KNE111TX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCISUBDEVICE11ADC115_H
