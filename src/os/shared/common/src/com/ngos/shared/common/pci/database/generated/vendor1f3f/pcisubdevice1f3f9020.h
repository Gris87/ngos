// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1F3F9020: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1F3F0051 = 0x1F3F0051,
    SUBDEVICE_1F3F0052 = 0x1F3F0052,
    SUBDEVICE_1F3F00A1 = 0x1F3F00A1
};



inline const char8* enumToString(PciSubDevice1F3F9020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F9020::NONE:               return "NONE";
        case PciSubDevice1F3F9020::SUBDEVICE_1F3F0051: return "SUBDEVICE_1F3F0051";
        case PciSubDevice1F3F9020::SUBDEVICE_1F3F0052: return "SUBDEVICE_1F3F0052";
        case PciSubDevice1F3F9020::SUBDEVICE_1F3F00A1: return "SUBDEVICE_1F3F00A1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1F3F9020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1F3F9020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F9020::SUBDEVICE_1F3F0051: return "Dual Port 25GE Ethernet Network Adapter";
        case PciSubDevice1F3F9020::SUBDEVICE_1F3F0052: return "Quad Port 25GE Ethernet Network Adapter";
        case PciSubDevice1F3F9020::SUBDEVICE_1F3F00A1: return "Dual Port 100GE Ethernet Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9020_H
