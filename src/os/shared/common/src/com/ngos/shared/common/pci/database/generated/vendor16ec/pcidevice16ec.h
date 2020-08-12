// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16EC_PCIDEVICE16EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16EC_PCIDEVICE16EC_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16EC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00ED = 0x00ED,
    DEVICE_0116 = 0x0116,
    DEVICE_2F00 = 0x2F00,
    DEVICE_3685 = 0x3685,
    DEVICE_4320 = 0x4320,
    DEVICE_AB06 = 0xAB06
};



inline const char8* enumToString(PciDevice16EC device16EC) // TEST: NO
{
    // COMMON_LT((" | device16EC = %u", device16EC)); // Commented to avoid bad looking logs



    switch (device16EC)
    {
        case PciDevice16EC::NONE:        return "NONE";
        case PciDevice16EC::DEVICE_00ED: return "DEVICE_00ED";
        case PciDevice16EC::DEVICE_0116: return "DEVICE_0116";
        case PciDevice16EC::DEVICE_2F00: return "DEVICE_2F00";
        case PciDevice16EC::DEVICE_3685: return "DEVICE_3685";
        case PciDevice16EC::DEVICE_4320: return "DEVICE_4320";
        case PciDevice16EC::DEVICE_AB06: return "DEVICE_AB06";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16EC device16EC) // TEST: NO
{
    // COMMON_LT((" | device16EC = %u", device16EC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16EC, enumToString(device16EC));

    return res;
}



inline const char8* enumToHumanString(PciDevice16EC device16EC) // TEST: NO
{
    // COMMON_LT((" | device16EC = %u", device16EC)); // Commented to avoid bad looking logs



    switch (device16EC)
    {
        case PciDevice16EC::DEVICE_00ED: return "USR997900";
        case PciDevice16EC::DEVICE_0116: return "USR997902 10/100/1000 Mbps PCI Network Card";
        case PciDevice16EC::DEVICE_2F00: return "USR5660A (USR265660A, USR5660A-BP) 56K PCI Faxmodem";
        case PciDevice16EC::DEVICE_3685: return "Wireless Access PCI Adapter Model 022415";
        case PciDevice16EC::DEVICE_4320: return "USR997904 10/100/1000 64-bit NIC (Marvell Yukon)";
        case PciDevice16EC::DEVICE_AB06: return "USR997901A 10/100 Cardbus NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16EC_PCIDEVICE16EC_H
