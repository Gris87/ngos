// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCISUBDEVICE13178201_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCISUBDEVICE13178201_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13178201: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B82635 = 0x10B82635,
    SUBDEVICE_13178201 = 0x13178201
};



inline const char8* enumToString(PciSubDevice13178201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13178201::NONE:               return "NONE";
        case PciSubDevice13178201::SUBDEVICE_10B82635: return "SUBDEVICE_10B82635";
        case PciSubDevice13178201::SUBDEVICE_13178201: return "SUBDEVICE_13178201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13178201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13178201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13178201::SUBDEVICE_10B82635: return "SMC2635W v1 802.11b Wireless Cardbus Adapter";
        case PciSubDevice13178201::SUBDEVICE_13178201: return "SMC2635W v2 802.11b Wireless Cardbus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCISUBDEVICE13178201_H
