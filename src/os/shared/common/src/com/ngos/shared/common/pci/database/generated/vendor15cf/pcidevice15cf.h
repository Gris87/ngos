// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15CF_PCIDEVICE15CF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15CF_PCIDEVICE15CF_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15CF: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice15CF device15CF) // TEST: NO
{
    // COMMON_LT((" | device15CF = %u", device15CF)); // Commented to avoid bad looking logs



    switch (device15CF)
    {
        case PciDevice15CF::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15CF device15CF) // TEST: NO
{
    // COMMON_LT((" | device15CF = %u", device15CF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15CF, enumToString(device15CF));

    return res;
}



inline const char8* enumToHumanString(PciDevice15CF device15CF) // TEST: NO
{
    // COMMON_LT((" | device15CF = %u", device15CF)); // Commented to avoid bad looking logs



    switch (device15CF)
    {
        case PciDevice15CF::DEVICE_0000: return "CIFX 50E-DP(M/S)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15CF_PCIDEVICE15CF_H
