// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CCF_PCIDEVICE1CCF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CCF_PCIDEVICE1CCF_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CCF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1CCF device1CCF) // TEST: NO
{
    // COMMON_LT((" | device1CCF = %u", device1CCF)); // Commented to avoid bad looking logs



    switch (device1CCF)
    {
        case PciDevice1CCF::NONE:        return "NONE";
        case PciDevice1CCF::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CCF device1CCF) // TEST: NO
{
    // COMMON_LT((" | device1CCF = %u", device1CCF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CCF, enumToString(device1CCF));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CCF device1CCF) // TEST: NO
{
    // COMMON_LT((" | device1CCF = %u", device1CCF)); // Commented to avoid bad looking logs



    switch (device1CCF)
    {
        case PciDevice1CCF::DEVICE_0001: return "TAC-2 Thunderbolt Audio Converter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CCF_PCIDEVICE1CCF_H
