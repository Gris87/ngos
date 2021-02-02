// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1999_PCIDEVICE1999_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1999_PCIDEVICE1999_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1999: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A900 = 0xA900
};



inline const char8* enumToString(PciDevice1999 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1999::NONE:        return "NONE";
        case PciDevice1999::DEVICE_A900: return "DEVICE_A900";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1999 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1999 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1999::DEVICE_A900: return "AM-7209 Video Processor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1999_PCIDEVICE1999_H
