// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EF_PCIDEVICE10EF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EF_PCIDEVICE10EF_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10EF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8154 = 0x8154
};



inline const char8* enumToString(PciDevice10EF device10EF) // TEST: NO
{
    // COMMON_LT((" | device10EF = %u", device10EF)); // Commented to avoid bad looking logs



    switch (device10EF)
    {
        case PciDevice10EF::NONE:        return "NONE";
        case PciDevice10EF::DEVICE_8154: return "DEVICE_8154";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10EF device10EF) // TEST: NO
{
    // COMMON_LT((" | device10EF = %u", device10EF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10EF, enumToString(device10EF));

    return res;
}



inline const char8* enumToHumanString(PciDevice10EF device10EF) // TEST: NO
{
    // COMMON_LT((" | device10EF = %u", device10EF)); // Commented to avoid bad looking logs



    switch (device10EF)
    {
        case PciDevice10EF::DEVICE_8154: return "M815x Token Ring Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EF_PCIDEVICE10EF_H
