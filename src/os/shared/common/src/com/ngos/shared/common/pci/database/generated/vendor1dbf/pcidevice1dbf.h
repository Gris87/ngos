// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DBF_PCIDEVICE1DBF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DBF_PCIDEVICE1DBF_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DBF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0401 = 0x0401
};



inline const char8* enumToString(PciDevice1DBF device1DBF) // TEST: NO
{
    // COMMON_LT((" | device1DBF = %u", device1DBF)); // Commented to avoid bad looking logs



    switch (device1DBF)
    {
        case PciDevice1DBF::NONE:        return "NONE";
        case PciDevice1DBF::DEVICE_0401: return "DEVICE_0401";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DBF device1DBF) // TEST: NO
{
    // COMMON_LT((" | device1DBF = %u", device1DBF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1DBF, enumToString(device1DBF));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DBF device1DBF) // TEST: NO
{
    // COMMON_LT((" | device1DBF = %u", device1DBF)); // Commented to avoid bad looking logs



    switch (device1DBF)
    {
        case PciDevice1DBF::DEVICE_0401: return "StarDragon4800 PCI Express Root Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DBF_PCIDEVICE1DBF_H
