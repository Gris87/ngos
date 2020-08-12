// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5452_PCIDEVICE5452_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5452_PCIDEVICE5452_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5452: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3443 = 0x3443
};



inline const char8* enumToString(PciDevice5452 device5452) // TEST: NO
{
    // COMMON_LT((" | device5452 = %u", device5452)); // Commented to avoid bad looking logs



    switch (device5452)
    {
        case PciDevice5452::NONE:        return "NONE";
        case PciDevice5452::DEVICE_3443: return "DEVICE_3443";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5452 device5452) // TEST: NO
{
    // COMMON_LT((" | device5452 = %u", device5452)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5452, enumToString(device5452));

    return res;
}



inline const char8* enumToHumanString(PciDevice5452 device5452) // TEST: NO
{
    // COMMON_LT((" | device5452 = %u", device5452)); // Commented to avoid bad looking logs



    switch (device5452)
    {
        case PciDevice5452::DEVICE_3443: return "RTC4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5452_PCIDEVICE5452_H
