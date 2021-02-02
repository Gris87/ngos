// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BF4_PCIDEVICE1BF4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BF4_PCIDEVICE1BF4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BF4: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_7011 = 0x7011
};



inline const char8* enumToString(PciDevice1BF4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BF4::NONE:        return "NONE";
        case PciDevice1BF4::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1BF4::DEVICE_7011: return "DEVICE_7011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BF4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BF4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BF4::DEVICE_0001: return "SentinelEX";
        case PciDevice1BF4::DEVICE_7011: return "RX0xxx";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BF4_PCIDEVICE1BF4_H
