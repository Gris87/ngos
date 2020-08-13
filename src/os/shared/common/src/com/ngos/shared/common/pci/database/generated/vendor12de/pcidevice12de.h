// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12DE_PCIDEVICE12DE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12DE_PCIDEVICE12DE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12DE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice12DE device12DE) // TEST: NO
{
    // COMMON_LT((" | device12DE = %u", device12DE)); // Commented to avoid bad looking logs



    switch (device12DE)
    {
        case PciDevice12DE::NONE:        return "NONE";
        case PciDevice12DE::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12DE device12DE) // TEST: NO
{
    // COMMON_LT((" | device12DE = %u", device12DE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12DE, enumToString(device12DE));

    return res;
}



inline const char8* enumToHumanString(PciDevice12DE device12DE) // TEST: NO
{
    // COMMON_LT((" | device12DE = %u", device12DE)); // Commented to avoid bad looking logs



    switch (device12DE)
    {
        case PciDevice12DE::DEVICE_0200: return "CryptoSwift CS200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12DE_PCIDEVICE12DE_H
