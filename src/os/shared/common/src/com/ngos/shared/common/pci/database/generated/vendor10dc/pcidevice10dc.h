// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DC_PCIDEVICE10DC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DC_PCIDEVICE10DC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10DC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_10DC = 0x10DC
};



inline const char8* enumToString(PciDevice10DC device10DC) // TEST: NO
{
    // COMMON_LT((" | device10DC = %u", device10DC)); // Commented to avoid bad looking logs



    switch (device10DC)
    {
        case PciDevice10DC::NONE:        return "NONE";
        case PciDevice10DC::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10DC::DEVICE_0002: return "DEVICE_0002";
        case PciDevice10DC::DEVICE_0021: return "DEVICE_0021";
        case PciDevice10DC::DEVICE_0022: return "DEVICE_0022";
        case PciDevice10DC::DEVICE_10DC: return "DEVICE_10DC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10DC device10DC) // TEST: NO
{
    // COMMON_LT((" | device10DC = %u", device10DC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10DC, enumToString(device10DC));

    return res;
}



inline const char8* enumToHumanString(PciDevice10DC device10DC) // TEST: NO
{
    // COMMON_LT((" | device10DC = %u", device10DC)); // Commented to avoid bad looking logs



    switch (device10DC)
    {
        case PciDevice10DC::DEVICE_0001: return "STAR/RD24 SCI-PCI (PMC)";
        case PciDevice10DC::DEVICE_0002: return "TAR/RD24 SCI-PCI (PMC)";
        case PciDevice10DC::DEVICE_0021: return "HIPPI destination";
        case PciDevice10DC::DEVICE_0022: return "HIPPI source";
        case PciDevice10DC::DEVICE_10DC: return "ATT2C15-3 FPGA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DC_PCIDEVICE10DC_H
