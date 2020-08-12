// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ADE_PCIDEVICE1ADE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ADE_PCIDEVICE1ADE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1ADE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1501 = 0x1501,
    DEVICE_3038 = 0x3038
};



inline const char8* enumToString(PciDevice1ADE device1ADE) // TEST: NO
{
    // COMMON_LT((" | device1ADE = %u", device1ADE)); // Commented to avoid bad looking logs



    switch (device1ADE)
    {
        case PciDevice1ADE::NONE:        return "NONE";
        case PciDevice1ADE::DEVICE_1501: return "DEVICE_1501";
        case PciDevice1ADE::DEVICE_3038: return "DEVICE_3038";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1ADE device1ADE) // TEST: NO
{
    // COMMON_LT((" | device1ADE = %u", device1ADE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1ADE, enumToString(device1ADE));

    return res;
}



inline const char8* enumToHumanString(PciDevice1ADE device1ADE) // TEST: NO
{
    // COMMON_LT((" | device1ADE = %u", device1ADE)); // Commented to avoid bad looking logs



    switch (device1ADE)
    {
        case PciDevice1ADE::DEVICE_1501: return "Swipetech barcode scanner";
        case PciDevice1ADE::DEVICE_3038: return "PCIe Video Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ADE_PCIDEVICE1ADE_H
