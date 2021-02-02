// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C0_PCIDEVICE13C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C0_PCIDEVICE13C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13C0: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0020 = 0x0020,
    DEVICE_0030 = 0x0030,
    DEVICE_0070 = 0x0070,
    DEVICE_0080 = 0x0080,
    DEVICE_00A0 = 0x00A0,
    DEVICE_0210 = 0x0210
};



inline const char8* enumToString(PciDevice13C0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C0::NONE:        return "NONE";
        case PciDevice13C0::DEVICE_0010: return "DEVICE_0010";
        case PciDevice13C0::DEVICE_0020: return "DEVICE_0020";
        case PciDevice13C0::DEVICE_0030: return "DEVICE_0030";
        case PciDevice13C0::DEVICE_0070: return "DEVICE_0070";
        case PciDevice13C0::DEVICE_0080: return "DEVICE_0080";
        case PciDevice13C0::DEVICE_00A0: return "DEVICE_00A0";
        case PciDevice13C0::DEVICE_0210: return "DEVICE_0210";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13C0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13C0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C0::DEVICE_0010: return "SyncLink Adapter v1";
        case PciDevice13C0::DEVICE_0020: return "SyncLink SCC Adapter";
        case PciDevice13C0::DEVICE_0030: return "SyncLink Multiport Adapter";
        case PciDevice13C0::DEVICE_0070: return "SyncLink GT Adapter";
        case PciDevice13C0::DEVICE_0080: return "SyncLink GT4 Adapter";
        case PciDevice13C0::DEVICE_00A0: return "SyncLink GT2 Adapter";
        case PciDevice13C0::DEVICE_0210: return "SyncLink Adapter v2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C0_PCIDEVICE13C0_H
