// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050250_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050250_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050250: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140279 = 0x10140279,
    SUBDEVICE_1014028C = 0x1014028C,
    SUBDEVICE_1014028E = 0x1014028E
};



inline const char8* enumToString(PciSubDevice90050250 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050250::NONE:               return "NONE";
        case PciSubDevice90050250::SUBDEVICE_10140279: return "SUBDEVICE_10140279";
        case PciSubDevice90050250::SUBDEVICE_1014028C: return "SUBDEVICE_1014028C";
        case PciSubDevice90050250::SUBDEVICE_1014028E: return "SUBDEVICE_1014028E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050250 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050250 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050250::SUBDEVICE_10140279: return "ServeRAID 6M";
        case PciSubDevice90050250::SUBDEVICE_1014028C: return "ServeRAID 6i/6i+";
        case PciSubDevice90050250::SUBDEVICE_1014028E: return "ServeRAID 7k";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050250_H
