// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BBF_PCIDEVICE1BBF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BBF_PCIDEVICE1BBF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BBF: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004
};



inline const char8* enumToString(PciDevice1BBF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BBF::NONE:        return "NONE";
        case PciDevice1BBF::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1BBF::DEVICE_0004: return "DEVICE_0004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BBF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BBF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BBF::DEVICE_0003: return "MAX3";
        case PciDevice1BBF::DEVICE_0004: return "MAX4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BBF_PCIDEVICE1BBF_H
