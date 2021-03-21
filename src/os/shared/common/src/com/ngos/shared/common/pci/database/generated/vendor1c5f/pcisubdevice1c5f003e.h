// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCISUBDEVICE1C5F003E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCISUBDEVICE1C5F003E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C5F003E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1C5F0A31 = 0x1C5F0A31,
    SUBDEVICE_1C5F0A41 = 0x1C5F0A41,
    SUBDEVICE_1C5F4A31 = 0x1C5F4A31,
    SUBDEVICE_1C5F4A41 = 0x1C5F4A41
};



inline const char8* enumToString(PciSubDevice1C5F003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5F003E::NONE:               return "NONE";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F0A31: return "SUBDEVICE_1C5F0A31";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F0A41: return "SUBDEVICE_1C5F0A41";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F4A31: return "SUBDEVICE_1C5F4A31";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F4A41: return "SUBDEVICE_1C5F4A41";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C5F003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C5F003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F0A31: return "NVMe SSD PBlaze6 6920 3840GB 2.5\" U.2";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F0A41: return "NVMe SSD PBlaze6 6920 7680GB 2.5\" U.2";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F4A31: return "NVMe SSD PBlaze6 6920 3200GB 2.5\" U.2";
        case PciSubDevice1C5F003E::SUBDEVICE_1C5F4A41: return "NVMe SSD PBlaze6 6920 6400GB 2.5\" U.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCISUBDEVICE1C5F003E_H
