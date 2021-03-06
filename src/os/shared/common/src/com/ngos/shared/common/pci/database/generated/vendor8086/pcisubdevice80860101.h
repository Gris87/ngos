// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860101: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804B2 = 0x102804B2,
    SUBDEVICE_106B00DC = 0x106B00DC,
    SUBDEVICE_144DC652 = 0x144DC652
};



inline const char8* enumToString(PciSubDevice80860101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860101::NONE:               return "NONE";
        case PciSubDevice80860101::SUBDEVICE_102804B2: return "SUBDEVICE_102804B2";
        case PciSubDevice80860101::SUBDEVICE_106B00DC: return "SUBDEVICE_106B00DC";
        case PciSubDevice80860101::SUBDEVICE_144DC652: return "SUBDEVICE_144DC652";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860101::SUBDEVICE_102804B2: return "Vostro 3350";
        case PciSubDevice80860101::SUBDEVICE_106B00DC: return "MacBookPro8, 2 [Core i7, 15\", 2011]";
        case PciSubDevice80860101::SUBDEVICE_144DC652: return "NP300E5C series laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860101_H
