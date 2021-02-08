// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4C_PCISUBDEVICE1E4C0010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4C_PCISUBDEVICE1E4C0010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E4C0010: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1E4C0120 = 0x1E4C0120
};



inline const char8* enumToString(PciSubDevice1E4C0010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E4C0010::NONE:               return "NONE";
        case PciSubDevice1E4C0010::SUBDEVICE_1E4C0120: return "SUBDEVICE_1E4C0120";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E4C0010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E4C0010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E4C0010::SUBDEVICE_1E4C0120: return "SE120";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4C_PCISUBDEVICE1E4C0010_H
