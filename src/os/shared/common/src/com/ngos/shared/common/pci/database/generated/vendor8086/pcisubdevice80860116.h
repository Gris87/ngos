// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860116_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860116_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860116: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804DA = 0x102804DA,
    SUBDEVICE_144DC652 = 0x144DC652
};



inline const char8* enumToString(PciSubDevice80860116 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860116::NONE:               return "NONE";
        case PciSubDevice80860116::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";
        case PciSubDevice80860116::SUBDEVICE_144DC652: return "SUBDEVICE_144DC652";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860116 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860116 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860116::SUBDEVICE_102804DA: return "Vostro 3750";
        case PciSubDevice80860116::SUBDEVICE_144DC652: return "integrated HD 3000 graphics controller on NP300E5C series laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860116_H
