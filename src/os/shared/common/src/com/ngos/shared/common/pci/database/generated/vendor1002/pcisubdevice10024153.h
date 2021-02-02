// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024153_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024153_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024153: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043010C = 0x1043010C,
    SUBDEVICE_1462932C = 0x1462932C
};



inline const char8* enumToString(PciSubDevice10024153 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024153::NONE:               return "NONE";
        case PciSubDevice10024153::SUBDEVICE_1043010C: return "SUBDEVICE_1043010C";
        case PciSubDevice10024153::SUBDEVICE_1462932C: return "SUBDEVICE_1462932C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024153 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024153 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024153::SUBDEVICE_1043010C: return "A9550GE/TD";
        case PciSubDevice10024153::SUBDEVICE_1462932C: return "RX9550SE-TD128 (MS-8932)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024153_H
