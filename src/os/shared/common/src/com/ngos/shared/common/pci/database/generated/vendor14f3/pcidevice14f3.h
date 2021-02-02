// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F3_PCIDEVICE14F3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F3_PCIDEVICE14F3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14F3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2030 = 0x2030,
    DEVICE_2035 = 0x2035,
    DEVICE_2050 = 0x2050,
    DEVICE_2060 = 0x2060
};



inline const char8* enumToString(PciDevice14F3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14F3::NONE:        return "NONE";
        case PciDevice14F3::DEVICE_2030: return "DEVICE_2030";
        case PciDevice14F3::DEVICE_2035: return "DEVICE_2035";
        case PciDevice14F3::DEVICE_2050: return "DEVICE_2050";
        case PciDevice14F3::DEVICE_2060: return "DEVICE_2060";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14F3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14F3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14F3::DEVICE_2030: return "2030 DVB-S Satellite Receiver";
        case PciDevice14F3::DEVICE_2035: return "2035 DVB-S Satellite Receiver";
        case PciDevice14F3::DEVICE_2050: return "2050 DVB-T Terrestrial (Cable) Receiver";
        case PciDevice14F3::DEVICE_2060: return "2060 ATSC Terrestrial (Cable) Receiver";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F3_PCIDEVICE14F3_H
