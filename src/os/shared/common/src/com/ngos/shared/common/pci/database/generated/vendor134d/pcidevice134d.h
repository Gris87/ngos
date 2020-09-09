// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134D_PCIDEVICE134D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134D_PCIDEVICE134D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor134d/pcisubdevice134d7890.h>
#include <com/ngos/shared/common/pci/database/generated/vendor134d/pcisubdevice134d7891.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice134D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2189 = 0x2189,
    DEVICE_2486 = 0x2486,
    DEVICE_7890 = 0x7890,
    DEVICE_7891 = 0x7891,
    DEVICE_7892 = 0x7892,
    DEVICE_7893 = 0x7893,
    DEVICE_7894 = 0x7894,
    DEVICE_7895 = 0x7895,
    DEVICE_7896 = 0x7896,
    DEVICE_7897 = 0x7897
};



inline const char8* enumToString(PciDevice134D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice134D::NONE:        return "NONE";
        case PciDevice134D::DEVICE_2189: return "DEVICE_2189";
        case PciDevice134D::DEVICE_2486: return "DEVICE_2486";
        case PciDevice134D::DEVICE_7890: return "DEVICE_7890";
        case PciDevice134D::DEVICE_7891: return "DEVICE_7891";
        case PciDevice134D::DEVICE_7892: return "DEVICE_7892";
        case PciDevice134D::DEVICE_7893: return "DEVICE_7893";
        case PciDevice134D::DEVICE_7894: return "DEVICE_7894";
        case PciDevice134D::DEVICE_7895: return "DEVICE_7895";
        case PciDevice134D::DEVICE_7896: return "DEVICE_7896";
        case PciDevice134D::DEVICE_7897: return "DEVICE_7897";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice134D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice134D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice134D::DEVICE_2189: return "HSP56 MicroModem";
        case PciDevice134D::DEVICE_2486: return "2304WT V.92 MDC Modem";
        case PciDevice134D::DEVICE_7890: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7891: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7892: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7893: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7894: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7895: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7896: return "HSP MicroModem 56";
        case PciDevice134D::DEVICE_7897: return "HSP MicroModem 56";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice134D device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice134D::DEVICE_2189: return "Unknown device";
        case PciDevice134D::DEVICE_2486: return "Unknown device";
        case PciDevice134D::DEVICE_7890: return enumToHumanString((PciSubDevice134D7890)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice134D::DEVICE_7891: return enumToHumanString((PciSubDevice134D7891)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice134D::DEVICE_7892: return "Unknown device";
        case PciDevice134D::DEVICE_7893: return "Unknown device";
        case PciDevice134D::DEVICE_7894: return "Unknown device";
        case PciDevice134D::DEVICE_7895: return "Unknown device";
        case PciDevice134D::DEVICE_7896: return "Unknown device";
        case PciDevice134D::DEVICE_7897: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134D_PCIDEVICE134D_H
