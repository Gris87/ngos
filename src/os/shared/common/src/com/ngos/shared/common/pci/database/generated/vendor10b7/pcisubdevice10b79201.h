// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79201_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79201_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B79201: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380AB = 0x104380AB
};



inline const char8* enumToString(PciSubDevice10B79201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79201::NONE:               return "NONE";
        case PciSubDevice10B79201::SUBDEVICE_104380AB: return "SUBDEVICE_104380AB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B79201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B79201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79201::SUBDEVICE_104380AB: return "A7N8X Deluxe onboard 3C920B-EMB Integrated Fast Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79201_H
