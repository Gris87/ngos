// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C2849_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C2849_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C5C2849: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1C5C0101 = 0x1C5C0101
};



inline const char8* enumToString(PciSubDevice1C5C2849 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5C2849::NONE:               return "NONE";
        case PciSubDevice1C5C2849::SUBDEVICE_1C5C0101: return "SUBDEVICE_1C5C0101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C5C2849 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C5C2849 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5C2849::SUBDEVICE_1C5C0101: return "PE81x0 U.2/3 NVMe Solid State Drive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C2849_H
