// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10111065_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10111065_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10111065: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10690020 = 0x10690020
};



inline const char8* enumToString(PciSubDevice10111065 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10111065::NONE:               return "NONE";
        case PciSubDevice10111065::SUBDEVICE_10690020: return "SUBDEVICE_10690020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10111065 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10111065 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10111065::SUBDEVICE_10690020: return "DAC960P / DAC1164P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10111065_H
