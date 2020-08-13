// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17AA_PCIDEVICE17AA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17AA_PCIDEVICE17AA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17AA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_402B = 0x402B
};



inline const char8* enumToString(PciDevice17AA device17AA) // TEST: NO
{
    // COMMON_LT((" | device17AA = %u", device17AA)); // Commented to avoid bad looking logs



    switch (device17AA)
    {
        case PciDevice17AA::NONE:        return "NONE";
        case PciDevice17AA::DEVICE_402B: return "DEVICE_402B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17AA device17AA) // TEST: NO
{
    // COMMON_LT((" | device17AA = %u", device17AA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17AA, enumToString(device17AA));

    return res;
}



inline const char8* enumToHumanString(PciDevice17AA device17AA) // TEST: NO
{
    // COMMON_LT((" | device17AA = %u", device17AA)); // Commented to avoid bad looking logs



    switch (device17AA)
    {
        case PciDevice17AA::DEVICE_402B: return "Intel 82599ES 10Gb 2-port Server Adapter X520-2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17AA_PCIDEVICE17AA_H
