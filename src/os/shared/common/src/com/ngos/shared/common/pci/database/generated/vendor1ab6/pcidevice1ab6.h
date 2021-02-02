// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AB6_PCIDEVICE1AB6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AB6_PCIDEVICE1AB6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AB6: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6201 = 0x6201
};



inline const char8* enumToString(PciDevice1AB6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AB6::NONE:        return "NONE";
        case PciDevice1AB6::DEVICE_6201: return "DEVICE_6201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AB6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AB6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AB6::DEVICE_6201: return "RAID Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AB6_PCIDEVICE1AB6_H
