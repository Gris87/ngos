// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12CB_PCIDEVICE12CB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12CB_PCIDEVICE12CB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12CB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0027 = 0x0027,
    DEVICE_002E = 0x002E
};



inline const char8* enumToString(PciDevice12CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12CB::NONE:        return "NONE";
        case PciDevice12CB::DEVICE_0027: return "DEVICE_0027";
        case PciDevice12CB::DEVICE_002E: return "DEVICE_002E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12CB::DEVICE_0027: return "SC4 (StudioCard)";
        case PciDevice12CB::DEVICE_002E: return "StudioCard 2000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12CB_PCIDEVICE12CB_H
