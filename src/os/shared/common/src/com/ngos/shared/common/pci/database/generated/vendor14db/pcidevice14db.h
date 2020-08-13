// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DB_PCIDEVICE14DB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DB_PCIDEVICE14DB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14DB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2120 = 0x2120,
    DEVICE_2182 = 0x2182
};



inline const char8* enumToString(PciDevice14DB device14DB) // TEST: NO
{
    // COMMON_LT((" | device14DB = %u", device14DB)); // Commented to avoid bad looking logs



    switch (device14DB)
    {
        case PciDevice14DB::NONE:        return "NONE";
        case PciDevice14DB::DEVICE_2120: return "DEVICE_2120";
        case PciDevice14DB::DEVICE_2182: return "DEVICE_2182";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14DB device14DB) // TEST: NO
{
    // COMMON_LT((" | device14DB = %u", device14DB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14DB, enumToString(device14DB));

    return res;
}



inline const char8* enumToHumanString(PciDevice14DB device14DB) // TEST: NO
{
    // COMMON_LT((" | device14DB = %u", device14DB)); // Commented to avoid bad looking logs



    switch (device14DB)
    {
        case PciDevice14DB::DEVICE_2120: return "TK9902";
        case PciDevice14DB::DEVICE_2182: return "AFAVLAB Technology Inc. 8-port serial card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DB_PCIDEVICE14DB_H
