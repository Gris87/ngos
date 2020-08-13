// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCIDEVICE1966_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCIDEVICE1966_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1966: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1975 = 0x1975,
    DEVICE_1977 = 0x1977,
    DEVICE_1979 = 0x1979,
    DEVICE_1980 = 0x1980
};



inline const char8* enumToString(PciDevice1966 device1966) // TEST: NO
{
    // COMMON_LT((" | device1966 = %u", device1966)); // Commented to avoid bad looking logs



    switch (device1966)
    {
        case PciDevice1966::NONE:        return "NONE";
        case PciDevice1966::DEVICE_1975: return "DEVICE_1975";
        case PciDevice1966::DEVICE_1977: return "DEVICE_1977";
        case PciDevice1966::DEVICE_1979: return "DEVICE_1979";
        case PciDevice1966::DEVICE_1980: return "DEVICE_1980";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1966 device1966) // TEST: NO
{
    // COMMON_LT((" | device1966 = %u", device1966)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1966, enumToString(device1966));

    return res;
}



inline const char8* enumToHumanString(PciDevice1966 device1966) // TEST: NO
{
    // COMMON_LT((" | device1966 = %u", device1966)); // Commented to avoid bad looking logs



    switch (device1966)
    {
        case PciDevice1966::DEVICE_1975: return "DVG64 family";
        case PciDevice1966::DEVICE_1977: return "DVG128 family";
        case PciDevice1966::DEVICE_1979: return "3DVG/UHD3";
        case PciDevice1966::DEVICE_1980: return "HDV2/UHD2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCIDEVICE1966_H
