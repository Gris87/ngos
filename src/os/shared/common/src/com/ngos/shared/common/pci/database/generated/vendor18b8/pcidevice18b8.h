// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18B8_PCIDEVICE18B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18B8_PCIDEVICE18B8_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18B8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_B001 = 0xB001
};



inline const char8* enumToString(PciDevice18B8 device18B8) // TEST: NO
{
    // COMMON_LT((" | device18B8 = %u", device18B8)); // Commented to avoid bad looking logs



    switch (device18B8)
    {
        case PciDevice18B8::NONE:        return "NONE";
        case PciDevice18B8::DEVICE_B001: return "DEVICE_B001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18B8 device18B8) // TEST: NO
{
    // COMMON_LT((" | device18B8 = %u", device18B8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18B8, enumToString(device18B8));

    return res;
}



inline const char8* enumToHumanString(PciDevice18B8 device18B8) // TEST: NO
{
    // COMMON_LT((" | device18B8 = %u", device18B8)); // Commented to avoid bad looking logs



    switch (device18B8)
    {
        case PciDevice18B8::DEVICE_B001: return "AMSO 1100 iWARP/RDMA Gigabit Ethernet Coprocessor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18B8_PCIDEVICE18B8_H
