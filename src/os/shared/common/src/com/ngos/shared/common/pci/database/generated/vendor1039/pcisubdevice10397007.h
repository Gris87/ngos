// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10397007: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1462701D = 0x1462701D
};



inline const char8* enumToString(PciSubDevice10397007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397007::NONE:               return "NONE";
        case PciSubDevice10397007::SUBDEVICE_1462701D: return "SUBDEVICE_1462701D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10397007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10397007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397007::SUBDEVICE_1462701D: return "MS-6701";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397007_H
