// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000020: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10001000 = 0x10001000,
    SUBDEVICE_107B1040 = 0x107B1040,
    SUBDEVICE_1DE11020 = 0x1DE11020
};



inline const char8* enumToString(PciSubDevice10000020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000020::NONE:               return "NONE";
        case PciSubDevice10000020::SUBDEVICE_10001000: return "SUBDEVICE_10001000";
        case PciSubDevice10000020::SUBDEVICE_107B1040: return "SUBDEVICE_107B1040";
        case PciSubDevice10000020::SUBDEVICE_1DE11020: return "SUBDEVICE_1DE11020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000020::SUBDEVICE_10001000: return "LSI53C1010-33 PCI to Dual Channel Ultra160 SCSI Controller";
        case PciSubDevice10000020::SUBDEVICE_107B1040: return "Server Onboard 53C1010-33";
        case PciSubDevice10000020::SUBDEVICE_1DE11020: return "DC-390U3W";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000020_H
