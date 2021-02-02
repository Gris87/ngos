// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18145360_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18145360_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18145360: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11863C05 = 0x11863C05,
    SUBDEVICE_20F4703A = 0x20F4703A
};



inline const char8* enumToString(PciSubDevice18145360 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18145360::NONE:               return "NONE";
        case PciSubDevice18145360::SUBDEVICE_11863C05: return "SUBDEVICE_11863C05";
        case PciSubDevice18145360::SUBDEVICE_20F4703A: return "SUBDEVICE_20F4703A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18145360 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18145360 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18145360::SUBDEVICE_11863C05: return "DWA-525 Wireless N 150 Desktop Adapter (rev.A2)";
        case PciSubDevice18145360::SUBDEVICE_20F4703A: return "TEW-703PI N150 Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18145360_H
