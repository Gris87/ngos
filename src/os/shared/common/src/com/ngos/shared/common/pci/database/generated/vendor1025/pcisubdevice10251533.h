// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251533_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251533_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10251533: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B91533 = 0x10B91533
};



inline const char8* enumToString(PciSubDevice10251533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10251533::NONE:               return "NONE";
        case PciSubDevice10251533::SUBDEVICE_10B91533: return "SUBDEVICE_10B91533";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10251533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10251533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10251533::SUBDEVICE_10B91533: return "ALI M1533 Aladdin IV/V ISA South Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251533_H
