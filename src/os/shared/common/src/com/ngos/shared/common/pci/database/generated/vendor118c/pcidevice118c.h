// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR118C_PCIDEVICE118C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR118C_PCIDEVICE118C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice118C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0014 = 0x0014,
    DEVICE_1117 = 0x1117
};



inline const char8* enumToString(PciDevice118C device118C) // TEST: NO
{
    // COMMON_LT((" | device118C = %u", device118C)); // Commented to avoid bad looking logs



    switch (device118C)
    {
        case PciDevice118C::NONE:        return "NONE";
        case PciDevice118C::DEVICE_0014: return "DEVICE_0014";
        case PciDevice118C::DEVICE_1117: return "DEVICE_1117";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice118C device118C) // TEST: NO
{
    // COMMON_LT((" | device118C = %u", device118C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device118C, enumToString(device118C));

    return res;
}



inline const char8* enumToHumanString(PciDevice118C device118C) // TEST: NO
{
    // COMMON_LT((" | device118C = %u", device118C)); // Commented to avoid bad looking logs



    switch (device118C)
    {
        case PciDevice118C::DEVICE_0014: return "PCIB [C-bus II to PCI bus host bridge chip]";
        case PciDevice118C::DEVICE_1117: return "Intel 8-way XEON Profusion Chipset [Cache Coherency Filter]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR118C_PCIDEVICE118C_H
