// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026811_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026811_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026811: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280B00 = 0x10280B00,
    SUBDEVICE_10432016 = 0x10432016,
    SUBDEVICE_14582016 = 0x14582016,
    SUBDEVICE_14622016 = 0x14622016,
    SUBDEVICE_14623050 = 0x14623050,
    SUBDEVICE_148C2016 = 0x148C2016,
    SUBDEVICE_16822015 = 0x16822015,
    SUBDEVICE_174B2015 = 0x174B2015,
    SUBDEVICE_174B2016 = 0x174B2016,
    SUBDEVICE_17872016 = 0x17872016
};



inline const char8* enumToString(PciSubDevice10026811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026811::NONE:               return "NONE";
        case PciSubDevice10026811::SUBDEVICE_10280B00: return "SUBDEVICE_10280B00";
        case PciSubDevice10026811::SUBDEVICE_10432016: return "SUBDEVICE_10432016";
        case PciSubDevice10026811::SUBDEVICE_14582016: return "SUBDEVICE_14582016";
        case PciSubDevice10026811::SUBDEVICE_14622016: return "SUBDEVICE_14622016";
        case PciSubDevice10026811::SUBDEVICE_14623050: return "SUBDEVICE_14623050";
        case PciSubDevice10026811::SUBDEVICE_148C2016: return "SUBDEVICE_148C2016";
        case PciSubDevice10026811::SUBDEVICE_16822015: return "SUBDEVICE_16822015";
        case PciSubDevice10026811::SUBDEVICE_174B2015: return "SUBDEVICE_174B2015";
        case PciSubDevice10026811::SUBDEVICE_174B2016: return "SUBDEVICE_174B2016";
        case PciSubDevice10026811::SUBDEVICE_17872016: return "SUBDEVICE_17872016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026811::SUBDEVICE_10280B00: return "Trinidad PRO [Radeon R9 370 OEM]";
        case PciSubDevice10026811::SUBDEVICE_10432016: return "Trinidad PRO [Radeon R9 370 OEM]";
        case PciSubDevice10026811::SUBDEVICE_14582016: return "Trinidad PRO [Radeon R9 370 OEM]";
        case PciSubDevice10026811::SUBDEVICE_14622016: return "Trinidad PRO [Radeon R9 370 OEM]";
        case PciSubDevice10026811::SUBDEVICE_14623050: return "R9 270 Gaming OC";
        case PciSubDevice10026811::SUBDEVICE_148C2016: return "Trinidad PRO [Radeon R9 370 OEM]";
        case PciSubDevice10026811::SUBDEVICE_16822015: return "Trinidad PRO [Radeon R7 370]";
        case PciSubDevice10026811::SUBDEVICE_174B2015: return "NITRO Radeon R7 370";
        case PciSubDevice10026811::SUBDEVICE_174B2016: return "Trinidad PRO [Radeon R9 370 OEM]";
        case PciSubDevice10026811::SUBDEVICE_17872016: return "Trinidad PRO [Radeon R9 370 OEM]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026811_H
