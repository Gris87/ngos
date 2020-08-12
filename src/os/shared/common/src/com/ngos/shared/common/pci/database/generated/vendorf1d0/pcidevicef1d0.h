// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF1D0_PCIDEVICEF1D0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF1D0_PCIDEVICEF1D0_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceF1D0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_C0FE = 0xC0FE,
    DEVICE_C0FF = 0xC0FF,
    DEVICE_CAFE = 0xCAFE,
    DEVICE_CFEE = 0xCFEE,
    DEVICE_DAFE = 0xDAFE,
    DEVICE_DAFF = 0xDAFF,
    DEVICE_DB00 = 0xDB00,
    DEVICE_DB01 = 0xDB01,
    DEVICE_DB02 = 0xDB02,
    DEVICE_DB03 = 0xDB03,
    DEVICE_DB04 = 0xDB04,
    DEVICE_DB05 = 0xDB05,
    DEVICE_DB06 = 0xDB06,
    DEVICE_DB07 = 0xDB07,
    DEVICE_DB08 = 0xDB08,
    DEVICE_DB09 = 0xDB09,
    DEVICE_DB11 = 0xDB11,
    DEVICE_DCAF = 0xDCAF,
    DEVICE_DFEE = 0xDFEE,
    DEVICE_EB07 = 0xEB07,
    DEVICE_EB0A = 0xEB0A,
    DEVICE_EB0B = 0xEB0B,
    DEVICE_EB0C = 0xEB0C,
    DEVICE_EB0D = 0xEB0D,
    DEVICE_EB0E = 0xEB0E,
    DEVICE_EB16 = 0xEB16,
    DEVICE_EB18 = 0xEB18,
    DEVICE_EB1A = 0xEB1A,
    DEVICE_EB1C = 0xEB1C,
    DEVICE_EB1D = 0xEB1D,
    DEVICE_EB1E = 0xEB1E,
    DEVICE_EB1F = 0xEB1F,
    DEVICE_EB23 = 0xEB23,
    DEVICE_EB24 = 0xEB24,
    DEVICE_EB25 = 0xEB25,
    DEVICE_EFAC = 0xEFAC,
    DEVICE_FACD = 0xFACD
};



inline const char8* enumToString(PciDeviceF1D0 deviceF1D0) // TEST: NO
{
    // COMMON_LT((" | deviceF1D0 = %u", deviceF1D0)); // Commented to avoid bad looking logs



    switch (deviceF1D0)
    {
        case PciDeviceF1D0::NONE:        return "NONE";
        case PciDeviceF1D0::DEVICE_C0FE: return "DEVICE_C0FE";
        case PciDeviceF1D0::DEVICE_C0FF: return "DEVICE_C0FF";
        case PciDeviceF1D0::DEVICE_CAFE: return "DEVICE_CAFE";
        case PciDeviceF1D0::DEVICE_CFEE: return "DEVICE_CFEE";
        case PciDeviceF1D0::DEVICE_DAFE: return "DEVICE_DAFE";
        case PciDeviceF1D0::DEVICE_DAFF: return "DEVICE_DAFF";
        case PciDeviceF1D0::DEVICE_DB00: return "DEVICE_DB00";
        case PciDeviceF1D0::DEVICE_DB01: return "DEVICE_DB01";
        case PciDeviceF1D0::DEVICE_DB02: return "DEVICE_DB02";
        case PciDeviceF1D0::DEVICE_DB03: return "DEVICE_DB03";
        case PciDeviceF1D0::DEVICE_DB04: return "DEVICE_DB04";
        case PciDeviceF1D0::DEVICE_DB05: return "DEVICE_DB05";
        case PciDeviceF1D0::DEVICE_DB06: return "DEVICE_DB06";
        case PciDeviceF1D0::DEVICE_DB07: return "DEVICE_DB07";
        case PciDeviceF1D0::DEVICE_DB08: return "DEVICE_DB08";
        case PciDeviceF1D0::DEVICE_DB09: return "DEVICE_DB09";
        case PciDeviceF1D0::DEVICE_DB11: return "DEVICE_DB11";
        case PciDeviceF1D0::DEVICE_DCAF: return "DEVICE_DCAF";
        case PciDeviceF1D0::DEVICE_DFEE: return "DEVICE_DFEE";
        case PciDeviceF1D0::DEVICE_EB07: return "DEVICE_EB07";
        case PciDeviceF1D0::DEVICE_EB0A: return "DEVICE_EB0A";
        case PciDeviceF1D0::DEVICE_EB0B: return "DEVICE_EB0B";
        case PciDeviceF1D0::DEVICE_EB0C: return "DEVICE_EB0C";
        case PciDeviceF1D0::DEVICE_EB0D: return "DEVICE_EB0D";
        case PciDeviceF1D0::DEVICE_EB0E: return "DEVICE_EB0E";
        case PciDeviceF1D0::DEVICE_EB16: return "DEVICE_EB16";
        case PciDeviceF1D0::DEVICE_EB18: return "DEVICE_EB18";
        case PciDeviceF1D0::DEVICE_EB1A: return "DEVICE_EB1A";
        case PciDeviceF1D0::DEVICE_EB1C: return "DEVICE_EB1C";
        case PciDeviceF1D0::DEVICE_EB1D: return "DEVICE_EB1D";
        case PciDeviceF1D0::DEVICE_EB1E: return "DEVICE_EB1E";
        case PciDeviceF1D0::DEVICE_EB1F: return "DEVICE_EB1F";
        case PciDeviceF1D0::DEVICE_EB23: return "DEVICE_EB23";
        case PciDeviceF1D0::DEVICE_EB24: return "DEVICE_EB24";
        case PciDeviceF1D0::DEVICE_EB25: return "DEVICE_EB25";
        case PciDeviceF1D0::DEVICE_EFAC: return "DEVICE_EFAC";
        case PciDeviceF1D0::DEVICE_FACD: return "DEVICE_FACD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceF1D0 deviceF1D0) // TEST: NO
{
    // COMMON_LT((" | deviceF1D0 = %u", deviceF1D0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceF1D0, enumToString(deviceF1D0));

    return res;
}



inline const char8* enumToHumanString(PciDeviceF1D0 deviceF1D0) // TEST: NO
{
    // COMMON_LT((" | deviceF1D0 = %u", deviceF1D0)); // Commented to avoid bad looking logs



    switch (deviceF1D0)
    {
        case PciDeviceF1D0::DEVICE_C0FE: return "Xena HS/HD-R";
        case PciDeviceF1D0::DEVICE_C0FF: return "Kona/Xena 2";
        case PciDeviceF1D0::DEVICE_CAFE: return "Kona SD";
        case PciDeviceF1D0::DEVICE_CFEE: return "Xena LS/SD-22-DA/SD-DA";
        case PciDeviceF1D0::DEVICE_DAFE: return "Corvid 1";
        case PciDeviceF1D0::DEVICE_DAFF: return "KONA LHi";
        case PciDeviceF1D0::DEVICE_DB00: return "IoExpress";
        case PciDeviceF1D0::DEVICE_DB01: return "Corvid22";
        case PciDeviceF1D0::DEVICE_DB02: return "Kona 3G";
        case PciDeviceF1D0::DEVICE_DB03: return "Corvid 3G";
        case PciDeviceF1D0::DEVICE_DB04: return "Kona 3G QUAD";
        case PciDeviceF1D0::DEVICE_DB05: return "Kona LHe+";
        case PciDeviceF1D0::DEVICE_DB06: return "IoXT";
        case PciDeviceF1D0::DEVICE_DB07: return "Kona 3G P2P";
        case PciDeviceF1D0::DEVICE_DB08: return "Kona 3G QUAD P2P";
        case PciDeviceF1D0::DEVICE_DB09: return "Corvid 24";
        case PciDeviceF1D0::DEVICE_DB11: return "T-Tap";
        case PciDeviceF1D0::DEVICE_DCAF: return "Kona HD";
        case PciDeviceF1D0::DEVICE_DFEE: return "Xena HD-DA";
        case PciDeviceF1D0::DEVICE_EB07: return "Io4K";
        case PciDeviceF1D0::DEVICE_EB0A: return "Io4K UFC";
        case PciDeviceF1D0::DEVICE_EB0B: return "Kona 4";
        case PciDeviceF1D0::DEVICE_EB0C: return "Kona 4 UFC";
        case PciDeviceF1D0::DEVICE_EB0D: return "Corvid 88";
        case PciDeviceF1D0::DEVICE_EB0E: return "Corvid 44";
        case PciDeviceF1D0::DEVICE_EB16: return "Corvid HEVC";
        case PciDeviceF1D0::DEVICE_EB18: return "Corvid HB-R";
        case PciDeviceF1D0::DEVICE_EB1A: return "Kona IP 1SFP";
        case PciDeviceF1D0::DEVICE_EB1C: return "Kona IP 2SFP";
        case PciDeviceF1D0::DEVICE_EB1D: return "Io4KPlus";
        case PciDeviceF1D0::DEVICE_EB1E: return "IoIP";
        case PciDeviceF1D0::DEVICE_EB1F: return "Kona 5";
        case PciDeviceF1D0::DEVICE_EB23: return "Kona 1";
        case PciDeviceF1D0::DEVICE_EB24: return "Kona HDMI";
        case PciDeviceF1D0::DEVICE_EB25: return "Corvid 44 12g";
        case PciDeviceF1D0::DEVICE_EFAC: return "Xena SD-MM/SD-22-MM";
        case PciDeviceF1D0::DEVICE_FACD: return "Xena HD-MM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF1D0_PCIDEVICEF1D0_H
