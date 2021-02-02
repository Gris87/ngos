// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AED_PCIDEVICE1AED_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AED_PCIDEVICE1AED_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1aed/pcisubdevice1aed1005.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AED: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1003 = 0x1003,
    DEVICE_1005 = 0x1005,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1008 = 0x1008,
    DEVICE_2001 = 0x2001,
    DEVICE_3001 = 0x3001,
    DEVICE_3002 = 0x3002,
    DEVICE_3003 = 0x3003
};



inline const char8* enumToString(PciDevice1AED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AED::NONE:        return "NONE";
        case PciDevice1AED::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1AED::DEVICE_1005: return "DEVICE_1005";
        case PciDevice1AED::DEVICE_1006: return "DEVICE_1006";
        case PciDevice1AED::DEVICE_1007: return "DEVICE_1007";
        case PciDevice1AED::DEVICE_1008: return "DEVICE_1008";
        case PciDevice1AED::DEVICE_2001: return "DEVICE_2001";
        case PciDevice1AED::DEVICE_3001: return "DEVICE_3001";
        case PciDevice1AED::DEVICE_3002: return "DEVICE_3002";
        case PciDevice1AED::DEVICE_3003: return "DEVICE_3003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AED::DEVICE_1003: return "ioDimm3 (v1.2)";
        case PciDevice1AED::DEVICE_1005: return "ioDimm3";
        case PciDevice1AED::DEVICE_1006: return "ioXtreme";
        case PciDevice1AED::DEVICE_1007: return "ioXtreme Pro";
        case PciDevice1AED::DEVICE_1008: return "ioXtreme-2";
        case PciDevice1AED::DEVICE_2001: return "ioDrive2";
        case PciDevice1AED::DEVICE_3001: return "ioMemory FHHL";
        case PciDevice1AED::DEVICE_3002: return "ioMemory HHHL";
        case PciDevice1AED::DEVICE_3003: return "ioMemory Mezzanine";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1AED device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AED::DEVICE_1003: return "Unknown device";
        case PciDevice1AED::DEVICE_1005: return enumToHumanString((PciSubDevice1AED1005)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1AED::DEVICE_1006: return "Unknown device";
        case PciDevice1AED::DEVICE_1007: return "Unknown device";
        case PciDevice1AED::DEVICE_1008: return "Unknown device";
        case PciDevice1AED::DEVICE_2001: return "Unknown device";
        case PciDevice1AED::DEVICE_3001: return "Unknown device";
        case PciDevice1AED::DEVICE_3002: return "Unknown device";
        case PciDevice1AED::DEVICE_3003: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AED_PCIDEVICE1AED_H
