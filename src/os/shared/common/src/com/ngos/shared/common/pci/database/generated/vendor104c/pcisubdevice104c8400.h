// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8400_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8400_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8400: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11863B00 = 0x11863B00,
    SUBDEVICE_11863B01 = 0x11863B01,
    SUBDEVICE_13952201 = 0x13952201,
    SUBDEVICE_16AB8501 = 0x16AB8501
};



inline const char8* enumToString(PciSubDevice104C8400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8400::NONE:               return "NONE";
        case PciSubDevice104C8400::SUBDEVICE_11863B00: return "SUBDEVICE_11863B00";
        case PciSubDevice104C8400::SUBDEVICE_11863B01: return "SUBDEVICE_11863B01";
        case PciSubDevice104C8400::SUBDEVICE_13952201: return "SUBDEVICE_13952201";
        case PciSubDevice104C8400::SUBDEVICE_16AB8501: return "SUBDEVICE_16AB8501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8400::SUBDEVICE_11863B00: return "DWL-650+ PC Card cardbus 22Mbs Wireless Adapter [AirPlus]";
        case PciSubDevice104C8400::SUBDEVICE_11863B01: return "DWL-520+ 22Mbps PCI Wireless Adapter";
        case PciSubDevice104C8400::SUBDEVICE_13952201: return "WL22-PC";
        case PciSubDevice104C8400::SUBDEVICE_16AB8501: return "WL-8305 IEEE802.11b+ Wireless LAN PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8400_H
