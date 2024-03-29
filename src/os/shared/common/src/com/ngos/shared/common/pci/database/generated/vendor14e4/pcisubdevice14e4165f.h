// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4165F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804F7 = 0x102804F7,
    SUBDEVICE_102808FD = 0x102808FD,
    SUBDEVICE_102808FF = 0x102808FF,
    SUBDEVICE_10280900 = 0x10280900,
    SUBDEVICE_10280917 = 0x10280917,
    SUBDEVICE_103C1786 = 0x103C1786,
    SUBDEVICE_103C193D = 0x103C193D,
    SUBDEVICE_103C2133 = 0x103C2133,
    SUBDEVICE_103C22E8 = 0x103C22E8,
    SUBDEVICE_103C22EB = 0x103C22EB,
    SUBDEVICE_15D9165F = 0x15D9165F
};



inline const char8* enumToString(PciSubDevice14E4165F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165F::NONE:               return "NONE";
        case PciSubDevice14E4165F::SUBDEVICE_102804F7: return "SUBDEVICE_102804F7";
        case PciSubDevice14E4165F::SUBDEVICE_102808FD: return "SUBDEVICE_102808FD";
        case PciSubDevice14E4165F::SUBDEVICE_102808FF: return "SUBDEVICE_102808FF";
        case PciSubDevice14E4165F::SUBDEVICE_10280900: return "SUBDEVICE_10280900";
        case PciSubDevice14E4165F::SUBDEVICE_10280917: return "SUBDEVICE_10280917";
        case PciSubDevice14E4165F::SUBDEVICE_103C1786: return "SUBDEVICE_103C1786";
        case PciSubDevice14E4165F::SUBDEVICE_103C193D: return "SUBDEVICE_103C193D";
        case PciSubDevice14E4165F::SUBDEVICE_103C2133: return "SUBDEVICE_103C2133";
        case PciSubDevice14E4165F::SUBDEVICE_103C22E8: return "SUBDEVICE_103C22E8";
        case PciSubDevice14E4165F::SUBDEVICE_103C22EB: return "SUBDEVICE_103C22EB";
        case PciSubDevice14E4165F::SUBDEVICE_15D9165F: return "SUBDEVICE_15D9165F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4165F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4165F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165F::SUBDEVICE_102804F7: return "PowerEdge R320 server";
        case PciSubDevice14E4165F::SUBDEVICE_102808FD: return "PowerEdge R6515/R7515 LOM";
        case PciSubDevice14E4165F::SUBDEVICE_102808FF: return "PowerEdge Rx5xx LOM Board";
        case PciSubDevice14E4165F::SUBDEVICE_10280900: return "PowerEdge C6525 LOM";
        case PciSubDevice14E4165F::SUBDEVICE_10280917: return "PowerEdge C6520 LOM";
        case PciSubDevice14E4165F::SUBDEVICE_103C1786: return "NC332T Adapter";
        case PciSubDevice14E4165F::SUBDEVICE_103C193D: return "NC332i Adapter";
        case PciSubDevice14E4165F::SUBDEVICE_103C2133: return "NC332i Adapter";
        case PciSubDevice14E4165F::SUBDEVICE_103C22E8: return "NC332i Adapter";
        case PciSubDevice14E4165F::SUBDEVICE_103C22EB: return "NC332i Adapter";
        case PciSubDevice14E4165F::SUBDEVICE_15D9165F: return "H12SSL-i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165F_H
