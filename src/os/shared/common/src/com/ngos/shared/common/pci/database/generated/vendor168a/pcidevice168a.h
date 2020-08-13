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
    DEVICE_C051 = 0xC051
};



inline const char8* enumToString(PciDevice168A device168A) // TEST: NO
{
    // COMMON_LT((" | device168A = %u", device168A)); // Commented to avoid bad looking logs



    switch (device168A)
    {
        case PciDevice168A::NONE:        return "NONE";
        case PciDevice168A::DEVICE_2086: return "DEVICE_2086";
        case PciDevice168A::DEVICE_C040: return "DEVICE_C040";
        case PciDevice168A::DEVICE_C051: return "DEVICE_C051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice168A device168A) // TEST: NO
{
    // COMMON_LT((" | device168A = %u", device168A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device168A, enumToString(device168A));

    return res;
}



inline const char8* enumToHumanString(PciDevice168A device168A) // TEST: NO
{
    // COMMON_LT((" | device168A = %u", device168A)); // Commented to avoid bad looking logs



    switch (device168A)
    {
        case PciDevice168A::DEVICE_2086: return "CryptoServer Se-Series Hardware Security Module";
        case PciDevice168A::DEVICE_C040: return "CryptoServer CSe-Series Hardware Security Module";
        case PciDevice168A::DEVICE_C051: return "CryptoServer Se-Series Gen2 Hardware Security Module";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168A_PCIDEVICE168A_H
