// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251521_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251521_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10251521: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B91521 = 0x10B91521
};



inline const char8* enumToString(PciSubDevice10251521 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10251521::NONE:               return "NONE";
        case PciSubDevice10251521::SUBDEVICE_10B91521: return "SUBDEVICE_10B91521";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10251521 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10251521 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10251521::SUBDEVICE_10B91521: return "ALI M1521 Aladdin III CPU Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251521_H
