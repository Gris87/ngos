// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E013: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11331300 = 0x11331300,
    SUBDEVICE_1133E013 = 0x1133E013
};



inline const char8* enumToString(PciSubDevice1133E013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E013::NONE:               return "NONE";
        case PciSubDevice1133E013::SUBDEVICE_11331300: return "SUBDEVICE_11331300";
        case PciSubDevice1133E013::SUBDEVICE_1133E013: return "SUBDEVICE_1133E013";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E013::SUBDEVICE_11331300: return "Diva V-4BRI-8 PCI v2";
        case PciSubDevice1133E013::SUBDEVICE_1133E013: return "Diva 4BRI-8 PCI v2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E013_H
