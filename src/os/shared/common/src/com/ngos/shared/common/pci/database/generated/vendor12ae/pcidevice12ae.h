// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCIDEVICE12AE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCIDEVICE12AE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12AE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_00FA = 0x00FA
};



inline const char8* enumToString(PciDevice12AE device12AE) // TEST: NO
{
    // COMMON_LT((" | device12AE = %u", device12AE)); // Commented to avoid bad looking logs



    switch (device12AE)
    {
        case PciDevice12AE::NONE:        return "NONE";
        case PciDevice12AE::DEVICE_0001: return "DEVICE_0001";
        case PciDevice12AE::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12AE::DEVICE_00FA: return "DEVICE_00FA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12AE device12AE) // TEST: NO
{
    // COMMON_LT((" | device12AE = %u", device12AE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12AE, enumToString(device12AE));

    return res;
}



inline const char8* enumToHumanString(PciDevice12AE device12AE) // TEST: NO
{
    // COMMON_LT((" | device12AE = %u", device12AE)); // Commented to avoid bad looking logs



    switch (device12AE)
    {
        case PciDevice12AE::DEVICE_0001: return "AceNIC Gigabit Ethernet";
        case PciDevice12AE::DEVICE_0002: return "AceNIC Gigabit Ethernet (Copper)";
        case PciDevice12AE::DEVICE_00FA: return "Farallon PN9100-T Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCIDEVICE12AE_H
