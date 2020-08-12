// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR147B_PCIDEVICE147B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR147B_PCIDEVICE147B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice147B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1084 = 0x1084
};



inline const char8* enumToString(PciDevice147B device147B) // TEST: NO
{
    // COMMON_LT((" | device147B = %u", device147B)); // Commented to avoid bad looking logs



    switch (device147B)
    {
        case PciDevice147B::NONE:        return "NONE";
        case PciDevice147B::DEVICE_1084: return "DEVICE_1084";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice147B device147B) // TEST: NO
{
    // COMMON_LT((" | device147B = %u", device147B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device147B, enumToString(device147B));

    return res;
}



inline const char8* enumToHumanString(PciDevice147B device147B) // TEST: NO
{
    // COMMON_LT((" | device147B = %u", device147B)); // Commented to avoid bad looking logs



    switch (device147B)
    {
        case PciDevice147B::DEVICE_1084: return "IP35 [Dark Raider]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR147B_PCIDEVICE147B_H
