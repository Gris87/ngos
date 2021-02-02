// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000070_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000070_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000070: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003010 = 0x10003010,
    SUBDEVICE_1014040E = 0x1014040E
};



inline const char8* enumToString(PciSubDevice10000070 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000070::NONE:               return "NONE";
        case PciSubDevice10000070::SUBDEVICE_10003010: return "SUBDEVICE_10003010";
        case PciSubDevice10000070::SUBDEVICE_1014040E: return "SUBDEVICE_1014040E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000070 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000070 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000070::SUBDEVICE_10003010: return "SAS9211-4i";
        case PciSubDevice10000070::SUBDEVICE_1014040E: return "ServeRAID H1110";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000070_H
