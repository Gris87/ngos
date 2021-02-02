// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C243B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C243B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C5C243B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1C5C0100 = 0x1C5C0100
};



inline const char8* enumToString(PciSubDevice1C5C243B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5C243B::NONE:               return "NONE";
        case PciSubDevice1C5C243B::SUBDEVICE_1C5C0100: return "SUBDEVICE_1C5C0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C5C243B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C5C243B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5C243B::SUBDEVICE_1C5C0100: return "PE6110 NVMe Solid State Drive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C243B_H
