// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE121700F7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE121700F7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice121700F7: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_1179FF50 = 0x1179FF50
};



inline const char8* enumToString(PciSubDevice121700F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121700F7::NONE:               return "NONE";
        case PciSubDevice121700F7::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice121700F7::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice121700F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice121700F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121700F7::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice121700F7::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE121700F7_H
