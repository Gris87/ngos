// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59749_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59749_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59749: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1D490004 = 0x1D490004
};



inline const char8* enumToString(PciSubDevice10B59749 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59749::NONE:               return "NONE";
        case PciSubDevice10B59749::SUBDEVICE_1D490004: return "SUBDEVICE_1D490004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59749 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59749 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59749::SUBDEVICE_1D490004: return "ThinkSystem 1610-8P NVMe Switch Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59749_H
