// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCISUBDEVICE11032210_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCISUBDEVICE11032210_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11032210: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11AB11AB = 0x11AB11AB
};



inline const char8* enumToString(PciSubDevice11032210 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11032210::NONE:               return "NONE";
        case PciSubDevice11032210::SUBDEVICE_11AB11AB: return "SUBDEVICE_11AB11AB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11032210 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11032210 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11032210::SUBDEVICE_11AB11AB: return "88SX6042";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCISUBDEVICE11032210_H
