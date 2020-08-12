// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9618_PCIDEVICE9618_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9618_PCIDEVICE9618_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9618: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice9618 device9618) // TEST: NO
{
    // COMMON_LT((" | device9618 = %u", device9618)); // Commented to avoid bad looking logs



    switch (device9618)
    {
        case PciDevice9618::NONE:        return "NONE";
        case PciDevice9618::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9618 device9618) // TEST: NO
{
    // COMMON_LT((" | device9618 = %u", device9618)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device9618, enumToString(device9618));

    return res;
}



inline const char8* enumToHumanString(PciDevice9618 device9618) // TEST: NO
{
    // COMMON_LT((" | device9618 = %u", device9618)); // Commented to avoid bad looking logs



    switch (device9618)
    {
        case PciDevice9618::DEVICE_0001: return "JusonTech Gigabit Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9618_PCIDEVICE9618_H
