// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168A_PCIDEVICE168A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168A_PCIDEVICE168A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice168A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2086 = 0x2086,
    DEVICE_C040 = 0xC040,
    DEVICE_C051 = 0xC051,
    DEVICE_C070 = 0xC070,
    DEVICE_C071 = 0xC071,
    DEVICE_C072 = 0xC072
};



inline const char8* enumToString(PciDevice168A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice168A::NONE:        return "NONE";
        case PciDevice168A::DEVICE_2086: return "DEVICE_2086";
        case PciDevice168A::DEVICE_C040: return "DEVICE_C040";
        case PciDevice168A::DEVICE_C051: return "DEVICE_C051";
        case PciDevice168A::DEVICE_C070: return "DEVICE_C070";
        case PciDevice168A::DEVICE_C071: return "DEVICE_C071";
        case PciDevice168A::DEVICE_C072: return "DEVICE_C072";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice168A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice168A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice168A::DEVICE_2086: return "CryptoServer Se-Series Hardware Security Module";
        case PciDevice168A::DEVICE_C040: return "CryptoServer CSe-Series Hardware Security Module";
        case PciDevice168A::DEVICE_C051: return "CryptoServer Se-Series Gen2 Hardware Security Module";
        case PciDevice168A::DEVICE_C070: return "u.trust Anchor Hardware Security Module cs7.2 Series";
        case PciDevice168A::DEVICE_C071: return "u.trust Anchor Hardware Security Module cs7.3 Series";
        case PciDevice168A::DEVICE_C072: return "u.trust Anchor Hardware Security Module cs7.3 Series Virtual Function";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168A_PCIDEVICE168A_H
