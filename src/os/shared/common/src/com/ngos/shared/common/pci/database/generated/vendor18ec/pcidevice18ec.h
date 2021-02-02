// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCIDEVICE18EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCIDEVICE18EC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcisubdevice18ec6d05.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcisubdevice18ecc006.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcisubdevice18ecc032.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcisubdevice18ecc058.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcisubdevice18ecc132.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18ec/pcisubdevice18ecc232.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18EC: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6D05 = 0x6D05,
    DEVICE_C006 = 0xC006,
    DEVICE_C032 = 0xC032,
    DEVICE_C045 = 0xC045,
    DEVICE_C050 = 0xC050,
    DEVICE_C058 = 0xC058,
    DEVICE_C132 = 0xC132,
    DEVICE_C232 = 0xC232
};



inline const char8* enumToString(PciDevice18EC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18EC::NONE:        return "NONE";
        case PciDevice18EC::DEVICE_6D05: return "DEVICE_6D05";
        case PciDevice18EC::DEVICE_C006: return "DEVICE_C006";
        case PciDevice18EC::DEVICE_C032: return "DEVICE_C032";
        case PciDevice18EC::DEVICE_C045: return "DEVICE_C045";
        case PciDevice18EC::DEVICE_C050: return "DEVICE_C050";
        case PciDevice18EC::DEVICE_C058: return "DEVICE_C058";
        case PciDevice18EC::DEVICE_C132: return "DEVICE_C132";
        case PciDevice18EC::DEVICE_C232: return "DEVICE_C232";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18EC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice18EC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18EC::DEVICE_6D05: return "ML555";
        case PciDevice18EC::DEVICE_C006: return "COMBO6";
        case PciDevice18EC::DEVICE_C032: return "COMBO-LXT110";
        case PciDevice18EC::DEVICE_C045: return "COMBO6E";
        case PciDevice18EC::DEVICE_C050: return "COMBO-PTM";
        case PciDevice18EC::DEVICE_C058: return "COMBO6X";
        case PciDevice18EC::DEVICE_C132: return "COMBO-LXT155";
        case PciDevice18EC::DEVICE_C232: return "COMBO-FXT100";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice18EC device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18EC::DEVICE_6D05: return enumToHumanString((PciSubDevice18EC6D05)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice18EC::DEVICE_C006: return enumToHumanString((PciSubDevice18ECC006)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice18EC::DEVICE_C032: return enumToHumanString((PciSubDevice18ECC032)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice18EC::DEVICE_C045: return "Unknown device";
        case PciDevice18EC::DEVICE_C050: return "Unknown device";
        case PciDevice18EC::DEVICE_C058: return enumToHumanString((PciSubDevice18ECC058)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice18EC::DEVICE_C132: return enumToHumanString((PciSubDevice18ECC132)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice18EC::DEVICE_C232: return enumToHumanString((PciSubDevice18ECC232)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCIDEVICE18EC_H
