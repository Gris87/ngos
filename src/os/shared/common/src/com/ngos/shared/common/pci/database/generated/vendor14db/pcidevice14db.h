// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DB_PCIDEVICE14DB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DB_PCIDEVICE14DB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14DB: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2120 = 0x2120,
    DEVICE_2182 = 0x2182
};



inline const char8* enumToString(PciDevice14DB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14DB::NONE:        return "NONE";
        case PciDevice14DB::DEVICE_2120: return "DEVICE_2120";
        case PciDevice14DB::DEVICE_2182: return "DEVICE_2182";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14DB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14DB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14DB::DEVICE_2120: return "TK9902";
        case PciDevice14DB::DEVICE_2182: return "AFAVLAB Technology Inc. 8-port serial card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DB_PCIDEVICE14DB_H
