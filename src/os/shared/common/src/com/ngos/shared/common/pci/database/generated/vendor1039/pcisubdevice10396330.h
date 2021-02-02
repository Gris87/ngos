// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396330_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396330_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10396330: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10396330 = 0x10396330,
    SUBDEVICE_10438113 = 0x10438113,
    SUBDEVICE_1458D000 = 0x1458D000,
    SUBDEVICE_17341099 = 0x17341099
};



inline const char8* enumToString(PciSubDevice10396330 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396330::NONE:               return "NONE";
        case PciSubDevice10396330::SUBDEVICE_10396330: return "SUBDEVICE_10396330";
        case PciSubDevice10396330::SUBDEVICE_10438113: return "SUBDEVICE_10438113";
        case PciSubDevice10396330::SUBDEVICE_1458D000: return "SUBDEVICE_1458D000";
        case PciSubDevice10396330::SUBDEVICE_17341099: return "SUBDEVICE_17341099";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10396330 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10396330 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396330::SUBDEVICE_10396330: return "[M]661xX/[M]741[GX]/[M]760 PCI/AGP VGA Adapter";
        case PciSubDevice10396330::SUBDEVICE_10438113: return "SiS Real 256E (ASUS P5S800-VM motherboard)";
        case PciSubDevice10396330::SUBDEVICE_1458D000: return "SiS661FX GUI 2D/3D Accelerator";
        case PciSubDevice10396330::SUBDEVICE_17341099: return "D2030-A1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396330_H
