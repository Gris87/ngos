// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2348_PCIDEVICE2348_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2348_PCIDEVICE2348_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2348: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2010 = 0x2010
};



inline const char8* enumToString(PciDevice2348 device2348) // TEST: NO
{
    // COMMON_LT((" | device2348 = %u", device2348)); // Commented to avoid bad looking logs



    switch (device2348)
    {
        case PciDevice2348::NONE:        return "NONE";
        case PciDevice2348::DEVICE_2010: return "DEVICE_2010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice2348 device2348) // TEST: NO
{
    // COMMON_LT((" | device2348 = %u", device2348)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device2348, enumToString(device2348));

    return res;
}



inline const char8* enumToHumanString(PciDevice2348 device2348) // TEST: NO
{
    // COMMON_LT((" | device2348 = %u", device2348)); // Commented to avoid bad looking logs



    switch (device2348)
    {
        case PciDevice2348::DEVICE_2010: return "8142 100VG/AnyLAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2348_PCIDEVICE2348_H
