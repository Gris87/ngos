// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1532_PCIDEVICE1532_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1532_PCIDEVICE1532_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1532: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0020 = 0x0020
};



inline const char8* enumToString(PciDevice1532 device1532) // TEST: NO
{
    // COMMON_LT((" | device1532 = %u", device1532)); // Commented to avoid bad looking logs



    switch (device1532)
    {
        case PciDevice1532::NONE:        return "NONE";
        case PciDevice1532::DEVICE_0020: return "DEVICE_0020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1532 device1532) // TEST: NO
{
    // COMMON_LT((" | device1532 = %u", device1532)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1532, enumToString(device1532));

    return res;
}



inline const char8* enumToHumanString(PciDevice1532 device1532) // TEST: NO
{
    // COMMON_LT((" | device1532 = %u", device1532)); // Commented to avoid bad looking logs



    switch (device1532)
    {
        case PciDevice1532::DEVICE_0020: return "LonWorks PCLTA-20 PCI LonTalk Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1532_PCIDEVICE1532_H
