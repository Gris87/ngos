// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0034_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0034_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0034: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020B = 0x1028020B,
    SUBDEVICE_10280300 = 0x10280300,
    SUBDEVICE_1A562003 = 0x1A562003
};



inline const char8* enumToString(PciSubDevice168C0034 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0034::NONE:               return "NONE";
        case PciSubDevice168C0034::SUBDEVICE_1028020B: return "SUBDEVICE_1028020B";
        case PciSubDevice168C0034::SUBDEVICE_10280300: return "SUBDEVICE_10280300";
        case PciSubDevice168C0034::SUBDEVICE_1A562003: return "SUBDEVICE_1A562003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0034 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0034 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0034::SUBDEVICE_1028020B: return "Wireless 1601 802.11abgn Adapter";
        case PciSubDevice168C0034::SUBDEVICE_10280300: return "Wireless 1802 802.11abgn Adapter";
        case PciSubDevice168C0034::SUBDEVICE_1A562003: return "Killer Wireless-N 1202 Half-size Mini PCIe Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0034_H
