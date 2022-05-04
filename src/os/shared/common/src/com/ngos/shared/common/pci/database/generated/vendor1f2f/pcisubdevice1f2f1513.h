// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F2F_PCISUBDEVICE1F2F1513_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F2F_PCISUBDEVICE1F2F1513_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1F2F1513: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1F2F6113 = 0x1F2F6113,
    SUBDEVICE_1F2F6114 = 0x1F2F6114,
    SUBDEVICE_1F2F6115 = 0x1F2F6115,
    SUBDEVICE_1F2F6116 = 0x1F2F6116,
    SUBDEVICE_1F2F6118 = 0x1F2F6118
};



inline const char8* enumToString(PciSubDevice1F2F1513 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F2F1513::NONE:               return "NONE";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6113: return "SUBDEVICE_1F2F6113";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6114: return "SUBDEVICE_1F2F6114";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6115: return "SUBDEVICE_1F2F6115";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6116: return "SUBDEVICE_1F2F6116";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6118: return "SUBDEVICE_1F2F6118";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1F2F1513 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1F2F1513 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6113: return "KM660 U.2 1.6TB NVMe SSD";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6114: return "KM560 U.2 1.92TB NVMe SSD";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6115: return "KM660 U.2 3.2TB NVMe SSD";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6116: return "KM560 U.2 3.84TB NVMe SSD";
        case PciSubDevice1F2F1513::SUBDEVICE_1F2F6118: return "KM560 U.2 7.68TB NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F2F_PCISUBDEVICE1F2F1513_H
