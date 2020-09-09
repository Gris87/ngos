// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251541_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251541_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10251541: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B91541 = 0x10B91541
};



inline const char8* enumToString(PciSubDevice10251541 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10251541::NONE:               return "NONE";
        case PciSubDevice10251541::SUBDEVICE_10B91541: return "SUBDEVICE_10B91541";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10251541 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10251541 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10251541::SUBDEVICE_10B91541: return "ALI M1541 Aladdin V/V+ AGP+PCI North Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1025_PCISUBDEVICE10251541_H
