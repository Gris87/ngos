// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79904_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79904_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B79904: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B71000 = 0x10B71000,
    SUBDEVICE_10B72000 = 0x10B72000
};



inline const char8* enumToString(PciSubDevice10B79904 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79904::NONE:               return "NONE";
        case PciSubDevice10B79904::SUBDEVICE_10B71000: return "SUBDEVICE_10B71000";
        case PciSubDevice10B79904::SUBDEVICE_10B72000: return "SUBDEVICE_10B72000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B79904 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B79904 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79904::SUBDEVICE_10B71000: return "3CR990B-TX-M [Typhoon2]";
        case PciSubDevice10B79904::SUBDEVICE_10B72000: return "3CR990BSVR [Typhoon2 Server]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79904_H
