// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17DB_PCIDEVICE17DB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17DB_PCIDEVICE17DB_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17DB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101
};



inline const char8* enumToString(PciDevice17DB device17DB) // TEST: NO
{
    // COMMON_LT((" | device17DB = %u", device17DB)); // Commented to avoid bad looking logs



    switch (device17DB)
    {
        case PciDevice17DB::NONE:        return "NONE";
        case PciDevice17DB::DEVICE_0101: return "DEVICE_0101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17DB device17DB) // TEST: NO
{
    // COMMON_LT((" | device17DB = %u", device17DB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17DB, enumToString(device17DB));

    return res;
}



inline const char8* enumToHumanString(PciDevice17DB device17DB) // TEST: NO
{
    // COMMON_LT((" | device17DB = %u", device17DB)); // Commented to avoid bad looking logs



    switch (device17DB)
    {
        case PciDevice17DB::DEVICE_0101: return "XT Series [Seastar] 3D Toroidal Router";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17DB_PCIDEVICE17DB_H
