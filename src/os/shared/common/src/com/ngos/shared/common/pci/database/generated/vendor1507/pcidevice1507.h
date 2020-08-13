// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1507_PCIDEVICE1507_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1507_PCIDEVICE1507_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1507: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0100 = 0x0100,
    DEVICE_0431 = 0x0431,
    DEVICE_4801 = 0x4801,
    DEVICE_4802 = 0x4802,
    DEVICE_4803 = 0x4803,
    DEVICE_4806 = 0x4806
};



inline const char8* enumToString(PciDevice1507 device1507) // TEST: NO
{
    // COMMON_LT((" | device1507 = %u", device1507)); // Commented to avoid bad looking logs



    switch (device1507)
    {
        case PciDevice1507::NONE:        return "NONE";
        case PciDevice1507::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1507::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1507::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1507::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1507::DEVICE_0431: return "DEVICE_0431";
        case PciDevice1507::DEVICE_4801: return "DEVICE_4801";
        case PciDevice1507::DEVICE_4802: return "DEVICE_4802";
        case PciDevice1507::DEVICE_4803: return "DEVICE_4803";
        case PciDevice1507::DEVICE_4806: return "DEVICE_4806";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1507 device1507) // TEST: NO
{
    // COMMON_LT((" | device1507 = %u", device1507)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1507, enumToString(device1507));

    return res;
}



inline const char8* enumToHumanString(PciDevice1507 device1507) // TEST: NO
{
    // COMMON_LT((" | device1507 = %u", device1507)); // Commented to avoid bad looking logs



    switch (device1507)
    {
        case PciDevice1507::DEVICE_0001: return "MPC105 [Eagle]";
        case PciDevice1507::DEVICE_0002: return "MPC106 [Grackle]";
        case PciDevice1507::DEVICE_0003: return "MPC8240 [Kahlua]";
        case PciDevice1507::DEVICE_0100: return "MC145575 [HFC-PCI]";
        case PciDevice1507::DEVICE_0431: return "KTI829c 100VG";
        case PciDevice1507::DEVICE_4801: return "Raven";
        case PciDevice1507::DEVICE_4802: return "Falcon";
        case PciDevice1507::DEVICE_4803: return "Hawk";
        case PciDevice1507::DEVICE_4806: return "CPX8216";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1507_PCIDEVICE1507_H
