// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCISUBDEVICE108E5000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCISUBDEVICE108E5000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice108E5000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108E5000 = 0x108E5000
};



inline const char8* enumToString(PciSubDevice108E5000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108E5000::NONE:               return "NONE";
        case PciSubDevice108E5000::SUBDEVICE_108E5000: return "SUBDEVICE_108E5000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice108E5000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice108E5000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108E5000::SUBDEVICE_108E5000: return "Netra AX1105-500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCISUBDEVICE108E5000_H
