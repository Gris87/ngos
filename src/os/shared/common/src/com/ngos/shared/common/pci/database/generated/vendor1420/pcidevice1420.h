// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1420_PCIDEVICE1420_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1420_PCIDEVICE1420_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1420: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8002 = 0x8002,
    DEVICE_8003 = 0x8003
};



inline const char8* enumToString(PciDevice1420 device1420) // TEST: NO
{
    // COMMON_LT((" | device1420 = %u", device1420)); // Commented to avoid bad looking logs



    switch (device1420)
    {
        case PciDevice1420::NONE:        return "NONE";
        case PciDevice1420::DEVICE_8002: return "DEVICE_8002";
        case PciDevice1420::DEVICE_8003: return "DEVICE_8003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1420 device1420) // TEST: NO
{
    // COMMON_LT((" | device1420 = %u", device1420)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1420, enumToString(device1420));

    return res;
}



inline const char8* enumToHumanString(PciDevice1420 device1420) // TEST: NO
{
    // COMMON_LT((" | device1420 = %u", device1420)); // Commented to avoid bad looking logs



    switch (device1420)
    {
        case PciDevice1420::DEVICE_8002: return "Gold Card NetGlobal 56k+10/100Mb CardBus (Ethernet part)";
        case PciDevice1420::DEVICE_8003: return "Gold Card NetGlobal 56k+10/100Mb CardBus (Modem part)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1420_PCIDEVICE1420_H
