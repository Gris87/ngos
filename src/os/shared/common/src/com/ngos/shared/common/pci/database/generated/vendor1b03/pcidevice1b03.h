// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B03_PCIDEVICE1B03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B03_PCIDEVICE1B03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B03: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6100 = 0x6100,
    DEVICE_7000 = 0x7000
};



inline const char8* enumToString(PciDevice1B03 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B03::NONE:        return "NONE";
        case PciDevice1B03::DEVICE_6100: return "DEVICE_6100";
        case PciDevice1B03::DEVICE_7000: return "DEVICE_7000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B03 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B03 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B03::DEVICE_6100: return "DXT/DXTPro Multiformat Broadcast HD/SD Encoder/Decoder/Transcoder";
        case PciDevice1B03::DEVICE_7000: return "D7 Multiformat Broadcast HD/SD Encoder/Decoder/Transcoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B03_PCIDEVICE1B03_H
