// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR113F_PCIDEVICE113F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR113F_PCIDEVICE113F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice113F: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0808 = 0x0808,
    DEVICE_1010 = 0x1010,
    DEVICE_80C0 = 0x80C0,
    DEVICE_80C4 = 0x80C4,
    DEVICE_80C8 = 0x80C8,
    DEVICE_8888 = 0x8888,
    DEVICE_9090 = 0x9090
};



inline const char8* enumToString(PciDevice113F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice113F::NONE:        return "NONE";
        case PciDevice113F::DEVICE_0808: return "DEVICE_0808";
        case PciDevice113F::DEVICE_1010: return "DEVICE_1010";
        case PciDevice113F::DEVICE_80C0: return "DEVICE_80C0";
        case PciDevice113F::DEVICE_80C4: return "DEVICE_80C4";
        case PciDevice113F::DEVICE_80C8: return "DEVICE_80C8";
        case PciDevice113F::DEVICE_8888: return "DEVICE_8888";
        case PciDevice113F::DEVICE_9090: return "DEVICE_9090";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice113F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice113F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice113F::DEVICE_0808: return "SST-64P Adapter";
        case PciDevice113F::DEVICE_1010: return "SST-128P Adapter";
        case PciDevice113F::DEVICE_80C0: return "SST-16P DB Adapter";
        case PciDevice113F::DEVICE_80C4: return "SST-16P RJ Adapter";
        case PciDevice113F::DEVICE_80C8: return "SST-16P Adapter";
        case PciDevice113F::DEVICE_8888: return "SST-4P Adapter";
        case PciDevice113F::DEVICE_9090: return "SST-8P Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR113F_PCIDEVICE113F_H
