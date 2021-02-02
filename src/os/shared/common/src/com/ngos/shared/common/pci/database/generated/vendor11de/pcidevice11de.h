// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCIDEVICE11DE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCIDEVICE11DE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11de/pcisubdevice11de6057.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11de/pcisubdevice11de6120.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11DE: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6017 = 0x6017,
    DEVICE_6057 = 0x6057,
    DEVICE_6120 = 0x6120
};



inline const char8* enumToString(PciDevice11DE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11DE::NONE:        return "NONE";
        case PciDevice11DE::DEVICE_6017: return "DEVICE_6017";
        case PciDevice11DE::DEVICE_6057: return "DEVICE_6057";
        case PciDevice11DE::DEVICE_6120: return "DEVICE_6120";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11DE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11DE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11DE::DEVICE_6017: return "miroVIDEO DC30";
        case PciDevice11DE::DEVICE_6057: return "ZR36057PQC Video cutting chipset";
        case PciDevice11DE::DEVICE_6120: return "ZR36120";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice11DE device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11DE::DEVICE_6017: return "Unknown device";
        case PciDevice11DE::DEVICE_6057: return enumToHumanString((PciSubDevice11DE6057)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11DE::DEVICE_6120: return enumToHumanString((PciSubDevice11DE6120)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCIDEVICE11DE_H
