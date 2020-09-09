// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D2_PCIDEVICE12D2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D2_PCIDEVICE12D2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d2/pcisubdevice12d20018.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12D2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_0020 = 0x0020,
    DEVICE_0028 = 0x0028,
    DEVICE_0029 = 0x0029,
    DEVICE_002C = 0x002C,
    DEVICE_00A0 = 0x00A0
};



inline const char8* enumToString(PciDevice12D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D2::NONE:        return "NONE";
        case PciDevice12D2::DEVICE_0008: return "DEVICE_0008";
        case PciDevice12D2::DEVICE_0009: return "DEVICE_0009";
        case PciDevice12D2::DEVICE_0018: return "DEVICE_0018";
        case PciDevice12D2::DEVICE_0019: return "DEVICE_0019";
        case PciDevice12D2::DEVICE_0020: return "DEVICE_0020";
        case PciDevice12D2::DEVICE_0028: return "DEVICE_0028";
        case PciDevice12D2::DEVICE_0029: return "DEVICE_0029";
        case PciDevice12D2::DEVICE_002C: return "DEVICE_002C";
        case PciDevice12D2::DEVICE_00A0: return "DEVICE_00A0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D2::DEVICE_0008: return "NV1";
        case PciDevice12D2::DEVICE_0009: return "DAC64";
        case PciDevice12D2::DEVICE_0018: return "Riva128";
        case PciDevice12D2::DEVICE_0019: return "Riva128ZX";
        case PciDevice12D2::DEVICE_0020: return "TNT";
        case PciDevice12D2::DEVICE_0028: return "TNT2";
        case PciDevice12D2::DEVICE_0029: return "UTNT2";
        case PciDevice12D2::DEVICE_002C: return "VTNT2";
        case PciDevice12D2::DEVICE_00A0: return "ITNT2";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice12D2 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D2::DEVICE_0008: return "Unknown device";
        case PciDevice12D2::DEVICE_0009: return "Unknown device";
        case PciDevice12D2::DEVICE_0018: return enumToHumanString((PciSubDevice12D20018)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12D2::DEVICE_0019: return "Unknown device";
        case PciDevice12D2::DEVICE_0020: return "Unknown device";
        case PciDevice12D2::DEVICE_0028: return "Unknown device";
        case PciDevice12D2::DEVICE_0029: return "Unknown device";
        case PciDevice12D2::DEVICE_002C: return "Unknown device";
        case PciDevice12D2::DEVICE_00A0: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D2_PCIDEVICE12D2_H
