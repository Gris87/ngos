// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18A2_PCIDEVICE18A2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18A2_PCIDEVICE18A2_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18A2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice18A2 device18A2) // TEST: NO
{
    // COMMON_LT((" | device18A2 = %u", device18A2)); // Commented to avoid bad looking logs



    switch (device18A2)
    {
        case PciDevice18A2::NONE:        return "NONE";
        case PciDevice18A2::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18A2 device18A2) // TEST: NO
{
    // COMMON_LT((" | device18A2 = %u", device18A2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18A2, enumToString(device18A2));

    return res;
}



inline const char8* enumToHumanString(PciDevice18A2 device18A2) // TEST: NO
{
    // COMMON_LT((" | device18A2 = %u", device18A2)); // Commented to avoid bad looking logs



    switch (device18A2)
    {
        case PciDevice18A2::DEVICE_0002: return "VRC6016 16-Channel PCIe DVR Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18A2_PCIDEVICE18A2_H
