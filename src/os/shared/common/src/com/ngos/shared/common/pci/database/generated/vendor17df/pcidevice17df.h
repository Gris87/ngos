// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17DF_PCIDEVICE17DF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17DF_PCIDEVICE17DF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17DF: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1864 = 0x1864,
    DEVICE_1865 = 0x1865,
    DEVICE_1866 = 0x1866,
    DEVICE_1867 = 0x1867,
    DEVICE_1868 = 0x1868,
    DEVICE_1900 = 0x1900,
    DEVICE_1901 = 0x1901,
    DEVICE_1902 = 0x1902,
    DEVICE_1903 = 0x1903,
    DEVICE_1904 = 0x1904,
    DEVICE_1905 = 0x1905,
    DEVICE_1906 = 0x1906,
    DEVICE_1907 = 0x1907,
    DEVICE_1908 = 0x1908,
    DEVICE_1909 = 0x1909,
    DEVICE_190A = 0x190A,
    DEVICE_190B = 0x190B,
    DEVICE_190C = 0x190C,
    DEVICE_190D = 0x190D,
    DEVICE_190E = 0x190E,
    DEVICE_190F = 0x190F,
    DEVICE_1910 = 0x1910,
    DEVICE_1911 = 0x1911,
    DEVICE_1912 = 0x1912,
    DEVICE_1913 = 0x1913,
    DEVICE_1914 = 0x1914,
    DEVICE_1915 = 0x1915,
    DEVICE_1916 = 0x1916,
    DEVICE_1917 = 0x1917,
    DEVICE_1918 = 0x1918,
    DEVICE_1919 = 0x1919,
    DEVICE_1A00 = 0x1A00,
    DEVICE_1A01 = 0x1A01,
    DEVICE_1A02 = 0x1A02,
    DEVICE_1A03 = 0x1A03,
    DEVICE_1A05 = 0x1A05,
    DEVICE_1A06 = 0x1A06,
    DEVICE_1A07 = 0x1A07,
    DEVICE_1A08 = 0x1A08,
    DEVICE_1A09 = 0x1A09,
    DEVICE_1A0A = 0x1A0A,
    DEVICE_1A0B = 0x1A0B,
    DEVICE_1A0C = 0x1A0C,
    DEVICE_1A0D = 0x1A0D,
    DEVICE_1A0E = 0x1A0E
};



inline const char8* enumToString(PciDevice17DF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17DF::NONE:        return "NONE";
        case PciDevice17DF::DEVICE_1864: return "DEVICE_1864";
        case PciDevice17DF::DEVICE_1865: return "DEVICE_1865";
        case PciDevice17DF::DEVICE_1866: return "DEVICE_1866";
        case PciDevice17DF::DEVICE_1867: return "DEVICE_1867";
        case PciDevice17DF::DEVICE_1868: return "DEVICE_1868";
        case PciDevice17DF::DEVICE_1900: return "DEVICE_1900";
        case PciDevice17DF::DEVICE_1901: return "DEVICE_1901";
        case PciDevice17DF::DEVICE_1902: return "DEVICE_1902";
        case PciDevice17DF::DEVICE_1903: return "DEVICE_1903";
        case PciDevice17DF::DEVICE_1904: return "DEVICE_1904";
        case PciDevice17DF::DEVICE_1905: return "DEVICE_1905";
        case PciDevice17DF::DEVICE_1906: return "DEVICE_1906";
        case PciDevice17DF::DEVICE_1907: return "DEVICE_1907";
        case PciDevice17DF::DEVICE_1908: return "DEVICE_1908";
        case PciDevice17DF::DEVICE_1909: return "DEVICE_1909";
        case PciDevice17DF::DEVICE_190A: return "DEVICE_190A";
        case PciDevice17DF::DEVICE_190B: return "DEVICE_190B";
        case PciDevice17DF::DEVICE_190C: return "DEVICE_190C";
        case PciDevice17DF::DEVICE_190D: return "DEVICE_190D";
        case PciDevice17DF::DEVICE_190E: return "DEVICE_190E";
        case PciDevice17DF::DEVICE_190F: return "DEVICE_190F";
        case PciDevice17DF::DEVICE_1910: return "DEVICE_1910";
        case PciDevice17DF::DEVICE_1911: return "DEVICE_1911";
        case PciDevice17DF::DEVICE_1912: return "DEVICE_1912";
        case PciDevice17DF::DEVICE_1913: return "DEVICE_1913";
        case PciDevice17DF::DEVICE_1914: return "DEVICE_1914";
        case PciDevice17DF::DEVICE_1915: return "DEVICE_1915";
        case PciDevice17DF::DEVICE_1916: return "DEVICE_1916";
        case PciDevice17DF::DEVICE_1917: return "DEVICE_1917";
        case PciDevice17DF::DEVICE_1918: return "DEVICE_1918";
        case PciDevice17DF::DEVICE_1919: return "DEVICE_1919";
        case PciDevice17DF::DEVICE_1A00: return "DEVICE_1A00";
        case PciDevice17DF::DEVICE_1A01: return "DEVICE_1A01";
        case PciDevice17DF::DEVICE_1A02: return "DEVICE_1A02";
        case PciDevice17DF::DEVICE_1A03: return "DEVICE_1A03";
        case PciDevice17DF::DEVICE_1A05: return "DEVICE_1A05";
        case PciDevice17DF::DEVICE_1A06: return "DEVICE_1A06";
        case PciDevice17DF::DEVICE_1A07: return "DEVICE_1A07";
        case PciDevice17DF::DEVICE_1A08: return "DEVICE_1A08";
        case PciDevice17DF::DEVICE_1A09: return "DEVICE_1A09";
        case PciDevice17DF::DEVICE_1A0A: return "DEVICE_1A0A";
        case PciDevice17DF::DEVICE_1A0B: return "DEVICE_1A0B";
        case PciDevice17DF::DEVICE_1A0C: return "DEVICE_1A0C";
        case PciDevice17DF::DEVICE_1A0D: return "DEVICE_1A0D";
        case PciDevice17DF::DEVICE_1A0E: return "DEVICE_1A0E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17DF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice17DF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17DF::DEVICE_1864: return "Virtex4 PCI Board w/ QL5064 Bridge [DN7000K10PCI/DN8000K10PCI/DN8000K10PSX/NOTUS]";
        case PciDevice17DF::DEVICE_1865: return "Virtex4 ASIC Emulator [DN8000K10PCIe]";
        case PciDevice17DF::DEVICE_1866: return "Virtex4 ASIC Emulator Cable Connection [DN8000K10PCI]";
        case PciDevice17DF::DEVICE_1867: return "Virtex4 ASIC Emulator Cable Connection [DN8000K10PCIe]";
        case PciDevice17DF::DEVICE_1868: return "Virtex4 ASIC Emulator [DN8000K10PCIe-8]";
        case PciDevice17DF::DEVICE_1900: return "Virtex5 PCIe ASIC Emulator [DN9000K10PCIe8T/DN9002K10PCIe8T/DN9200K10PCIe8T/DN7006K10PCIe8T/DN7406K10PCIe8T]";
        case PciDevice17DF::DEVICE_1901: return "Virtex5 PCIe ASIC Emulator Large BARs [DN9000K10PCIe8T/DN9002K10PCIe8T/DN9200K10PCIe8T/DN7006K10PCIe8T/DN7406K10PCIe8T]";
        case PciDevice17DF::DEVICE_1902: return "Virtex5 PCIe ASIC Emulator Low Power [Interceptor]";
        case PciDevice17DF::DEVICE_1903: return "Spartan6 PCIe FPGA Accelerator Board [DNBFCS12PCIe]";
        case PciDevice17DF::DEVICE_1904: return "Virtex6 PCIe ASIC Emulation Board [DNDUALV6_PCIe4]";
        case PciDevice17DF::DEVICE_1905: return "Virtex6 PCIe ASIC Emulation Board [DNV6F6PCIe]";
        case PciDevice17DF::DEVICE_1906: return "Virtex6 PCIe ASIC Emulation Board [DN2076K10]";
        case PciDevice17DF::DEVICE_1907: return "Virtex6 PCIe ASIC Emulation Board [DNV6F2PCIe]";
        case PciDevice17DF::DEVICE_1908: return "Virtex6 PCIe ASIC Emulation Board Large BARs[DNV6F2PCIe]";
        case PciDevice17DF::DEVICE_1909: return "Kintex7 PCIe FPGA Accelerator Board [DNK7F5PCIe]";
        case PciDevice17DF::DEVICE_190A: return "Virtex7 PCIe ASIC Emulation Board [DNV7F1A]";
        case PciDevice17DF::DEVICE_190B: return "Stratix5 PCIe ASIC Emulation Board [DNS5GXF2]";
        case PciDevice17DF::DEVICE_190C: return "Virtex7 PCIe ASIC Emulation Board [DNV7F2A]";
        case PciDevice17DF::DEVICE_190D: return "Virtex7 PCIe ASIC Emulation Board [DNV7F4A]";
        case PciDevice17DF::DEVICE_190E: return "Virtex7 PCIe ASIC Emulation Board [DNV7F2B]";
        case PciDevice17DF::DEVICE_190F: return "KintexUS PCIe MainRef Design [DNPCIE_40G_KU_LL]";
        case PciDevice17DF::DEVICE_1910: return "VirtexUS ASIC Emulation Board [DNVUF4A]";
        case PciDevice17DF::DEVICE_1911: return "VirtexUS PCIe ASIC Emulation Board [DNVU_F2PCIe]";
        case PciDevice17DF::DEVICE_1912: return "KintexUS PCIe MainRef Design [DNPCIe_40G_KU_LL_QSFP]";
        case PciDevice17DF::DEVICE_1913: return "VirtexUS ASIC Emulation Board [DNVUF1A]";
        case PciDevice17DF::DEVICE_1914: return "VirtexUS ASIC Emulation Board [DNVUF2A]";
        case PciDevice17DF::DEVICE_1915: return "Arria10 PCIe MainRef Design [DNPCIe_80G_A10_LL]";
        case PciDevice17DF::DEVICE_1916: return "VirtexUS PCIe Accelerator Board [DNVUF2_HPC_PCIe]";
        case PciDevice17DF::DEVICE_1917: return "UltrascalePlus PCIe Accelerator Board [DNPCIe_400G_VU_LL]";
        case PciDevice17DF::DEVICE_1918: return "VirtexUS+ ASIC Emulation Board [DNVUPF4A]";
        case PciDevice17DF::DEVICE_1919: return "UltrascalePlus PCIe Accelerator Board [DNPCIe_400G_VUP_HBM_LL]";
        case PciDevice17DF::DEVICE_1A00: return "Virtex6 PCIe DMA Netlist Design";
        case PciDevice17DF::DEVICE_1A01: return "Virtex6 PCIe Darklite Design [DNPCIe_HXT_10G_LL]";
        case PciDevice17DF::DEVICE_1A02: return "Virtex7 PCIe DMA Netlist Design";
        case PciDevice17DF::DEVICE_1A03: return "Kintex7 PCIe Darklite Design [DNPCIe_K7_10G_LL]";
        case PciDevice17DF::DEVICE_1A05: return "Stratix5 PCIe Darklite Design [DNS5GX_F2]";
        case PciDevice17DF::DEVICE_1A06: return "VirtexUS PCIe DMA Netlist Design";
        case PciDevice17DF::DEVICE_1A07: return "KintexUS PCIe Darklite Design [DNPCIe_40G_KU_LL]";
        case PciDevice17DF::DEVICE_1A08: return "KintexUS PCIe Darklite Design [DNPCIe_40G_KU_LL_QSFP]";
        case PciDevice17DF::DEVICE_1A09: return "Arria10 PCIe Darklite Design [DNPCIe_80G_A10_LL]";
        case PciDevice17DF::DEVICE_1A0A: return "VirtexUS PCIe Darklite Design [DNVUF2_HPC_PCIe]";
        case PciDevice17DF::DEVICE_1A0B: return "UltrascalePlus PCIe Darklite Design [DNPCIe_400G_VU_LL]";
        case PciDevice17DF::DEVICE_1A0C: return "KintexUS PCIe DRAM Packet Capture Design [DNPCIe_40G_KU_LL]";
        case PciDevice17DF::DEVICE_1A0D: return "KintexUS PCIe DRAM Packet Capture Design [DNPCIe_40G_KU_LL_2QSFP]";
        case PciDevice17DF::DEVICE_1A0E: return "UltrascalePlus PCIe Darklite Design [DNPCIe_400G_VUP_HBM_LL]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17DF_PCIDEVICE17DF_H
