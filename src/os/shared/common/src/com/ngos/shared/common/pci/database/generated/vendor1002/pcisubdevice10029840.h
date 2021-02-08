// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029840_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029840_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029840: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438623 = 0x10438623,
    SUBDEVICE_18499840 = 0x18499840
};



inline const char8* enumToString(PciSubDevice10029840 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029840::NONE:               return "NONE";
        case PciSubDevice10029840::SUBDEVICE_10438623: return "SUBDEVICE_10438623";
        case PciSubDevice10029840::SUBDEVICE_18499840: return "SUBDEVICE_18499840";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029840 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029840 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029840::SUBDEVICE_10438623: return "AM1I-A Motherboard";
        case PciSubDevice10029840::SUBDEVICE_18499840: return "QC5000-ITX/PH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029840_H
