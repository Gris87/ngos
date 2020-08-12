// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD4_PCIDEVICE1BD4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD4_PCIDEVICE1BD4_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BD4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0911 = 0x0911
};



inline const char8* enumToString(PciDevice1BD4 device1BD4) // TEST: NO
{
    // COMMON_LT((" | device1BD4 = %u", device1BD4)); // Commented to avoid bad looking logs



    switch (device1BD4)
    {
        case PciDevice1BD4::NONE:        return "NONE";
        case PciDevice1BD4::DEVICE_0911: return "DEVICE_0911";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BD4 device1BD4) // TEST: NO
{
    // COMMON_LT((" | device1BD4 = %u", device1BD4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1BD4, enumToString(device1BD4));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BD4 device1BD4) // TEST: NO
{
    // COMMON_LT((" | device1BD4 = %u", device1BD4)); // Commented to avoid bad looking logs



    switch (device1BD4)
    {
        case PciDevice1BD4::DEVICE_0911: return "Arria10_PCIe_F10A1150";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BD4_PCIDEVICE1BD4_H
