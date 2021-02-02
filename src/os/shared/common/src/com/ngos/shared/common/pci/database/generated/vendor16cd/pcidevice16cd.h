// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16CD_PCIDEVICE16CD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16CD_PCIDEVICE16CD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16CD: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0105 = 0x0105,
    DEVICE_0106 = 0x0106,
    DEVICE_0107 = 0x0107,
    DEVICE_0108 = 0x0108,
    DEVICE_0109 = 0x0109,
    DEVICE_010A = 0x010A,
    DEVICE_010B = 0x010B
};



inline const char8* enumToString(PciDevice16CD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16CD::NONE:        return "NONE";
        case PciDevice16CD::DEVICE_0101: return "DEVICE_0101";
        case PciDevice16CD::DEVICE_0102: return "DEVICE_0102";
        case PciDevice16CD::DEVICE_0103: return "DEVICE_0103";
        case PciDevice16CD::DEVICE_0104: return "DEVICE_0104";
        case PciDevice16CD::DEVICE_0105: return "DEVICE_0105";
        case PciDevice16CD::DEVICE_0106: return "DEVICE_0106";
        case PciDevice16CD::DEVICE_0107: return "DEVICE_0107";
        case PciDevice16CD::DEVICE_0108: return "DEVICE_0108";
        case PciDevice16CD::DEVICE_0109: return "DEVICE_0109";
        case PciDevice16CD::DEVICE_010A: return "DEVICE_010A";
        case PciDevice16CD::DEVICE_010B: return "DEVICE_010B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16CD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16CD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16CD::DEVICE_0101: return "DirectPCI SRAM for DPX-11x series";
        case PciDevice16CD::DEVICE_0102: return "DirectPCI SRAM for DPX-S/C/E-series";
        case PciDevice16CD::DEVICE_0103: return "DirectPCI ROM for DPX-11x series";
        case PciDevice16CD::DEVICE_0104: return "DirectPCI ROM for DPX-S/C/E-series";
        case PciDevice16CD::DEVICE_0105: return "DirectPCI I/O for DPX-114/DPX-115";
        case PciDevice16CD::DEVICE_0106: return "DirectPCI I/O for DPX-116";
        case PciDevice16CD::DEVICE_0107: return "DirectPCI I/O for DPX-116U";
        case PciDevice16CD::DEVICE_0108: return "DirectPCI I/O for DPX-117";
        case PciDevice16CD::DEVICE_0109: return "DirectPCI I/O for DPX-112";
        case PciDevice16CD::DEVICE_010A: return "DirectPCI I/O for DPX-C/E-series";
        case PciDevice16CD::DEVICE_010B: return "DirectPCI I/O for DPX-S series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16CD_PCIDEVICE16CD_H
