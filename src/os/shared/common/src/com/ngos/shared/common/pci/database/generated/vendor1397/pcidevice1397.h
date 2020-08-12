// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCIDEVICE1397_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCIDEVICE1397_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1397: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_08B4 = 0x08B4,
    DEVICE_16B8 = 0x16B8,
    DEVICE_2BD0 = 0x2BD0,
    DEVICE_30B1 = 0x30B1,
    DEVICE_B700 = 0xB700,
    DEVICE_F001 = 0xF001
};



inline const char8* enumToString(PciDevice1397 device1397) // TEST: NO
{
    // COMMON_LT((" | device1397 = %u", device1397)); // Commented to avoid bad looking logs



    switch (device1397)
    {
        case PciDevice1397::NONE:        return "NONE";
        case PciDevice1397::DEVICE_08B4: return "DEVICE_08B4";
        case PciDevice1397::DEVICE_16B8: return "DEVICE_16B8";
        case PciDevice1397::DEVICE_2BD0: return "DEVICE_2BD0";
        case PciDevice1397::DEVICE_30B1: return "DEVICE_30B1";
        case PciDevice1397::DEVICE_B700: return "DEVICE_B700";
        case PciDevice1397::DEVICE_F001: return "DEVICE_F001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1397 device1397) // TEST: NO
{
    // COMMON_LT((" | device1397 = %u", device1397)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1397, enumToString(device1397));

    return res;
}



inline const char8* enumToHumanString(PciDevice1397 device1397) // TEST: NO
{
    // COMMON_LT((" | device1397 = %u", device1397)); // Commented to avoid bad looking logs



    switch (device1397)
    {
        case PciDevice1397::DEVICE_08B4: return "ISDN network Controller [HFC-4S]";
        case PciDevice1397::DEVICE_16B8: return "ISDN network Controller [HFC-8S]";
        case PciDevice1397::DEVICE_2BD0: return "ISDN network controller [HFC-PCI]";
        case PciDevice1397::DEVICE_30B1: return "ISDN network Controller [HFC-E1]";
        case PciDevice1397::DEVICE_B700: return "ISDN network controller PrimuX S0 [HFC-PCI]";
        case PciDevice1397::DEVICE_F001: return "GSM Network Controller [HFC-4GSM]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCIDEVICE1397_H
