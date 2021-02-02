// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104B_PCIDEVICE104B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104B_PCIDEVICE104B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice104B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0140 = 0x0140,
    DEVICE_1040 = 0x1040,
    DEVICE_8130 = 0x8130
};



inline const char8* enumToString(PciDevice104B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104B::NONE:        return "NONE";
        case PciDevice104B::DEVICE_0140: return "DEVICE_0140";
        case PciDevice104B::DEVICE_1040: return "DEVICE_1040";
        case PciDevice104B::DEVICE_8130: return "DEVICE_8130";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice104B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice104B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104B::DEVICE_0140: return "BT-946C (old) [multimaster 01]";
        case PciDevice104B::DEVICE_1040: return "BT-946C (BA80C30) [MultiMaster 10]";
        case PciDevice104B::DEVICE_8130: return "Flashpoint LT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104B_PCIDEVICE104B_H
