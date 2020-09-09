// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024171_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024171_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024171: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043C005 = 0x1043C005,
    SUBDEVICE_174B7C36 = 0x174B7C36
};



inline const char8* enumToString(PciSubDevice10024171 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024171::NONE:               return "NONE";
        case PciSubDevice10024171::SUBDEVICE_1043C005: return "SUBDEVICE_1043C005";
        case PciSubDevice10024171::SUBDEVICE_174B7C36: return "SUBDEVICE_174B7C36";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024171 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024171 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024171::SUBDEVICE_1043C005: return "A9600SE (Secondary)";
        case PciSubDevice10024171::SUBDEVICE_174B7C36: return "Radeon 9600SE 128M DDR V/D/VO (secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024171_H
