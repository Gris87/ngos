// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CD_PCIDEVICE10CD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CD_PCIDEVICE10CD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10cd/pcisubdevice10cd1300.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10CD: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100,
    DEVICE_1200 = 0x1200,
    DEVICE_1300 = 0x1300,
    DEVICE_2300 = 0x2300,
    DEVICE_2500 = 0x2500,
    DEVICE_2700 = 0x2700
};



inline const char8* enumToString(PciDevice10CD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10CD::NONE:        return "NONE";
        case PciDevice10CD::DEVICE_1100: return "DEVICE_1100";
        case PciDevice10CD::DEVICE_1200: return "DEVICE_1200";
        case PciDevice10CD::DEVICE_1300: return "DEVICE_1300";
        case PciDevice10CD::DEVICE_2300: return "DEVICE_2300";
        case PciDevice10CD::DEVICE_2500: return "DEVICE_2500";
        case PciDevice10CD::DEVICE_2700: return "DEVICE_2700";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10CD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10CD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10CD::DEVICE_1100: return "ASC1100";
        case PciDevice10CD::DEVICE_1200: return "ASC1200 [(abp940) Fast SCSI-II]";
        case PciDevice10CD::DEVICE_1300: return "ASC1300 / ASC3030 [ABP940-U / ABP960-U / ABP3925]";
        case PciDevice10CD::DEVICE_2300: return "ABP940-UW";
        case PciDevice10CD::DEVICE_2500: return "ABP940-U2W";
        case PciDevice10CD::DEVICE_2700: return "ABP3950-U3W";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10CD device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10CD::DEVICE_1100: return "Unknown device";
        case PciDevice10CD::DEVICE_1200: return "Unknown device";
        case PciDevice10CD::DEVICE_1300: return enumToHumanString((PciSubDevice10CD1300)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10CD::DEVICE_2300: return "Unknown device";
        case PciDevice10CD::DEVICE_2500: return "Unknown device";
        case PciDevice10CD::DEVICE_2700: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CD_PCIDEVICE10CD_H
