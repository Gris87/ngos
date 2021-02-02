// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCISUBDEVICE110A4029_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCISUBDEVICE110A4029_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice110A4029: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_110A4029 = 0x110A4029,
    SUBDEVICE_110AC029 = 0x110AC029
};



inline const char8* enumToString(PciSubDevice110A4029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice110A4029::NONE:               return "NONE";
        case PciSubDevice110A4029::SUBDEVICE_110A4029: return "SUBDEVICE_110A4029";
        case PciSubDevice110A4029::SUBDEVICE_110AC029: return "SUBDEVICE_110AC029";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice110A4029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice110A4029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice110A4029::SUBDEVICE_110A4029: return "SIMATIC NET CP 5613 A2";
        case PciSubDevice110A4029::SUBDEVICE_110AC029: return "SIMATIC NET CP 5614 A2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCISUBDEVICE110A4029_H
