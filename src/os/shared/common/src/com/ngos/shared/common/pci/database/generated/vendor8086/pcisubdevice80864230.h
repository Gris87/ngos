// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864230_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864230_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864230: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861110 = 0x80861110,
    SUBDEVICE_80861111 = 0x80861111
};



inline const char8* enumToString(PciSubDevice80864230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864230::NONE:               return "NONE";
        case PciSubDevice80864230::SUBDEVICE_80861110: return "SUBDEVICE_80861110";
        case PciSubDevice80864230::SUBDEVICE_80861111: return "SUBDEVICE_80861111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864230::SUBDEVICE_80861110: return "Lenovo ThinkPad T51";
        case PciSubDevice80864230::SUBDEVICE_80861111: return "Lenovo ThinkPad T61";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864230_H
