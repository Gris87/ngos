// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1278_PCIDEVICE1278_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1278_PCIDEVICE1278_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1278: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0701 = 0x0701,
    DEVICE_0710 = 0x0710,
    DEVICE_1100 = 0x1100,
    DEVICE_1101 = 0x1101
};



inline const char8* enumToString(PciDevice1278 device1278) // TEST: NO
{
    // COMMON_LT((" | device1278 = %u", device1278)); // Commented to avoid bad looking logs



    switch (device1278)
    {
        case PciDevice1278::NONE:        return "NONE";
        case PciDevice1278::DEVICE_0701: return "DEVICE_0701";
        case PciDevice1278::DEVICE_0710: return "DEVICE_0710";
        case PciDevice1278::DEVICE_1100: return "DEVICE_1100";
        case PciDevice1278::DEVICE_1101: return "DEVICE_1101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1278 device1278) // TEST: NO
{
    // COMMON_LT((" | device1278 = %u", device1278)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1278, enumToString(device1278));

    return res;
}



inline const char8* enumToHumanString(PciDevice1278 device1278) // TEST: NO
{
    // COMMON_LT((" | device1278 = %u", device1278)); // Commented to avoid bad looking logs



    switch (device1278)
    {
        case PciDevice1278::DEVICE_0701: return "TPE3/TM3 PowerPC Node";
        case PciDevice1278::DEVICE_0710: return "TPE5 PowerPC PCI board";
        case PciDevice1278::DEVICE_1100: return "PMC-FPGA02";
        case PciDevice1278::DEVICE_1101: return "TS-C43 card with 4 ADSP-TS101 processors";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1278_PCIDEVICE1278_H
