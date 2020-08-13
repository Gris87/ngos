// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCIDEVICE1524_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCIDEVICE1524_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1524: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0510 = 0x0510,
    DEVICE_0520 = 0x0520,
    DEVICE_0530 = 0x0530,
    DEVICE_0550 = 0x0550,
    DEVICE_0551 = 0x0551,
    DEVICE_0610 = 0x0610,
    DEVICE_0720 = 0x0720,
    DEVICE_0730 = 0x0730,
    DEVICE_0750 = 0x0750,
    DEVICE_0751 = 0x0751,
    DEVICE_1211 = 0x1211,
    DEVICE_1225 = 0x1225,
    DEVICE_1410 = 0x1410,
    DEVICE_1411 = 0x1411,
    DEVICE_1412 = 0x1412,
    DEVICE_1420 = 0x1420,
    DEVICE_1421 = 0x1421,
    DEVICE_1422 = 0x1422
};



inline const char8* enumToString(PciDevice1524 device1524) // TEST: NO
{
    // COMMON_LT((" | device1524 = %u", device1524)); // Commented to avoid bad looking logs



    switch (device1524)
    {
        case PciDevice1524::NONE:        return "NONE";
        case PciDevice1524::DEVICE_0510: return "DEVICE_0510";
        case PciDevice1524::DEVICE_0520: return "DEVICE_0520";
        case PciDevice1524::DEVICE_0530: return "DEVICE_0530";
        case PciDevice1524::DEVICE_0550: return "DEVICE_0550";
        case PciDevice1524::DEVICE_0551: return "DEVICE_0551";
        case PciDevice1524::DEVICE_0610: return "DEVICE_0610";
        case PciDevice1524::DEVICE_0720: return "DEVICE_0720";
        case PciDevice1524::DEVICE_0730: return "DEVICE_0730";
        case PciDevice1524::DEVICE_0750: return "DEVICE_0750";
        case PciDevice1524::DEVICE_0751: return "DEVICE_0751";
        case PciDevice1524::DEVICE_1211: return "DEVICE_1211";
        case PciDevice1524::DEVICE_1225: return "DEVICE_1225";
        case PciDevice1524::DEVICE_1410: return "DEVICE_1410";
        case PciDevice1524::DEVICE_1411: return "DEVICE_1411";
        case PciDevice1524::DEVICE_1412: return "DEVICE_1412";
        case PciDevice1524::DEVICE_1420: return "DEVICE_1420";
        case PciDevice1524::DEVICE_1421: return "DEVICE_1421";
        case PciDevice1524::DEVICE_1422: return "DEVICE_1422";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1524 device1524) // TEST: NO
{
    // COMMON_LT((" | device1524 = %u", device1524)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1524, enumToString(device1524));

    return res;
}



inline const char8* enumToHumanString(PciDevice1524 device1524) // TEST: NO
{
    // COMMON_LT((" | device1524 = %u", device1524)); // Commented to avoid bad looking logs



    switch (device1524)
    {
        case PciDevice1524::DEVICE_0510: return "CB710 Memory Card Reader Controller";
        case PciDevice1524::DEVICE_0520: return "FLASH memory: ENE Technology Inc:";
        case PciDevice1524::DEVICE_0530: return "ENE PCI Memory Stick Card Reader Controller";
        case PciDevice1524::DEVICE_0550: return "ENE PCI Secure Digital Card Reader Controller";
        case PciDevice1524::DEVICE_0551: return "SD/MMC Card Reader Controller";
        case PciDevice1524::DEVICE_0610: return "PCI Smart Card Reader Controller";
        case PciDevice1524::DEVICE_0720: return "Memory Stick Card Reader Controller";
        case PciDevice1524::DEVICE_0730: return "ENE PCI Memory Stick Card Reader Controller";
        case PciDevice1524::DEVICE_0750: return "ENE PCI SmartMedia / xD Card Reader Controller";
        case PciDevice1524::DEVICE_0751: return "ENE PCI Secure Digital / MMC Card Reader Controller";
        case PciDevice1524::DEVICE_1211: return "CB1211 Cardbus Controller";
        case PciDevice1524::DEVICE_1225: return "CB1225 Cardbus Controller";
        case PciDevice1524::DEVICE_1410: return "CB1410 Cardbus Controller";
        case PciDevice1524::DEVICE_1411: return "CB-710/2/4 Cardbus Controller";
        case PciDevice1524::DEVICE_1412: return "CB-712/4 Cardbus Controller";
        case PciDevice1524::DEVICE_1420: return "CB1420 Cardbus Controller";
        case PciDevice1524::DEVICE_1421: return "CB-720/2/4 Cardbus Controller";
        case PciDevice1524::DEVICE_1422: return "CB-722/4 Cardbus Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCIDEVICE1524_H
