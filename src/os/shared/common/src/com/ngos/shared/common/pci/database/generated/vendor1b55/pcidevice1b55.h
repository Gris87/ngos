// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B55_PCIDEVICE1B55_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B55_PCIDEVICE1B55_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B55: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_18F6 = 0x18F6,
    DEVICE_18F7 = 0x18F7,
    DEVICE_2A2C = 0x2A2C,
    DEVICE_E2E4 = 0xE2E4,
    DEVICE_E5F4 = 0xE5F4,
    DEVICE_F1C4 = 0xF1C4
};



inline const char8* enumToString(PciDevice1B55 device1B55) // TEST: NO
{
    // COMMON_LT((" | device1B55 = %u", device1B55)); // Commented to avoid bad looking logs



    switch (device1B55)
    {
        case PciDevice1B55::NONE:        return "NONE";
        case PciDevice1B55::DEVICE_18F6: return "DEVICE_18F6";
        case PciDevice1B55::DEVICE_18F7: return "DEVICE_18F7";
        case PciDevice1B55::DEVICE_2A2C: return "DEVICE_2A2C";
        case PciDevice1B55::DEVICE_E2E4: return "DEVICE_E2E4";
        case PciDevice1B55::DEVICE_E5F4: return "DEVICE_E5F4";
        case PciDevice1B55::DEVICE_F1C4: return "DEVICE_F1C4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B55 device1B55) // TEST: NO
{
    // COMMON_LT((" | device1B55 = %u", device1B55)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B55, enumToString(device1B55));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B55 device1B55) // TEST: NO
{
    // COMMON_LT((" | device1B55 = %u", device1B55)); // Commented to avoid bad looking logs



    switch (device1B55)
    {
        case PciDevice1B55::DEVICE_18F6: return "Dual DVB Universal CI card";
        case PciDevice1B55::DEVICE_18F7: return "Dual DVB Universal CI card rev 1.4";
        case PciDevice1B55::DEVICE_2A2C: return "Dual DVB-S2-CI card";
        case PciDevice1B55::DEVICE_E2E4: return "Dual DVB-T/C-CI RF card";
        case PciDevice1B55::DEVICE_E5F4: return "MPEG2 and H264 Encoder-Transcoder";
        case PciDevice1B55::DEVICE_F1C4: return "Dual ASI-RX/TX-CI card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B55_PCIDEVICE1B55_H
