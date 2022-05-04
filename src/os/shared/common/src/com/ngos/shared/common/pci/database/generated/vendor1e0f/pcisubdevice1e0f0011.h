// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0011_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0011_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E0F0011: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282189 = 0x10282189,
    SUBDEVICE_1028218A = 0x1028218A,
    SUBDEVICE_1028218B = 0x1028218B,
    SUBDEVICE_1028218C = 0x1028218C,
    SUBDEVICE_1028218D = 0x1028218D,
    SUBDEVICE_1028218E = 0x1028218E,
    SUBDEVICE_1028218F = 0x1028218F,
    SUBDEVICE_10282190 = 0x10282190,
    SUBDEVICE_10282191 = 0x10282191,
    SUBDEVICE_10282192 = 0x10282192
};



inline const char8* enumToString(PciSubDevice1E0F0011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E0F0011::NONE:               return "NONE";
        case PciSubDevice1E0F0011::SUBDEVICE_10282189: return "SUBDEVICE_10282189";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218A: return "SUBDEVICE_1028218A";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218B: return "SUBDEVICE_1028218B";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218C: return "SUBDEVICE_1028218C";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218D: return "SUBDEVICE_1028218D";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218E: return "SUBDEVICE_1028218E";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218F: return "SUBDEVICE_1028218F";
        case PciSubDevice1E0F0011::SUBDEVICE_10282190: return "SUBDEVICE_10282190";
        case PciSubDevice1E0F0011::SUBDEVICE_10282191: return "SUBDEVICE_10282191";
        case PciSubDevice1E0F0011::SUBDEVICE_10282192: return "SUBDEVICE_10282192";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E0F0011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E0F0011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E0F0011::SUBDEVICE_10282189: return "DC NVMe SED CD7 RI 960GB";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218A: return "DC NVMe CD7 RI 960GB";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218B: return "DC NVMe SED CD7 RI 1.92TB";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218C: return "DC NVMe CD7 RI 1.92TB";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218D: return "DC NVMe SED CD7 RI 3.84TB";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218E: return "DC NVMe CD7 RI 3.84TB";
        case PciSubDevice1E0F0011::SUBDEVICE_1028218F: return "DC NVMe SED CD7 RI 7.68TB";
        case PciSubDevice1E0F0011::SUBDEVICE_10282190: return "DC NVMe CD7 RI 7.68TB";
        case PciSubDevice1E0F0011::SUBDEVICE_10282191: return "DC NVMe SED CD7 RI 15.36TB";
        case PciSubDevice1E0F0011::SUBDEVICE_10282192: return "DC NVMe CD7 RI 15.36TB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0011_H
