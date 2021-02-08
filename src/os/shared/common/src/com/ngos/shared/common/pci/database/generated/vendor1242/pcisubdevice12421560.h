// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1242_PCISUBDEVICE12421560_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1242_PCISUBDEVICE12421560_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12421560: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12426562 = 0x12426562,
    SUBDEVICE_1242656A = 0x1242656A
};



inline const char8* enumToString(PciSubDevice12421560 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12421560::NONE:               return "NONE";
        case PciSubDevice12421560::SUBDEVICE_12426562: return "SUBDEVICE_12426562";
        case PciSubDevice12421560::SUBDEVICE_1242656A: return "SUBDEVICE_1242656A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12421560 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12421560 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12421560::SUBDEVICE_12426562: return "FCX2-6562 Dual Channel PCI-X Fibre Channel Adapter";
        case PciSubDevice12421560::SUBDEVICE_1242656A: return "FCX-6562 PCI-X Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1242_PCISUBDEVICE12421560_H
