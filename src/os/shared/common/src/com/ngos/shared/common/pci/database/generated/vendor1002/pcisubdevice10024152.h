// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024152_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024152_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024152: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020002 = 0x10020002,
    SUBDEVICE_10024772 = 0x10024772,
    SUBDEVICE_1043C002 = 0x1043C002,
    SUBDEVICE_1043C01A = 0x1043C01A,
    SUBDEVICE_14629510 = 0x14629510,
    SUBDEVICE_174B7C29 = 0x174B7C29,
    SUBDEVICE_17874002 = 0x17874002
};



inline const char8* enumToString(PciSubDevice10024152 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024152::NONE:               return "NONE";
        case PciSubDevice10024152::SUBDEVICE_10020002: return "SUBDEVICE_10020002";
        case PciSubDevice10024152::SUBDEVICE_10024772: return "SUBDEVICE_10024772";
        case PciSubDevice10024152::SUBDEVICE_1043C002: return "SUBDEVICE_1043C002";
        case PciSubDevice10024152::SUBDEVICE_1043C01A: return "SUBDEVICE_1043C01A";
        case PciSubDevice10024152::SUBDEVICE_14629510: return "SUBDEVICE_14629510";
        case PciSubDevice10024152::SUBDEVICE_174B7C29: return "SUBDEVICE_174B7C29";
        case PciSubDevice10024152::SUBDEVICE_17874002: return "SUBDEVICE_17874002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024152 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024152 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024152::SUBDEVICE_10020002: return "Radeon 9600XT";
        case PciSubDevice10024152::SUBDEVICE_10024772: return "All-in-Wonder 9600 XT";
        case PciSubDevice10024152::SUBDEVICE_1043C002: return "Radeon 9600 XT TVD";
        case PciSubDevice10024152::SUBDEVICE_1043C01A: return "A9600XT/TD";
        case PciSubDevice10024152::SUBDEVICE_14629510: return "RX9600XT (MS-8951)";
        case PciSubDevice10024152::SUBDEVICE_174B7C29: return "Radeon 9600XT";
        case PciSubDevice10024152::SUBDEVICE_17874002: return "Radeon 9600 XT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024152_H
