// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCISUBDEVICE11790110_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCISUBDEVICE11790110_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11790110: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281FFB = 0x10281FFB,
    SUBDEVICE_10281FFC = 0x10281FFC,
    SUBDEVICE_10281FFD = 0x10281FFD,
    SUBDEVICE_10281FFE = 0x10281FFE,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_11790021 = 0x11790021,
    SUBDEVICE_1D494039 = 0x1D494039,
    SUBDEVICE_1D49403A = 0x1D49403A
};



inline const char8* enumToString(PciSubDevice11790110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11790110::NONE:               return "NONE";
        case PciSubDevice11790110::SUBDEVICE_10281FFB: return "SUBDEVICE_10281FFB";
        case PciSubDevice11790110::SUBDEVICE_10281FFC: return "SUBDEVICE_10281FFC";
        case PciSubDevice11790110::SUBDEVICE_10281FFD: return "SUBDEVICE_10281FFD";
        case PciSubDevice11790110::SUBDEVICE_10281FFE: return "SUBDEVICE_10281FFE";
        case PciSubDevice11790110::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11790110::SUBDEVICE_11790021: return "SUBDEVICE_11790021";
        case PciSubDevice11790110::SUBDEVICE_1D494039: return "SUBDEVICE_1D494039";
        case PciSubDevice11790110::SUBDEVICE_1D49403A: return "SUBDEVICE_1D49403A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11790110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11790110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11790110::SUBDEVICE_10281FFB: return "Express Flash NVMe 960G (RI) U.2 (CD5)";
        case PciSubDevice11790110::SUBDEVICE_10281FFC: return "Express Flash NVMe 1.92T (RI) U.2 (CD5)";
        case PciSubDevice11790110::SUBDEVICE_10281FFD: return "Express Flash NVMe 3.84T (RI) U.2 (CD5)";
        case PciSubDevice11790110::SUBDEVICE_10281FFE: return "Express Flash NVMe 7.68T (RI) U.2 (CD5)";
        case PciSubDevice11790110::SUBDEVICE_11790001: return "KIOXIA CM5-R series SSD";
        case PciSubDevice11790110::SUBDEVICE_11790021: return "KIOXIA CD5 series SSD";
        case PciSubDevice11790110::SUBDEVICE_1D494039: return "Thinksystem U.2 CM5 NVMe SSD";
        case PciSubDevice11790110::SUBDEVICE_1D49403A: return "Thinksystem AIC CM5 NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCISUBDEVICE11790110_H
