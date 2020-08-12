// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR159B_PCIDEVICE159B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR159B_PCIDEVICE159B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice159B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4321 = 0x4321
};



inline const char8* enumToString(PciDevice159B device159B) // TEST: NO
{
    // COMMON_LT((" | device159B = %u", device159B)); // Commented to avoid bad looking logs



    switch (device159B)
    {
        case PciDevice159B::NONE:        return "NONE";
        case PciDevice159B::DEVICE_4321: return "DEVICE_4321";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice159B device159B) // TEST: NO
{
    // COMMON_LT((" | device159B = %u", device159B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device159B, enumToString(device159B));

    return res;
}



inline const char8* enumToHumanString(PciDevice159B device159B) // TEST: NO
{
    // COMMON_LT((" | device159B = %u", device159B)); // Commented to avoid bad looking logs



    switch (device159B)
    {
        case PciDevice159B::DEVICE_4321: return "StorLink SL3516 (Gemini) Host Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR159B_PCIDEVICE159B_H
