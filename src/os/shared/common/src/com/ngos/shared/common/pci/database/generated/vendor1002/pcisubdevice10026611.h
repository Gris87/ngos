// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026611_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026611_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026611: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028210B = 0x1028210B,
    SUBDEVICE_16421869 = 0x16421869,
    SUBDEVICE_174B4248 = 0x174B4248,
    SUBDEVICE_174BA240 = 0x174BA240,
    SUBDEVICE_174BD340 = 0x174BD340,
    SUBDEVICE_1B0A90D3 = 0x1B0A90D3
};



inline const char8* enumToString(PciSubDevice10026611 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026611::NONE:               return "NONE";
        case PciSubDevice10026611::SUBDEVICE_1028210B: return "SUBDEVICE_1028210B";
        case PciSubDevice10026611::SUBDEVICE_16421869: return "SUBDEVICE_16421869";
        case PciSubDevice10026611::SUBDEVICE_174B4248: return "SUBDEVICE_174B4248";
        case PciSubDevice10026611::SUBDEVICE_174BA240: return "SUBDEVICE_174BA240";
        case PciSubDevice10026611::SUBDEVICE_174BD340: return "SUBDEVICE_174BD340";
        case PciSubDevice10026611::SUBDEVICE_1B0A90D3: return "SUBDEVICE_1B0A90D3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026611 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026611 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026611::SUBDEVICE_1028210B: return "Radeon R5 240 OEM";
        case PciSubDevice10026611::SUBDEVICE_16421869: return "Radeon 520 OEM";
        case PciSubDevice10026611::SUBDEVICE_174B4248: return "Radeon R7 240 OEM";
        case PciSubDevice10026611::SUBDEVICE_174BA240: return "Radeon R7 240 OEM";
        case PciSubDevice10026611::SUBDEVICE_174BD340: return "Radeon R7 340 OEM";
        case PciSubDevice10026611::SUBDEVICE_1B0A90D3: return "Radeon R7 240 OEM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026611_H
