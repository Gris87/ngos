// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0042: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11AD08A6 = 0x11AD08A6,
    SUBDEVICE_17AA0901 = 0x17AA0901
};



inline const char8* enumToString(PciSubDevice168C0042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0042::NONE:               return "NONE";
        case PciSubDevice168C0042::SUBDEVICE_11AD08A6: return "SUBDEVICE_11AD08A6";
        case PciSubDevice168C0042::SUBDEVICE_17AA0901: return "SUBDEVICE_17AA0901";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0042::SUBDEVICE_11AD08A6: return "Qualcomm Atheros QCA9377 802.11ac Wireless Network Adapter";
        case PciSubDevice168C0042::SUBDEVICE_17AA0901: return "Qualcomm Atheros QCA9377 Wireless Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0042_H
