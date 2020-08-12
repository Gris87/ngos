// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A8_PCIDEVICE10A8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A8_PCIDEVICE10A8_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10A8: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice10A8 device10A8) // TEST: NO
{
    // COMMON_LT((" | device10A8 = %u", device10A8)); // Commented to avoid bad looking logs



    switch (device10A8)
    {
        case PciDevice10A8::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10A8 device10A8) // TEST: NO
{
    // COMMON_LT((" | device10A8 = %u", device10A8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10A8, enumToString(device10A8));

    return res;
}



inline const char8* enumToHumanString(PciDevice10A8 device10A8) // TEST: NO
{
    // COMMON_LT((" | device10A8 = %u", device10A8)); // Commented to avoid bad looking logs



    switch (device10A8)
    {
        case PciDevice10A8::DEVICE_0000: return "STB Horizon 64";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A8_PCIDEVICE10A8_H
