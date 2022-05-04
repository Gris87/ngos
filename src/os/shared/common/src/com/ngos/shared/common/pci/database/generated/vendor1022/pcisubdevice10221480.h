// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10221480_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10221480_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10221480: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14627C37 = 0x14627C37,
    SUBDEVICE_15D91B95 = 0x15D91B95
};



inline const char8* enumToString(PciSubDevice10221480 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10221480::NONE:               return "NONE";
        case PciSubDevice10221480::SUBDEVICE_14627C37: return "SUBDEVICE_14627C37";
        case PciSubDevice10221480::SUBDEVICE_15D91B95: return "SUBDEVICE_15D91B95";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10221480 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10221480 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10221480::SUBDEVICE_14627C37: return "X570-A PRO motherboard";
        case PciSubDevice10221480::SUBDEVICE_15D91B95: return "H12SSL-i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10221480_H
