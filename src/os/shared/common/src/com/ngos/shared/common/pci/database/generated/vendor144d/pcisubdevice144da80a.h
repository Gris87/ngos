// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA80A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA80A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA80A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0128215A = 0x0128215A,
    SUBDEVICE_0128215B = 0x0128215B,
    SUBDEVICE_0128215C = 0x0128215C,
    SUBDEVICE_0128215D = 0x0128215D,
    SUBDEVICE_01282166 = 0x01282166,
    SUBDEVICE_01282167 = 0x01282167,
    SUBDEVICE_01282168 = 0x01282168,
    SUBDEVICE_01282169 = 0x01282169,
    SUBDEVICE_144DA813 = 0x144DA813
};



inline const char8* enumToString(PciSubDevice144DA80A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA80A::NONE:               return "NONE";
        case PciSubDevice144DA80A::SUBDEVICE_0128215A: return "SUBDEVICE_0128215A";
        case PciSubDevice144DA80A::SUBDEVICE_0128215B: return "SUBDEVICE_0128215B";
        case PciSubDevice144DA80A::SUBDEVICE_0128215C: return "SUBDEVICE_0128215C";
        case PciSubDevice144DA80A::SUBDEVICE_0128215D: return "SUBDEVICE_0128215D";
        case PciSubDevice144DA80A::SUBDEVICE_01282166: return "SUBDEVICE_01282166";
        case PciSubDevice144DA80A::SUBDEVICE_01282167: return "SUBDEVICE_01282167";
        case PciSubDevice144DA80A::SUBDEVICE_01282168: return "SUBDEVICE_01282168";
        case PciSubDevice144DA80A::SUBDEVICE_01282169: return "SUBDEVICE_01282169";
        case PciSubDevice144DA80A::SUBDEVICE_144DA813: return "SUBDEVICE_144DA813";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA80A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA80A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA80A::SUBDEVICE_0128215A: return "DC NVMe PM9A3 RI U.2 960GB";
        case PciSubDevice144DA80A::SUBDEVICE_0128215B: return "DC NVMe PM9A3 RI U.2 1.92TB";
        case PciSubDevice144DA80A::SUBDEVICE_0128215C: return "DC NVMe PM9A3 RI U.2 3.84TB";
        case PciSubDevice144DA80A::SUBDEVICE_0128215D: return "DC NVMe PM9A3 RI U.2 7.68TB";
        case PciSubDevice144DA80A::SUBDEVICE_01282166: return "DC NVMe PM9A3 RI 110M.2 960GB";
        case PciSubDevice144DA80A::SUBDEVICE_01282167: return "DC NVMe PM9A3 RI 110M.2 1.92TB";
        case PciSubDevice144DA80A::SUBDEVICE_01282168: return "DC NVMe PM9A3 RI 80M.2 480GB";
        case PciSubDevice144DA80A::SUBDEVICE_01282169: return "DC NVMe PM9A3 RI 80M.2 960GB";
        case PciSubDevice144DA80A::SUBDEVICE_144DA813: return "General DC NVMe PM9A3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA80A_H
