// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020009: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020010 = 0x11020010,
    SUBDEVICE_11020018 = 0x11020018
};



inline const char8* enumToString(PciSubDevice11020009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020009::NONE:               return "NONE";
        case PciSubDevice11020009::SUBDEVICE_11020010: return "SUBDEVICE_11020010";
        case PciSubDevice11020009::SUBDEVICE_11020018: return "SUBDEVICE_11020018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020009::SUBDEVICE_11020010: return "MB0820 Integrated";
        case PciSubDevice11020009::SUBDEVICE_11020018: return "SB1040 PCI Express";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020009_H
