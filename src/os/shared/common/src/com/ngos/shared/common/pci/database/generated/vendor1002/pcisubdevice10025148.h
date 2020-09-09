// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025148_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025148_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025148: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002010A = 0x1002010A,
    SUBDEVICE_10020152 = 0x10020152,
    SUBDEVICE_10020162 = 0x10020162,
    SUBDEVICE_10020172 = 0x10020172
};



inline const char8* enumToString(PciSubDevice10025148 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025148::NONE:               return "NONE";
        case PciSubDevice10025148::SUBDEVICE_1002010A: return "SUBDEVICE_1002010A";
        case PciSubDevice10025148::SUBDEVICE_10020152: return "SUBDEVICE_10020152";
        case PciSubDevice10025148::SUBDEVICE_10020162: return "SUBDEVICE_10020162";
        case PciSubDevice10025148::SUBDEVICE_10020172: return "SUBDEVICE_10020172";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025148 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025148 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025148::SUBDEVICE_1002010A: return "FireGL 8800 64Mb";
        case PciSubDevice10025148::SUBDEVICE_10020152: return "FireGL 8800 128Mb";
        case PciSubDevice10025148::SUBDEVICE_10020162: return "FireGL 8700 32Mb";
        case PciSubDevice10025148::SUBDEVICE_10020172: return "FireGL 8700 64Mb";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025148_H
