// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B2D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B2D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B2D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_144DC06A = 0x144DC06A,
    SUBDEVICE_17C010D2 = 0x17C010D2,
    SUBDEVICE_E4BF50C1 = 0xE4BF50C1
};



inline const char8* enumToString(PciSubDevice80863B2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B2D::NONE:               return "NONE";
        case PciSubDevice80863B2D::SUBDEVICE_144DC06A: return "SUBDEVICE_144DC06A";
        case PciSubDevice80863B2D::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";
        case PciSubDevice80863B2D::SUBDEVICE_E4BF50C1: return "SUBDEVICE_E4BF50C1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B2D::SUBDEVICE_144DC06A: return "R730 Laptop";
        case PciSubDevice80863B2D::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";
        case PciSubDevice80863B2D::SUBDEVICE_E4BF50C1: return "PC1-GROOVE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B2D_H
