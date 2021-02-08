// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE1073000C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE1073000C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1073000C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107A000C = 0x107A000C
};



inline const char8* enumToString(PciSubDevice1073000C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1073000C::NONE:               return "NONE";
        case PciSubDevice1073000C::SUBDEVICE_107A000C: return "SUBDEVICE_107A000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1073000C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1073000C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1073000C::SUBDEVICE_107A000C: return "DS-XG PCI Audio CODEC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE1073000C_H
