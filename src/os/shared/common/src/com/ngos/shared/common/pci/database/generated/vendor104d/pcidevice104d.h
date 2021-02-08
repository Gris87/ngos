// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104D_PCIDEVICE104D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104D_PCIDEVICE104D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice104D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8004 = 0x8004,
    DEVICE_8009 = 0x8009,
    DEVICE_800C = 0x800C,
    DEVICE_8039 = 0x8039,
    DEVICE_8047 = 0x8047,
    DEVICE_8056 = 0x8056,
    DEVICE_808A = 0x808A,
    DEVICE_80FF = 0x80FF,
    DEVICE_814A = 0x814A,
    DEVICE_8183 = 0x8183,
    DEVICE_81B0 = 0x81B0,
    DEVICE_81C3 = 0x81C3,
    DEVICE_81CE = 0x81CE,
    DEVICE_81FF = 0x81FF,
    DEVICE_8200 = 0x8200,
    DEVICE_820E = 0x820E,
    DEVICE_905C = 0x905C,
    DEVICE_907F = 0x907F,
    DEVICE_908F = 0x908F,
    DEVICE_909E = 0x909E,
    DEVICE_909F = 0x909F,
    DEVICE_90A0 = 0x90A0,
    DEVICE_90A1 = 0x90A1,
    DEVICE_90A2 = 0x90A2,
    DEVICE_90A3 = 0x90A3,
    DEVICE_90A4 = 0x90A4,
    DEVICE_90BC = 0x90BC,
    DEVICE_90C8 = 0x90C8,
    DEVICE_90C9 = 0x90C9,
    DEVICE_90CA = 0x90CA,
    DEVICE_90CB = 0x90CB,
    DEVICE_90CC = 0x90CC,
    DEVICE_90CD = 0x90CD,
    DEVICE_90CE = 0x90CE,
    DEVICE_90CF = 0x90CF,
    DEVICE_90D7 = 0x90D7,
    DEVICE_90D8 = 0x90D8,
    DEVICE_90D9 = 0x90D9,
    DEVICE_90DA = 0x90DA,
    DEVICE_90DB = 0x90DB,
    DEVICE_90DC = 0x90DC,
    DEVICE_90DD = 0x90DD,
    DEVICE_90DE = 0x90DE
};



inline const char8* enumToString(PciDevice104D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104D::NONE:        return "NONE";
        case PciDevice104D::DEVICE_8004: return "DEVICE_8004";
        case PciDevice104D::DEVICE_8009: return "DEVICE_8009";
        case PciDevice104D::DEVICE_800C: return "DEVICE_800C";
        case PciDevice104D::DEVICE_8039: return "DEVICE_8039";
        case PciDevice104D::DEVICE_8047: return "DEVICE_8047";
        case PciDevice104D::DEVICE_8056: return "DEVICE_8056";
        case PciDevice104D::DEVICE_808A: return "DEVICE_808A";
        case PciDevice104D::DEVICE_80FF: return "DEVICE_80FF";
        case PciDevice104D::DEVICE_814A: return "DEVICE_814A";
        case PciDevice104D::DEVICE_8183: return "DEVICE_8183";
        case PciDevice104D::DEVICE_81B0: return "DEVICE_81B0";
        case PciDevice104D::DEVICE_81C3: return "DEVICE_81C3";
        case PciDevice104D::DEVICE_81CE: return "DEVICE_81CE";
        case PciDevice104D::DEVICE_81FF: return "DEVICE_81FF";
        case PciDevice104D::DEVICE_8200: return "DEVICE_8200";
        case PciDevice104D::DEVICE_820E: return "DEVICE_820E";
        case PciDevice104D::DEVICE_905C: return "DEVICE_905C";
        case PciDevice104D::DEVICE_907F: return "DEVICE_907F";
        case PciDevice104D::DEVICE_908F: return "DEVICE_908F";
        case PciDevice104D::DEVICE_909E: return "DEVICE_909E";
        case PciDevice104D::DEVICE_909F: return "DEVICE_909F";
        case PciDevice104D::DEVICE_90A0: return "DEVICE_90A0";
        case PciDevice104D::DEVICE_90A1: return "DEVICE_90A1";
        case PciDevice104D::DEVICE_90A2: return "DEVICE_90A2";
        case PciDevice104D::DEVICE_90A3: return "DEVICE_90A3";
        case PciDevice104D::DEVICE_90A4: return "DEVICE_90A4";
        case PciDevice104D::DEVICE_90BC: return "DEVICE_90BC";
        case PciDevice104D::DEVICE_90C8: return "DEVICE_90C8";
        case PciDevice104D::DEVICE_90C9: return "DEVICE_90C9";
        case PciDevice104D::DEVICE_90CA: return "DEVICE_90CA";
        case PciDevice104D::DEVICE_90CB: return "DEVICE_90CB";
        case PciDevice104D::DEVICE_90CC: return "DEVICE_90CC";
        case PciDevice104D::DEVICE_90CD: return "DEVICE_90CD";
        case PciDevice104D::DEVICE_90CE: return "DEVICE_90CE";
        case PciDevice104D::DEVICE_90CF: return "DEVICE_90CF";
        case PciDevice104D::DEVICE_90D7: return "DEVICE_90D7";
        case PciDevice104D::DEVICE_90D8: return "DEVICE_90D8";
        case PciDevice104D::DEVICE_90D9: return "DEVICE_90D9";
        case PciDevice104D::DEVICE_90DA: return "DEVICE_90DA";
        case PciDevice104D::DEVICE_90DB: return "DEVICE_90DB";
        case PciDevice104D::DEVICE_90DC: return "DEVICE_90DC";
        case PciDevice104D::DEVICE_90DD: return "DEVICE_90DD";
        case PciDevice104D::DEVICE_90DE: return "DEVICE_90DE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice104D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice104D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104D::DEVICE_8004: return "DTL-H2500 [Playstation development board]";
        case PciDevice104D::DEVICE_8009: return "CXD1947Q i.LINK Controller";
        case PciDevice104D::DEVICE_800C: return "DTL-H800 [PS1 sound development board]";
        case PciDevice104D::DEVICE_8039: return "CXD3222 i.LINK Controller";
        case PciDevice104D::DEVICE_8047: return "PS2 TOOL MRP";
        case PciDevice104D::DEVICE_8056: return "Rockwell HCF 56K modem";
        case PciDevice104D::DEVICE_808A: return "Memory Stick Controller";
        case PciDevice104D::DEVICE_80FF: return "PS2 Performance Analyzer";
        case PciDevice104D::DEVICE_814A: return "PS2 Performance Analyzer";
        case PciDevice104D::DEVICE_8183: return "ATHENS [PS3 prototype developer interface card]";
        case PciDevice104D::DEVICE_81B0: return "BM-1 [PSP TOOL Board Management Device]";
        case PciDevice104D::DEVICE_81C3: return "VO-4 [PSP TOOL Video Output Device]";
        case PciDevice104D::DEVICE_81CE: return "SxS Pro memory card";
        case PciDevice104D::DEVICE_81FF: return "PS3 TOOL MRP";
        case PciDevice104D::DEVICE_8200: return "PS3 TOOL RSX Tracing FPGA";
        case PciDevice104D::DEVICE_820E: return "CXD9208GP [PS3 PS2 emulation subsystem adapter]";
        case PciDevice104D::DEVICE_905C: return "SxS Pro memory card";
        case PciDevice104D::DEVICE_907F: return "SxS Pro+ memory card";
        case PciDevice104D::DEVICE_908F: return "Aeolia ACPI";
        case PciDevice104D::DEVICE_909E: return "Aeolia Ethernet Controller (Marvell Yukon 2 Family)";
        case PciDevice104D::DEVICE_909F: return "Aeolia SATA AHCI Controller";
        case PciDevice104D::DEVICE_90A0: return "Aeolia SD/MMC Host Controller";
        case PciDevice104D::DEVICE_90A1: return "Aeolia PCI Express Glue and Miscellaneous Devices";
        case PciDevice104D::DEVICE_90A2: return "Aeolia DMA Controller";
        case PciDevice104D::DEVICE_90A3: return "Aeolia Memory (DDR3/SPM)";
        case PciDevice104D::DEVICE_90A4: return "Aeolia USB 3.0 xHCI Host Controller";
        case PciDevice104D::DEVICE_90BC: return "SxS Pro+ memory card";
        case PciDevice104D::DEVICE_90C8: return "Belize ACPI";
        case PciDevice104D::DEVICE_90C9: return "Belize Ethernet Controller";
        case PciDevice104D::DEVICE_90CA: return "Belize SATA AHCI Controller";
        case PciDevice104D::DEVICE_90CB: return "Belize SD/MMC Host Controller";
        case PciDevice104D::DEVICE_90CC: return "Belize PCI Express Glue and Miscellaneous Devices";
        case PciDevice104D::DEVICE_90CD: return "Belize DMA Controller";
        case PciDevice104D::DEVICE_90CE: return "Belize Memory (DDR3/SPM)";
        case PciDevice104D::DEVICE_90CF: return "Belize USB 3.0 xHCI Host Controller";
        case PciDevice104D::DEVICE_90D7: return "Baikal ACPI";
        case PciDevice104D::DEVICE_90D8: return "Baikal Ethernet Controller";
        case PciDevice104D::DEVICE_90D9: return "Baikal SATA AHCI Controller";
        case PciDevice104D::DEVICE_90DA: return "Baikal SD/MMC Host Controller";
        case PciDevice104D::DEVICE_90DB: return "Baikal PCI Express Glue and Miscellaneous Devices";
        case PciDevice104D::DEVICE_90DC: return "Baikal DMA Controller";
        case PciDevice104D::DEVICE_90DD: return "Baikal Memory (DDR3/SPM)";
        case PciDevice104D::DEVICE_90DE: return "Baikal USB 3.0 xHCI Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104D_PCIDEVICE104D_H
