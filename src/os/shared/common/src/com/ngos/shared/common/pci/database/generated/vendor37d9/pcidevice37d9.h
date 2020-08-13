// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR37D9_PCIDEVICE37D9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR37D9_PCIDEVICE37D9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice37D9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1138 = 0x1138,
    DEVICE_1140 = 0x1140,
    DEVICE_1141 = 0x1141,
    DEVICE_1142 = 0x1142
};



inline const char8* enumToString(PciDevice37D9 device37D9) // TEST: NO
{
    // COMMON_LT((" | device37D9 = %u", device37D9)); // Commented to avoid bad looking logs



    switch (device37D9)
    {
        case PciDevice37D9::NONE:        return "NONE";
        case PciDevice37D9::DEVICE_1138: return "DEVICE_1138";
        case PciDevice37D9::DEVICE_1140: return "DEVICE_1140";
        case PciDevice37D9::DEVICE_1141: return "DEVICE_1141";
        case PciDevice37D9::DEVICE_1142: return "DEVICE_1142";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice37D9 device37D9) // TEST: NO
{
    // COMMON_LT((" | device37D9 = %u", device37D9)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device37D9, enumToString(device37D9));

    return res;
}



inline const char8* enumToHumanString(PciDevice37D9 device37D9) // TEST: NO
{
    // COMMON_LT((" | device37D9 = %u", device37D9)); // Commented to avoid bad looking logs



    switch (device37D9)
    {
        case PciDevice37D9::DEVICE_1138: return "SCHD-PH-8 Phase detector";
        case PciDevice37D9::DEVICE_1140: return "VR-12-PCI";
        case PciDevice37D9::DEVICE_1141: return "PCI-485(422)";
        case PciDevice37D9::DEVICE_1142: return "PCI-CAN2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR37D9_PCIDEVICE37D9_H
