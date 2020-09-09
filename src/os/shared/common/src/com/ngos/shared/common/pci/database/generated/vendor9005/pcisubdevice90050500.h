// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050500_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050500_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050500: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101402C1 = 0x101402C1,
    SUBDEVICE_101402C2 = 0x101402C2
};



inline const char8* enumToString(PciSubDevice90050500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050500::NONE:               return "NONE";
        case PciSubDevice90050500::SUBDEVICE_101402C1: return "SUBDEVICE_101402C1";
        case PciSubDevice90050500::SUBDEVICE_101402C2: return "SUBDEVICE_101402C2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050500::SUBDEVICE_101402C1: return "PCI-X DDR 3Gb SAS Adapter (572A/572C)";
        case PciSubDevice90050500::SUBDEVICE_101402C2: return "PCI-X DDR 3Gb SAS RAID Adapter (572B/572D)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050500_H
