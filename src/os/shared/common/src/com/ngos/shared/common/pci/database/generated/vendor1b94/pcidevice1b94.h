// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B94_PCIDEVICE1B94_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B94_PCIDEVICE1B94_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B94: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E400 = 0xE400
};



inline const char8* enumToString(PciDevice1B94 device1B94) // TEST: NO
{
    // COMMON_LT((" | device1B94 = %u", device1B94)); // Commented to avoid bad looking logs



    switch (device1B94)
    {
        case PciDevice1B94::NONE:        return "NONE";
        case PciDevice1B94::DEVICE_E400: return "DEVICE_E400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B94 device1B94) // TEST: NO
{
    // COMMON_LT((" | device1B94 = %u", device1B94)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B94, enumToString(device1B94));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B94 device1B94) // TEST: NO
{
    // COMMON_LT((" | device1B94 = %u", device1B94)); // Commented to avoid bad looking logs



    switch (device1B94)
    {
        case PciDevice1B94::DEVICE_E400: return "PX14400 Dual Xilinx Virtex5 based Digitizer";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B94_PCIDEVICE1B94_H
