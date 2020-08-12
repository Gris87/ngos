// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCIDEVICE1924_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCIDEVICE1924_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1924: u16 // Ignore CppEnumVerifier
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



inline const char8* enumToString(PciDevice1924 device1924) // TEST: NO
{
    // COMMON_LT((" | device1924 = %u", device1924)); // Commented to avoid bad looking logs



    switch (device1924)
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



inline const char8* enumToFullString(PciDevice1924 device1924) // TEST: NO
{
    // COMMON_LT((" | device1924 = %u", device1924)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1924, enumToString(device1924));

    return res;
}



inline const char8* enumToHumanString(PciDevice1924 device1924) // TEST: NO
{
    // COMMON_LT((" | device1924 = %u", device1924)); // Commented to avoid bad looking logs



    switch (device1924)
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



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCIDEVICE1924_H
