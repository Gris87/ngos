// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11803_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11803_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F11803: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110023 = 0x0E110023,
    SUBDEVICE_0E110043 = 0x0E110043
};



inline const char8* enumToString(PciSubDevice14F11803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11803::NONE:               return "NONE";
        case PciSubDevice14F11803::SUBDEVICE_0E110023: return "SUBDEVICE_0E110023";
        case PciSubDevice14F11803::SUBDEVICE_0E110043: return "SUBDEVICE_0E110043";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F11803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F11803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11803::SUBDEVICE_0E110023: return "623-LAN Grizzly";
        case PciSubDevice14F11803::SUBDEVICE_0E110043: return "623-LAN Yogi";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11803_H
