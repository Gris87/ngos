// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AD7_PCIDEVICE1AD7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AD7_PCIDEVICE1AD7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AD7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8000 = 0x8000,
    DEVICE_9100 = 0x9100
};



inline const char8* enumToString(PciDevice1AD7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AD7::NONE:        return "NONE";
        case PciDevice1AD7::DEVICE_8000: return "DEVICE_8000";
        case PciDevice1AD7::DEVICE_9100: return "DEVICE_9100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AD7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AD7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AD7::DEVICE_8000: return "TSync-PCIe Time Code Processor";
        case PciDevice1AD7::DEVICE_9100: return "TPRO-PCI-66U Timecode Reader/Generator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AD7_PCIDEVICE1AD7_H
