// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9412_PCIDEVICE9412_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9412_PCIDEVICE9412_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9412: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6565 = 0x6565
};



inline const char8* enumToString(PciDevice9412 device9412) // TEST: NO
{
    // COMMON_LT((" | device9412 = %u", device9412)); // Commented to avoid bad looking logs



    switch (device9412)
    {
        case PciDevice9412::NONE:        return "NONE";
        case PciDevice9412::DEVICE_6565: return "DEVICE_6565";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9412 device9412) // TEST: NO
{
    // COMMON_LT((" | device9412 = %u", device9412)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device9412, enumToString(device9412));

    return res;
}



inline const char8* enumToHumanString(PciDevice9412 device9412) // TEST: NO
{
    // COMMON_LT((" | device9412 = %u", device9412)); // Commented to avoid bad looking logs



    switch (device9412)
    {
        case PciDevice9412::DEVICE_6565: return "6565";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9412_PCIDEVICE9412_H
