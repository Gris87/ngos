// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31019_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31019_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B31019: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15B30008 = 0x15B30008,
    SUBDEVICE_15B30125 = 0x15B30125
};



inline const char8* enumToString(PciSubDevice15B31019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31019::NONE:               return "NONE";
        case PciSubDevice15B31019::SUBDEVICE_15B30008: return "SUBDEVICE_15B30008";
        case PciSubDevice15B31019::SUBDEVICE_15B30125: return "SUBDEVICE_15B30125";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B31019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B31019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31019::SUBDEVICE_15B30008: return "ConnectX-5 Ex EN network interface card, 100GbE dual-port QSFP28, PCIe4.0 x16, tall bracket; MCX516A-CDAT";
        case PciSubDevice15B31019::SUBDEVICE_15B30125: return "Tencent ConnectX-5 EN Ex network interface card for OCP 3.0, with host management, 50GbE Dual-port QSFP28, PCIe4.0 x16, Thumbscrew (pull-tab) bracket";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31019_H
