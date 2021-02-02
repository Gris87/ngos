// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B34117_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B34117_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B34117: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1BD40039 = 0x1BD40039,
    SUBDEVICE_1BD4003A = 0x1BD4003A,
    SUBDEVICE_1BD4004D = 0x1BD4004D
};



inline const char8* enumToString(PciSubDevice15B34117 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B34117::NONE:               return "NONE";
        case PciSubDevice15B34117::SUBDEVICE_1BD40039: return "SUBDEVICE_1BD40039";
        case PciSubDevice15B34117::SUBDEVICE_1BD4003A: return "SUBDEVICE_1BD4003A";
        case PciSubDevice15B34117::SUBDEVICE_1BD4004D: return "SUBDEVICE_1BD4004D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B34117 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B34117 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B34117::SUBDEVICE_1BD40039: return "SN10XMP2P25";
        case PciSubDevice15B34117::SUBDEVICE_1BD4003A: return "25G SFP28 SP EO251FM9 Adapter";
        case PciSubDevice15B34117::SUBDEVICE_1BD4004D: return "SN10XMP2P25, YZPC-01191-101";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B34117_H
