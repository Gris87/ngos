// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E0F0009: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1E0F0001 = 0x1E0F0001
};



inline const char8* enumToString(PciSubDevice1E0F0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E0F0009::NONE:               return "NONE";
        case PciSubDevice1E0F0009::SUBDEVICE_1E0F0001: return "SUBDEVICE_1E0F0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E0F0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E0F0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E0F0009::SUBDEVICE_1E0F0001: return "Toshiba RC500 NVMe SSD 500GB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0009_H
