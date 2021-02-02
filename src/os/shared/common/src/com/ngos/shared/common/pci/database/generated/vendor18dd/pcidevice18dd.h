// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18DD_PCIDEVICE18DD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18DD_PCIDEVICE18DD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18DD: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4C6F = 0x4C6F
};



inline const char8* enumToString(PciDevice18DD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18DD::NONE:        return "NONE";
        case PciDevice18DD::DEVICE_4C6F: return "DEVICE_4C6F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18DD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice18DD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18DD::DEVICE_4C6F: return "Artimi RTMI-100 UWB adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18DD_PCIDEVICE18DD_H
