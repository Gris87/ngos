// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B4949_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B4949_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B4949: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0010 = 0x102B0010,
    SUBDEVICE_102B0011 = 0x102B0011,
    SUBDEVICE_102B0020 = 0x102B0020,
    SUBDEVICE_102B0030 = 0x102B0030,
    SUBDEVICE_102B0040 = 0x102B0040,
    SUBDEVICE_102B0050 = 0x102B0050,
    SUBDEVICE_102B1010 = 0x102B1010,
    SUBDEVICE_102B1015 = 0x102B1015,
    SUBDEVICE_102B1020 = 0x102B1020,
    SUBDEVICE_102B1050 = 0x102B1050
};



inline const char8* enumToString(PciSubDevice102B4949 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B4949::NONE:               return "NONE";
        case PciSubDevice102B4949::SUBDEVICE_102B0010: return "SUBDEVICE_102B0010";
        case PciSubDevice102B4949::SUBDEVICE_102B0011: return "SUBDEVICE_102B0011";
        case PciSubDevice102B4949::SUBDEVICE_102B0020: return "SUBDEVICE_102B0020";
        case PciSubDevice102B4949::SUBDEVICE_102B0030: return "SUBDEVICE_102B0030";
        case PciSubDevice102B4949::SUBDEVICE_102B0040: return "SUBDEVICE_102B0040";
        case PciSubDevice102B4949::SUBDEVICE_102B0050: return "SUBDEVICE_102B0050";
        case PciSubDevice102B4949::SUBDEVICE_102B1010: return "SUBDEVICE_102B1010";
        case PciSubDevice102B4949::SUBDEVICE_102B1015: return "SUBDEVICE_102B1015";
        case PciSubDevice102B4949::SUBDEVICE_102B1020: return "SUBDEVICE_102B1020";
        case PciSubDevice102B4949::SUBDEVICE_102B1050: return "SUBDEVICE_102B1050";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B4949 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B4949 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B4949::SUBDEVICE_102B0010: return "Radient eCL (Single-full) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B0011: return "Radient eCLV (Single-full) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B0020: return "Radient eCL (Dual-base) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B0030: return "Radient eCL (Dual-full) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B0040: return "Radient eCL (Quad-base) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B0050: return "Radient eCL (Golden) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B1010: return "Radient eV-CXP (quad CXP-6) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B1015: return "Radient eV-CXP (dual CXP-6) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B1020: return "Radient eV-CXP (quad CXP-3) frame grabber";
        case PciSubDevice102B4949::SUBDEVICE_102B1050: return "Radient eV-CXP (Golden) frame grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B4949_H
