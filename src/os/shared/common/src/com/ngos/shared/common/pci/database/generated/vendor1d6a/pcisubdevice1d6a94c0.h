// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6A_PCISUBDEVICE1D6A94C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6A_PCISUBDEVICE1D6A94C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1D6A94C0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104387F5 = 0x104387F5
};



inline const char8* enumToString(PciSubDevice1D6A94C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1D6A94C0::NONE:               return "NONE";
        case PciSubDevice1D6A94C0::SUBDEVICE_104387F5: return "SUBDEVICE_104387F5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1D6A94C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1D6A94C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1D6A94C0::SUBDEVICE_104387F5: return "ProArt X570-CREATOR WIFI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6A_PCISUBDEVICE1D6A94C0_H
