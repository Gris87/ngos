// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR184A_PCIDEVICE184A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR184A_PCIDEVICE184A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice184A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100
};



inline const char8* enumToString(PciDevice184A device184A) // TEST: NO
{
    // COMMON_LT((" | device184A = %u", device184A)); // Commented to avoid bad looking logs



    switch (device184A)
    {
        case PciDevice184A::NONE:        return "NONE";
        case PciDevice184A::DEVICE_1100: return "DEVICE_1100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice184A device184A) // TEST: NO
{
    // COMMON_LT((" | device184A = %u", device184A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device184A, enumToString(device184A));

    return res;
}



inline const char8* enumToHumanString(PciDevice184A device184A) // TEST: NO
{
    // COMMON_LT((" | device184A = %u", device184A)); // Commented to avoid bad looking logs



    switch (device184A)
    {
        case PciDevice184A::DEVICE_1100: return "MAX II cPLD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR184A_PCIDEVICE184A_H
