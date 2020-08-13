// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FCC_PCIDEVICE1FCC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FCC_PCIDEVICE1FCC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1FCC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_F416 = 0xF416,
    DEVICE_FB01 = 0xFB01
};



inline const char8* enumToString(PciDevice1FCC device1FCC) // TEST: NO
{
    // COMMON_LT((" | device1FCC = %u", device1FCC)); // Commented to avoid bad looking logs



    switch (device1FCC)
    {
        case PciDevice1FCC::NONE:        return "NONE";
        case PciDevice1FCC::DEVICE_F416: return "DEVICE_F416";
        case PciDevice1FCC::DEVICE_FB01: return "DEVICE_FB01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1FCC device1FCC) // TEST: NO
{
    // COMMON_LT((" | device1FCC = %u", device1FCC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1FCC, enumToString(device1FCC));

    return res;
}



inline const char8* enumToHumanString(PciDevice1FCC device1FCC) // TEST: NO
{
    // COMMON_LT((" | device1FCC = %u", device1FCC)); // Commented to avoid bad looking logs



    switch (device1FCC)
    {
        case PciDevice1FCC::DEVICE_F416: return "MS416";
        case PciDevice1FCC::DEVICE_FB01: return "MH4LM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FCC_PCIDEVICE1FCC_H
