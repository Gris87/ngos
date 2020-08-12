// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCIDEVICE125D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCIDEVICE125D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice125D: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_1948 = 0x1948,
    DEVICE_1968 = 0x1968,
    DEVICE_1969 = 0x1969,
    DEVICE_1978 = 0x1978,
    DEVICE_1988 = 0x1988,
    DEVICE_1989 = 0x1989,
    DEVICE_1998 = 0x1998,
    DEVICE_1999 = 0x1999,
    DEVICE_199A = 0x199A,
    DEVICE_199B = 0x199B,
    DEVICE_2808 = 0x2808,
    DEVICE_2838 = 0x2838,
    DEVICE_2898 = 0x2898
};



inline const char8* enumToString(PciDevice125D device125D) // TEST: NO
{
    // COMMON_LT((" | device125D = %u", device125D)); // Commented to avoid bad looking logs



    switch (device125D)
    {
        case PciDevice125D::DEVICE_0000: return "DEVICE_0000";
        case PciDevice125D::DEVICE_1948: return "DEVICE_1948";
        case PciDevice125D::DEVICE_1968: return "DEVICE_1968";
        case PciDevice125D::DEVICE_1969: return "DEVICE_1969";
        case PciDevice125D::DEVICE_1978: return "DEVICE_1978";
        case PciDevice125D::DEVICE_1988: return "DEVICE_1988";
        case PciDevice125D::DEVICE_1989: return "DEVICE_1989";
        case PciDevice125D::DEVICE_1998: return "DEVICE_1998";
        case PciDevice125D::DEVICE_1999: return "DEVICE_1999";
        case PciDevice125D::DEVICE_199A: return "DEVICE_199A";
        case PciDevice125D::DEVICE_199B: return "DEVICE_199B";
        case PciDevice125D::DEVICE_2808: return "DEVICE_2808";
        case PciDevice125D::DEVICE_2838: return "DEVICE_2838";
        case PciDevice125D::DEVICE_2898: return "DEVICE_2898";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice125D device125D) // TEST: NO
{
    // COMMON_LT((" | device125D = %u", device125D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device125D, enumToString(device125D));

    return res;
}



inline const char8* enumToHumanString(PciDevice125D device125D) // TEST: NO
{
    // COMMON_LT((" | device125D = %u", device125D)); // Commented to avoid bad looking logs



    switch (device125D)
    {
        case PciDevice125D::DEVICE_0000: return "ES336H Fax Modem (Early Model)";
        case PciDevice125D::DEVICE_1948: return "ES1948 Maestro-1";
        case PciDevice125D::DEVICE_1968: return "ES1968 Maestro 2";
        case PciDevice125D::DEVICE_1969: return "ES1938/ES1946/ES1969 Solo-1 Audiodrive";
        case PciDevice125D::DEVICE_1978: return "ES1978 Maestro 2E";
        case PciDevice125D::DEVICE_1988: return "ES1988 Allegro-1";
        case PciDevice125D::DEVICE_1989: return "ESS Modem";
        case PciDevice125D::DEVICE_1998: return "ES1983S Maestro-3i PCI Audio Accelerator";
        case PciDevice125D::DEVICE_1999: return "ES1983S Maestro-3i PCI Modem Accelerator";
        case PciDevice125D::DEVICE_199A: return "ES1983S Maestro-3i PCI Audio Accelerator";
        case PciDevice125D::DEVICE_199B: return "ES1983S Maestro-3i PCI Modem Accelerator";
        case PciDevice125D::DEVICE_2808: return "ES336H Fax Modem (Later Model)";
        case PciDevice125D::DEVICE_2838: return "ES2838/2839 SuperLink Modem";
        case PciDevice125D::DEVICE_2898: return "ES2898 Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCIDEVICE125D_H
