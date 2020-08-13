// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCIDEVICE19E5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCIDEVICE19E5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19E5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0123 = 0x0123,
    DEVICE_0200 = 0x0200,
    DEVICE_0202 = 0x0202,
    DEVICE_0203 = 0x0203,
    DEVICE_0205 = 0x0205,
    DEVICE_0206 = 0x0206,
    DEVICE_0210 = 0x0210,
    DEVICE_0211 = 0x0211,
    DEVICE_0212 = 0x0212,
    DEVICE_1710 = 0x1710,
    DEVICE_1711 = 0x1711,
    DEVICE_1822 = 0x1822,
    DEVICE_371E = 0x371E,
    DEVICE_375E = 0x375E,
    DEVICE_379E = 0x379E,
    DEVICE_A120 = 0xA120,
    DEVICE_A121 = 0xA121,
    DEVICE_A122 = 0xA122,
    DEVICE_A124 = 0xA124,
    DEVICE_A125 = 0xA125,
    DEVICE_A126 = 0xA126,
    DEVICE_A127 = 0xA127,
    DEVICE_A12A = 0xA12A,
    DEVICE_A220 = 0xA220,
    DEVICE_A221 = 0xA221,
    DEVICE_A222 = 0xA222,
    DEVICE_A224 = 0xA224,
    DEVICE_A226 = 0xA226,
    DEVICE_A22A = 0xA22A,
    DEVICE_A22E = 0xA22E,
    DEVICE_A22F = 0xA22F,
    DEVICE_A230 = 0xA230,
    DEVICE_A235 = 0xA235,
    DEVICE_A238 = 0xA238,
    DEVICE_A239 = 0xA239,
    DEVICE_A23A = 0xA23A,
    DEVICE_A23B = 0xA23B,
    DEVICE_A250 = 0xA250,
    DEVICE_A251 = 0xA251,
    DEVICE_A255 = 0xA255,
    DEVICE_A256 = 0xA256,
    DEVICE_A258 = 0xA258,
    DEVICE_A259 = 0xA259,
    DEVICE_A25A = 0xA25A,
    DEVICE_A25B = 0xA25B
};



inline const char8* enumToString(PciDevice19E5 device19E5) // TEST: NO
{
    // COMMON_LT((" | device19E5 = %u", device19E5)); // Commented to avoid bad looking logs



    switch (device19E5)
    {
        case PciDevice19E5::NONE:        return "NONE";
        case PciDevice19E5::DEVICE_0123: return "DEVICE_0123";
        case PciDevice19E5::DEVICE_0200: return "DEVICE_0200";
        case PciDevice19E5::DEVICE_0202: return "DEVICE_0202";
        case PciDevice19E5::DEVICE_0203: return "DEVICE_0203";
        case PciDevice19E5::DEVICE_0205: return "DEVICE_0205";
        case PciDevice19E5::DEVICE_0206: return "DEVICE_0206";
        case PciDevice19E5::DEVICE_0210: return "DEVICE_0210";
        case PciDevice19E5::DEVICE_0211: return "DEVICE_0211";
        case PciDevice19E5::DEVICE_0212: return "DEVICE_0212";
        case PciDevice19E5::DEVICE_1710: return "DEVICE_1710";
        case PciDevice19E5::DEVICE_1711: return "DEVICE_1711";
        case PciDevice19E5::DEVICE_1822: return "DEVICE_1822";
        case PciDevice19E5::DEVICE_371E: return "DEVICE_371E";
        case PciDevice19E5::DEVICE_375E: return "DEVICE_375E";
        case PciDevice19E5::DEVICE_379E: return "DEVICE_379E";
        case PciDevice19E5::DEVICE_A120: return "DEVICE_A120";
        case PciDevice19E5::DEVICE_A121: return "DEVICE_A121";
        case PciDevice19E5::DEVICE_A122: return "DEVICE_A122";
        case PciDevice19E5::DEVICE_A124: return "DEVICE_A124";
        case PciDevice19E5::DEVICE_A125: return "DEVICE_A125";
        case PciDevice19E5::DEVICE_A126: return "DEVICE_A126";
        case PciDevice19E5::DEVICE_A127: return "DEVICE_A127";
        case PciDevice19E5::DEVICE_A12A: return "DEVICE_A12A";
        case PciDevice19E5::DEVICE_A220: return "DEVICE_A220";
        case PciDevice19E5::DEVICE_A221: return "DEVICE_A221";
        case PciDevice19E5::DEVICE_A222: return "DEVICE_A222";
        case PciDevice19E5::DEVICE_A224: return "DEVICE_A224";
        case PciDevice19E5::DEVICE_A226: return "DEVICE_A226";
        case PciDevice19E5::DEVICE_A22A: return "DEVICE_A22A";
        case PciDevice19E5::DEVICE_A22E: return "DEVICE_A22E";
        case PciDevice19E5::DEVICE_A22F: return "DEVICE_A22F";
        case PciDevice19E5::DEVICE_A230: return "DEVICE_A230";
        case PciDevice19E5::DEVICE_A235: return "DEVICE_A235";
        case PciDevice19E5::DEVICE_A238: return "DEVICE_A238";
        case PciDevice19E5::DEVICE_A239: return "DEVICE_A239";
        case PciDevice19E5::DEVICE_A23A: return "DEVICE_A23A";
        case PciDevice19E5::DEVICE_A23B: return "DEVICE_A23B";
        case PciDevice19E5::DEVICE_A250: return "DEVICE_A250";
        case PciDevice19E5::DEVICE_A251: return "DEVICE_A251";
        case PciDevice19E5::DEVICE_A255: return "DEVICE_A255";
        case PciDevice19E5::DEVICE_A256: return "DEVICE_A256";
        case PciDevice19E5::DEVICE_A258: return "DEVICE_A258";
        case PciDevice19E5::DEVICE_A259: return "DEVICE_A259";
        case PciDevice19E5::DEVICE_A25A: return "DEVICE_A25A";
        case PciDevice19E5::DEVICE_A25B: return "DEVICE_A25B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19E5 device19E5) // TEST: NO
{
    // COMMON_LT((" | device19E5 = %u", device19E5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device19E5, enumToString(device19E5));

    return res;
}



inline const char8* enumToHumanString(PciDevice19E5 device19E5) // TEST: NO
{
    // COMMON_LT((" | device19E5 = %u", device19E5)); // Commented to avoid bad looking logs



    switch (device19E5)
    {
        case PciDevice19E5::DEVICE_0123: return "ES3000 V3 NVMe PCIe SSD";
        case PciDevice19E5::DEVICE_0200: return "Hi1822 Family (2*100GE)";
        case PciDevice19E5::DEVICE_0202: return "Hi1822 Family (2*32G FC)";
        case PciDevice19E5::DEVICE_0203: return "Hi1822 Family (2*16G FC)";
        case PciDevice19E5::DEVICE_0205: return "Hi1822 Family (2*100GE)";
        case PciDevice19E5::DEVICE_0206: return "Hi1822 Family (2*25GE)";
        case PciDevice19E5::DEVICE_0210: return "Hi1822 Family (4*25GE)";
        case PciDevice19E5::DEVICE_0211: return "Hi1822 Family (4*25GE)";
        case PciDevice19E5::DEVICE_0212: return "Hi1822 Family (2*8G FC)";
        case PciDevice19E5::DEVICE_1710: return "iBMA Virtual Network Adapter";
        case PciDevice19E5::DEVICE_1711: return "Hi1710 [iBMC Intelligent Management system chip w/VGA support]";
        case PciDevice19E5::DEVICE_1822: return "Hi1822 Family (4*25GE)";
        case PciDevice19E5::DEVICE_371E: return "Hi1822 Family Virtual Bridge";
        case PciDevice19E5::DEVICE_375E: return "Hi1822 Family Virtual Function";
        case PciDevice19E5::DEVICE_379E: return "Hi1822 Family Virtual Function";
        case PciDevice19E5::DEVICE_A120: return "HiSilicon PCIe Root Port with Gen4";
        case PciDevice19E5::DEVICE_A121: return "HiSilicon PCI-PCI Bridge";
        case PciDevice19E5::DEVICE_A122: return "HiSilicon Embedded DMA Engine";
        case PciDevice19E5::DEVICE_A124: return "HiSilicon Internal SDI Function Engine";
        case PciDevice19E5::DEVICE_A125: return "HiSilicon SDI Network Controller";
        case PciDevice19E5::DEVICE_A126: return "HiSilicon SDI NVMe Storage Controller";
        case PciDevice19E5::DEVICE_A127: return "HiSilicon SDI Accelerator";
        case PciDevice19E5::DEVICE_A12A: return "HiSilicon Add-on PCI-PCI Bridge";
        case PciDevice19E5::DEVICE_A220: return "HNS GE Network Controller";
        case PciDevice19E5::DEVICE_A221: return "HNS GE/10GE/25GE Network Controller";
        case PciDevice19E5::DEVICE_A222: return "HNS GE/10GE/25GE RDMA Network Controller";
        case PciDevice19E5::DEVICE_A224: return "HNS GE/10GE/25GE/50GE RDMA Network Controller";
        case PciDevice19E5::DEVICE_A226: return "HNS GE/10GE/25GE/50GE/100GE RDMA Network Controller";
        case PciDevice19E5::DEVICE_A22A: return "HiSilicon Network For SDI";
        case PciDevice19E5::DEVICE_A22E: return "HNS Network Controller (Virtual Function)";
        case PciDevice19E5::DEVICE_A22F: return "HNS RDMA Network Controller (Virtual Function)";
        case PciDevice19E5::DEVICE_A230: return "HiSilicon SAS 3.0 HBA";
        case PciDevice19E5::DEVICE_A235: return "HiSilicon AHCI HBA";
        case PciDevice19E5::DEVICE_A238: return "HiSilicon USB 3.0 Host Controller";
        case PciDevice19E5::DEVICE_A239: return "HiSilicon USB 2.0 2-port Host Controller";
        case PciDevice19E5::DEVICE_A23A: return "HiSilicon USB 2.0 Host Controller";
        case PciDevice19E5::DEVICE_A23B: return "HiSilicon USB 1.1 Host Controller";
        case PciDevice19E5::DEVICE_A250: return "HiSilicon ZIP Engine";
        case PciDevice19E5::DEVICE_A251: return "HiSilicon ZIP Engine(Virtual Function)";
        case PciDevice19E5::DEVICE_A255: return "HiSilicon SEC Engine";
        case PciDevice19E5::DEVICE_A256: return "HiSilicon SEC Engine(Virtual Function)";
        case PciDevice19E5::DEVICE_A258: return "HiSilicon HPRE Engine";
        case PciDevice19E5::DEVICE_A259: return "HiSilicon HPRE Engine(Virtual Function)";
        case PciDevice19E5::DEVICE_A25A: return "HiSilicon RDE Engine";
        case PciDevice19E5::DEVICE_A25B: return "HiSilicon RDE Engine(Virtual Function)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCIDEVICE19E5_H
