// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCISUBDEVICE108E1103_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCISUBDEVICE108E1103_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice108E1103: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108E1103 = 0x108E1103
};



inline const char8* enumToString(PciSubDevice108E1103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108E1103::NONE:               return "NONE";
        case PciSubDevice108E1103::SUBDEVICE_108E1103: return "SUBDEVICE_108E1103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice108E1103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice108E1103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108E1103::SUBDEVICE_108E1103: return "RIO USB on Blade 100 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCISUBDEVICE108E1103_H
