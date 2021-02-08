// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79905_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79905_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B79905: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B71101 = 0x10B71101,
    SUBDEVICE_10B71102 = 0x10B71102,
    SUBDEVICE_10B72101 = 0x10B72101,
    SUBDEVICE_10B72102 = 0x10B72102
};



inline const char8* enumToString(PciSubDevice10B79905 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79905::NONE:               return "NONE";
        case PciSubDevice10B79905::SUBDEVICE_10B71101: return "SUBDEVICE_10B71101";
        case PciSubDevice10B79905::SUBDEVICE_10B71102: return "SUBDEVICE_10B71102";
        case PciSubDevice10B79905::SUBDEVICE_10B72101: return "SUBDEVICE_10B72101";
        case PciSubDevice10B79905::SUBDEVICE_10B72102: return "SUBDEVICE_10B72102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B79905 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B79905 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79905::SUBDEVICE_10B71101: return "3CR990-FX-95 [Typhoon Fiber 56-bit]";
        case PciSubDevice10B79905::SUBDEVICE_10B71102: return "3CR990-FX-97 [Typhoon Fiber 168-bit]";
        case PciSubDevice10B79905::SUBDEVICE_10B72101: return "3CR990-FX-95 Server [Typhoon Fiber 56-bit]";
        case PciSubDevice10B79905::SUBDEVICE_10B72102: return "3CR990-FX-97 Server [Typhoon Fiber 168-bit]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79905_H
