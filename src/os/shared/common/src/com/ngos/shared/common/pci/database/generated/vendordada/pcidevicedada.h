// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDADA_PCIDEVICEDADA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDADA_PCIDEVICEDADA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceDADA: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0133 = 0x0133,
    DEVICE_0139 = 0x0139,
    DEVICE_0144 = 0x0144,
    DEVICE_0150 = 0x0150,
    DEVICE_0151 = 0x0151,
    DEVICE_0159 = 0x0159,
    DEVICE_0161 = 0x0161,
    DEVICE_0165 = 0x0165,
    DEVICE_0167 = 0x0167,
    DEVICE_0168 = 0x0168,
    DEVICE_1139 = 0x1139,
    DEVICE_1150 = 0x1150,
    DEVICE_1151 = 0x1151,
    DEVICE_1153 = 0x1153,
    DEVICE_1154 = 0x1154
};



inline const char8* enumToString(PciDeviceDADA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDADA::NONE:        return "NONE";
        case PciDeviceDADA::DEVICE_0133: return "DEVICE_0133";
        case PciDeviceDADA::DEVICE_0139: return "DEVICE_0139";
        case PciDeviceDADA::DEVICE_0144: return "DEVICE_0144";
        case PciDeviceDADA::DEVICE_0150: return "DEVICE_0150";
        case PciDeviceDADA::DEVICE_0151: return "DEVICE_0151";
        case PciDeviceDADA::DEVICE_0159: return "DEVICE_0159";
        case PciDeviceDADA::DEVICE_0161: return "DEVICE_0161";
        case PciDeviceDADA::DEVICE_0165: return "DEVICE_0165";
        case PciDeviceDADA::DEVICE_0167: return "DEVICE_0167";
        case PciDeviceDADA::DEVICE_0168: return "DEVICE_0168";
        case PciDeviceDADA::DEVICE_1139: return "DEVICE_1139";
        case PciDeviceDADA::DEVICE_1150: return "DEVICE_1150";
        case PciDeviceDADA::DEVICE_1151: return "DEVICE_1151";
        case PciDeviceDADA::DEVICE_1153: return "DEVICE_1153";
        case PciDeviceDADA::DEVICE_1154: return "DEVICE_1154";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceDADA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceDADA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDADA::DEVICE_0133: return "VisionRGB-X2";
        case PciDeviceDADA::DEVICE_0139: return "VisionRGB-E1";
        case PciDeviceDADA::DEVICE_0144: return "VisionSD8";
        case PciDeviceDADA::DEVICE_0150: return "VisionRGB-E2";
        case PciDeviceDADA::DEVICE_0151: return "VisionSD4+1";
        case PciDeviceDADA::DEVICE_0159: return "VisionAV";
        case PciDeviceDADA::DEVICE_0161: return "DGC161";
        case PciDeviceDADA::DEVICE_0165: return "DGC165";
        case PciDeviceDADA::DEVICE_0167: return "DGC167";
        case PciDeviceDADA::DEVICE_0168: return "DGC168";
        case PciDeviceDADA::DEVICE_1139: return "VisionRGB-E1S";
        case PciDeviceDADA::DEVICE_1150: return "VisionRGB-E2S";
        case PciDeviceDADA::DEVICE_1151: return "VisionSD4+1S";
        case PciDeviceDADA::DEVICE_1153: return "VisionDVI-DL";
        case PciDeviceDADA::DEVICE_1154: return "VisionSDI2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDADA_PCIDEVICEDADA_H
