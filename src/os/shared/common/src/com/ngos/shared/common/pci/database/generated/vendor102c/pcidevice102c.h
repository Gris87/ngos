// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCIDEVICE102C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCIDEVICE102C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102c/pcisubdevice102c00c0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102c/pcisubdevice102c00e5.h>
#include <com/ngos/shared/common/pci/database/generated/vendor102c/pcisubdevice102c0c30.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice102C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00B8 = 0x00B8,
    DEVICE_00C0 = 0x00C0,
    DEVICE_00D0 = 0x00D0,
    DEVICE_00D8 = 0x00D8,
    DEVICE_00DC = 0x00DC,
    DEVICE_00E0 = 0x00E0,
    DEVICE_00E4 = 0x00E4,
    DEVICE_00E5 = 0x00E5,
    DEVICE_00F0 = 0x00F0,
    DEVICE_00F4 = 0x00F4,
    DEVICE_00F5 = 0x00F5,
    DEVICE_0C30 = 0x0C30
};



inline const char8* enumToString(PciDevice102C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice102C::NONE:        return "NONE";
        case PciDevice102C::DEVICE_00B8: return "DEVICE_00B8";
        case PciDevice102C::DEVICE_00C0: return "DEVICE_00C0";
        case PciDevice102C::DEVICE_00D0: return "DEVICE_00D0";
        case PciDevice102C::DEVICE_00D8: return "DEVICE_00D8";
        case PciDevice102C::DEVICE_00DC: return "DEVICE_00DC";
        case PciDevice102C::DEVICE_00E0: return "DEVICE_00E0";
        case PciDevice102C::DEVICE_00E4: return "DEVICE_00E4";
        case PciDevice102C::DEVICE_00E5: return "DEVICE_00E5";
        case PciDevice102C::DEVICE_00F0: return "DEVICE_00F0";
        case PciDevice102C::DEVICE_00F4: return "DEVICE_00F4";
        case PciDevice102C::DEVICE_00F5: return "DEVICE_00F5";
        case PciDevice102C::DEVICE_0C30: return "DEVICE_0C30";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice102C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice102C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice102C::DEVICE_00B8: return "F64310";
        case PciDevice102C::DEVICE_00C0: return "F69000 HiQVideo";
        case PciDevice102C::DEVICE_00D0: return "F65545";
        case PciDevice102C::DEVICE_00D8: return "F65545";
        case PciDevice102C::DEVICE_00DC: return "F65548";
        case PciDevice102C::DEVICE_00E0: return "F65550";
        case PciDevice102C::DEVICE_00E4: return "F65554";
        case PciDevice102C::DEVICE_00E5: return "F65555 HiQVPro";
        case PciDevice102C::DEVICE_00F0: return "F68554";
        case PciDevice102C::DEVICE_00F4: return "F68554 HiQVision";
        case PciDevice102C::DEVICE_00F5: return "F68555";
        case PciDevice102C::DEVICE_0C30: return "F69030";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice102C device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice102C::DEVICE_00B8: return "Unknown device";
        case PciDevice102C::DEVICE_00C0: return enumToHumanString((PciSubDevice102C00C0)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice102C::DEVICE_00D0: return "Unknown device";
        case PciDevice102C::DEVICE_00D8: return "Unknown device";
        case PciDevice102C::DEVICE_00DC: return "Unknown device";
        case PciDevice102C::DEVICE_00E0: return "Unknown device";
        case PciDevice102C::DEVICE_00E4: return "Unknown device";
        case PciDevice102C::DEVICE_00E5: return enumToHumanString((PciSubDevice102C00E5)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice102C::DEVICE_00F0: return "Unknown device";
        case PciDevice102C::DEVICE_00F4: return "Unknown device";
        case PciDevice102C::DEVICE_00F5: return "Unknown device";
        case PciDevice102C::DEVICE_0C30: return enumToHumanString((PciSubDevice102C0C30)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCIDEVICE102C_H
