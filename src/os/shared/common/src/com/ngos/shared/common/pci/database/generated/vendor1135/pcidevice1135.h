// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1135_PCIDEVICE1135_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1135_PCIDEVICE1135_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1135: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1135 device1135) // TEST: NO
{
    // COMMON_LT((" | device1135 = %u", device1135)); // Commented to avoid bad looking logs



    switch (device1135)
    {
        case PciDevice1135::NONE:        return "NONE";
        case PciDevice1135::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1135 device1135) // TEST: NO
{
    // COMMON_LT((" | device1135 = %u", device1135)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1135, enumToString(device1135));

    return res;
}



inline const char8* enumToHumanString(PciDevice1135 device1135) // TEST: NO
{
    // COMMON_LT((" | device1135 = %u", device1135)); // Commented to avoid bad looking logs



    switch (device1135)
    {
        case PciDevice1135::DEVICE_0001: return "Printer controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1135_PCIDEVICE1135_H
