// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4355_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4355_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4355: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1179FF50 = 0x1179FF50
};



inline const char8* enumToString(PciSubDevice11AB4355 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4355::NONE:               return "NONE";
        case PciSubDevice11AB4355::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4355 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4355 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4355::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4355_H
