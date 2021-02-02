// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12177130_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12177130_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12177130: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_1179FF50 = 0x1179FF50
};



inline const char8* enumToString(PciSubDevice12177130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12177130::NONE:               return "NONE";
        case PciSubDevice12177130::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice12177130::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12177130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12177130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12177130::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice12177130::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12177130_H
