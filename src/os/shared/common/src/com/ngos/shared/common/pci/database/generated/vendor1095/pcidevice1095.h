// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCIDEVICE1095_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCIDEVICE1095_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1095: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0240 = 0x0240,
    DEVICE_0640 = 0x0640,
    DEVICE_0643 = 0x0643,
    DEVICE_0646 = 0x0646,
    DEVICE_0647 = 0x0647,
    DEVICE_0648 = 0x0648,
    DEVICE_0649 = 0x0649,
    DEVICE_0650 = 0x0650,
    DEVICE_0670 = 0x0670,
    DEVICE_0673 = 0x0673,
    DEVICE_0680 = 0x0680,
    DEVICE_3112 = 0x3112,
    DEVICE_3114 = 0x3114,
    DEVICE_3124 = 0x3124,
    DEVICE_3132 = 0x3132,
    DEVICE_3512 = 0x3512,
    DEVICE_3531 = 0x3531
};



inline const char8* enumToString(PciDevice1095 device1095) // TEST: NO
{
    // COMMON_LT((" | device1095 = %u", device1095)); // Commented to avoid bad looking logs



    switch (device1095)
    {
        case PciDevice1095::NONE:        return "NONE";
        case PciDevice1095::DEVICE_0240: return "DEVICE_0240";
        case PciDevice1095::DEVICE_0640: return "DEVICE_0640";
        case PciDevice1095::DEVICE_0643: return "DEVICE_0643";
        case PciDevice1095::DEVICE_0646: return "DEVICE_0646";
        case PciDevice1095::DEVICE_0647: return "DEVICE_0647";
        case PciDevice1095::DEVICE_0648: return "DEVICE_0648";
        case PciDevice1095::DEVICE_0649: return "DEVICE_0649";
        case PciDevice1095::DEVICE_0650: return "DEVICE_0650";
        case PciDevice1095::DEVICE_0670: return "DEVICE_0670";
        case PciDevice1095::DEVICE_0673: return "DEVICE_0673";
        case PciDevice1095::DEVICE_0680: return "DEVICE_0680";
        case PciDevice1095::DEVICE_3112: return "DEVICE_3112";
        case PciDevice1095::DEVICE_3114: return "DEVICE_3114";
        case PciDevice1095::DEVICE_3124: return "DEVICE_3124";
        case PciDevice1095::DEVICE_3132: return "DEVICE_3132";
        case PciDevice1095::DEVICE_3512: return "DEVICE_3512";
        case PciDevice1095::DEVICE_3531: return "DEVICE_3531";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1095 device1095) // TEST: NO
{
    // COMMON_LT((" | device1095 = %u", device1095)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1095, enumToString(device1095));

    return res;
}



inline const char8* enumToHumanString(PciDevice1095 device1095) // TEST: NO
{
    // COMMON_LT((" | device1095 = %u", device1095)); // Commented to avoid bad looking logs



    switch (device1095)
    {
        case PciDevice1095::DEVICE_0240: return "Adaptec AAR-1210SA SATA HostRAID Controller";
        case PciDevice1095::DEVICE_0640: return "PCI0640";
        case PciDevice1095::DEVICE_0643: return "PCI0643";
        case PciDevice1095::DEVICE_0646: return "PCI0646";
        case PciDevice1095::DEVICE_0647: return "PCI0647";
        case PciDevice1095::DEVICE_0648: return "PCI0648";
        case PciDevice1095::DEVICE_0649: return "SiI 0649 Ultra ATA/100 PCI to ATA Host Controller";
        case PciDevice1095::DEVICE_0650: return "PBC0650A";
        case PciDevice1095::DEVICE_0670: return "USB0670";
        case PciDevice1095::DEVICE_0673: return "USB0673";
        case PciDevice1095::DEVICE_0680: return "PCI0680 Ultra ATA-133 Host Controller";
        case PciDevice1095::DEVICE_3112: return "SiI 3112 [SATALink/SATARaid] Serial ATA Controller";
        case PciDevice1095::DEVICE_3114: return "SiI 3114 [SATALink/SATARaid] Serial ATA Controller";
        case PciDevice1095::DEVICE_3124: return "SiI 3124 PCI-X Serial ATA Controller";
        case PciDevice1095::DEVICE_3132: return "SiI 3132 Serial ATA Raid II Controller";
        case PciDevice1095::DEVICE_3512: return "SiI 3512 [SATALink/SATARaid] Serial ATA Controller";
        case PciDevice1095::DEVICE_3531: return "SiI 3531 [SATALink/SATARaid] Serial ATA Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCIDEVICE1095_H
