// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778030_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778030_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10778030: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770243 = 0x10770243,
    SUBDEVICE_10770246 = 0x10770246
};



inline const char8* enumToString(PciSubDevice10778030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778030::NONE:               return "NONE";
        case PciSubDevice10778030::SUBDEVICE_10770243: return "SUBDEVICE_10770243";
        case PciSubDevice10778030::SUBDEVICE_10770246: return "SUBDEVICE_10770246";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10778030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10778030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778030::SUBDEVICE_10770243: return "8300 Series Single Port 10GbE Converged Network Adapter (TCP/IP Networking)";
        case PciSubDevice10778030::SUBDEVICE_10770246: return "8300 Series Dual Port 10GbE Converged Network Adapter (TCP/IP Networking)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778030_H
