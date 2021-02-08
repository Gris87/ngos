// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCISUBDEVICE108D0004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCISUBDEVICE108D0004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice108D0004: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108D0004 = 0x108D0004
};



inline const char8* enumToString(PciSubDevice108D0004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108D0004::NONE:               return "NONE";
        case PciSubDevice108D0004::SUBDEVICE_108D0004: return "SUBDEVICE_108D0004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice108D0004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice108D0004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108D0004::SUBDEVICE_108D0004: return "OC-3139/3140 RapidFire Token-Ring 16/4 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCISUBDEVICE108D0004_H
