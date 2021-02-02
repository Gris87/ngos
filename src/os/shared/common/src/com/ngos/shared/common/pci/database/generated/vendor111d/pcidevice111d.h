// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111D_PCIDEVICE111D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111D_PCIDEVICE111D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111d/pcisubdevice111d806a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111d/pcisubdevice111d8088.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice111D: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_8018 = 0x8018,
    DEVICE_801C = 0x801C,
    DEVICE_8028 = 0x8028,
    DEVICE_802B = 0x802B,
    DEVICE_802C = 0x802C,
    DEVICE_802D = 0x802D,
    DEVICE_802E = 0x802E,
    DEVICE_802F = 0x802F,
    DEVICE_8032 = 0x8032,
    DEVICE_8034 = 0x8034,
    DEVICE_8035 = 0x8035,
    DEVICE_8036 = 0x8036,
    DEVICE_8037 = 0x8037,
    DEVICE_8039 = 0x8039,
    DEVICE_803A = 0x803A,
    DEVICE_803C = 0x803C,
    DEVICE_803D = 0x803D,
    DEVICE_8048 = 0x8048,
    DEVICE_8049 = 0x8049,
    DEVICE_804A = 0x804A,
    DEVICE_804B = 0x804B,
    DEVICE_804C = 0x804C,
    DEVICE_804D = 0x804D,
    DEVICE_804E = 0x804E,
    DEVICE_804F = 0x804F,
    DEVICE_8058 = 0x8058,
    DEVICE_8059 = 0x8059,
    DEVICE_805A = 0x805A,
    DEVICE_805B = 0x805B,
    DEVICE_805C = 0x805C,
    DEVICE_805D = 0x805D,
    DEVICE_805E = 0x805E,
    DEVICE_805F = 0x805F,
    DEVICE_8060 = 0x8060,
    DEVICE_8061 = 0x8061,
    DEVICE_8068 = 0x8068,
    DEVICE_806A = 0x806A,
    DEVICE_806C = 0x806C,
    DEVICE_806E = 0x806E,
    DEVICE_806F = 0x806F,
    DEVICE_8077 = 0x8077,
    DEVICE_8088 = 0x8088,
    DEVICE_808A = 0x808A,
    DEVICE_808C = 0x808C,
    DEVICE_808E = 0x808E,
    DEVICE_808F = 0x808F,
    DEVICE_8090 = 0x8090,
    DEVICE_8092 = 0x8092,
    DEVICE_80CF = 0x80CF,
    DEVICE_80D2 = 0x80D2
};



inline const char8* enumToString(PciDevice111D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice111D::NONE:        return "NONE";
        case PciDevice111D::DEVICE_0001: return "DEVICE_0001";
        case PciDevice111D::DEVICE_0003: return "DEVICE_0003";
        case PciDevice111D::DEVICE_0004: return "DEVICE_0004";
        case PciDevice111D::DEVICE_0005: return "DEVICE_0005";
        case PciDevice111D::DEVICE_8018: return "DEVICE_8018";
        case PciDevice111D::DEVICE_801C: return "DEVICE_801C";
        case PciDevice111D::DEVICE_8028: return "DEVICE_8028";
        case PciDevice111D::DEVICE_802B: return "DEVICE_802B";
        case PciDevice111D::DEVICE_802C: return "DEVICE_802C";
        case PciDevice111D::DEVICE_802D: return "DEVICE_802D";
        case PciDevice111D::DEVICE_802E: return "DEVICE_802E";
        case PciDevice111D::DEVICE_802F: return "DEVICE_802F";
        case PciDevice111D::DEVICE_8032: return "DEVICE_8032";
        case PciDevice111D::DEVICE_8034: return "DEVICE_8034";
        case PciDevice111D::DEVICE_8035: return "DEVICE_8035";
        case PciDevice111D::DEVICE_8036: return "DEVICE_8036";
        case PciDevice111D::DEVICE_8037: return "DEVICE_8037";
        case PciDevice111D::DEVICE_8039: return "DEVICE_8039";
        case PciDevice111D::DEVICE_803A: return "DEVICE_803A";
        case PciDevice111D::DEVICE_803C: return "DEVICE_803C";
        case PciDevice111D::DEVICE_803D: return "DEVICE_803D";
        case PciDevice111D::DEVICE_8048: return "DEVICE_8048";
        case PciDevice111D::DEVICE_8049: return "DEVICE_8049";
        case PciDevice111D::DEVICE_804A: return "DEVICE_804A";
        case PciDevice111D::DEVICE_804B: return "DEVICE_804B";
        case PciDevice111D::DEVICE_804C: return "DEVICE_804C";
        case PciDevice111D::DEVICE_804D: return "DEVICE_804D";
        case PciDevice111D::DEVICE_804E: return "DEVICE_804E";
        case PciDevice111D::DEVICE_804F: return "DEVICE_804F";
        case PciDevice111D::DEVICE_8058: return "DEVICE_8058";
        case PciDevice111D::DEVICE_8059: return "DEVICE_8059";
        case PciDevice111D::DEVICE_805A: return "DEVICE_805A";
        case PciDevice111D::DEVICE_805B: return "DEVICE_805B";
        case PciDevice111D::DEVICE_805C: return "DEVICE_805C";
        case PciDevice111D::DEVICE_805D: return "DEVICE_805D";
        case PciDevice111D::DEVICE_805E: return "DEVICE_805E";
        case PciDevice111D::DEVICE_805F: return "DEVICE_805F";
        case PciDevice111D::DEVICE_8060: return "DEVICE_8060";
        case PciDevice111D::DEVICE_8061: return "DEVICE_8061";
        case PciDevice111D::DEVICE_8068: return "DEVICE_8068";
        case PciDevice111D::DEVICE_806A: return "DEVICE_806A";
        case PciDevice111D::DEVICE_806C: return "DEVICE_806C";
        case PciDevice111D::DEVICE_806E: return "DEVICE_806E";
        case PciDevice111D::DEVICE_806F: return "DEVICE_806F";
        case PciDevice111D::DEVICE_8077: return "DEVICE_8077";
        case PciDevice111D::DEVICE_8088: return "DEVICE_8088";
        case PciDevice111D::DEVICE_808A: return "DEVICE_808A";
        case PciDevice111D::DEVICE_808C: return "DEVICE_808C";
        case PciDevice111D::DEVICE_808E: return "DEVICE_808E";
        case PciDevice111D::DEVICE_808F: return "DEVICE_808F";
        case PciDevice111D::DEVICE_8090: return "DEVICE_8090";
        case PciDevice111D::DEVICE_8092: return "DEVICE_8092";
        case PciDevice111D::DEVICE_80CF: return "DEVICE_80CF";
        case PciDevice111D::DEVICE_80D2: return "DEVICE_80D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice111D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice111D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice111D::DEVICE_0001: return "IDT77201/77211 155Mbps ATM SAR Controller [NICStAR]";
        case PciDevice111D::DEVICE_0003: return "IDT77222/77252 155Mbps ATM MICRO ABR SAR Controller";
        case PciDevice111D::DEVICE_0004: return "IDT77V252 155Mbps ATM MICRO ABR SAR Controller";
        case PciDevice111D::DEVICE_0005: return "IDT77V222 155Mbps ATM MICRO ABR SAR Controller";
        case PciDevice111D::DEVICE_8018: return "PES12N3A 12-lane 3-Port PCI Express Switch";
        case PciDevice111D::DEVICE_801C: return "PES24N3A PCI Express Switch";
        case PciDevice111D::DEVICE_8028: return "PES4T4 PCI Express Switch";
        case PciDevice111D::DEVICE_802B: return "PES8T5A PCI Express Switch";
        case PciDevice111D::DEVICE_802C: return "PES16T4 PCI Express Switch";
        case PciDevice111D::DEVICE_802D: return "PES16T7 PCI Express Switch";
        case PciDevice111D::DEVICE_802E: return "PES24T6 PCI Express Switch";
        case PciDevice111D::DEVICE_802F: return "PES32T8 PCI Express Switch";
        case PciDevice111D::DEVICE_8032: return "PES48T12 PCI Express Switch";
        case PciDevice111D::DEVICE_8034: return "PES16/22/34H16 PCI Express Switch";
        case PciDevice111D::DEVICE_8035: return "PES32H8 PCI Express Switch";
        case PciDevice111D::DEVICE_8036: return "PES48H12 PCI Express Switch";
        case PciDevice111D::DEVICE_8037: return "PES64H16 PCI Express Switch";
        case PciDevice111D::DEVICE_8039: return "PES3T3 PCI Express Switch";
        case PciDevice111D::DEVICE_803A: return "PES4T4 PCI Express Switch";
        case PciDevice111D::DEVICE_803C: return "PES5T5 PCI Express Switch";
        case PciDevice111D::DEVICE_803D: return "PES6T5 PCI Express Switch";
        case PciDevice111D::DEVICE_8048: return "PES8NT2 PCI Express Switch";
        case PciDevice111D::DEVICE_8049: return "PES8NT2 PCI Express Switch";
        case PciDevice111D::DEVICE_804A: return "PES8NT2 PCI Express Internal NTB";
        case PciDevice111D::DEVICE_804B: return "PES8NT2 PCI Express External NTB";
        case PciDevice111D::DEVICE_804C: return "PES16NT2 PCI Express Switch";
        case PciDevice111D::DEVICE_804D: return "PES16NT2 PCI Express Switch";
        case PciDevice111D::DEVICE_804E: return "PES16NT2 PCI Express Internal NTB";
        case PciDevice111D::DEVICE_804F: return "PES16NT2 PCI Express External NTB";
        case PciDevice111D::DEVICE_8058: return "PES12NT3 PCI Express Switch";
        case PciDevice111D::DEVICE_8059: return "PES12NT3 PCI Express Switch";
        case PciDevice111D::DEVICE_805A: return "PES12NT3 PCI Express Internal NTB";
        case PciDevice111D::DEVICE_805B: return "PES12NT3 PCI Express External NTB";
        case PciDevice111D::DEVICE_805C: return "PES24NT3 PCI Express Switch";
        case PciDevice111D::DEVICE_805D: return "PES24NT3 PCI Express Switch";
        case PciDevice111D::DEVICE_805E: return "PES24NT3 PCI Express Internal NTB";
        case PciDevice111D::DEVICE_805F: return "PES24NT3 PCI Express External NTB";
        case PciDevice111D::DEVICE_8060: return "PES16T4G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_8061: return "PES12T3G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_8068: return "PES6T6G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_806A: return "PES24T3G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_806C: return "PES16T4A/4T4G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_806E: return "PES24T6G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_806F: return "HIO524G2 PCI Express Gen2 Switch";
        case PciDevice111D::DEVICE_8077: return "89HPES64H16G2 64-Lane 16-Port PCIe Gen2 System Interconnect Switch";
        case PciDevice111D::DEVICE_8088: return "PES32NT8BG2 PCI Express Switch";
        case PciDevice111D::DEVICE_808A: return "89HPES32NT24BG2 PCI Express Switch";
        case PciDevice111D::DEVICE_808C: return "89HPES32NT24AG2 PCI Express Switch";
        case PciDevice111D::DEVICE_808E: return "PES24NT24G2 PCI Express Switch";
        case PciDevice111D::DEVICE_808F: return "89HPES32NT8AG2 32-Lane 8-Port PCIe Gen2 System Interconnect Switch with Non-Transparent Bridging";
        case PciDevice111D::DEVICE_8090: return "89HPES16NT16G2 16-Lane 16-Port PCIe Gen2 System Interconnect Switch";
        case PciDevice111D::DEVICE_8092: return "89HPES12NT12G2 12-Lane 12-Port PCIe Gen2 System Interconnect Switch";
        case PciDevice111D::DEVICE_80CF: return "F32P08xG3 [PCIe boot mode]";
        case PciDevice111D::DEVICE_80D2: return "F32P08xG3 NVMe controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice111D device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice111D::DEVICE_0001: return "Unknown device";
        case PciDevice111D::DEVICE_0003: return "Unknown device";
        case PciDevice111D::DEVICE_0004: return "Unknown device";
        case PciDevice111D::DEVICE_0005: return "Unknown device";
        case PciDevice111D::DEVICE_8018: return "Unknown device";
        case PciDevice111D::DEVICE_801C: return "Unknown device";
        case PciDevice111D::DEVICE_8028: return "Unknown device";
        case PciDevice111D::DEVICE_802B: return "Unknown device";
        case PciDevice111D::DEVICE_802C: return "Unknown device";
        case PciDevice111D::DEVICE_802D: return "Unknown device";
        case PciDevice111D::DEVICE_802E: return "Unknown device";
        case PciDevice111D::DEVICE_802F: return "Unknown device";
        case PciDevice111D::DEVICE_8032: return "Unknown device";
        case PciDevice111D::DEVICE_8034: return "Unknown device";
        case PciDevice111D::DEVICE_8035: return "Unknown device";
        case PciDevice111D::DEVICE_8036: return "Unknown device";
        case PciDevice111D::DEVICE_8037: return "Unknown device";
        case PciDevice111D::DEVICE_8039: return "Unknown device";
        case PciDevice111D::DEVICE_803A: return "Unknown device";
        case PciDevice111D::DEVICE_803C: return "Unknown device";
        case PciDevice111D::DEVICE_803D: return "Unknown device";
        case PciDevice111D::DEVICE_8048: return "Unknown device";
        case PciDevice111D::DEVICE_8049: return "Unknown device";
        case PciDevice111D::DEVICE_804A: return "Unknown device";
        case PciDevice111D::DEVICE_804B: return "Unknown device";
        case PciDevice111D::DEVICE_804C: return "Unknown device";
        case PciDevice111D::DEVICE_804D: return "Unknown device";
        case PciDevice111D::DEVICE_804E: return "Unknown device";
        case PciDevice111D::DEVICE_804F: return "Unknown device";
        case PciDevice111D::DEVICE_8058: return "Unknown device";
        case PciDevice111D::DEVICE_8059: return "Unknown device";
        case PciDevice111D::DEVICE_805A: return "Unknown device";
        case PciDevice111D::DEVICE_805B: return "Unknown device";
        case PciDevice111D::DEVICE_805C: return "Unknown device";
        case PciDevice111D::DEVICE_805D: return "Unknown device";
        case PciDevice111D::DEVICE_805E: return "Unknown device";
        case PciDevice111D::DEVICE_805F: return "Unknown device";
        case PciDevice111D::DEVICE_8060: return "Unknown device";
        case PciDevice111D::DEVICE_8061: return "Unknown device";
        case PciDevice111D::DEVICE_8068: return "Unknown device";
        case PciDevice111D::DEVICE_806A: return enumToHumanString((PciSubDevice111D806A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice111D::DEVICE_806C: return "Unknown device";
        case PciDevice111D::DEVICE_806E: return "Unknown device";
        case PciDevice111D::DEVICE_806F: return "Unknown device";
        case PciDevice111D::DEVICE_8077: return "Unknown device";
        case PciDevice111D::DEVICE_8088: return enumToHumanString((PciSubDevice111D8088)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice111D::DEVICE_808A: return "Unknown device";
        case PciDevice111D::DEVICE_808C: return "Unknown device";
        case PciDevice111D::DEVICE_808E: return "Unknown device";
        case PciDevice111D::DEVICE_808F: return "Unknown device";
        case PciDevice111D::DEVICE_8090: return "Unknown device";
        case PciDevice111D::DEVICE_8092: return "Unknown device";
        case PciDevice111D::DEVICE_80CF: return "Unknown device";
        case PciDevice111D::DEVICE_80D2: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111D_PCIDEVICE111D_H
