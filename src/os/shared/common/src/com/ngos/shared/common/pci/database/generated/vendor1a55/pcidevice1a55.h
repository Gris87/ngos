// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A55_PCIDEVICE1A55_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A55_PCIDEVICE1A55_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A55: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0030 = 0x0030,
    DEVICE_0040 = 0x0040,
    DEVICE_0050 = 0x0050,
    DEVICE_0060 = 0x0060,
    DEVICE_0061 = 0x0061,
    DEVICE_0062 = 0x0062,
    DEVICE_0063 = 0x0063,
    DEVICE_0064 = 0x0064,
    DEVICE_0065 = 0x0065,
    DEVICE_0070 = 0x0070,
    DEVICE_0090 = 0x0090
};



inline const char8* enumToString(PciDevice1A55 device1A55) // TEST: NO
{
    // COMMON_LT((" | device1A55 = %u", device1A55)); // Commented to avoid bad looking logs



    switch (device1A55)
    {
        case PciDevice1A55::NONE:        return "NONE";
        case PciDevice1A55::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1A55::DEVICE_0011: return "DEVICE_0011";
        case PciDevice1A55::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1A55::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1A55::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1A55::DEVICE_0030: return "DEVICE_0030";
        case PciDevice1A55::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1A55::DEVICE_0050: return "DEVICE_0050";
        case PciDevice1A55::DEVICE_0060: return "DEVICE_0060";
        case PciDevice1A55::DEVICE_0061: return "DEVICE_0061";
        case PciDevice1A55::DEVICE_0062: return "DEVICE_0062";
        case PciDevice1A55::DEVICE_0063: return "DEVICE_0063";
        case PciDevice1A55::DEVICE_0064: return "DEVICE_0064";
        case PciDevice1A55::DEVICE_0065: return "DEVICE_0065";
        case PciDevice1A55::DEVICE_0070: return "DEVICE_0070";
        case PciDevice1A55::DEVICE_0090: return "DEVICE_0090";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A55 device1A55) // TEST: NO
{
    // COMMON_LT((" | device1A55 = %u", device1A55)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A55, enumToString(device1A55));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A55 device1A55) // TEST: NO
{
    // COMMON_LT((" | device1A55 = %u", device1A55)); // Commented to avoid bad looking logs



    switch (device1A55)
    {
        case PciDevice1A55::DEVICE_0010: return "SDStationOEM";
        case PciDevice1A55::DEVICE_0011: return "SDStationOEM II";
        case PciDevice1A55::DEVICE_0020: return "Centaurus";
        case PciDevice1A55::DEVICE_0021: return "Centaurus II";
        case PciDevice1A55::DEVICE_0022: return "Centaurus II LT";
        case PciDevice1A55::DEVICE_0030: return "CLIPSTER-VPU 1.x (Hugo)";
        case PciDevice1A55::DEVICE_0040: return "Hydra Cinema (JPEG)";
        case PciDevice1A55::DEVICE_0050: return "CLIPSTER-VPU 2.x (DigiLab)";
        case PciDevice1A55::DEVICE_0060: return "CLIPSTER-DCI 2.x (HydraX)";
        case PciDevice1A55::DEVICE_0061: return "Atomix";
        case PciDevice1A55::DEVICE_0062: return "Atomix LT";
        case PciDevice1A55::DEVICE_0063: return "Atomix HDMI";
        case PciDevice1A55::DEVICE_0064: return "Atomix STAN";
        case PciDevice1A55::DEVICE_0065: return "Atomix HDMI STAN";
        case PciDevice1A55::DEVICE_0070: return "RED Rocket";
        case PciDevice1A55::DEVICE_0090: return "CinePlay";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A55_PCIDEVICE1A55_H
