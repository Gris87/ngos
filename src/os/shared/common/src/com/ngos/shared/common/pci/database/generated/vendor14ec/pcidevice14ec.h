// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14EC_PCIDEVICE14EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14EC_PCIDEVICE14EC_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14EC: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice14EC device14EC) // TEST: NO
{
    // COMMON_LT((" | device14EC = %u", device14EC)); // Commented to avoid bad looking logs



    switch (device14EC)
    {
        case PciDevice14EC::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14EC device14EC) // TEST: NO
{
    // COMMON_LT((" | device14EC = %u", device14EC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14EC, enumToString(device14EC));

    return res;
}



inline const char8* enumToHumanString(PciDevice14EC device14EC) // TEST: NO
{
    // COMMON_LT((" | device14EC = %u", device14EC)); // Commented to avoid bad looking logs



    switch (device14EC)
    {
        case PciDevice14EC::DEVICE_0000: return "Aciris Digitizer (malformed ID)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14EC_PCIDEVICE14EC_H
