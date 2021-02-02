// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41677_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41677_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41677: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280176 = 0x10280176,
    SUBDEVICE_10280177 = 0x10280177,
    SUBDEVICE_10280179 = 0x10280179,
    SUBDEVICE_10280182 = 0x10280182,
    SUBDEVICE_10280187 = 0x10280187,
    SUBDEVICE_102801A3 = 0x102801A3,
    SUBDEVICE_102801A8 = 0x102801A8,
    SUBDEVICE_102801AD = 0x102801AD,
    SUBDEVICE_103C3006 = 0x103C3006,
    SUBDEVICE_1462028C = 0x1462028C,
    SUBDEVICE_1734105D = 0x1734105D
};



inline const char8* enumToString(PciSubDevice14E41677 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41677::NONE:               return "NONE";
        case PciSubDevice14E41677::SUBDEVICE_10280176: return "SUBDEVICE_10280176";
        case PciSubDevice14E41677::SUBDEVICE_10280177: return "SUBDEVICE_10280177";
        case PciSubDevice14E41677::SUBDEVICE_10280179: return "SUBDEVICE_10280179";
        case PciSubDevice14E41677::SUBDEVICE_10280182: return "SUBDEVICE_10280182";
        case PciSubDevice14E41677::SUBDEVICE_10280187: return "SUBDEVICE_10280187";
        case PciSubDevice14E41677::SUBDEVICE_102801A3: return "SUBDEVICE_102801A3";
        case PciSubDevice14E41677::SUBDEVICE_102801A8: return "SUBDEVICE_102801A8";
        case PciSubDevice14E41677::SUBDEVICE_102801AD: return "SUBDEVICE_102801AD";
        case PciSubDevice14E41677::SUBDEVICE_103C3006: return "SUBDEVICE_103C3006";
        case PciSubDevice14E41677::SUBDEVICE_1462028C: return "SUBDEVICE_1462028C";
        case PciSubDevice14E41677::SUBDEVICE_1734105D: return "SUBDEVICE_1734105D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41677 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41677 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41677::SUBDEVICE_10280176: return "Dimension XPS Gen 4";
        case PciSubDevice14E41677::SUBDEVICE_10280177: return "Dimension 8400";
        case PciSubDevice14E41677::SUBDEVICE_10280179: return "Optiplex GX280";
        case PciSubDevice14E41677::SUBDEVICE_10280182: return "Latitude D610";
        case PciSubDevice14E41677::SUBDEVICE_10280187: return "Precision M70";
        case PciSubDevice14E41677::SUBDEVICE_102801A3: return "Latitude X1";
        case PciSubDevice14E41677::SUBDEVICE_102801A8: return "Precision 380";
        case PciSubDevice14E41677::SUBDEVICE_102801AD: return "OptiPlex GX620";
        case PciSubDevice14E41677::SUBDEVICE_103C3006: return "DC7100 SFF(DX878AV)";
        case PciSubDevice14E41677::SUBDEVICE_1462028C: return "915P/G Neo2";
        case PciSubDevice14E41677::SUBDEVICE_1734105D: return "Scenic W620";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41677_H
