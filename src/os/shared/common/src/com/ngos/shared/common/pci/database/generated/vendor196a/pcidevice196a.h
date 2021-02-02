// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR196A_PCIDEVICE196A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR196A_PCIDEVICE196A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice196A: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0105 = 0x0105
};



inline const char8* enumToString(PciDevice196A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice196A::NONE:        return "NONE";
        case PciDevice196A::DEVICE_0101: return "DEVICE_0101";
        case PciDevice196A::DEVICE_0102: return "DEVICE_0102";
        case PciDevice196A::DEVICE_0105: return "DEVICE_0105";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice196A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice196A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice196A::DEVICE_0101: return "NodalCore C-1000 Content Classification Accelerator";
        case PciDevice196A::DEVICE_0102: return "NodalCore C-2000 Content Classification Accelerator";
        case PciDevice196A::DEVICE_0105: return "NodalCore C-3000 Content Classification Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR196A_PCIDEVICE196A_H
