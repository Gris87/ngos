// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101402BD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101402BD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101402BD: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101402C1 = 0x101402C1,
    SUBDEVICE_101402C2 = 0x101402C2,
    SUBDEVICE_10140338 = 0x10140338
};



inline const char8* enumToString(PciSubDevice101402BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101402BD::NONE:               return "NONE";
        case PciSubDevice101402BD::SUBDEVICE_101402C1: return "SUBDEVICE_101402C1";
        case PciSubDevice101402BD::SUBDEVICE_101402C2: return "SUBDEVICE_101402C2";
        case PciSubDevice101402BD::SUBDEVICE_10140338: return "SUBDEVICE_10140338";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101402BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101402BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101402BD::SUBDEVICE_101402C1: return "PCI-X DDR 3Gb SAS Adapter (572A/572C)";
        case PciSubDevice101402BD::SUBDEVICE_101402C2: return "PCI-X DDR 3Gb SAS RAID Adapter (572B/571D)";
        case PciSubDevice101402BD::SUBDEVICE_10140338: return "PCI-X DDR Auxiliary Cache Adapter (575C)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101402BD_H
