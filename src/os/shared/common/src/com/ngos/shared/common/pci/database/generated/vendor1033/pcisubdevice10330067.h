// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330067_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330067_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10330067: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10100020 = 0x10100020,
    SUBDEVICE_10100080 = 0x10100080,
    SUBDEVICE_10100088 = 0x10100088,
    SUBDEVICE_10100090 = 0x10100090,
    SUBDEVICE_10100098 = 0x10100098,
    SUBDEVICE_101000A0 = 0x101000A0,
    SUBDEVICE_101000A8 = 0x101000A8,
    SUBDEVICE_10100120 = 0x10100120
};



inline const char8* enumToString(PciSubDevice10330067 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330067::NONE:               return "NONE";
        case PciSubDevice10330067::SUBDEVICE_10100020: return "SUBDEVICE_10100020";
        case PciSubDevice10330067::SUBDEVICE_10100080: return "SUBDEVICE_10100080";
        case PciSubDevice10330067::SUBDEVICE_10100088: return "SUBDEVICE_10100088";
        case PciSubDevice10330067::SUBDEVICE_10100090: return "SUBDEVICE_10100090";
        case PciSubDevice10330067::SUBDEVICE_10100098: return "SUBDEVICE_10100098";
        case PciSubDevice10330067::SUBDEVICE_101000A0: return "SUBDEVICE_101000A0";
        case PciSubDevice10330067::SUBDEVICE_101000A8: return "SUBDEVICE_101000A8";
        case PciSubDevice10330067::SUBDEVICE_10100120: return "SUBDEVICE_10100120";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10330067 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10330067 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330067::SUBDEVICE_10100020: return "PowerVR Neon 250 AGP 32Mb";
        case PciSubDevice10330067::SUBDEVICE_10100080: return "PowerVR Neon 250 AGP 16Mb";
        case PciSubDevice10330067::SUBDEVICE_10100088: return "PowerVR Neon 250 16Mb";
        case PciSubDevice10330067::SUBDEVICE_10100090: return "PowerVR Neon 250 AGP 16Mb";
        case PciSubDevice10330067::SUBDEVICE_10100098: return "PowerVR Neon 250 16Mb";
        case PciSubDevice10330067::SUBDEVICE_101000A0: return "PowerVR Neon 250 AGP 32Mb";
        case PciSubDevice10330067::SUBDEVICE_101000A8: return "PowerVR Neon 250 32Mb";
        case PciSubDevice10330067::SUBDEVICE_10100120: return "PowerVR Neon 250 AGP 32Mb";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330067_H
