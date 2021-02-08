// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19691091_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19691091_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19691091: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10431477 = 0x10431477
};



inline const char8* enumToString(PciSubDevice19691091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19691091::NONE:               return "NONE";
        case PciSubDevice19691091::SUBDEVICE_10431477: return "SUBDEVICE_10431477";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19691091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19691091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19691091::SUBDEVICE_10431477: return "N56VZ";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19691091_H
