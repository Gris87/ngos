// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8167_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8167_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8167: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105B0E10 = 0x105B0E10,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_1462235C = 0x1462235C,
    SUBDEVICE_1462236C = 0x1462236C
};



inline const char8* enumToString(PciSubDevice10EC8167 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8167::NONE:               return "NONE";
        case PciSubDevice10EC8167::SUBDEVICE_105B0E10: return "SUBDEVICE_105B0E10";
        case PciSubDevice10EC8167::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice10EC8167::SUBDEVICE_1462235C: return "SUBDEVICE_1462235C";
        case PciSubDevice10EC8167::SUBDEVICE_1462236C: return "SUBDEVICE_1462236C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8167 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8167 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8167::SUBDEVICE_105B0E10: return "RTL-8110SC-GR on a N15235/A74MX mainboard";
        case PciSubDevice10EC8167::SUBDEVICE_1458E000: return "GA-MA69G-S3H Motherboard";
        case PciSubDevice10EC8167::SUBDEVICE_1462235C: return "P965 Neo MS-7235 mainboard";
        case PciSubDevice10EC8167::SUBDEVICE_1462236C: return "945P Neo3-F motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8167_H
