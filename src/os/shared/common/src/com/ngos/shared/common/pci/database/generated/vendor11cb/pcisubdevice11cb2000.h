// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11CB_PCISUBDEVICE11CB2000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11CB_PCISUBDEVICE11CB2000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11CB2000: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11CB0200 = 0x11CB0200,
    SUBDEVICE_11CBB008 = 0x11CBB008
};



inline const char8* enumToString(PciSubDevice11CB2000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11CB2000::NONE:               return "NONE";
        case PciSubDevice11CB2000::SUBDEVICE_11CB0200: return "SUBDEVICE_11CB0200";
        case PciSubDevice11CB2000::SUBDEVICE_11CBB008: return "SUBDEVICE_11CBB008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11CB2000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11CB2000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11CB2000::SUBDEVICE_11CB0200: return "SX";
        case PciSubDevice11CB2000::SUBDEVICE_11CBB008: return "I/O8+";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11CB_PCISUBDEVICE11CB2000_H
