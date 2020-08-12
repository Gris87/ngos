// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1621_PCIDEVICE1621_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1621_PCIDEVICE1621_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1621: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0028 = 0x0028
};



inline const char8* enumToString(PciDevice1621 device1621) // TEST: NO
{
    // COMMON_LT((" | device1621 = %u", device1621)); // Commented to avoid bad looking logs



    switch (device1621)
    {
        case PciDevice1621::NONE:        return "NONE";
        case PciDevice1621::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1621::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1621::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1621::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1621::DEVICE_0024: return "DEVICE_0024";
        case PciDevice1621::DEVICE_0025: return "DEVICE_0025";
        case PciDevice1621::DEVICE_0028: return "DEVICE_0028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1621 device1621) // TEST: NO
{
    // COMMON_LT((" | device1621 = %u", device1621)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1621, enumToString(device1621));

    return res;
}



inline const char8* enumToHumanString(PciDevice1621 device1621) // TEST: NO
{
    // COMMON_LT((" | device1621 = %u", device1621)); // Commented to avoid bad looking logs



    switch (device1621)
    {
        case PciDevice1621::DEVICE_0020: return "LynxTWO-A";
        case PciDevice1621::DEVICE_0021: return "LynxTWO-B";
        case PciDevice1621::DEVICE_0022: return "LynxTWO-C";
        case PciDevice1621::DEVICE_0023: return "Lynx L22";
        case PciDevice1621::DEVICE_0024: return "Lynx AES16";
        case PciDevice1621::DEVICE_0025: return "Lynx AES16-SRC";
        case PciDevice1621::DEVICE_0028: return "Lynx AES16e";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1621_PCIDEVICE1621_H
