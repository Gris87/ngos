// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953531_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953531_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10953531: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17C04083 = 0x17C04083
};



inline const char8* enumToString(PciSubDevice10953531 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10953531::NONE:               return "NONE";
        case PciSubDevice10953531::SUBDEVICE_17C04083: return "SUBDEVICE_17C04083";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10953531 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10953531 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10953531::SUBDEVICE_17C04083: return "Medion WIM 2210 Notebook PC [MD96850]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953531_H
