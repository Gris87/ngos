// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16E5_PCIDEVICE16E5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16E5_PCIDEVICE16E5_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16E5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6000 = 0x6000,
    DEVICE_6300 = 0x6300
};



inline const char8* enumToString(PciDevice16E5 device16E5) // TEST: NO
{
    // COMMON_LT((" | device16E5 = %u", device16E5)); // Commented to avoid bad looking logs



    switch (device16E5)
    {
        case PciDevice16E5::NONE:        return "NONE";
        case PciDevice16E5::DEVICE_6000: return "DEVICE_6000";
        case PciDevice16E5::DEVICE_6300: return "DEVICE_6300";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16E5 device16E5) // TEST: NO
{
    // COMMON_LT((" | device16E5 = %u", device16E5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16E5, enumToString(device16E5));

    return res;
}



inline const char8* enumToHumanString(PciDevice16E5 device16E5) // TEST: NO
{
    // COMMON_LT((" | device16E5 = %u", device16E5)); // Commented to avoid bad looking logs



    switch (device16E5)
    {
        case PciDevice16E5::DEVICE_6000: return "INT6000 Ethernet-to-Powerline Bridge [HomePlug AV]";
        case PciDevice16E5::DEVICE_6300: return "INT6300 Ethernet-to-Powerline Bridge [HomePlug AV]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16E5_PCIDEVICE16E5_H
