// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR153B_PCIDEVICE153B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR153B_PCIDEVICE153B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice153B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1144 = 0x1144,
    DEVICE_1147 = 0x1147,
    DEVICE_1158 = 0x1158
};



inline const char8* enumToString(PciDevice153B device153B) // TEST: NO
{
    // COMMON_LT((" | device153B = %u", device153B)); // Commented to avoid bad looking logs



    switch (device153B)
    {
        case PciDevice153B::NONE:        return "NONE";
        case PciDevice153B::DEVICE_1144: return "DEVICE_1144";
        case PciDevice153B::DEVICE_1147: return "DEVICE_1147";
        case PciDevice153B::DEVICE_1158: return "DEVICE_1158";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice153B device153B) // TEST: NO
{
    // COMMON_LT((" | device153B = %u", device153B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device153B, enumToString(device153B));

    return res;
}



inline const char8* enumToHumanString(PciDevice153B device153B) // TEST: NO
{
    // COMMON_LT((" | device153B = %u", device153B)); // Commented to avoid bad looking logs



    switch (device153B)
    {
        case PciDevice153B::DEVICE_1144: return "Aureon 5.1";
        case PciDevice153B::DEVICE_1147: return "Aureon 5.1 Sky";
        case PciDevice153B::DEVICE_1158: return "Philips Semiconductors SAA7134 (rev 01) [Terratec Cinergy 600 TV]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR153B_PCIDEVICE153B_H
