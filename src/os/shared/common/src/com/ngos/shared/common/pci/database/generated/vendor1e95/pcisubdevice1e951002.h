// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E95_PCISUBDEVICE1E951002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E95_PCISUBDEVICE1E951002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E951002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1EA05636 = 0x1EA05636
};



inline const char8* enumToString(PciSubDevice1E951002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E951002::NONE:               return "NONE";
        case PciSubDevice1E951002::SUBDEVICE_1EA05636: return "SUBDEVICE_1EA05636";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E951002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E951002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E951002::SUBDEVICE_1EA05636: return "TP1500 Series U.2 NVMe Datacenter SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E95_PCISUBDEVICE1E951002_H
