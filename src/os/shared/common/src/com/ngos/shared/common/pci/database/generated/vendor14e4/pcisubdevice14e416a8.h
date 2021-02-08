// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416A8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C132B = 0x103C132B,
    SUBDEVICE_10A98014 = 0x10A98014,
    SUBDEVICE_10A9801C = 0x10A9801C,
    SUBDEVICE_10B72001 = 0x10B72001
};



inline const char8* enumToString(PciSubDevice14E416A8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A8::NONE:               return "NONE";
        case PciSubDevice14E416A8::SUBDEVICE_103C132B: return "SUBDEVICE_103C132B";
        case PciSubDevice14E416A8::SUBDEVICE_10A98014: return "SUBDEVICE_10A98014";
        case PciSubDevice14E416A8::SUBDEVICE_10A9801C: return "SUBDEVICE_10A9801C";
        case PciSubDevice14E416A8::SUBDEVICE_10B72001: return "SUBDEVICE_10B72001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416A8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416A8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A8::SUBDEVICE_103C132B: return "PCI-X 1000Mbps Dual-port Built-in";
        case PciSubDevice14E416A8::SUBDEVICE_10A98014: return "Dual Port Gigabit Ethernet (PCI-X, Fiber)";
        case PciSubDevice14E416A8::SUBDEVICE_10A9801C: return "Quad Port Gigabit Ethernet (PCI-E, Fiber)";
        case PciSubDevice14E416A8::SUBDEVICE_10B72001: return "3C998-SX Dual Port 1000-SX PCI-X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A8_H
