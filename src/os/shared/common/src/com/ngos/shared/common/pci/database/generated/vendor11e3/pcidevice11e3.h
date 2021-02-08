// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11E3_PCIDEVICE11E3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11E3_PCIDEVICE11E3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11E3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0560 = 0x0560,
    DEVICE_5030 = 0x5030,
    DEVICE_8417 = 0x8417
};



inline const char8* enumToString(PciDevice11E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11E3::NONE:        return "NONE";
        case PciDevice11E3::DEVICE_0001: return "DEVICE_0001";
        case PciDevice11E3::DEVICE_0560: return "DEVICE_0560";
        case PciDevice11E3::DEVICE_5030: return "DEVICE_5030";
        case PciDevice11E3::DEVICE_8417: return "DEVICE_8417";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11E3::DEVICE_0001: return "COM-ON-AIR Dosch&Amand DECT";
        case PciDevice11E3::DEVICE_0560: return "QL5064 Companion Design Demo Board";
        case PciDevice11E3::DEVICE_5030: return "PC Watchdog";
        case PciDevice11E3::DEVICE_8417: return "QL5064 [QuickPCI] PCI v2.2 bridge for SMT417 Dual TMS320C6416T PMC Module";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11E3_PCIDEVICE11E3_H
