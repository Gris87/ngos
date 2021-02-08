// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB7042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB7042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB7042: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16B8434B = 0x16B8434B
};



inline const char8* enumToString(PciSubDevice11AB7042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB7042::NONE:               return "NONE";
        case PciSubDevice11AB7042::SUBDEVICE_16B8434B: return "SUBDEVICE_16B8434B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB7042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB7042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB7042::SUBDEVICE_16B8434B: return "Tempo SATA E4P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB7042_H
