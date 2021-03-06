// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862500_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862500_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862500: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280095 = 0x10280095,
    SUBDEVICE_1043801C = 0x1043801C
};



inline const char8* enumToString(PciSubDevice80862500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862500::NONE:               return "NONE";
        case PciSubDevice80862500::SUBDEVICE_10280095: return "SUBDEVICE_10280095";
        case PciSubDevice80862500::SUBDEVICE_1043801C: return "SUBDEVICE_1043801C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862500::SUBDEVICE_10280095: return "Precision Workstation 220 Chipset";
        case PciSubDevice80862500::SUBDEVICE_1043801C: return "P3C-2000 system chipset";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862500_H
