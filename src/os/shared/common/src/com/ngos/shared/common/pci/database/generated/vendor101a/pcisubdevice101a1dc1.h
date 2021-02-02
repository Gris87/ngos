// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A1DC1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A1DC1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101A1DC1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101A0019 = 0x101A0019,
    SUBDEVICE_101A001F = 0x101A001F,
    SUBDEVICE_101A0ECE = 0x101A0ECE
};



inline const char8* enumToString(PciSubDevice101A1DC1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101A1DC1::NONE:               return "NONE";
        case PciSubDevice101A1DC1::SUBDEVICE_101A0019: return "SUBDEVICE_101A0019";
        case PciSubDevice101A1DC1::SUBDEVICE_101A001F: return "SUBDEVICE_101A001F";
        case PciSubDevice101A1DC1::SUBDEVICE_101A0ECE: return "SUBDEVICE_101A0ECE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101A1DC1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101A1DC1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101A1DC1::SUBDEVICE_101A0019: return "BIC2M";
        case PciSubDevice101A1DC1::SUBDEVICE_101A001F: return "BIC4M";
        case PciSubDevice101A1DC1::SUBDEVICE_101A0ECE: return "BYA4M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A1DC1_H
