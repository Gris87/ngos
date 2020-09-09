// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCISUBDEVICE10EE7038_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCISUBDEVICE10EE7038_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EE7038: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA402F = 0x17AA402F
};



inline const char8* enumToString(PciSubDevice10EE7038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EE7038::NONE:               return "NONE";
        case PciSubDevice10EE7038::SUBDEVICE_17AA402F: return "SUBDEVICE_17AA402F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EE7038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EE7038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EE7038::SUBDEVICE_17AA402F: return "FPGA XC7VX690T-3FFG1157E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCISUBDEVICE10EE7038_H
