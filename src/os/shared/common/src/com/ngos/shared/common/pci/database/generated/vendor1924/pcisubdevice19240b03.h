// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240B03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240B03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240B03: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1924801D = 0x1924801D,
    SUBDEVICE_1924801E = 0x1924801E,
    SUBDEVICE_19248022 = 0x19248022,
    SUBDEVICE_19248024 = 0x19248024,
    SUBDEVICE_19248027 = 0x19248027,
    SUBDEVICE_19248028 = 0x19248028,
    SUBDEVICE_1924802A = 0x1924802A,
    SUBDEVICE_1924802B = 0x1924802B,
    SUBDEVICE_1924802C = 0x1924802C,
    SUBDEVICE_1924802D = 0x1924802D
};



inline const char8* enumToString(PciSubDevice19240B03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240B03::NONE:               return "NONE";
        case PciSubDevice19240B03::SUBDEVICE_1924801D: return "SUBDEVICE_1924801D";
        case PciSubDevice19240B03::SUBDEVICE_1924801E: return "SUBDEVICE_1924801E";
        case PciSubDevice19240B03::SUBDEVICE_19248022: return "SUBDEVICE_19248022";
        case PciSubDevice19240B03::SUBDEVICE_19248024: return "SUBDEVICE_19248024";
        case PciSubDevice19240B03::SUBDEVICE_19248027: return "SUBDEVICE_19248027";
        case PciSubDevice19240B03::SUBDEVICE_19248028: return "SUBDEVICE_19248028";
        case PciSubDevice19240B03::SUBDEVICE_1924802A: return "SUBDEVICE_1924802A";
        case PciSubDevice19240B03::SUBDEVICE_1924802B: return "SUBDEVICE_1924802B";
        case PciSubDevice19240B03::SUBDEVICE_1924802C: return "SUBDEVICE_1924802C";
        case PciSubDevice19240B03::SUBDEVICE_1924802D: return "SUBDEVICE_1924802D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240B03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240B03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240B03::SUBDEVICE_1924801D: return "x2522-R1 2000 Series 10/25G Adapter";
        case PciSubDevice19240B03::SUBDEVICE_1924801E: return "x2542-R1 2000 Series 40/100G Adapter";
        case PciSubDevice19240B03::SUBDEVICE_19248022: return "XtremeScale X2522 10G Network Adapter";
        case PciSubDevice19240B03::SUBDEVICE_19248024: return "XtremeScale X2562 OCP 3.0 Dual Port SFP28";
        case PciSubDevice19240B03::SUBDEVICE_19248027: return "XtremeScale X2541 PCIe Single Port QSFP28";
        case PciSubDevice19240B03::SUBDEVICE_19248028: return "XtremeScale X2522-25G Network Adapter";
        case PciSubDevice19240B03::SUBDEVICE_1924802A: return "XtremeScale X2542 PCIe Dual Port QSFP28";
        case PciSubDevice19240B03::SUBDEVICE_1924802B: return "XtremeScale X2552 OCP 2.0 Dual Port SFP28";
        case PciSubDevice19240B03::SUBDEVICE_1924802C: return "XtremeScale X2522-25G PCIe Dual Port SFP28";
        case PciSubDevice19240B03::SUBDEVICE_1924802D: return "XtremeScale X2562 OCP 3.0 Dual Port SFP28";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240B03_H
