// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCIDEVICE11BD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCIDEVICE11BD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11bd/pcisubdevice11bd0040.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11bd/pcisubdevice11bd0041.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11bd/pcisubdevice11bd0042.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11BD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_002E = 0x002E,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0051 = 0x0051,
    DEVICE_BEDE = 0xBEDE
};



inline const char8* enumToString(PciDevice11BD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11BD::NONE:        return "NONE";
        case PciDevice11BD::DEVICE_002E: return "DEVICE_002E";
        case PciDevice11BD::DEVICE_0040: return "DEVICE_0040";
        case PciDevice11BD::DEVICE_0041: return "DEVICE_0041";
        case PciDevice11BD::DEVICE_0042: return "DEVICE_0042";
        case PciDevice11BD::DEVICE_0051: return "DEVICE_0051";
        case PciDevice11BD::DEVICE_BEDE: return "DEVICE_BEDE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11BD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11BD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11BD::DEVICE_002E: return "PCTV 40i";
        case PciDevice11BD::DEVICE_0040: return "Royal TS Function 1";
        case PciDevice11BD::DEVICE_0041: return "RoyalTS Function 2";
        case PciDevice11BD::DEVICE_0042: return "Royal TS Function 3";
        case PciDevice11BD::DEVICE_0051: return "PCTV HD 800i";
        case PciDevice11BD::DEVICE_BEDE: return "AV/DV Studio Capture Card";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice11BD device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11BD::DEVICE_002E: return "Unknown device";
        case PciDevice11BD::DEVICE_0040: return enumToHumanString((PciSubDevice11BD0040)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11BD::DEVICE_0041: return enumToHumanString((PciSubDevice11BD0041)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11BD::DEVICE_0042: return enumToHumanString((PciSubDevice11BD0042)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11BD::DEVICE_0051: return "Unknown device";
        case PciDevice11BD::DEVICE_BEDE: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCIDEVICE11BD_H
