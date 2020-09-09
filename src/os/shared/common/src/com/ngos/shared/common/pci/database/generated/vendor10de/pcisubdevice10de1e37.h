// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1E37_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1E37_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1E37: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE1347 = 0x10DE1347,
    SUBDEVICE_10DE1348 = 0x10DE1348,
    SUBDEVICE_10DE1370 = 0x10DE1370
};



inline const char8* enumToString(PciSubDevice10DE1E37 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1E37::NONE:               return "NONE";
        case PciSubDevice10DE1E37::SUBDEVICE_10DE1347: return "SUBDEVICE_10DE1347";
        case PciSubDevice10DE1E37::SUBDEVICE_10DE1348: return "SUBDEVICE_10DE1348";
        case PciSubDevice10DE1E37::SUBDEVICE_10DE1370: return "SUBDEVICE_10DE1370";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1E37 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1E37 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1E37::SUBDEVICE_10DE1347: return "GRID RTX T10-8";
        case PciSubDevice10DE1E37::SUBDEVICE_10DE1348: return "GRID RTX T10-4";
        case PciSubDevice10DE1E37::SUBDEVICE_10DE1370: return "GRID RTX T10-16";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1E37_H
