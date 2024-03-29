// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCISUBDEVICE10EE8019_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCISUBDEVICE10EE8019_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EE8019: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1EEC0201 = 0x1EEC0201
};



inline const char8* enumToString(PciSubDevice10EE8019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EE8019::NONE:               return "NONE";
        case PciSubDevice10EE8019::SUBDEVICE_1EEC0201: return "SUBDEVICE_1EEC0201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EE8019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EE8019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EE8019::SUBDEVICE_1EEC0201: return "VSEC10232X Dual-port 100Gb/s Etherent PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCISUBDEVICE10EE8019_H
