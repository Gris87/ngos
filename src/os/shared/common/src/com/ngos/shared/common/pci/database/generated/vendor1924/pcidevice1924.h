// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCIDEVICE1924_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCIDEVICE1924_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240703.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240710.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240803.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240813.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240903.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240923.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240a03.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19240b03.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1924/pcisubdevice19246703.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1924: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0703 = 0x0703,
    DEVICE_0710 = 0x0710,
    DEVICE_0803 = 0x0803,
    DEVICE_0813 = 0x0813,
    DEVICE_0903 = 0x0903,
    DEVICE_0923 = 0x0923,
    DEVICE_0A03 = 0x0A03,
    DEVICE_0B03 = 0x0B03,
    DEVICE_1803 = 0x1803,
    DEVICE_1813 = 0x1813,
    DEVICE_1903 = 0x1903,
    DEVICE_1923 = 0x1923,
    DEVICE_1A03 = 0x1A03,
    DEVICE_1B03 = 0x1B03,
    DEVICE_6703 = 0x6703,
    DEVICE_C101 = 0xC101
};



inline const char8* enumToString(PciDevice1924 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1924::NONE:        return "NONE";
        case PciDevice1924::DEVICE_0703: return "DEVICE_0703";
        case PciDevice1924::DEVICE_0710: return "DEVICE_0710";
        case PciDevice1924::DEVICE_0803: return "DEVICE_0803";
        case PciDevice1924::DEVICE_0813: return "DEVICE_0813";
        case PciDevice1924::DEVICE_0903: return "DEVICE_0903";
        case PciDevice1924::DEVICE_0923: return "DEVICE_0923";
        case PciDevice1924::DEVICE_0A03: return "DEVICE_0A03";
        case PciDevice1924::DEVICE_0B03: return "DEVICE_0B03";
        case PciDevice1924::DEVICE_1803: return "DEVICE_1803";
        case PciDevice1924::DEVICE_1813: return "DEVICE_1813";
        case PciDevice1924::DEVICE_1903: return "DEVICE_1903";
        case PciDevice1924::DEVICE_1923: return "DEVICE_1923";
        case PciDevice1924::DEVICE_1A03: return "DEVICE_1A03";
        case PciDevice1924::DEVICE_1B03: return "DEVICE_1B03";
        case PciDevice1924::DEVICE_6703: return "DEVICE_6703";
        case PciDevice1924::DEVICE_C101: return "DEVICE_C101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1924 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1924 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1924::DEVICE_0703: return "SFC4000 rev A net [Solarstorm]";
        case PciDevice1924::DEVICE_0710: return "SFC4000 rev B [Solarstorm]";
        case PciDevice1924::DEVICE_0803: return "SFC9020 10G Ethernet Controller";
        case PciDevice1924::DEVICE_0813: return "SFL9021 10GBASE-T Ethernet Controller";
        case PciDevice1924::DEVICE_0903: return "SFC9120 10G Ethernet Controller";
        case PciDevice1924::DEVICE_0923: return "SFC9140 10/40G Ethernet Controller";
        case PciDevice1924::DEVICE_0A03: return "SFC9220 10/40G Ethernet Controller";
        case PciDevice1924::DEVICE_0B03: return "XtremeScale SFC9250 10/25/40/50/100G Ethernet Controller";
        case PciDevice1924::DEVICE_1803: return "SFC9020 10G Ethernet Controller (Virtual Function)";
        case PciDevice1924::DEVICE_1813: return "SFL9021 10GBASE-T Ethernet Controller (Virtual Function)";
        case PciDevice1924::DEVICE_1903: return "SFC9120 10G Ethernet Controller (Virtual Function)";
        case PciDevice1924::DEVICE_1923: return "SFC9140 10/40G Ethernet Controller (Virtual Function)";
        case PciDevice1924::DEVICE_1A03: return "SFC9220 10/40G Ethernet Controller (Virtual Function)";
        case PciDevice1924::DEVICE_1B03: return "XtremeScale SFC9250 10/25/40/50/100G Ethernet Controller (Virtual Function)";
        case PciDevice1924::DEVICE_6703: return "SFC4000 rev A iSCSI/Onload [Solarstorm]";
        case PciDevice1924::DEVICE_C101: return "EF1-21022T [EtherFabric]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1924 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1924::DEVICE_0703: return enumToHumanString((PciSubDevice19240703)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0710: return enumToHumanString((PciSubDevice19240710)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0803: return enumToHumanString((PciSubDevice19240803)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0813: return enumToHumanString((PciSubDevice19240813)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0903: return enumToHumanString((PciSubDevice19240903)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0923: return enumToHumanString((PciSubDevice19240923)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0A03: return enumToHumanString((PciSubDevice19240A03)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_0B03: return enumToHumanString((PciSubDevice19240B03)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_1803: return "Unknown device";
        case PciDevice1924::DEVICE_1813: return "Unknown device";
        case PciDevice1924::DEVICE_1903: return "Unknown device";
        case PciDevice1924::DEVICE_1923: return "Unknown device";
        case PciDevice1924::DEVICE_1A03: return "Unknown device";
        case PciDevice1924::DEVICE_1B03: return "Unknown device";
        case PciDevice1924::DEVICE_6703: return enumToHumanString((PciSubDevice19246703)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1924::DEVICE_C101: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCIDEVICE1924_H
