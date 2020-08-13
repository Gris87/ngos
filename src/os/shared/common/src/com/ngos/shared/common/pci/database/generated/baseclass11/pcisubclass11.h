// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS11_PCISUBCLASS11_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS11_PCISUBCLASS11_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass11: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_10 = 0x10,
    SUB_CLASS_20 = 0x20,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass11 class11) // TEST: NO
{
    // COMMON_LT((" | class11 = %u", class11)); // Commented to avoid bad looking logs



    switch (class11)
    {
        case PciSubClass11::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass11::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass11::SUB_CLASS_10: return "SUB_CLASS_10";
        case PciSubClass11::SUB_CLASS_20: return "SUB_CLASS_20";
        case PciSubClass11::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass11 class11) // TEST: NO
{
    // COMMON_LT((" | class11 = %u", class11)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class11, enumToString(class11));

    return res;
}



inline const char8* enumToHumanString(PciSubClass11 class11) // TEST: NO
{
    // COMMON_LT((" | class11 = %u", class11)); // Commented to avoid bad looking logs



    switch (class11)
    {
        case PciSubClass11::SUB_CLASS_00: return "Signal processing controller - DPIO module";
        case PciSubClass11::SUB_CLASS_01: return "Signal processing controller - Performance counters";
        case PciSubClass11::SUB_CLASS_10: return "Signal processing controller - Communication synchronizer";
        case PciSubClass11::SUB_CLASS_20: return "Signal processing controller - Signal processing management";
        case PciSubClass11::SUB_CLASS_80: return "Signal processing controller - Signal processing controller";

        default: return "Signal processing controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS11_PCISUBCLASS11_H
